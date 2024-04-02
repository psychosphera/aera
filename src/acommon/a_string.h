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

EXTERN_C int   A_memcmp (const void* a,    const void* b,   size_t n);
EXTERN_C void* A_memcpy (      void* dest, const void* src, size_t n);
EXTERN_C void* A_memchr (const void* p,    int c,           size_t n);
EXTERN_C void* A_memrchr(const void* p,    int c,           size_t n);
 
EXTERN_C void* A_memset (      void* p,    int c,           size_t n);

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

EXTERN_C str_t A_literal_internal(const char* s, size_t c);
#define A_literal(s) A_literal_internal(s, A_countof(s))

EXTERN_C str_t A_str(const string_t* A_RESTRICT s);

EXTERN_C string_t A_string_Str   (const str_t*    A_RESTRICT s);
EXTERN_C string_t A_string_String(const string_t* A_RESTRICT s);
EXTERN_C string_t A_string_SizeT (      size_t               c);

#ifndef __cplusplus
#define A_string(s) (_Generic((s), \
          int:       A_string_SizeT, \
          size_t:    A_string_SizeT, \
          str_t*:    A_string_Str, \
    const str_t*:    A_string_Str, \
          string_t*: A_string_String, \
    const string_t*: A_string_String \
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

EXTERN_C const char* A_cstr_Str    (const str_t*    A_RESTRICT s);
EXTERN_C       char* A_cstr_String (      string_t* A_RESTRICT s);
EXTERN_C const char* A_cstr_StringC(const string_t* A_RESTRICT s);

#ifndef __cplusplus
#define A_cstr(s) (_Generic((s), \
    const str_t*:    A_cstr_Str, \
          string_t*: A_cstr_String, \
    const string_t*: A_cstr_StringC \
))(s)
#endif // __cplusplus

EXTERN_C char A_strat_Str   (const str_t*    A_RESTRICT s, size_t i);
EXTERN_C char A_strat_String(const string_t* A_RESTRICT s, size_t i);

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

EXTERN_C const char* A_stratp_Str    (const str_t*    A_RESTRICT s, size_t i);
EXTERN_C       char* A_stratp_String (      string_t* A_RESTRICT s, size_t i);
EXTERN_C const char* A_stratp_StringC(const string_t* A_RESTRICT s, size_t i);

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
       
EXTERN_C size_t A_strlen_Str   (const str_t* A_RESTRICT    s);
EXTERN_C size_t A_strlen_String(const string_t* A_RESTRICT s);

#ifndef __cplusplus
#define A_strlen(s) (_Generic((s), \
          str_t*:    A_strlen_Str, \
    const str_t*:    A_strlen_Str, \
          string_t*: A_strlen_String, \
    const string_t*: A_strlen_String \
))(s)
#else
inline size_t A_strlen(const str_t* A_RESTRICT s) { 
    return A_strlen_Str(s);    
} 
inline size_t A_strlen(const string_t* A_RESTRICT s) { 
    return A_strlen_String(s);
}
#endif // __cplusplus
       
EXTERN_C size_t A_strcap(const string_t* A_RESTRICT s);

EXTERN_C bool A_strcpyz_Str(
    string_t* A_RESTRICT dest, size_t dest_off, 
    const str_t* A_RESTRICT src, size_t src_off, 
    size_t n
);
EXTERN_C bool A_strcpyz_String(
    string_t* A_RESTRICT dest, size_t dest_off, 
    const string_t* A_RESTRICT src, size_t src_off,
    size_t n
);

#ifndef __cplusplus
#define A_strcpyz(d, do, s, so, n) _Generic(s, \
          str_t*:    A_strcpyz_Str, \
    const str_t*:    A_strcpyz_Str, \
          string_t*: A_strcpyz_String, \
    const string_t*: A_strcpyz_String \
)((d), (do), (s), (so), (n))
#else 
inline bool A_strcpyz(
    string_t* A_RESTRICT dest, size_t dest_off, 
    const str_t* A_RESTRICT src, size_t src_off, 
    size_t n
) {
    return A_strcpyz_Str(dest, dest_off, src, src_off, n);
}
inline bool A_strcpyz(
    string_t* A_RESTRICT dest, size_t dest_off, 
    const string_t* A_RESTRICT src, size_t src_off, 
    size_t n
) {
    return A_strcpyz_String(dest, dest_off, src, src_off, n);
}
#endif // __cplusplus

EXTERN_C string_t A_strdup_Str   (const str_t*    A_RESTRICT s);
EXTERN_C string_t A_strdup_String(const string_t* A_RESTRICT s);

#ifndef __cplusplus
#define A_strdup(s) (_Generic((s), \
          str_t*:    A_strdup_Str, \
    const str_t*:    A_strdup_Str, \
          string_t*: A_strdup_String, \
    const string_t*: A_strdup_String \
))(s)
#else
inline string_t A_strdup(const str_t* A_RESTRICT s) { 
    return A_strdup_Str(s);
}
inline string_t A_strdup(const string_t* A_RESTRICT s) {
    return A_strdup_String(s);
} 
#endif // __cplusplus

EXTERN_C bool A_strext (string_t* A_RESTRICT s, size_t n);
EXTERN_C bool A_strpush(string_t* A_RESTRICT s, char   c);

EXTERN_C bool A_strshrnk(string_t* A_RESTRICT s, size_t n);
EXTERN_C char A_strpop  (string_t* A_RESTRICT s);

EXTERN_C bool A_strcat_Str(
    string_t* A_RESTRICT dest, const str_t* A_RESTRICT src
);
EXTERN_C bool A_strcat_String(
    string_t* A_RESTRICT dest, const string_t* A_RESTRICT src
);

#ifndef __cplusplus
#define A_strcat(d, s) (_Generic((s), \
          str_t*:    A_strdup_Str, \
    const str_t*:    A_strdup_Str, \
          string_t*: A_strdup_String, \
    const string_t*: A_strdup_String \
))((d), (s))
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

EXTERN_C size_t A_strchr_Str   (const str_t*    A_RESTRICT s, char c);
EXTERN_C size_t A_strchr_String(const string_t* A_RESTRICT s, char c);

#ifndef __cplusplus
#define A_strchr(s, c) (_Generic((s), \
          str_t*:    A_strchr_Str, \
    const str_t*:    A_strchr_Str, \
          string_t*: A_strchr_String, \
    const string_t*: A_strchr_String \
))((s), (c))
#else
inline size_t A_strchr(const str_t* A_RESTRICT s, char c) { 
    return A_strchr_Str(s, c); 
} 
inline size_t A_strchr(const string_t* A_RESTRICT s, char c) { 
    return A_strchr_String(s, c); 
} 
#endif // __cplusplus

EXTERN_C size_t A_strrchr_Str   (const str_t*    A_RESTRICT s, char c);
EXTERN_C size_t A_strrchr_String(const string_t* A_RESTRICT s, char c);

#ifndef __cplusplus
#define A_strrchr(s, c) (_Generic((s), \
          str_t*:    A_strrchr_Str, \
    const str_t*:    A_strrchr_Str, \
          string_t*: A_strrchr_String, \
    const string_t*: A_strrchr_String \
))((s), (c))
#else
inline size_t A_strrchr(const str_t* A_RESTRICT s, char c) { 
    return A_strrchr_Str(s, c); 
} 
inline size_t A_strrchr(const string_t* A_RESTRICT s, char c) { 
    return A_strrchr_String(s, c); 
} 
#endif // __cplusplus

EXTERN_C bool A_strcont_Str   (const str_t*    A_RESTRICT s, char c);
EXTERN_C bool A_strcont_String(const string_t* A_RESTRICT s, char c);

#ifndef __cplusplus
#define A_strcont(s, c) (_Generic((s), \
          str_t*:    A_strcont_Str, \
    const str_t*:    A_strcont_Str, \
          string_t*: A_strcont_String, \
    const string_t*: A_strcont_String \
))((s), (c))
#else
inline bool A_strcont(const str_t* A_RESTRICT s, char c) { 
    return A_strcont_Str(s, c); 
} 
inline bool A_strcont(const string_t* A_RESTRICT s, char c) { 
    return A_strcont_String(s, c); 
} 
#endif // __cplusplus

EXTERN_C bool A_streq_Str_Str(
    const str_t* A_RESTRICT a, const str_t* A_RESTRICT b
);
EXTERN_C bool A_streq_Str_String(
    const str_t* A_RESTRICT a, const string_t* A_RESTRICT b
);
EXTERN_C bool A_streq_String_Str(
    const string_t* A_RESTRICT a, const str_t* A_RESTRICT b
);
EXTERN_C bool A_streq_String_String(
        const string_t* A_RESTRICT a, const string_t* A_RESTRICT b
);

#ifndef __cplusplus
#define A_streq(a, b) (_Generic((a), \
          str_t*:    _Generic((b), \
              str_t*:    A_streq_Str_Str, \
        const str_t*:    A_streq_Str_Str, \
              string_t*: A_streq_Str_String, \
        const string_t*: A_streq_Str_String), \
    const str_t*:    _Generic((b), \
              str_t*:    A_streq_Str_Str, \
        const str_t*:    A_streq_Str_Str, \
              string_t*: A_streq_Str_String, \
        const string_t*: A_streq_Str_String), \
          string_t*: _Generic((b), \
              str_t*:    A_streq_String_Str, \
        const str_t*:    A_streq_String_Str, \
              string_t*: A_streq_String_String, \
        const string_t*: A_streq_String_String), \
    const string_t*: _Generic((b), \
              str_t*:    A_streq_String_Str, \
        const str_t*:    A_streq_String_Str, \
              string_t*: A_streq_String_String, \
        const string_t*: A_streq_String_String) \
))((a), (b))
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

EXTERN_C size_t A_strpbrk_Str_Str(
    const str_t* A_RESTRICT a, const str_t* A_RESTRICT b
);
EXTERN_C size_t A_strpbrk_Str_String(
    const str_t* A_RESTRICT a, const string_t* A_RESTRICT b
);
EXTERN_C size_t A_strpbrk_String_Str(
    const string_t* A_RESTRICT a, const str_t* A_RESTRICT b
);
EXTERN_C size_t A_strpbrk_String_String(
    const string_t* A_RESTRICT a, const string_t* A_RESTRICT b
);

#ifndef __cplusplus
#define A_strpbrk(a, b) (_Generic((a), \
          str_t*:    _Generic((b), \
              str_t*:    A_strpbrk_Str_Str, \
        const str_t*:    A_strpbrk_Str_Str, \
              string_t*: A_strpbrk_Str_String, \
        const string_t*: A_strpbrk_Str_String), \
    const str_t*:    _Generic((b), \
              str_t*:    A_strpbrk_Str_Str, \
        const str_t*:    A_strpbrk_Str_Str, \
              string_t*: A_strpbrk_Str_String, \
        const string_t*: A_strpbrk_Str_String), \
          string_t*: _Generic((b), \
              str_t*:    A_strpbrk_String_Str, \
        const str_t*:    A_strpbrk_String_Str, \
              string_t*: A_strpbrk_String_String, \
        const string_t*: A_strpbrk_String_String), \
    const string_t*: _Generic((b), \
              str_t*:    A_strpbrk_String_Str, \
        const str_t*:    A_strpbrk_String_Str, \
              string_t*: A_strpbrk_String_String, \
        const string_t*: A_strpbrk_String_String) \
))((a), (b))
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

EXTERN_C size_t A_strrpbrk_Str_Str(
    const str_t* A_RESTRICT a, const str_t* A_RESTRICT b
);
EXTERN_C size_t A_strrpbrk_Str_String(
    const str_t* A_RESTRICT a, const string_t* A_RESTRICT b
);
EXTERN_C size_t A_strrpbrk_String_Str(
    const string_t* A_RESTRICT a, const str_t* A_RESTRICT b
);
EXTERN_C size_t A_strrpbrk_String_String(
    const string_t* A_RESTRICT a, const string_t* A_RESTRICT b
);

#ifndef __cplusplus
#define A_strrpbrk(a, b) (_Generic((a), \
          str_t*:    _Generic((b), \
              str_t*:    A_strrpbrk_Str_Str, \
        const str_t*:    A_strrpbrk_Str_Str, \
              string_t*: A_strrpbrk_Str_String, \
        const string_t*: A_strrpbrk_Str_String), \
    const str_t*:    _Generic((b), \
              str_t*:    A_strrpbrk_Str_Str, \
        const str_t*:    A_strrpbrk_Str_Str, \
              string_t*: A_strrpbrk_Str_String, \
        const string_t*: A_strrpbrk_Str_String), \
          string_t*: _Generic((b), \
              str_t*:    A_strrpbrk_String_Str, \
        const str_t*:    A_strrpbrk_String_Str, \
              string_t*: A_strrpbrk_String_String, \
        const string_t*: A_strrpbrk_String_String), \
    const string_t*: _Generic((b), \
              str_t*:    A_strrpbrk_String_Str, \
        const str_t*:    A_strrpbrk_String_Str, \
              string_t*: A_strrpbrk_String_String, \
        const string_t*: A_strrpbrk_String_String) \
))((a), (b))
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

EXTERN_C size_t A_strpcnt_Str_Str(
    const str_t* A_RESTRICT a, const str_t* A_RESTRICT b
);
EXTERN_C size_t A_strpcnt_Str_String(
    const str_t* A_RESTRICT a, const string_t* A_RESTRICT b
);
EXTERN_C size_t A_strpcnt_String_Str(
    const string_t* A_RESTRICT a, const str_t* A_RESTRICT b
);
EXTERN_C size_t A_strpcnt_String_String(
    const string_t* A_RESTRICT a, const string_t* A_RESTRICT b
);

#ifndef __cplusplus
#define A_strpcnt(a, b) (_Generic((a), \
          str_t*:    _Generic((b), \
              str_t*:    A_strpcnt_Str_Str, \
        const str_t*:    A_strpcnt_Str_Str, \
              string_t*: A_strpcnt_Str_String, \
        const string_t*: A_strpcnt_Str_String), \
    const str_t*:    _Generic((b), \
              str_t*:    A_strpcnt_Str_Str, \
        const str_t*:    A_strpcnt_Str_Str, \
              string_t*: A_strpcnt_Str_String, \
        const string_t*: A_strpcnt_Str_String), \
          string_t*: _Generic((b), \
        const str_t*:    A_strpcnt_String_Str, \
              str_t*:    A_strpcnt_String_Str, \
        const string_t*: A_strpcnt_String_String, \
              string_t*: A_strpcnt_String_String), \
    const string_t*: _Generic((b), \
        const str_t*:    A_strpcnt_String_Str, \
              str_t*:    A_strpcnt_String_Str, \
        const string_t*: A_strpcnt_String_String, \
              string_t*: A_strpcnt_String_String) \
))((a), (b))
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

EXTERN_C size_t A_strrpcnt_Str_Str(
    const str_t* A_RESTRICT a, const str_t* A_RESTRICT b
);
EXTERN_C size_t A_strrpcnt_Str_String(
    const str_t* A_RESTRICT a, const string_t* A_RESTRICT b
);
EXTERN_C size_t A_strrpcnt_String_Str(
    const string_t* A_RESTRICT a, const str_t* A_RESTRICT b
);
EXTERN_C size_t A_strrpcnt_String_String(
    const string_t* A_RESTRICT a, const string_t* A_RESTRICT b
);

#ifndef __cplusplus
#define A_strrpcnt(a, b) (_Generic((a), \
          str_t*:    _Generic((b), \
              str_t*:    A_strrpcnt_Str_Str, \
        const str_t*:    A_strrpcnt_Str_Str, \
              string_t*: A_strrpcnt_Str_String, \
        const string_t*: A_strrpcnt_Str_String), \
    const str_t*:    _Generic((b), \
              str_t*:    A_strrpcnt_Str_Str, \
        const str_t*:    A_strrpcnt_Str_Str, \
              string_t*: A_strrpcnt_Str_String, \
        const string_t*: A_strrpcnt_Str_String), \
          string_t*: _Generic((b), \
              str_t*:    A_strrpcnt_String_Str, \
        const str_t*:    A_strrpcnt_String_Str, \
              string_t*: A_strrpcnt_String_String, \
        const string_t*: A_strrpcnt_String_String), \
    const string_t*: _Generic((b), \
              str_t*:    A_strrpcnt_String_Str, \
        const str_t*:    A_strrpcnt_String_Str, \
              string_t*: A_strrpcnt_String_String, \
        const string_t*: A_strrpcnt_String_String) \
))((a), (b))
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

EXTERN_C size_t A_strstr_Str_Str(
    const str_t* A_RESTRICT a, const str_t* A_RESTRICT b
);
EXTERN_C size_t A_strstr_Str_String(
    const str_t* A_RESTRICT a, const string_t* A_RESTRICT b
);
EXTERN_C size_t A_strstr_String_Str(
    const string_t* A_RESTRICT a, const str_t* A_RESTRICT b
);
EXTERN_C size_t A_strstr_String_String(
    const string_t* A_RESTRICT a, const string_t* A_RESTRICT b
);

#ifndef __cplusplus
#define A_strstr(a, b) (_Generic((a), \
          str_t*:    _Generic((b), \
              str_t*:    A_strstr_Str_Str, \
        const str_t*:    A_strstr_Str_Str, \
              string_t*: A_strstr_Str_String, \
        const string_t*: A_strstr_Str_String), \
    const str_t*:    _Generic((b), \
              str_t*:    A_strstr_Str_Str, \
        const str_t*:    A_strstr_Str_Str, \
              string_t*: A_strstr_Str_String, \
        const string_t*: A_strstr_Str_String), \
          string_t*: _Generic((b), \
              str_t*:    A_strstr_String_Str, \
        const str_t*:    A_strstr_String_Str, \
              string_t*: A_strstr_String_String, \
        const string_t*: A_strstr_String_String), \
    const string_t*: _Generic((b), \
              str_t*:    A_strstr_String_Str, \
        const str_t*:    A_strstr_String_Str, \
              string_t*: A_strstr_String_String, \
        const string_t*: A_strstr_String_String) \
))((a), (b))
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

EXTERN_C size_t A_strrstr_Str_Str(
    const str_t* A_RESTRICT a, const str_t* A_RESTRICT b
);
EXTERN_C size_t A_strrstr_Str_String(
    const str_t* A_RESTRICT a, const string_t* A_RESTRICT b
);
EXTERN_C size_t A_strrstr_String_Str(
    const string_t* A_RESTRICT a, const str_t* A_RESTRICT b
);
EXTERN_C size_t A_strrstr_String_String(
    const string_t* A_RESTRICT a, const string_t* A_RESTRICT b
);

#ifndef __cplusplus
#define A_strrstr(a, b) (_Generic((a), \
          str_t*:    _Generic((b), \
              str_t*:    A_strrstr_Str_Str, \
        const str_t*:    A_strrstr_Str_Str, \
              string_t*: A_strrstr_Str_String, \
        const string_t*: A_strrstr_Str_String), \
    const str_t*:    _Generic((b), \
              str_t*:    A_strrstr_Str_Str, \
        const str_t*:    A_strrstr_Str_Str, \
              string_t*: A_strrstr_Str_String, \
        const string_t*: A_strrstr_Str_String), \
          string_t*: _Generic((b), \
              str_t*:    A_strrstr_String_Str, \
        const str_t*:    A_strrstr_String_Str, \
              string_t*: A_strrstr_String_String, \
        const string_t*: A_strrstr_String_String), \
    const string_t*: _Generic((b), \
              str_t*:    A_strrstr_String_Str, \
        const str_t*:    A_strrstr_String_Str, \
              string_t*: A_strrstr_String_String, \
        const string_t*: A_strrstr_String_String) \
))((a), (b))
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

EXTERN_C str_t A_substr_Str(const str_t* A_RESTRICT s, size_t i, size_t len);
EXTERN_C str_t A_substr_String(
    const string_t* A_RESTRICT s, size_t i, size_t len
);

#ifndef __cplusplus
#define A_substr(s, i, n) (_Generic((s), \
          str_t*:    A_substr_Str, \
    const str_t*:    A_substr_Str, \
          string_t*: A_substr_String, \
    const string_t*: A_substr_String \
))((s), (i), (n))
#else
inline str_t A_substr(const str_t* A_RESTRICT s, size_t i, size_t len) { 
    return A_substr_Str(s, i, len); 
}
inline str_t A_substr(const string_t* A_RESTRICT s, size_t i, size_t len) {
    return A_substr_String(s, i, len); 
}
#endif // __cplusplus

EXTERN_C string_t A_substring_Str(
    const str_t* A_RESTRICT s, size_t i, size_t len
);
EXTERN_C string_t A_substring_String(
    const string_t* A_RESTRICT s, size_t i, size_t len
);

#ifndef __cplusplus
#define A_substring(s, i, n) (_Generic((s), \
          str_t*:    A_substring_Str, \
    const str_t*:    A_substring_Str, \
          string_t*: A_substring_String, \
    const string_t*: A_substring_String \
))((s), (i), (n))
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

EXTERN_C void A_strclear(string_t* A_RESTRICT s);
EXTERN_C void A_strdrop (string_t* A_RESTRICT s);

