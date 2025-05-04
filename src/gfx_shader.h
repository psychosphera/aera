#pragma once

#if A_RENDER_BACKEND_D3D9
#include <d3dx9mesh.h>
#include <d3dx9shader.h>
#endif // A_RENDER_BACKEND_D3D9

#include "com_defs.h"
#include "gfx_defs.h"
#include "gfx_uniform.h"

#define R_SHADER_MAX_UNIFORM 16

#if A_RENDER_BACKEND_GL
typedef GLint GfxCompiledShader;
#elif A_RENDER_BACKEND_D3D9
typedef LPD3DXBUFFER GfxCompiledShader;
#endif // A_RENDER_BACKEND_GL

typedef struct GfxVertexShader {
#if A_RENDER_BACKEND_D3D9
    IDirect3DVertexShader9* vs;
    ID3DXConstantTable*     constant_table;
#endif // A_RENDER_BACKEND_D3D9
    GfxCompiledShader       compiled_shader;
} GfxVertexShader;

typedef struct GfxPixelShader {
#if A_RENDER_BACKEND_D3D9
    IDirect3DPixelShader9* ps;
    ID3DXConstantTable*    constant_table;
#endif // A_RENDER_BACKEND_D3D9
    GfxCompiledShader      compiled_shader;
} GfxPixelShader;

typedef struct GfxShaderProgram {
#if A_RENDER_BACKEND_GL
	shader_program_t program;
#elif A_RENDER_BACKEND_D3D9
    int current_location;
#endif // A_RENDER_BACKEND_GL
    GfxVertexShader vertex_shader;
    GfxPixelShader  pixel_shader;
    int current_uniform;
    GfxShaderUniformDef uniforms[R_SHADER_MAX_UNIFORM];
} GfxShaderProgram;

A_EXTERN_C A_NO_DISCARD bool R_CompileVertexShader(
    A_INOUT GfxShaderProgram* prog,
    const char* shaderSource,
    A_OUT GfxVertexShader* shader
);

A_EXTERN_C A_NO_DISCARD bool R_CompilePixelShader(
    A_INOUT GfxShaderProgram* prog,
    const char* shaderSource,
    A_OUT GfxPixelShader* shader
);

A_EXTERN_C A_NO_DISCARD bool R_CreateShaderProgram(
    const char* vertexSource,
    const char* pixelSource,
    A_OUT GfxShaderProgram* prog
);

A_EXTERN_C int R_ShaderAddUniform(A_INOUT GfxShaderProgram* prog,
                                  A_IN GfxShaderUniformDef* uniform);
A_EXTERN_C GfxShaderUniformDef* R_ShaderGetUniform(
    A_INOUT GfxShaderProgram* prog, int i
);
A_EXTERN_C GfxShaderUniformDef* R_ShaderGetUniformByName(
    A_INOUT GfxShaderProgram* prog, const char* name
);
A_EXTERN_C void R_ShaderSetUniformBool(A_INOUT GfxShaderProgram* prog,
                                       int i, bool value);
A_EXTERN_C void R_ShaderSetUniformBoolByName(A_INOUT GfxShaderProgram* prog,
                                             const char* name, bool value);
A_EXTERN_C void R_ShaderSetUniformFloat(A_INOUT GfxShaderProgram* prog,
                                        int i, float value);
A_EXTERN_C void R_ShaderSetUniformFloatByName(A_INOUT GfxShaderProgram* prog,
                                              const char* name, float value);
A_EXTERN_C void R_ShaderSetUniformFloatArray(A_INOUT GfxShaderProgram* prog,
                                             int i, 
                                             const float* value, int count);
A_EXTERN_C void R_ShaderSetUniformFloatArrayByName(
    A_INOUT GfxShaderProgram* prog,
    const char* name, 
    const float* value, int count
);
A_EXTERN_C void R_ShaderSetUniformVec2f(A_INOUT GfxShaderProgram* prog,
                                        int i, 
                                        avec2f_t value);
A_EXTERN_C void R_ShaderSetUniformVec2fByName(A_INOUT GfxShaderProgram* prog,
                                              const char* name, 
                                              avec2f_t value);
A_EXTERN_C void R_ShaderSetUniformVec3f(A_INOUT GfxShaderProgram* prog,
                                        int i, avec3f_t value);
A_EXTERN_C void R_ShaderSetUniformVec3fByName(A_INOUT GfxShaderProgram* prog,
                                   const char* name, avec3f_t value);
A_EXTERN_C void R_ShaderSetUniformVec4f(A_INOUT GfxShaderProgram* prog,
                                        int i, avec4f_t value);
A_EXTERN_C void R_ShaderSetUniformVec4fByName(A_INOUT GfxShaderProgram* prog,
                                              const char* name, 
                                              avec4f_t value);
A_EXTERN_C void R_ShaderSetUniformInt(A_INOUT GfxShaderProgram* prog,
                                      int i, int value);
A_EXTERN_C void R_ShaderSetUniformIntByName(A_INOUT GfxShaderProgram* prog,
                                            const char* name, int value);
A_EXTERN_C void R_ShaderSetUniformUint(A_INOUT GfxShaderProgram* prog,
                                       int i, unsigned int value);
A_EXTERN_C void R_ShaderSetUniformUintByName(A_INOUT GfxShaderProgram* prog,
                                             const char* name, 
                                             unsigned int value);
A_EXTERN_C void R_ShaderSetUniformIntArray(A_INOUT GfxShaderProgram* prog,
                                           int i, const int* value, int count);
A_EXTERN_C void R_ShaderSetUniformIntArrayByName(
    A_INOUT GfxShaderProgram* prog, 
    const char* name, 
    const int* value, int count
);
A_EXTERN_C void R_ShaderSetUniformVec2i(A_INOUT GfxShaderProgram* prog,
                                        int i,
                                        avec2i_t value);
A_EXTERN_C void R_ShaderSetUniformVec2iByName(A_INOUT GfxShaderProgram* prog,
                                              const char* name, 
                                              avec2i_t value);
A_EXTERN_C void R_ShaderSetUniformVec3i(A_INOUT GfxShaderProgram* prog,
                                        int i, 
                                        avec3i_t value);
A_EXTERN_C void R_ShaderSetUniformVec3iByName(A_INOUT GfxShaderProgram* prog,
                                              const char* name, 
                                              avec3i_t value);
A_EXTERN_C void R_ShaderSetUniformVec4i(A_INOUT GfxShaderProgram* prog,
                                        int i, avec4i_t value);
A_EXTERN_C void R_ShaderSetUniformVec4iByName(A_INOUT GfxShaderProgram* prog,
                                              const char* name, 
                                              avec4i_t value);
A_EXTERN_C void R_ShaderSetUniformMat2f(A_INOUT GfxShaderProgram* prog,
                                        int i, amat2f_t value);
A_EXTERN_C void R_ShaderSetUniformMat2fByName(A_INOUT GfxShaderProgram* prog,
                                              const char* name, 
                                              amat2f_t value);
A_EXTERN_C void R_ShaderSetUniformMat3f(A_INOUT GfxShaderProgram* prog,
                                        int i, amat3f_t value);
A_EXTERN_C void R_ShaderSetUniformMat3fByName(A_INOUT GfxShaderProgram* prog,
                                              const char* name, 
                                              amat3f_t value);
A_EXTERN_C void R_ShaderSetUniformMat4f(A_INOUT GfxShaderProgram* prog,
                                        int i, amat4f_t value);
A_EXTERN_C void R_ShaderSetUniformMat4fByName(A_INOUT GfxShaderProgram* prog,
                                              const char* name, amat4f_t value);

A_EXTERN_C bool R_DeleteShaderProgram(A_INOUT GfxShaderProgram* prog);
