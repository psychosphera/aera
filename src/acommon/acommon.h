#pragma once

#include <stddef.h>
#include <limits.h>

#define countof(a) (sizeof((a)) / sizeof(*(a))) 

#define SIZE_BIT ((size_t)((size_t)CHAR_BIT * sizeof(size_t)))

#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C
#endif

EXTERN_C size_t A_npow2(size_t n);
EXTERN_C size_t A_ppow2(size_t n);

