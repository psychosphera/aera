#include "gfx_defs.h"

#include <assert.h>

#if A_RENDER_BACKEND_D3D9
#include <d3d9.h>
#endif // A_RENDER_BACKEND_D3D9

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

#if A_RENDER_BACKEND_GL
GLenum R_GlCheckError(int line, const char* file) {
    GLenum err = glGetError();
    if (err != GL_NO_ERROR) {
        const char* s = R_GlDebugErrorString(err);
        Com_Println(
            CON_DEST_ERR,
            "GL call at line %d in %s failed with %s.", line, file, s
        );
    }
    return err;
}
#endif // A_RENDER_BACKEND_GL

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
    bool ret = true;
#elif A_RENDER_BACKEND_D3D9
    IDirect3DVertexBuffer9* buffer = NULL;
    HRESULT hr = r_d3d9Glob.d3ddev->lpVtbl->CreateVertexBuffer(
        r_d3d9Glob.d3ddev, capacity, 0, 0,
        D3DPOOL_DEFAULT, &buffer, NULL
    );
    assert(hr == D3D_OK);
    bool ret = hr == D3D_OK;
    assert(buffer);

    vb->buffer = buffer;

    if (hr == D3D_OK && data && n) {
        void* p = NULL;
        hr = buffer->lpVtbl->Lock(buffer, off, n, &p, D3DLOCK_DISCARD);
        assert(hr == D3D_OK);
        if (ret)
            ret = hr == D3D_OK;
        if (hr == D3D_OK)
            A_memcpy(p, data, n);

        hr = buffer->lpVtbl->Unlock(buffer);
        assert(hr == D3D_OK);
        if (ret)
            ret = hr == D3D_OK;
    }
    vb->stride = stride;
#endif
    vb->bytes    = n;
    vb->capacity = capacity;

    return ret;
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
    return true;
#elif A_RENDER_BACKEND_D3D9
    void* p = NULL;
    HRESULT hr = vb->buffer->lpVtbl->Lock(vb->buffer, off, n, &p, D3DLOCK_DISCARD);
    assert(hr == D3D_OK);
    bool ret = hr == D3D_OK;
    if (hr == D3D_OK)
        A_memcpy(p, data, n);
    hr = vb->buffer->lpVtbl->Unlock(vb->buffer);
    if (ret)
        ret = hr == D3D_OK;
    return ret;
#endif // A_RENDER_BACKEND_GL
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
    bool ret = true;
#elif A_RENDER_BACKEND_D3D9
    void* p = NULL;
    HRESULT hr = vb->buffer->lpVtbl->Lock(vb->buffer, vb->bytes, n, &p, D3DLOCK_DISCARD);
    assert(hr == D3D_OK);
    bool ret = hr == D3D_OK;
    if (hr == D3D_OK)
        A_memcpy(p, data, n);
    hr = vb->buffer->lpVtbl->Unlock(vb->buffer);
    if (ret)
        ret = hr == D3D_OK;
#endif // A_RENDER_BACKEND_GL

    vb->bytes += n;
    return ret;
}

GfxImage* R_AddImageToMaterialPass(A_INOUT GfxMaterialPass* pass, 
                                   A_IN    GfxImage*        image
) {
    assert(pass);
    assert(image);
    assert(pass->current_image < A_countof(pass->images));

    pass->images[pass->current_image] = *image;
    int i = pass->current_image;
    pass->current_image++;
    A_memset(image, 0, sizeof(*image));
    return &pass->images[i];
}

GfxVertexBuffer* R_AddVertexBufferToMaterialPass(A_INOUT GfxMaterialPass* pass,
                                                 A_IN GfxVertexBuffer* vb
) {
    assert(pass);
    assert(vb);
    assert(pass->vb_count < A_countof(pass->vbs));
    pass->vbs[pass->vb_count] = *vb;
    GfxVertexBuffer* ret = &pass->vbs[pass->vb_count];
    pass->vb_count++;
    A_memset(vb, 0, sizeof(*vb));
    return ret;
}

bool R_RenderMaterialPass(const GfxMaterialPass* pass, 
                          size_t vertices_count, size_t off, 
                          GfxPolygonMode mode
) {
    assert(pass);
    if (!pass)
        return false;

    assert(pass->vb_count > 0);
    if (pass->vb_count < 1)
        return false;
    
    assert(vertices_count > 0);
#if A_RENDER_BACKEND_GL
    assert(pass->vb_count == 1 && 
           "R_RenderVertexBuffer: GL backend only supports one vertex buffer at a time");
#elif A_RENDER_BACKEND_D3D9
    HRESULT hr = r_d3d9Glob.d3ddev->lpVtbl->SetVertexDeclaration(
        r_d3d9Glob.d3ddev, pass->decl
    );
    assert(hr == D3D_OK);
    if (hr != D3D_OK)
        return false;
#endif

    bool b = true;
    for (int i = 0; i < pass->vb_count; i++) {
        b = R_BindVertexBuffer(&pass->vbs[i], i);
        assert(b);
        if (!b)
            return false;
    }

    for (int i = 0; i < pass->current_image; i++) {
        const GfxImage* image = &pass->images[i];
        b = R_BindImage(&pass->images[i], i);
        assert(b);
        if (!b)
            return false;
    }

    b = R_SetPolygonMode(mode);
    assert(b);
    if (!b)
        return false;
    
    b = R_DrawTris(vertices_count / 3, off / 3);
    assert(b);
    if (!b)
        return false;

    b = R_SetPolygonMode(R_POLYGON_MODE_FILL);
    assert(b);
    
    return b;

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
    vb->buffer->lpVtbl->Release(vb->buffer);
    vb->buffer = NULL;
#endif // A_RENDER_BACKEND_GL
    vb->bytes    = 0;
    vb->capacity = 0;
    return true;
}

bool R_DeleteMaterialPass(A_IN GfxMaterialPass* pass) {
    assert(pass);
    if (!pass)
        return false;

    for (int i = 0; i < pass->vb_count; i++) 
        R_DeleteVertexBuffer(&pass->vbs[i]);    
 
    for (int i = 0; i < pass->current_image; i++)
        R_DeleteImage(&pass->images[i]);

#if A_RENDER_BACKEND_D3D9
    if (pass->decl)
        pass->decl->lpVtbl->Release(pass->decl);
#endif // A_RENDER_BACKEND_D3D9
    A_memset(pass, 0, sizeof(*pass));
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
    default:
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
A_NO_DISCARD ImageFormat R_ImageFormatFromGl(GLenum format) {
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
    default:
        assert(false && "Unimplemented GL format");
        Com_Errorln(
            -1, 
            "R_ImageFormatToGL: Unimplemented GL format %d.", 
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

A_NO_DISCARD int R_ImageFormatPixelSize(ImageFormat format) {
    switch (format) {
    case R_IMAGE_FORMAT_A8:
    case R_IMAGE_FORMAT_R8:
        return 1;
    case R_IMAGE_FORMAT_RGB565:
        return 2;
    case R_IMAGE_FORMAT_RGB888: 
        return 3;
    case R_IMAGE_FORMAT_ARGB8888:
    case R_IMAGE_FORMAT_RGBA8888:
        return 4;
    case R_IMAGE_FORMAT_DXT1:
        return 8;
    case R_IMAGE_FORMAT_DXT3:
    case R_IMAGE_FORMAT_DXT5:
        return 16;
    default:
        assert(false && "Unimplemented ImageFormat");
        Com_Errorln(
            -1,
            "R_ImageFormatPixelSize: Unimplemented ImageFormat %d.",
            format
        );
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
