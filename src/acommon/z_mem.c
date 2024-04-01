#include "z_mem.h"

#include <stdlib.h>

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
