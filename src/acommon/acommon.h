#pragma once

#include <stddef.h>
#include <limits.h>

#define A_countof(a) (sizeof((a)) / sizeof(*(a))) 

#define SIZE_BIT ((size_t)((size_t)CHAR_BIT * sizeof(size_t)))

#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C
#endif // __cplusplus

#ifdef __cplusplus
#define A_RESTRICT __restrict
#else
#define A_RESTRICT restrict
#endif // __cplusplus

#ifdef __cplusplus
#define NO_RETURN [[noreturn]] void
#else
#include <stdnoreturn.h>
#define NO_RETURN _Noreturn void
#endif // __cplusplus

#ifdef __cplusplus
#define NO_DISCARD [[nodiscard]]
#else
#define NO_DISCARD
#endif // __cpluslplus

#ifdef _WIN32
#define TARGET_OS_IS_WINDOWS 1
#else 
#define TARGET_OS_IS_WINDOWS 0
#endif // _WIN32

#if TARGET_OS_IS_WINDOWS
#define IN _In_
#else
#define IN
#endif // TARGET_OS_IS_WINDOWS

#if TARGET_OS_IS_WINDOWS
#define OUT _Out_
#else
#define OUT
#endif // TARGET_OS_IS_WINDOWS

#if TARGET_OS_IS_WINDOWS
#define INOUT _Inout_
#else
#define INOUT
#endif // TARGET_OS_IS_WINDOWS

#if TARGET_OS_IS_WINDOWS
#define OPTIONAL_IN _In_opt_
#else
#define OPTIONAL_IN
#endif // TARGET_OS_IS_WINDOWS

#if TARGET_OS_IS_WINDOWS
#define OPTIONAL_OUT _Out_opt_
#else
#define OPTIONAL_OUT
#endif // TARGET_OS_IS_WINDOWS

EXTERN_C size_t A_npow2(size_t n);
EXTERN_C size_t A_ppow2(size_t n);

