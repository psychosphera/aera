#pragma once

#include <string>

#include "com_defs.hpp"
#include "gfx_defs.hpp"

A_NO_DISCARD bool R_CompileShader(
    const std::string& shaderSource, int type,
    A_OPTIONAL_OUT std::string* log, A_OUT unsigned int& shader
);
A_NO_DISCARD bool R_LinkShaders(
    vertex_shader_t vertShader, fragment_shader_t fragShader,
    A_OPTIONAL_OUT std::string* log, A_OUT shader_program_t& program
);
A_NO_DISCARD bool R_CreateShaderProgram(
    const std::string& vertexSource, const std::string& fragmentSource,
    A_OPTIONAL_OUT std::string* log, A_OUT GfxShaderProgram& prog
);