// a_string.h
//
// Contains declarations for A_cstr* and A_mem* functions (mostly analogues
// to their stdlib counterparts, with some extras added for convenience).

#pragma once

#include <stddef.h>
#include <stdarg.h>
#include <limits.h>

#include "acommon.h"

// ============================================================================
// Basically the C `mem*` functions from `string.h`. They're basically 
// identical to their stdlib counterparts, except all pointers are `restrict`
A_EXTERN_C A_NO_DISCARD bool A_memcmp (
    const void* A_RESTRICT a, const void* A_RESTRICT b, size_t n
);
A_EXTERN_C void A_memcpy(
    void* A_RESTRICT dest, const void* A_RESTRICT src, size_t n
);
A_EXTERN_C A_NO_DISCARD void*  A_memchr (const void* A_RESTRICT p, 
                                         char c, 
                                         size_t n);
A_EXTERN_C A_NO_DISCARD void*  A_memrchr(const void* A_RESTRICT p, 
                                         char c,
                                        size_t n);
A_EXTERN_C void   A_memset(void* A_RESTRICT p, char c, size_t n);
A_EXTERN_C void   A_memzero(void* A_RESTRICT p, size_t n);
// ============================================================================

// Analogous to std::string::npos.
#define A_NPOS (~(size_t)0)

A_EXTERN_C A_NO_DISCARD bool A_cstrcmp (const char* A_RESTRICT a, 
                                        const char* A_RESTRICT b);
A_EXTERN_C A_NO_DISCARD bool A_cstricmp(const char* A_RESTRICT a, 
                                        const char* A_RESTRICT b);

// This is its own function, rather than being an overload of `A_strlen` 
// because it's O(n) rather than O(1). It should only ever really be used to
// create a `str_t` from a C-style string.
A_EXTERN_C A_NO_DISCARD size_t A_cstrlen(const char* A_RESTRICT p);

A_EXTERN_C A_NO_DISCARD char* A_cstrdup (const char* A_RESTRICT s);
A_EXTERN_C              void  A_cstrfree(const char* A_RESTRICT s);

A_EXTERN_C A_NO_DISCARD size_t A_cstrchr(const char* A_RESTRICT s, char c);
A_EXTERN_C void A_cstrncpyz(char* A_RESTRICT dest, 
                            const char* A_RESTRICT src, size_t n);
A_EXTERN_C int    A_vsnprintf(char* A_RESTRICT buf, size_t count, const char* fmt, va_list ap);
A_EXTERN_C int    A_snprintf(char* buf, size_t count, const char* fmt, ...);
A_EXTERN_C bool   A_atob(const char* A_RESTRICT s, A_OUT bool* b);
A_EXTERN_C size_t A_itoa(int i, char* A_RESTRICT p, size_t n);
A_EXTERN_C bool   A_atoi(const char* A_RESTRICT s, A_OUT int* i);
A_EXTERN_C size_t A_ftoa(float f, char* A_RESTRICT p, size_t n);
A_EXTERN_C bool   A_atof(const char* A_RESTRICT s, A_OUT float* f);