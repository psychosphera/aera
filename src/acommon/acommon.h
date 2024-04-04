#pragma once

#include <stddef.h>
#include <limits.h>

#define A_countof(a) (sizeof((a)) / sizeof(*(a))) 

#define SIZE_BIT ((size_t)((size_t)CHAR_BIT * sizeof(size_t)))

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

#ifdef __cplusplus
#define A_NO_RETURN [[noreturn]] void
#else
#include <stdnoreturn.h>
#define A_NO_RETURN _Noreturn void
#endif // __cplusplus

#ifdef __cplusplus
#define A_NO_DISCARD [[nodiscard]]
#else
#define A_NO_DISCARD
#endif // __cpluslplus

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

A_EXTERN_C size_t A_npow2(size_t n);
A_EXTERN_C size_t A_ppow2(size_t n);

