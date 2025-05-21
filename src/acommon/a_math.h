#pragma once

#include "acommon.h"

#define A_MIN(a, b) ((a) < (b) ? (a) : (b))
#define A_MAX(a, b) ((a) > (b) ? (a) : (b))

#define A_ROUND(from, by) (from + ((~(from - 1)) & (by - 1)))
#define A_CLAMP(a, min, max) ((a) < (min) ? (min) : (a) > (max) ? (max) : (a))

#define A_IS_MULTIPLE_OF(a, m) (((a) / (m)) * (m) == (a))

typedef union apoint2i_t {
    struct { int x, y; };
    int array[2];
    char bytes[8];
} apoint2i_t;
A_STATIC_ASSERT(sizeof(apoint2i_t) == 8);

typedef union apoint2s_t {
    struct { short x, y; };
    struct { short u, v; };
    short array[2];
    char bytes[4];
} apoint2s_t;
A_STATIC_ASSERT(sizeof(apoint2s_t) == 4);

typedef union apoint2f_t {
    struct { float x, y; };
    struct { float u, v; };
    float array[2];
    char bytes[8];
} apoint2f_t;
A_STATIC_ASSERT(sizeof(apoint2f_t) == 8);

#define A_point2(a, b)  { .x = a, .y = b }

typedef union apoint3i_t {
    struct { int x, y, z; };
    int array[3];
    char bytes[12];
} apoint3i_t;
A_STATIC_ASSERT(sizeof(apoint3i_t) == 12);

typedef union apoint3s_t {
    struct { short x, y, z; };
    short array[3];
    char bytes[6];
} apoint3s_t;
A_STATIC_ASSERT(sizeof(apoint3s_t) == 6);

typedef union apoint3f_t {
    struct { float x, y, z; };
    float array[3];
    char bytes[12];
} apoint3f_t;
A_STATIC_ASSERT(sizeof(apoint3f_t) == 12);

#define A_point3(a, b, c)  { .x = a, .y = b, .z = c }

typedef union avec2i_t {
    struct { int x, y; };
    struct { int t, u; };
    int array[2];
    char bytes[8];
} avec2i_t;
A_STATIC_ASSERT(sizeof(avec2i_t) == 8);

A_EXTERN_C const avec2i_t  A__priv__vec2i_zero;
#define A_VEC2I_ZERO       A__priv__vec2i_zero

typedef union avec2f_t {
    struct { float x, y; };
    struct { float t, u; };
    float array[2];
    char bytes[8];
} avec2f_t;
A_STATIC_ASSERT(sizeof(apoint2f_t) == 8);

#define A_vec2(a, b) { a, b }
A_EXTERN_C const avec2f_t  A__priv__vec2f_zero;
#define A_VEC2F_ZERO       A__priv__vec2f_zero

typedef union avec3i_t {
    struct { int x, y, z; };
    int array[3];
    char bytes[12];
} avec3i_t;
A_STATIC_ASSERT(sizeof(avec3i_t) == 12);

A_EXTERN_C const avec3i_t  A__priv__vec3i_zero;
#define A_VEC3I_ZERO       A__priv__vec3i_zero

typedef union avec3f_t {
    struct { float x, y, z; };
    float array[3];
    char bytes[12];
} avec3f_t;
A_STATIC_ASSERT(sizeof(avec3f_t) == 12);

#define A_vec3(a, b, c) { a, b, c }
A_EXTERN_C const avec3f_t  A__priv__vec3f_zero;
#define A_VEC3F_ZERO       A__priv__vec3f_zero

typedef union avec4i_t {
    struct { int x, y, z, w; };
    int array[4];
    char bytes[16];
} avec4i_t;
A_STATIC_ASSERT(sizeof(avec4i_t) == 16);

A_EXTERN_C const avec4i_t  A__priv__vec4i_zero;
#define A_VEC4I_ZERO   A__priv__vec4i_zero

typedef union avec4f_t {
    struct { float x, y, z, w; };
    float array[4];
    char bytes[16];
} avec4f_t;
A_STATIC_ASSERT(sizeof(avec4f_t) == 16);

#define A_vec4(a, b, c, d) { a, b, c, d }
A_EXTERN_C const avec4f_t  A__priv__vec4f_zero;
#define A_VEC4F_ZERO       A__priv__vec4f_zero

typedef union acolor_rgb_t {
    struct { float r, g, b; };
    float array[3];
    char  bytes[12];
} acolor_rgb_t;
A_STATIC_ASSERT(sizeof(acolor_rgb_t) == 12);

#define A_color_rgb(d, e, f) { /*.r =*/ d, /*.g =*/ e, /*.b =*/ f }

typedef union acolor_rgba_t {
    struct { float r, g, b, a; };
    float array[4];
    char  bytes[16];
} acolor_rgba_t;
A_STATIC_ASSERT(sizeof(acolor_rgba_t) == 16);

#define A_color_rgba(d, e, f, g) { /*.r =*/ d, /*.g =*/ e, /*.b =*/ f, /*.a =*/ g }

typedef union acolor_argb_t {
    struct { float a, r, g, b; };
    float array[4];
    char  bytes[16];
} acolor_argb_t;
A_STATIC_ASSERT(sizeof(acolor_argb_t) == 16);

#define A_color_argb(d, e, f, g) { .a = d, .r = e, .g = f, .b = g }

typedef union aplane3f_t {
    struct { avec3f_t v; float w; } p;
    float array[4];
    char  bytes[16];
} aplane3f_t;
A_STATIC_ASSERT(sizeof(aplane3f_t) == 16);

typedef union amat2f_t {
    float m[2][2];
    float array[4];
    char  bytes[16];
} amat2f_t;
A_STATIC_ASSERT(sizeof(amat2f_t) == 16);

typedef union amat3f_t {
    float m[3][3];
    float array[9];
    char  bytes[36];
} amat3f_t;
A_STATIC_ASSERT(sizeof(amat3f_t) == 36);

typedef union amat4f_t {
    float m[4][4];
    float array[16];
    char  bytes[64];
} amat4f_t;
A_STATIC_ASSERT(sizeof(amat4f_t) == 64);

typedef union aquatf_t {
    float q[2][2];
    float array[4];
    char  bytes[16];
} aquatf_t;
A_STATIC_ASSERT(sizeof(aquatf_t) == 16);

typedef union abounds2f_t {
    struct { float min, max; };
    float array[2];
    char bytes[8];
} abounds2f_t;

A_EXTERN_C const amat4f_t A__priv__mat4f_identity;
#define A_MAT4F_ZERO      A__priv__mat4f_zero
#define A_MAT4F_IDENTITY  A__priv__mat4f_identity

A_EXTERN_C A_NO_DISCARD float  A_ceilf(float  a, float  b);
A_EXTERN_C A_NO_DISCARD double A_ceil (double a, double b);
A_EXTERN_C A_NO_DISCARD int    A_ceili(int    a, int    b);

A_EXTERN_C A_NO_DISCARD float      A_sqrtf(float  x);
A_EXTERN_C A_NO_DISCARD double     A_sqrt (double x);
A_EXTERN_C A_NO_DISCARD float      A_sinf (float  x);
A_EXTERN_C A_NO_DISCARD double     A_sin  (double x);
A_EXTERN_C A_NO_DISCARD float      A_asinf(float  x);
A_EXTERN_C A_NO_DISCARD double     A_asin (double x);
A_EXTERN_C A_NO_DISCARD float      A_cosf (float  x);
A_EXTERN_C A_NO_DISCARD double     A_cos  (double x);
A_EXTERN_C A_NO_DISCARD float      A_acosf(float  x);
A_EXTERN_C A_NO_DISCARD double     A_acos (double x);
A_EXTERN_C A_NO_DISCARD float      A_tanf (float  x);
A_EXTERN_C A_NO_DISCARD double     A_tan  (double x);
A_EXTERN_C A_NO_DISCARD float      A_atanf(float  x);
A_EXTERN_C A_NO_DISCARD double     A_atan (double x);

A_EXTERN_C A_NO_DISCARD float      A_radians(float degrees);
A_EXTERN_C A_NO_DISCARD float      A_degrees(float radians);
          
A_EXTERN_C A_NO_DISCARD float      A_vec2f_length   (avec2f_t v);
A_EXTERN_C A_NO_DISCARD float      A_vec3f_length   (avec3f_t v);
A_EXTERN_C A_NO_DISCARD float      A_vec4f_length   (avec4f_t v);
A_EXTERN_C A_NO_DISCARD avec2f_t   A_vec2f_normalize(avec2f_t v);
A_EXTERN_C A_NO_DISCARD avec3f_t   A_vec3f_normalize(avec3f_t v);
A_EXTERN_C A_NO_DISCARD avec4f_t   A_vec4f_normalize(avec4f_t v);

A_EXTERN_C A_NO_DISCARD apoint3f_t A_point3f_swap_yz(apoint3f_t p);

A_EXTERN_C A_NO_DISCARD bool       A_vec3f_eq   (avec3f_t a, avec3f_t b);
A_EXTERN_C A_NO_DISCARD avec3f_t   A_vec3f_add  (avec3f_t a, avec3f_t b);
A_EXTERN_C A_NO_DISCARD avec3f_t   A_vec3f_sub  (avec3f_t a, avec3f_t b);
A_EXTERN_C A_NO_DISCARD float      A_vec3f_dot  (avec3f_t a, avec3f_t b);
A_EXTERN_C A_NO_DISCARD avec3f_t   A_vec3f_cross(avec3f_t a, avec3f_t b);
A_EXTERN_C A_NO_DISCARD avec3f_t   A_vec3f_mul  (avec3f_t a, float b);

A_EXTERN_C A_NO_DISCARD avec4f_t   A_vec4f_add(avec4f_t a, avec4f_t b);

A_EXTERN_C A_NO_DISCARD amat4f_t   A_mat4f_translate_vec3(amat4f_t m,   
                                                          avec3f_t v);
A_EXTERN_C A_NO_DISCARD amat4f_t   A_mat4f_scale_vec3    (amat4f_t m,   
                                                          avec3f_t v);
A_EXTERN_C A_NO_DISCARD amat4f_t   A_mat4f_mul(amat4f_t a, amat4f_t b);
A_EXTERN_C A_NO_DISCARD amat4f_t   A_mat4f_euler(avec3f_t angles);

//A_EXTERN_C A_NO_DISCARD amat4f_t   A_mat4f_look_at       (avec3f_t eye, 
//                                                          avec3f_t center, 
//                                                          avec3f_t up);
//A_EXTERN_C A_NO_DISCARD amat4f_t   A_mat4f_ortho         (float left,   
//                                                          float right, 
//                                                          float top,    
//                                                          float bottom);
//A_EXTERN_C A_NO_DISCARD amat4f_t   A_mat4f_perspective   (float fovy,   
//                                                          float aspect,
//                                                          float z_near, 
//                                                          float z_far);
