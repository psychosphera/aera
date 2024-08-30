#include "z_mem.h"

#include <stdlib.h>
#include <stdbool.h>

#include "a_string.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <sys/mman.h>
#endif // _WIN32

void* Z_Alloc(size_t n) {
    return malloc(n);
}

void* Z_Zalloc(size_t n) {
    return calloc(n, 1);
}

void* Z_Realloc(void* p, size_t n) {
    return realloc(p, n);
}

void Z_Free(void* p) {
    free(p);
}

#ifdef _WIN32
void* Z_AllocAt(void* p, size_t n) {
    return VirtualAlloc(p, n, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE) == p ? p : NULL;
}
#else 
void* Z_AllocAt(void* p, size_t n) {
    return mmap(p, n, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0) == p ? p : NULL;
}
#endif // _WIN32

void* Z_ZallocAt(void* p, size_t n) {
    if (Z_AllocAt(p, n) != p)
        return NULL;

    A_memset(p, 0, n);
    return p;
}

#ifdef _WIN32
bool Z_FreeAt(void* p, size_t n) {
    n = 0;
    return VirtualFree(p, n, MEM_RELEASE);
}
#else
bool Z_FreeAt(void* p, size_t n) {
    return munmap(p, n) == 0;
}
#endif // _WIN32
