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

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

void* Z_Alloc   (size_t n);
void* Z_Zalloc  (size_t n);
void* Z_Realloc (void* p, size_t n); 
void  Z_Free    (void* p);

void* Z_AllocAt (const void* p, size_t n);
void* Z_ZallocAt(const void* p, size_t n);
bool  Z_FreeAt  (const void* p, size_t n);

FileMapping Z_MapFile  (const char* filename);
bool        Z_UnmapFile(A_INOUT FileMapping* f);

#ifdef __cplusplus
}
#endif // __cplusplus
