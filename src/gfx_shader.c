#include "gfx_shader.h"

#include <assert.h>

#if A_RENDER_BACKEND_D3D9
#include <d3dx9shader.h>
#endif // A_RENDER_BACKEND_D3D9

#include "acommon/a_math.h"
#include "acommon/a_string.h"
#include "acommon/z_mem.h"

#include "com_print.h"
#include "gfx_uniform.h"

#define R_MAX_SHADER_ERROR_LEN 1024

static char s_lastShaderError[R_MAX_SHADER_ERROR_LEN];

void R_SetLastShaderError(const char* error, size_t n) {
    A_cstrncpyz(s_lastShaderError, error, n);
}

const char* R_GetLastShaderError(void) {
    return s_lastShaderError;
}

#if A_RENDER_BACKEND_GL
static bool R_CompileShaderGL(
    const char* shaderSource, 
    A_OUT GfxCompiledShader* shader
) {
    GL_CALL(glShaderSource, *shader, 1, &shaderSource, NULL);
    GL_CALL(glCompileShader, *shader);

    int success = GL_FALSE;
    GL_CALL(glGetShaderiv, *shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        GL_CALL(glGetShaderInfoLog, *shader, sizeof(s_lastShaderError),
                                    NULL, s_lastShaderError);
    }

    return success == GL_TRUE;
}
#elif A_RENDER_BACKEND_D3D9
static bool R_CompileShaderD3D9(
    const char* shaderSource,
    A_OUT LPD3DXBUFFER* shader,
    A_OUT LPD3DXCONSTANTTABLE* constant_table
) {
    assert(shader);
    ID3DXBuffer* error = NULL;
    HRESULT hr = D3DXCompileShader(
        shaderSource, A_cstrlen(shaderSource), NULL, NULL,
        "main", "vs_2_0", 0, shader, &error, constant_table
    );
    if (hr != D3D_OK) {
        R_SetLastShaderError(error->lpVtbl->GetBufferPointer(error),
                             error->lpVtbl->GetBufferSize(error));
        Com_Errorln(-1,
            "Failed to compile vertex shader: %s.",
            R_GetLastShaderError());
        return false;
    }
    if (error)
        error->lpVtbl->Release(error);

    return hr == D3D_OK;
}
#endif // A_RENDER_BACKEND_GL

A_NO_DISCARD bool R_CompileVertexShader(
    A_INOUT GfxShaderProgram* prog,
    const char* shaderSource,
    A_OUT GfxVertexShader* shader
) {
    assert(prog);
    assert(shader);
    assert(shaderSource);
#if A_RENDER_BACKEND_GL
    shader->compiled_shader = GL_CALL(glCreateShader, GL_VERTEX_SHADER);
    return R_CompileShaderGL(shaderSource, &shader->compiled_shader);
#elif A_RENDER_BACKEND_D3D9
    return R_CompileShaderD3D9(
        shaderSource, &prog->vertex_shader.compiled_shader,
        &prog->vertex_shader.constant_table
    );
#endif // A_RENDER_BACKEND_GL
}

A_NO_DISCARD bool R_CompilePixelShader(
    A_INOUT GfxShaderProgram* prog,
    const char* shaderSource,
    A_OUT GfxPixelShader* shader
) {
    assert(prog);
    assert(shader);
    assert(shaderSource);
#if A_RENDER_BACKEND_GL
    shader->compiled_shader = GL_CALL(glCreateShader, GL_FRAGMENT_SHADER);
    return R_CompileShaderGL(shaderSource, &shader->compiled_shader);
#elif A_RENDER_BACKEND_D3D9
    return R_CompileShaderD3D9(
        shaderSource, &prog->pixel_shader.compiled_shader,
        &prog->pixel_shader.constant_table
    );
#endif // A_RENDER_BACKEND_GL
}

#if A_RENDER_BACKEND_GL
A_NO_DISCARD bool R_LinkShadersGL(
    A_INOUT GfxCompiledShader* vertShader,
    A_INOUT GfxCompiledShader* fragShader,
    A_INOUT GfxShaderProgram*  prog
) {
    prog->program = GL_CALL(glCreateProgram);
    GL_CALL(glAttachShader, prog->program, *vertShader);
    GL_CALL(glAttachShader, prog->program, *fragShader);
    GL_CALL(glLinkProgram,  prog->program);

    GLint success = GL_FALSE;
    GL_CALL(glGetProgramiv, prog->program, GL_LINK_STATUS, &success);
    if (!success) {
        GL_CALL(glGetProgramInfoLog, prog->program, A_countof(s_lastShaderError), 
                                     NULL, s_lastShaderError);
    }
    GL_CALL(glDeleteShader, *vertShader);
    GL_CALL(glDeleteShader, *fragShader);
    *vertShader = 0;
    *fragShader = 0;

    return success == GL_TRUE;
}
#endif // A_RENDER_BACKEND_GL

#if A_RENDER_BACKEND_D3D9
static bool R_CreateVertexShaderD3D9(A_INOUT GfxShaderProgram*  prog, 
                                     A_IN    GfxCompiledShader* compiled_shader
) {
    D3D_CALL(r_d3d9Glob.d3ddev, CreateVertexShader,
        (*compiled_shader)->lpVtbl->GetBufferPointer(*compiled_shader),
        &prog->vertex_shader.vs
    );
       
    (*compiled_shader)->lpVtbl->Release(*compiled_shader);
    *compiled_shader = NULL;
    return true;
}

static bool R_CreatePixelShaderD3D9(A_INOUT GfxShaderProgram*  prog,
                                    A_IN    GfxCompiledShader* compiled_shader
) {
    D3D_CALL(r_d3d9Glob.d3ddev, CreatePixelShader,
        (*compiled_shader)->lpVtbl->GetBufferPointer(*compiled_shader),
        &prog->pixel_shader.ps
    );
    (*compiled_shader)->lpVtbl->Release(*compiled_shader);
    *compiled_shader = NULL;
    return true;
}
#endif // A_RENDER_BACKEND_D3D9

A_NO_DISCARD bool R_CreateShaderProgram(
    const char* vertexSource, 
    const char* pixelSource,
    A_OUT GfxShaderProgram* prog
) {
    A_memset(prog, 0, sizeof(*prog));

    if (!R_CompileVertexShader(prog, vertexSource, &prog->vertex_shader))
        return false;

    if (!R_CompilePixelShader(prog, pixelSource, &prog->pixel_shader))
        return false;

#if A_RENDER_BACKEND_GL
    if (!R_LinkShadersGL(&prog->vertex_shader.compiled_shader, 
                         &prog->pixel_shader.compiled_shader, prog
    ))
        return false;
#elif A_RENDER_BACKEND_D3D9
    if (!R_CreateVertexShaderD3D9(prog, &prog->vertex_shader.compiled_shader))
        return false;
    if (!R_CreatePixelShaderD3D9(prog, &prog->pixel_shader.compiled_shader))
        return false;
#endif // A_RENDER_BACKEND_GL
    return true;
}

#if A_RENDER_BACKEND_GL
static void R_ShaderSetUniformIntGL(shader_program_t program,
                                    int location, int value);
static void R_ShaderSetUniformBoolGL(shader_program_t program,
                                     int locaction, bool value
) {
    R_ShaderSetUniformIntGL(program, locaction, (int)value);
}

static void R_ShaderSetUniformFloatGL(
    shader_program_t program, int location, float value
) {
    assert(location >= 0);
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniform1f, location, value);
}

static void R_ShaderSetUniformFloatArrayGL(
    shader_program_t program, int location,
    const float* value, int count
) {
    assert(location >= 0);
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniform1fv, location, count, value);
}

static void R_ShaderSetUniformVec2fGL(
    shader_program_t program, int location, avec2f_t value
) {
    assert(location >= 0);
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniform2f, location, value.x, value.y);
}

static void R_ShaderSetUniformVec3fGL(
    shader_program_t program, int location, avec3f_t value
) {
    assert(location >= 0);
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniform3f, location, value.x, value.y, value.z);
}

static void R_ShaderSetUniformVec4fGL(
    shader_program_t program, int location, avec4f_t value
) {
    assert(location >= 0);
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniform4f, location, value.x, value.y, value.z, value.w);
}

static void R_ShaderSetUniformIntGL(
    shader_program_t program, int location, int value
) {
    assert(location >= 0);
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniform1i, location, value);
}

static void R_ShaderSetUniformIntArrayGL(
    shader_program_t program, int location,
    const int* value, int count
) {
    assert(location >= 0);
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniform1iv, location, count, value);
}

static void R_ShaderSetUniformVec2iGL(
    shader_program_t program, int location, avec2i_t value
) {
    assert(location >= 0);
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniform2i, location, value.x, value.y);
}

static void R_ShaderSetUniformVec3iGL(
    shader_program_t program, int location, avec3i_t value
) {
    assert(location >= 0);
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniform3i, location, value.x, value.y, value.z);
}

static void R_ShaderSetUniformVec4iGL(
    shader_program_t program, int location, avec4i_t value
) {
    assert(location >= 0);
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniform4i, location, value.x, value.y, value.z, value.w);
}

static void R_ShaderSetUniformUintGL(
    shader_program_t program, int location, unsigned int value
) {
    assert(location >= 0);
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniform1ui, location, value);
}

static void R_ShaderSetUniformUintArrayGL(
    shader_program_t program, int location,
    const unsigned int* value, int count
) {
    assert(location >= 0);
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniform1uiv, location, count, value);
}

static void R_ShaderSetUniformMat2fGL(
    shader_program_t program, int location, const amat2f_t value
) {
    assert(location >= 0);
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniformMatrix2fv, location, 1, GL_FALSE, value.array);
}

static void R_ShaderSetUniformMat3fGL(
    shader_program_t program, int location, amat3f_t value
) {
    assert(location >= 0);
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniformMatrix3fv, location, 1, GL_FALSE, value.array);
}

static void R_ShaderSetUniformMat4fGL(
    shader_program_t program, int location, amat4f_t value
) {
    assert(location >= 0);
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniformMatrix4fv, location, 1, GL_FALSE, value.array);
}

static void R_ShaderSetUniformGL(shader_program_t program, int location,
                                 GfxShaderUniformDef* uniform
) {
    switch (uniform->type) {
    case UNIFORM_TYPE_BOOL:
        R_ShaderSetUniformBoolGL(program, location, uniform->value.b);
        break;
    case UNIFORM_TYPE_FLOAT:
        R_ShaderSetUniformFloatGL(program, location, uniform->value.f);
        break;
    case UNIFORM_TYPE_FLOAT_ARRAY:
        R_ShaderSetUniformFloatArrayGL(program, location, uniform->value.fa, uniform->value.fcount);
        break;
    case UNIFORM_TYPE_VEC2F:
        R_ShaderSetUniformVec2fGL(program, location, uniform->value.v2f);
        break;
    case UNIFORM_TYPE_VEC3F:
        R_ShaderSetUniformVec3fGL(program, location, uniform->value.v3f);
        break;
    case UNIFORM_TYPE_VEC4F:
        R_ShaderSetUniformVec4fGL(program, location, uniform->value.v4f);
        break;
    case UNIFORM_TYPE_INT:
        R_ShaderSetUniformIntGL(program, location, uniform->value.i);
        break;
    case UNIFORM_TYPE_INT_ARRAY:
        R_ShaderSetUniformIntArrayGL(program, location, uniform->value.ia, uniform->value.icount);
        break;
    case UNIFORM_TYPE_VEC2I:
        R_ShaderSetUniformVec2iGL(program, location, uniform->value.v2i);
        break;
    case UNIFORM_TYPE_VEC3I:
        R_ShaderSetUniformVec3iGL(program, location, uniform->value.v3i);
        break;
    case UNIFORM_TYPE_VEC4I:
        R_ShaderSetUniformVec4iGL(program, location, uniform->value.v4i);
        break;
    case UNIFORM_TYPE_UINT:
        R_ShaderSetUniformUintGL(program, location, uniform->value.u);
        break;
    case UNIFORM_TYPE_UINT_ARRAY:
        R_ShaderSetUniformUintArrayGL(program, location, uniform->value.ua, uniform->value.ucount);
        break;
    case UNIFORM_TYPE_MAT2F:
        R_ShaderSetUniformMat2fGL(program, location, uniform->value.m2f);
        break;
    case UNIFORM_TYPE_MAT3F:
        R_ShaderSetUniformMat3fGL(program, location, uniform->value.m3f);
        break;
    case UNIFORM_TYPE_MAT4F:
        R_ShaderSetUniformMat4fGL(program, location, uniform->value.m4f);
        break;
    default:
        assert(false && "R_SetUniformGL: Invalid uniform type.");
        Com_Errorln(
            -1,
            "R_SetUniformGL: Invalid uniform type %d.",
            uniform->type
        );
        break;
    }
}

static void R_ShaderSetUniformIntByNameGL(shader_program_t program,
                                    const char* name, int value);
static void R_ShaderSetUniformBoolByNameGL(shader_program_t program,
                                     const char* name, bool value
) {
    R_ShaderSetUniformIntByNameGL(program, name, (int)value);
}

static void R_ShaderSetUniformFloatByNameGL(
    shader_program_t program, const char* name, float value
) {
    int location = GL_CALL(glGetUniformLocation, program, name);
    R_ShaderSetUniformFloatGL(program, location, value);
}

static void R_ShaderSetUniformFloatArrayByNameGL(
    shader_program_t program, const char* name,
    const float* value, int count
) {
    int location = GL_CALL(glGetUniformLocation, program, name);
    R_ShaderSetUniformFloatArrayGL(program, location, value, count);
}

static void R_ShaderSetUniformVec2fByNameGL(
    shader_program_t program, const char* name, avec2f_t value
) {
    int location = GL_CALL(glGetUniformLocation, program, name);
    R_ShaderSetUniformVec2fGL(program, location, value);
}

static void R_ShaderSetUniformVec3fByNameGL(
    shader_program_t program, const char* name, avec3f_t value
) {
    int location = GL_CALL(glGetUniformLocation, program, name);
    R_ShaderSetUniformVec3fGL(program, location, value);
}

static void R_ShaderSetUniformVec4fByNameGL(
    shader_program_t program, const char* name, avec4f_t value
) {
    int location = GL_CALL(glGetUniformLocation, program, name);
    R_ShaderSetUniformVec4fGL(program, location, value);
}

static void R_ShaderSetUniformIntByNameGL(
    shader_program_t program, const char* name, int value
) {
    int location = GL_CALL(glGetUniformLocation, program, name);
    R_ShaderSetUniformIntGL(program, location, value);
}

static void R_ShaderSetUniformIntArrayByNameGL(
    shader_program_t program, const char* name,
    const int* value, int count
) {
    int location = GL_CALL(glGetUniformLocation, program, name);
    R_ShaderSetUniformIntArrayGL(program, location, value, count);
}

static void R_ShaderSetUniformVec2iByNameGL(
    shader_program_t program, const char* name, avec2i_t value
) {
    int location = GL_CALL(glGetUniformLocation, program, name);
    R_ShaderSetUniformVec2iGL(program, location, value);
}

static void R_ShaderSetUniformVec3iByNameGL(
    shader_program_t program, const char* name, avec3i_t value
) {
    int location = GL_CALL(glGetUniformLocation, program, name);
    R_ShaderSetUniformVec3iGL(program, location, value);
}

static void R_ShaderSetUniformVec4iByNameGL(
    shader_program_t program, const char* name, avec4i_t value
) {
    int location = GL_CALL(glGetUniformLocation, program, name);
    R_ShaderSetUniformVec4iGL(program, location, value);
}

static void R_ShaderSetUniformUintByNameGL(
    shader_program_t program, const char* name, unsigned int value
) {
    int location = GL_CALL(glGetUniformLocation, program, name);
    R_ShaderSetUniformUintGL(program, location, value);
}

static void R_ShaderSetUniformUintArrayByNameGL(
    shader_program_t program, const char* name,
    const unsigned int* value, int count
) {
    int location = GL_CALL(glGetUniformLocation, program, name);
    R_ShaderSetUniformUintArrayGL(program, location, value, count);
}

static void R_ShaderSetUniformMat2fByNameGL(
    shader_program_t program, const char* name, const amat2f_t value
) {
    int location = GL_CALL(glGetUniformLocation, program, name);
    R_ShaderSetUniformMat2fGL(program, location, value);
}

static void R_ShaderSetUniformMat3fByNameGL(
    shader_program_t program, const char* name, amat3f_t value
) {
    int location = GL_CALL(glGetUniformLocation, program, name);
    R_ShaderSetUniformMat3fGL(program, location, value);
}

static void R_ShaderSetUniformMat4fByNameGL(
    shader_program_t program, const char* name, amat4f_t value
) {
    int location = GL_CALL(glGetUniformLocation, program, name);
    R_ShaderSetUniformMat4fGL(program, location, value);
}

static void R_ShaderSetUniformByNameGL(shader_program_t program, 
                                       const char* name,
                                       GfxShaderUniformDef* uniform
) {
    switch (uniform->type) {
    case UNIFORM_TYPE_BOOL:
        R_ShaderSetUniformBoolByNameGL(program, name, uniform->value.b);
        break;
    case UNIFORM_TYPE_FLOAT:
        R_ShaderSetUniformFloatByNameGL(program, name, uniform->value.f);
        break;
    case UNIFORM_TYPE_FLOAT_ARRAY:
        R_ShaderSetUniformFloatArrayByNameGL(program, name, uniform->value.fa,
            uniform->value.fcount);
        break;
    case UNIFORM_TYPE_VEC2F:
        R_ShaderSetUniformVec2fByNameGL(program, name, uniform->value.v2f);
        break;
    case UNIFORM_TYPE_VEC3F:
        R_ShaderSetUniformVec3fByNameGL(program, name, uniform->value.v3f);
        break;
    case UNIFORM_TYPE_VEC4F:
        R_ShaderSetUniformVec4fByNameGL(program, name, uniform->value.v4f);
        break;
    case UNIFORM_TYPE_INT:
        R_ShaderSetUniformIntByNameGL(program, name, uniform->value.i);
        break;
    case UNIFORM_TYPE_INT_ARRAY:
        R_ShaderSetUniformIntArrayByNameGL(program, name, uniform->value.ia,
            uniform->value.icount);
        break;
    case UNIFORM_TYPE_VEC2I:
        R_ShaderSetUniformVec2iByNameGL(program, name, uniform->value.v2i);
        break;
    case UNIFORM_TYPE_VEC3I:
        R_ShaderSetUniformVec3iByNameGL(program, name, uniform->value.v3i);
        break;
    case UNIFORM_TYPE_VEC4I:
        R_ShaderSetUniformVec4iByNameGL(program, name, uniform->value.v4i);
        break;
    case UNIFORM_TYPE_UINT:
        R_ShaderSetUniformUintByNameGL(program, name, uniform->value.u);
        break;
    case UNIFORM_TYPE_UINT_ARRAY:
        R_ShaderSetUniformUintArrayByNameGL(program, name, uniform->value.ua,
            uniform->value.ucount);
        break;
    case UNIFORM_TYPE_MAT2F:
        R_ShaderSetUniformMat2fByNameGL(program, name, uniform->value.m2f);
        break;
    case UNIFORM_TYPE_MAT3F:
        R_ShaderSetUniformMat3fByNameGL(program, name, uniform->value.m3f);
        break;
    case UNIFORM_TYPE_MAT4F:
        R_ShaderSetUniformMat4fByNameGL(program, name, uniform->value.m4f);
        break;
    default:
        assert(false && "R_SetUniformGL: Invalid uniform type.");
        Com_Errorln(
            -1,
            "R_SetUniformGL: Invalid uniform type %d.",
            uniform->type
        );
        break;
    }
}
#elif A_RENDER_BACKEND_D3D9
static bool R_ShaderSetUniformBoolD3D9(ID3DXConstantTable* constant_table, 
                                       int location, bool value
) {
    D3DXHANDLE handle = constant_table->lpVtbl->GetConstant(
        constant_table, NULL, location
    );
    D3D_CALL(constant_table, SetBool, r_d3d9Glob.d3ddev, handle, value);
    return true;
}

static bool R_ShaderSetUniformFloatD3D9(ID3DXConstantTable* constant_table,
    int location, float value
) {
    D3DXHANDLE handle = constant_table->lpVtbl->GetConstant(
        constant_table, NULL, location
    );
    D3D_CALL(constant_table, SetFloat, r_d3d9Glob.d3ddev, handle, value);
    return true;
}

static bool R_ShaderSetUniformFloatArrayD3D9(ID3DXConstantTable* constant_table,
    int location, const float* value, int count
) {
    D3DXHANDLE handle = constant_table->lpVtbl->GetConstant(
        constant_table, NULL, location
    );
    D3D_CALL(constant_table, SetFloatArray, r_d3d9Glob.d3ddev, handle, 
                                                               value, count);
    return true;
}

static bool R_ShaderSetUniformVec4fD3D9(ID3DXConstantTable* constant_table,
    int location, const avec4f_t value
) {
    D3DXHANDLE handle = constant_table->lpVtbl->GetConstant(
        constant_table, NULL, location
    );
    D3D_CALL(constant_table, SetVector, r_d3d9Glob.d3ddev, 
             handle, (D3DXVECTOR4*)value.array);
    return true;
}

static bool R_ShaderSetUniformIntD3D9(ID3DXConstantTable* constant_table,
    int location, int value
) {
    D3DXHANDLE handle = constant_table->lpVtbl->GetConstant(
        constant_table, NULL, location
    );
    D3D_CALL(constant_table, SetInt, r_d3d9Glob.d3ddev, handle, value);
    return true;
}

static bool R_ShaderSetUniformMat4fD3D9(ID3DXConstantTable* constant_table,
    int location, const amat4f_t value
) {
    D3DXHANDLE handle = constant_table->lpVtbl->GetConstant(
        constant_table, NULL, location
    );
    D3D_CALL(constant_table, SetMatrix, r_d3d9Glob.d3ddev,
             handle, (D3DXMATRIX*)value.array);
    return true;
}

static bool R_ShaderSetUniformD3D9(ID3DXConstantTable* constant_table, 
                                         int location,
                                         GfxShaderUniformDef* uniform
) {
    switch (uniform->type) {
    case UNIFORM_TYPE_BOOL:
        return R_ShaderSetUniformBoolD3D9(constant_table, 
                                          location, uniform->value.b);
    case UNIFORM_TYPE_FLOAT:
        return R_ShaderSetUniformFloatD3D9(constant_table, location,
                                           uniform->value.f);
    case UNIFORM_TYPE_FLOAT_ARRAY:
        return R_ShaderSetUniformFloatArrayD3D9(constant_table, location,
                                                uniform->value.fa, 
                                                uniform->value.fcount);
    case UNIFORM_TYPE_VEC4F:
        return R_ShaderSetUniformVec4fD3D9(constant_table, location,
                                           uniform->value.v4f);
    case UNIFORM_TYPE_INT:
        return R_ShaderSetUniformIntD3D9(constant_table, location, 
                                         uniform->value.i);
    case UNIFORM_TYPE_MAT4F:
        return R_ShaderSetUniformMat4fD3D9(constant_table, location,
                                           uniform->value.m4f);
    default:
        assert(false && "R_ShaderSetUniformD3D9: Invalid uniform type.");
        Com_Errorln(
            -1,
            "R_ShaderSetUniformD3D9: Invalid uniform type %d.",
            uniform->type
        );
        return false;
    }
}

static bool R_ShaderSetUniformBoolByNameD3D9(ID3DXConstantTable* constant_table,
                                             const char* name, bool value
) {
    D3DXHANDLE handle = constant_table->lpVtbl->GetConstantByName(
        constant_table, NULL, name
    );
    D3D_CALL(constant_table, SetBool, r_d3d9Glob.d3ddev, handle, value);
    return true;
}

static bool R_ShaderSetUniformFloatByNameD3D9(ID3DXConstantTable* constant_table,
                                              const char* name, float value
) {
    D3DXHANDLE handle = constant_table->lpVtbl->GetConstantByName(
        constant_table, NULL, name
    );
    D3D_CALL(constant_table, SetFloat, r_d3d9Glob.d3ddev, handle, value);
    return true;
}

static bool R_ShaderSetUniformFloatArrayByNameD3D9(
    ID3DXConstantTable* constant_table, const char* name,
    const float* value, int count
) {
    D3DXHANDLE handle = constant_table->lpVtbl->GetConstantByName(
        constant_table, NULL, name
    );
    D3D_CALL(constant_table, SetFloatArray, r_d3d9Glob.d3ddev, handle, 
                                                               value, count);
    return true;
}

static bool R_ShaderSetUniformVec4fByNameD3D9(
    ID3DXConstantTable* constant_table, const char* name,
    const avec4f_t value
) {
    D3DXHANDLE handle = constant_table->lpVtbl->GetConstantByName(
        constant_table, NULL, name
    );
    D3D_CALL(constant_table, SetVector, r_d3d9Glob.d3ddev, 
             handle, (D3DXVECTOR4*)value.array);
    return true;
}

static bool R_ShaderSetUniformIntByNameD3D9(ID3DXConstantTable* constant_table,
                                            const char* name, int value
) {
    D3DXHANDLE handle = constant_table->lpVtbl->GetConstantByName(
        constant_table, NULL, name
    );
    D3D_CALL(constant_table, SetInt, r_d3d9Glob.d3ddev, handle, value);
    return true;
}

static bool R_ShaderSetUniformMat4fByNameD3D9(
    ID3DXConstantTable* constant_table, const char* name,
    const amat4f_t value
) {
    D3DXHANDLE handle = constant_table->lpVtbl->GetConstantByName(
        constant_table, NULL, name
    );
    D3D_CALL(constant_table, SetMatrix, r_d3d9Glob.d3ddev, 
             handle, (D3DXMATRIX*)value.array);
    return true;
}

static bool R_ShaderSetUniformByNameD3D9(ID3DXConstantTable* constant_table,
                                         const char* name,
                                         GfxShaderUniformDef* uniform
) {
    switch (uniform->type) {
    case UNIFORM_TYPE_BOOL:
        return R_ShaderSetUniformBoolByNameD3D9(constant_table,
                                                name, uniform->value.b);
    case UNIFORM_TYPE_FLOAT:
        return R_ShaderSetUniformFloatByNameD3D9(constant_table, name,
                                                 uniform->value.f);
    case UNIFORM_TYPE_FLOAT_ARRAY:
        return R_ShaderSetUniformFloatArrayByNameD3D9(constant_table, name,
                                                      uniform->value.fa,
                                                      uniform->value.fcount);
    case UNIFORM_TYPE_VEC4F:
        return R_ShaderSetUniformVec4fByNameD3D9(constant_table, name,
                                                 uniform->value.v4f);
    case UNIFORM_TYPE_INT:
        return R_ShaderSetUniformIntByNameD3D9(constant_table, name,
                                               uniform->value.i);
    case UNIFORM_TYPE_MAT4F:
        return R_ShaderSetUniformMat4fByNameD3D9(constant_table, name,
                                                 uniform->value.m4f);
    default:
        assert(false && "R_ShaderSetUniformD3D9: Invalid uniform type.");
        Com_Errorln(
            -1,
            "R_ShaderSetUniformD3D9: Invalid uniform type %d.",
            uniform->type
        );
        return false;
    }
}
#endif // A_RENDER_BACKEND_GL

static bool R_ShaderSetUniform(const GfxShaderProgram* prog, int location, 
                               GfxShaderUniformDef* uniform
) {
#if A_RENDER_BACKEND_GL
    R_ShaderSetUniformGL(prog->program, location, uniform);
    return true;
#elif A_RENDER_BACKEND_D3D9
    bool b = R_ShaderSetUniformD3D9(prog->vertex_shader.constant_table,
                                    location, uniform);
    assert(b);
    if (!b)
        return false;
    b = R_ShaderSetUniformD3D9(prog->pixel_shader.constant_table,
                                    location, uniform);
    assert(b);
    return b;
#endif // A_RENDER_BACKEND_GL
}

static bool R_ShaderSetUniformByName(const GfxShaderProgram* prog, 
                                     const char* name,
                                     GfxShaderUniformDef* uniform
) {
#if A_RENDER_BACKEND_GL
    R_ShaderSetUniformByNameGL(prog->program, name, uniform);
    return true;
#elif A_RENDER_BACKEND_D3D9
    bool b = R_ShaderSetUniformByNameD3D9(prog->vertex_shader.constant_table,
                                          name, uniform);
    assert(b);
    if (!b)
        return false;
    b = R_ShaderSetUniformByNameD3D9(prog->pixel_shader.constant_table,
                                     name, uniform);
    assert(b);
    return b;
#endif // A_RENDER_BACKEND_GL
}

GfxShaderUniformDef* R_ShaderAddUniform(A_INOUT GfxShaderProgram* prog,
                                        A_IN GfxShaderUniformDef* uniform
) {
    assert(prog);
    assert(uniform);
    assert(prog->current_uniform < R_SHADER_MAX_UNIFORM);
    if (prog->current_uniform >= R_SHADER_MAX_UNIFORM) {
        Com_Errorln(-1, "R_ShaderAddUniform: program has too many uniforms.");
        return NULL;
    }
    
    A_memcpy(&prog->uniforms[prog->current_uniform], uniform, sizeof(*uniform));
    GfxShaderUniformDef* ret = &prog->uniforms[prog->current_uniform];
#if A_RENDER_BACKEND_GL
    int location = GL_CALL(
        glGetUniformLocation, prog->program, uniform->name
    );
    assert(location >= 0);
    ret->location = location;
    R_ShaderSetUniformByName(
        prog,
        uniform->name,
        ret
    );
#elif A_RENDER_BACKEND_D3D9
    D3DXHANDLE handle = 
        prog->vertex_shader.constant_table->lpVtbl->GetConstantByName(
            prog->vertex_shader.constant_table, NULL,
            prog->uniforms[prog->current_uniform].name
        );
    assert(handle);
    D3DXCONSTANT_DESC desc;
    UINT count = 1;
    D3D_CALL(prog->vertex_shader.constant_table, GetConstantDesc, handle, 
                                                                  &desc, 
                                                                  &count);
    assert(count > 0);
    prog->uniforms[prog->current_uniform].location = desc.RegisterIndex;
    bool b = R_ShaderSetUniformD3D9(
        prog->vertex_shader.constant_table,
        prog->uniforms[prog->current_uniform].location,
        &prog->uniforms[prog->current_uniform]
    );
    assert(b);
#endif // A_RENDER_BACKEND_D3D9
    prog->current_uniform++;
    
    return ret;
}

GfxShaderUniformDef* R_ShaderGetUniform(A_INOUT GfxShaderProgram* prog, int i) 
{
    assert(prog);
    assert(i <= prog->current_uniform);
    if (i > prog->current_uniform) {
        Com_Errorln(-1, "R_ShaderGetUniform: Invalid uniform index %d.", i);
        return NULL;
    }

    return &prog->uniforms[i];
}

GfxShaderUniformDef* R_ShaderGetUniformByName(A_INOUT GfxShaderProgram* prog, 
                                              const char* name
) {
    assert(prog);
    assert(name);

    int hash = R_HashUniformName(name);
    for (int i = 0; i < prog->current_uniform; i++) {
        if (prog->uniforms[i].name_hash == hash)
            return &prog->uniforms[i];
    }
    return NULL;
}

void R_ShaderSetUniformBool(A_INOUT GfxShaderProgram* prog,
                            int i, bool value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if(uniform)
        R_SetUniformBool(uniform, value);
    R_ShaderSetUniform(prog, i, uniform);
}

void R_ShaderSetUniformBoolByName(A_INOUT GfxShaderProgram* prog, 
                                  const char* name, bool value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformBool(uniform, value);
    R_ShaderSetUniformByName(prog, name, uniform);
}

void R_ShaderSetUniformFloat(A_INOUT GfxShaderProgram* prog,
                             int i, float value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformFloat(uniform, value);
    R_ShaderSetUniform(prog, i, uniform);
}

void R_ShaderSetUniformFloatByName(A_INOUT GfxShaderProgram* prog,
                                   const char* name, float value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformFloat(uniform, value);
    R_ShaderSetUniformByName(prog, name, uniform);
}

void R_ShaderSetUniformFloatArray(A_INOUT GfxShaderProgram* prog,
                                  int i, const float* value, int count
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformFloatArray(uniform, value, count);
    R_ShaderSetUniform(prog, i, uniform);
}

void R_ShaderSetUniformFloatArrayByName(A_INOUT GfxShaderProgram* prog,
                                        const char* name, const float* value, int count
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformFloatArray(uniform, value, count);
    R_ShaderSetUniformByName(prog, name, uniform);
}

void R_ShaderSetUniformVec2f(A_INOUT GfxShaderProgram* prog,
                             int i, avec2f_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformVec2f(uniform, value);
    R_ShaderSetUniform(prog, i, uniform);
}

void R_ShaderSetUniformVec2fByName(A_INOUT GfxShaderProgram* prog,
                                   const char* name, avec2f_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformVec2f(uniform, value);
    R_ShaderSetUniformByName(prog, name, uniform);
}

void R_ShaderSetUniformVec3f(A_INOUT GfxShaderProgram* prog,
                             int i, avec3f_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformVec3f(uniform, value);
    R_ShaderSetUniform(prog, i, uniform);
}

void R_ShaderSetUniformVec3fByName(A_INOUT GfxShaderProgram* prog,
                                   const char* name, avec3f_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformVec3f(uniform, value);
    R_ShaderSetUniformByName(prog, name, uniform);
}

void R_ShaderSetUniformVec4f(A_INOUT GfxShaderProgram* prog,
                             int i, avec4f_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformVec4f(uniform, value);
    R_ShaderSetUniform(prog, i, uniform);
}

void R_ShaderSetUniformVec4fByName(A_INOUT GfxShaderProgram* prog,
                                   const char* name, avec4f_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformVec4f(uniform, value);
    R_ShaderSetUniformByName(prog, name, uniform);
}

void R_ShaderSetUniformInt(A_INOUT GfxShaderProgram* prog,
                           int i, int value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformInt(uniform, value);
    R_ShaderSetUniform(prog, i, uniform);
}

void R_ShaderSetUniformIntByName(A_INOUT GfxShaderProgram* prog,
                                 const char* name, int value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformInt(uniform, value);
    R_ShaderSetUniformByName(prog, name, uniform);
}

void R_ShaderSetUniformUint(A_INOUT GfxShaderProgram* prog,
                            int i, unsigned int value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformUint(uniform, value);
    R_ShaderSetUniform(prog, i, uniform);
}

void R_ShaderSetUniformUintByName(A_INOUT GfxShaderProgram* prog,
                                  const char* name, unsigned int value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformUint(uniform, value);
    R_ShaderSetUniformByName(prog, name, uniform);
}

void R_ShaderSetUniformIntArray(A_INOUT GfxShaderProgram* prog,
                                int i, const int* value, int count
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformIntArray(uniform, value, count);
    R_ShaderSetUniform(prog, i, uniform);
}

void R_ShaderSetUniformIntArrayByName(A_INOUT GfxShaderProgram* prog,
                                      const char* name, const int* value, int count
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformIntArray(uniform, value, count);
    R_ShaderSetUniformByName(prog, name, uniform);
}

void R_ShaderSetUniformVec2i(A_INOUT GfxShaderProgram* prog,
                             int i, avec2i_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformVec2i(uniform, value);
    R_ShaderSetUniform(prog, i, uniform);
}

void R_ShaderSetUniformVec2iByName(A_INOUT GfxShaderProgram* prog,
                                   const char* name, avec2i_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformVec2i(uniform, value);
    R_ShaderSetUniformByName(prog, name, uniform);
}

void R_ShaderSetUniformVec3i(A_INOUT GfxShaderProgram* prog,
                             int i, avec3i_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformVec3i(uniform, value);
    R_ShaderSetUniform(prog, i, uniform);
}

void R_ShaderSetUniformVec3iByName(A_INOUT GfxShaderProgram* prog,
                                   const char* name, avec3i_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformVec3i(uniform, value);
    R_ShaderSetUniformByName(prog, name, uniform);
}

void R_ShaderSetUniformVec4i(A_INOUT GfxShaderProgram* prog,
                             int i, avec4i_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformVec4i(uniform, value);
    R_ShaderSetUniform(prog, i, uniform);
}

void R_ShaderSetUniformVec4iByName(A_INOUT GfxShaderProgram* prog,
                                   const char* name, avec4i_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformVec4i(uniform, value);
    R_ShaderSetUniformByName(prog, name, uniform);
}

void R_ShaderSetUniformMat2f(A_INOUT GfxShaderProgram* prog,
                             int i, amat2f_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformMat2f(uniform, value);
    R_ShaderSetUniform(prog, i, uniform);
}

void R_ShaderSetUniformMat2fByName(A_INOUT GfxShaderProgram* prog,
                                   const char* name, amat2f_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformMat2f(uniform, value);
    R_ShaderSetUniformByName(prog, name, uniform);
}

void R_ShaderSetUniformMat3f(A_INOUT GfxShaderProgram* prog,
                             int i, amat3f_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformMat3f(uniform, value);
    R_ShaderSetUniform(prog, i, uniform);
}

void R_ShaderSetUniformMat3fByName(A_INOUT GfxShaderProgram* prog,
                                   const char* name, amat3f_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformMat3f(uniform, value);
    R_ShaderSetUniformByName(prog, name, uniform);
}

void R_ShaderSetUniformMat4f(A_INOUT GfxShaderProgram* prog,
                             int i, amat4f_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformMat4f(uniform, value);
    R_ShaderSetUniform(prog, i, uniform);
}

void R_ShaderSetUniformMat4fByName(A_INOUT GfxShaderProgram* prog,
    const char* name, amat4f_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformMat4f(uniform, value);
    R_ShaderSetUniformByName(prog, name, uniform);
}

bool R_DeleteShaderProgram(
    A_INOUT GfxShaderProgram* prog
) {
#if A_RENDER_BACKEND_GL
    GL_CALL(glDeleteProgram, prog->program);
    prog->program = 0;
#elif A_RENDER_BACKEND_D3D9
    prog->vertex_shader.vs->lpVtbl->Release(prog->vertex_shader.vs);
    prog->pixel_shader.ps->lpVtbl->Release(prog->pixel_shader.ps);
    prog->vertex_shader.vs = NULL;
    prog->pixel_shader.ps  = NULL;
#endif // A_RENDER_BACKEND_GL
    for (int i = 0; i < A_countof(prog->uniforms); i++)
        R_DeleteUniform(&prog->uniforms[i]);
    return true;
}
