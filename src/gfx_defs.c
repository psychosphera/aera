#include "gfx_defs.h"

#include <assert.h>

#include "acommon/a_math.h"
#include "acommon/a_string.h"

#include "com_print.h"
#include "dvar.h"

extern dvar_t* vid_width;
extern dvar_t* vid_height;

float R_FovHorzToVertical(float fovx, float aspect_inv) {
    return 2.0f * A_degrees(A_atanf(A_tanf(A_radians(fovx) / 2) * aspect_inv));
}

A_NO_DISCARD float R_VidAspect(void) {
    return (float)Dvar_GetInt(vid_width) / (float)Dvar_GetInt(vid_width);
}

A_NO_DISCARD float R_VidAspectInv(void) {
    return (float)Dvar_GetInt(vid_width) / (float)Dvar_GetInt(vid_width);
}

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

bool R_CreateVertexBuffer(const void* data, size_t n, size_t capacity,
                          size_t off, A_OUT GfxVertexBuffer* vb
) {
    assert(vb);
    if (!vb)
        return false;

    if (data) {
        assert(capacity > 0);
        if (capacity < 1)
            return false;
    }

    assert(capacity >= off + n && capacity > 0);
    if (capacity < off + n || capacity < 1)
        return false;

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

    GL_CALL(glBindVertexArray, vb->vao);
    GL_CALL(glBindBuffer, GL_ARRAY_BUFFER, vb->vbo);
    if (data && n > 0) {
        GL_CALL(glBufferSubData, GL_ARRAY_BUFFER, off, n, data);
        vb->bytes = A_MAX(vb->bytes, off + n);
    }

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

    GL_CALL(glBindVertexArray, vb->vao);
    GL_CALL(glBindBuffer, GL_ARRAY_BUFFER, vb->vbo);
    GL_CALL(glBufferSubData, GL_ARRAY_BUFFER, vb->bytes, n, data);

    return true;
}

bool R_DeleteVertexBuffer(A_INOUT GfxVertexBuffer* vb) {
    assert(vb);
    if (!vb)
        return false;

    GL_CALL(glBindVertexArray, vb->vao);
    GL_CALL(glBindBuffer, GL_ARRAY_BUFFER, vb->vbo);

    GL_CALL(glBufferData, GL_ARRAY_BUFFER, 0, NULL, GL_STATIC_DRAW);

    GL_CALL(glBindBuffer, GL_ARRAY_BUFFER, 0);
    GL_CALL(glBindVertexArray, 0);

    GL_CALL(glDeleteBuffers, 1, &vb->vbo);
    GL_CALL(glDeleteVertexArrays, 1, &vb->vao);

    vb->vao = 0;
    vb->vbo = 0;
    return true;
}

A_NO_DISCARD GLenum R_ImageFormatToGl(ImageFormat format) {
    GLenum gl_format = 0;
    switch (format) {
    case R_IMAGE_FORMAT_A8:
        gl_format = GL_ALPHA8;
        break;
    case R_IMAGE_FORMAT_RGB565:
        gl_format = GL_RGB565;
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
        Com_Errorln(-1, "R_ImageFormatToGL: Unimplemented ImageFormat %d.", (int)format);
    };

    return gl_format;
}

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
        Com_Errorln(-1, "R_ImageFormatToGL: Unimplemented GL format %d.", format);
    };

    return img_format;
}

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

A_NO_DISCARD bool R_CreateImage2D(int width, int height,
                                             ImageFormat format,
                                             ImageFormat internal_format,
                                             const void* pixels,
                                             size_t      pixels_size,
                                             A_INOUT GfxImage* image
) {
    assert(image);
    if (!image)
        return false;

    if (pixels) {
        assert(pixels_size > 0);
        if (pixels_size < 1)
            return false;
    } else {
        assert(pixels_size == 0);
        if (pixels_size != 0)
            return false;

        assert(width == 0);
        if (width != 0)
            return false;

        assert(height == 0);
        if (height != 0)
            return false;
    }

    A_memset(image, 0, sizeof(*image));

    GLenum gl_format          = R_ImageFormatToGl(format);
    GLenum gl_internal_format = R_ImageFormatToGl(internal_format);

    texture_t tex;
    GL_CALL(glActiveTexture, GL_TEXTURE0);
    GL_CALL(glGenTextures, 1, &tex);
    GL_CALL(glBindTexture, GL_TEXTURE_2D, tex);

    GL_CALL(glTexParameteri, GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    GL_CALL(glTexParameteri, GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    GL_CALL(glTexParameteri, GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    GL_CALL(glTexParameteri, GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    bool compressed = R_ImageFormatIsCompressed(format);
    if (pixels) {
        if (compressed) {
            GL_CALL(glCompressedTexImage2D, GL_TEXTURE_2D, 0,
                gl_internal_format, width, height, 0, pixels_size, pixels);
        }
        else {
            GL_CALL(glTexImage2D, GL_TEXTURE_2D, 0, gl_internal_format,
                width, height, 0, gl_format, GL_UNSIGNED_BYTE, pixels);
        }
    }
    GL_CALL(glGenerateMipmap, GL_TEXTURE_2D);

    image->width           = width;
    image->height          = height;
    image->depth           = 1;
    image->type            = R_IMAGE_TYPE_2D_TEXTURE;
    image->format          = format;
    image->internal_format = internal_format;
    image->pixels          = pixels;
    image->pixels_size     = pixels_size;
    image->tex             = tex;

    return true;
}

void R_DeleteImage(A_INOUT GfxImage* image) {
    GL_CALL(glDeleteTextures, 1, &image->tex);
}