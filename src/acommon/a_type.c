#include "acommon.h"

#include <ctype.h>

char A_tolower_Char(char c) {
    return tolower(c);
}

string_t A_tolower_Str(str_t s) {
    std::string s;
    for (auto c : sv)
        s.push_back((char)tolower((int)c));
    return s;
}
