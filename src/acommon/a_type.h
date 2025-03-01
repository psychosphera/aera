#pragma once

#include <stdbool.h>

#include "acommon.h"

A_EXTERN_C A_NO_DISCARD char A_tolower(char c);
A_EXTERN_C A_NO_DISCARD bool A_isspace(char c);
// void A_cstrlwr(char* A_RESTRICT s);

// A_STRING_DECLARE_CHAR(A_EXTERN_C char, A_tolower, c);
// A_STRING_DECLARE_BOTH_CONST(A_EXTERN_C string_t, A_tolower, s);

// #ifndef __cplusplus
// #define A_tolower(s) (_Generic((s), \
//     A_STRING_GENERIC_MATCH_CHAR(A_tolower), \
//     A_STRING_GENERIC_MATCH_BOTH(A_tolower) \
// ))(s)
// #else
// A_STRING_CXX_OVERLOAD_CHAR(char, A_tolower);
// A_STRING_CXX_OVERLOAD_BOTH_CONST(string_t, A_tolower);
// #endif // __cplusplus
