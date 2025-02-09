#include "a_math.h"

#include <math.h>

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

void A_vec2f_normalize(A_INOUT avec2f_t* v) {
	float m = A_sqrtf((v->x * v->x) + (v->y * v->y) );
	v->x /= m;
	v->y /= m;
}

void A_vec3f_normalize(A_INOUT avec3f_t* v) {
	float m = A_sqrtf((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
	v->x /= m;
	v->y /= m;
	v->z /= m;
}

void A_vec4f_normalize(A_INOUT avec4f_t* v) {
	float m = A_sqrtf((v->x * v->x) + (v->y * v->y) + 
		              (v->z * v->z) + (v->w * v->w));
	v->x /= m;
	v->y /= m;
	v->z /= m;
	v->w /= m;
}