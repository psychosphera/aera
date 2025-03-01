#include "a_type.h"

#include <ctype.h>

#include "a_string.h"

A_EXTERN_C A_NO_DISCARD char A_tolower(char c) {
    return (char)tolower(c);
}

A_EXTERN_C A_NO_DISCARD bool A_isspace(char c) {
    return isspace(c) != 0;
}

// void A_cstrlwr(char* A_RESTRICT s) {
//     for (size_t i = 0; i < A_cstrlen(s); c++)
//         s[i] = A_tolower(c);
// }

// char A_STRING_MANGLE_CHAR(A_tolower)(char c) {
//     return (char)tolower(c);
// }

// string_t A_STRING_MANGLE_STR(A_tolower)(const str_t* A_RESTRICT s) {
//     string_t n = A_string(0);
//     for(size_t i = 0; i < A_strlen(s); i++) {
//         char c = A_strat(s, i);
//         A_strpush(&n, A_tolower(c));
//     }
//     return n;
// }

// string_t A_STRING_MANGLE_STRING(A_tolower)(const string_t* A_RESTRICT s) {
//     string_t n = A_string(0);
//     for(size_t i = 0; i < A_strlen(s); i++) {
//         char c = A_strat(s, i);
//         A_strpush(&n, A_tolower(c));
//     }
//     return n;
// }
