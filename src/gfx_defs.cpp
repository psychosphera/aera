#include "gfx_defs.hpp"

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
            GL_ARRAY_BUFFER, capacity, nullptr, GL_STATIC_DRAW);
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

    GL_CALL(glBufferData, GL_ARRAY_BUFFER, 0, nullptr, GL_STATIC_DRAW);

    GL_CALL(glBindBuffer, GL_ARRAY_BUFFER, 0);
    GL_CALL(glBindVertexArray, 0);

    GL_CALL(glDeleteBuffers, 1, &vb->vbo);
    GL_CALL(glDeleteVertexArrays, 1, &vb->vao);

    vb->vao = 0;
    vb->vbo = 0;
    return true;
}
