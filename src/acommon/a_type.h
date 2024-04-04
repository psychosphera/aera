#pragma once

#include "a_string.h"

A_EXTERN_C char     A_tolower_Char  (      char      c);
A_EXTERN_C string_t A_tolower_Str   (const str_t*    s);
A_EXTERN_C string_t A_tolower_String(const string_t* s);

#ifndef __cplusplus
#define A_tolower(s) (_Generic((s), \
          char:      A_tolower_Char, \
          str_t*:    A_tolower_Str, \
    const str_t*:    A_tolower_Str, \
          string_t*: A_tolower_String, \
    const string_t*: A_tolower_String \
))(s)
#else
inline char     A_tolower(      char      c) { return A_tolower_Char  (c); }
inline string_t A_tolower(const str_t*    s) { return A_tolower_Str   (s); }
inline string_t A_tolower(const string_t* s) { return A_tolower_String(s); }
#endif // __cplusplus

