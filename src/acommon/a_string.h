#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
#include <stdint.h>

#include "acommon.h"

int   A_memcmp (const void* a,    const void* b,   size_t n);
void* A_memcpy (      void* dest, const void* src, size_t n);
void* A_memchr (const void* p,    int c,           size_t n);
void* A_memrchr(const void* p,    int c,           size_t n);
 
void* A_memset (      void* p,    int c,           size_t n);

typedef struct str_s {
    const char* __data;
    size_t      __len;
} str_t;

typedef struct string_s {
    char*  __data;
    size_t __len;
    size_t __cap;
} string_t;

#define A_NPOS SIZE_MAX

str_t A_literal_internal(const char* s, size_t c);
#define A_literal(s) A_literal_internal(s, countof(s))

str_t A_str(const string_t* s);

string_t A_string_Str   (const str_t*    s);
string_t A_string_String(const string_t* s);
string_t A_string_SizeT (      size_t    c);

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
inline string_t A_string(const str_t* s)    { return A_string_Str(s); }
inline string_t A_string(const string_t* s) { return A_string_String(s); }
inline string_t A_string(      size_t c)    { return A_string_SizeT(c); }
#endif

#ifdef __cplusplus
#define A_cstr_Str    A_cstr
#define A_cstr_String A_cstr
#endif // __cplusplus
const char* A_cstr_Str    (const str_t*    s);
      char* A_cstr_String (      string_t* s);
const char* A_cstr_StringC(const string_t* s);

#ifndef __cplusplus
#define A_cstr(s) (_Generic((s), \
    const str_t*:    A_cstr_Str, \
          string_t*: A_cstr_String, \
    const string_t*: A_cstr_StringC \
))(s)
#endif // __cplusplus

char A_strat_Str   (const str_t*    s, size_t i);
char A_strat_String(const string_t* s, size_t i);

#ifndef __cplusplus
#define A_strat(s, i) (_Generic((s), \
          str_t*:    A_strat_Str, \
    const str_t*:    A_strat_Str, \
          string_t*: A_strat_String, \
    const string_t*: A_strat_String \
))(s, i)
#else
inline char A_strat(const str_t* s, size_t i) { 
    return A_strat_Str(s, i); 
};
inline char A_strat(const string_t* s, size_t i) { 
    return A_strat_String(s, i); 
};
#endif // __cplusplus

const char* A_stratp_Str    (const str_t*    s, size_t i);
      char* A_stratp_String (      string_t* s, size_t i);
const char* A_stratp_StringC(const string_t* s, size_t i);

#ifndef __cplusplus
#define A_stratp(s, i) (_Generic((s), \
          str_t*:    A_stratp_Str, \
    const str_t*:    A_stratp_Str, \
          string_t*: A_stratp_String, \
    const string_t*: A_stratp_StringC \
))(s, i)
#else
inline const char* A_stratp(const str_t* s, size_t i) { 
    return A_stratp_Str(s, i); 
}
inline char* A_stratp(string_t* s, size_t i) { 
    return A_stratp_String(s, i); 
}
inline const char* A_stratp(const string_t* s, size_t i) { 
    return A_stratp_StringC(s, i); 
}
#endif // __cplusplus
       
size_t A_strlen_Str   (const str_t*    s);
size_t A_strlen_String(const string_t* s);

#ifndef __cplusplus
#define A_strlen(s) (_Generic((s), \
          str_t*:    A_strlen_Str, \
    const str_t*:    A_strlen_Str, \
          string_t*: A_strlen_String, \
    const string_t*: A_strlen_String \
))(s)
#else
inline size_t A_strlen(const str_t*    s) { return A_strlen_Str(s);    } 
inline size_t A_strlen(const string_t* s) { return A_strlen_String(s); } 
#endif // __cplusplus
       
size_t A_strcap(const string_t* s);

#ifdef __cplusplus
#define A_strcpyz_Str    A_strcpyz
#define A_strcpyz_String A_strcpyz
#endif // __cplusplus
bool A_strcpyz_Str(
    string_t* dest, size_t dest_off, const str_t* src, size_t src_off
);
bool A_strcpyz_String(
    string_t* dest, size_t dest_off, const string_t* src, size_t src_off
);

#ifndef __cplusplus
#define A_strcpyz(d, do, s, so) _Generic(s, \
          str_t*:    A_strcpyz_Str, \
    const str_t*:    A_strcpyz_Str, \
          string_t*: A_strcpyz_String, \
    const string_t*: A_strcpyz_String \
)((d), (do), (s), (so))
#else 
inline bool A_strcpyz(
    string_t* dest, size_t dest_off, const str_t* src, size_t src_off
) {
    return A_strcpyz_Str(dest, dest_off, src, src_off);
}
inline bool A_strcpyz(
    string_t* dest, size_t dest_off, const string_t* src, size_t src_off
) {
    return A_strcpyz_String(dest, dest_off, src, src_off);
}
#endif // __cplusplus

string_t A_strdup_Str   (const str_t*    s);
string_t A_strdup_String(const string_t* s);

#ifndef __cplusplus
#define A_strdup(s) (_Generic((s), \
          str_t*:    A_strdup_Str, \
    const str_t*:    A_strdup_Str, \
          string_t*: A_strdup_String, \
    const string_t*: A_strdup_String \
))(s)
#else
inline string_t A_strdup(const str_t*    s) { return A_strdup_Str(s);    } 
inline string_t A_strdup(const string_t* s) { return A_strdup_String(s); } 
#endif // __cplusplus

bool A_strext (string_t* s, size_t n);
bool A_strpush(string_t* s, char   c);

bool A_strshrnk(string_t* s, size_t n);
char A_strpop  (string_t* s);

bool A_strcat_Str   (string_t* dest, const str_t*    src);
bool A_strcat_String(string_t* dest, const string_t* src);

#ifndef __cplusplus
#define A_strcat(d, s) (_Generic((s), \
          str_t*:    A_strdup_Str, \
    const str_t*:    A_strdup_Str, \
          string_t*: A_strdup_String, \
    const string_t*: A_strdup_String \
))((d), (s))
#else
inline size_t A_strcat(string_t* dest, const str_t* src) { 
    return A_strcat_Str(dest, src); 
} 
inline size_t A_strcat(string_t* dest, const string_t* src) { 
    return A_strcat_String(dest, src); 
} 
#endif

size_t A_strchr_Str   (const str_t*    s, char c);
size_t A_strchr_String(const string_t* s, char c);

#ifndef __cplusplus
#define A_strchr(s, c) (_Generic((s), \
          str_t*:    A_strchr_Str, \
    const str_t*:    A_strchr_Str, \
          string_t*: A_strchr_String, \
    const string_t*: A_strchr_String \
))((s), (c))
#else
inline size_t A_strchr(const str_t* s, char c) { 
    return A_strchr_Str(s, c); 
} 
inline size_t A_strchr(const string_t* s, char c) { 
    return A_strchr_String(s, c); 
} 
#endif // __cplusplus

size_t A_strrchr_Str   (const str_t*    s, char c);
size_t A_strrchr_String(const string_t* s, char c);

#ifndef __cplusplus
#define A_strrchr(s, c) (_Generic((s), \
          str_t*:    A_strrchr_Str, \
    const str_t*:    A_strrchr_Str, \
          string_t*: A_strrchr_String, \
    const string_t*: A_strrchr_String \
))((s), (c))
#else
inline size_t A_strrchr(const str_t* s, char c) { 
    return A_strrchr_Str(s, c); 
} 
inline size_t A_strrchr(const string_t* s, char c) { 
    return A_strrchr_String(s, c); 
} 
#endif // __cplusplus

#ifdef __cplusplus
#define A_strcont_Str    A_strcont
#define A_strcont_String A_strcont
#endif // __cplusplus
bool A_strcont_Str   (const str_t*    s, char c);
bool A_strcont_String(const string_t* s, char c);

#ifndef __cplusplus
#define A_strcont(s, c) (_Generic((s), \
          str_t*:    A_strcont_Str, \
    const str_t*:    A_strcont_Str, \
          string_t*: A_strcont_String, \
    const string_t*: A_strcont_String \
))((s), (c))
#endif // __cplusplus

bool A_streq_Str_Str      (const str_t*    a, const str_t*    b);
bool A_streq_Str_String   (const str_t*    a, const string_t* b);
bool A_streq_String_Str   (const string_t* a, const str_t*    b);
bool A_streq_String_String(const string_t* a, const string_t* b);

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
inline bool A_streq(const str_t* a, const str_t* b) { 
    return A_streq_Str_Str(a, b); 
}

inline bool A_streq(const str_t* a, const string_t* b) { 
    return A_streq_Str_String(a, b); 
}

inline bool A_streq(const string_t* a, const str_t* b) { 
    return A_streq_String_Str(a, b); 
}

inline bool A_streq(const string_t* a, const string_t* b) { 
    return A_streq_String_String(a, b); 
}
#endif // __cplusplus

#ifdef __cplusplus
#define A_strpbrk_Str_Str       A_strpbrk
#define A_strpbrk_Str_String    A_strpbrk
#define A_strpbrk_Str_Str       A_strpbrk
#define A_strpbrk_String_String A_strpbrk
#endif // __cplusplus
size_t A_strpbrk_Str_Str      (const str_t*    a, const str_t*    b);
size_t A_strpbrk_Str_String   (const str_t*    a, const string_t* b);
size_t A_strpbrk_String_Str   (const string_t* a, const str_t*    b);
size_t A_strpbrk_String_String(const string_t* a, const string_t* b);

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
#endif // __cplusplus

#ifdef __cplusplus
#define A_strrpbrk_Str_Str       A_strrpbrk
#define A_strrpbrk_Str_String    A_strrpbrk
#define A_strrpbrk_Str_Str       A_strrpbrk
#define A_strrpbrk_String_String A_strrpbrk
#endif // __cplusplus
size_t A_strrpbrk_Str_Str      (const str_t*    a, const str_t*    b);
size_t A_strrpbrk_Str_String   (const str_t*    a, const string_t* b);
size_t A_strrpbrk_String_Str   (const string_t* a, const str_t*    b);
size_t A_strrpbrk_String_String(const string_t* a, const string_t* b);

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
#endif // __cplusplus

#ifdef __cplusplus
#define A_strpcnt_Str_Str       A_strpcnt
#define A_strpcnt_Str_String    A_strpcnt
#define A_strpcnt_Str_Str       A_strpcnt
#define A_strpcnt_String_String A_strpcnt
#endif // __cplusplus
size_t A_strpcnt_Str_Str      (const str_t*    a, const str_t*    b);
size_t A_strpcnt_Str_String   (const str_t*    a, const string_t* b);
size_t A_strpcnt_String_Str   (const string_t* a, const str_t*    b);
size_t A_strpcnt_String_String(const string_t* a, const string_t* b);

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
#endif // __cplusplus

#ifdef __cplusplus
#define A_strrpcnt_Str_Str       A_strrpcnt
#define A_strrpcnt_Str_String    A_strrpcnt
#define A_strrpcnt_Str_Str       A_strrpcnt
#define A_strrpcnt_String_String A_strrpcnt
#endif // __cplusplus
size_t A_strrpcnt_Str_Str      (const str_t*    a, const str_t*    b);
size_t A_strrpcnt_Str_String   (const str_t*    a, const string_t* b);
size_t A_strrpcnt_String_Str   (const string_t* a, const str_t*    b);
size_t A_strrpcnt_String_String(const string_t* a, const string_t* b);

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
#endif // __cplusplus

#ifdef __cplusplus
#define A_strstr_Str_Str       A_strstr
#define A_strstr_Str_String    A_strstr
#define A_strstr_Str_Str       A_strstr
#define A_strstr_String_String A_strstr
#endif // __cplusplus
size_t A_strstr_Str_Str      (const str_t*    a, const str_t*    b);
size_t A_strstr_Str_String   (const str_t*    a, const string_t* b);
size_t A_strstr_String_Str   (const string_t* a, const str_t*    b);
size_t A_strstr_String_String(const string_t* a, const string_t* b);

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
#endif // __cplusplus

#ifdef __cplusplus
#define A_strrstr_Str_Str       A_strrstr
#define A_strrstr_Str_String    A_strrstr
#define A_strrstr_Str_Str       A_strrstr
#define A_strrstr_String_String A_strrstr
#endif // __cplusplus
size_t A_strrstr_Str_Str      (const str_t*    a, const str_t*    b);
size_t A_strrstr_Str_String   (const str_t*    a, const string_t* b);
size_t A_strrstr_String_Str   (const string_t* a, const str_t*    b);
size_t A_strrstr_String_String(const string_t* a, const string_t* b);

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
#endif // __cplusplus

#ifdef __cplusplus
#define A_substr_Str    A_substr
#define A_substr_String A_substr
#endif // __cplusplus
str_t A_substr_Str   (const str_t*    s, size_t i);
str_t A_substr_String(const string_t* s, size_t i);

#ifndef __cplusplus
#define A_substr(s, i) (_Generic((s), \
          str_t*:    A_substr_Str, \
    const str_t*:    A_substr_Str, \
          string_t*: A_substr_String, \
    const string_t*: A_substr_String \
))((s), (i))
#endif // __cplusplus

#ifdef __cplusplus
#define A_substring_Str    A_substring
#define A_substring_String A_substring
#endif // __cplusplus
string_t A_substring_Str   (const str_t*    s, size_t i);
string_t A_substring_String(const string_t* s, size_t i);

#ifndef __cplusplus
#define A_substring(s, i) (_Generic((s), \
          str_t*:    A_substring_Str, \
    const str_t*:    A_substring_Str, \
          string_t*: A_substring_String, \
    const string_t*: A_substring_String \
))((s), (i))
#endif // __cplusplus

void A_strclear(string_t* s);
void A_strdrop(string_t* s);

