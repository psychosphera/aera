#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
#include <stdint.h>

#include "acommon.h"

#define A_STR_ENUMERATE(s, i, c, body) \
    for(i = 0; i < A_strlen(s); i++) { c = A_strat(s, i); { body } }

#define A_STR_ITER(s, c, body) { \
        size_t __A_str_iter_i = 0; \
        A_STR_ENUMERATE(s, __A_str_iter_i, c, body); \
    }

#define A_STR_ENUMERATE_REV(s, i, c, body) \
    for(i = A_strlen(s); i > 0; i--) { c = A_strat(s, i); { body } }

#define A_STR_ITER_REV(s, c, body) { \
        size_t __A_str_iter_rev_i = 0; \
        A_STR_ENUMERATE_REV(s, __A_str_iter_rev_i, c, body); \
    }

A_EXTERN_C bool A_memcmp (
    const void* A_RESTRICT a, const void* A_RESTRICT b, size_t n
);
A_EXTERN_C void A_memcpy(
    void* A_RESTRICT dest, const void* A_RESTRICT src, size_t n
);
A_EXTERN_C void* A_memchr (const void* A_RESTRICT p, char c, size_t n);
A_EXTERN_C void* A_memrchr(const void* A_RESTRICT p, char c, size_t n);
A_EXTERN_C void  A_memset (      void* A_RESTRICT p, char c, size_t n);

typedef struct str_s {
    const char* A_RESTRICT __data;
    size_t                 __len;
} str_t;

typedef struct string_s {
    char* A_RESTRICT __data;
    size_t           __len;
    size_t           __cap;
} string_t;

#define A_NPOS SIZE_MAX

A_EXTERN_C str_t A_literal_internal(const char* s, size_t c);
#define A_literal(s) A_literal_internal(s, A_countof(s))

A_EXTERN_C str_t A_str(const string_t* A_RESTRICT s);

#define A_STRING_MANGLE_STR(name)           name##_Str
#define A_STRING_MANGLE_STRING(name)        name##_String
#define A_STRING_MANGLE_STR_STR(name)       name##_Str_Str
#define A_STRING_MANGLE_STR_STRING(name)    name##_Str_String
#define A_STRING_MANGLE_STRING_STR(name)    name##_String_Str
#define A_STRING_MANGLE_STRING_STRING(name) name##_String_String
#define A_STRING_MANGLE_SIZE_T(name)        name##_SizeT
#define A_STRING_MANGLE_LITERAL(name)       name##_StringC

#define A_STRING_DECLARE_STR(attr_ret, name, s, ...) \
    attr_ret A_STRING_MANGLE_STR(name) \
        (const str_t* A_RESTRICT s __VA_OPT__(,) __VA_ARGS__)

#define A_STRING_DECLARE_STRING(attr_ret, name, s, ...) \
    attr_ret A_STRING_MANGLE_STRING(name)( \
        string_t* A_RESTRICT s __VA_OPT__(,) __VA_ARGS__ \
    )

#define A_STRING_DECLARE_STR_STR(attr_ret, name, s, t, ...) \
    attr_ret A_STRING_MANGLE_STR_STR(name)( \
        const str_t* A_RESTRICT s, const str_t* A_RESTRICT t __VA_OPT__(,) \
        __VA_ARGS__ \
    )

#define A_STRING_DECLARE_STR_STRING(attr_ret, name, s, t, ...) \
    attr_ret A_STRING_MANGLE_STR_STRING(name)( \
        const str_t* A_RESTRICT s, const string_t* A_RESTRICT t __VA_OPT__(,) \
        __VA_ARGS__ \
    )

#define A_STRING_DECLARE_STR2(attr_ret, name, s, t, ...) \
    A_STRING_DECLARE_STR_STR(attr_ret, name, s, t, __VA_ARGS__); \
    A_STRING_DECLARE_STR_STRING(attr_ret, name, s, t, __VA_ARGS__)

#define A_STRING_DECLARE_STRING_STR(attr_ret, name, s, t, ...) \
    attr_ret A_STRING_MANGLE_STRING_STR(name)( \
        string_t* A_RESTRICT s, const str_t* A_RESTRICT t __VA_OPT__(,) \
        __VA_ARGS__ \
    )

#define A_STRING_DECLARE_STRING_STRING(attr_ret, name, s, t, ...) \
    attr_ret A_STRING_MANGLE_STRING_STRING(name)( \
        string_t* A_RESTRICT s, const string_t* A_RESTRICT t __VA_OPT__(,) \
        __VA_ARGS__ \
    )

#define A_STRING_DECLARE_STRING2(attr_ret, name, s, t, ...) \
    A_STRING_DECLARE_STRING_STR(attr_ret, name, s, t, __VA_ARGS__); \
    A_STRING_DECLARE_STRING_STRING(attr_ret, name, s, t, __VA_ARGS__)

#define A_STRING_DECLARE_STRING_CONST(attr_ret, name, s, ...) \
    attr_ret A_STRING_MANGLE_STRING(name)( \
        const string_t* A_RESTRICT s __VA_OPT__(,) __VA_ARGS__ \
    )

#define A_STRING_DECLARE_STRING_STR_CONST(attr_ret, name, s, t, ...) \
    attr_ret A_STRING_MANGLE_STRING_STR(name)( \
        const string_t* A_RESTRICT s, const str_t* A_RESTRICT t __VA_OPT__(,) \
        __VA_ARGS__ \
    )

#define A_STRING_DECLARE_STRING_STRING_CONST(attr_ret, name, s, t, ...) \
    attr_ret A_STRING_MANGLE_STRING_STRING(name)( \
        const string_t* A_RESTRICT s, \
        const string_t* A_RESTRICT t __VA_OPT__(,) __VA_ARGS__ \
    )

#define A_STRING_DECLARE_STRING2_CONST(attr_ret, name, s, t, ...) \
    A_STRING_DECLARE_STRING_STR_CONST(attr_ret, name, s, t, __VA_ARGS__); \
    A_STRING_DECLARE_STRING_STRING_CONST(attr_ret, name, s, t, __VA_ARGS__)

#define A_STRING_DECLARE_BOTH(attr_ret, name, s, ...) \
    A_STRING_DECLARE_STR(attr_ret, name, s __VA_OPT__(,) __VA_ARGS__); \
    A_STRING_DECLARE_STRING(attr_ret, name, s __VA_OPT__(,) __VA_ARGS__)

#define A_STRING_DECLARE_BOTH_CONST(attr_ret, name, s, ...) \
    A_STRING_DECLARE_STR(attr_ret, name, s __VA_OPT__(,) __VA_ARGS__); \
    A_STRING_DECLARE_STRING_CONST(attr_ret, name, s __VA_OPT__(,) __VA_ARGS__)

#define A_STRING_DECLARE_BOTH2(attr_ret, name, s, t, ...) \
    A_STRING_DECLARE_STR2(attr_ret, name, s, t __VA_OPT__(,) __VA_ARGS__); \
    A_STRING_DECLARE_STRING2_CONST(attr_ret, name, s, t __VA_OPT__(,) \
        __VA_ARGS__ \
    )

#define A_STRING_DECLARE_BOTH2_CONST(attr_ret, name, s, t, ...) \
    A_STRING_DECLARE_STR2(attr_ret, name, s, t __VA_OPT__(,) \
        __VA_ARGS__ \
    ); \
    A_STRING_DECLARE_STRING2_CONST(attr_ret, name, s, t __VA_OPT__(,) \
        __VA_ARGS__ \
    )

#define A_STRING_DECLARE_INTEGRAL(attr_ret, name, s, ...) \
    attr_ret A_STRING_MANGLE_SIZE_T(name)(size_t s __VA_OPT__(,) __VA_ARGS__)

#define A_STRING_DECLARE_LITERAL(attr_ret, name, s, ...) \
    attr_ret A_STRING_MANGLE_LITERAL(name)( \
        const string_t* A_RESTRICT s __VA_OPT__(,) __VA_ARGS__ \
    )

#define A_STRING_GENERIC_MATCH_BOTH(f) \
    A_GENERIC_MATCH_CONST(str_t*, A_STRING_MANGLE_STR(f)), \
    A_GENERIC_MATCH_CONST(string_t*, A_STRING_MANGLE_STRING(f))

#define A_STRING_GENERIC_MATCH_BOTH2(s, f) \
    A_GENERIC_MATCH_CONST(str_t*, (_Generic((s), \
        A_STRING_GENERIC_MATCH_BOTH(A_STRING_MANGLE_STR(f)))) \
    ), A_GENERIC_MATCH_CONST(string_t*, (_Generic((s), \
        A_STRING_GENERIC_MATCH_BOTH(A_STRING_MANGLE_STRING(f))))) \

#define A_STRING_GENERIC_BOTH(s, f) (_Generic((s), \
    A_STRING_GENERIC_MATCH_BOTH(f) \
))

#define A_STRING_GENERIC_BOTH2(s, t, f) (_Generic((s), \
    A_STRING_GENERIC_MATCH_BOTH2(t, f) \
))

#define A_STRING_GENERIC_MATCH_INTEGRAL(f) \
    A_GENERIC_MATCH_INTEGRAL(A_STRING_MANGLE_SIZE_T(f))

#ifdef __cplusplus
#define A_STRING_CXX_OVERLOAD_STR(attr_ret, name) \
    inline attr_ret name (const str_t* A_RESTRICT s) { \
        return A_STRING_MANGLE_STR(name)(s); \
    } 
#endif

#ifdef __cplusplus
#define A_STRING_CXX_OVERLOAD_STRING(attr_ret, name) \
    inline attr_ret name (string_t* A_RESTRICT s) { \
        return A_STRING_MANGLE_STRING(name)(s); \
    } 
#endif

#ifdef __cplusplus
#define A_STRING_CXX_OVERLOAD_STRING_CONST(attr_ret, name) \
    inline attr_ret name (const string_t* A_RESTRICT s) { \
        return A_STRING_MANGLE_STRING(name)(s); \
    } 
#endif

#ifdef __cplusplus
#define A_STRING_CXX_OVERLOAD_BOTH(attr_ret, name) \
    A_STRING_CXX_OVERLOAD_STR   (attr_ret, name) \
    A_STRING_CXX_OVERLOAD_STRING(attr_ret, name)
#endif

#ifdef __cplusplus
#define A_STRING_CXX_OVERLOAD_BOTH_CONST(attr_ret, name) \
    A_STRING_CXX_OVERLOAD_STR         (attr_ret, name) \
    A_STRING_CXX_OVERLOAD_STRING_CONST(attr_ret, name)
#endif

#ifdef __cplusplus
#define A_STRING_CXX_OVERLOAD_STRING2(attr_ret, name) \
    inline attr_ret name ( \
        string_t* A_RESTRICT s, const str_t* A_RESTRICT t \
    ) { \
        return A_STRING_MANGLE_STRING_STR(name)(s, t); \
    } \
    inline attr_ret name ( \
        string_t* A_RESTRICT s, const string_t* A_RESTRICT t \
    ) { \
        return A_STRING_MANGLE_STRING_STRING(name)(s, t); \
    } 
#endif

#ifdef __cplusplus
#define A_STRING_CXX_OVERLOAD_STRING2_CONST(attr_ret, name) \
    inline attr_ret name ( \
        const string_t* A_RESTRICT s, const str_t* A_RESTRICT t \
    ) { \
        return A_STRING_MANGLE_STRING_STR(name)(s, t); \
    } \
    inline attr_ret name ( \
        const string_t* A_RESTRICT s, const string_t* A_RESTRICT t \
    ) { \
        return A_STRING_MANGLE_STRING_STRING(name)(s, t); \
    } 
#endif

#ifdef __cplusplus
#define A_STRING_CXX_OVERLOAD_BOTH2(attr_ret, name) \
    inline attr_ret name ( \
        const str_t* A_RESTRICT s, const str_t* A_RESTRICT t \
    ) { \
        return A_STRING_MANGLE_STR_STR(name)(s, t); \
    } \
    inline attr_ret name ( \
        string_t* A_RESTRICT s, const str_t* A_RESTRICT t \
    ) { \
        return A_STRING_MANGLE_STRING_STR(name)(s, t); \
    } \
    inline attr_ret name ( \
        const str_t* A_RESTRICT s, const string_t* A_RESTRICT t \
    ) { \
        return A_STRING_MANGLE_STR_STRING(name)(s, t); \
    } \
    inline attr_ret name ( \
        string_t* A_RESTRICT s, const string_t* A_RESTRICT t \
    ) { \
        return A_STRING_MANGLE_STRING_STRING(name)(s, t); \
    }
#endif

#ifdef __cplusplus
#define A_STRING_CXX_OVERLOAD_BOTH2_CONST(attr_ret, name) \
    inline attr_ret name ( \
        const str_t* A_RESTRICT s, const str_t* A_RESTRICT t \
    ) { \
        return A_STRING_MANGLE_STR_STR(name)(s, t); \
    } \
    inline attr_ret name ( \
        const string_t* A_RESTRICT s, const str_t* A_RESTRICT t \
    ) { \
        return A_STRING_MANGLE_STRING_STR(name)(s, t); \
    } \
    inline attr_ret name ( \
        const str_t* A_RESTRICT s, const string_t* A_RESTRICT t \
    ) { \
        return A_STRING_MANGLE_STR_STRING(name)(s, t); \
    } \
    inline attr_ret name ( \
        const string_t* A_RESTRICT s, const string_t* A_RESTRICT t \
    ) { \
        return A_STRING_MANGLE_STRING_STRING(name)(s, t); \
    }
#endif

#ifdef __cplusplus
#define A_STRING_CXX_OVERLOAD_INTEGRAL(attr_ret, name) \
    inline attr_ret name (size_t n) { \
        return A_STRING_MANGLE_SIZE_T(name)(n); \
    } 
#endif

#ifdef __cplusplus
#define A_STRING_CXX_OVERLOAD_LITERAL(attr_ret, name) \
    inline attr_ret name (const char* s) { \
        return A_STRING_MANGLE_LITERAL(name)(s); \
    } 
#endif

A_STRING_DECLARE_BOTH_CONST(A_EXTERN_C string_t, A_string, s);
A_STRING_DECLARE_INTEGRAL  (A_EXTERN_C string_t, A_string, s);

#ifndef __cplusplus
#define A_string(s) (_Generic((s), \
    A_STRING_GENERIC_MATCH_INTEGRAL(A_string), \
    A_STRING_GENERIC_MATCH_BOTH(A_string) \
))(s)
#else
A_STRING_CXX_OVERLOAD_BOTH_CONST(string_t, A_string);
A_STRING_CXX_OVERLOAD_INTEGRAL(string_t, A_string);
#endif

A_STRING_DECLARE_STR    (A_EXTERN_C const char*, A_cstr, s);
A_STRING_DECLARE_STRING (A_EXTERN_C char*,       A_cstr, s);
A_STRING_DECLARE_LITERAL(A_EXTERN_C const char*, A_cstr, s);
#ifndef __cplusplus
#define A_cstr(s) (_Generic((s), \
    const str_t*:    A_STRING_MANGLE_STR    (A_cstr), \
          string_t*: A_STRING_MANGLE_STRING (A_cstr), \
    const string_t*: A_STRING_MANGLE_LITERAL(A_cstr) \
))(s)
#endif // __cplusplus

A_STRING_DECLARE_BOTH_CONST(A_EXTERN_C char, A_strat, s, size_t i);
#ifndef __cplusplus
#define A_strat(s, i) A_STRING_GENERIC_BOTH(s, A_strat)(s, i)
#else
inline char A_strat(const str_t* A_RESTRICT s, size_t i) { 
    return A_STRING_MANGLE_STR(A_strat)(s, i); 
};
inline char A_strat(const string_t* A_RESTRICT s, size_t i) { 
    return A_STRING_MANGLE_STRING(A_strat)(s, i); 
};
#endif // __cplusplus

A_STRING_DECLARE_STR    (A_EXTERN_C const char*, A_stratp, s, size_t i);
A_STRING_DECLARE_STRING (A_EXTERN_C       char*, A_stratp, s, size_t i);
A_STRING_DECLARE_LITERAL(A_EXTERN_C const char*, A_stratp, s, size_t i);
#ifndef __cplusplus
#define A_stratp(s, i) (_Generic((s), \
    A_GENERIC_MATCH_CONST(str_t*, A_STRING_MANGLE_STR(A_stratp)), \
          string_t*: A_STRING_MANGLE_STRING(A_stratp), \
    const string_t*: A_STRING_MANGLE_LITERAL(A_stratp) \
))(s, i)
#else
inline const char* A_stratp(const str_t* A_RESTRICT s, size_t i) { 
    return A_STRING_MANGLE_STR(A_stratp)(s, i); 
}
inline char* A_stratp(string_t* A_RESTRICT s, size_t i) { 
    return A_STRING_MANGLE_STRING(A_stratp)(s, i); 
}
inline const char* A_stratp(const string_t* A_RESTRICT s, size_t i) { 
    return A_STRING_MANGLE_LITERAL(A_stratp)(s, i); 
}
#endif // __cplusplus

A_STRING_DECLARE_BOTH_CONST(A_EXTERN_C size_t, A_strlen, s);
#ifndef __cplusplus
#define A_strlen(s) A_STRING_GENERIC_BOTH(s, A_strlen)(s)
#else
A_STRING_CXX_OVERLOAD_BOTH_CONST(size_t, A_strlen);
#endif // __cplusplus
       
A_EXTERN_C size_t A_strcap(const string_t* A_RESTRICT s);

A_EXTERN_C bool A_STRING_MANGLE_STR(A_strncpy)(
    string_t* A_RESTRICT dest, size_t dest_off, 
    const str_t* A_RESTRICT src, size_t src_off, 
    size_t n
);
A_EXTERN_C bool A_STRING_MANGLE_STRING(A_strncpy)(
    string_t* A_RESTRICT dest, size_t dest_off, 
    const string_t* A_RESTRICT src, size_t src_off,
    size_t n
);

#ifndef __cplusplus
#define A_strncpy(d, do, s, so, n) \
    A_STRING_GENERIC_BOTH(s, A_strncpy)(d, do, s, so, n)
#else 
inline bool A_strncpy(
    string_t* A_RESTRICT dest, size_t dest_off, 
    const str_t* A_RESTRICT src, size_t src_off, 
    size_t n
) {
    return A_STRING_MANGLE_STR(A_strncpy)(dest, dest_off, src, src_off, n);
}
inline bool A_strncpy(
    string_t* A_RESTRICT dest, size_t dest_off, 
    const string_t* A_RESTRICT src, size_t src_off, 
    size_t n
) {
    return A_STRING_MANGLE_STRING(A_strncpy)(dest, dest_off, src, src_off, n);
}
#endif // __cplusplus

A_STRING_DECLARE_BOTH_CONST(A_EXTERN_C string_t, A_strdup, s);
#ifndef __cplusplus
#define A_strdup(s) A_STRING_GENERIC_BOTH(s, A_strdup)(s)
#else
A_STRING_CXX_OVERLOAD_BOTH_CONST(string_t, A_strdup);
#endif // __cplusplus

A_EXTERN_C bool A_strext (string_t* A_RESTRICT s, size_t n);
A_EXTERN_C bool A_strpush(string_t* A_RESTRICT s, char   c);

A_EXTERN_C bool A_strshrnk(string_t* A_RESTRICT s, size_t n);
A_EXTERN_C char A_strpop  (string_t* A_RESTRICT s);

A_STRING_DECLARE_STRING2(A_EXTERN_C bool, A_strcat, s, t);
#ifndef __cplusplus
#define A_strcat(d, s) A_STRING_GENERIC_BOTH(s, A_strcat)(d, s)
#else
A_STRING_CXX_OVERLOAD_STRING2(bool, A_strcat)
#endif

A_STRING_DECLARE_BOTH_CONST(A_EXTERN_C size_t, A_strchr, 
    s, char c, size_t off, size_t n
);
#ifndef __cplusplus
#define A_strchr(s, c, off, n) A_STRING_GENERIC_BOTH(s, A_strchr)(s, c, off, n)
#else
inline size_t A_strchr(
    const str_t* A_RESTRICT s, char c, size_t off, size_t n
) { 
    return A_STRING_MANGLE_STR(A_strchr)(s, c, off, n);
} 
inline size_t A_strchr(
    const string_t* A_RESTRICT s, char c, size_t off, size_t n
) { 
    return A_STRING_MANGLE_STRING(A_strchr)(s, c, off, n); 
} 
#endif // __cplusplus

A_STRING_DECLARE_BOTH_CONST(A_EXTERN_C size_t, A_strrchr, 
    s, char c, size_t off, size_t n
);
#ifndef __cplusplus
#define A_strrchr(s, c) A_STRING_GENERIC_BOTH(s, A_strrchr)(s, c, off, n)
#else
inline size_t A_strrchr(
    const str_t* A_RESTRICT s, char c, size_t off, size_t n
) { 
    return A_STRING_MANGLE_STR(A_strrchr)(s, c, off, n); 
} 
inline size_t A_strrchr(
    const string_t* A_RESTRICT s, char c, size_t off, size_t n
) { 
    return A_STRING_MANGLE_STRING(A_strrchr)(s, c, off, n); 
} 
#endif // __cplusplus

A_STRING_DECLARE_BOTH_CONST(A_EXTERN_C bool, A_strcont, s, char c);
#ifndef __cplusplus
#define A_strcont(s, c) A_STRING_GENERIC_BOTH(s, A_strcont)(s, c)
#endif

A_STRING_DECLARE_BOTH2_CONST(A_EXTERN_C bool, A_strcmp, a, b);
#ifndef __cplusplus
#define A_strcmp(a, b) A_STRING_GENERIC_BOTH2(a, b, A_strcmp)(a, b)
#else
A_STRING_CXX_OVERLOAD_BOTH2_CONST(bool, A_strcmp)
#endif // __cplusplus

A_STRING_DECLARE_BOTH2_CONST(A_EXTERN_C bool, A_stricmp, a, b);
#ifndef __cplusplus
#define A_stricmp(a, b) A_STRING_GENERIC_BOTH2(a, b, A_stricmp)(a, b)
#else
A_STRING_CXX_OVERLOAD_BOTH2_CONST(bool, A_stricmp)
#endif // __cplusplus

A_STRING_DECLARE_BOTH2_CONST(A_EXTERN_C size_t, A_strpbrk, a, b);
#ifndef __cplusplus
#define A_strpbrk(a, b) A_STRING_GENERIC_BOTH2(a, b, A_strpbrk)(a, b)
#else
A_STRING_CXX_OVERLOAD_BOTH2_CONST(size_t, A_strpbrk)
#endif // __cplusplus

A_STRING_DECLARE_BOTH2_CONST(A_EXTERN_C size_t, A_strrpbrk, a, b);
#ifndef __cplusplus
#define A_strrpbrk(a, b) A_STRING_GENERIC_BOTH2(a, b, A_strrpbrk)(a, b)
#else
A_STRING_CXX_OVERLOAD_BOTH2_CONST(size_t, A_strrpbrk)
#endif // __cplusplus

A_STRING_DECLARE_BOTH2_CONST(A_EXTERN_C size_t, A_strpcnt, a, b);
#ifndef __cplusplus
#define A_strpcnt(a, b) A_STRING_GENERIC_BOTH2(a, b, A_strpcnt)(a, b)
#else
A_STRING_CXX_OVERLOAD_BOTH2_CONST(size_t, A_strpcnt)
#endif // __cplusplus

A_STRING_DECLARE_BOTH2_CONST(A_EXTERN_C size_t, A_strrpcnt, a, b);
#ifndef __cplusplus
#define A_strrpcnt(a, b) A_STRING_GENERIC_BOTH2(a, b, A_strrpcnt)(a, b)
#else
A_STRING_CXX_OVERLOAD_BOTH2_CONST(size_t, A_strrpcnt)
#endif // __cplusplus

A_STRING_DECLARE_BOTH2_CONST(A_EXTERN_C size_t, A_strstr, a, b);
#ifndef __cplusplus
#define A_strstr(a, b) A_STRING_GENERIC_BOTH2(a, b, A_strstr)(a, b)
#else
A_STRING_CXX_OVERLOAD_BOTH2_CONST(size_t, A_strstr)
#endif // __cplusplus

A_STRING_DECLARE_BOTH2_CONST(A_EXTERN_C size_t, A_strrstr, a, b);
#ifndef __cplusplus
#define A_strrstr(a, b) A_STRING_GENERIC_BOTH2(a, b, A_strrstr)(a, b)
#else
A_STRING_CXX_OVERLOAD_BOTH2_CONST(size_t, A_strrstr)
#endif // __cplusplus

A_STRING_DECLARE_BOTH_CONST(
    A_EXTERN_C str_t, A_substr, s, size_t i, size_t len
);
#ifndef __cplusplus
#define A_substr(s, i, n) A_STRING_GENERIC_BOTH(s, A_substr)(s, i, n)
#else
inline str_t A_substr(const str_t* A_RESTRICT s, size_t i, size_t len) { 
    return A_STRING_MANGLE_STR(A_substr)(s, i, len); 
}
inline str_t A_substr(const string_t* A_RESTRICT s, size_t i, size_t len) {
    return A_STRING_MANGLE_STRING(A_substr)(s, i, len); 
}
#endif // __cplusplus

A_STRING_DECLARE_BOTH_CONST(
    A_EXTERN_C string_t, A_substring, s, size_t i, size_t len
);
#ifndef __cplusplus
#define A_substring(s, i, n) A_STRING_GENERIC_BOTH(s, A_substring)(s, i, n)
#else
inline string_t A_substring(const str_t* A_RESTRICT s, size_t i, size_t len) {
    return A_STRING_MANGLE_STR(A_substring)(s, i, len); 
}
inline string_t A_substring(
    const string_t* A_RESTRICT s, size_t i, size_t len
) { 
    return A_STRING_MANGLE_STRING(A_substring)(s, i, len); 
}
#endif // __cplusplus

A_STRING_DECLARE_BOTH_CONST(
    A_EXTERN_C size_t, A_strtok, s, char delim, size_t n, str_t* toks
);
#ifndef __cplusplus
#define A_strtok(s, d, n, t) A_STRING_GENERIC_BOTH(s, A_strtok)(s, d, n, t)
#else
inline size_t A_strtok(
    const str_t* A_RESTRICT s, char delim, size_t n, str_t* toks
) {
    return A_STRING_MANGLE_STR(A_strtok)(s, delim, n, toks); 
}
inline size_t A_strtok(
    const string_t* A_RESTRICT s, char delim, size_t n, str_t* toks
) {
    return A_STRING_MANGLE_STRING(A_strtok)(s, delim, n, toks); 
}
#endif // __cplusplus

A_EXTERN_C void A_strclear(string_t* A_RESTRICT s);
A_EXTERN_C void A_strdrop (string_t* A_RESTRICT s);

