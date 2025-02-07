#pragma once

#include <stddef.h>
#include <limits.h>

#define A_countof(a) (sizeof((a)) / sizeof(*(a))) 

#define SIZE_BIT ((size_t)((size_t)CHAR_BIT * sizeof(size_t)))

#ifdef __STDC__
#define A_STDC 1
#else
#define A_STDC 0
#endif // __STDC__
       
#ifdef __cplusplus
#define A_CXX 1
#else
#define A_CXX 0
#endif // __cplusplus

#ifdef __STDC__
#define A_C89 1
#else
#define A_C89 0
#endif // __STDC__

#if defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L
#define A_C99 1
#else 
#define A_C99 0
#endif // defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L

#if defined __STDC_VERSION__ && __STDC_VERSION__ >= 201112L
#define A_C11 1
#else 
#define A_C11 0
#endif // defined __STDC_VERSION__ && __STDC_VERSION__ >= 201112L       

#if defined __STDC_VERSION__ && __STDC_VERSION__ >= 201710L
#define A_C17 1
#else 
#define A_C17 0
#endif // defined __STDC_VERSION__ && __STDC_VERSION__ >= 201710L       

#if defined __STDC_VERSION__ && __STDC_VERSION__ >= 202311L
#define A_C23 1
#else 
#define A_C23 0
#endif // defined __STDC_VERSION__ && __STDC_VERSION__ >= 202311L       

#if defined __cplusplus && __cplusplus >= 199711L
#define A_CXX98 1
#else
#define A_CXX98 0
#endif // defined __cplusplus && __cplusplus >= 199711L

#if defined __cplusplus && __cplusplus >= 201103L
#define A_CXX11 1
#else
#define A_CXX11 0
#endif // defined __cplusplus && __cplusplus >= 201103L

#if defined __cplusplus && __cplusplus >= 201402L
#define A_CXX14 1
#else
#define A_CXX14 0
#endif // defined __cplusplus && __cplusplus >= 201402L

#if defined __cplusplus && __cplusplus >= 201703L
#define A_CXX17 1
#else
#define A_CXX17 0
#endif // defined __cplusplus && __cplusplus >= 201703L

#if defined __cplusplus && __cplusplus >= 202002L
#define A_CXX20 1
#else
#define A_CXX20 0
#endif // defined __cplusplus && __cplusplus >= 202002L

#if defined __cplusplus && __cplusplus >= 202302L
#define A_CXX23 1
#else
#define A_CXX23 0
#endif // defined __cplusplus && __cplusplus >= 202302L

#ifdef _WIN32
#define A_TARGET_OS_IS_WINDOWS 1
#else
#define A_TARGET_OS_IS_WINDOWS 0
#endif // _WIN32

#ifdef _MSC_VER
#define A_COMPILER_IS_MSVC 1
#else
#define A_COMPILER_IS_MSVC 0
#endif // _MSC_VER
       
#ifdef __GNUC__
#define A_COMPILER_IS_GCC_COMPATIBLE 1
#else
#define A_COMPILER_IS_GCC_COMPATIBLE 0
#endif // __GNUC__
       
#if A_COMPILER_IS_MSVC
#define A_IN _In_
#else
#define A_IN
#endif // A_TARGET_OS_IS_WINDOWS

#if A_COMPILER_IS_MSVC
#define A_OUT _Out_
#else
#define A_OUT
#endif // A_TARGET_OS_IS_WINDOWS

#if A_COMPILER_IS_MSVC
#define A_INOUT _Inout_
#else
#define A_INOUT
#endif // A_TARGET_OS_IS_WINDOWS

#if A_COMPILER_IS_MSVC
#define A_OPTIONAL_IN _In_opt_
#else
#define A_OPTIONAL_IN
#endif // A_TARGET_OS_IS_WINDOWS

#if A_COMPILER_IS_MSVC
#define A_OPTIONAL_OUT _Out_opt_
#else
#define A_OPTIONAL_OUT
#endif // A_TARGET_OS_IS_WINDOWS

#if A_CXX17 || A_C23
#define A_NO_DISCARD [[nodiscard]]
#elif A_COMPILER_IS_GCC_COMAPTIBLE
#define A_NO_DISCARD __attribute__((warn_unused_result))
#elif A_COMPILER_IS_MSVC
#define A_NO_DISCARD _Check_return_
#else
#define A_NO_DISCARD
#endif // __cplusplus 

#if A_CXX11 || A_C23
#define A_NO_RETURN [[noreturn]] void
#elif A_C11 && !A_C23
#define A_NO_RETURN _Noreturn void
#elif A_COMPILER_IS_GCC_COMPATIBLE
#define A_NO_RETURN __attribute__((noreturn)) void
#elif A_COMPILER_IS_MSVC 
#define A_NO_RETURN __declspec(noreturn) void
#else 
#define A_NO_RETURN void
#endif // __cplusplus

#if A_CXX11 || A_C23
#define A_MAYBE_UNUSED [[maybe_unused]]
#elif A_COMPILER_IS_GCC_COMPATIBLE
#define A_MAYBE_UNUSED __attribute__((unused)) void
#else 
#define A_MAYBE_UNUSED
#endif // __cplusplus

#define A_NOP() ;
#define A_SCOPE(...) do { __VA_ARGS__ } while(0);

#ifdef __cplusplus
#define A_EXTERN_C extern "C"
#else
#define A_EXTERN_C
#endif // __cplusplus

#ifdef __cplusplus
#define A_RESTRICT __restrict
#else
#define A_RESTRICT restrict
#endif // __cplusplus

#define A_UNUSED(a) 

#define A_EXPAND(a) a

#define A_CAT_INTERNAL(a, b) a##b
#define A_CAT(a, b) A_CAT_INTERNAL(a, b)
#define A_CAT2(a, b, c) A_CAT(a, A_CAT(b, c))
#define A_CAT3(a, b, c, d) A_CAT(a, A_CAT2(b, c, d))
#define A_CAT4(a, b, c, d, e) A_CAT(a, A_CAT3(b, c, d, e))
#define A_CAT5(a, b, c, d, e, f) A_CAT(a, A_CAT4(b, c, d, e, f))
#define A_CAT6(a, b, c, d, e, f, g) A_CAT(a, A_CAT5(b, c, d, e, f, g))
#define A_CAT7(a, b, c, d, e, f, g, h) A_CAT(a, A_CAT6(b, c, d, e, f, g, h))

#define A_STRINGIFY_INTERNAL(a) #a
#define A_STRINGIFY(a) A_STRINGIFY_INTERNAL(a)

#define A_PRAGMA(s) _Pragma(A_STRINGIFY(s))
#define A_MESSAGE(s) A_PRAGMA(message(s))

#define A_GENERIC_MATCH_CONST(t, b) t: b, const t: b

#define A_GENERIC_MATCH_SIGNED_INTEGRAL(b) \
    A_GENERIC_MATCH_CONST(signed char, b), \
    A_GENERIC_MATCH_CONST(signed short, b), \
    A_GENERIC_MATCH_CONST(signed int, b), \
    A_GENERIC_MATCH_CONST(signed long, b), \
    A_GENERIC_MATCH_CONST(signed long long, b)

#define A_GENERIC_MATCH_UNSIGNED_INTEGRAL(b) \
    A_GENERIC_MATCH_CONST(unsigned char, b), \
    A_GENERIC_MATCH_CONST(unsigned short, b), \
    A_GENERIC_MATCH_CONST(unsigned int, b), \
    A_GENERIC_MATCH_CONST(unsigned long, b), \
    A_GENERIC_MATCH_CONST(unsigned long long, b)

#define A_GENERIC_MATCH_INTEGRAL(b) \
    A_GENERIC_MATCH_SIGNED_INTEGRAL(b), \
    A_GENERIC_MATCH_UNSIGNED_INTEGRAL(b)

#if A_C23 || A_CXX17
#   define A_STATIC_ASSERT(...) static_assert(__VA_ARGS__)
#elif A_C11
#   define A_STATIC_ASSERT(...) _Static_assert(__VA_ARGS__)
#elif A_CXX11
#   define A_STATIC_ASSERT(...) static_assert(__VA_ARGS__, "Static Assertion Failed.")
#endif

#if A_COMPILER_IS_GCC_COMPATIBLE
#define A_PACK(...) __attribute__((__packed__)) __VA_ARGS__ 
#elif A_COMPILER_IS_MSVC
#define A_PACK(...) \
    A_PRAGMA(pack(push, 1)) \
    __VA_ARGS__ \
    A_PRAGMA(pack(pop))
#else 
#error "Struct packing unimplemented."
#endif // A_COMPILER_IS_GCC_COMPATIBLE

#define A_MAKE_FOURCC(a, b, c, d) ((d) | (c << 8) | (b << 16) | (a << 24))

A_EXTERN_C size_t A_npow2(size_t n);
A_EXTERN_C size_t A_ppow2(size_t n);

A_PACK(union apoint2i_t {
    struct { int x, y; };
    int array[2];
    char bytes[8];
});
typedef union apoint2i_t apoint2i_t;

A_PACK(union apoint2s_t {
    struct { short x, y; };
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
