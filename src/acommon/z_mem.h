#pragma once

#include <stddef.h>
#ifndef __cplusplus
#include <stdbool.h>
#endif // __cplusplus

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>
#endif // _WIN32

#include "acommon.h"


typedef struct FileMapping {
    void* p;
    size_t n;
#ifdef _WIN32
    HANDLE __hFile;
    HANDLE __hMap;
#endif // _WIN32
} FileMapping;

A_EXTERN_C A_NO_DISCARD void* Z_Alloc   (size_t n);
A_EXTERN_C A_NO_DISCARD void* Z_Zalloc  (size_t n);
A_EXTERN_C A_NO_DISCARD void* Z_Realloc (void* p, size_t n); 
A_EXTERN_C              void  Z_Free    (void* p);

A_EXTERN_C A_NO_DISCARD void* Z_AllocAt (const void* p, size_t n);
A_EXTERN_C A_NO_DISCARD void* Z_ZallocAt(const void* p, size_t n);
A_EXTERN_C              bool  Z_FreeAt  (const void* p, size_t n);

A_EXTERN_C A_NO_DISCARD FileMapping Z_MapFile  (const char* filename);
A_EXTERN_C              bool        Z_UnmapFile(A_INOUT FileMapping* f);
