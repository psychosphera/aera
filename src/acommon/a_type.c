#include "a_type.h"

#include <ctype.h>

char A_STRING_MANGLE_CHAR(A_tolower)(char c) {
    return (char)tolower(c);
}

string_t A_STRING_MANGLE_STR(A_tolower)(const str_t* A_RESTRICT s) {
    string_t n = A_string(0);
    for(size_t i = 0; i < A_strlen(s); i++) {
        char c = A_strat(s, i);
        A_strpush(&n, A_tolower(c));
    }
    return n;
}

string_t A_STRING_MANGLE_STRING(A_tolower)(const string_t* A_RESTRICT s) {
    string_t n = A_string(0);
    for(size_t i = 0; i < A_strlen(s); i++) {
        char c = A_strat(s, i);
        A_strpush(&n, A_tolower(c));
    }
    return n;
}

