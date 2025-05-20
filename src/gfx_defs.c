#include "gfx_defs.h"

#include <assert.h>

#include "acommon/a_math.h"
#include "acommon/a_string.h"

#include "com_print.h"
#include "dvar.h"
#include "gfx.h"

extern dvar_t* vid_width;
extern dvar_t* vid_height;

A_NO_DISCARD float R_FovHorzToVertical(float fovx, float aspect_inv) {
    return 2.0f * A_degrees(A_atanf(A_tanf(A_radians(fovx) / 2) * aspect_inv));
}

A_NO_DISCARD float R_VidAspect(void) {
    return (float)Dvar_GetInt(vid_width) / (float)Dvar_GetInt(vid_width);
}

A_NO_DISCARD float R_VidAspectInv(void) {
    return (float)Dvar_GetInt(vid_width) / (float)Dvar_GetInt(vid_width);
}

bool R_CreateVertexBuffer(const void* data, size_t n, size_t capacity,
                          size_t off, size_t stride, A_OUT GfxVertexBuffer* vb
) {
    assert(vb);
    if (!vb)
        return false;

    A_memset(vb, 0, sizeof(*vb));

    if (data) {
        assert(capacity > 0);
        if (capacity < 1)
            return false;
    }

    assert(capacity >= off + n && capacity > 0);
    if (capacity < off + n || capacity < 1)
        return false;
#if A_RENDER_BACKEND_GL
    (void)stride;
    GL_CALL(glGenVertexArrays, 1, &vb->vao);
    GL_CALL(glGenBuffers,      1, &vb->vbo);

    GL_CALL(glBindVertexArray, vb->vao);
    GL_CALL(glBindBuffer, GL_ARRAY_BUFFER, vb->vbo);

    if (data && n > 0 && n == capacity && off == 0) {
        glBufferData(GL_ARRAY_BUFFER, n, data, GL_STATIC_DRAW);
    } else if (n > 0) {
        GL_CALL(glBufferData, 
            GL_ARRAY_BUFFER, capacity, NULL, GL_STATIC_DRAW);
        if (data)
            GL_CALL(glBufferSubData, GL_ARRAY_BUFFER, off, n, data);
    }
#elif A_RENDER_BACKEND_D3D9
    IDirect3DVertexBuffer9* buffer = NULL;
    D3D_CALL(r_d3d9Glob.d3ddev, CreateVertexBuffer, 
        capacity, 0, 0,
        D3DPOOL_DEFAULT, &buffer, NULL
    );

    vb->buffer = buffer;

    if (data && n) {
        void* p = NULL;
        D3D_CALL(buffer, Lock, off, n, &p, D3DLOCK_DISCARD);
        A_memcpy(p, data, n);
        D3D_CALL(buffer, Unlock);
    }
    vb->stride = stride;
#endif
    vb->bytes    = n;
    vb->capacity = capacity;

    return true;
}

bool R_UploadVertexData(A_INOUT GfxVertexBuffer* vb,
                        size_t off, const void* data, size_t n
) {
    assert(vb);
    if (!vb)
        return false;

    assert(data);
    assert(n);
    assert(off + n < vb->capacity);

#if A_RENDER_BACKEND_GL
    GL_CALL(glBindVertexArray, vb->vao);
    GL_CALL(glBindBuffer, GL_ARRAY_BUFFER, vb->vbo);
    if (data && n > 0) {
        GL_CALL(glBufferSubData, GL_ARRAY_BUFFER, off, n, data);
        vb->bytes = A_MAX(vb->bytes, off + n);
    }
#elif A_RENDER_BACKEND_D3D9
    void* p = NULL;
    D3D_CALL(vb->buffer, Lock, off, n, &p, D3DLOCK_DISCARD);
    A_memcpy(p, data, n);
    D3D_CALL(vb->buffer, Unlock);
#endif // A_RENDER_BACKEND_GL
    return true;
}

bool R_AppendVertexData(A_INOUT GfxVertexBuffer* vb,
                        const void* data, size_t n
) {
    assert(vb);
    if (!vb)
        return false;

    assert(data);
    if (!data)
        return false;

    assert(n > 0);
    if (n < 1)
        return false;

    assert(vb->bytes + n <= vb->capacity);
    if (vb->bytes + n > vb->capacity)
        return false;

#if A_RENDER_BACKEND_GL
    GL_CALL(glBindVertexArray, vb->vao);
    GL_CALL(glBindBuffer, GL_ARRAY_BUFFER, vb->vbo);
    GL_CALL(glBufferSubData, GL_ARRAY_BUFFER, vb->bytes, n, data);
#elif A_RENDER_BACKEND_D3D9
    void* p = NULL;
    D3D_CALL(vb->buffer, Lock, vb->bytes, n, &p, D3DLOCK_DISCARD);
    A_memcpy(p, data, n);
    D3D_CALL(vb->buffer, Unlock);
#endif // A_RENDER_BACKEND_GL
    vb->bytes += n;
    return true;
}

GfxVertexBuffer* R_AddVertexBufferToVertexDeclaration(A_INOUT GfxVertexDeclaration* decl,
                                                      A_IN GfxVertexBuffer* vb
) {
    assert(decl);
    assert(vb);
    assert(decl->vb_count < A_countof(decl->vbs));
    decl->vbs[decl->vb_count] = *vb;
    GfxVertexBuffer* ret = &decl->vbs[decl->vb_count];
    decl->vb_count++;
    A_memset(vb, 0, sizeof(*vb));
    return ret;
}

bool R_DeleteVertexBuffer(A_INOUT GfxVertexBuffer* vb) {
    assert(vb);
    if (!vb)
        return false;

#if A_RENDER_BACKEND_GL
    GL_CALL(glBindVertexArray, vb->vao);
    GL_CALL(glBindBuffer, GL_ARRAY_BUFFER, vb->vbo);

    GL_CALL(glBufferData, GL_ARRAY_BUFFER, 0, NULL, GL_STATIC_DRAW);

    GL_CALL(glBindBuffer, GL_ARRAY_BUFFER, 0);
    GL_CALL(glBindVertexArray, 0);

    GL_CALL(glDeleteBuffers, 1, &vb->vbo);
    GL_CALL(glDeleteVertexArrays, 1, &vb->vao);

    vb->vao = 0;
    vb->vbo = 0;
#elif A_RENDER_BACKEND_D3D9
    D3D_CALL(vb->buffer, Release);
    vb->buffer = NULL;
#endif // A_RENDER_BACKEND_GL
    vb->bytes    = 0;
    vb->capacity = 0;
    return true;
}

bool R_DeleteVertexDeclaration(A_IN GfxVertexDeclaration* vertex_declaration) {
    assert(vertex_declaration);
    if (!vertex_declaration)
        return false;

    for (int i = 0; i < vertex_declaration->vb_count; i++)
        R_DeleteVertexBuffer(&vertex_declaration->vbs[i]);

#if A_RENDER_BACKEND_D3D9
    if (vertex_declaration->decl)
        D3D_CALL(vertex_declaration->decl, Release);
#endif // A_RENDER_BACKEND_D3D9
    return true;
}

#if A_RENDER_BACKEND_GL
A_NO_DISCARD GLenum R_ImageFormatToGL(ImageFormat format) {
    GLenum gl_format = 0;
    switch (format) {
    case R_IMAGE_FORMAT_A8:
        gl_format = GL_ALPHA8;
        break;
    case R_IMAGE_FORMAT_R8:
        gl_format = GL_RED;
        break;
    case R_IMAGE_FORMAT_RGB565:
       /* gl_format = GL_RGB565;
        break;*/
       // Intentional fallthrough
    case R_IMAGE_FORMAT_RGB888:
        gl_format = GL_RGB;
        break;
    case R_IMAGE_FORMAT_DXT1:
        gl_format = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT;
        break;
    case R_IMAGE_FORMAT_DXT3:
        gl_format = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
        break;
    case R_IMAGE_FORMAT_DXT5:
        gl_format = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;
        break;
    case R_IMAGE_FORMAT_P8:
        gl_format = GL_ALPHA8;
        break;
    default:
        assert(false && "R_ImageFormatToGL: Unimplemented ImageFormat");
        Com_Errorln(
            -1, 
            "R_ImageFormatToGL: Unimplemented ImageFormat %d.", 
            (int)format);
    };

    return gl_format;
}
#elif A_RENDER_BACKEND_D3D9
A_NO_DISCARD D3DFORMAT R_ImageFormatToD3D(ImageFormat format) {
    D3DFORMAT d3dfmt = 0;
    switch (format) {
    case R_IMAGE_FORMAT_A8:
        d3dfmt = D3DFMT_A8;
        break;
    case R_IMAGE_FORMAT_RGB565:
        d3dfmt = D3DFMT_R5G6B5;
        break;
    case R_IMAGE_FORMAT_DXT1:
        d3dfmt = D3DFMT_DXT1;
        break;
    case R_IMAGE_FORMAT_DXT3:
        d3dfmt = D3DFMT_DXT3;
        break;
    case R_IMAGE_FORMAT_DXT5:
        d3dfmt = D3DFMT_DXT5;
        break;
    default:
        Com_Errorln(
            -1,
            "R_ImageFormatToD3D: Unimplemented ImageFormat %d.",
            (int)format);
    };

    return d3dfmt;
}
#endif // A_RENDER_BACKEND_GL

#if A_RENDER_BACKEND_GL
A_NO_DISCARD ImageFormat R_ImageFormatFromGL(GLenum format) {
    ImageFormat img_format = R_IMAGE_FORMAT_UNKNOWN;
    switch (format) {
    case GL_ALPHA8:
        img_format = R_IMAGE_FORMAT_A8;
        break;
    case GL_RED:
        img_format = R_IMAGE_FORMAT_R8;
        break;
    case GL_RGB565:
        img_format = R_IMAGE_FORMAT_RGB565;
        break;
    case GL_RGB:
        img_format = R_IMAGE_FORMAT_RGB888;
        break;
    case GL_COMPRESSED_RGBA_S3TC_DXT1_EXT:
        img_format = R_IMAGE_FORMAT_DXT1;
        break;
    case GL_COMPRESSED_RGBA_S3TC_DXT3_EXT:
        img_format = R_IMAGE_FORMAT_DXT3;
        break;
    case GL_COMPRESSED_RGBA_S3TC_DXT5_EXT:
        img_format = R_IMAGE_FORMAT_DXT5;
        break;
    case GL_PALETTE8_RGB8_OES:
        img_format = R_IMAGE_FORMAT_P8;
    default:
        assert(false && "Unimplemented GL format");
        Com_Errorln(
            -1, 
            "R_ImageFormatFromGL: Unimplemented GL format %d.", 
            format);
    };

    return img_format;
}
#elif A_RENDER_BACKEND_D3D9
A_NO_DISCARD ImageFormat R_ImageFormatFromD3D(D3DFORMAT format) {
    ImageFormat img_format = R_IMAGE_FORMAT_UNKNOWN;
    switch (format) {
    case D3DFMT_A8:
        img_format = R_IMAGE_FORMAT_A8;
        break;
    case D3DFMT_R5G6B5:
        img_format = R_IMAGE_FORMAT_RGB565;
        break;
    case D3DFMT_R8G8B8:
        img_format = R_IMAGE_FORMAT_RGB888;
        break;
    case D3DFMT_DXT1:
        img_format = R_IMAGE_FORMAT_DXT1;
        break;
    case D3DFMT_DXT3:
        img_format = R_IMAGE_FORMAT_DXT3;
        break;
    case D3DFMT_DXT5:
        img_format = R_IMAGE_FORMAT_DXT5;
        break;
    default:
        assert(false && "Unimplemented D3D format");
        Com_Errorln(
            -1,
            "R_ImageFormatToGL: Unimplemented GL format %d.",
            format);
    };

    return img_format;
}
#endif // A_RENDER_BACKEND_GL

A_NO_DISCARD bool R_ImageFormatIsCompressed(ImageFormat format) {
    assert(format < R_IMAGE_FORMAT_COUNT);
    if (format >= R_IMAGE_FORMAT_COUNT)
        return false;

    switch (format) {
    case R_IMAGE_FORMAT_DXT1:
    case R_IMAGE_FORMAT_DXT3:
    case R_IMAGE_FORMAT_DXT5:
        return true;
    default:
        return false;
    };
}

A_NO_DISCARD int R_ImageFormatBPP(ImageFormat format) {
    switch (format) {
    case R_IMAGE_FORMAT_A8:
    case R_IMAGE_FORMAT_R8:
        return 8;
    case R_IMAGE_FORMAT_RGB565:
        return 16;
    case R_IMAGE_FORMAT_RGB888: 
        return 24;
    case R_IMAGE_FORMAT_ARGB8888:
    case R_IMAGE_FORMAT_RGBA8888:
        return 32;
    case R_IMAGE_FORMAT_DXT1:
        return 4;
    case R_IMAGE_FORMAT_DXT3:
    case R_IMAGE_FORMAT_DXT5:
        return 8;
    default:
        assert(false && "Unimplemented ImageFormat");
        Com_Errorln(
            -1,
            "R_ImageFormatPixelSize: Unimplemented ImageFormat %d.",
            format
        );
    }
}

A_NO_DISCARD bool R_ImageFormatIsDXT(ImageFormat format) {
    switch (format) {
    case R_IMAGE_FORMAT_DXT1:
    case R_IMAGE_FORMAT_DXT3:
    case R_IMAGE_FORMAT_DXT5:
        return true;
    default:
        return false;
    }
}

#if A_RENDER_BACKEND_GL
A_NO_DISCARD GLint R_ImageFilterToGL(ImageFilter filter) {
    switch (filter) {
    case R_IMAGE_FILTER_LINEAR:
        return GL_LINEAR;
    default:
        assert(false && "Unimplemented GfxFilter");
    }
    return 0;
}
#elif A_RENDER_BACKEND_D3D9
A_NO_DISCARD DWORD R_ImageFilterToD3D(ImageFilter filter) {
    switch (filter) {
    case R_IMAGE_FILTER_LINEAR:
        return D3DTEXF_LINEAR;
    default:
        assert(false && "Unimplemented GfxFilter");
    }
    return -1;
}
#endif // A_RENDER_BACKEND_D3D9

#if A_RENDER_BACKEND_D3D9
A_NO_DISCARD D3DCOLOR R_ColorRGBAToD3DARGB(acolor_rgba_t rgba) {
    DWORD r = rgba.r * 255;
    DWORD g = rgba.g * 255;
    DWORD b = rgba.b * 255;
    DWORD a = rgba.a * 255;
    return D3DCOLOR_ARGB(a, r, g, b);
}
#endif // A_RENDER_BACKEND_D3D9
