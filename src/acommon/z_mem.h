#pragma once

#include <stddef.h>

#include "acommon.h"

#if A_TARGET_OS_IS_WINDOWS && !A_TARGET_PLATFORM_IS_XBOX
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>
#elif A_TARGET_PLATFORM_IS_XBOX
#include <Xtl.h>
#endif // _WIN32

#if !A_TARGET_PLATFORM_IS_XBOX
typedef struct FileMapping {
    void* p;
    size_t n;
#ifdef _WIN32
    HANDLE __hFile;
    HANDLE __hMap;
#endif // _WIN32
} FileMapping;
#endif // !A_TARGET_PLATFORM_IS_XBOX

A_EXTERN_C A_NO_DISCARD void* Z_Alloc   (size_t n);
A_EXTERN_C A_NO_DISCARD void* Z_Zalloc  (size_t n);
A_EXTERN_C A_NO_DISCARD void* Z_Realloc (void* p, size_t n); 
A_EXTERN_C              void  Z_Free    (void* p);

A_EXTERN_C A_NO_DISCARD void* Z_AllocAt (const void* p, size_t n);
A_EXTERN_C A_NO_DISCARD void* Z_ZallocAt(const void* p, size_t n);
A_EXTERN_C              bool  Z_FreeAt  (const void* p, size_t n);

#if !A_TARGET_PLATFORM_IS_XBOX
A_EXTERN_C A_NO_DISCARD FileMapping Z_MapFile  (const char* filename);
A_EXTERN_C              bool        Z_UnmapFile(A_INOUT FileMapping* f);
#endif // !A_TARGET_PLATFORM_IS_XBOX