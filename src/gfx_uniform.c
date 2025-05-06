#include "gfx_uniform.h"

#include <assert.h>

#include "acommon/a_string.h"

#include "com_print.h"

uint32_t R_HashUniformName(const char* name) {
    assert(name);
    uint32_t hash = 0;
    for (uint32_t i = 0; name[i] != '\0'; i++) {
        char c = A_tolower(name[i]);
        hash += (uint32_t)c * (i + 119);
    }
    return hash;
}

void R_CreateUniformBool(const char* name, bool value, 
                         A_OUT GfxShaderUniformDef* pUniform
) {
    GfxShaderUniformDef uniform = {
        .name      = A_cstrdup(name),
        .name_hash = R_HashUniformName(name),
        .location  = -1,
        .type      = UNIFORM_TYPE_BOOL,
        .value.b   = value
    };

    *pUniform = uniform;
}

void R_CreateUniformFloat(const char* name, float value, 
                          A_OUT GfxShaderUniformDef* pUniform
) {
    GfxShaderUniformDef uniform = {
        .name = A_cstrdup(name),
        .name_hash = R_HashUniformName(name),
        .location = -1,
        .type = UNIFORM_TYPE_FLOAT,
        .value.f = value
    };
    *pUniform = uniform;
}

void R_CreateUniformFloatArray(const char* name, const float* value, int count,
                               A_OUT GfxShaderUniformDef* pUniform
) {
    GfxShaderUniformDef uniform = {
        .name         = A_cstrdup(name),
        .name_hash    = R_HashUniformName(name),
        .location     = -1,
        .type         = UNIFORM_TYPE_FLOAT_ARRAY,
        .value.fa     = value,
        .value.fcount = count
    };
    *pUniform = uniform;
}

void R_CreateUniformVec2f(const char* name, avec2f_t value, 
                          A_OUT GfxShaderUniformDef* pUniform
) {
    GfxShaderUniformDef uniform = {
        .name      = A_cstrdup(name),
        .name_hash = R_HashUniformName(name),
        .location  = -1,
        .type      = UNIFORM_TYPE_VEC2F,
        .value.v2f = value
    };
    *pUniform = uniform;
}

void R_CreateUniformVec3f(const char* name, avec3f_t value, 
                          A_OUT GfxShaderUniformDef* pUniform
) {
    GfxShaderUniformDef uniform = {
        .name      = A_cstrdup(name),
        .name_hash = R_HashUniformName(name),
        .location  = -1,
        .type      = UNIFORM_TYPE_VEC3F,
        .value.v3f = value
    };
    *pUniform = uniform;
}

void R_CreateUniformVec4f(const char* name, avec4f_t value, 
                          A_OUT GfxShaderUniformDef* pUniform
) {
    GfxShaderUniformDef uniform = {
        .name      = A_cstrdup(name),
        .name_hash = R_HashUniformName(name),
        .location  = -1,
        .type      = UNIFORM_TYPE_VEC4F,
        .value.v4f = value
    };
    *pUniform = uniform;
}

void R_CreateUniformInt(const char* name, int value, 
                        A_OUT GfxShaderUniformDef* pUniform
) {
    GfxShaderUniformDef uniform = {
        .name      = A_cstrdup(name),
        .name_hash = R_HashUniformName(name),
        .location  = -1,
        .type      = UNIFORM_TYPE_INT,
        .value.i   = value
    };
    *pUniform = uniform;
}

void R_CreateUniformIntArray(const char* name, const int* value, int count, 
                             A_OUT GfxShaderUniformDef* pUniform
) {
    GfxShaderUniformDef uniform = {
        .name         = A_cstrdup(name),
        .name_hash    = R_HashUniformName(name),
        .location     = -1,
        .type         = UNIFORM_TYPE_INT_ARRAY,
        .value.ia     = value,
        .value.icount = count
    };
    *pUniform = uniform;
}

void R_CreateUniformVec2i(const char* name, avec2i_t value, 
                          A_OUT GfxShaderUniformDef* pUniform
) {
    GfxShaderUniformDef uniform = {
        .name      = A_cstrdup(name),
        .name_hash = R_HashUniformName(name),
        .location  = -1,
        .type      = UNIFORM_TYPE_VEC2I,
        .value.v2i = value
    };
    *pUniform = uniform;
}

void R_CreateUniformVec3i(const char* name, avec3i_t value, 
                          A_OUT GfxShaderUniformDef* pUniform
) {
    GfxShaderUniformDef uniform = {
        .name      = A_cstrdup(name),
        .name_hash = R_HashUniformName(name),
        .location  = -1,
        .type      = UNIFORM_TYPE_VEC3I,
        .value.v3i = value
    };
    *pUniform = uniform;
}

void R_CreateUniformVec4i(const char* name, avec4i_t value, 
                          A_OUT GfxShaderUniformDef* pUniform
) {
    GfxShaderUniformDef uniform = {
        .name      = A_cstrdup(name),
        .name_hash = R_HashUniformName(name),
        .location  = -1,
        .type      = UNIFORM_TYPE_VEC4I,
        .value.v4i = value
    };
    *pUniform = uniform;
}

void R_CreateUniformUint(const char* name, unsigned int value, 
                         A_OUT GfxShaderUniformDef* pUniform
) {
    GfxShaderUniformDef uniform = {
        .name      = A_cstrdup(name),
        .name_hash = R_HashUniformName(name),
        .location  = -1,
        .type      = UNIFORM_TYPE_UINT,
        .value.u   = value
    };
    *pUniform = uniform;
}

void R_CreateUniformUintArray(const char* name, const unsigned int* value, 
                              int count, A_OUT GfxShaderUniformDef* pUniform
) {
    GfxShaderUniformDef uniform = {
        .name         = A_cstrdup(name),
        .name_hash    = R_HashUniformName(name),
        .location     = -1,
        .type         = UNIFORM_TYPE_UINT_ARRAY,
        .value.ua     = value,
        .value.ucount = count
    };
    *pUniform = uniform;
}

void R_CreateUniformMat2f(const char* name, amat2f_t value, 
                          A_OUT GfxShaderUniformDef* pUniform
) {
    GfxShaderUniformDef uniform = {
        .name      = A_cstrdup(name),
        .name_hash = R_HashUniformName(name),
        .location  = -1,
        .type      = UNIFORM_TYPE_MAT2F,
        .value.m2f = value
    };
    *pUniform = uniform;
}

void R_CreateUniformMat3f(const char* name, amat3f_t value, 
                          A_OUT GfxShaderUniformDef* pUniform
) {
    GfxShaderUniformDef uniform = {
        .name      = A_cstrdup(name),
        .name_hash = R_HashUniformName(name),
        .location  = -1,
        .type      = UNIFORM_TYPE_MAT3F,
        .value.m3f = value
    };
    *pUniform = uniform;
}

void R_CreateUniformMat4f(const char* name, amat4f_t value, 
                          A_OUT GfxShaderUniformDef* pUniform
) {
    GfxShaderUniformDef uniform = {
        .name      = A_cstrdup(name),
        .name_hash = R_HashUniformName(name),
        .location  = -1,
        .type      = UNIFORM_TYPE_MAT4F,
        .value.m4f = value
    };
    *pUniform = uniform;
}

void R_SetUniformBool(A_INOUT GfxShaderUniformDef* pUniform, bool value) {
    assert(pUniform);
    assert(pUniform->type == UNIFORM_TYPE_BOOL);
    if (pUniform->type != UNIFORM_TYPE_BOOL) {
        Com_Errorln(
            -1, 
            "R_SetUniformBool: Invalid uniform type %d.", 
            pUniform->type
        );
    }
    pUniform->value.b = value;
    if (pUniform->location != -1) {
        GL_CALL(glUniform1i, pUniform->location, value);
    }
}

void R_SetUniformFloat(A_INOUT GfxShaderUniformDef* pUniform, float value) {
    assert(pUniform);
    assert(pUniform->type == UNIFORM_TYPE_FLOAT);
    if (pUniform->type != UNIFORM_TYPE_FLOAT) {
        Com_Errorln(
            -1,
            "R_SetUniformFloat: Invalid uniform type %d.",
            pUniform->type
        );
    }
    pUniform->value.f = value;
}

void R_SetUniformFloatArray(A_INOUT GfxShaderUniformDef* pUniform, 
                            const float* value, int count
) {
    assert(pUniform);
    assert(pUniform->type == UNIFORM_TYPE_FLOAT_ARRAY);
    if (pUniform->type != UNIFORM_TYPE_FLOAT_ARRAY) {
        Com_Errorln(
            -1,
            "R_SetUniformFloatArray: Invalid uniform type %d.",
            pUniform->type
        );
    }
    pUniform->value.fa = value;
    pUniform->value.fcount = count;
}

void R_SetUniformVec2f(A_INOUT GfxShaderUniformDef* pUniform, avec2f_t value) {
    assert(pUniform);
    assert(pUniform->type == UNIFORM_TYPE_VEC2F);
    if (pUniform->type != UNIFORM_TYPE_VEC2F) {
        Com_Errorln(
            -1,
            "R_SetUniformVec2f: Invalid uniform type %d.",
            pUniform->type
        );
    }
    pUniform->value.v2f = value;
}

void R_SetUniformVec3f(A_INOUT GfxShaderUniformDef* pUniform, avec3f_t value) {
    assert(pUniform);
    assert(pUniform->type == UNIFORM_TYPE_VEC3F);
    if (pUniform->type != UNIFORM_TYPE_VEC3F) {
        Com_Errorln(
            -1,
            "R_SetUniformVec3f: Invalid uniform type %d.",
            pUniform->type
        );
    }
    pUniform->value.v3f = value;
}

void R_SetUniformVec4f(A_INOUT GfxShaderUniformDef* pUniform, avec4f_t value) {
    assert(pUniform);
    assert(pUniform->type == UNIFORM_TYPE_VEC4F);
    if (pUniform->type != UNIFORM_TYPE_VEC4F) {
        Com_Errorln(
            -1,
            "R_SetUniformVec4f: Invalid uniform type %d.",
            pUniform->type
        );
    }
    pUniform->value.v4f = value;
}

void R_SetUniformInt(A_INOUT GfxShaderUniformDef* pUniform, int value) {
    assert(pUniform);
    assert(pUniform->type == UNIFORM_TYPE_INT);
    if (pUniform->type != UNIFORM_TYPE_INT) {
        Com_Errorln(
            -1,
            "R_SetUniformInt: Invalid uniform type %d.",
            pUniform->type
        );
    }
    pUniform->value.i = value;
}

void R_SetUniformIntArray(A_INOUT GfxShaderUniformDef* pUniform,
                          const int* value, int count
) {
    assert(pUniform);
    assert(pUniform->type == UNIFORM_TYPE_INT_ARRAY);
    if (pUniform->type != UNIFORM_TYPE_INT_ARRAY) {
        Com_Errorln(
            -1,
            "R_SetUniformIntArray: Invalid uniform type %d.",
            pUniform->type
        );
    }
    pUniform->value.ia = value;
    pUniform->value.icount = count;
}

void R_SetUniformVec2i(A_INOUT GfxShaderUniformDef* pUniform, avec2i_t value) {
    assert(pUniform);
    assert(pUniform->type == UNIFORM_TYPE_VEC2I);
    if (pUniform->type != UNIFORM_TYPE_VEC2I) {
        Com_Errorln(
            -1,
            "R_SetUniformVec2i: Invalid uniform type %d.",
            pUniform->type
        );
    }
    pUniform->value.v2i = value;
}

void R_SetUniformVec3i(A_INOUT GfxShaderUniformDef* pUniform, avec3i_t value) {
    assert(pUniform);
    assert(pUniform->type == UNIFORM_TYPE_VEC3I);
    if (pUniform->type != UNIFORM_TYPE_VEC3I) {
        Com_Errorln(
            -1,
            "R_SetUniformVec3i: Invalid uniform type %d.",
            pUniform->type
        );
    }
    pUniform->value.v3i = value;
}

void R_SetUniformVec4i(A_INOUT GfxShaderUniformDef* pUniform, avec4i_t value) {
    assert(pUniform);
    assert(pUniform->type == UNIFORM_TYPE_VEC4I);
    if (pUniform->type != UNIFORM_TYPE_VEC4I) {
        Com_Errorln(
            -1,
            "R_SetUniformVec4i: Invalid uniform type %d.",
            pUniform->type
        );
    }
    pUniform->value.v4i = value;
}

void R_SetUniformUint(A_INOUT GfxShaderUniformDef* pUniform, unsigned int value) {
    assert(pUniform);
    assert(pUniform->type == UNIFORM_TYPE_UINT);
    if (pUniform->type != UNIFORM_TYPE_UINT) {
        Com_Errorln(
            -1,
            "R_SetUniformUint: Invalid uniform type %d.",
            pUniform->type
        );
    }
    pUniform->value.u = value;
}

void R_SetUniformUintArray(A_INOUT GfxShaderUniformDef* pUniform,
    const unsigned int* value, int count
) {
    assert(pUniform);
    assert(pUniform->type == UNIFORM_TYPE_UINT_ARRAY);
    if (pUniform->type != UNIFORM_TYPE_UINT_ARRAY) {
        Com_Errorln(
            -1,
            "R_SetUniformUintArray: Invalid uniform type %d.",
            pUniform->type
        );
    }
    pUniform->value.ua = value;
}

void R_SetUniformMat2f(A_INOUT GfxShaderUniformDef* pUniform, amat2f_t value) {
    assert(pUniform);
    assert(pUniform->type == UNIFORM_TYPE_MAT2F);
    if (pUniform->type != UNIFORM_TYPE_MAT2F) {
        Com_Errorln(
            -1,
            "R_SetUniformMat2f: Invalid uniform type %d.",
            pUniform->type
        );
    }
    pUniform->value.m2f = value;
}

void R_SetUniformMat3f(A_INOUT GfxShaderUniformDef* pUniform, amat3f_t value) {
    assert(pUniform);
    assert(pUniform->type == UNIFORM_TYPE_MAT3F);
    if (pUniform->type != UNIFORM_TYPE_MAT3F) {
        Com_Errorln(
            -1,
            "R_SetUniformMat3f: Invalid uniform type %d.",
            pUniform->type
        );
    }
    pUniform->value.m3f = value;
}

void R_SetUniformMat4f(A_INOUT GfxShaderUniformDef* pUniform, amat4f_t value) {
    assert(pUniform);
    assert(pUniform->type == UNIFORM_TYPE_MAT4F);
    if (pUniform->type != UNIFORM_TYPE_MAT4F) {
        Com_Errorln(
            -1,
            "R_SetUniformMat4f: Invalid uniform type %d.",
            pUniform->type
        );
    }
    pUniform->value.m4f = value;
}

void R_DeleteUniform(A_IN GfxShaderUniformDef* pUniform) {
    assert(pUniform);
    A_cstrfree(pUniform->name);
    pUniform->name      =  NULL;
    pUniform->location  = -1;
    pUniform->type      =  UNIFORM_TYPE_INVALID;
    pUniform->value.i   =  0;
    pUniform->name_hash = -1;
}