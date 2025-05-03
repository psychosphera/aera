#include "gfx_shader.h"

#include <assert.h>

#include "acommon/a_math.h"
#include "acommon/a_string.h"
#include "acommon/z_mem.h"

#include "com_print.h"
#include "gfx_uniform.h"

#if A_RENDER_BACKEND_GL
A_NO_DISCARD bool R_CompileShader(
    const char* shaderSource, int type,
    A_OPTIONAL_OUT char** log, A_OUT unsigned int* shader
) {
    *shader = GL_CALL(glCreateShader, type);

    GL_CALL(glShaderSource, *shader, 1, &shaderSource, NULL);
    GL_CALL(glCompileShader, *shader);

    int success = GL_FALSE;
    GL_CALL(glGetShaderiv, *shader, GL_COMPILE_STATUS, &success);
    if (!success && log) {
        GLint len = 0;
        GL_CALL(glGetShaderiv, *shader, GL_INFO_LOG_LENGTH, &len);
        *log = Z_Alloc(len);
        GL_CALL(glGetShaderInfoLog, *shader, len, &len, *log);
    } else if (log) {
        *log = NULL;
    }

    return success == GL_TRUE;
}
#endif // A_RENDER_BACKEND_GL

#if A_RENDER_BACKEND_GL
A_NO_DISCARD bool R_LinkShaders(
    vertex_shader_t vertShader, fragment_shader_t fragShader,
    A_OPTIONAL_OUT char** log, A_OUT shader_program_t* program
) {
    *program = GL_CALL(glCreateProgram);
    GL_CALL(glAttachShader, *program, vertShader);
    GL_CALL(glAttachShader, *program, fragShader);
    GL_CALL(glLinkProgram,  *program);

    int success = GL_FALSE;
    GL_CALL(glGetProgramiv, *program, GL_LINK_STATUS, &success);
    if (!success && log) {
        GLint len = 0;
        GL_CALL(glGetProgramiv, *program, GL_INFO_LOG_LENGTH, &len);
        *log = Z_Alloc(len);
        GL_CALL(glGetProgramInfoLog, *program, len, NULL, *log);
    } else if (log) {
        *log = NULL;
    }

    GL_CALL(glDeleteShader, vertShader);
    GL_CALL(glDeleteShader, fragShader);

    return success == GL_TRUE;
}
#endif // A_RENDER_BACKEND_GL

#if A_RENDER_BACKEND_GL
A_NO_DISCARD bool R_CreateShaderProgram(
    const char* vertexSource, const char* fragmentSource,
    A_OPTIONAL_OUT char** log, A_OUT GfxShaderProgram* prog
) {
    A_memset(prog, 0, sizeof(*prog));

    vertex_shader_t v = 0;
    if (!R_CompileShader(vertexSource, GL_VERTEX_SHADER, log, &v))
        return false;

    fragment_shader_t f = 0;
    if (!R_CompileShader(fragmentSource, GL_FRAGMENT_SHADER, log, &f))
        return false;

    shader_program_t p = 0;
    if (!R_LinkShaders(v, f, log, &p))
        return false;

    prog->vertex_shader   = v;
    prog->fragment_shader = f;
    prog->program         = p;
    return true;
}
#endif // A_RENDER_BACKEND_GL

static int R_UniformDataSize(const GfxShaderUniformDef* uniform) {
    switch (uniform->type) {
    case UNIFORM_TYPE_INT:
    case UNIFORM_TYPE_UINT:
    case UNIFORM_TYPE_FLOAT:
    case UNIFORM_TYPE_BOOL:
    case UNIFORM_TYPE_VEC2F:
    case UNIFORM_TYPE_VEC2I:
    case UNIFORM_TYPE_VEC3F:
    case UNIFORM_TYPE_VEC3I:
    case UNIFORM_TYPE_VEC4F:
    case UNIFORM_TYPE_VEC4I:
        return 1;
    case UNIFORM_TYPE_MAT2F:
        return 2;
    case UNIFORM_TYPE_MAT3F:
        return 3;
    case UNIFORM_TYPE_MAT4F:   
        return 4;
    // TODO: integer ceil
    case UNIFORM_TYPE_FLOAT_ARRAY:
        return A_ceili(uniform->value.fcount, 4);
    case UNIFORM_TYPE_INT_ARRAY:
        return A_ceili(uniform->value.icount, 4);
    case UNIFORM_TYPE_UINT_ARRAY:
        return A_ceili(uniform->value.ucount, 4);
    default:
        assert(false && "R_UniformDataSize: Invalid uniform type.");
        Com_Errorln(
            -1,
            "R_UniformDataSize: Invalid uniform type %d.",
            uniform->type
        );
    }
}

#if A_RENDER_BACKEND_GL
void R_SetUniformIntGL(shader_program_t program, int location, int value);
void R_SetUniformBoolGL(shader_program_t program, int locaction, bool value) {
    R_SetUniformIntGL(program, locaction, (int)value);
}

void R_SetUniformFloatGL(
    shader_program_t program, int location, float value
) {
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniform1f, location, value);
}

void R_SetUniformFloatArrayGL(
    shader_program_t program, int location,
    const float* value, int count
) {
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniform1fv, location, count, value);
}

void R_SetUniformVec2fGL(
    shader_program_t program, int location, avec2f_t value
) {
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniform2f, location, value.x, value.y);
}

void R_SetUniformVec3fGL(
    shader_program_t program, int location, avec3f_t value
) {
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniform3f, location, value.x, value.y, value.z);
}

void R_SetUniformVec4fGL(
    shader_program_t program, int location, avec4f_t value
) {
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniform4f, location, value.x, value.y, value.z, value.w);
}

void R_SetUniformIntGL(
    shader_program_t program, int location, int value
) {
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniform1i, location, value);
}

void R_SetUniformIntArrayGL(
    shader_program_t program, int location,
    const int* value, int count
) {
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniform1iv, location, count, value);
}

void R_SetUniformVec2iGL(
    shader_program_t program, int location, avec2i_t value
) {
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniform2i, location, value.x, value.y);
}

void R_SetUniformVec3iGL(
    shader_program_t program, int location, avec3i_t value
) {
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniform3i, location, value.x, value.y, value.z);
}

void R_SetUniformVec4iGL(
    shader_program_t program, int location, avec4i_t value
) {
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniform4i, location, value.x, value.y, value.z, value.w);
}

void R_SetUniformUintGL(
    shader_program_t program, int location, unsigned int value
) {
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniform1ui, location, value);
}

void R_SetUniformUintArrayGL(
    shader_program_t program, int location,
    const unsigned int* value, int count
) {
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniform1uiv, location, count, value);
}

void R_SetUniformMat2fGL(
    shader_program_t program, int location, const amat2f_t value
) {
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniformMatrix2fv, location, 1, GL_FALSE, value.array);
}

void R_SetUniformMat3fGL(
    shader_program_t program, int location, amat3f_t value
) {
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniformMatrix3fv, location, 1, GL_FALSE, value.array);
}

void R_SetUniformMat4fGL(
    shader_program_t program, int location, amat4f_t value
) {
    GL_CALL(glUseProgram, program);
    GL_CALL(glUniformMatrix4fv, location, 1, GL_FALSE, value.array);
}

void R_SetUniformGL(shader_program_t program, int location, GfxShaderUniformDef* uniform) {
    switch (uniform->type) {
    case UNIFORM_TYPE_BOOL:
        R_SetUniformBoolGL(program, location, uniform->value.b);
        break;
    case UNIFORM_TYPE_FLOAT:
        R_SetUniformFloatGL(program, location, uniform->value.f);
        break;
    case UNIFORM_TYPE_FLOAT_ARRAY:
        R_SetUniformFloatArrayGL(program, location, uniform->value.fa, uniform->value.fcount);
        break;
    case UNIFORM_TYPE_VEC2F:
        R_SetUniformVec2fGL(program, location, uniform->value.v2f);
        break;
    case UNIFORM_TYPE_VEC3F:
        R_SetUniformVec3fGL(program, location, uniform->value.v3f);
        break;
    case UNIFORM_TYPE_VEC4F:
        R_SetUniformVec4fGL(program, location, uniform->value.v4f);
        break;
    case UNIFORM_TYPE_INT:
        R_SetUniformIntGL(program, location, uniform->value.i);
        break;
    case UNIFORM_TYPE_INT_ARRAY:
        R_SetUniformIntArrayGL(program, location, uniform->value.ia, uniform->value.icount);
        break;
    case UNIFORM_TYPE_VEC2I:
        R_SetUniformVec2iGL(program, location, uniform->value.v2i);
        break;
    case UNIFORM_TYPE_VEC3I:
        R_SetUniformVec3iGL(program, location, uniform->value.v3i);
        break;
    case UNIFORM_TYPE_VEC4I:
        R_SetUniformVec4iGL(program, location, uniform->value.v4i);
        break;
    case UNIFORM_TYPE_UINT:
        R_SetUniformUintGL(program, location, uniform->value.u);
        break;
    case UNIFORM_TYPE_UINT_ARRAY:
        R_SetUniformUintArrayGL(program, location, uniform->value.ua, uniform->value.ucount);
        break;
    case UNIFORM_TYPE_MAT2F:
        R_SetUniformMat2fGL(program, location, uniform->value.m2f);
        break;
    case UNIFORM_TYPE_MAT3F:
        R_SetUniformMat3fGL(program, location, uniform->value.m3f);
        break;
    case UNIFORM_TYPE_MAT4F:
        R_SetUniformMat4fGL(program, location, uniform->value.m4f);
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
#endif // A_RENDER_BACKEND_GL



int R_ShaderAddUniform(A_INOUT GfxShaderProgram* prog, 
                       A_IN GfxShaderUniformDef* uniform
) {
    assert(prog);
    assert(uniform);
    assert(prog->current_uniform < R_SHADER_MAX_UNIFORM);
    if (prog->current_uniform >= R_SHADER_MAX_UNIFORM) {
        Com_Errorln(-1, "R_ShaderAddUniform: program has too many uniforms.");
        return -1;
    }
    
    A_memcpy(&prog->uniforms[prog->current_uniform], uniform, sizeof(*uniform));
#if A_RENDER_BACKEND_D3D9
    prog->uniforms[prog->current_uniform].location = prog->current_location;
    int ret = prog->current_uniform;
    prog->current_location += R_UniformDataSize(uniform);
#elif A_RENDER_BACKEND_GL
    int ret = prog->current_uniform;
    prog->uniforms[prog->current_uniform].location = GL_CALL(
        glGetUniformLocation, prog->program, uniform->name
    );
    R_SetUniformGL(
        prog->program,
        prog->uniforms[prog->current_uniform].location,
        &prog->uniforms[prog->current_uniform]
    );
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
}

void R_ShaderSetUniformBoolByName(A_INOUT GfxShaderProgram* prog, 
                                  const char* name, bool value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformBool(uniform, value);
}

void R_ShaderSetUniformFloat(A_INOUT GfxShaderProgram* prog,
                             int i, float value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformFloat(uniform, value);
}

void R_ShaderSetUniformFloatByName(A_INOUT GfxShaderProgram* prog,
                                   const char* name, float value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformFloat(uniform, value);
}

void R_ShaderSetUniformFloatArray(A_INOUT GfxShaderProgram* prog,
                                  int i, const float* value, int count
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformFloatArray(uniform, value, count);
}

void R_ShaderSetUniformFloatArrayByName(A_INOUT GfxShaderProgram* prog,
                                        const char* name, const float* value, int count
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformFloatArray(uniform, value, count);
}

void R_ShaderSetUniformVec2f(A_INOUT GfxShaderProgram* prog,
                             int i, avec2f_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformVec2f(uniform, value);
}

void R_ShaderSetUniformVec2fByName(A_INOUT GfxShaderProgram* prog,
                                   const char* name, avec2f_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformVec2f(uniform, value);
}

void R_ShaderSetUniformVec3f(A_INOUT GfxShaderProgram* prog,
                             int i, avec3f_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformVec3f(uniform, value);
}

void R_ShaderSetUniformVec3fByName(A_INOUT GfxShaderProgram* prog,
                                   const char* name, avec3f_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformVec3f(uniform, value);
}

void R_ShaderSetUniformVec4f(A_INOUT GfxShaderProgram* prog,
                             int i, avec4f_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformVec4f(uniform, value);
}

void R_ShaderSetUniformVec4fByName(A_INOUT GfxShaderProgram* prog,
                                   const char* name, avec4f_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformVec4f(uniform, value);
}

void R_ShaderSetUniformInt(A_INOUT GfxShaderProgram* prog,
                           int i, int value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformInt(uniform, value);
}

void R_ShaderSetUniformIntByName(A_INOUT GfxShaderProgram* prog,
                                 const char* name, int value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformInt(uniform, value);
}

void R_ShaderSetUniformUint(A_INOUT GfxShaderProgram* prog,
                            int i, unsigned int value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformUint(uniform, value);
}

void R_ShaderSetUniformUintByName(A_INOUT GfxShaderProgram* prog,
                                  const char* name, unsigned int value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformUint(uniform, value);
}

void R_ShaderSetUniformIntArray(A_INOUT GfxShaderProgram* prog,
                                int i, const int* value, int count
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformIntArray(uniform, value, count);
}

void R_ShaderSetUniformIntArrayByName(A_INOUT GfxShaderProgram* prog,
                                      const char* name, const int* value, int count
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformIntArray(uniform, value, count);
}

void R_ShaderSetUniformVec2i(A_INOUT GfxShaderProgram* prog,
                             int i, avec2i_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformVec2i(uniform, value);
}

void R_ShaderSetUniformVec2iByName(A_INOUT GfxShaderProgram* prog,
                                   const char* name, avec2i_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformVec2i(uniform, value);
}

void R_ShaderSetUniformVec3i(A_INOUT GfxShaderProgram* prog,
                             int i, avec3i_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformVec3i(uniform, value);
}

void R_ShaderSetUniformVec3iByName(A_INOUT GfxShaderProgram* prog,
                                   const char* name, avec3i_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformVec3i(uniform, value);
}

void R_ShaderSetUniformVec4i(A_INOUT GfxShaderProgram* prog,
                             int i, avec4i_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformVec4i(uniform, value);
}

void R_ShaderSetUniformVec4iByName(A_INOUT GfxShaderProgram* prog,
                                   const char* name, avec4i_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformVec4i(uniform, value);
}

void R_ShaderSetUniformMat2f(A_INOUT GfxShaderProgram* prog,
                             int i, amat2f_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformMat2f(uniform, value);
}

void R_ShaderSetUniformMat2fByName(A_INOUT GfxShaderProgram* prog,
                                   const char* name, amat2f_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformMat2f(uniform, value);
}

void R_ShaderSetUniformMat3f(A_INOUT GfxShaderProgram* prog,
                             int i, amat3f_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformMat3f(uniform, value);
}

void R_ShaderSetUniformMat3fByName(A_INOUT GfxShaderProgram* prog,
                                   const char* name, amat3f_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformMat3f(uniform, value);
}

void R_ShaderSetUniformMat4f(A_INOUT GfxShaderProgram* prog,
                             int i, amat4f_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniform(prog, i);
    assert(uniform);
    if (uniform)
        R_SetUniformMat4f(uniform, value);
}

void R_ShaderSetUniformMat4fByName(A_INOUT GfxShaderProgram* prog,
    const char* name, amat4f_t value
) {
    assert(prog);
    GfxShaderUniformDef* uniform = R_ShaderGetUniformByName(prog, name);
    assert(uniform);
    if (uniform)
        R_SetUniformMat4f(uniform, value);
}

bool R_DeleteShaderProgram(
    A_INOUT GfxShaderProgram* prog
) {
#if A_RENDER_BACKEND_GL
    GL_CALL(glDeleteProgram, prog->program);
    prog->vertex_shader   = 0;
    prog->fragment_shader = 0;
    prog->program         = 0;
#elif A_RENDER_BACKEND_D3D9
    prog->vertex_shader->lpVtbl->Release(prog->vertex_shader);
    prog->pixel_shader->lpVtbl->Release(prog->pixel_shader);
    prog->vertex_shader = NULL;
    prog->pixel_shader  = NULL;
#else
    (void)prog;
#endif // A_RENDER_BACKEND_GL
    for (int i = 0; i < A_countof(prog->uniforms); i++)
        R_DeleteUniform(&prog->uniforms[i]);
    return true;
}
