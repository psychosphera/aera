#pragma once

#if A_RENDER_BACKEND_GL
#include <GL/glew.h>
#elif A_RENDER_BACKEND_D3D9
#include <d3d9.h>
#endif // A_RENDER_BACKEND_GL

#include "acommon/a_math.h"

#include "com_defs.h"

#define R_MAX_IMAGES_PER_VERTEX_BUFFER 8
#define R_MATERIAL_PASS_MAX_VBS 2

#if A_RENDER_BACKEND_GL
typedef unsigned int vbo_t;
typedef unsigned int vao_t;
typedef unsigned int ebo_t;
typedef unsigned int vertex_shader_t;
typedef unsigned int fragment_shader_t;
typedef unsigned int shader_program_t;
typedef unsigned int texture_t;
#endif // A_RENDER_BACKEND_GL

#define R_VFOV_DEFAULT 74.0f

typedef struct GfxSubTexDef {
    float x, y, u, v;
} GfxSubTexDef;

#if A_RENDER_BACKEND_D3D9
typedef struct D3D9RenderGlob {
    HWND              hWnd;
    IDirect3D9* d3d9;
    IDirect3DDevice9* d3ddev;

    D3DCOLOR          clear_color_argb;
} D3D9RenderGlob;
extern D3D9RenderGlob r_d3d9Glob;
#endif // A_RENDER_BACKEND_D3D9

typedef enum ImageFormat {
    R_IMAGE_FORMAT_UNKNOWN,
    R_IMAGE_FORMAT_DXT1,
    R_IMAGE_FORMAT_DXT3,
    R_IMAGE_FORMAT_DXT5,
    R_IMAGE_FORMAT_A8,
    R_IMAGE_FORMAT_R8,
    R_IMAGE_FORMAT_RGB565,
    R_IMAGE_FORMAT_RGB888,
    R_IMAGE_FORMAT_RGBA8888,
    R_IMAGE_FORMAT_ARGB8888,
    R_IMAGE_FORMAT_COUNT
} ImageFormat;

typedef enum ImageType {
    R_IMAGE_TYPE_2D_TEXTURE,
    R_IMAGE_TYPE_3D_TEXTURE,
    R_IMAGE_TYPE_CUBE_MAP
} ImageType;

#if A_RENDER_BACKEND_GL
typedef texture_t GfxTexture;
#elif A_RENDER_BACKEND_D3D9
typedef LPDIRECT3DTEXTURE9 GfxTexture;
#endif // A_RENDER_BACKEND_GL

typedef enum GfxFilter {
    R_IMAGE_FILTER_LINEAR
} GfxFilter;

typedef struct GfxImage {
    ImageType          type;
    GfxTexture         tex;
    bool               wrap_s, wrap_t;
    GfxFilter          minfilter, magfilter;
    ImageFormat        format, internal_format;
    const void*        pixels;
    size_t             pixels_size;
    int                width, height, depth;
} GfxImage;

typedef struct GfxVertexBuffer {
#if A_RENDER_BACKEND_GL
    vao_t  vao;
    vbo_t  vbo;
#elif A_RENDER_BACKEND_D3D9
    IDirect3DVertexBuffer9*      buffer;
#endif // A_RENDER_BACKEND_GL
    size_t bytes, capacity;
} GfxVertexBuffer;

typedef struct GfxMaterialPass {
    GfxVertexBuffer vbs[R_MATERIAL_PASS_MAX_VBS];
    int vb_count;
    GfxImage images[R_MAX_IMAGES_PER_VERTEX_BUFFER];
    int current_image;
#if A_RENDER_BACKEND_D3D9
    IDirect3DVertexDeclaration9* decl;
#endif // A_RENDER_BACKEND_D3D9
} GfxMaterialPass;

typedef enum GfxPolygonMode {
    R_POLYGON_MODE_FILL,
    R_POLYGON_MODE_LINE
} GfxPolygonMode;

A_EXTERN_C bool R_CreateVertexBuffer(const void* data, 
                                     size_t n, size_t capacity,
                                     size_t off, A_OUT GfxVertexBuffer* vb);
A_EXTERN_C bool R_UploadVertexData  (A_INOUT GfxVertexBuffer* vb,
                                     size_t off, const void* data, size_t n);
A_EXTERN_C bool R_AppendVertexData  (A_INOUT GfxVertexBuffer* vb,
                                     const void* data, size_t n);
A_EXTERN_C int  R_AddImageToMaterialPass(A_INOUT GfxMaterialPass* pass, 
                                         A_IN GfxImage* image);
A_EXTERN_C bool R_RenderMaterialPass(const GfxMaterialPass* pass,
                                     size_t vertices_count, size_t off,
                                     GfxPolygonMode mode
);
A_EXTERN_C bool R_DeleteVertexBuffer(A_INOUT GfxVertexBuffer* vb);
A_EXTERN_C bool R_DeleteMaterialPass(A_IN GfxMaterialPass* pass);

#if A_RENDER_BACKEND_GL
typedef texture_t          GfxTexture;
#elif A_RENDER_BACKEND_D3D9
typedef LPDIRECT3DTEXTURE9 GfxTexture;
// FIXME: not sure if it's 0/1 and 2/3 or 0/2 and 1/3
#define D3DWRAP_S (D3DWRAPCOORD_0 | D3DWRAPCOORD_1)
#define D3DWRAP_T (D3DWRAPCOORD_2 | D3DWRAPCOORD_3)
#endif // A_RENDER_BACKEND_GL

#if A_RENDER_BACKEND_GL
A_NO_DISCARD GLint R_ImageFilterToGL(GfxFilter filter);
#elif A_RENDER_BACKEND_D3D9
A_NO_DISCARD DWORD R_ImageFilterToD3D(GfxFilter filter);
#endif // A_RENDER_BACKEND_D3D9

typedef struct GfxCamera {
	apoint3f_t pos;
	avec3f_t   front;
	avec3f_t   worldUp;
	avec3f_t   right;
	avec3f_t   up;
	float      pitch;
	float      yaw;
    amat4f_t   perspectiveProjection;
    amat4f_t   orthoProjection;
} GfxCamera;

struct FontDef;
typedef struct FontDef FontDef;

typedef struct GfxTextDraw {
    bool         free;
    FontDef*     font;
    char*        text;
    RectDef      rect;
    float        xscale, yscale;
    acolor_rgb_t color;
    bool         active;
    bool         right;
} GfxTextDraw;

#if A_RENDER_BACKEND_GL
A_EXTERN_C A_NO_DISCARD GLenum      R_ImageFormatToGL     (ImageFormat format);
A_EXTERN_C A_NO_DISCARD ImageFormat R_ImageFormatFromGl   (GLenum      format);
#elif A_RENDER_BACKEND_D3D9                               
A_EXTERN_C A_NO_DISCARD D3DFORMAT   R_ImageFormatToD3D    (ImageFormat format);
A_EXTERN_C A_NO_DISCARD ImageFormat R_ImageFormatFromD3D  (D3DFORMAT   format);
#endif // A_RENDER_BACKEND_GL
A_EXTERN_C A_NO_DISCARD int         R_ImageFormatPixelSize(ImageFormat format);

#if A_RENDER_BACKEND_D3D9
A_EXTERN_C A_NO_DISCARD D3DCOLOR    R_ColorRGBAToD3DARGB  (acolor_rgba_t rgba);
#endif // A_RENDER_BACKEND_D3D9

#if A_RENDER_BACKEND_GL
A_EXTERN_C A_NO_DISCARD const char* R_GlDebugErrorString(GLenum err);
A_EXTERN_C GLenum R_GlCheckError(int line, const char* file);
#endif // A_RENDER_BACKEND_GL

#if A_RENDER_BACKEND_GL
#define GL_CALL(func, ...)                                            \
    func(__VA_ARGS__);                                                \
    R_GlCheckError(__LINE__, __FILE__);
#endif // A_RENDER_BACKEND_GL

A_EXTERN_C A_NO_DISCARD float R_FovHorzToVertical(float fovx, 
                                                  float aspect_inv);
A_EXTERN_C A_NO_DISCARD float R_VidAspect   (void);
A_EXTERN_C A_NO_DISCARD float R_VidAspectInv(void);
