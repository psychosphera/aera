#include "gfx.hpp"

#include <cassert>
#include <cstdio>
#include <cstddef>

#include <GL/glew.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <glm/gtc/matrix_transform.hpp>

#include "cg_cgame.hpp"
#include "db_files.hpp"
#include "dvar.hpp"
#include "font.hpp"
#include "gfx_backend.hpp"
#include "gfx_text.hpp"
#include "gfx_uniform.hpp"
#include "m_math.hpp"
#include "sys.hpp"

extern dvar_t* vid_width;
extern dvar_t* vid_height;
extern void R_DrawTextDrawDefs (size_t localClientNum);
extern void R_ClearTextDrawDefs(size_t localClientNum);

void GLAPIENTRY R_GlDebugOutput(
    GLenum source, GLenum type, unsigned int id, GLenum severity,
    GLsizei /*unused*/, const char* message, const void* /*unused*/
) {
    if (/*id == 131169 ||*/ id == 131185/* ||
        id == 131218 || id == 131204 || id == 131139*/
    ) {
        return;
    }

    std::string_view src = GL_DEBUG_SOURCE_STR(source);
    std::string_view t   = GL_DEBUG_TYPE_STR(type);
    std::string_view sev = GL_DEBUG_SEVERITY_STR(severity);
    
    Com_DPrintln(
        "OpenGL debug message (id={}, source={}, type={}, severity={}): {}", 
        id, src, t, sev, message
    );
}

static void   R_RegisterDvars        ();
static void   R_InitMap              ();
static void   R_InitCubes            (A_INOUT GfxCubePrim& cubePrim);
//static size_t R_GetBSPSurfTris       (const BSPCollSurf* surf, GfxBSPTri* tris, size_t max_tris);
static void   R_DrawFrameInternal    (size_t localClientNum);
static void   R_InitLocalClient      (size_t localClientNum);
static void   R_UpdateLocalClientView(size_t localClientNum);

constexpr float R_NEAR_PLANE_DEFAULT = 0.1f;
constexpr float R_FAR_PLANE_DEFAULT  = 1000.0f;

dvar_t* r_vsync;
dvar_t* r_fullscreen;
dvar_t* r_noBorder;
dvar_t* r_renderDistance;
dvar_t* r_wireframe;

GfxCubePrim r_cubePrim;
extern FontDef r_defaultFont;

size_t r_testDrawId = 0;

void R_Init() {
    RB_Init();

    int imgInitFlags = IMG_INIT_JPG | IMG_INIT_PNG;
    if ((IMG_Init(imgInitFlags) & imgInitFlags) != imgInitFlags)
        Com_Errorln("SDL_image init failed.");

#if _DEBUG
    //GLint flags = 0;
    //GL_CALL(glGetIntegerv, GL_CONTEXT_FLAGS, &flags);
    //if ((flags & GL_CONTEXT_FLAG_DEBUG_BIT) == 0)
    //    Com_Errorln("Failed to initialize OpenGL debug context in debug build.");

    GLint num_extensions = 0;
    GL_CALL(glGetIntegerv, GL_NUM_EXTENSIONS, &num_extensions);
    for (GLint i = 0; i < num_extensions; i++)
        Com_Println(CON_DEST_CLIENT, "{} ", (const char*)glGetStringi(GL_EXTENSIONS, i));

    GL_CALL(glEnable, GL_DEBUG_OUTPUT);
    GL_CALL(glEnable, GL_DEBUG_OUTPUT_SYNCHRONOUS);
    GL_CALL(glDebugMessageCallback, R_GlDebugOutput, nullptr);
    GL_CALL(glDebugMessageControl, GL_DONT_CARE, GL_DONT_CARE, 
            GL_DONT_CARE, 0, nullptr, (GLboolean)GL_TRUE);
#endif // _DEBUG

    GL_CALL(glClearColor, 0.2f, 0.3f, 0.3f, 1.0f);
    
    for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
        R_InitLocalClient(i);
        R_ClearTextDrawDefs(i);
    }

    R_RegisterDvars();

    bool b = Font_Load("consola.ttf", 0, 48, r_defaultFont);
    assert(b);
    (void)b;

    RectDef rect = { .x = 0.1f, .y = 0.1f, .w = 0.8f, .h = 0.2f };
    R_AddTextDrawDef(
        0, nullptr, rect, "This is a test.\nWhere the fuck i am?", 1.0f, 1.0f,
        glm::vec3(0.77, 0.77, 0.2), true, false, r_testDrawId
    );
    R_InitCubes(r_cubePrim);
    R_InitMap();

    //glEnable(GL_POINT_SMOOTH);
    //glPointSize(4);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
}

static void R_InitLocalClient(size_t localClientNum) {
    cg_t& cg     = CG_GetLocalClientGlobals(localClientNum);
    cg.nearPlane = R_NEAR_PLANE_DEFAULT;
    cg.farPlane  = R_FAR_PLANE_DEFAULT;
    R_UpdateLocalClientView(localClientNum);
}

static void R_UpdateOrtho(size_t localClientNum) {
    cg_t& cg = CG_GetLocalClientGlobals(localClientNum);

    float left   = cg.viewport.x * Dvar_GetInt(*vid_width);
    float right  = cg.viewport.w * Dvar_GetInt(*vid_width)  + left;
    float bottom = cg.viewport.y * Dvar_GetInt(*vid_height);
    float top    = cg.viewport.h * Dvar_GetInt(*vid_height) + bottom;
    cg.camera.orthoProjection = glm::ortho(left, right, bottom, top);
}

void R_UpdateProjection(size_t localClientNum) {
    cg_t& cg = CG_GetLocalClientGlobals(localClientNum);

    float w = cg.viewport.w * Dvar_GetInt(*vid_width);
    float h = cg.viewport.h * Dvar_GetInt(*vid_height);
    cg.camera.perspectiveProjection = glm::perspective(
        glm::radians(cg.fovy), w / h, cg.nearPlane, cg.farPlane
    );
}

static void R_UpdateLocalClientView(size_t localClientNum) {
    R_UpdateOrtho(localClientNum);
    R_UpdateProjection(localClientNum);
}

static void R_RegisterDvars() {
    r_vsync          = &Dvar_RegisterBool("r_vsync", DVAR_FLAG_NONE, true);
    r_fullscreen     = &Dvar_RegisterBool("r_fullscreen", DVAR_FLAG_NONE, false);
    r_noBorder       = &Dvar_RegisterBool("r_noBorder", DVAR_FLAG_NONE, false);
    r_renderDistance = &Dvar_RegisterFloat("r_renderDistance", DVAR_FLAG_NONE, R_FAR_PLANE_DEFAULT, 10.0f, 1000000.0f);
    r_wireframe      = &Dvar_RegisterBool("r_wireframe", DVAR_FLAG_NONE, false);
}

static void R_InitCubes(A_INOUT GfxCubePrim& cubePrim) {
    std::string vertSource = DB_LoadShader("vs.glsl");
    std::string fragSource = DB_LoadShader("fs.glsl");

    std::string errorLog;
    if (!R_CreateShaderProgram(
        vertSource, fragSource, &errorLog, r_cubePrim.prog
    )) {
        Com_Errorln(errorLog);
    }

    GL_CALL(glGenVertexArrays, 1, &cubePrim.vao);
    GL_CALL(glBindVertexArray, cubePrim.vao);

    GL_CALL(glGenBuffers, 1, &cubePrim.vbo);
    GL_CALL(glBindBuffer, GL_ARRAY_BUFFER, cubePrim.vbo);
    GL_CALL(glBufferData,
        GL_ARRAY_BUFFER, sizeof(GfxCubePrim::vertices), 
        GfxCubePrim::vertices, GL_STATIC_DRAW
    );

    GL_CALL(glVertexAttribPointer,
        0, 3, GL_FLOAT, (GLboolean)GL_FALSE, 
        5 * (GLsizei)sizeof(*GfxCubePrim::vertices), (void*)0
    );
    GL_CALL(glEnableVertexAttribArray, 0);

    GL_CALL(glVertexAttribPointer,
        1, 2, GL_FLOAT, (GLboolean)GL_FALSE, 
        5 * (GLsizei)sizeof(*GfxCubePrim::vertices),
        (void*)(3 * sizeof(*GfxCubePrim::vertices))
    );
    GL_CALL(glEnableVertexAttribArray, 1);

    bool b = R_CreateImage("container.jpg", NULL, NULL, cubePrim.tex);
    assert(b);
    (void)b;

    GL_CALL(glUseProgram, cubePrim.prog.program);
    R_SetUniform(cubePrim.prog.program, "uContainerTex", 0);
    GL_CALL(glUseProgram, 0);
    GL_CALL(glBindBuffer, GL_ARRAY_BUFFER, 0);
    GL_CALL(glBindVertexArray, 0);
}

static void R_ShutdownCubes(A_INOUT GfxCubePrim& cubePrim) {
    R_DeleteShaderProgram(cubePrim.prog);
    R_DeleteImage(cubePrim.tex);
    GL_CALL(glDisableVertexAttribArray, 0);
    GL_CALL(glDisableVertexAttribArray, 1);
    GL_CALL(glDeleteBuffers, 1, &cubePrim.vbo);
    GL_CALL(glDeleteVertexArrays, 1, &cubePrim.vao);
}

void R_DrawFrame(size_t localClientNum) {
    R_DrawFrameInternal(localClientNum);
}

void R_Frame() {
    RB_BeginFrame();
    GL_CALL(glEnable, GL_SCISSOR_TEST);
    for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
        if (!CG_LocalClientIsActive(i))
            continue;

        R_DrawFrame(i);
    }
    GL_CALL(glDisable, GL_SCISSOR_TEST);
    RB_EndFrame();
}

void R_WindowResized() {
    for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++)
        R_UpdateLocalClientView(i);
    
}

A_NO_DISCARD bool R_CreateImage(
    std::string_view image_name, A_OPTIONAL_OUT int* width, 
    A_OPTIONAL_OUT int* height,  A_OUT texture_t& tex
) {
    if(width)
        *width  = 0;
    if(height)
        *height = 0;

    GL_CALL(glActiveTexture, GL_TEXTURE0);
    GL_CALL(glGenTextures,   1, &tex);
    GL_CALL(glBindTexture,   GL_TEXTURE_2D, tex);

    GL_CALL(glTexParameteri, GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,     GL_REPEAT);
    GL_CALL(glTexParameteri, GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,     GL_REPEAT);
    GL_CALL(glTexParameteri, GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    GL_CALL(glTexParameteri, GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    SdlSurface surf = SdlSurface(
        IMG_Load(DB_ImagePath(image_name).string().c_str())
    );

    if (!surf)
        return false;

    if (!surf->pixels)
        return false;

    if (surf->w < 1 || surf->h < 1)
        return false;

    image_format_t format = 0;
    switch (surf->format->format) {
    case SDL_PIXELFORMAT_RGB24:
        format = GL_RGB;
        break;
    case SDL_PIXELFORMAT_RGBA32:
        format = GL_RGBA;
        break;
    default:
        assert(false);
        return false;
    }

    GL_CALL(glTexImage2D,
        GL_TEXTURE_2D, 0, GL_RGB, surf->w, surf->h, 
        0, format, GL_UNSIGNED_BYTE, surf->pixels
    );
    GL_CALL(glGenerateMipmap, GL_TEXTURE_2D);

    if (width)
        *width = surf->w;
    if (height)
        *height = surf->h;

    return true;
}

static image_format_t R_BSPToGLImageFormat(BSPBitmapDataFormat format) {
    image_format_t gl_format = 0;
    switch(format) {
    case BSP_BITMAP_DATA_FORMAT_A8: 
        gl_format = GL_ALPHA8;
        break;
    case BSP_BITMAP_DATA_FORMAT_R5G6B5:
        gl_format = GL_RGB565;
        break;
    case BSP_BITMAP_DATA_FORMAT_DXT1:
        gl_format = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT;
        break;
    case BSP_BITMAP_DATA_FORMAT_DXT3:
        gl_format = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
        break;
    case BSP_BITMAP_DATA_FORMAT_DXT5:
        gl_format = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;
        break;
    default:
        Com_Errorln("R_BSPToGLImageFormat: Unimplemented BSPBitmapDataFormat {}.", BSPBitmapDataFormat_to_string(format));
    };

    return gl_format;
}

A_NO_DISCARD bool R_CreateBSPImage(const void* pixels, size_t pixels_size, int width, int height, int depth, BSPBitmapDataType type, BSPBitmapDataFormat format, A_OUT texture_t* tex) {
    if (type == BSP_BITMAP_DATA_TYPE_2D_TEXTURE)
        assert(depth == 1);

    assert(type == BSP_BITMAP_DATA_TYPE_2D_TEXTURE ||
           type == BSP_BITMAP_DATA_TYPE_3D_TEXTURE);

    GLenum target = 0;
    if (type == BSP_BITMAP_DATA_TYPE_2D_TEXTURE) {
        target = GL_TEXTURE_2D;
    } else if (type == BSP_BITMAP_DATA_TYPE_3D_TEXTURE) {
        target = GL_TEXTURE_3D;
    } else {
        assert(false);
        return false;
    }

    GL_CALL(glActiveTexture, GL_TEXTURE0);
    GL_CALL(glGenTextures,   1, tex);
    GL_CALL(glBindTexture,   target, *tex);
    GL_CALL(glTexParameteri, target, GL_TEXTURE_WRAP_S,     GL_REPEAT);
    GL_CALL(glTexParameteri, target, GL_TEXTURE_WRAP_T,     GL_REPEAT);
    GL_CALL(glTexParameteri, target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    GL_CALL(glTexParameteri, target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    image_format_t gl_format = R_BSPToGLImageFormat(format);
    
    if (type == BSP_BITMAP_DATA_TYPE_2D_TEXTURE) {
        if (CL_BitmapDataFormatIsCompressed(format)) {
            GL_CALL(glCompressedTexImage2D, GL_TEXTURE_2D, 0, gl_format, width, height, 0, pixels_size, pixels);
        } else {
            GL_CALL(glTexImage2D, GL_TEXTURE_2D, 0, gl_format, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);
        }
    } else {
        if (CL_BitmapDataFormatIsCompressed(format)) {
            GL_CALL(glCompressedTexImage3D, GL_TEXTURE_3D, 0, gl_format, width, height, depth, 0, pixels_size, pixels);
        } else {
            GL_CALL(glTexImage3D, GL_TEXTURE_3D, 0, gl_format, width, height, depth, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);
        }
    }

    GL_CALL(glGenerateMipmap, target);
    
    return true;
}

bool R_DeleteImage(
    A_IN texture_t& tex
) {
    GL_CALL(glDeleteTextures, 1, &tex);
    return true;
}

void R_DrawCube(const glm::vec3& pos, float angle, texture_t tex) {
    glEnable(GL_DEPTH_TEST);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tex);
    glBindVertexArray(r_cubePrim.vao);
    glBindBuffer(GL_ARRAY_BUFFER, r_cubePrim.vbo);
    glUseProgram(r_cubePrim.prog.program);

    glm::mat4 model = glm::translate(glm::mat4(1.0f), pos);
    model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0, 0.3, 0.5));
    R_SetUniform(r_cubePrim.prog.program, "uModel", model);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    glUseProgram(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_DEPTH_TEST);
}

struct GfxMaterial {
    vao_t     vao;
    vbo_t     vbo;
    GLsizei   vertices_count;
    texture_t tex;
};

struct GfxLightmap {
    GfxMaterial*     materials;
    uint32_t         material_count;
};

struct MapRenderGlob {
    GfxLightmap*     lightmaps;
    uint32_t         lightmap_count;
    GfxShaderProgram prog;
} r_mapGlob;

void R_InitMap() {
    std::string vertSource = DB_LoadShader("bsp.vs.glsl");
    std::string fragSource = DB_LoadShader("bsp.fs.glsl");

    std::string errorLog;
    if (!R_CreateShaderProgram(
        vertSource, fragSource, &errorLog, r_mapGlob.prog
    )) {
        Com_Errorln(errorLog);
    }

    GL_CALL(glUseProgram, r_mapGlob.prog.program);
    R_SetUniform(r_mapGlob.prog.program, 
                 "uWireframe", Dvar_GetBool(*r_wireframe));
    GL_CALL(glUseProgram, 0);
}

static void R_SwapYZPoint3(A_INOUT apoint3f_t* p) {
    float tmp = p->y;
    p->y = p->z;
    p->z = tmp;
}

static void R_SwapYZVec3(A_INOUT avec3f_t* p) {
    float tmp = p->y;
    p->y = p->z;
    p->z = tmp;
}

static void R_SwapRenderedVertexYZ(A_INOUT BSPRenderedVertex* v) {
    R_SwapYZPoint3(&v->pos);
    R_SwapYZVec3(&v->normal);
    R_SwapYZVec3(&v->binormal);
    R_SwapYZVec3(&v->tangent);
}

static void R_SwapLightmapVertexYZ(A_INOUT BSPLightmapVertex* v) {
    R_SwapYZVec3(&v->normal);
}

void R_LoadMap() {
    r_mapGlob.lightmap_count = CL_Map_LightmapCount();
    r_mapGlob.lightmaps = (GfxLightmap*)Z_Alloc(
        r_mapGlob.lightmap_count * sizeof(*r_mapGlob.lightmaps)
    );
    for (uint32_t i = 0; i < r_mapGlob.lightmap_count; i++) {
        const BSPLightmap* lightmap = CL_Map_Lightmap(i);
        r_mapGlob.lightmaps[i].materials = (GfxMaterial*)Z_Alloc(
            lightmap->materials.count *
            sizeof(*r_mapGlob.lightmaps[i].materials)
        );
        r_mapGlob.lightmaps[i].material_count = lightmap->materials.count;
        const BSPMaterial* materials = (const BSPMaterial*)lightmap->materials.pointer;
        for (uint32_t j = 0; j < lightmap->materials.count; j++) {
            GL_CALL(glGenVertexArrays,
                1, &r_mapGlob.lightmaps[i].materials[j].vao);
            GL_CALL(glGenBuffers,
                1, &r_mapGlob.lightmaps[i].materials[j].vbo);

            GL_CALL(glBindVertexArray,
                r_mapGlob.lightmaps[i].materials[j].vao);
            GL_CALL(glBindBuffer,
                GL_ARRAY_BUFFER, r_mapGlob.lightmaps[i].materials[j].vbo);

            const BSPMaterial* material = &materials[j];
            uint32_t start_surf = material->surfaces;
            uint32_t surf_count = material->surface_count;
            BSPRenderedVertex* rendered_vertices =
                (BSPRenderedVertex*)Z_Alloc(
                    3 * surf_count * sizeof(BSPRenderedVertex));
            BSPLightmapVertex* lightmap_vertices =
                (BSPLightmapVertex*)Z_Alloc(
                    3 * surf_count * sizeof(BSPLightmapVertex));
            const BSPRenderedVertex* bsp_rendered_vertices =
                (BSPRenderedVertex*)material->uncompressed_vertices.pointer;
            const BSPLightmapVertex* bsp_lightmap_vertices =
                (BSPLightmapVertex*)
                (rendered_vertices + material->rendered_vertices_count);

            const BSPSurf* surfs = &CL_Map_Surfs()[start_surf];
            for (uint32_t k = 0; k < surf_count; k++) {
                for (int l = 0; l < 3; l++) {
                    rendered_vertices[k * 3 + l] =
                        bsp_rendered_vertices[surfs[k].verts[l]];
                    R_SwapRenderedVertexYZ(&rendered_vertices[k * 3 + l]);
                }
            }
            for (uint32_t k = 0; k < surf_count; k++) {
                for (int l = 0; l < 3; l++) {
                    lightmap_vertices[k * 3 + l] =
                        bsp_lightmap_vertices[surfs[k].verts[l]];
                    R_SwapLightmapVertexYZ(&lightmap_vertices[k * 3 + l]);
                }
            }

            r_mapGlob.lightmaps[i].materials[j].vertices_count =
                surf_count * 3;

            GLsizei rendered_vertices_size =
                r_mapGlob.lightmaps[i].materials[j].vertices_count *
                sizeof(BSPRenderedVertex);
            GLsizei lightmap_vertices_size =
                r_mapGlob.lightmaps[i].materials[j].vertices_count *
                sizeof(BSPLightmapVertex);
            GLsizei vertices_size =
                rendered_vertices_size + lightmap_vertices_size;

            Tag* shader_tag = CL_Map_Tag(material->shader.id);
            assert(shader_tag);
            assert(shader_tag->secondary_class == TAG_FOURCC_SHADER);
            if (shader_tag->primary_class == TAG_FOURCC_SHADER_ENVIRONMENT) {
                BSPShaderEnvironment* shader = (BSPShaderEnvironment*)shader_tag->tag_data;
                assert(shader);
                Tag* base_map_tag = CL_Map_Tag(shader->base_map.id);
                assert(base_map_tag);
                assert(base_map_tag->primary_class == TAG_FOURCC_BITMAP);
                BSPBitmap* bitmap = (BSPBitmap*)base_map_tag->tag_data;
                assert(bitmap);
                BSPBitmapData* bitmap_data = (BSPBitmapData*)bitmap->bitmap_data.pointer;
                if (bitmap_data->type == BSP_BITMAP_DATA_TYPE_2D_TEXTURE || bitmap_data->type == BSP_BITMAP_DATA_TYPE_3D_TEXTURE) {
                    bool b = R_CreateBSPImage(
                        bitmap_data->pixels,
                        bitmap_data->actual_size,
                        bitmap_data->width,
                        bitmap_data->height,
                        bitmap_data->depth,
                        bitmap_data->type,
                        bitmap_data->format,
                        &r_mapGlob.lightmaps[i].materials[j].tex
                    );
                    assert(b);
                    (void)b;
                }
            } else {
                const char* shader_path = (const char*)shader_tag->tag_path;
                Com_DPrintln("R_LoadMap: Cannot create shader {}: shader type 0x{:08X} unsupported.", shader_path, shader_tag->primary_class);
                r_mapGlob.lightmaps[i].materials[j].tex = 0;
            }

            GL_CALL(glBufferData,
                GL_ARRAY_BUFFER, vertices_size, nullptr, GL_STATIC_DRAW
            );

            GL_CALL(glBufferSubData,
                GL_ARRAY_BUFFER, 0, rendered_vertices_size,
                (const void*)rendered_vertices
            );

            glBufferSubData(GL_ARRAY_BUFFER,
                rendered_vertices_size, lightmap_vertices_size,
                (const void*)lightmap_vertices
            );

            Z_Free(rendered_vertices);
            Z_Free(lightmap_vertices);

            GL_CALL(glVertexAttribPointer,
                0, 3, GL_FLOAT, GL_FALSE, sizeof(BSPRenderedVertex),
                (const void*)offsetof(BSPRenderedVertex, pos)
            );
            GL_CALL(glVertexAttribPointer,
                1, 3, GL_FLOAT, GL_FALSE, sizeof(BSPRenderedVertex),
                (const void*)offsetof(BSPRenderedVertex, normal)
            );
            GL_CALL(glVertexAttribPointer,
                2, 3, GL_FLOAT, GL_FALSE, sizeof(BSPRenderedVertex),
                (const void*)offsetof(BSPRenderedVertex, binormal)
            );
            GL_CALL(glVertexAttribPointer,
                3, 3, GL_FLOAT, GL_FALSE, sizeof(BSPRenderedVertex),
                (const void*)offsetof(BSPRenderedVertex, tangent)
            );
            GL_CALL(glVertexAttribPointer,
                4, 2, GL_FLOAT, GL_FALSE, sizeof(BSPRenderedVertex),
                (const void*)offsetof(BSPRenderedVertex, tex_coords)
            );
            GL_CALL(glVertexAttribPointer,
                5, 3, GL_FLOAT, GL_FALSE, sizeof(BSPLightmapVertex),
                (const void*)(rendered_vertices_size +
                    offsetof(BSPLightmapVertex, normal))
            );
            GL_CALL(glVertexAttribPointer,
                6, 2, GL_FLOAT, GL_FALSE, sizeof(BSPLightmapVertex),
                (const void*)(rendered_vertices_size +
                    offsetof(BSPLightmapVertex, tex_coords))
            );

            GL_CALL(glEnableVertexAttribArray, 0);
            GL_CALL(glEnableVertexAttribArray, 1);
            GL_CALL(glEnableVertexAttribArray, 2);
            GL_CALL(glEnableVertexAttribArray, 3);
            GL_CALL(glEnableVertexAttribArray, 4);
            GL_CALL(glEnableVertexAttribArray, 5);
            GL_CALL(glEnableVertexAttribArray, 6);
        }
    }
}

void R_UnloadMap() {
    for (uint32_t i = 0; i < r_mapGlob.lightmap_count; i++) {
        BSPLightmap* lightmap = CL_Map_Lightmap(i);
        for (uint32_t j = 0; j < lightmap->materials.count; j++) {
            glDeleteVertexArrays(1, &r_mapGlob.lightmaps[i].materials[j].vao);
            glDeleteBuffers(1, &r_mapGlob.lightmaps[i].materials[j].vbo);
            R_DeleteImage(r_mapGlob.lightmaps[i].materials[j].tex);
        }
        Z_Free((void*)r_mapGlob.lightmaps[i].materials);
    }
    Z_Free((void*)r_mapGlob.lightmaps);
}

void R_ShutdownMap() {
    if (CL_IsMapLoaded())
        R_UnloadMap();

    R_DeleteShaderProgram(r_mapGlob.prog);
}

void R_RenderMapInternal() {
    GL_CALL(glEnable,     GL_DEPTH_TEST);
    GL_CALL(glUseProgram, r_mapGlob.prog.program);
    R_SetUniform(r_mapGlob.prog.program, "uTex", 0);

    glm::mat4 model(1.0f);
    R_SetUniform(r_mapGlob.prog.program, "uModel", model);    
    for (uint32_t i = 0; i < r_mapGlob.lightmap_count; i++) {
        for (uint32_t j = 0; j < r_mapGlob.lightmaps[i].material_count; j++) {
            GL_CALL(glBindVertexArray, 
                r_mapGlob.lightmaps[i].materials[j].vao);
            GL_CALL(glBindBuffer, GL_ARRAY_BUFFER, 
                r_mapGlob.lightmaps[i].materials[j].vbo);
            GLsizei vertices_count = 
                r_mapGlob.lightmaps[i].materials[j].vertices_count;

            GL_CALL(glActiveTexture, GL_TEXTURE0);
            GL_CALL(glBindTexture, GL_TEXTURE_2D, r_mapGlob.lightmaps[i].materials[j].tex);

            R_SetUniform(r_mapGlob.prog.program, "uWireframe", false);
            GL_CALL(glDrawArrays, GL_TRIANGLES, 0, vertices_count);
            if (Dvar_GetBool(*r_wireframe)) {
                R_SetUniform(r_mapGlob.prog.program, "uWireframe", true);
                GL_CALL(glPolygonMode, GL_FRONT_AND_BACK, GL_LINE);
                GL_CALL(glDrawArrays,  GL_TRIANGLES,      0, vertices_count);
                GL_CALL(glPolygonMode, GL_FRONT_AND_BACK, GL_FILL);
            }
        }
    }

    GL_CALL(glUseProgram, 0);
    GL_CALL(glDisable, GL_DEPTH_TEST);
}

void R_RenderMap() {
    if (!CL_IsMapLoaded())
        return;

    R_RenderMapInternal();
}

static void R_DrawFrameInternal(size_t localClientNum) {
    cg_t& cg = CG_GetLocalClientGlobals(localClientNum);

    GLint x   = (GLint)  (cg.viewport.x * Dvar_GetInt(*vid_width));
    GLint y   = (GLint)  (cg.viewport.y * Dvar_GetInt(*vid_height));
    GLsizei w = (GLsizei)(cg.viewport.w * Dvar_GetInt(*vid_width));
    GLsizei h = (GLsizei)(cg.viewport.h * Dvar_GetInt(*vid_height));

    if (Dvar_WasModified(*cg.fov)) {
        R_UpdateProjection(localClientNum);
        Dvar_ClearModified(*cg.fov);
    }

    GL_CALL(glViewport, x, y, w, h);
    GL_CALL(glScissor,  x, y, w, h);
    GL_CALL(glClear, GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    static const std::array<glm::vec3, 10> cubePositions = {
        glm::vec3( 0.0f,  0.0f,  0.0f ),
        glm::vec3( 2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f ),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f ),
        glm::vec3(-1.7f,  3.0f, -7.5f ),
        glm::vec3( 1.3f, -2.0f, -2.5f ),
        glm::vec3( 1.5f,  2.0f, -2.5f ),
        glm::vec3( 1.5f,  0.2f, -1.5f ),
        glm::vec3(-1.3f,  1.0f, -1.5f )
    };

    /*
    R_DrawText(
        NULL, "Testing 123...", 
        25.0, 25.0, 1.0, 1.0, 
        glm::vec3(0.5, 0.8f, 0.2f)
    );
    */

    glm::vec3 pos    = cg.camera.pos;
    glm::vec3 center = pos + cg.camera.front;
    glm::vec3 up     = cg.camera.up;
    glm::mat4 view   = glm::lookAt(pos, center, up);

    GL_CALL(glUseProgram, r_mapGlob.prog.program);
    R_SetUniform(r_mapGlob.prog.program, "uView", view);
    R_SetUniform(
        r_mapGlob.prog.program, "uPerspectiveProjection",
        cg.camera.perspectiveProjection
    );

    GL_CALL(glUseProgram, r_cubePrim.prog.program);
    R_SetUniform(r_cubePrim.prog.program, "uView", view);
    R_SetUniform(
        r_cubePrim.prog.program, "uPerspectiveProjection", 
        cg.camera.perspectiveProjection
    );

    GL_CALL(glActiveTexture, GL_TEXTURE0);
    GL_CALL(glBindTexture, GL_TEXTURE_2D, r_cubePrim.tex);
    for (int i = 0; i < (int)cubePositions.size(); i++) 
        R_DrawCube(cubePositions[i], 20.0f * (float)i, r_cubePrim.tex);

    GL_CALL(glUseProgram, 0);

    R_RenderMap();
    
    

    R_DrawTextDrawDefs(localClientNum);
}

static void R_UnregisterDvars() {
    Dvar_Unregister("r_wireframe");
    Dvar_Unregister("r_renderDistance");
    Dvar_Unregister("r_noBorder");
    Dvar_Unregister("r_fullscreen");
    Dvar_Unregister("r_vsync");
    r_wireframe      = NULL;
    r_renderDistance = NULL;
    r_noBorder       = NULL;
    r_fullscreen     = NULL;
    r_vsync          = NULL;
}

void R_Shutdown() {
    for(size_t i = 0; i < MAX_LOCAL_CLIENTS; i++)
        R_ClearTextDrawDefs(i);

    R_ShutdownMap();
    R_ShutdownCubes(r_cubePrim);

    R_UnregisterDvars();
    IMG_Quit();
    RB_Shutdown();
}
