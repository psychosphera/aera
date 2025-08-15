#include "a_string.h"
#include "a_type.h"

#include <assert.h>
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if defined(_MSC_VER) && _MSC_VER < 1900
#define snprintf  _snprintf
#define vsnprintf _vsnprintf
#endif // defined(_MSC_VER) && _MSC_VER < 1900

#include "z_mem.h"

A_NO_DISCARD bool A_memcmp(const void* A_RESTRICT a, 
                           const void* A_RESTRICT b, size_t n
) {
    for(int i = 0; i < n; i++) {
        if(((char* A_RESTRICT)a)[i] != ((char* A_RESTRICT)b)[i])
            return false;
    }

    return true;
}

void A_memcpy(void* A_RESTRICT dest, const void* A_RESTRICT src, size_t n) {
    for(size_t i = 0; i < n; i++)
        ((char* A_RESTRICT)dest)[i] = ((char* A_RESTRICT)src)[i];
}

A_NO_DISCARD void* A_memchr(const void* A_RESTRICT p, char c, size_t n) {
    for(size_t i = 0; i < n; i++) {
        if(((char* A_RESTRICT)p)[i] == c)
            return (void* A_RESTRICT)((const char*)p + i);
    }

    return NULL;
}

A_NO_DISCARD void* A_memrchr(const void* A_RESTRICT p, char c, size_t n) {
    for(size_t i = n; i > 0; i--) {
        if(((char* A_RESTRICT)p)[i] == c)
            return (void* A_RESTRICT)((const char*)p + i);
    }

    return NULL;
}

void A_memset(void* A_RESTRICT p, char c, size_t n) {
    for(size_t i = 0; i < n; i++)
        ((char* A_RESTRICT)p)[i] = c;
}

void A_memzero(void* A_RESTRICT p, size_t n) {
    A_memset(p, 0, n);
}

A_NO_DISCARD bool A_cstrcmp(const char* A_RESTRICT a,
                            const char* A_RESTRICT b
) {
    return strcmp(a, b) == 0;
}

A_NO_DISCARD bool A_cstricmp(const char* A_RESTRICT a, 
                             const char* A_RESTRICT b
) {
    size_t a_len = A_cstrlen(a);
    size_t b_len = A_cstrlen(b);

    if (a_len != b_len)
        return false;

    for (size_t i = 0; i < a_len; i++) {
        if (A_tolower(a[i]) != A_tolower(b[i]))
            return false;
    }
    
    return true;
}

A_NO_DISCARD size_t A_cstrlen(const char* A_RESTRICT s) {
    return strlen(s);
}

A_NO_DISCARD char* A_cstrdup(const char* A_RESTRICT s) {
    size_t len = A_cstrlen(s);
    char* t = (char*)Z_Zalloc(len + 1);
    A_memcpy(t, s, len);
    return t;
}

void A_cstrfree(const char* A_RESTRICT s) {
    Z_Free((void*)s);
}

void A_cstrncpyz(char* A_RESTRICT dest, const char* A_RESTRICT src, size_t n) {
    size_t i = 0;
    for (; i < n; i++) {
        dest[i] = src[i];
        if (dest[i] == '\0')
            break;
    }
    if (i < n - 1)
        dest[i] = '\0';
    else
        dest[n - 1] = '\0';
}

A_NO_DISCARD size_t A_cstrchr(const char* A_RESTRICT s, char c) {
    const char* A_RESTRICT p = (const char*)memchr(s, c, A_cstrlen(s));
    return p == NULL ? A_NPOS : p - s;
}

int A_vsnprintf(char* A_RESTRICT buf, size_t count, const char* fmt, va_list ap) {
	return vsnprintf(buf, count, fmt, ap);
}

int A_snprintf(char* A_RESTRICT buf, size_t count, const char* fmt, ...) {
    if (buf == NULL || fmt == NULL || count < 1)
        return -1;
    va_list ap;
    va_start(ap, fmt);
    return A_vsnprintf(buf, count, fmt, ap);
}

bool A_atob(const char* A_RESTRICT s, A_OUT bool* b) {
    *b = false;
    if (A_cstricmp(s, "true")) {
        *b = true;
        return true;
    }
    if (A_cstricmp(s, "false")) {
        return true;
    }
    int i = 0;
    if (A_atoi(s, &i)) {
        if (i == 0)
            return false;
        if (i == 1)
            return true;
    }
    return false;
}

size_t A_itoa(int i, char* A_RESTRICT p, size_t n) {
    int ret = snprintf(p, n, "%*d", (int)n, i);
    assert(ret <= n);
    return ret;
}

bool A_atoi(const char* A_RESTRICT s, A_OUT int* i) {
    assert(i);
    *i = 0;
    if (s == NULL)
        return false;
    errno = 0;
    const char* A_RESTRICT end = s;
    int l = strtod(s, (char** A_RESTRICT)&end);
    if (errno != 0 || end == s)
        return false;
    *i = l;
    return true;
}

size_t A_ftoa(float f, char* A_RESTRICT p, size_t n) {
    int ret = snprintf(p, n, "%*f", (int)n, f);
    assert(ret <= n);
    return ret;
}

bool A_atof(const char* A_RESTRICT s, A_OUT float* f) {
    assert(f);
    *f = 0.0f;
    if (s == NULL)
        return false;
    errno = 0;
#if (defined(_MSC_VER) && _MSC_VER >= 1700) || !defined(_MSC_VER)
    const char* A_RESTRICT end = s;
    float g = strtof(s, (char** A_RESTRICT)&end);
    if (errno != 0 || end == s)
        return false;
    *f = g;
#else
	*f = atof(s);
#endif // (defined(_MSC_VER) && _MSC_VER >= 1700) || !defined(_MSC_VER)
    return true;
}
