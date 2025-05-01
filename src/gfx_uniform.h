#include "gfx_defs.h"

#if A_RENDER_BACKEND_GL
A_EXTERN_C void R_SetUniformBool(
    shader_program_t program, const char* name, bool value);
A_EXTERN_C void R_SetUniformFloat(
    shader_program_t program, const char* name, float value);
A_EXTERN_C void R_SetUniformFloatArray(
    shader_program_t program, const char* name, const float* value, int count);
A_EXTERN_C void R_SetUniformVec2f(
    shader_program_t program, const char* name, avec2f_t value);
A_EXTERN_C void R_SetUniformVec3f(
    shader_program_t program, const char* name, avec3f_t value);
A_EXTERN_C void R_SetUniformVec4f(
    shader_program_t program, const char* name, avec4f_t value);
A_EXTERN_C void R_SetUniformInt(
    shader_program_t program, const char* name, int value);
A_EXTERN_C void R_SetUniformIntArray(
    shader_program_t program, const char* name, const int* value, int count);
A_EXTERN_C void R_SetUniformVec2i(
    shader_program_t program, const char* name, avec2i_t value);
A_EXTERN_C void R_SetUniformVec3i(
    shader_program_t program, const char* name, avec3i_t value);
A_EXTERN_C void R_SetUniformVec4i(
    shader_program_t program, const char* name, avec4i_t value);
A_EXTERN_C void R_SetUniformUint(
    shader_program_t program, const char* name, unsigned int value);
A_EXTERN_C void R_SetUniformUintArray(
    shader_program_t program, const char* name,
    const unsigned int* value, int count);
A_EXTERN_C void R_SetUniformMat2f(
    shader_program_t program, const char* name, const amat2f_t value);
A_EXTERN_C void R_SetUniformMat3f(
    shader_program_t program, const char* name, amat3f_t value);
A_EXTERN_C void R_SetUniformMat4f(
    shader_program_t program, const char* name, amat4f_t value);
#endif // A_RENDER_BACKEND_GL