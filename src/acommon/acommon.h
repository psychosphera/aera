#pragma once

#include <stddef.h>
#include <limits.h>

#define A_countof(a) (sizeof((a)) / sizeof(*(a))) 

#define SIZE_BIT ((size_t)((size_t)CHAR_BIT * sizeof(size_t)))

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

#ifdef __cplusplus
#define A_NO_DISCARD [[nodiscard]]
#else
#define A_NO_DISCARD
#endif // __cplusplus

#ifdef __cplusplus
#define A_NO_RETURN [[noreturn]] void
#else
#include <stdnoreturn.h>
#define A_NO_RETURN _Noreturn void
#endif // __cplusplus

#define NOP() ;

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

A_EXTERN_C size_t A_npow2(size_t n);
A_EXTERN_C size_t A_ppow2(size_t n);

