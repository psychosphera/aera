#include "a_string.h"
#include "a_type.h"

#include <assert.h>
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "z_mem.h"

A_NO_DISCARD bool A_memcmp(const void* A_RESTRICT a, 
                           const void* A_RESTRICT b, size_t n
) {
    for(size_t i = 0; i < n; i++) {
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
    char* t = Z_Zalloc(len + 1);
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
    const char* A_RESTRICT p = memchr(s, c, A_cstrlen(s));
    return p == NULL ? A_NPOS : p - s;
}

int A_snprintf(char* buf, size_t count, const char* fmt, ...) {
    if (buf == NULL || fmt == NULL || count < 1)
        return -1;
    va_list ap;
    va_start(ap, fmt);
    return vsnprintf(buf, count, fmt, ap);
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
    const char* A_RESTRICT end = s;
    float g = strtof(s, (char** A_RESTRICT)&end);
    if (errno != 0 || end == s)
        return false;
    *f = g;
    return true;
}

// str_t A_literal_internal(const char* A_RESTRICT s, size_t c) {
//     str_t n;
//     n.__data = s;
//     n.__len  = c - 1; // sizeof(literal) includes the null-terminator
//     return n;
// }

// str_t A_STRING_MANGLE_VOID(A_str)(void) {
//     str_t n;
//     n.__data = NULL;
//     n.__len = 0;
//     return n;
// }

// str_t A_STRING_MANGLE_CSTR(A_str)(const char* A_RESTRICT p) {
//     str_t n;
//     n.__data = p;
//     n.__len  = A_cstrlen(p);
//     return n;
// }

// str_t A_STRING_MANGLE_STR(A_str)(const str_t* A_RESTRICT s) {
//     return *s;
// }

// str_t A_STRING_MANGLE_STRING(A_str)(const string_t* A_RESTRICT s) {
//     str_t n;
//     n.__data = A_cstr(s);
//     n.__len  = A_strlen(s);
//     return n;
// }

// #define A_STRING_IMPL_STR(attr_ret, name, s, ...) \
//     attr_ret A_STRING_MANGLE_STR(name)(const str_t* s) { __VA_ARGS__ }

// #define A_STRING_IMPL_STRING(attr_ret, name, s, ...) \
//     attr_ret A_STRING_MANGLE_STRING(name)(string_t* s) { __VA_ARGS__ }

// #define A_STRING_IMPL_STRING_CONST(attr_ret, name, s, ...) \
//     attr_ret A_STRING_MANGLE_STRING(name)(const string_t* s) { __VA_ARGS__ }

// #define A_STRING_IMPL_LITERAL(attr_ret, name, s, ...) \
//     attr_ret A_STRING_MANGLE_LITERAL(name)(const string_t* s) { __VA_ARGS__ }

// #define A_STRING_IMPL_BOTH(attr_ret, name, s, ...) \
//     A_STRING_IMPL_STR(attr_ret, name, s, __VA_ARGS__) \
//     A_STRING_IMPL_STRING(attr_ret, name, s, __VA_ARGS__)

// #define A_STRING_IMPL_BOTH_CONST(attr_ret, name, s, ...) \
//     A_STRING_IMPL_STR(attr_ret, name, s, __VA_ARGS__) \
//     A_STRING_IMPL_STRING_CONST(attr_ret, name, s, __VA_ARGS__)

// #define A_STRING_IMPL_STR_STR(attr_ret, name, s, t, ...) \
//     attr_ret A_STRING_MANGLE_STR_STR(name)(const str_t* s, const str_t* t) { \
//         __VA_ARGS__ \
//     }

// #define A_STRING_IMPL_STR_STRING(attr_ret, name, s, t, ...) \
//     attr_ret A_STRING_MANGLE_STR_STRING(name)( \
//         const str_t* s, const string_t* t \
//     ) { __VA_ARGS__ }

// #define A_STRING_IMPL_STR2(attr_ret, name, s, t, ...) \
//     A_STRING_IMPL_STR_STR(attr_ret, name, s, t, __VA_ARGS__) \
//     A_STRING_IMPL_STR_STRING(attr_ret, name, s, t, __VA_ARGS__)

// #define A_STRING_IMPL_STRING_STR(attr_ret, name, s, t, ...) \
//     attr_ret A_STRING_MANGLE_STRING_STR(name)( \
//         string_t* s, const str_t* t \
//     ) { __VA_ARGS__ }

// #define A_STRING_IMPL_STRING_STRING(attr_ret, name, s, t, ...) \
//     attr_ret A_STRING_MANGLE_STRING_STRING(name)( \
//         string_t* s, const string_t* t \
//     ) { __VA_ARGS__ }

// #define A_STRING_IMPL_STRING2(attr_ret, name, s, t, ...) \
//     A_STRING_IMPL_STRING_STR(attr_ret, name, s, t, __VA_ARGS__) \
//     A_STRING_IMPL_STRING_STRING(attr_ret, name, s, t, __VA_ARGS__)

// #define A_STRING_IMPL_STRING_STR_CONST(attr_ret, name, s, t, ...) \
//     attr_ret A_STRING_MANGLE_STRING_STR(name)( \
//         const string_t* s, const str_t* t \
//     ) { __VA_ARGS__ }

// #define A_STRING_IMPL_STRING_STRING_CONST(attr_ret, name, s, t, ...) \
//     attr_ret A_STRING_MANGLE_STRING_STRING(name)( \
//         const string_t* s, const string_t* t \
//     ) { __VA_ARGS__ }

// #define A_STRING_IMPL_STRING2_CONST(attr_ret, name, s, t, ...) \
//     A_STRING_IMPL_STRING_STR_CONST(attr_ret, name, s, t, __VA_ARGS__) \
//     A_STRING_IMPL_STRING_STRING_CONST(attr_ret, name, s, t, __VA_ARGS__)

// #define A_STRING_IMPL_BOTH2(attr_ret, name, s, t, ...) \
//     A_STRING_IMPL_STR2(attr_ret, name, s, t, __VA_ARGS__) \
//     A_STRING_IMPL_STRING2(attr_ret, name, s, t, __VA_ARGS__)
    
// #define A_STRING_IMPL_BOTH2_CONST(attr_ret, name, s, t, ...) \
//     A_STRING_IMPL_STR2(attr_ret, name, s, t, __VA_ARGS__) \
//     A_STRING_IMPL_STRING2_CONST(attr_ret, name, s, t, __VA_ARGS__)

// A_STRING_IMPL_BOTH_CONST(string_t, A_string, s, return A_strdup(s);)
// string_t A_STRING_MANGLE_SIZE_T(A_string)(size_t c) {
//     size_t cap = c;
//     if(cap < 7)
//         cap = 7;

//     string_t n;
//     n.__data = Z_Alloc(c + 1);
//     if(n.__data != NULL) {
//         n.__len = c;
//         n.__cap = cap;
//         n.__data[c] = '\0';
//     } else {
//         n.__len = 0;
//     }
//     return n;   
// }

// A_STRING_IMPL_STR    (const char*, A_cstr, s, return s->__data; )
// A_STRING_IMPL_STRING (      char*, A_cstr, s, return s->__data; )
// A_STRING_IMPL_LITERAL(const char*, A_cstr, s, return (const char*)s->__data; )

// A_STRING_IMPL_BOTH_CONST(size_t, A_strlen,   s, return s->__len; )
// A_STRING_IMPL_BOTH_CONST(bool,   A_strempty, s, return A_strlen(s) == 0; )

// size_t A_strcap(const string_t* A_RESTRICT s) {
//     return s->__cap;
// }

// char A_STRING_MANGLE_STR(A_strat)(const str_t* A_RESTRICT s, size_t i) {
//     if(i > A_strlen(s))
//         return '\0';

//     return A_cstr(s)[i];
// }

// char A_STRING_MANGLE_STRING(A_strat)(const string_t* A_RESTRICT s, size_t i) {
//     if(i > A_strlen(s))
//         return '\0';
    
//     return A_cstr(s)[i];
// }

// const char* A_STRING_MANGLE_STR(A_stratp)(const str_t* A_RESTRICT s, size_t i) {
//     if(i > A_strlen(s))
//         return NULL;
    
//     return &A_cstr(s)[i];
// }

// char* A_STRING_MANGLE_STRING(A_stratp)(string_t* A_RESTRICT s, size_t i) {
//     if(i > A_strlen(s))
//         return NULL;
    
//     return &A_cstr(s)[i];
// }

// const char* A_STRING_MANGLE_LITERAL(A_stratp)(
//     const string_t* A_RESTRICT s, size_t i
// ) {
//     return &A_cstr(s)[i];
// }

// bool A_STRING_MANGLE_STR(A_strncpy)(
//     string_t* A_RESTRICT dest, size_t dest_off, 
//     const str_t* A_RESTRICT src, size_t src_off, 
//     size_t n
// ) {
//     if(n > A_strlen(src) - src_off) 
//         n = A_strlen(src) - src_off;

//     if(dest_off + n > A_strlen(dest))
//         return false;

//     A_memcpy(A_stratp(dest, dest_off), A_stratp(src, src_off), n);

//     *A_stratp(dest, A_strlen(dest)) = '\0';

//     return true;
// }

// bool A_STRING_MANGLE_STRING(A_strncpy)(
//     string_t* A_RESTRICT dest, size_t dest_off, 
//     const string_t* A_RESTRICT src, size_t src_off, 
//     size_t n
// ) {
//     if(n > A_strlen(src) - src_off) 
//         n = A_strlen(src) - src_off;

//     if(dest_off + n > A_strlen(dest))
//         return false;

//     memcpy(A_stratp(dest, dest_off), A_stratp(src, src_off), n);

//     *A_stratp(dest, A_strlen(dest)) = '\0';

//     return true;
// }

// string_t A_STRING_MANGLE_STR(A_strdup)(const str_t* A_RESTRICT s) {
//     string_t n = A_string(A_strlen(s));
//     A_strncpy(&n, 0, s, 0, A_NPOS);
//     return n;
// }

// string_t A_STRING_MANGLE_STRING(A_strdup)(const string_t* A_RESTRICT s) {
//     string_t n = A_string(A_strlen(s));
//     A_strncpy(&n, 0, s, 0, A_NPOS);
//     return n;
// }

// string_t A_strmove(string_t* A_RESTRICT s) {
//     string_t n = *s;
//     s->__data = NULL;
//     s->__len  = 0;
//     s->__cap  = 0;
//     return n;
// }

// bool A_strext(string_t* A_RESTRICT s, size_t n) {
//     size_t newlen = A_strlen(s) + n;
//     if(newlen + 1 > A_strcap(s))
//         s->__data = Z_Realloc(s->__data, A_npow2(newlen + 1));
    
//     if(s->__data != NULL) {
//         s->__len += n;
//         return true;
//     } else {
//         s->__len = 0;
//         s->__cap = 0;
//         return false;
//     }
// }

// bool A_strpush(string_t* A_RESTRICT s, char c) {
//     if(!A_strext(s, 1))
//         return false;
    
//     *A_stratp(s, A_strlen(s) - 1) = c;
//     *A_stratp(s, A_strlen(s))     = '\0';

//     return true;
// }

// bool A_strshrnk(string_t* A_RESTRICT s, size_t n) {
//     size_t newlen = n >= A_strlen(s) ? 0 : A_strlen(s) - n;
//     if(newlen + 1 < A_ppow2(A_strcap(s)))
//         s->__data = Z_Realloc(s->__data, A_npow2(newlen + 1));
    
//     if(s->__data != NULL) {
//         s->__len -= n;
//         return true;
//     } else {
//         s->__len = 0;
//         s->__cap = 0;
//         return false;
//     }
// }

// char A_strpop(string_t* A_RESTRICT s) {
//     char c = A_strat(s, A_strlen(s) - 1);
//     *A_stratp(s, A_strlen(s) - 1) = '\0';

//     if(!A_strshrnk(s, 1))
//         return '\0';

//     return c;
// }

// bool A_STRING_MANGLE_STR(A_strcat)(
//     string_t* A_RESTRICT dest, const str_t* A_RESTRICT src
// ) {
//     size_t off = A_strlen(dest);

//     if(!A_strext(dest, A_strlen(src)))
//         return false;

//     A_strncpy(dest, off, src, 0, A_NPOS);
//     return true;
// }

// bool A_STRING_MANGLE_STRING(A_strcat)(
//     string_t* A_RESTRICT dest, const string_t* A_RESTRICT src
// ) {
//     size_t off = A_strlen(dest);

//     if(!A_strext(dest, A_strlen(src)))
//         return false;

//     A_strncpy(dest, off, src, 0, A_NPOS);
//     return true;
// }

// size_t A_STRING_MANGLE_STR(A_strchr)(
//     const str_t* A_RESTRICT s, char c, size_t off, size_t n
// ) {
//     if(n == A_NPOS)
//         n = A_strlen(s);

//     if(n == 0 || off + n > A_strlen(s))
//         return 0;
    
//     const char* p = (const char*)A_memchr(
//         A_cstr(s) + off, c, n - off
//     );
    
//     if(!p)
//         return A_NPOS;
//     return (size_t)(p - A_cstr(s));
// }

// size_t A_STRING_MANGLE_STRING(A_strchr)(
//     const string_t* A_RESTRICT s, char c, size_t off, size_t n
// ) {
//     if(n == A_NPOS)
//         n = A_strlen(s);

//     if(n == 0 || off + n > A_strlen(s))
//         return 0;
    
//     const char* p = (const char*)A_memchr(
//         A_cstr(s) + n, c, n - off
//     );
    
//     if(!p)
//         return A_NPOS;
//     return (size_t)(p - A_cstr(s));
// }

// size_t A_STRING_MANGLE_STR(A_strrchr)(
//     const str_t* A_RESTRICT s, char c, size_t off, size_t n
// ) {
//     if(n == A_NPOS)
//         n = A_strlen(s);

//     if(n == 0 || off - n > A_strlen(s) - off)
//         return 0;
    
//     const char* p = (const char*)A_memchr(
//         A_cstr(s) + A_strlen(s) - off, c, n - off
//     );
    
//     if(!p)
//         return A_NPOS;
//     return (size_t)(p - A_cstr(s));
// }

// size_t A_STRING_MANGLE_STRING(A_strrchr)(
//     const string_t* A_RESTRICT s, char c, size_t off, size_t n
// ) {
//     if(n == A_NPOS)
//         n = A_strlen(s);

//     if(n == 0 || off - n > A_strlen(s) - off)
//         return 0;
    
//     const char* p = (const char*)A_memchr(A_cstr(s), c, n - off);
//     if(!p)
//         return A_NPOS;
//     return (size_t)(p - A_cstr(s));
// }

// bool A_STRING_MANGLE_STR(A_strcont)(const str_t* A_RESTRICT s, char c) {
//     return A_strchr(s, c, 0, A_NPOS) != A_NPOS;
// }

// bool A_STRING_MANGLE_STRING(A_strcont)(const string_t* A_RESTRICT s, char c) {
//     return A_strchr(s, c, 0, A_NPOS) != A_NPOS;
// }

// A_STRING_IMPL_BOTH2_CONST(bool, A_strcmp, a, b, 
//     if(A_strlen(a) != A_strlen(b))
//         return false;

//     return strncmp(A_cstr(a), A_cstr(b), A_strlen(a)) == 0;
// )

// A_STRING_IMPL_BOTH2_CONST(bool, A_stricmp, a, b, 
//     if(A_strlen(a) != A_strlen(b))
//         return false;

//     char ca = '\0', cb = '\0';
//     //A_STR_ITER(a, ca)
//     for(size_t i = 0; i < A_strlen(a); i++) {
//         ca = A_strat(a, i);
//         //A_STR_ITER(b, cb)
//         for(size_t j = 0; j < A_strlen(b); j++) {
//             cb = A_strat(b, j);
//             if(A_tolower(ca) != A_tolower(cb)) return false;
//         }
//     }

//     return true;
// )

// A_STRING_IMPL_BOTH2_CONST(size_t, A_strpbrk, a, b, 
//     char ca = '\0', cb = '\0';
//     //size_t i = 0;
//     //A_STR_ENUMERATE(a, i, ca)
//     for(size_t i = 0; i < A_strlen(a); i++) {
//         ca = A_strat(a, i);
//         //A_STR_ITER(b, cb)
//         for(size_t j = 0; j < A_strlen(b); j++) {
//             cb = A_strat(b, j);
//             if(ca == cb) return i;
//         }
//     }

//     return A_NPOS;
// )

// A_STRING_IMPL_BOTH2_CONST(size_t, A_strrpbrk, a, b, 
//     char ca = '\0', cb = '\0';
//     //size_t i = 0;
//     //A_STR_ENUMERATE_REV(a, i, ca)
//     for(size_t i = A_strlen(a); i > 0; i--) {
//         ca = A_strat(a, i);
//         //A_STR_ITER_REV(b, cb)
//         for(size_t j = A_strlen(b); j > 0; j--) {
//             cb = A_strat(b, j);
//             if(ca == cb) return i; 
//         }
//     }

//     return A_NPOS;
// )

// A_STRING_IMPL_BOTH2_CONST(size_t, A_strpcnt, a, b,
//     char ca = '\0', cb = '\0';
//     //size_t i = 0;
//     //A_STR_ENUMERATE(a, i, ca)
//     for(size_t i = 0; i < A_strlen(a); i++) {
//         ca = A_strat(a, i);
//         //A_STR_ITER(b, cb)
//         for(size_t j = 0; j < A_strlen(b); j++) {
//             cb = A_strat(b, j);
//             if(ca != cb) return i; 
//         }
//     }

//     return A_NPOS;
// )


// A_STRING_IMPL_BOTH2_CONST(size_t, A_strrpcnt, a, b, 
//     char ca = '\0', cb = '\0';
//     //size_t i = 0;
//     //A_STR_ENUMERATE_REV(a, i, ca)
//     for(size_t i = A_strlen(a); i > 0; i--) {
//         ca = A_strat(a, i);
//         //A_STR_ITER_REV(b, cb)
//         for(size_t j = A_strlen(b); j > 0; j--) {
//             cb = A_strat(b, j);
//             if(ca == cb) return i; 
//         }
//     }

//     return A_NPOS;
// )

// A_STRING_IMPL_BOTH2_CONST(size_t, A_strstr, a, b, 
//     if(A_strlen(b) > A_strlen(a))
//         return A_NPOS;

//     if(A_strlen(b) == A_strlen(b))
//         return A_strcmp(a, b);

//     char c = A_strat(b, 0);
//     for(size_t i = 0; i < A_strlen(a) - A_strlen(b); i++) {
//         if(A_strat(a, i) == c) {
//             if(A_memcmp(A_cstr(a), A_cstr(b), A_strlen(b)) == 0)
//                 return i;
//         }
//     }

//     return A_NPOS;
// )

// A_STRING_IMPL_BOTH2_CONST(size_t, A_strrstr, a, b, {
//     if(A_strlen(b) > A_strlen(a))
//         return A_NPOS;

//     if(A_strlen(b) == A_strlen(b))
//         return A_strcmp(a, b);

//     char c = A_strat(b, 0);
//     for(size_t i = A_strlen(a); i > A_strlen(a) - A_strlen(b); i--) {
//         if(A_strat(a, i) == c) {
//             if(A_memcmp(A_cstr(a), A_cstr(b), A_strlen(b)) == 0)
//                 return i;
//         }
//     }

//     return A_NPOS;
// })

// str_t A_STRING_MANGLE_STR(A_substr)(
//     const str_t* A_RESTRICT s, size_t i, size_t len
// ) {
//     str_t n;

//     if(i >= A_strlen(s)) {
//         n.__data = NULL;
//         n.__len  = 0;
//         return n;
//     }

//     if(len >= A_strlen(s) - i)
//         len = A_strlen(s) - i;

//     n.__data = s->__data + i;
//     n.__len  = len;    
//     return n;
// }

// str_t A_STRING_MANGLE_STRING(A_substr)(
//     const string_t* A_RESTRICT s, size_t i, size_t len
// ) {
//     str_t n;

//     if(i >= A_strlen(s)) {
//         n.__data = NULL;
//         n.__len  = 0;
//         return n;
//     }

//     if(len >= A_strlen(s) - i)
//         len = A_strlen(s) - i;

//     n.__data = s->__data + i;
//     n.__len  = len;    
//     return n;
// }

// string_t A_STRING_MANGLE_STR(A_substring)(
//     const str_t* A_RESTRICT s, size_t i, size_t len
// ) {
//     string_t n;

//     if(i >= A_strlen(s)) {
//         n.__data = NULL;
//         n.__len  = 0;
//         return n;
//     }
    
//     if(len >= A_strlen(s) - i)
//         len = A_strlen(s) - i;

//     A_strext(&n, len);
//     A_strncpy(&n, 0, s, i, len);
//     return n;
// }

// string_t A_STRING_MANGLE_STRING(A_substring)(
//     const string_t* A_RESTRICT s, size_t i, size_t len
// ) {
//     string_t n;

//     if(i >= A_strlen(s)) {
//         n.__data = NULL;
//         n.__len  = 0;
//         return n;
//     }
    
//     if(len >= A_strlen(s) - i)
//         len = A_strlen(s) - i;

//     A_strext(&n, len);
//     A_strncpy(&n, 0, s, i, len);
//     return n;
// }

// size_t A_STRING_MANGLE_STR(A_strtok)(
//     const str_t* A_RESTRICT s, char delim, size_t n, str_t* toks
// ) {
//     if(n == 0)
//         return 0;

//     if(delim == '\0')
//         return 0;
    
//     size_t m = 0;
//     size_t off = 0, last_off = 0;
//     while((off = A_strchr(s, delim, off, A_NPOS)) != A_NPOS && m < n) {
//         if(off - last_off == 1) {
//             toks[m] = A_substr(s, last_off, off - last_off);
//             m++;
//         }
        
//         off++;
//         last_off = off;
//     }
    
//     return m;
// }

// size_t A_STRING_MANGLE_STRING(A_strtok)(
//     const string_t* A_RESTRICT s, char delim, size_t n, str_t* toks
// ) {
//     if(n == 0)
//         return 0;

//     if(delim == '\0')
//         return 0;
    
//     size_t m = 0;
//     size_t off = 0, last_off = 0;
//     while((off = A_strchr(s, delim, off, A_NPOS)) != A_NPOS && m < n) {
//         if(off - last_off == 1) {
//             toks[m] = A_substr(s, last_off, off - last_off);
//             m++;
//         }
        
//         off++;
//         last_off = off;
//     }
    
//     return m;
// }

// void A_strclear(string_t* A_RESTRICT s) {
//    *A_stratp(s, 0) = '\0';
//    s->__len = 0;
// }

// void A_strdrop(string_t* A_RESTRICT s) {
//     A_strshrnk(s, A_strlen(s) + 1);
// }
