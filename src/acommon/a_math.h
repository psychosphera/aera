#pragma once

#include "acommon.h"

#include <stdbool.h>

#define A_MIN(a, b) ((a) < (b) ? (a) : (b))
#define A_MAX(a, b) ((a) > (b) ? (a) : (b))

#define A_ROUND(from, by) (from + ((~(from - 1)) & (by - 1)))
#define A_CLAMP(a, min, max) ((a) < (min) ? (min) : (a) > (max) ? (max) : (a))

#define A_IS_MULTIPLE_OF(a, m) (((a) / (m)) * (m) == (a))

union apoint2i_t {
    struct { int x, y; };
    int array[2];
    char bytes[8];
};
typedef union apoint2i_t apoint2i_t;
A_STATIC_ASSERT(sizeof(apoint2i_t) == 8);

union apoint2s_t {
    struct { short x, y; };
    struct { short u, v; };
    short array[2];
    char bytes[4];
};
typedef union apoint2s_t apoint2s_t;
A_STATIC_ASSERT(sizeof(apoint2s_t) == 4);

union apoint2f_t {
    struct { float x, y; };
    struct { float u, v; };
    float array[2];
    char bytes[8];
};
typedef union apoint2f_t apoint2f_t;
A_STATIC_ASSERT(sizeof(apoint2f_t) == 8);

#define A_point2(a, b)  { .x = a, .y = b }

union apoint3i_t {
    struct { int x, y, z; };
    int array[3];
    char bytes[12];
};
typedef union apoint3i_t apoint3i_t;
A_STATIC_ASSERT(sizeof(apoint3i_t) == 12);

union apoint3s_t {
    struct { short x, y, z; };
    short array[3];
    char bytes[6];
};
typedef union apoint3s_t apoint3s_t;
A_STATIC_ASSERT(sizeof(apoint3s_t) == 6);

union apoint3f_t {
    struct { float x, y, z; };
    float array[3];
    char bytes[12];
};
typedef union apoint3f_t apoint3f_t;
A_STATIC_ASSERT(sizeof(apoint3f_t) == 12);

#define A_point3(a, b, c)  { .x = a, .y = b, .z = c }

union avec2i_t {
    struct { int x, y; };
    struct { int t, u; };
    int array[2];
    char bytes[8];
};
typedef union avec2i_t avec2i_t;
A_STATIC_ASSERT(sizeof(avec2i_t) == 8);

extern const avec2i_t  A__priv__vec2i_zero;
#define A_VEC2I_ZERO   A__priv__vec2i_zero

union avec2f_t {
    struct { float x, y; };
    struct { float t, u; };
    float array[2];
    char bytes[8];
};
typedef union avec2f_t avec2f_t;
A_STATIC_ASSERT(sizeof(apoint2f_t) == 8);

#define A_vec2(a, b) { .t = a, .u = b }
extern const avec2f_t  A__priv__vec2f_zero;
#define A_VEC2F_ZERO   A__priv__vec2f_zero

union avec3i_t {
    struct { int x, y, z; };
    int array[3];
    char bytes[12];
};
typedef union avec3i_t avec3i_t;
A_STATIC_ASSERT(sizeof(avec3i_t) == 12);

extern const avec3i_t  A__priv__vec3i_zero;
#define A_VEC3I_ZERO   A__priv__vec3i_zero

union avec3f_t {
    struct { float x, y, z; };
    float array[3];
    char bytes[12];
};
typedef union avec3f_t avec3f_t;
A_STATIC_ASSERT(sizeof(avec3f_t) == 12);

#define A_vec3(a, b, c) { .x = a, .y = b, .z = c }
extern const avec3f_t  A__priv__vec3f_zero;
#define A_VEC3F_ZERO   A__priv__vec3f_zero

union avec4i_t {
    struct { int x, y, z, w; };
    int array[4];
    char bytes[16];
};
typedef union avec4i_t avec4i_t;
A_STATIC_ASSERT(sizeof(avec4i_t) == 16);

extern const avec4i_t  A__priv__vec4i_zero;
#define A_VEC4I_ZERO   A__priv__vec4i_zero

union avec4f_t {
    struct { float x, y, z, w; };
    float array[4];
    char bytes[16];
};
typedef union avec4f_t avec4f_t;
A_STATIC_ASSERT(sizeof(avec4f_t) == 16);

#define A_vec4(a, b, c, d) { .x = a, .y = b, .z = c, .w = d }
extern const avec4f_t  A__priv__vec4f_zero;
#define A_VEC4F_ZERO   A__priv__vec4f_zero

union acolor_rgb_t {
    struct { float r, g, b; };
    float array[3];
    char bytes[12];
};
typedef union acolor_rgb_t acolor_rgb_t;
A_STATIC_ASSERT(sizeof(acolor_rgb_t) == 12);

#define A_color_rgb(d, e, f) { .r = d, .g = e, .b = f }

union acolor_rgba_t {
    struct { float r, g, b, a; };
    float array[4];
    char bytes[16];
};
typedef union acolor_rgba_t acolor_rgba_t;
A_STATIC_ASSERT(sizeof(acolor_rgba_t) == 16);

union acolor_argb_t {
    struct { float a, r, g, b; };
    float array[4];
    char bytes[16];
};
typedef union acolor_argb_t acolor_argb_t;
A_STATIC_ASSERT(sizeof(acolor_argb_t) == 16);

union aplane3f_t {
    struct { avec3f_t v; float w; } p;
    float array[4];
    char bytes[16];
};
typedef union aplane3f_t aplane3f_t;
A_STATIC_ASSERT(sizeof(aplane3f_t) == 16);

union amat2f_t {
    float m[2][2];
    float array[4];
    char bytes[16];
};
typedef union amat2f_t amat2f_t;
A_STATIC_ASSERT(sizeof(amat2f_t) == 16);

union amat3f_t {
    float m[3][3];
    float array[9];
    char bytes[36];
};
typedef union amat3f_t amat3f_t;
A_STATIC_ASSERT(sizeof(amat3f_t) == 36);

union amat4f_t {
    float m[4][4];
    float array[16];
    char bytes[64];
};
typedef union amat4f_t amat4f_t;
A_STATIC_ASSERT(sizeof(amat4f_t) == 64);

A_EXTERN_C float      A_sqrtf(float  x);
A_EXTERN_C double     A_sqrt (double x);
A_EXTERN_C float      A_sinf (float  x);
A_EXTERN_C double     A_sin  (double x);
A_EXTERN_C float      A_asinf(float  x);
A_EXTERN_C double     A_asin (double x);
A_EXTERN_C float      A_cosf (float  x);
A_EXTERN_C double     A_cos  (double x);
A_EXTERN_C float      A_acosf(float  x);
A_EXTERN_C double     A_acos (double x);
A_EXTERN_C float      A_tanf (float  x);
A_EXTERN_C double     A_tan  (double x);
A_EXTERN_C float      A_atanf(float  x);
A_EXTERN_C double     A_atan (double x);

A_EXTERN_C float A_radians(float degrees);
A_EXTERN_C float A_degrees(float radians);
                      
A_EXTERN_C float      A_vec2f_length   (avec2f_t v);
A_EXTERN_C float      A_vec3f_length   (avec3f_t v);
A_EXTERN_C float      A_vec4f_length   (avec4f_t v);
A_EXTERN_C avec2f_t   A_vec2f_normalize(avec2f_t v);
A_EXTERN_C avec3f_t   A_vec3f_normalize(avec3f_t v);
A_EXTERN_C avec4f_t   A_vec4f_normalize(avec4f_t v);

A_EXTERN_C apoint3f_t A_point3f_swap_yz(apoint3f_t p);

A_EXTERN_C bool       A_vec3f_eq(avec3f_t a, avec3f_t b);

A_EXTERN_C avec3f_t   A_vec3f_add  (avec3f_t a, avec3f_t b);
A_EXTERN_C avec3f_t   A_vec3f_sub  (avec3f_t a, avec3f_t b);
A_EXTERN_C float      A_vec3f_dot  (avec3f_t a, avec3f_t b);
A_EXTERN_C avec3f_t   A_vec3f_cross(avec3f_t a, avec3f_t b);
A_EXTERN_C avec3f_t   A_vec3f_mul  (avec3f_t a, float b);