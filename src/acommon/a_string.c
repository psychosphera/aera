#include "a_string.h"
#include "a_type.h"

#include <string.h>

#include "z_mem.h"

int A_memcmp(const void* a, const void* b, size_t n) {
    return memcmp(a, b, n);
}

void* A_memcpy(void* dest, const void* src, size_t n) {
    return memcpy(dest, src, n);
}

void* A_memchr(const void* p, int c, size_t n) {
    return memchr(p, c, n);
}

void* A_memrchr(const void* p, int c, size_t n) {
    for(size_t i = n; i > 0; i--) {
        if(((char*)p)[i] == (char)c)
            return (void*)((const char*)p + i);
    }

    return NULL;
}

void* A_memset(void* p, int c, size_t n) {
    return memset(p, c, n);
}

str_t A_literal_internal(const char* s, size_t c) {
    str_t n;
    n.__data = s;
    n.__len  = c - 1; // sizeof(literal) includes the null-terminator
    return n;
}

str_t A_str(const string_t* restrict s) {
    str_t n;
    n.__data = A_cstr(s);
    n.__len  = A_strlen(s);
    return n;
}

string_t A_string_Str(const str_t* restrict s) {
    return A_strdup(s);
}

string_t A_string_String(const string_t* restrict s) {
    return A_strdup(s);
}

string_t A_string_SizeT(size_t c) {
    size_t cap = c;
    if(cap < 7)
        cap = 7;

    string_t n;
    n.__data = Z_Alloc(c + 1);
    if(n.__data != NULL) {
        n.__len = c;
        n.__cap = cap;
        n.__data[c] = '\0';
    } else {
        n.__len = 0;
    }
    return n;   
}

const char* A_cstr_Str(const str_t* restrict s) {
    return s->__data;
}

char* A_cstr_String(string_t* restrict s) {
    return s->__data;
}

const char* A_cstr_StringC(const string_t* restrict s) {
    return (const char*)s->__data;
}

size_t A_strlen_Str(const str_t* restrict s) {
    return s->__len;
}

size_t A_strlen_String(const string_t* restrict s) {
    return s->__len;
}

size_t A_strcap(const string_t* restrict s) {
    return s->__cap;
}

char A_strat_Str(const str_t* restrict s, size_t i) {
    if(i > A_strlen(s))
        return '\0';

    return A_cstr(s)[i];
}

char A_strat_String(const string_t* restrict s, size_t i) {
    if(i > A_strlen(s))
        return '\0';
    
    return A_cstr(s)[i];
}

const char* A_stratp_Str(const str_t* restrict s, size_t i) {
    if(i > A_strlen(s))
        return NULL;
    
    return &A_cstr(s)[i];
}

char* A_stratp_String(string_t* restrict s, size_t i) {
    return &A_cstr(s)[i];
}

const char* A_stratp_StringC(const string_t* restrict s, size_t i) {
    return &A_cstr(s)[i];
}

bool A_strncpy_Str(
    string_t* restrict dest, size_t dest_off, const str_t* restrict src, size_t src_off, size_t n
) {
    if(n > A_strlen(src) - src_off) 
        n = A_strlen(src) - src_off;

    if(dest_off + n > A_strlen(dest))
        return false;

    memcpy(A_stratp(dest, dest_off), A_stratp(src, src_off), n);

    *A_stratp(dest, A_strlen(dest)) = '\0';

    return true;
}

bool A_strncpy_String(
    string_t* restrict dest, size_t dest_off, 
    const string_t* restrict src, size_t src_off, 
    size_t n
) {
    if(n > A_strlen(src) - src_off) 
        n = A_strlen(src) - src_off;

    if(dest_off + n > A_strlen(dest))
        return false;

    memcpy(A_stratp(dest, dest_off), A_stratp(src, src_off), n);

    *A_stratp(dest, A_strlen(dest)) = '\0';

    return true;
}

string_t A_strdup_Str(const str_t* restrict s) {
    string_t n = A_string(A_strlen(s));
    A_strncpy(&n, 0, s, 0, A_NPOS);
    return n;
}

string_t A_strdup_String(const string_t* restrict s) {
    string_t n = A_string(A_strlen(s));
    A_strncpy(&n, 0, s, 0, A_NPOS);
    return n;
}

bool A_strext(string_t* restrict s, size_t n) {
    size_t newlen = A_strlen(s) + n;
    if(newlen + 1 > A_strcap(s))
        s->__data = Z_Realloc(s->__data, A_npow2(newlen + 1));
    
    if(s->__data != NULL) {
        s->__len += n;
        return true;
    } else {
        s->__len = 0;
        s->__cap = 0;
        return false;
    }
}

bool A_strpush(string_t* restrict s, char c) {
    if(!A_strext(s, 1))
        return false;
    
    *A_stratp(s, A_strlen(s) - 1) = c;
    *A_stratp(s, A_strlen(s))     = '\0';

    return true;
}

bool A_strshrnk(string_t* restrict s, size_t n) {
    size_t newlen = n >= A_strlen(s) ? 0 : A_strlen(s) - n;
    if(newlen + 1 < A_ppow2(A_strcap(s)))
        s->__data = Z_Realloc(s->__data, A_npow2(newlen + 1));
    
    if(s->__data != NULL) {
        s->__len -= n;
        return true;
    } else {
        s->__len = 0;
        s->__cap = 0;
        return false;
    }
}

char A_strpop(string_t* restrict s) {
    char c = A_strat(s, A_strlen(s) - 1);
    *A_stratp(s, A_strlen(s) - 1) = '\0';

    if(!A_strshrnk(s, 1))
        return '\0';

    return c;
}

bool A_strcat_Str(string_t* restrict dest, const str_t* restrict src) {
    size_t off = A_strlen(dest);

    if(!A_strext(dest, A_strlen(src)))
        return false;

    A_strncpy(dest, off, src, 0, A_NPOS);
    return true;
}

bool A_strcat_String(string_t* restrict dest, const string_t* restrict src) {
    size_t off = A_strlen(dest);

    if(!A_strext(dest, A_strlen(src)))
        return false;

    A_strncpy(dest, off, src, 0, A_NPOS);
    return true;
}

size_t A_strchr_Str(const str_t* restrict s, char c) {
    const char* p = (const char*)A_memchr(A_cstr(s), (int)c, A_strlen(s));
    if(!p)
        return A_NPOS;
    return (size_t)(p - A_cstr(s));
}

size_t A_strchr_String(const string_t* restrict s, char c) {
    const char* p = (const char*)A_memchr(A_cstr(s), (int)c, A_strlen(s));
    if(!p)
        return A_NPOS;
    return (size_t)(p - A_cstr(s));
}

size_t A_strrchr_Str(const str_t* restrict s, char c) {
    const char* p = (const char*)A_memrchr(A_cstr(s), (int)c, A_strlen(s));
    if(!p)
        return A_NPOS;
    return (size_t)(p - A_cstr(s));
}

size_t A_strrchr_String(const string_t* restrict s, char c) {
    const char* p = (const char*)A_memrchr(A_cstr(s), (int)c, A_strlen(s));
    if(!p)
        return A_NPOS;
    return (size_t)(p - A_cstr(s));
}

bool A_strcont_Str(const str_t* restrict s, char c) {
    return A_strchr(s, c) != A_NPOS;
}

bool A_strcont_String(const string_t* restrict s, char c) {
    return A_strchr(s, c) != A_NPOS;
}

bool A_streq_Str_Str(const str_t* restrict a, const str_t* restrict b) {
    if(A_strlen(a) != A_strlen(b))
        return false;

    return strncmp(A_cstr(a), A_cstr(b), A_strlen(a)) == 0;
}

bool A_streq_Str_String(const str_t* restrict a, const string_t* restrict b) {
    if(A_strlen(a) != A_strlen(b))
        return false;

    return strncmp(A_cstr(a), A_cstr(b), A_strlen(a)) == 0;
}

bool A_streq_String_Str(const string_t* restrict a, const str_t* restrict b) {
    if(A_strlen(a) != A_strlen(b))
        return false;

    return strncmp(A_cstr(a), A_cstr(b), A_strlen(a)) == 0;
}

bool A_streq_String_String(const string_t* restrict a, const string_t* restrict b) {
    if(A_strlen(a) != A_strlen(b))
        return false;

    return strncmp(A_cstr(a), A_cstr(b), A_strlen(a)) == 0;
}

bool A_strieq_Str_Str(const str_t* restrict a, const str_t* restrict b) {
    if(A_strlen(a) != A_strlen(b))
        return false;

    for(size_t i = 0; i < A_strlen(a); i++) {
        if(A_tolower(A_strat(a, i)) != A_tolower(A_strat(b, i)))
            return false;
    }

    return true;
}

bool A_strieq_Str_String(const str_t* restrict a, const string_t* restrict b) {
    if(A_strlen(a) != A_strlen(b))
        return false;

    for(size_t i = 0; i < A_strlen(a); i++) {
        if(A_tolower(A_strat(a, i)) != A_tolower(A_strat(b, i)))
            return false;
    }

    return true;
}

bool A_strieq_String_Str(const string_t* restrict a, const str_t* restrict b) {
    if(A_strlen(a) != A_strlen(b))
        return false;

    for(size_t i = 0; i < A_strlen(a); i++) {
        if(A_tolower(A_strat(a, i)) != A_tolower(A_strat(b, i)))
            return false;
    }

    return true;
}

bool A_strieq_String_String(const string_t* restrict a, const string_t* restrict b) {
    if(A_strlen(a) != A_strlen(b))
        return false;

    for(size_t i = 0; i < A_strlen(a); i++) {
        if(A_tolower(A_strat(a, i)) != A_tolower(A_strat(b, i)))
            return false;
    }

    return true;
}

size_t A_strpbrk_Str_Str(const str_t* restrict a, const str_t* restrict b) {
    char ca = '\0', cb = '\0';
    size_t i = 0;
    A_STR_ENUMERATE(a, i, ca, A_STR_ITER(b, cb, 
        if(ca == cb) return i; 
    ));

    return A_NPOS;
}

size_t A_strpbrk_Str_String(const str_t* restrict a, const string_t* restrict b) {
    char ca = '\0', cb = '\0';
    size_t i = 0;
    A_STR_ENUMERATE(a, i, ca, A_STR_ITER(b, cb, 
        if(ca == cb) return i; 
    ));

    return A_NPOS;
}

size_t A_strpbrk_String_Str(const string_t* restrict a, const str_t* restrict b) {
    char ca = '\0', cb = '\0';
    size_t i = 0;
    A_STR_ENUMERATE(a, i, ca, A_STR_ITER(b, cb, 
        if(ca == cb) return i; 
    ));

    return A_NPOS;
}

size_t A_strpbrk_String_String(const string_t* restrict a, const string_t* restrict b) {
    char ca = '\0', cb = '\0';
    size_t i = 0;
    A_STR_ENUMERATE(a, i, ca, A_STR_ITER(b, cb, 
        if(ca == cb) return i; 
    ));

    return A_NPOS;
}

size_t A_strrpbrk_Str_Str(const str_t* restrict a, const str_t* restrict b) {
    char ca = '\0', cb = '\0';
    size_t i = 0;
    A_STR_ENUMERATE_REV(a, i, ca, A_STR_ITER_REV(b, cb, 
        if(ca == cb) return i; 
    ));

    return A_NPOS;
}

size_t A_strrpbrk_Str_String(const str_t* restrict a, const string_t* restrict b) {
    char ca = '\0', cb = '\0';
    size_t i = 0;
    A_STR_ENUMERATE_REV(a, i, ca, A_STR_ITER_REV(b, cb, 
        if(ca == cb) return i; 
    ));

    return A_NPOS;
}

size_t A_strrpbrk_String_Str(const string_t* restrict a, const str_t* restrict b) {
    char ca = '\0', cb = '\0';
    size_t i = 0;
    A_STR_ENUMERATE_REV(a, i, ca, A_STR_ITER_REV(b, cb, 
        if(ca == cb) return i; 
    ));

    return A_NPOS;
}

size_t A_strrpbrk_String_String(const string_t* restrict a, const string_t* restrict b) {
    char ca = '\0', cb = '\0';
    size_t i = 0;
    A_STR_ENUMERATE_REV(a, i, ca, A_STR_ITER_REV(b, cb, 
        if(ca == cb) return i; 
    ));

    return A_NPOS;
}

size_t A_strpcnt_Str_Str(const str_t* restrict a, const str_t* restrict b) {
    char ca = '\0', cb = '\0';
    size_t i = 0;
    A_STR_ENUMERATE(a, i, ca, A_STR_ITER(b, cb, 
        if(ca != cb) return i; 
    ));

    return A_NPOS;
}

size_t A_strpcnt_Str_String(const str_t* restrict a, const string_t* restrict b) {
    char ca = '\0', cb = '\0';
    size_t i = 0;
    A_STR_ENUMERATE(a, i, ca, A_STR_ITER(b, cb, 
        if(ca != cb) return i; 
    ));

    return A_NPOS;
}

size_t A_strpcnt_String_Str(const string_t* restrict a, const str_t* restrict b) {
    char ca = '\0', cb = '\0';
    size_t i = 0;
    A_STR_ENUMERATE(a, i, ca, A_STR_ITER(b, cb, 
        if(ca != cb) return i; 
    ));

    return A_NPOS;
}

size_t A_strpcnt_String_String(const string_t* restrict a, const string_t* restrict b) {
    char ca = '\0', cb = '\0';
    size_t i = 0;
    A_STR_ENUMERATE(a, i, ca, A_STR_ITER(b, cb, 
        if(ca != cb) return i; 
    ));

    return A_NPOS;
}

size_t A_strrpcnt_Str_Str(const str_t* restrict a, const str_t* restrict b) {
    char ca = '\0', cb = '\0';
    size_t i = 0;
    A_STR_ENUMERATE_REV(a, i, ca, A_STR_ITER_REV(b, cb, 
        if(ca == cb) return i; 
    ));

    return A_NPOS;
}

size_t A_strrpcnt_Str_String(const str_t* restrict a, const string_t* restrict b) {
    char ca = '\0', cb = '\0';
    size_t i = 0;
    A_STR_ENUMERATE_REV(a, i, ca, A_STR_ITER_REV(b, cb, 
        if(ca == cb) return i; 
    ));

    return A_NPOS;
}

size_t A_strrpcnt_String_Str(const string_t* restrict a, const str_t* restrict b) {
    char ca = '\0', cb = '\0';
    size_t i = 0;
    A_STR_ENUMERATE_REV(a, i, ca, A_STR_ITER_REV(b, cb, 
        if(ca == cb) return i; 
    ));

    return A_NPOS;
}

size_t A_strrpcnt_String_String(const string_t* restrict a, const string_t* restrict b) {
    char ca = '\0', cb = '\0';
    size_t i = 0;
    A_STR_ENUMERATE_REV(a, i, ca, A_STR_ITER_REV(b, cb, 
        if(ca == cb) return i; 
    ));

    return A_NPOS;
}

size_t A_strstr_Str_Str(const str_t* restrict a, const str_t* restrict b) {
    if(A_strlen(b) > A_strlen(a))
        return A_NPOS;

    if(A_strlen(b) == A_strlen(b))
        return A_streq(a, b);

    char c = A_strat(b, 0);
    for(size_t i = 0; i < A_strlen(a) - A_strlen(b); i++) {
        if(A_strat(a, i) == c) {
            if(A_memcmp(A_cstr(a), A_cstr(b), A_strlen(b)) == 0)
                return i;
        }
    }

    return A_NPOS;
}

size_t A_strstr_Str_String(const str_t* restrict a, const string_t* restrict b) {
    if(A_strlen(b) > A_strlen(a))
        return A_NPOS;

    if(A_strlen(b) == A_strlen(b))
        return A_streq(a, b);

    char c = A_strat(b, 0);
    for(size_t i = 0; i < A_strlen(a) - A_strlen(b); i++) {
        if(A_strat(a, i) == c) {
            if(A_memcmp(A_cstr(a), A_cstr(b), A_strlen(b)) == 0)
                return i;
        }
    }

    return A_NPOS;
}

size_t A_strstr_String_Str(const string_t* restrict a, const str_t* restrict b) {
    if(A_strlen(b) > A_strlen(a))
        return A_NPOS;

    if(A_strlen(b) == A_strlen(b))
        return A_streq(a, b);

    char c = A_strat(b, 0);
    for(size_t i = 0; i < A_strlen(a) - A_strlen(b); i++) {
        if(A_strat(a, i) == c) {
            if(A_memcmp(A_cstr(a), A_cstr(b), A_strlen(b)) == 0)
                return i;
        }
    }

    return A_NPOS;
}

size_t A_strstr_String_String(const string_t* restrict a, const string_t* restrict b) {
    if(A_strlen(b) > A_strlen(a))
        return A_NPOS;

    if(A_strlen(b) == A_strlen(b))
        return A_streq(a, b);

    char c = A_strat(b, 0);
    for(size_t i = 0; i < A_strlen(a) - A_strlen(b); i++) {
        if(A_strat(a, i) == c) {
            if(A_memcmp(A_cstr(a), A_cstr(b), A_strlen(b)) == 0)
                return i;
        }
    }

    return A_NPOS;
}

size_t A_strrstr_Str_Str(const str_t* restrict a, const str_t* restrict b) {
    if(A_strlen(b) > A_strlen(a))
        return A_NPOS;

    if(A_strlen(b) == A_strlen(b))
        return A_streq(a, b);

    char c = A_strat(b, 0);
    for(size_t i = A_strlen(a); i > A_strlen(a) - A_strlen(b); i--) {
        if(A_strat(a, i) == c) {
            if(A_memcmp(A_cstr(a), A_cstr(b), A_strlen(b)) == 0)
                return i;
        }
    }

    return A_NPOS;
}

size_t A_strrstr_Str_String(const str_t* restrict a, const string_t* restrict b) {
    if(A_strlen(b) > A_strlen(a))
        return A_NPOS;

    if(A_strlen(b) == A_strlen(b))
        return A_streq(a, b);

    char c = A_strat(b, 0);
    for(size_t i = A_strlen(a); i > A_strlen(a) - A_strlen(b); i--) {
        if(A_strat(a, i) == c) {
            if(A_memcmp(A_cstr(a), A_cstr(b), A_strlen(b)) == 0)
                return i;
        }
    }

    return A_NPOS;
}

size_t A_strrstr_String_Str(const string_t* restrict a, const str_t* restrict b) {
    if(A_strlen(b) > A_strlen(a))
        return A_NPOS;

    if(A_strlen(b) == A_strlen(b))
        return A_streq(a, b);

    char c = A_strat(b, 0);
    for(size_t i = A_strlen(a); i > A_strlen(a) - A_strlen(b); i--) {
        if(A_strat(a, i) == c) {
            if(A_memcmp(A_cstr(a), A_cstr(b), A_strlen(b)) == 0)
                return i;
        }
    }

    return A_NPOS;
}

size_t A_strrstr_String_String(const string_t* restrict a, const string_t* restrict b) {
    if(A_strlen(b) > A_strlen(a))
        return A_NPOS;

    if(A_strlen(b) == A_strlen(b))
        return A_streq(a, b);

    char c = A_strat(b, 0);
    for(size_t i = A_strlen(a); i > A_strlen(a) - A_strlen(b); i--) {
        if(A_strat(a, i) == c) {
            if(A_memcmp(A_cstr(a), A_cstr(b), A_strlen(b)) == 0)
                return i;
        }
    }

    return A_NPOS;
}

str_t A_substr_Str(const str_t* restrict s, size_t i, size_t len) {
    str_t n;

    if(i >= A_strlen(s)) {
        n.__data = NULL;
        n.__len  = 0;
        return n;
    }

    if(len >= A_strlen(s) - i)
        len = A_strlen(s) - i;

    n.__data = s->__data + i;
    n.__len  = len;    
    return n;
}

str_t A_substr_String(const string_t* restrict s, size_t i, size_t len) {
    str_t n;

    if(i >= A_strlen(s)) {
        n.__data = NULL;
        n.__len  = 0;
        return n;
    }

    if(len >= A_strlen(s) - i)
        len = A_strlen(s) - i;

    n.__data = s->__data + i;
    n.__len  = len;    
    return n;
}

string_t A_substring_Str(const str_t* restrict s, size_t i, size_t len) {
    string_t n;

    if(i >= A_strlen(s)) {
        n.__data = NULL;
        n.__len  = 0;
        return n;
    }
    
    if(len >= A_strlen(s) - i)
        len = A_strlen(s) - i;

    A_strext(&n, len);
    A_strncpy(&n, 0, s, i, len);
    return n;
}

string_t A_substring_String(const string_t* restrict s, size_t i, size_t len) {
    string_t n;

    if(i >= A_strlen(s)) {
        n.__data = NULL;
        n.__len  = 0;
        return n;
    }
    
    if(len >= A_strlen(s) - i)
        len = A_strlen(s) - i;

    A_strext(&n, len);
    A_strncpy(&n, 0, s, i, len);
    return n;
}

void A_strclear(string_t* restrict s) {
   *A_stratp(s, 0) = '\0';
   s->__len = 0;
}

void A_strdrop(string_t* restrict s) {
    A_strshrnk(s, A_strlen(s) + 1);
}

