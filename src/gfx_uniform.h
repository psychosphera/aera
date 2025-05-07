#pragma once

#include "gfx_defs.h"

typedef enum GfxUniformType {
    UNIFORM_TYPE_INVALID,
    UNIFORM_TYPE_BOOL,
    UNIFORM_TYPE_FLOAT,
    UNIFORM_TYPE_FLOAT_ARRAY,
    UNIFORM_TYPE_VEC2F,
    UNIFORM_TYPE_VEC3F,
    UNIFORM_TYPE_VEC4F,
    UNIFORM_TYPE_INT,
    UNIFORM_TYPE_INT_ARRAY,
    UNIFORM_TYPE_VEC2I,
    UNIFORM_TYPE_VEC3I,
    UNIFORM_TYPE_VEC4I,
    UNIFORM_TYPE_UINT,
    UNIFORM_TYPE_UINT_ARRAY,
    UNIFORM_TYPE_MAT2F,
    UNIFORM_TYPE_MAT3F,
    UNIFORM_TYPE_MAT4F,
} GfxUniformType;

typedef union GfxUniformValue {
    bool          b;
    float         f;
    struct { const float* fa; float fcount; };
    avec2f_t      v2f;
    avec3f_t      v3f;
    avec4f_t      v4f;
    int           i;
    struct { const int* ia; int icount; };
    avec2i_t      v2i;
    avec3i_t      v3i;
    avec4i_t      v4i;
    unsigned int  u;
    struct { const unsigned int* ua; unsigned int ucount; };
    amat2f_t      m2f;
    amat3f_t      m3f;
    amat4f_t      m4f;
} GfxUniformValue;

typedef struct GfxUniformDef {
    const char*     name;
    int             name_hash;
    int             location;
    GfxUniformType  type;
    GfxUniformValue value;
} GfxShaderUniformDef;

A_EXTERN_C uint32_t R_HashUniformName(const char* name);

A_EXTERN_C void R_CreateUniformBool(const char* name, bool value, 
                                    A_OUT GfxShaderUniformDef* pUniform);
A_EXTERN_C void R_CreateUniformFloat(const char* name, float value,
                                     A_OUT GfxShaderUniformDef* pUniform);
A_EXTERN_C void R_CreateUniformFloatArray(const char* name, 
                                          const float* value,
                                          int count, A_OUT 
                                          GfxShaderUniformDef* pUniform);
A_EXTERN_C void R_CreateUniformVec2f(const char* name, avec2f_t value,
                                     A_OUT GfxShaderUniformDef* pUniform);
A_EXTERN_C void R_CreateUniformVec3f(const char* name, avec3f_t value,
                                     A_OUT GfxShaderUniformDef* pUniform);
A_EXTERN_C void R_CreateUniformVec4f(const char* name, avec4f_t value,
                                     A_OUT GfxShaderUniformDef* pUniform);
A_EXTERN_C void R_CreateUniformInt(const char* name, int value,
                                   A_OUT GfxShaderUniformDef* pUniform);
A_EXTERN_C void R_CreateUniformIntArray(const char* name,
                                        const int* value, 
                                        int count,
                                        A_OUT GfxShaderUniformDef* pUniform);
A_EXTERN_C void R_CreateUniformVec2i(const char* name, avec2i_t value,
                                     A_OUT GfxShaderUniformDef* pUniform);
A_EXTERN_C void R_CreateUniformVec3i(const char* name, avec3i_t value,
                                     A_OUT GfxShaderUniformDef* pUniform);
A_EXTERN_C void R_CreateUniformVec4i(const char* name, avec4i_t value,
                                     A_OUT GfxShaderUniformDef* pUniform);
A_EXTERN_C void R_CreateUniformUint(const char* name, unsigned int value,
                                    A_OUT GfxShaderUniformDef* pUniform);
A_EXTERN_C void R_CreateUniformUintArray(const char* name, 
                                         const unsigned int* value,
                                         int count, 
                                         A_OUT GfxShaderUniformDef* pUniform);
A_EXTERN_C void R_CreateUniformMat2f(const char* name, amat2f_t value,
                                     A_OUT GfxShaderUniformDef* pUniform);
A_EXTERN_C void R_CreateUniformMat3f(const char* name, amat3f_t value,
                                     A_OUT GfxShaderUniformDef* pUniform);
A_EXTERN_C void R_CreateUniformMat4f(const char* name, amat4f_t value,
                                     A_OUT GfxShaderUniformDef* pUniform);
A_EXTERN_C void R_SetUniformBool(A_INOUT GfxShaderUniformDef* pUniform, 
                                bool value);
A_EXTERN_C void R_SetUniformFloat(A_INOUT GfxShaderUniformDef* pUniform, 
                                  float value);
A_EXTERN_C void R_SetUniformFloatArray(A_INOUT GfxShaderUniformDef* pUniform,
                                       const float* value, int count);
A_EXTERN_C void R_SetUniformVec2f(A_INOUT GfxShaderUniformDef* pUniform, 
                                  avec2f_t value);
A_EXTERN_C void R_SetUniformVec3f(A_INOUT GfxShaderUniformDef* pUniform, 
                                  avec3f_t value);
A_EXTERN_C void R_SetUniformVec4f(A_INOUT GfxShaderUniformDef* pUniform, 
                                  avec4f_t value);
A_EXTERN_C void R_SetUniformInt(A_INOUT GfxShaderUniformDef* pUniform,
                                int value);
A_EXTERN_C void R_SetUniformIntArray(A_INOUT GfxShaderUniformDef* pUniform,
                                     const int* value, int count);
A_EXTERN_C void R_SetUniformVec2i(A_INOUT GfxShaderUniformDef* pUniform, 
                                  avec2i_t value);
A_EXTERN_C void R_SetUniformVec3i(A_INOUT GfxShaderUniformDef* pUniform, 
                                  avec3i_t value);
A_EXTERN_C void R_SetUniformVec4i(A_INOUT GfxShaderUniformDef* pUniform, 
                                  avec4i_t value);
A_EXTERN_C void R_SetUniformUint(A_INOUT GfxShaderUniformDef* pUniform, 
                                 unsigned int value);
A_EXTERN_C void R_SetUniformUintArray(A_INOUT GfxShaderUniformDef* pUniform,
                                      const unsigned int* value, int count);
A_EXTERN_C void R_SetUniformMat2f(A_INOUT GfxShaderUniformDef* pUniform, 
                                  amat2f_t value);
A_EXTERN_C void R_SetUniformMat3f(A_INOUT GfxShaderUniformDef* pUniform, 
                                  amat3f_t value);
A_EXTERN_C void R_SetUniformMat4f(A_INOUT GfxShaderUniformDef* pUniform, 
                                  amat4f_t value);

A_EXTERN_C void R_DeleteUniform(A_IN GfxShaderUniformDef* pUniform);
