#pragma once

#include <GL/glew.h>

#include "acommon/a_math.h"

#include "com_defs.h"

typedef unsigned int vbo_t;
typedef unsigned int vao_t;
typedef unsigned int ebo_t;
typedef unsigned int vertex_shader_t;
typedef unsigned int fragment_shader_t;
typedef unsigned int shader_program_t;
typedef unsigned int texture_t;

#define R_VFOV_DEFAULT 74.0f

typedef struct GfxSubTexDef {
    float x, y, u, v;
} GfxSubTexDef;

typedef struct GfxVertexBuffer {
    vao_t  vao;
    vbo_t  vbo;
    size_t bytes, capacity;
} GfxVertexBuffer;

A_EXTERN_C bool R_CreateVertexBuffer(const void* data, size_t n, size_t capacity,
                                     size_t off, A_OUT GfxVertexBuffer* vb);
A_EXTERN_C bool R_UploadVertexData  (A_INOUT GfxVertexBuffer* vb,
                                     size_t off, const void* data, size_t n);
A_EXTERN_C bool R_AppendVertexData  (A_INOUT GfxVertexBuffer* vb,
                                     const void* data, size_t n);
A_EXTERN_C bool R_DeleteVertexBuffer(A_INOUT GfxVertexBuffer* vb);

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

typedef struct GfxImage {
    ImageType   type;
    texture_t   tex;
    ImageFormat format, internal_format;
    const void* pixels;
    size_t      pixels_size;
    int         width, height, depth;
} GfxImage;

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

typedef struct GfxShaderProgram {
	shader_program_t  program;
	vertex_shader_t   vertex_shader;
	fragment_shader_t fragment_shader;
} GfxShaderProgram;

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

A_EXTERN_C A_NO_DISCARD GLenum R_ImageFormatToGl(ImageFormat format);
A_EXTERN_C A_NO_DISCARD ImageFormat R_ImageFormatFromGl(GLenum format);
A_EXTERN_C A_NO_DISCARD bool R_CreateImage2D(
    int width, int height,
    ImageFormat format,
    ImageFormat internal_format,
    const void* pixels,
    size_t pixels_size,
    A_INOUT GfxImage* image
);
A_EXTERN_C void R_DeleteImage(A_INOUT GfxImage* image);

A_EXTERN_C A_NO_DISCARD const char* R_GlDebugErrorString(GLenum err);
A_EXTERN_C GLenum R_GlCheckError(int line, const char* file);

#define GL_CALL(func, ...)                                            \
    func(__VA_ARGS__);                                                \
    R_GlCheckError(__LINE__, __FILE__);

A_EXTERN_C A_NO_DISCARD float R_FovHorzToVertical(float fovx, float aspect_inv);
A_EXTERN_C A_NO_DISCARD float R_VidAspect        (void);
A_EXTERN_C A_NO_DISCARD float R_VidAspectInv     (void);
