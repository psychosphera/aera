#pragma once

#include "acommon.h"

#define A_MIN(a, b) ((a) < (b) ? (a) : (b))
#define A_MAX(a, b) ((a) > (b) ? (a) : (b))

#define A_ROUND(from, by) (from + ((~(from - 1)) & (by - 1)))

#define A_IS_MULTIPLE_OF(a, m) (((a) / (m)) * (m) == (a))

A_PACK(union apoint2i_t {
    struct { int x, y; };
    int array[2];
    char bytes[8];
});
typedef union apoint2i_t apoint2i_t;

A_PACK(union apoint2s_t {
    struct { short x, y; };
    struct { short u, v; };
    short array[2];
    char bytes[4];
});
typedef union apoint2s_t apoint2s_t;

A_PACK(union apoint3i_t {
    struct { int x, y, z; };
    int array[3];
    char bytes[12];
});
typedef union apoint3i_t apoint3i_t;

A_PACK(union apoint2f_t {
    struct { float x, y; };
    struct { float u, v; };
    float array[2];
    char bytes[8];
});
typedef union apoint2f_t apoint2f_t;

A_PACK(union apoint3f_t {
    struct { float x, y, z; };
    float array[3];
    char bytes[12];
});
typedef union apoint3f_t apoint3f_t;

A_PACK(union avec2i_t {
    struct { int x, y; };
    struct { int t, u; };
    int array[2];
    char bytes[8];
});
typedef union avec2i_t avec2i_t;

A_PACK(union avec3i_t {
    struct { int a, b, c; };
    struct { int x, y, z; };
    int array[3];
    char bytes[12];
});
typedef union avec3i_t avec3i_t;

A_PACK(union avec4i_t {
    struct { int x, y, z, w; };
    int array[4];
    char bytes[16];
});
typedef union avec4i_t avec4i_t;

A_PACK(union avec2f_t {
    struct { float x, y; };
    struct { float t, u; };
    float array[2];
    char bytes[8];
});
typedef union avec2f_t avec2f_t;

A_PACK(union avec3f_t {
    struct { float x, y, z; };
    float array[3];
    char bytes[12];
});
typedef union avec3f_t avec3f_t;

A_PACK(union avec4f_t {
    struct { float a, b, c, d; };
    struct { float x, y, z, w; };
    float array[4];
    char bytes[16];
});
typedef union avec4f_t avec4f_t;

A_PACK(union acolor_rgb_t {
    struct { float r, g, b; };
    float array[3];
    char bytes[12];
});
typedef union acolor_rgb_t acolor_rgb_t;

A_PACK(union acolor_rgba_t {
    struct { float r, g, b, a; };
    float array[4];
    char bytes[16];
});
typedef union acolor_rgba_t acolor_rgba_t;

A_PACK(union acolor_argb_t {
    struct { float a, r, g, b; };
    float array[4];
    char bytes[16];
});
typedef union acolor_argb_t acolor_argb_t;

A_PACK(union aplane3f_t {
    struct { avec3f_t v; float w; } p;
    float array[4];
    char bytes[16];
});
typedef union aplane3f_t aplane3f_t;

A_EXTERN_C float  A_sqrtf(float  x);
A_EXTERN_C double A_sqrt (double x);
A_EXTERN_C float  A_sinf (float  x);
A_EXTERN_C double A_sin  (double x);
A_EXTERN_C float  A_asinf(float  x);
A_EXTERN_C double A_asin (double x);
A_EXTERN_C float  A_cosf (float  x);
A_EXTERN_C double A_cos  (double x);
A_EXTERN_C float  A_acosf(float  x);
A_EXTERN_C double A_acos (double x);
A_EXTERN_C float  A_tanf (float  x);
A_EXTERN_C double A_tan  (double x);
A_EXTERN_C float  A_atanf(float  x);
A_EXTERN_C double A_atan (double x);

A_EXTERN_C void   A_vec2f_normalize(A_INOUT avec2f_t* v);
A_EXTERN_C void   A_vec3f_normalize(A_INOUT avec3f_t* v);
A_EXTERN_C void   A_vec4f_normalize(A_INOUT avec4f_t* v);