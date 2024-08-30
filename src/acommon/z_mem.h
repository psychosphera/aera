#pragma once

#include <stddef.h>
#ifndef __cplusplus
#include <stdbool.h>
#endif // __cplusplus

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

void* Z_Alloc   (size_t n);
void* Z_Zalloc  (size_t n);
void* Z_Realloc (void* p, size_t n); 
void  Z_Free    (void* p);

void* Z_AllocAt (void* p, size_t n);
void* Z_ZallocAt(void* p, size_t n);
bool  Z_FreeAt  (void* p, size_t n);

#ifdef __cplusplus
}
#endif // __cplusplus
