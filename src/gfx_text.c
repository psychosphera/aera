#include "gfx_text.h"

#include <assert.h>

#include "acommon/a_string.h"

#include "cg_cgame.h"
#include "db_files.h"
#include "dvar.h"
#include "font.h"
#include "gfx.h"
#include "gfx_defs.h"
#include "gfx_shader.h"
#include "gfx_uniform.h"
#include "sys.h" 

A_EXTERN_C dvar_t* vid_width;
A_EXTERN_C dvar_t* vid_height;
FontDef r_defaultFont;

static const GfxSubTexDef s_subTexDefs[6] = {
   {.x = 0, .y = 0, .u = 0, .v = 1 },
   {.x = 0, .y = 1, .u = 0, .v = 0 },
   {.x = 1, .y = 1, .u = 1, .v = 0 },
   {.x = 0, .y = 0, .u = 0, .v = 1 },
   {.x = 1, .y = 1, .u = 1, .v = 0 },
   {.x = 1, .y = 0, .u = 1, .v = 1 }
};

// ============================================================================
A_NO_DISCARD bool R_CreateTextureAtlas(A_INOUT FontDef* f) {
    char* vertSource  = DB_LoadShader("text.vs");
    char* pixelSource = DB_LoadShader("text.ps");

    bool b = R_CreateShaderProgram(vertSource, pixelSource, &f->prog);
    assert(b);

    DB_UnloadShader(vertSource);
    DB_UnloadShader(pixelSource);

    if (!b)
        return false;
    b = R_BindShaderProgram(&f->prog);
    assert(b);
    if (!b)
        return false;

    for (char i = ' '; i < Font_GlyphCount(f) + ' '; i++) {
        const GlyphDef* g = Font_GetGlyph(f, i);
        f->atlas_width += g->width + 1;
        f->atlas_height = A_MAX(f->atlas_height, g->height);
    }

    b = R_CreateVertexBuffer(
        s_subTexDefs,
        sizeof(s_subTexDefs),
        sizeof(s_subTexDefs),
        0,
        sizeof(GfxSubTexDef),
        &f->pass.vbs[0]
    );
    assert(b);
    if (!b)
        return false;

    ImageFormat format    = R_IMAGE_FORMAT_R8;
    ImageFilter minfilter = R_IMAGE_FILTER_LINEAR;
    ImageFilter magfilter = R_IMAGE_FILTER_LINEAR;

    int width = 0;
    int height = 0;
    for (char c = ' '; c < ' ' + Font_GlyphCount(f); c++) {
        GlyphDef* g = Font_GetGlyph(f, c);
        if (g->advance_x == 0)
            continue;

        width += g->width + 1;
        height = A_MAX(height, g->height);
    }

    GfxImage image;
    b = R_CreateImage2D(NULL, 0, width, height, 1, format, true, true, true,
                        minfilter, magfilter, &image);
    GfxImage* pImage = R_AddImageToMaterialPass(&f->pass, &image);
    assert(b);
    assert(pImage);
    GfxShaderUniformDef uniform;

    R_CreateUniformInt("uTex", pImage->tex, &uniform);
    GfxShaderUniformDef* pUniform = R_ShaderAddUniform(&f->prog, &uniform);
    assert(pUniform);

    amat4f_t m = A_MAT4F_IDENTITY;
    R_CreateUniformMat4f("uModel", m, &uniform);
    pUniform = R_ShaderAddUniform(&f->prog, &uniform);
    assert(pUniform);
    
    R_CreateUniformMat4f("uOrthoProjection", m, &uniform);
    pUniform = R_ShaderAddUniform(&f->prog, &uniform);
    assert(pUniform);
    
    R_CreateUniformVec4f("uAtlasCoord", A_VEC4F_ZERO, &uniform);
    pUniform = R_ShaderAddUniform(&f->prog, &uniform);
    assert(pUniform);

    R_CreateUniformVec3f("uTextColor", A_VEC3F_ZERO, &uniform);
    pUniform = R_ShaderAddUniform(&f->prog, &uniform);
    assert(pUniform);

#if A_RENDER_BACKEND_GL
    GL_CALL(glBindVertexArray, f->pass.vbs[0].vao);
    GL_CALL(glVertexAttribPointer,
        0, 2, GL_FLOAT, (GLboolean)GL_FALSE,
        (GLsizei)sizeof(GfxSubTexDef), (void*)offsetof(GfxSubTexDef, x)
    );
    GL_CALL(glVertexAttribPointer,
        1, 2, GL_FLOAT, (GLboolean)GL_FALSE,
        (GLsizei)sizeof(GfxSubTexDef), (void*)offsetof(GfxSubTexDef, u)
    );
    GL_CALL(glEnableVertexAttribArray, 0);
    GL_CALL(glEnableVertexAttribArray, 1);


    GLint unpackAlign = 0;
    GL_CALL(glGetIntegerv, GL_UNPACK_ALIGNMENT, &unpackAlign);
    GL_CALL(glPixelStorei, GL_UNPACK_ALIGNMENT, 1);
#elif A_RENDER_BACKEND_D3D9
    D3DVERTEXELEMENT9 vertex_elements[] = {
        {
            .Stream     = 0,
            .Offset     = offsetof(GfxSubTexDef, x),
            .Type       = D3DDECLTYPE_FLOAT2,
            .Method     = D3DDECLMETHOD_DEFAULT,
            .Usage      = D3DDECLUSAGE_POSITION,
            .UsageIndex = 0
        },
        {
            .Stream     = 0,
            .Offset     = offsetof(GfxSubTexDef, u),
            .Type       = D3DDECLTYPE_FLOAT2,
            .Method     = D3DDECLMETHOD_DEFAULT,
            .Usage      = D3DDECLUSAGE_TEXCOORD,
            .UsageIndex = 0
        },
        D3DDECL_END()
    };
    HRESULT hr = r_d3d9Glob.d3ddev->lpVtbl->CreateVertexDeclaration(
        r_d3d9Glob.d3ddev, vertex_elements, &f->pass.decl
    );
    assert(hr == D3D_OK);
    assert(f->pass.decl);
    if (hr != D3D_OK)
        return false;
    if (!f->pass.decl)
        return false;
#endif // A_RENDER_BACKEND_GL
    int pixel_size = R_ImageFormatPixelSize(format);
    width = 0;
    height = 0;
    for (char c = ' '; c < ' ' + Font_GlyphCount(f); c++) {
        GlyphDef* g = Font_GetGlyph(f, c);
        if (g->advance_x == 0)
            continue;

        g->atlas_x = (float)width / (float)f->atlas_width;
        g->atlas_y = 0.0f;

        if (g->width > 0 && g->height > 0) {
            b = R_ImageSubData(
                pImage, g->pixels, g->width * g->height * pixel_size,
                width, 0,
                g->width, g->height, format
            );
            assert(b);
        }

        width += g->width + 1;
    }

#if A_RENDER_BACKEND_GL
    GL_CALL(glPixelStorei, GL_UNPACK_ALIGNMENT, unpackAlign);
#endif // A_RENDER_BACKEND_GL

    return true;
}
// ============================================================================

void R_DeleteTextureAtlas(A_INOUT FontDef* f) {
    R_DeleteShaderProgram(&f->prog);
    R_DeleteMaterialPass(&f->pass);
}

void R_DrawText(
    size_t localClientNum, A_OPTIONAL_IN const FontDef* font, 
    const RectDef* rect, const char* text,
    float xscale, float yscale, acolor_rgb_t color,
    bool right
) {
    if (font == NULL)
        font = &r_defaultFont;

    cg_t* cg = CG_GetLocalClientGlobals(localClientNum);

    const float screenScaleX = cg->viewport.w * Dvar_GetInt(vid_width);
    const float screenScaleY = cg->viewport.h * Dvar_GetInt(vid_height);

    const float min_x =  rect->x * screenScaleX;
    const float max_x = (rect->x + rect->w) * screenScaleX;
    const float min_y = (rect->y + rect->h) * screenScaleY - font->atlas_height;
    const float max_y =  rect->y * screenScaleY;

    float x = min_x;
    float y = min_y;

    bool b = R_EnableTransparencyBlending();
    assert(b);
    if (!b)
        return;
    b = R_BindVertexBuffer(&font->pass.vbs[0], 0);
    assert(b);
    if (!b)
        return;
    b = R_BindImage(&font->pass.images[0], 0);
    assert(b);
    if (!b)
        return;
    b = R_BindShaderProgram(&font->prog);
    assert(b);
    if (!b)
        return;
    avec3f_t textColor = A_vec3(color.r, color.g, color.b);
    R_ShaderSetUniformVec3fByName(&font->prog, "uTextColor", textColor);

    R_ShaderSetUniformMat4fByName(
        &font->prog, "uOrthoProjection", cg->camera.orthoProjection
    );

    char            last_c   = '\0';
    float           last_w   = 0, last_h = 0;
    const GlyphDef* last_g   = NULL;
    size_t          text_len = A_cstrlen(text);

    int i = right ? (int)text_len - 1 : 0;
    const int end = right ? -1 : (int)text_len;

    while (i != end) {
        char c = text[i];
        // Make sure c != last_c so that g gets bound to a valid glyph instead
        // of getting bound to last_g and derefing NULL on the first iteration
        // of the loop.
        assert(c != '\0');

        if (c == '\n') {
            y -= font->atlas_height;
            if (y < max_y)
                break;
            x = min_x;
            right ? i-- : i++;
            continue;
        }

        if (c < 32 || c > 127)
            c = '#';

        // Reuse the last glyph if it's going to be rendered again.
        const GlyphDef* g = NULL;
        if (c == last_c)
            g = last_g;
        else
            g = Font_GetGlyphConst(font, c);

        // If the glyph couldn't be retrieved, use '#' as a placeholder.
        if (g == NULL)
            g = Font_GetGlyphConst(font, '#');

        // If '#' couldn't be retrieved either, just move on to the next char.
        if (g == NULL) {
            right ? i-- : i++;
            continue;
        }

        // Skip rendering a glyph if it has no advance
        if (g->advance_x == 0) {
            right ? i-- : i++;
            continue;
        }

        // Wrap the text if it goes beyond the boundaries of rect
        if (x + g->advance_x > max_x) {
            y -= font->atlas_height;
            if (y < max_y)
                break;

            x = min_x;
        }

        // Scale the width and height and update the last ones, or reuse the 
        // last ones if the same glyph is being rendered.
        float w = c == last_c ? last_w
            : g->width * xscale;
        float h = c == last_c ? last_h
            : g->height * yscale;

        last_w = w;
        last_h = h;

        // Glyphs can have no width or height because they have no pixel data
        // but a nonzero advance (i.e., space). Skip rendering on those and
        // just update the cursor position.
        if (g->width == 0 || g->height == 0) {
            if (right)
                x -= g->advance_x * xscale;
            else
                x += g->advance_x * xscale;
            last_c = c;
            last_g = g;
            right ? i-- : i++;
            continue;
        }

        float xpos = x + g->left;
        float ypos = y - (g->height - g->top);

        amat4f_t model = A_MAT4F_IDENTITY;
        avec3f_t pos = A_vec3(xpos, ypos, 0.0f);
        model = A_mat4f_translate_vec3(model, pos);
        avec3f_t scale = A_vec3(w, h, 0.0f);
        model = A_mat4f_scale_vec3(model, scale);
        R_ShaderSetUniformMat4fByName(&font->prog, "uModel", model);

        // If the same glyph is being rendered again, the coord uniform doesn't
        // need to be updated.
        if (c != last_c) {
            avec4f_t atlasCoord = A_vec4(g->atlas_x, g->atlas_y,
                (float)g->width / (float)font->atlas_width,
                (float)g->height / (float)font->atlas_height);
            R_ShaderSetUniformVec4fByName(&font->prog, "uAtlasCoord", atlasCoord);
        }

        R_BindVertexBuffer(&font->pass.vbs[0], 0);
        R_BindImage(&font->pass.images[0], 0);
        b = R_DrawTris(2, 0);
        assert(b);
        if (!b)
            return;

        if (right)
            x -= g->advance_x * xscale;
        else
            x += g->advance_x * xscale;
        last_c = c;
        last_g = g;
        right ? i-- : i++;
    }
    R_DisableTransparencyBlending();
}

GfxTextDraw r_textDraws[MAX_LOCAL_CLIENTS][256];

bool R_GetTextDraw(size_t localClientNum, size_t id, A_OUT GfxTextDraw** draw) 
{
    assert(id < A_countof(r_textDraws[localClientNum]));

    *draw = &r_textDraws[localClientNum][id];
    assert(draw);
    return !(*draw)->free;
}


bool R_FindFreeTextDraw(
    size_t localClientNum, A_OUT size_t* index, A_OUT GfxTextDraw** draw
) {
    *index = (size_t)-1;
    *draw = NULL;

    for (int i = 0; i < A_countof(r_textDraws[localClientNum]); i++) {
        R_GetTextDraw(localClientNum, i, draw);
        if ((*draw)->free) {
            *index = i;
            return true;
        }
    }

    return false;
}

bool R_AddTextDrawDef(
    size_t localClientNum, FontDef* font, const RectDef* rect, 
    const char* text, float xscale, float yscale, acolor_rgb_t color, 
    bool active, bool right, A_OUT size_t* id
) {
    GfxTextDraw* d = NULL;
    if (!R_FindFreeTextDraw(localClientNum, id, &d))
        return false;

    char* t = A_cstrdup(text);

    d->free   = false;
    d->font   = font;
    d->text   = t;
    d->rect   = *rect;
    d->xscale = xscale;
    d->yscale = yscale;
    d->color  = color;
    d->active = active;
    d->right  = right;

    return true;
}

bool R_UpdateTextDrawDef(size_t localClientNum, size_t id, const char* text) {
    GfxTextDraw* d = NULL;
    if (!R_GetTextDraw(localClientNum, id, &d))
        return false;

    A_cstrfree(d->text);
    char* t = A_cstrdup(text);
    d->text = t;
    return true;
}

bool R_ActivateTextDrawDef(size_t localClientNum, size_t id, bool active) {
    GfxTextDraw* d = NULL;
    R_GetTextDraw(localClientNum, id, &d);
    bool wasActive = d->active;
    d->active = active;
    return wasActive;
}

A_EXTERN_C bool R_RemoveTextDrawDef(size_t localClientNum, size_t id) {
    GfxTextDraw* d = NULL;
    if (!R_GetTextDraw(localClientNum, id, &d))
        return false;

    if (d->free == true)
        return false;

    d->free   = true;
    d->active = false;
    A_cstrfree(d->text);
    return true;
}

A_EXTERN_C void R_ClearTextDrawDefs(size_t localClientNum) {
    for (int i = 0; i < A_countof(r_textDraws[i]); i++) {
        GfxTextDraw* d = &r_textDraws[localClientNum][i];
        d->active = false;
        d->free   = true;
    }
}

A_EXTERN_C void R_DrawTextDrawDefs(size_t localClientNum) {
    for (int i = 0; i < A_countof(r_textDraws); i++) {
        for (int j = 0; j < A_countof(r_textDraws[i]); j++) {
            GfxTextDraw* d = &r_textDraws[i][j];
            if (!d->free && d->active) {
                R_DrawText(
                    localClientNum, d->font, &d->rect, d->text,
                    d->xscale, d->yscale, d->color, d->right
                );
            }
        }
    }
}
