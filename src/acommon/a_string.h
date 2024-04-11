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

A_EXTERN_C int   A_memcmp (const void* a,    const void* b,   size_t n);
A_EXTERN_C void* A_memcpy (      void* dest, const void* src, size_t n);
A_EXTERN_C void* A_memchr (const void* p,    int c,           size_t n);
A_EXTERN_C void* A_memrchr(const void* p,    int c,           size_t n);
 
A_EXTERN_C void* A_memset (      void* p,    int c,           size_t n);

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

#define A_STRING_DECLARE_STR(attr_ret, name, s, ...) \
    attr_ret name##_Str(const str_t* A_RESTRICT s __VA_OPT__(,) __VA_ARGS__)

#define A_STRING_DECLARE_STR2(attr_ret, name, s, t, ...) \
    A_STRING_DECLARE_STR( \
        attr_ret, name##_Str, s, const str_t* A_RESTRICT t __VA_OPT__(,) __VA_ARGS__ \
    ); \
    A_STRING_DECLARE_STRING( \
        attr_ret, name##_Str, s, const str_t* A_RESTRICT t __VA_OPT__(,) __VA_ARGS__ \
    )

#define A_STRING_DECLARE_STRING(attr_ret, name, s, ...) \
    attr_ret name##_String( \
        string_t* A_RESTRICT s __VA_OPT__(,) __VA_ARGS__ \
    )

#define A_STRING_DECLARE_STRING2(attr_ret, name, s, t, ...) \
    A_STRING_DECLARE_STR( \
        attr_ret, name##_String, s, string_t* A_RESTRICT t __VA_OPT__(,) __VA_ARGS__ \
    ); \
    A_STRING_DECLARE_STRING( \
        attr_ret, name##_String, s, string_t* A_RESTRICT t __VA_OPT__(,) __VA_ARGS__ \
    )

#define A_STRING_DECLARE_STRING_CONST(attr_ret, name, s, ...) \
    attr_ret name##_String( \
        const string_t* A_RESTRICT s __VA_OPT__(,) __VA_ARGS__ \
    )

#define A_STRING_DECLARE_STRING2_CONST(attr_ret, name, s, t, ...) \
    A_STRING_DECLARE_STR( \
        attr_ret, name##_String, s, const string_t* A_RESTRICT t __VA_OPT__(,) __VA_ARGS__ \
    ); \
    A_STRING_DECLARE_STRING_CONST( \
        attr_ret, name##_String, s, const string_t* A_RESTRICT t __VA_OPT__(,) __VA_ARGS__ \
    )

#define A_STRING_DECLARE_BOTH(attr_ret, name, s, ...) \
    A_STRING_DECLARE_STR(attr_ret, name, s __VA_OPT__(,) __VA_ARGS__); \
    A_STRING_DECLARE_STRING(attr_ret, name, s __VA_OPT__(,) __VA_ARGS__)

#define A_STRING_DECLARE_BOTH_CONST(attr_ret, name, s, ...) \
    A_STRING_DECLARE_STR(attr_ret, name, s __VA_OPT__(,) __VA_ARGS__); \
    A_STRING_DECLARE_STRING_CONST(attr_ret, name, s __VA_OPT__(,) __VA_ARGS__)

#define A_STRING_DECLARE_BOTH2(attr_ret, name, s, t, ...) \
    A_STRING_DECLARE_STR2(attr_ret, name, s, t __VA_OPT__(,) __VA_ARGS__); \
    A_STRING_DECLARE_STRING2(attr_ret, name, s, t __VA_OPT__(,) __VA_ARGS__)

#define A_STRING_DECLARE_BOTH2_CONST(attr_ret, name, s, t, ...) \
    A_STRING_DECLARE_STR2(attr_ret, name, s, t __VA_OPT__(,) __VA_ARGS__); \
    A_STRING_DECLARE_STRING2_CONST(attr_ret, name, s, t __VA_OPT__(,) __VA_ARGS__)

#define A_STRING_DECLARE_INTEGRAL(attr_ret, name, s, ...) \
    attr_ret name##_SizeT(size_t s __VA_OPT__(,) __VA_ARGS__)

#define A_STRING_DECLARE_LITERAL(attr_ret, name, s, ...) \
    attr_ret name##_StringC(const string_t* A_RESTRICT s __VA_OPT__(,) __VA_ARGS__)

#define A_STRING_GENERIC_MATCH_BOTH(f) \
    A_GENERIC_MATCH_CONST(str_t*, f##_Str), \
    A_GENERIC_MATCH_CONST(string_t*, f##_String)

#define A_STRING_GENERIC_MATCH_BOTH2(s, f) \
    A_GENERIC_MATCH_CONST(str_t*, (_Generic((s), \
        A_STRING_GENERIC_MATCH_BOTH(f##_Str))) \
    ), A_GENERIC_MATCH_CONST(string_t*, (_Generic((s), \
        A_STRING_GENERIC_MATCH_BOTH(f##_String)))) \

#define A_STRING_GENERIC_BOTH(s, f) (_Generic((s), \
    A_STRING_GENERIC_MATCH_BOTH(f) \
))

#define A_STRING_GENERIC_BOTH2(s, t, f) (_Generic((s), \
    A_STRING_GENERIC_MATCH_BOTH2(t, f) \
))

#define A_STRING_GENERIC_MATCH_INTEGRAL(f) A_GENERIC_MATCH_INTEGRAL(f##_SizeT)

A_STRING_DECLARE_BOTH_CONST(A_EXTERN_C string_t, A_string, s);
A_STRING_DECLARE_INTEGRAL(A_EXTERN_C string_t, A_string, s);

#ifndef __cplusplus
#define A_string(s) (_Generic((s), \
    A_STRING_GENERIC_MATCH_INTEGRAL(A_string), \
    A_STRING_GENERIC_MATCH_BOTH(A_string) \
))(s)
#else
inline string_t A_string(const str_t* A_RESTRICT s) { 
    return A_string_Str(s); 
}
inline string_t A_string(const string_t* A_RESTRICT s) {
    return A_string_String(s);
}
inline string_t A_string(size_t c) { 
    return A_string_SizeT(c); 
}
#endif

A_STRING_DECLARE_STR(A_EXTERN_C const char*, A_cstr, s);
A_STRING_DECLARE_STRING(A_EXTERN_C char*, A_cstr, s);
A_STRING_DECLARE_LITERAL(A_EXTERN_C const char*, A_cstr, s);

#ifndef __cplusplus
#define A_cstr(s) (_Generic((s), \
    const str_t*:    A_cstr_Str, \
          string_t*: A_cstr_String, \
    const string_t*: A_cstr_StringC \
))(s)
#endif // __cplusplus

A_STRING_DECLARE_BOTH_CONST(A_EXTERN_C char, A_strat, s, size_t i);

#ifndef __cplusplus
#define A_strat(s, i) (_Generic((s), \
          str_t*:    A_strat_Str, \
    const str_t*:    A_strat_Str, \
          string_t*: A_strat_String, \
    const string_t*: A_strat_String \
))(s, i)
#else
inline char A_strat(const str_t* A_RESTRICT s, size_t i) { 
    return A_strat_Str(s, i); 
};
inline char A_strat(const string_t* A_RESTRICT s, size_t i) { 
    return A_strat_String(s, i); 
};
#endif // __cplusplus

A_STRING_DECLARE_STR(A_EXTERN_C const char*, A_stratp, s, size_t i);
A_STRING_DECLARE_STRING(A_EXTERN_C char*, A_stratp, s, size_t i);
A_STRING_DECLARE_LITERAL(A_EXTERN_C const char*, A_stratp, s, size_t i);

#ifndef __cplusplus
#define A_stratp(s, i) (_Generic((s), \
          str_t*:    A_stratp_Str, \
    const str_t*:    A_stratp_Str, \
          string_t*: A_stratp_String, \
    const string_t*: A_stratp_StringC \
))(s, i)
#else
inline const char* A_stratp(const str_t* A_RESTRICT s, size_t i) { 
    return A_stratp_Str(s, i); 
}
inline char* A_stratp(string_t* A_RESTRICT s, size_t i) { 
    return A_stratp_String(s, i); 
}
inline const char* A_stratp(const string_t* A_RESTRICT s, size_t i) { 
    return A_stratp_StringC(s, i); 
}
#endif // __cplusplus

A_STRING_DECLARE_BOTH_CONST(A_EXTERN_C size_t, A_strlen, s);

#ifndef __cplusplus
#define A_strlen(s) A_STRING_GENERIC_BOTH(s, A_strlen)(s)
#else
inline size_t A_strlen(const str_t* A_RESTRICT s) { 
    return A_strlen_Str(s);    
} 
inline size_t A_strlen(const string_t* A_RESTRICT s) { 
    return A_strlen_String(s);
}
#endif // __cplusplus
       
A_EXTERN_C size_t A_strcap(const string_t* A_RESTRICT s);

A_EXTERN_C bool A_strncpy_Str(
    string_t* A_RESTRICT dest, size_t dest_off, 
    const str_t* A_RESTRICT src, size_t src_off, 
    size_t n
);
A_EXTERN_C bool A_strncpy_String(
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
    return A_strncpy_Str(dest, dest_off, src, src_off, n);
}
inline bool A_strncpy(
    string_t* A_RESTRICT dest, size_t dest_off, 
    const string_t* A_RESTRICT src, size_t src_off, 
    size_t n
) {
    return A_strncpy_String(dest, dest_off, src, src_off, n);
}
#endif // __cplusplus

A_STRING_DECLARE_BOTH_CONST(A_EXTERN_C string_t, A_strdup, s);

#ifndef __cplusplus
#define A_strdup(s) A_STRING_GENERIC_BOTH(s, A_strdup)(s)
#else
inline string_t A_strdup(const str_t* A_RESTRICT s) { 
    return A_strdup_Str(s);
}
inline string_t A_strdup(const string_t* A_RESTRICT s) {
    return A_strdup_String(s);
} 
#endif // __cplusplus

A_EXTERN_C bool A_strext (string_t* A_RESTRICT s, size_t n);
A_EXTERN_C bool A_strpush(string_t* A_RESTRICT s, char   c);

A_EXTERN_C bool A_strshrnk(string_t* A_RESTRICT s, size_t n);
A_EXTERN_C char A_strpop  (string_t* A_RESTRICT s);

A_EXTERN_C bool A_strcat_Str(
    string_t* A_RESTRICT dest, const str_t* A_RESTRICT src
);
A_EXTERN_C bool A_strcat_String(
    string_t* A_RESTRICT dest, const string_t* A_RESTRICT src
);

#ifndef __cplusplus
#define A_strcat(d, s) A_STRING_GENERIC_BOTH(s, A_strcat)(d, s)
#else
inline bool A_strcat(string_t* A_RESTRICT dest, const str_t* A_RESTRICT src) { 
    return A_strcat_Str(dest, src); 
} 
inline bool A_strcat(
    string_t* A_RESTRICT dest, const string_t* A_RESTRICT src
) { 
    return A_strcat_String(dest, src); 
} 
#endif

A_STRING_DECLARE_BOTH_CONST(A_EXTERN_C size_t, A_strchr, s, char c);

#ifndef __cplusplus
#define A_strchr(s, c) A_STRING_GENERIC_BOTH(s, A_strchr)(s, c)
#else
inline size_t A_strchr(const str_t* A_RESTRICT s, char c) { 
    return A_strchr_Str(s, c); 
} 
inline size_t A_strchr(const string_t* A_RESTRICT s, char c) { 
    return A_strchr_String(s, c); 
} 
#endif // __cplusplus

A_STRING_DECLARE_BOTH_CONST(A_EXTERN_C size_t, A_strrchr, s, char c);

#ifndef __cplusplus
#define A_strrchr(s, c) A_STRING_GENERIC_BOTH(s, A_strrchr)(s, c)
#else
inline size_t A_strrchr(const str_t* A_RESTRICT s, char c) { 
    return A_strrchr_Str(s, c); 
} 
inline size_t A_strrchr(const string_t* A_RESTRICT s, char c) { 
    return A_strrchr_String(s, c); 
} 
#endif // __cplusplus

A_STRING_DECLARE_BOTH_CONST(A_EXTERN_C bool, A_strcont, s, char c);

#ifndef __cplusplus
#define A_strcont(s, c) A_STRING_GENERIC_BOTH(s, A_strcont)(s, c)
#endif

A_STRING_DECLARE_BOTH2_CONST(A_EXTERN_C bool, A_streq, a, b);

#ifndef __cplusplus
#define A_streq(a, b) A_STRING_GENERIC_BOTH2(a, b, A_streq)(a, b)
#else
inline bool A_streq(const str_t* A_RESTRICT a, const str_t* A_RESTRICT b) { 
    return A_streq_Str_Str(a, b); 
}
inline bool A_streq(const str_t* A_RESTRICT a, const string_t* A_RESTRICT b) {
    return A_streq_Str_String(a, b); 
}
inline bool A_streq(const string_t* A_RESTRICT a, const str_t* A_RESTRICT b) {
    return A_streq_String_Str(a, b); 
}
inline bool A_streq(
    const string_t* A_RESTRICT a, const string_t* A_RESTRICT b
) { 
    return A_streq_String_String(a, b); 
}
#endif // __cplusplus

A_STRING_DECLARE_BOTH2_CONST(A_EXTERN_C bool, A_strieq, a, b);

#ifndef __cplusplus
#define A_strieq(a, b) A_STRING_GENERIC_BOTH2(a, b, A_strieq)(a, b)
#else
inline bool A_strieq(const str_t* A_RESTRICT a, const str_t* A_RESTRICT b) { 
    return A_strieq_Str_Str(a, b); 
}
inline bool A_strieq(const str_t* A_RESTRICT a, const string_t* A_RESTRICT b) {
    return A_strieq_Str_String(a, b); 
}
inline bool A_strieq(const string_t* A_RESTRICT a, const str_t* A_RESTRICT b) {
    return A_strieq_String_Str(a, b); 
}
inline bool A_strieq(
    const string_t* A_RESTRICT a, const string_t* A_RESTRICT b
) { 
    return A_strieq_String_String(a, b); 
}
#endif // __cplusplus

A_STRING_DECLARE_BOTH2_CONST(A_EXTERN_C size_t, A_strpbrk, a, b);

#ifndef __cplusplus
#define A_strpbrk(a, b) A_STRING_GENERIC_BOTH2(a, b, A_strpbrk)(a, b)
#else
inline size_t A_strpbrk(const str_t* A_RESTRICT a, const str_t* A_RESTRICT b) {
    return A_strpbrk_Str_Str(a, b); 
}
inline size_t A_strpbrk(
    const str_t* A_RESTRICT a, const string_t* A_RESTRICT b
) { 
    return A_strpbrk_Str_String(a, b); 
}
inline size_t A_strpbrk(
    const string_t* A_RESTRICT a, const str_t* A_RESTRICT b
) { 
    return A_strpbrk_String_Str(a, b); 
}
inline size_t A_strpbrk(
    const string_t* A_RESTRICT a, const string_t* A_RESTRICT b
) { 
    return A_strpbrk_String_String(a, b); 
}
#endif // __cplusplus

A_STRING_DECLARE_BOTH2_CONST(A_EXTERN_C size_t, A_strrpbrk, a, b);

#ifndef __cplusplus
#define A_strrpbrk(a, b) A_STRING_GENERIC_BOTH2(a, b, A_strrpbrk)(a, b)
#else
inline size_t A_strrpbrk(const str_t* A_RESTRICT a, const str_t* A_RESTRICT b) { 
    return A_strrpbrk_Str_Str(a, b); 
}
inline size_t A_strrpbrk(
    const str_t* A_RESTRICT a, const string_t* A_RESTRICT b
) { 
    return A_strrpbrk_Str_String(a, b); 
}
inline size_t A_strrpbrk(
    const string_t* A_RESTRICT a, const str_t* A_RESTRICT b
) { 
    return A_strrpbrk_String_Str(a, b); 
}
inline size_t A_strrpbrk(
    const string_t* A_RESTRICT a, const string_t* A_RESTRICT b
) { 
    return A_strrpbrk_String_String(a, b); 
}
#endif // __cplusplus

A_STRING_DECLARE_BOTH2_CONST(A_EXTERN_C size_t, A_strpcnt, a, b);

#ifndef __cplusplus
#define A_strpcnt(a, b) A_STRING_GENERIC_BOTH2(a, b, A_strpcnt)(a, b)
#else
inline size_t A_strpcnt(const str_t* A_RESTRICT a, const str_t* A_RESTRICT b) {
    return A_strpcnt_Str_Str(a, b); 
}
inline size_t A_strpcnt(
    const str_t* A_RESTRICT a, const string_t* A_RESTRICT b
) { 
    return A_strpcnt_Str_String(a, b); 
}
inline size_t A_strpcnt(
    const string_t* A_RESTRICT a, const str_t* A_RESTRICT b
) { 
    return A_strpcnt_String_Str(a, b); 
}
inline size_t A_strpcnt(
    const string_t* A_RESTRICT a, const string_t* A_RESTRICT b
) { 
    return A_strpcnt_String_String(a, b); 
}
#endif // __cplusplus

A_STRING_DECLARE_BOTH2_CONST(A_EXTERN_C size_t, A_strrpcnt, a, b);

#ifndef __cplusplus
#define A_strrpcnt(a, b) A_STRING_GENERIC_BOTH2(a, b, A_strrpcnt)(a, b)
#else
inline size_t A_strrpcnt(
    const str_t* A_RESTRICT a, const str_t* A_RESTRICT b
) { 
    return A_strrpcnt_Str_Str(a, b); 
}
inline size_t A_strrpcnt(
    const str_t* A_RESTRICT a, const string_t* A_RESTRICT b
) { 
    return A_strrpcnt_Str_String(a, b); 
}
inline size_t A_strrpcnt(
    const string_t* A_RESTRICT a, const str_t* A_RESTRICT b
) { 
    return A_strrpcnt_String_Str(a, b); 
}
inline size_t A_strrpcnt(
    const string_t* A_RESTRICT a, const string_t* A_RESTRICT b
) { 
    return A_strrpcnt_String_String(a, b); 
}
#endif // __cplusplus

A_STRING_DECLARE_BOTH2_CONST(A_EXTERN_C size_t, A_strstr, a, b);

#ifndef __cplusplus
#define A_strstr(a, b) A_STRING_GENERIC_BOTH2(a, b, A_strstr)(a, b)
#else
inline size_t A_strstr(const str_t* A_RESTRICT a, const str_t* A_RESTRICT b) { 
    return A_strstr_Str_Str(a, b); 
}
inline size_t A_strstr(
    const str_t* A_RESTRICT a, const string_t* A_RESTRICT b
) { 
    return A_strstr_Str_String(a, b); 
}
inline size_t A_strstr(
    const string_t* A_RESTRICT a, const str_t* A_RESTRICT b
) { 
    return A_strstr_String_Str(a, b); 
}
inline size_t A_strstr(
    const string_t* A_RESTRICT a, const string_t* A_RESTRICT b
) { 
    return A_strstr_String_String(a, b); 
}
#endif // __cplusplus

A_STRING_DECLARE_BOTH2_CONST(A_EXTERN_C size_t, A_strrstr, a, b);

#ifndef __cplusplus
#define A_strrstr(a, b) A_STRING_GENERIC_BOTH2(a, b, A_strrstr)(a, b)
#else
inline bool A_strrstr(const str_t* A_RESTRICT a, const str_t* A_RESTRICT b) {
    return A_strrstr_Str_Str(a, b); 
}
inline bool A_strrstr(
    const str_t* A_RESTRICT a, const string_t* A_RESTRICT b
) {
    return A_strrstr_Str_String(a, b); 
}
inline bool A_strrstr(
    const string_t* A_RESTRICT a, const str_t* A_RESTRICT b
) { 
    return A_strrstr_String_Str(a, b); 
}
inline bool A_strrstr(
    const string_t* A_RESTRICT a, const string_t* A_RESTRICT b
) { 
    return A_strrstr_String_String(a, b); 
}
#endif // __cplusplus

A_STRING_DECLARE_BOTH_CONST(A_EXTERN_C str_t, A_substr, s, size_t i, size_t len);

#ifndef __cplusplus
#define A_substr(s, i, n) A_STRING_GENERIC_BOTH(s, A_substr)(s, i, n)
#else
inline str_t A_substr(const str_t* A_RESTRICT s, size_t i, size_t len) { 
    return A_substr_Str(s, i, len); 
}
inline str_t A_substr(const string_t* A_RESTRICT s, size_t i, size_t len) {
    return A_substr_String(s, i, len); 
}
#endif // __cplusplus

A_STRING_DECLARE_BOTH_CONST(A_EXTERN_C string_t, A_substring, s, size_t i, size_t len);

#ifndef __cplusplus
#define A_substring(s, i, n) A_STRING_GENERIC_BOTH(s, A_substring)(s, i, n)
#else
inline string_t A_substring(const str_t* A_RESTRICT s, size_t i, size_t len) {
    return A_substring_Str(s, i, len); 
}
inline string_t A_substring(
    const string_t* A_RESTRICT s, size_t i, size_t len
) { 
    return A_substring_String(s, i, len); 
}
#endif // __cplusplus

A_EXTERN_C void A_strclear(string_t* A_RESTRICT s);
A_EXTERN_C void A_strdrop (string_t* A_RESTRICT s);

