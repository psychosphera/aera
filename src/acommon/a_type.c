#include "a_type.h"

#include <ctype.h>

EXTERN_C char A_tolower_Char(char c) {
    return (char)tolower(c);
}

EXTERN_C string_t A_tolower_Str(const str_t* s) {
    string_t n = A_string(0);
    for(size_t i = 0; i < A_strlen(s); i++) 
        A_strpush(&n, A_tolower(A_strat(s, i)));

    return n;
}

EXTERN_C string_t A_tolower_String(const string_t* s) {
    string_t n = A_string(0);
    for(size_t i = 0; i < A_strlen(s); i++) 
        A_strpush(&n, A_tolower(A_strat(s, i)));

    return n;
}

