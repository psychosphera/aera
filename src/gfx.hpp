#pragma once

#include <filesystem>
#include <memory>
#include <string_view>

#include "com_defs.hpp"
#include "gfx_defs.hpp"

void R_Init();
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
bool R_DeleteShaderProgram(
	A_IN GfxShaderProgram& prog
);

void R_Frame();
void R_WindowResized();

A_NO_DISCARD bool R_CreateImage(
	std::string_view image_name, A_OPTIONAL_OUT int* width, 
	A_OPTIONAL_OUT int* height, A_OUT texture_t& tex
);
bool R_DeleteImage(
	A_IN texture_t& tex
);

void R_LoadMap();
void R_UnloadMap();

void R_Shutdown();