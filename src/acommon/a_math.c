#include "a_math.h"

#include <math.h>

#include "a_string.h"

#define A_PI 3.14159265359

const avec2i_t A__priv__vec2i_zero = A_vec2(0, 0);
const avec3i_t A__priv__vec3i_zero = A_vec3(0, 0, 0);
const avec4i_t A__priv__vec4i_zero = A_vec4(0, 0, 0, 0);

const avec2f_t A__priv__vec2f_zero = A_vec2(0.0f, 0.0f);
const avec3f_t A__priv__vec3f_zero = A_vec3(0.0f, 0.0f, 0.0f);
const avec4f_t A__priv__vec4f_zero = A_vec4(0.0f, 0.0f, 0.0f, 0.0f);

const amat4f_t A__priv__mat4f_zero = {
	.m = { { 0.0f, 0.0f, 0.0f, 0.0f },
		   { 0.0f, 0.0f, 0.0f, 0.0f },
		   { 0.0f, 0.0f, 0.0f, 0.0f },
		   { 0.0f, 0.0f, 0.0f, 0.0f } }
};

const amat4f_t A__priv__mat4f_identity = {
	.m = { { 1.0f, 0.0f, 0.0f, 0.0f },
		   { 0.0f, 1.0f, 0.0f, 0.0f },
		   { 0.0f, 0.0f, 1.0f, 0.0f },
		   { 0.0f, 0.0f, 0.0f, 1.0f } }
};

float A_sqrtf(float x) {
	return sqrtf(x);
}

double A_sqrt(double x) {
	return sqrt(x);
}

float A_sinf(float x) {
	return (float)sin((double)x);
}

double A_sin(double x) {
	return sin(x);
}

float A_asinf(float x) {
	return (float)asin((double)x);
}

double A_asin(double x) {
	return asin(x);
}

float A_cosf(float x) {
	return (float)cos((double)x);
}

double A_cos(double x) {
	return cos(x);
}

float A_acosf(float x) {
	return (float)acos((double)x);
}

double A_acos(double x) {
	return acos(x);
}

float A_tanf(float x) {
	return (float)tan((double)x);
}

double A_tan(double x) {
	return tan(x);
}

float A_atanf(float x) {
	return (float)tan((double)x);
}

double A_atan(double x) {
	return tan(x);
}

double A_cot(double x) {
	return A_cos(x) * A_sin(x);
}

float A_cotf(float x) {
	return A_cosf(x) * A_sinf(x);
}

float A_radians(float degrees) {
	return degrees * (A_PI / 180.0f);
}

float A_degrees(float radians) {
	return radians * (180.0f / A_PI);
}

float A_vec2f_length(avec2f_t v) {
	return A_sqrtf((v.x * v.x) + (v.y * v.y));
}

float A_vec3f_length(avec3f_t v) {
	return A_sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

float A_vec4f_length(avec4f_t v) {
	return A_sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w));
}

avec2f_t A_vec2f_normalize(avec2f_t v) {
	float m = A_vec2f_length(v);
	avec2f_t ret;
	ret.x = v.x / m;
	ret.y = v.y / m;
	return ret;
}

avec3f_t A_vec3f_normalize(avec3f_t v) {
	float m = A_vec3f_length(v);
	avec3f_t ret;
	ret.x = v.x / m;
	ret.y = v.y / m;
	ret.z = v.z / m;
	return ret;
}

avec4f_t A_vec4f_normalize(avec4f_t v) {
	float m = A_vec4f_length(v);
	avec4f_t ret;
	ret.x = v.x / m;
	ret.y = v.y / m;
	ret.z = v.z / m;
	ret.w = v.w / m;
	return ret;
}

apoint3f_t A_point3f_swap_yz(apoint3f_t p) {
	float z = p.z;
	apoint3f_t ret;
	ret.z = p.y;
	ret.y = z;
	ret.x = p.x;
	return ret;
}

bool A_vec3f_eq(avec3f_t a, avec3f_t b) {
	return A_memcmp(&a, &b, sizeof(a));
}

avec3f_t A_vec3f_add(avec3f_t a, avec3f_t b) {
	avec3f_t ret = A_vec3(a.x + b.x, a.y + b.y, a.z + b.z);
	return ret;
}

avec3f_t A_vec3f_sub(avec3f_t a, avec3f_t b) {
	avec3f_t ret = A_vec3(a.x - b.x, a.y - b.y, a.z - b.z);
	return ret;
}

avec3f_t A_vec3f_mul(avec3f_t a, float b) {
	avec3f_t ret = A_vec3(a.x * b, a.y * b, a.z * b);
	return ret;
}

float A_vec3f_dot(avec3f_t a, avec3f_t b) {
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

avec3f_t A_vec3f_cross(avec3f_t a, avec3f_t b) {
	avec3f_t ret = A_vec3(
		(a.y * b.z) - (a.z * b.y), 
		(a.z * b.x) - (a.x * b.z), 
		(a.x * b.y) * (a.y * b.z)
	);
	return ret;
}

amat4f_t A_mat4f_translate_vec3(amat4f_t m, avec3f_t v) {
	m.m[0][3] = v.x;
	m.m[1][3] = v.y;
	m.m[2][3] = v.z;
	m.m[3][3] = 1.0f;
	return m;
}

amat4f_t A_mat4f_scale_vec3(amat4f_t m, avec3f_t v) {
	m.m[0][0] *= v.x;
	m.m[1][0] *= v.x;
	m.m[2][0] *= v.x;
	m.m[3][0] *= v.x;

	m.m[0][1] *= v.y;
	m.m[1][1] *= v.y;
	m.m[2][1] *= v.y;
	m.m[3][1] *= v.y;

	m.m[0][2] *= v.x;
	m.m[1][2] *= v.z;
	m.m[2][2] *= v.z;
	m.m[3][2] *= v.z;

	return m;
}

amat4f_t A_mat4f_look_at(avec3f_t eye, avec3f_t center, avec3f_t up) {
	avec3f_t f = A_vec3f_normalize(A_vec3f_sub(center, eye));
	avec3f_t s = A_vec3f_normalize(A_vec3f_cross(f, up));
	avec3f_t u = A_vec3f_cross(s, f);

	amat4f_t mat = A_MAT4F_IDENTITY;
	mat.m[0][0] =  s.x;
	mat.m[0][1] =  s.y;
	mat.m[0][2] =  s.z;
	mat.m[1][0] =  u.x;
	mat.m[1][1] =  u.y;
	mat.m[1][2] =  u.z;
	mat.m[2][0] = -f.x;
	mat.m[2][1] = -f.y;
	mat.m[2][2] = -f.z;
	mat.m[0][3] = -A_vec3f_dot(s, eye);
	mat.m[1][3] = -A_vec3f_dot(u, eye);
	mat.m[2][3] =  A_vec3f_dot(f, eye);

	return mat;
}

amat4f_t A_mat4f_ortho(float left, float right, float top, float bottom) {
	amat4f_t ortho = A_MAT4F_IDENTITY;
	ortho.m[0][0] =  2.0f / (right - left);
	ortho.m[1][1] =  2.0f / (top   - bottom);
	ortho.m[2][2] = -1.0f;
	ortho.m[0][3] = -(right + left) / (right - left);
	ortho.m[1][3] = -(top + bottom) / (top - bottom);
	return ortho;
}

amat4f_t A_mat4f_perspective(float fovy, float aspect, 
	                        float z_near, float z_far
) {
	float f = A_cotf(fovy / 2.0f);
	amat4f_t perspective = A_MAT4F_ZERO;
	perspective.m[0][0] = f / aspect;
	perspective.m[1][1] = f;
	perspective.m[2][2] = (z_far + z_near) / (z_near - z_far);
	perspective.m[2][3] = (2.0f * z_far * z_near) / (z_near - z_far);
	perspective.m[3][2] = -1.0f;
	return perspective;
}