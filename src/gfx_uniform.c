#include "gfx_uniform.h"

void R_SetUniformBool(shader_program_t program, const char* name, bool value) {
    R_SetUniformInt(program, name, (int)value);
}

void R_SetUniformFloat(
    shader_program_t program, const char* name, float value
) {
    int location = glGetUniformLocation(program, name);
    glUniform1f(location, value);
}

void R_SetUniformFloatArray(
    shader_program_t program, const char* name,
    const float* value, int count
) {
    int location = glGetUniformLocation(program, name);
    glUniform1fv(location, count, value);
}

void R_SetUniformVec2f(
    shader_program_t program, const char* name, avec2f_t value
) {
    int location = glGetUniformLocation(program, name);
    glUniform2f(location, value.x, value.y);
}

void R_SetUniformVec3f(
    shader_program_t program, const char* name, avec3f_t value
) {
    int location = glGetUniformLocation(program, name);
    glUniform3f(location, value.x, value.y, value.z);
}

void R_SetUniformVec4f(
    shader_program_t program, const char* name, avec4f_t value
) {
    int location = glGetUniformLocation(program, name);
    glUniform4f(location, value.x, value.y, value.z, value.w);
}

void R_SetUniformInt(
    shader_program_t program, const char* name, int value
) {
    int location = glGetUniformLocation(program, name);
    glUniform1i(location, value);
}

void R_SetUniformIntArray(
    shader_program_t program, const char* name,
    const int* value, int count
) {
    int location = glGetUniformLocation(program, name);
    glUniform1iv(location, count, value);
}

void R_SetUniformVec2i(
    shader_program_t program, const char* name, avec2i_t value
) {
    int location = glGetUniformLocation(program, name);
    glUniform2i(location, value.x, value.y);
}

void R_SetUniformVec3i(
    shader_program_t program, const char* name, avec3i_t value
) {
    int location = glGetUniformLocation(program, name);
    glUniform3i(location, value.x, value.y, value.z);
}

void R_SetUniformVec4i(
    shader_program_t program, const char* name, avec4i_t value
) {
    int location = glGetUniformLocation(program, name);
    glUniform4i(location, value.x, value.y, value.z, value.w);
}

void R_SetUniformUint(
    shader_program_t program, const char* name, unsigned int value
) {
    int location = glGetUniformLocation(program, name);
    glUniform1ui(location, value);
}

void R_SetUniformUintArray(
    shader_program_t program, const char* name,
    const unsigned int* value, int count
) {
    int location = glGetUniformLocation(program, name);
    glUniform1uiv(location, count, value);
}

void R_SetUniformMat2f(
    shader_program_t program, const char* name, const amat2f_t value
) {
    int location = glGetUniformLocation(program, name);
    glUniformMatrix2fv(location, 1, GL_TRUE, value.array);
}

void R_SetUniformMat3f(
    shader_program_t program, const char* name, amat3f_t value
) {
    int location = glGetUniformLocation(program, name);
    glUniformMatrix3fv(location, 1, GL_TRUE, value.array);
}

void R_SetUniformMat4f(
    shader_program_t program, const char* name, amat4f_t value
) {
    int location = glGetUniformLocation(program, name);
    glUniformMatrix4fv(location, 1, GL_TRUE, value.array);
}