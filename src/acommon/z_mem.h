#pragma once

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

void* Z_Alloc  (size_t n);
void* Z_Zalloc (size_t n);
void* Z_Realloc(void* p, size_t n); 
void  Z_Free   (void* p);

#ifdef __cplusplus
}
#endif // __cplusplus
