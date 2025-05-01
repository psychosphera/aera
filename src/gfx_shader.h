#pragma once

#include "com_defs.h"
#include "gfx_defs.h"

#if A_RENDER_BACKEND_GL
A_EXTERN_C A_NO_DISCARD bool R_CompileShader(
    const char* shaderSource, int type,
    A_OPTIONAL_OUT char** log, A_OUT unsigned int* shader
);
A_EXTERN_C A_NO_DISCARD bool R_LinkShaders(
    vertex_shader_t vertShader, fragment_shader_t fragShader,
    A_OPTIONAL_OUT char** log, A_OUT shader_program_t* program
);
A_EXTERN_C A_NO_DISCARD bool R_CreateShaderProgram(
    const char* vertexSource, const char* fragmentSource,
    A_OPTIONAL_OUT char** log, A_OUT GfxShaderProgram* prog
);
#endif // A_RENDER_BACKEND_GL
A_EXTERN_C bool R_DeleteShaderProgram(A_INOUT GfxShaderProgram* prog);
