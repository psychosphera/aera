#include "a_type.h"

#include <ctype.h>

char A_STRING_MANGLE_CHAR(A_tolower)(char c) {
    return (char)tolower(c);
}

string_t A_STRING_MANGLE_STR(A_tolower)(const str_t* A_RESTRICT s) {
    string_t n = A_string(0);
    char c = 0;
    for(size_t i = 0, c = A_strat(s, 0); i < A_strlen(s); i++)
        A_strpush(&n, A_STRING_MANGLE_CHAR(A_tolower)(c));
    return n;
}

string_t A_STRING_MANGLE_STRING(A_tolower)(const string_t* A_RESTRICT s) {
    string_t n = A_string(0);
    char c = 0;
    A_STR_ITER(s, c)
        A_strpush(&n, A_STRING_MANGLE_CHAR(A_tolower)(c));
    return n;
}

