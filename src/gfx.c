#include "gfx.h"

#include <assert.h>
#include <stdio.h>
#include <stddef.h>

#include <GL/glew.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "acommon/a_string.h"

#include "cg_cgame.h"
#include "cl_client.h"
#include "cl_map.h"
#include "com_print.h"
#include "db_files.h"
#include "dvar.h"
#include "font.h"
#include "gfx_backend.h"
#include "gfx_shader.h"
#include "gfx_text.h"
#include "gfx_uniform.h"
#include "m_math.h"
#include "sys.h"

A_EXTERN_C dvar_t* vid_width;
A_EXTERN_C dvar_t* vid_height;

A_NO_DISCARD const char* R_GlDebugErrorString(GLenum err) {
    switch (err) {
    case GL_NO_ERROR:
        return "GL_NO_ERROR";
    case GL_INVALID_ENUM:
        return "GL_INVALID_ENUM";
    case GL_INVALID_VALUE:
        return "GL_INVALID_VALUE";
    case GL_INVALID_OPERATION:
        return "GL_INVALID_OPERATION";
    case GL_STACK_OVERFLOW:
        return "GL_STACK_OVERFLOW";
    case GL_STACK_UNDERFLOW:
        return "GL_STACK_UNDERFLOW";
    case GL_OUT_OF_MEMORY:
        return "GL_OUT_OF_MEMORY";
    case GL_INVALID_FRAMEBUFFER_OPERATION:
        return "GL_INVALID_FRAMEBUFFER_OPERATION";
    default:
        Com_DPrintln(CON_DEST_CLIENT, "R_GlErrorStr called with unknown value (err=%d)", err);
        return "";
    }
}

A_NO_DISCARD static const char* R_GlDebugSourceString(GLenum source) {
    switch (source) {
    case GL_DEBUG_SOURCE_API:
        return "API";
    case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
        return "WindowSystem";
    case GL_DEBUG_SOURCE_SHADER_COMPILER:
        return "ShaderCompiler";
    case GL_DEBUG_SOURCE_THIRD_PARTY:
        return "ThirdParty";
    case GL_DEBUG_SOURCE_APPLICATION:
        return "Application";
    case GL_DEBUG_SOURCE_OTHER:
        return "Other";
    default:
        return "<unknown>";
    };
}

A_NO_DISCARD static const char* R_GlDebugTypeString(GLenum type) {
    switch (type) {
    case GL_DEBUG_TYPE_ERROR:
        return "Error";
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
        return "DeprecatedBehaviour";
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
        return "UndefinedBehaviour";
    case GL_DEBUG_TYPE_PORTABILITY:
        return "Portability";
    case GL_DEBUG_TYPE_PERFORMANCE:
        return "Performance";
    case GL_DEBUG_TYPE_MARKER:
        return "Marker";
    case GL_DEBUG_TYPE_PUSH_GROUP:
        return "PushGroup";
    case GL_DEBUG_TYPE_POP_GROUP:
        return "PopGroup";
    case GL_DEBUG_TYPE_OTHER:
        return "Other";
    default:
        return "<unknown>";
    };
}

A_NO_DISCARD static const char* R_GlDebugSeverityString(GLenum severity) {
    switch (severity) {
    case GL_DEBUG_SEVERITY_HIGH:
        return "High";
    case GL_DEBUG_SEVERITY_MEDIUM:
        return "Medium";
    case GL_DEBUG_SEVERITY_LOW:
        return "Low";
    case GL_DEBUG_SEVERITY_NOTIFICATION:
        return "Notification";
    default:
        return "<unknown>";
    };
}

static void GLAPIENTRY R_GlDebugOutput(
    GLenum source, GLenum type, unsigned int id, GLenum severity,
    GLsizei length, const char* message, const void* user
) {
    A_UNUSED(length);
    A_UNUSED(user);

    if (/*id == 131169 ||*/ id == 131185 || /*
        id == 131218 ||*/ id == 131204/* || id == 131139 */
    ) {
        return;
    }

    const char* i   = R_GlDebugErrorString(id);
    const char* src = R_GlDebugSourceString(source);
    const char* t   = R_GlDebugTypeString(type);
    const char* sev = R_GlDebugSeverityString(severity);
    
    Com_DPrintln(CON_DEST_CLIENT,
        "OpenGL debug message (id=%s, source=%s, type=%s, severity=%s): %s", 
        i, src, t, sev, message
    );
}

static void R_RegisterDvars        ();
static void R_InitMap              ();
static void R_DrawFrameInternal    (size_t localClientNum);
static void R_InitLocalClient      (size_t localClientNum);
static void R_UpdateLocalClientView(size_t localClientNum);

#define R_NEAR_PLANE_DEFAULT 0.1f
#define R_FAR_PLANE_DEFAULT  1000.0f

dvar_t* r_vsync;
dvar_t* r_fullscreen;
dvar_t* r_noBorder;
dvar_t* r_renderDistance;
dvar_t* r_wireframe;

extern FontDef r_defaultFont;

size_t r_testDrawId = 0;

A_EXTERN_C void R_Init(void) {
    RB_Init();

    int imgInitFlags = IMG_INIT_JPG | IMG_INIT_PNG;
    if ((IMG_Init(imgInitFlags) & imgInitFlags) != imgInitFlags)
        Com_Errorln(-1, "SDL_image init failed.");

#if _DEBUG
    //GLint flags = 0;
    //GL_CALL(glGetIntegerv, GL_CONTEXT_FLAGS, &flags);
    //if ((flags & GL_CONTEXT_FLAG_DEBUG_BIT) == 0)
    //    Com_Errorln("Failed to initialize OpenGL debug context in debug build.");

    GLint num_extensions = 0;
    GL_CALL(glGetIntegerv, GL_NUM_EXTENSIONS, &num_extensions);
    for (GLint i = 0; i < num_extensions; i++)
        Com_Println(CON_DEST_CLIENT, "%s ", (const char*)glGetStringi(GL_EXTENSIONS, i));

    GL_CALL(glEnable, GL_DEBUG_OUTPUT);
    GL_CALL(glEnable, GL_DEBUG_OUTPUT_SYNCHRONOUS);
    GL_CALL(glDebugMessageCallback, R_GlDebugOutput, NULL);
    GL_CALL(glDebugMessageControl, GL_DONT_CARE, GL_DONT_CARE, 
            GL_DONT_CARE, 0, NULL, (GLboolean)GL_TRUE);
#endif // _DEBUG

    GL_CALL(glClearColor, 0.2f, 0.3f, 0.3f, 1.0f);
    
    for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
        R_InitLocalClient(i);
        R_ClearTextDrawDefs(i);
    }

    R_RegisterDvars();

    bool b = Font_Load("consola.ttf", 0, 48, &r_defaultFont);
    assert(b);
    (void)b;

    RectDef rect = { .x = 0.1f, .y = 0.1f, .w = 0.8f, .h = 0.2f };
    acolor_rgb_t color = A_color_rgb(0.77, 0.77, 0.2);
    R_AddTextDrawDef(
        0, NULL, &rect, "This is a test.\nWhere the fuck i am?", 1.0f, 1.0f,
        color, true, false, &r_testDrawId
    );
    R_InitMap();

    //glEnable(GL_POINT_SMOOTH);
    //glPointSize(4);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
}

static void R_InitLocalClient(size_t localClientNum) {
    cg_t* cg      = CG_GetLocalClientGlobals(localClientNum);
    cg->nearPlane = R_NEAR_PLANE_DEFAULT;
    cg->farPlane  = R_FAR_PLANE_DEFAULT;
    R_UpdateLocalClientView(localClientNum);
}

static void R_UpdateOrtho(size_t localClientNum) {
    cg_t* cg = CG_GetLocalClientGlobals(localClientNum);

    float left = cg->viewport.x * Dvar_GetInt(vid_width);
    float right  = cg->viewport.w * Dvar_GetInt(vid_width)  + left;
    float bottom = cg->viewport.y * Dvar_GetInt(vid_height);
    float top    = cg->viewport.h * Dvar_GetInt(vid_height) + bottom;
    cg->camera.orthoProjection = A_mat4f_ortho(left, right, bottom, top);
}

void R_UpdateProjection(size_t localClientNum) {
    cg_t* cg = CG_GetLocalClientGlobals(localClientNum);

    float w = cg->viewport.w * Dvar_GetInt(vid_width);
    float h = cg->viewport.h * Dvar_GetInt(vid_height);
    cg->camera.perspectiveProjection = A_mat4f_perspective(
        A_radians(cg->fovy), w / h, cg->nearPlane, cg->farPlane
    );
}

static void R_UpdateLocalClientView(size_t localClientNum) {
    R_UpdateOrtho(localClientNum);
    R_UpdateProjection(localClientNum);
}

static void R_RegisterDvars(void) {
    r_vsync          = Dvar_RegisterBool("r_vsync", DVAR_FLAG_NONE, true);
    r_fullscreen     = Dvar_RegisterBool("r_fullscreen", DVAR_FLAG_NONE, false);
    r_noBorder       = Dvar_RegisterBool("r_noBorder", DVAR_FLAG_NONE, false);
    r_renderDistance = Dvar_RegisterFloat("r_renderDistance", DVAR_FLAG_NONE, R_FAR_PLANE_DEFAULT, 10.0f, 1000000.0f);
    r_wireframe      = Dvar_RegisterBool("r_wireframe", DVAR_FLAG_NONE, false);
}

A_EXTERN_C void R_DrawFrame(size_t localClientNum) {
    R_DrawFrameInternal(localClientNum);
}

A_EXTERN_C void R_Frame(void) {
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

A_EXTERN_C void R_WindowResized(void) {
    for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++)
        R_UpdateLocalClientView(i);
    
}

A_NO_DISCARD bool R_CreateSdlImage(const char* image_name, 
                                A_INOUT GfxImage* image
) {
    assert(image_name);
    if (!image_name)
        return false;

    assert(image);
    if (!image)
        return false;

    A_memset(image, 0, sizeof(*image));

    texture_t tex;
    GL_CALL(glActiveTexture, GL_TEXTURE0);
    GL_CALL(glGenTextures,   1, &tex);
    GL_CALL(glBindTexture,   GL_TEXTURE_2D, tex);

    GL_CALL(glTexParameteri, GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,     GL_REPEAT);
    GL_CALL(glTexParameteri, GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,     GL_REPEAT);
    GL_CALL(glTexParameteri, GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    GL_CALL(glTexParameteri, GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    const char* image_path = DB_ImagePath(image_name);
    SDL_Surface* surf = IMG_Load(image_path);

    assert(surf);
    if (!surf)
        return false;

    assert(surf->pixels);
    if (!surf->pixels)
        return false;

    assert(surf->w > 0 && surf->h > 0);
    if (surf->w < 1 || surf->h < 1)
        return false;

    ImageFormat format;
    switch (surf->format->format) {
    case SDL_PIXELFORMAT_RGB24:
        format = R_IMAGE_FORMAT_RGB888;
        break;
    case SDL_PIXELFORMAT_RGBA32:
        format = R_IMAGE_FORMAT_RGBA8888;
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

    SDL_DestroySurface(surf);

    image->width           = surf->w;
    image->height          = surf->h;
    image->depth           = 1;
    image->type            = R_IMAGE_TYPE_2D_TEXTURE;
    image->format          = format;
    image->internal_format = R_IMAGE_FORMAT_RGB888;
    image->tex             = tex;

    return true;
}

static ImageFormat R_BSPGetImageFormat(BSPBitmapDataFormat format) {
    ImageFormat img_format;
    switch (format) {
    case BSP_BITMAP_DATA_FORMAT_A8:
        img_format = R_IMAGE_FORMAT_A8;
        break;
    case BSP_BITMAP_DATA_FORMAT_R5G6B5:
        img_format = R_IMAGE_FORMAT_RGB565;
        break;
    case BSP_BITMAP_DATA_FORMAT_DXT1:
        img_format = R_IMAGE_FORMAT_DXT1;
        break;
    case BSP_BITMAP_DATA_FORMAT_DXT3:
        img_format = R_IMAGE_FORMAT_DXT3;
        break;
    case BSP_BITMAP_DATA_FORMAT_DXT5:
        img_format = R_IMAGE_FORMAT_DXT5;
        break;
    default:
        Com_Errorln(-1,
            "R_BSPGetImageFormat: Unimplemented BSPBitmapDataFormat %d.",
            (int)format
        );
    };

    return img_format;
}

static ImageType R_BSPGetImageType(BSPBitmapDataType type) {
    ImageType img_type;
    switch (type) {
    case BSP_BITMAP_DATA_TYPE_2D_TEXTURE:
        img_type = R_IMAGE_TYPE_2D_TEXTURE;
        break;
    case BSP_BITMAP_DATA_TYPE_3D_TEXTURE:
        img_type = R_IMAGE_TYPE_3D_TEXTURE;
        break;
    case BSP_BITMAP_DATA_TYPE_CUBE_MAP:
        img_type = R_IMAGE_TYPE_CUBE_MAP;
        break;
    default:
        Com_Errorln(-1, 
            "R_BSPGetImageType: Unimplemented BSPBitmapDataType %d.", 
            (int)type
        );
    }

    return img_type;
}

A_NO_DISCARD bool R_CreateBSPImage(
    const void* pixels, size_t pixels_size, int width, int height, int depth, 
    BSPBitmapDataType type, BSPBitmapDataFormat bsp_format, 
    A_OUT GfxImage* image
) {
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

    texture_t tex;
    GL_CALL(glActiveTexture, GL_TEXTURE0);
    GL_CALL(glGenTextures,   1, &tex);
    GL_CALL(glBindTexture,   target, tex);
    GL_CALL(glTexParameteri, target, GL_TEXTURE_WRAP_S,     GL_REPEAT);
    GL_CALL(glTexParameteri, target, GL_TEXTURE_WRAP_T,     GL_REPEAT);
    GL_CALL(glTexParameteri, target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    GL_CALL(glTexParameteri, target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    bool compressed = CL_BitmapDataFormatIsCompressed(bsp_format);
    GLenum internal_format = 
        R_ImageFormatToGl(R_BSPGetImageFormat(bsp_format));
    GLenum gl_format = compressed ? internal_format : GL_RGB;
    ImageFormat format = R_ImageFormatFromGl(gl_format);

    if (type == BSP_BITMAP_DATA_TYPE_2D_TEXTURE) {
        if (compressed) {
            GL_CALL(glCompressedTexImage2D, GL_TEXTURE_2D, 0, 
                    internal_format, width, height, 0, pixels_size, pixels);
        } else {
            GL_CALL(glTexImage2D, GL_TEXTURE_2D, 0, internal_format, 
                    width, height, 0, gl_format, GL_UNSIGNED_BYTE, pixels);
        }
    } else {
        if (compressed) {
            GL_CALL(glCompressedTexImage3D, GL_TEXTURE_3D, 0, internal_format,
                    width, height, depth, 0, pixels_size, pixels);
        } else {
            GL_CALL(glTexImage3D, GL_TEXTURE_3D, 0, internal_format, width, 
                   height, depth, 0, gl_format, GL_UNSIGNED_BYTE, pixels);
        }
    }

    GL_CALL(glGenerateMipmap, target);

    image->tex             = tex;
    image->pixels          = pixels;
    image->pixels_size     = pixels_size;
    image->width           = width;
    image->height          = height;
    image->depth           = depth;
    image->type            = R_BSPGetImageType(type);
    image->internal_format = R_BSPGetImageFormat(bsp_format);
    image->format          = format;
    return true;
}

typedef struct GfxMaterial {
    GfxVertexBuffer         vb;
    GLsizei                 vertices_count;
    bool                    alpha_tested;
    GfxImage                map, base_map, primary_detail_map;
    GfxImage                secondary_detail_map, micro_detail_map, bump_map;
    BSPShaderDetailFunction detail_map_function, micro_detail_map_function;
    acolor_rgb_t            color;
    acolor_rgb_t            ambient_color;
    avec3f_t                distant_light_0_dir;
    avec3f_t                distant_light_1_dir;
    acolor_rgb_t            distant_light_0_color;
    acolor_rgb_t            distant_light_1_color;
} GfxMaterial;

typedef struct GfxLightmap {
    GfxMaterial*     materials;
    uint32_t         material_count;
} GfxLightmap;

struct MapRenderGlob {
    GfxLightmap*     lightmaps;
    uint32_t         lightmap_count;
    GfxShaderProgram prog;
} r_mapGlob;

A_EXTERN_C void R_InitMap(void) {
    char* vertSource = DB_LoadShader("bsp.vs.glsl");
    char* fragSource = DB_LoadShader("bsp.fs.glsl");

    char* errorLog = NULL;
    if (!R_CreateShaderProgram(vertSource, fragSource, 
                               &errorLog, &r_mapGlob.prog)
    ) {
        Com_Errorln(-1, errorLog);
    }
    A_cstrfree(errorLog);
    DB_UnloadShader(vertSource);
    DB_UnloadShader(fragSource);
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

A_EXTERN_C bool R_LoadBitmap(TagId tag_id, A_OUT GfxImage* image) {
    assert(image);
    if (!image)
        return false;
    A_memset(image, 0, sizeof(*image));

    Tag* tag = CL_Map_Tag(tag_id);
    assert(tag);
    if (!tag)
        return false;
    assert(tag->primary_class == TAG_FOURCC_BITMAP);
    if (tag->primary_class != TAG_FOURCC_BITMAP)
        return false;
    BSPBitmap* bitmap = (BSPBitmap*)tag->tag_data;
    assert(bitmap);
    if (!bitmap)
        return false;
    BSPBitmapData* bitmap_data = (BSPBitmapData*)bitmap->bitmap_data.pointer;
    if (!bitmap_data)
        return false;
    if (bitmap_data->pixels != (void*)0xFFFFFFFF && 
        (bitmap_data->type == BSP_BITMAP_DATA_TYPE_2D_TEXTURE || 
        bitmap_data->type == BSP_BITMAP_DATA_TYPE_3D_TEXTURE)
    ) {
        bool b = R_CreateBSPImage(
            bitmap_data->pixels,
            bitmap_data->actual_size,
            bitmap_data->width,
            bitmap_data->height,
            bitmap_data->depth,
            bitmap_data->type,
            bitmap_data->format,
            image
        );
        assert(b);
        (void)b;
    }
    return true;
}

A_EXTERN_C void R_LoadMap(void) {
    r_mapGlob.lightmap_count = CL_Map_LightmapCount();
    r_mapGlob.lightmaps = (GfxLightmap*)Z_Zalloc(
        r_mapGlob.lightmap_count * sizeof(*r_mapGlob.lightmaps)
    );
    for (uint32_t i = 0; i < r_mapGlob.lightmap_count; i++) {
        const BSPLightmap* lightmap = CL_Map_Lightmap(i);
        r_mapGlob.lightmaps[i].materials = (GfxMaterial*)Z_Zalloc(
            lightmap->materials.count *
            sizeof(*r_mapGlob.lightmaps[i].materials)
        );
        r_mapGlob.lightmaps[i].material_count = lightmap->materials.count;
        const BSPMaterial* materials = (const BSPMaterial*)lightmap->materials.pointer;
        for (uint32_t j = 0; j < lightmap->materials.count; j++) {
            GL_CALL(glGenVertexArrays,
                1, &r_mapGlob.lightmaps[i].materials[j].vb.vao);
            GL_CALL(glGenBuffers,
                1, &r_mapGlob.lightmaps[i].materials[j].vb.vbo);

            GL_CALL(glBindVertexArray,
                r_mapGlob.lightmaps[i].materials[j].vb.vao);
            GL_CALL(glBindBuffer,
                GL_ARRAY_BUFFER, r_mapGlob.lightmaps[i].materials[j].vb.vbo);

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

            r_mapGlob.lightmaps[i].materials[j].color =
                material->ambient_color;

            r_mapGlob.lightmaps[i].materials[j].ambient_color = 
                material->ambient_color;

            r_mapGlob.lightmaps[i].materials[j].distant_light_0_dir =
                material->distant_light_0_direction;
            r_mapGlob.lightmaps[i].materials[j].distant_light_1_dir =
                material->distant_light_1_direction;
            r_mapGlob.lightmaps[i].materials[j].distant_light_0_color =
                material->distant_light_0_color;
            r_mapGlob.lightmaps[i].materials[j].distant_light_1_color =
                material->distant_light_1_color;



            Tag* shader_tag = CL_Map_Tag(material->shader.id);
            assert(shader_tag);
            assert(shader_tag->secondary_class == TAG_FOURCC_SHADER);
            if (shader_tag->primary_class == TAG_FOURCC_SHADER_ENVIRONMENT) {
                BSPShaderEnvironment* shader = (BSPShaderEnvironment*)shader_tag->tag_data;
                assert(shader);
                r_mapGlob.lightmaps[i].materials[j].alpha_tested = 
                    shader->flags & 0x01;

                bool b = true;
                assert(shader->map.fourcc == TAG_FOURCC_BITMAP);
                if (shader->map.id.index != 0xFFFF) {
                    b = R_LoadBitmap(
                        shader->map.id,
                        &r_mapGlob.lightmaps[i].materials[j].map
                    );
                }
                assert(b);
                assert(shader->base_map.fourcc == TAG_FOURCC_BITMAP);
                if (shader->base_map.id.index != 0xFFFF) {
                    b = R_LoadBitmap(
                        shader->base_map.id,
                        &r_mapGlob.lightmaps[i].materials[j].base_map
                    );
                }
                assert(b);
                assert(shader->primary_detail_map.fourcc == TAG_FOURCC_BITMAP);
                if (shader->primary_detail_map.id.index != 0xFFFF) {
                    b = R_LoadBitmap(
                        shader->primary_detail_map.id, 
                        &r_mapGlob.lightmaps[i].materials[j].primary_detail_map
                    );
                }
                assert(b);
                assert(shader->secondary_detail_map.fourcc == TAG_FOURCC_BITMAP);
                if (shader->secondary_detail_map.id.index != 0xFFFF) {
                    b = R_LoadBitmap(
                        shader->secondary_detail_map.id, 
                        &r_mapGlob.lightmaps[i].materials[j]
                            .secondary_detail_map
                    );
                }
                assert(b);
                assert(shader->micro_detail_map.fourcc == TAG_FOURCC_BITMAP);
                if (shader->micro_detail_map.id.index != 0xFFFF) {
                    b = R_LoadBitmap(
                        shader->micro_detail_map.id,
                        &r_mapGlob.lightmaps[i].materials[j].micro_detail_map
                    );
                }
                assert(b);
                assert(shader->bump_map.fourcc == TAG_FOURCC_BITMAP);
                if (shader->bump_map.id.index != 0xFFFF) {
                    b = R_LoadBitmap(
                        shader->bump_map.id,
                        &r_mapGlob.lightmaps[i].materials[j].bump_map
                    );
                }
                assert(b);
                r_mapGlob.lightmaps[i].materials[j].detail_map_function =
                    shader->detail_map_function;
                r_mapGlob.lightmaps[i].materials[j].micro_detail_map_function =
                    shader->micro_detail_map_function;
                (void)b;
            } else {
                const char* shader_path = (const char*)shader_tag->tag_path;
                Com_DPrintln(CON_DEST_CLIENT,
                    "R_LoadMap: Cannot create shader %s: shader type 0x%08X unsupported.",
                    shader_path, (uint32_t)shader_tag->primary_class
                );
            }

            GL_CALL(glBufferData,
                GL_ARRAY_BUFFER, vertices_size, NULL, GL_STATIC_DRAW
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

A_EXTERN_C void R_RenderMapInternal(void) {
    GL_CALL(glEnable,     GL_DEPTH_TEST);
    GL_CALL(glEnable,     GL_CULL_FACE);
    GL_CALL(glUseProgram, r_mapGlob.prog.program);
    R_SetUniformInt(r_mapGlob.prog.program, "uMap",                0);
    R_SetUniformInt(r_mapGlob.prog.program, "uBaseMap",            1);
    R_SetUniformInt(r_mapGlob.prog.program, "uPrimaryDetailMap",   2);
    R_SetUniformInt(r_mapGlob.prog.program, "uSecondaryDetailMap", 3);
    R_SetUniformInt(r_mapGlob.prog.program, "uMicroDetailMap",     4);
    R_SetUniformInt(r_mapGlob.prog.program, "uBumpMap",            5);

    amat4f_t model = A_MAT4F_IDENTITY;
    R_SetUniformMat4f(r_mapGlob.prog.program, "uModel", model);    
    for (uint32_t i = 0; i < r_mapGlob.lightmap_count; i++) {
        for (uint32_t j = 0; j < r_mapGlob.lightmaps[i].material_count; j++) {
            GL_CALL(glBindVertexArray, 
                r_mapGlob.lightmaps[i].materials[j].vb.vao);
            GL_CALL(glBindBuffer, GL_ARRAY_BUFFER, 
                r_mapGlob.lightmaps[i].materials[j].vb.vbo);

            R_SetUniformBool(r_mapGlob.prog.program, "uAlphaTested",
                r_mapGlob.lightmaps[i].materials[j].alpha_tested);

            R_SetUniformInt(r_mapGlob.prog.program, "uDetailMapFunction",
                (int)r_mapGlob.lightmaps[i].materials[j].detail_map_function);
            R_SetUniformInt(r_mapGlob.prog.program, "uMicroDetailMapFunction",
                (int)r_mapGlob.lightmaps[i].materials[j].micro_detail_map_function);

            avec3f_t color = A_vec3(
                r_mapGlob.lightmaps[i].materials[j].color.r,
                r_mapGlob.lightmaps[i].materials[j].color.g,
                r_mapGlob.lightmaps[i].materials[j].color.b
            );
            R_SetUniformVec3f(r_mapGlob.prog.program, "uMaterialColor", color);

            color.x = r_mapGlob.lightmaps[i].materials[j].ambient_color.r;
            color.y = r_mapGlob.lightmaps[i].materials[j].ambient_color.g;
            color.z = r_mapGlob.lightmaps[i].materials[j].ambient_color.b;
            R_SetUniformVec3f(r_mapGlob.prog.program, "uAmbientColor", color);

            R_SetUniformVec3f(r_mapGlob.prog.program, "uDistantLight0Dir", r_mapGlob.lightmaps[i].materials[j].distant_light_0_dir);
            R_SetUniformVec3f(r_mapGlob.prog.program, "uDistantLight1Dir", r_mapGlob.lightmaps[i].materials[j].distant_light_1_dir);

            color.x = r_mapGlob.lightmaps[i].materials[j].distant_light_0_color.r;
            color.y = r_mapGlob.lightmaps[i].materials[j].distant_light_0_color.g;
            color.z = r_mapGlob.lightmaps[i].materials[j].distant_light_0_color.b;
            R_SetUniformVec3f(r_mapGlob.prog.program, "uDistantLight0Color", color);

            color.x = r_mapGlob.lightmaps[i].materials[j].distant_light_1_color.r;
            color.y = r_mapGlob.lightmaps[i].materials[j].distant_light_1_color.g;
            color.z = r_mapGlob.lightmaps[i].materials[j].distant_light_1_color.b;
            R_SetUniformVec3f(r_mapGlob.prog.program, "uDistantLight1Color", color);

            GL_CALL(glActiveTexture, GL_TEXTURE0);
            GL_CALL(glBindTexture,
                GL_TEXTURE_2D,
                r_mapGlob.lightmaps[i].materials[j].map.tex
            );
            bool has_map = 
                r_mapGlob.lightmaps[i].materials[j].map.tex != 0;
            GL_CALL(glActiveTexture, GL_TEXTURE0 + 1);
            GL_CALL(glBindTexture,   
                GL_TEXTURE_2D, 
                r_mapGlob.lightmaps[i].materials[j].base_map.tex
            );
            bool has_base_map = 
                r_mapGlob.lightmaps[i].materials[j].base_map.tex != 0;
            GL_CALL(glActiveTexture, GL_TEXTURE0 + 2);
            GL_CALL(glBindTexture,   
                GL_TEXTURE_2D, 
                r_mapGlob.lightmaps[i].materials[j].primary_detail_map.tex
            );
            bool has_primary_detail_map = 
                r_mapGlob.lightmaps[i].materials[j]
                    .primary_detail_map.tex != 0;
            GL_CALL(glActiveTexture, GL_TEXTURE0 + 3);
            GL_CALL(glBindTexture,   
                GL_TEXTURE_2D, 
                r_mapGlob.lightmaps[i].materials[j].secondary_detail_map.tex
            );
            bool has_secondary_detail_map =
                r_mapGlob.lightmaps[i].materials[j]
                    .secondary_detail_map.tex != 0;

            GL_CALL(glActiveTexture, GL_TEXTURE0 + 4);
            GL_CALL(glBindTexture,
                GL_TEXTURE_2D,
                r_mapGlob.lightmaps[i].materials[j].micro_detail_map.tex
            );

            bool has_bump_map =
                r_mapGlob.lightmaps[i].materials[j].bump_map.tex != 0;
            GL_CALL(glActiveTexture, GL_TEXTURE0 + 5);
            GL_CALL(glBindTexture,
                GL_TEXTURE_2D,
                r_mapGlob.lightmaps[i].materials[j].bump_map.tex
            );
            bool has_micro_detail_map =
                r_mapGlob.lightmaps[i].materials[j].micro_detail_map.tex != 0;
            
            bool wireframe = Dvar_GetBool(r_wireframe);
            int flags = wireframe | has_map << 1 | has_base_map << 2 |
                has_primary_detail_map << 3 | has_secondary_detail_map << 4 |
                has_micro_detail_map << 5 | has_bump_map << 6;
            R_SetUniformInt(r_mapGlob.prog.program, "uFlags", flags & 0x7E);
            GLsizei vertices_count =
                r_mapGlob.lightmaps[i].materials[j].vertices_count;
            GL_CALL(glDrawArrays, GL_TRIANGLES, 0, vertices_count);
            if (Dvar_GetBool(r_wireframe)) {
                R_SetUniformInt(r_mapGlob.prog.program, "uFlags", flags & 0x7F);
                GL_CALL(glPolygonMode, GL_FRONT_AND_BACK, GL_LINE);
                GL_CALL(glDrawArrays,  GL_TRIANGLES,      0, vertices_count);
                GL_CALL(glPolygonMode, GL_FRONT_AND_BACK, GL_FILL);
            }
        }
    }

    GL_CALL(glUseProgram, 0);
    GL_CALL(glDisable, GL_CULL_FACE);
    GL_CALL(glDisable, GL_DEPTH_TEST);
}

A_EXTERN_C void R_RenderMap(void) {
    if (!CL_IsMapLoaded())
        return;

    R_RenderMapInternal();
}

static void R_DrawFrameInternal(size_t localClientNum) {
    cg_t* cg = CG_GetLocalClientGlobals(localClientNum);

    GLint   x = (GLint)  (cg->viewport.x * Dvar_GetInt(vid_width));
    GLint   y = (GLint)  (cg->viewport.y * Dvar_GetInt(vid_height));
    GLsizei w = (GLsizei)(cg->viewport.w * Dvar_GetInt(vid_width));
    GLsizei h = (GLsizei)(cg->viewport.h * Dvar_GetInt(vid_height));

    if (Dvar_WasModified(cg->fov)) {
        R_UpdateProjection(localClientNum);
        Dvar_ClearModified(cg->fov);
    }

    GL_CALL(glViewport, x, y, w, h);
    GL_CALL(glScissor,  x, y, w, h);
    GL_CALL(glClear, GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    const RectDef rect = {
        .x = x,
        .y = y,
        .w = w,
        .h = h
    };
    acolor_rgb_t color = A_color_rgb(0.5f, 0.8f, 0.2f);
    R_DrawText(localClientNum,
        NULL, &rect, "Testing 123...", 
        1.0f, 1.0f, color, false
    );

    avec3f_t pos   = A_vec3(cg->camera.pos.x,   
                            cg->camera.pos.y,   
                            cg->camera.pos.z);
    avec3f_t front = A_vec3(cg->camera.front.x, 
                            cg->camera.front.y, 
                            cg->camera.front.z);
    avec3f_t center = A_vec3f_add(pos, front);
    amat4f_t view   = A_mat4f_look_at(pos, center, cg->camera.up);
    
    GL_CALL(glUseProgram, r_mapGlob.prog.program);
    R_SetUniformMat4f(r_mapGlob.prog.program, "uView", view);
    R_SetUniformMat4f(
        r_mapGlob.prog.program, "uPerspectiveProjection",
        cg->camera.perspectiveProjection
    );;

    GL_CALL(glUseProgram, 0);

    R_RenderMap();
    
    R_DrawTextDrawDefs(localClientNum);
}

A_EXTERN_C void R_UnloadMap(void) {
    for (uint32_t i = 0; i < r_mapGlob.lightmap_count; i++) {
        BSPLightmap* lightmap = CL_Map_Lightmap(i);
        for (uint32_t j = 0; j < lightmap->materials.count; j++) {
            R_DeleteVertexBuffer(&r_mapGlob.lightmaps[i].materials[j].vb);
            R_DeleteImage(&r_mapGlob.lightmaps[i].materials[j].map);
            R_DeleteImage(&r_mapGlob.lightmaps[i].materials[j].base_map);
            R_DeleteImage(
                &r_mapGlob.lightmaps[i].materials[j].primary_detail_map);
            R_DeleteImage(
                &r_mapGlob.lightmaps[i].materials[j].secondary_detail_map);
            R_DeleteImage(
                &r_mapGlob.lightmaps[i].materials[j].micro_detail_map);
        }
        Z_Free((void*)r_mapGlob.lightmaps[i].materials);
    }
    Z_Free((void*)r_mapGlob.lightmaps);
}

A_EXTERN_C void R_ShutdownMap(void) {
    if (CL_IsMapLoaded())
        R_UnloadMap();

    R_DeleteShaderProgram(&r_mapGlob.prog);
}

static void R_UnregisterDvars(void) {
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

A_EXTERN_C void R_Shutdown(void) {
    for(size_t i = 0; i < MAX_LOCAL_CLIENTS; i++)
        R_ClearTextDrawDefs(i);

    R_ShutdownMap();

    R_UnregisterDvars();
    IMG_Quit();
    RB_Shutdown();
}
