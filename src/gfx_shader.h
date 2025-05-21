#pragma once

#if A_RENDER_BACKEND_D3D9
#include <d3dx9mesh.h>
#include <d3dx9shader.h>
#endif // A_RENDER_BACKEND_D3D9

#include "com_defs.h"
#include "gfx_defs.h"
#include "gfx_uniform.h"

#define R_SHADER_MAX_UNIFORM 20

#if A_RENDER_BACKEND_GL
typedef GLint GfxCompiledShader;
#elif A_RENDER_BACKEND_D3D9 || A_RENDER_BACKEND_D3D8
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

#if !A_TARGET_PLATFORM_IS_XBOX
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
#endif // !A_TARGET_PLATFORM_IS_XBOX

A_EXTERN_C A_NO_DISCARD bool R_CreateShaderProgram(
    const char* vertexSource,
    const char* pixelSource,
    A_OUT GfxShaderProgram* prog
);

typedef enum ShaderType {
    SHADER_TYPE_VERTEX,
    SHADER_TYPE_PIXEL,
} ShaderType;

#if !A_TARGET_PLATFORM_IS_XBOX
A_EXTERN_C GfxShaderUniformDef* R_ShaderAddUniform(
    A_INOUT GfxShaderProgram* prog, int shader_type,
    A_IN GfxShaderUniformDef* uniform
);
A_EXTERN_C GfxShaderUniformDef* R_ShaderGetUniform(
    A_INOUT GfxShaderProgram* prog, int i
);
A_EXTERN_C GfxShaderUniformDef* R_ShaderGetUniformByName(
    A_INOUT GfxShaderProgram* prog, const char* name
);
A_EXTERN_C void R_ShaderSetUniformBool(A_INOUT GfxShaderProgram* prog,
                                       int i, int shader_type, bool value);
A_EXTERN_C void R_ShaderSetUniformBoolByName(A_INOUT GfxShaderProgram* prog,
                                             const char* name, int shader_type,
                                             bool value);
A_EXTERN_C void R_ShaderSetUniformFloat(A_INOUT GfxShaderProgram* prog,
                                        int i, int shader_type, float value);
A_EXTERN_C void R_ShaderSetUniformFloatByName(A_INOUT GfxShaderProgram* prog,
                                              const char* name, int shader_type,
                                              float value);
A_EXTERN_C void R_ShaderSetUniformFloatArray(A_INOUT GfxShaderProgram* prog,
                                             int i, int shader_type,
                                             const float* value, int count);
A_EXTERN_C void R_ShaderSetUniformFloatArrayByName(
    A_INOUT GfxShaderProgram* prog,
    const char* name, int shader_type,
    const float* value, int count
);
A_EXTERN_C void R_ShaderSetUniformVec2f(A_INOUT GfxShaderProgram* prog,
                                        int i, int shader_type,
                                        avec2f_t value);
A_EXTERN_C void R_ShaderSetUniformVec2fByName(A_INOUT GfxShaderProgram* prog,
                                              const char* name, int shader_type,
                                              avec2f_t value);
A_EXTERN_C void R_ShaderSetUniformVec3f(A_INOUT GfxShaderProgram* prog,
                                        int i, int shader_type, avec3f_t value);
A_EXTERN_C void R_ShaderSetUniformVec3fByName(A_INOUT GfxShaderProgram* prog,
                                              const char* name, int shader_type,
                                              avec3f_t value);
A_EXTERN_C void R_ShaderSetUniformVec4f(A_INOUT GfxShaderProgram* prog,
                                        int i, int shader_type, 
                                        avec4f_t value);
A_EXTERN_C void R_ShaderSetUniformVec4fByName(A_INOUT GfxShaderProgram* prog,
                                              const char* name, 
                                              int shader_type,
                                              avec4f_t value);
A_EXTERN_C void R_ShaderSetUniformInt(A_INOUT GfxShaderProgram* prog,
                                      int i, int shader_type, int value);
A_EXTERN_C void R_ShaderSetUniformIntByName(A_INOUT GfxShaderProgram* prog,
                                            const char* name, int shader_type,
                                            int value);
A_EXTERN_C void R_ShaderSetUniformUint(A_INOUT GfxShaderProgram* prog,
                                       int i, int shader_type, 
                                       unsigned int value);
A_EXTERN_C void R_ShaderSetUniformUintByName(A_INOUT GfxShaderProgram* prog,
                                             const char* name, 
                                             int shader_type,
                                             unsigned int value);
A_EXTERN_C void R_ShaderSetUniformIntArray(A_INOUT GfxShaderProgram* prog,
                                           int i, int shader_type, 
                                           const int* value, int count);
A_EXTERN_C void R_ShaderSetUniformIntArrayByName(
    A_INOUT GfxShaderProgram* prog, 
    const char* name, int shader_type,
    const int* value, int count
);
A_EXTERN_C void R_ShaderSetUniformVec2i(A_INOUT GfxShaderProgram* prog,
                                        int i, int shader_type,
                                        avec2i_t value);
A_EXTERN_C void R_ShaderSetUniformVec2iByName(A_INOUT GfxShaderProgram* prog,
                                              const char* name, 
                                              int shader_type,
                                              avec2i_t value);
A_EXTERN_C void R_ShaderSetUniformVec3i(A_INOUT GfxShaderProgram* prog,
                                        int i, int shader_type,
                                        avec3i_t value);
A_EXTERN_C void R_ShaderSetUniformVec3iByName(A_INOUT GfxShaderProgram* prog,
                                              const char* name, 
                                              int shader_type,
                                              avec3i_t value);
A_EXTERN_C void R_ShaderSetUniformVec4i(A_INOUT GfxShaderProgram* prog,
                                        int i, int shader_type, 
                                        avec4i_t value);
A_EXTERN_C void R_ShaderSetUniformVec4iByName(A_INOUT GfxShaderProgram* prog,
                                              const char* name, 
                                              int shader_type,
                                              avec4i_t value);
A_EXTERN_C void R_ShaderSetUniformMat2f(A_INOUT GfxShaderProgram* prog,
                                        int i, int shader_type, 
                                        amat2f_t value);
A_EXTERN_C void R_ShaderSetUniformMat2fByName(A_INOUT GfxShaderProgram* prog,
                                              const char* name, 
                                              int shader_type,
                                              amat2f_t value);
A_EXTERN_C void R_ShaderSetUniformMat3f(A_INOUT GfxShaderProgram* prog,
                                        int shader_type,
                                        int i, amat3f_t value);
A_EXTERN_C void R_ShaderSetUniformMat3fByName(A_INOUT GfxShaderProgram* prog,
                                              const char* name, 
                                              int shader_type,
                                              amat3f_t value);
A_EXTERN_C void R_ShaderSetUniformMat4f(A_INOUT GfxShaderProgram* prog,
                                        int shader_type,
                                        int i, amat4f_t value);
A_EXTERN_C void R_ShaderSetUniformMat4fByName(A_INOUT GfxShaderProgram* prog,
                                              const char* name,
                                              int shader_type,
                                              amat4f_t value);
#endif // !A_TARGET_PLATFORM_IS_XBOX
A_EXTERN_C bool R_DeleteShaderProgram(A_INOUT GfxShaderProgram* prog);
