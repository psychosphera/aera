#pragma once

#include "acommon/acommon.h"

#if A_RENDER_BACKEND_GL
#include <GL/glew.h>
#include <cglm/cglm.h>
#elif A_RENDER_BACKEND_D3D9
#include <d3d9.h>
#include <d3dx9.h>
#elif A_RENDER_BACKEND_D3D8
#if A_TARGET_PLATFORM_IS_XBOX
#include <Xtl.h>
#else
#include <d3d8.h>
#endif // A_TARGET_PLATFORM_IS_XBOX
#include <d3dx8.h>
#endif // A_RENDER_BACKEND_GL

#if A_RENDER_BACKEND_D3D8 || A_RENDER_BACKEND_D3D9
#define A_RENDER_BACKEND_D3D 1
#else
#define A_RENDER_BACKEND_D3D 0
#endif // A_RENDER_BACKEND_D3D8 || A_RENDER_BACKEND_D3D9

#include "acommon/a_math.h"

#include "com_defs.h"

#define R_MAX_IMAGES_PER_VERTEX_BUFFER 8
#define R_MATERIAL_PASS_MAX_VBS        2

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
    IDirect3D9*       d3d9;
    IDirect3DDevice9* d3ddev;

    D3DCOLOR          clear_color_argb;
} D3D9RenderGlob;
extern D3D9RenderGlob r_d3d9Glob;
#elif A_RENDER_BACKEND_D3D8
typedef struct D3D8RenderGlob {
#if !A_TARGET_PLATFORM_IS_XBOX
    HWND              hWnd;
#endif // !A_TARGET_PLATFORM_IS_XBOX
    IDirect3D8*       d3d8;
    IDirect3DDevice8* d3ddev;

    D3DCOLOR          clear_color_argb;
} D3D9RenderGlob;
extern D3D8RenderGlob r_d3d8Glob;
#endif // A_RENDER_BACKEND_D3D9

typedef enum ImageFormat {
    R_IMAGE_FORMAT_UNKNOWN,
    R_IMAGE_FORMAT_DXT1,
    R_IMAGE_FORMAT_DXT3,
    R_IMAGE_FORMAT_DXT5,
    R_IMAGE_FORMAT_A8,
    R_IMAGE_FORMAT_R8,
    R_IMAGE_FORMAT_P8,
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
#define D3DWRAP_S (D3DWRAPCOORD_0 | D3DWRAPCOORD_1)
#define D3DWRAP_T (D3DWRAPCOORD_2 | D3DWRAPCOORD_3)
#elif A_RENDER_BACKEND_D3D8
typedef LPDIRECT3DTEXTURE8 GfxTexture;
#define D3DWRAP_S (D3DWRAPCOORD_0 | D3DWRAPCOORD_1)
#define D3DWRAP_T (D3DWRAPCOORD_2 | D3DWRAPCOORD_3)
#endif // A_RENDER_BACKEND_GL

typedef enum ImageFilter {
    R_IMAGE_FILTER_LINEAR
} ImageFilter;

typedef struct GfxImage {
    ImageType          type;
    GfxTexture         tex;
    bool               wrap_s, wrap_t;
    ImageFilter        minfilter, magfilter;
    ImageFormat        format, internal_format;
    const void*        pixels;
    size_t             pixels_size;
    int                width, height, depth;
} GfxImage;

typedef struct GfxVertexBuffer {
#if A_RENDER_BACKEND_GL
    vao_t  vao;
    vbo_t  vbo;
#elif A_RENDER_BACKEND_D3D
#if A_RENDER_BACKEND_D3D9
    IDirect3DVertexBuffer9* buffer;
#elif A_RENDER_BACKEND_D3D8
    IDirect3DVertexBuffer8* buffer;
#endif // A_RENDER_BACKEND_D3D9
    size_t stride;
#endif // A_RENDER_BACKEND_GL
    size_t bytes, capacity;
} GfxVertexBuffer;

typedef struct GfxVertexDeclaration {
    GfxVertexBuffer              vbs[R_MATERIAL_PASS_MAX_VBS];
    int                          vb_count;
    size_t                       vertices_count;
#if A_RENDER_BACKEND_D3D9
    IDirect3DVertexDeclaration9* decl;
#elif A_RENDER_BACKEND_D3D8
    D3DVERTEXATTRIBUTEFORMAT format;
    size_t format_count;
#endif // A_RENDER_BACKEND_D3D9
} GfxVertexDeclaration;

typedef enum GfxPrimitiveType {
    PRIMITIVE_TYPE_TRI,
    PRIMITIVE_TYPE_TRI_STRIP
} GfxPrimitiveType;

typedef enum GfxPolygonMode {
    R_POLYGON_MODE_FILL,
    R_POLYGON_MODE_LINE
} GfxPolygonMode;

#if A_RENDER_BACKEND_D3D9
A_EXTERN_C HRESULT R_SetLastD3DError(HRESULT hr);
A_EXTERN_C HRESULT R_GetLastD3DError(void);
A_EXTERN_C void R_D3DCheckError(const char* func, int line, const char* file);
#endif // A_RENDER_BACKEND_D3D9

A_EXTERN_C A_NO_DISCARD bool R_ImageFormatIsCompressed(ImageFormat format);

A_EXTERN_C bool      R_CreateVertexBuffer(const void* data, 
                                          size_t n, size_t capacity, 
                                          size_t off, size_t stride, 
                                          A_OUT GfxVertexBuffer* vb);
A_EXTERN_C bool      R_UploadVertexData(A_INOUT GfxVertexBuffer* vb,
                                        size_t off, const void* data, size_t n);
A_EXTERN_C bool      R_AppendVertexData(A_INOUT GfxVertexBuffer* vb,
                                        const void* data, size_t n);
A_EXTERN_C GfxVertexBuffer* R_AddVertexBufferToVertexDeclaration(
    A_INOUT GfxVertexDeclaration* decl,
    A_IN GfxVertexBuffer* vb
);
//A_EXTERN_C bool      R_RenderMaterialPass(A_INOUT GfxMaterialPass* pass,
//                                          GfxPrimitiveType primitive_type,
//                                          size_t vertices_count, size_t off,
//                                          GfxPolygonMode mode
//);
A_EXTERN_C bool R_DeleteVertexBuffer(A_INOUT GfxVertexBuffer* vb);
A_EXTERN_C bool R_DeleteVertexDeclaration(A_IN GfxVertexDeclaration* vertex_declaration);

#if A_RENDER_BACKEND_GL
A_NO_DISCARD GLint R_ImageFilterToGL(ImageFilter filter);
#elif A_RENDER_BACKEND_D3D
A_NO_DISCARD DWORD R_ImageFilterToD3D(ImageFilter filter);
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
A_EXTERN_C A_NO_DISCARD ImageFormat R_ImageFormatFromGL   (GLenum      format);
#elif A_RENDER_BACKEND_D3D9 || A_RENDER_BACKEND_D3D8                              
A_EXTERN_C A_NO_DISCARD D3DFORMAT   R_ImageFormatToD3D    (ImageFormat format);
A_EXTERN_C A_NO_DISCARD ImageFormat R_ImageFormatFromD3D  (D3DFORMAT   format);
#endif // A_RENDER_BACKEND_GL
A_EXTERN_C A_NO_DISCARD int         R_ImageFormatBPP      (ImageFormat format);
A_EXTERN_C A_NO_DISCARD bool        R_ImageFormatIsDXT    (ImageFormat format);

#if A_RENDER_BACKEND_D3D
A_EXTERN_C A_NO_DISCARD D3DCOLOR    R_ColorRGBAToD3DARGB  (acolor_rgba_t rgba);
#endif // A_RENDER_BACKEND_D3D9

#if A_RENDER_BACKEND_GL
A_EXTERN_C A_NO_DISCARD const char* R_GLDebugErrorString(GLenum err);
A_EXTERN_C GLenum R_GLCheckError(const char* func, int line, const char* file);
#endif // A_RENDER_BACKEND_GL

#if A_RENDER_BACKEND_GL
#define GL_CALL(func, ...)                                                     \
    func(__VA_ARGS__);                                                         \
    R_GLCheckError(__func__, __LINE__, __FILE__);                                        
#elif A_RENDER_BACKEND_D3D9                                                    
#define D3D_CALL(self, fn, ...)                                                \
    R_SetLastD3DError((self)->lpVtbl->fn((self) A_VA_OPT(__VA_ARGS__)));       \
    R_D3DCheckError(__func__, __LINE__, __FILE__);         
#define D3D_CALL_NO_ERR(self, fn, ...)                                         \
    (self)->lpVtbl->fn((self) A_VA_OPT(__VA_ARGS__));                          
#endif // A_RENDER_BACKEND_GL

A_EXTERN_C A_NO_DISCARD float R_FovHorzToVertical(float fovx, 
                                                  float aspect_inv);
A_EXTERN_C A_NO_DISCARD float R_VidAspect   (void);
A_EXTERN_C A_NO_DISCARD float R_VidAspectInv(void);
