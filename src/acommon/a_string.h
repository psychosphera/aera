#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
#include <stdint.h>

#include "acommon.h"

// ============================================================================
// These currently don't work, ignore them.
#define A_STR_ENUMERATE(s, i, c) \
    for(i = 0, c = (char)A_strat(s, 0); i < A_strlen(s); i++)

#define A_STR_ITER(s, c) \
    for(size_t i = 0, c = (char)A_strat(s, 0); i < A_strlen(s); i++)

#define A_STR_ENUMERATE_REV(s, i, c) \
    for(i = A_strlen(s), c = (char)A_strat(s, A_strlen(s); i > 0; i--)

#define A_STR_ITER_REV(s, c) \
    for(size_t i = A_strlen(s), c = (char)A_strat(s, A_strlen(s); i > 0; i--)
// ============================================================================

// ============================================================================
// Basically the C `mem*` functions from `string.h`. They're basically 
// identical to their stdlib counterparts, except all pointers are `restrict`
A_EXTERN_C bool A_memcmp (
    const void* A_RESTRICT a, const void* A_RESTRICT b, size_t n
);
A_EXTERN_C void A_memcpy(
    void* A_RESTRICT dest, const void* A_RESTRICT src, size_t n
);
A_EXTERN_C void*  A_memchr (const void* A_RESTRICT p, char c, size_t n);
A_EXTERN_C void*  A_memrchr(const void* A_RESTRICT p, char c, size_t n);
A_EXTERN_C void   A_memset (      void* A_RESTRICT p, char c, size_t n);
// ============================================================================

// This is its own function, rather than being an overload of `A_strlen` 
// because it's O(n) rather than O(1). It should only ever really be used to
// create a `str_t` from a C-style string.
A_EXTERN_C size_t A_cstrlen(const char* A_RESTRICT p);

// ============================================================================
// These are two primary types that the rest of the string library uses.
//
// `str_t` is analogous to `std::string_view` in C++. It *does not* own the
// underlying data (`string_t`, C-style string, etc.), and the underlying data 
// cannot be modified through it. Changes in the underlying data's size are not
// reflected in any `str_t`s pointing to it, so a `str_t` can be rendered 
// invalid if the underlying data is shrunk to a size less than the `str_t`'s
// length.
typedef struct str_s {
    const char* A_RESTRICT __data;
    size_t                 __len;
} str_t;

// `string_t` is analogous to `std::string` in C++. It owns the underlying data
// and can do what it pleases with it. It shall be valid from creation by 
// `A_string` until destruction by `A_strdrop`, after which point it can be
// reinitialized. 
//
// In order to prevent erroneous frees by `A_strdrop`, `string_t`s should 
// either be copied with `A_strdup` or moved with `A_strmove`, never directly
// copied (e.g., by `A_memset`, `operator=`, etc.).
typedef struct string_s {
    char* A_RESTRICT __data;
    size_t           __len;
    size_t           __cap;
} string_t;

// Analogous to std::string::npos.
#define A_NPOS SIZE_MAX
// ============================================================================

// Creates a `str_t` from a pointer and size.
// 
// Intended to be used within the `A_literal` macro, but can be used 
// standalone.
A_EXTERN_C str_t A_literal_internal(const char* s, size_t c);

// Creates a `str_t` from a literal
#define A_literal(s) A_literal_internal(s, A_countof(s))

// ============================================================================
// The following macros mangle function names, similar to how C++ does.
// They are meant to be used in concert with `_Generic` to facilitate
// "overloading" in C.
//
// If a specific "overload" of a function needs to be called, rather than
// using the `_Generic`, ALWAYS use these macros. Do not call them "manually"
// by appending the suffixes used here. They can and probably will change.
#define A_STRING_MANGLE_VOID(name)    name##_Void
#define A_STRING_MANGLE_CHAR(name)    name##_Char
#define A_STRING_MANGLE_CSTR(name)    name##_Cstr
#define A_STRING_MANGLE_STR(name)     name##_Str
#define A_STRING_MANGLE_STRING(name)  name##_String
#define A_STRING_MANGLE_SIZE_T(name)  name##_SizeT
#define A_STRING_MANGLE_LITERAL(name) name##_Literal

#define A_STRING_MANGLE_STR_STR(name)       name##_Str_Str
#define A_STRING_MANGLE_STR_STRING(name)    name##_Str_String
#define A_STRING_MANGLE_STRING_STR(name)    name##_String_Str
#define A_STRING_MANGLE_STRING_STRING(name) name##_String_String
// ============================================================================

// ============================================================================
// These macros declare mangled functions with the given name and return 
// type/attributes.
#define A_STRING_DECLARE_VOID(attr_ret, name) \
    attr_ret A_STRING_MANGLE_VOID(name)(void)

#define A_STRING_DECLARE_CHAR(attr_ret, name, c, ...) \
    attr_ret A_STRING_MANGLE_CHAR(name)(char c __VA_OPT__(,) __VA_ARGS__)

#define A_STRING_DECLARE_CSTR(attr_ret, name, s, ...) \
    attr_ret A_STRING_MANGLE_CSTR(name) \
        (const char* A_RESTRICT s __VA_OPT__(,) __VA_ARGS__)

#define A_STRING_DECLARE_STR(attr_ret, name, s, ...) \
    attr_ret A_STRING_MANGLE_STR(name) \
        (const str_t* A_RESTRICT s __VA_OPT__(,) __VA_ARGS__)

#define A_STRING_DECLARE_STRING(attr_ret, name, s, ...) \
    attr_ret A_STRING_MANGLE_STRING(name)( \
        string_t* A_RESTRICT s __VA_OPT__(,) __VA_ARGS__ \
    )

#define A_STRING_DECLARE_STR_STR(attr_ret, name, s, t, ...) \
    attr_ret A_STRING_MANGLE_STR_STR(name)( \
        const str_t* A_RESTRICT s, const str_t* A_RESTRICT t __VA_OPT__(,) \
        __VA_ARGS__ \
    )

#define A_STRING_DECLARE_STR_STRING(attr_ret, name, s, t, ...) \
    attr_ret A_STRING_MANGLE_STR_STRING(name)( \
        const str_t* A_RESTRICT s, const string_t* A_RESTRICT t __VA_OPT__(,) \
        __VA_ARGS__ \
    )

#define A_STRING_DECLARE_STR2(attr_ret, name, s, t, ...) \
    A_STRING_DECLARE_STR_STR(attr_ret, name, s, t, __VA_ARGS__); \
    A_STRING_DECLARE_STR_STRING(attr_ret, name, s, t, __VA_ARGS__)

#define A_STRING_DECLARE_STRING_STR(attr_ret, name, s, t, ...) \
    attr_ret A_STRING_MANGLE_STRING_STR(name)( \
        string_t* A_RESTRICT s, const str_t* A_RESTRICT t __VA_OPT__(,) \
        __VA_ARGS__ \
    )

#define A_STRING_DECLARE_STRING_STRING(attr_ret, name, s, t, ...) \
    attr_ret A_STRING_MANGLE_STRING_STRING(name)( \
        string_t* A_RESTRICT s, const string_t* A_RESTRICT t __VA_OPT__(,) \
        __VA_ARGS__ \
    )

#define A_STRING_DECLARE_STRING2(attr_ret, name, s, t, ...) \
    A_STRING_DECLARE_STRING_STR(attr_ret, name, s, t, __VA_ARGS__); \
    A_STRING_DECLARE_STRING_STRING(attr_ret, name, s, t, __VA_ARGS__)

#define A_STRING_DECLARE_STRING_CONST(attr_ret, name, s, ...) \
    attr_ret A_STRING_MANGLE_STRING(name)( \
        const string_t* A_RESTRICT s __VA_OPT__(,) __VA_ARGS__ \
    )

#define A_STRING_DECLARE_STRING_STR_CONST(attr_ret, name, s, t, ...) \
    attr_ret A_STRING_MANGLE_STRING_STR(name)( \
        const string_t* A_RESTRICT s, const str_t* A_RESTRICT t __VA_OPT__(,) \
        __VA_ARGS__ \
    )

#define A_STRING_DECLARE_STRING_STRING_CONST(attr_ret, name, s, t, ...) \
    attr_ret A_STRING_MANGLE_STRING_STRING(name)( \
        const string_t* A_RESTRICT s, \
        const string_t* A_RESTRICT t __VA_OPT__(,) __VA_ARGS__ \
    )

#define A_STRING_DECLARE_STRING2_CONST(attr_ret, name, s, t, ...) \
    A_STRING_DECLARE_STRING_STR_CONST(attr_ret, name, s, t, __VA_ARGS__); \
    A_STRING_DECLARE_STRING_STRING_CONST(attr_ret, name, s, t, __VA_ARGS__)

#define A_STRING_DECLARE_BOTH(attr_ret, name, s, ...) \
    A_STRING_DECLARE_STR(attr_ret, name, s __VA_OPT__(,) __VA_ARGS__); \
    A_STRING_DECLARE_STRING(attr_ret, name, s __VA_OPT__(,) __VA_ARGS__)

#define A_STRING_DECLARE_BOTH_CONST(attr_ret, name, s, ...) \
    A_STRING_DECLARE_STR(attr_ret, name, s __VA_OPT__(,) __VA_ARGS__); \
    A_STRING_DECLARE_STRING_CONST(attr_ret, name, s __VA_OPT__(,) __VA_ARGS__)

#define A_STRING_DECLARE_BOTH2(attr_ret, name, s, t, ...) \
    A_STRING_DECLARE_STR2(attr_ret, name, s, t __VA_OPT__(,) __VA_ARGS__); \
    A_STRING_DECLARE_STRING2_CONST(attr_ret, name, s, t __VA_OPT__(,) \
        __VA_ARGS__ \
    )

#define A_STRING_DECLARE_BOTH2_CONST(attr_ret, name, s, t, ...) \
    A_STRING_DECLARE_STR2(attr_ret, name, s, t __VA_OPT__(,) \
        __VA_ARGS__ \
    ); \
    A_STRING_DECLARE_STRING2_CONST(attr_ret, name, s, t __VA_OPT__(,) \
        __VA_ARGS__ \
    )

#define A_STRING_DECLARE_INTEGRAL(attr_ret, name, s, ...) \
    attr_ret A_STRING_MANGLE_SIZE_T(name)(size_t s __VA_OPT__(,) __VA_ARGS__)

#define A_STRING_DECLARE_LITERAL(attr_ret, name, s, ...) \
    attr_ret A_STRING_MANGLE_LITERAL(name)( \
        const string_t* A_RESTRICT s __VA_OPT__(,) __VA_ARGS__ \
    )
// ============================================================================

// ============================================================================
// These macros match an unmangled function name to its mangled counterpart
// in `_Generic` association lists.
#define A_STRING_GENERIC_MATCH_VOID(f) \
    void: A_STRING_MANGLE_VOID(f)

#define A_STRING_GENERIC_MATCH_CHAR(f) \
    A_GENERIC_MATCH_CONST(char, A_STRING_MANGLE_CHAR(f))

#define A_STRING_GENERIC_MATCH_CSTR(f) \
    const char* A_RESTRICT: f

#define A_STRING_GENERIC_MATCH_BOTH(f) \
    A_GENERIC_MATCH_CONST(str_t*, A_STRING_MANGLE_STR(f)), \
    A_GENERIC_MATCH_CONST(string_t*, A_STRING_MANGLE_STRING(f))

#define A_STRING_GENERIC_MATCH_BOTH2(s, f) \
    A_GENERIC_MATCH_CONST(str_t*, (_Generic((s), \
        A_STRING_GENERIC_MATCH_BOTH(A_STRING_MANGLE_STR(f)))) \
    ), A_GENERIC_MATCH_CONST(string_t*, (_Generic((s), \
        A_STRING_GENERIC_MATCH_BOTH(A_STRING_MANGLE_STRING(f))))) \

#define A_STRING_GENERIC_BOTH(s, f) (_Generic((s), \
    A_STRING_GENERIC_MATCH_BOTH(f) \
))

#define A_STRING_GENERIC_BOTH2(s, t, f) (_Generic((s), \
    A_STRING_GENERIC_MATCH_BOTH2(t, f) \
))

#define A_STRING_GENERIC_MATCH_INTEGRAL(f) \
    A_GENERIC_MATCH_INTEGRAL(A_STRING_MANGLE_SIZE_T(f))
// ============================================================================

// ============================================================================
// These macros declare and call C++ overloads for string-related functions.
#ifdef __cplusplus
#define A_STRING_CXX_DECLARE_OVERLOAD_CSTR(attr_ret, name, s, ...) \
    inline attr_ret name (const char* A_RESTRICT s __VA_OPT__(,) __VA_ARGS__)
#endif // __cplusplus

#ifdef __cplusplus
#define A_STRING_CXX_CALL_OVERLOAD_CSTR(name, s, ...) \
    A_STRING_MANGLE_CSTR(name)(s __VA_OPT__(,) __VA_ARGS__)
#endif // __cplusplus

#ifdef __cplusplus
#define A_STRING_CXX_CALL_OVERLOAD_LITERAL(name, s, ...) \
    A_STRING_MANGLE_LITERAL(name)(s __VA_OPT__(,) __VA_ARGS__)
#endif // __cplusplus

#ifdef __cplusplus
#define A_STRING_CXX_DECLARE_OVERLOAD_STR(attr_ret, name, s, ...) \
    inline attr_ret name(const str_t* A_RESTRICT s __VA_OPT__(,) __VA_ARGS__)
#endif // __cplusplus

#ifdef __cplusplus
#define A_STRING_CXX_CALL_OVERLOAD_STR(name, s, ...) \
    A_STRING_MANGLE_STR(name)(s __VA_OPT__(,) __VA_ARGS__)
#endif // __cplusplus

#ifdef __cplusplus
#define A_STRING_CXX_DECLARE_OVERLOAD_STRING(attr_ret, name, s, ...) \
    inline attr_ret name (string_t* A_RESTRICT s __VA_OPT__(,) __VA_ARGS__)
#endif // __cplusplus

#ifdef __cplusplus
#define A_STRING_CXX_CALL_OVERLOAD_STRING(name, s, ...) \
    A_STRING_MANGLE_STRING(name)(s __VA_OPT__(,) __VA_ARGS__)
#endif // __cplusplus

#ifdef __cplusplus
#define A_STRING_CXX_DECLARE_OVERLOAD_STRING_CONST(attr_ret, name, s, ...) \
    inline attr_ret name ( \
        const string_t* A_RESTRICT s __VA_OPT__(,) __VA_ARGS__ \
    )
#endif // __cplusplus

#ifdef __cplusplus
#define A_STRING_CXX_CALL_OVERLOAD_STRING_CONST(name, s, ...) \
    A_STRING_MANGLE_STRING(name)(s __VA_OPT__(,) __VA_ARGS__)
#endif // __cplusplus
// ============================================================================

// ============================================================================
// These macros define C++ overloads for string-related functions.
#ifdef __cplusplus
#define A_STRING_CXX_OVERLOAD_VOID(attr_ret, name) \
    inline attr_ret name (void) { \
        return A_STRING_MANGLE_VOID(name)(); \
    } 
#endif

#ifdef __cplusplus
#define A_STRING_CXX_OVERLOAD_CHAR(attr_ret, name) \
    inline attr_ret name (char c) { \
        return A_STRING_MANGLE_CHAR(name)(c); \
    } 
#endif

#ifdef __cplusplus
#define A_STRING_CXX_OVERLOAD_CSTR(attr_ret, name) \
    inline attr_ret name (const char* A_RESTRICT s) { \
        return A_STRING_MANGLE_CSTR(name)(s); \
    } 
#endif

#ifdef __cplusplus
#define A_STRING_CXX_OVERLOAD_STR(attr_ret, name) \
    inline attr_ret name (const str_t* A_RESTRICT s) { \
        return A_STRING_MANGLE_STR(name)(s); \
    } 
#endif

#ifdef __cplusplus
#define A_STRING_CXX_OVERLOAD_STRING(attr_ret, name) \
    inline attr_ret name (string_t* A_RESTRICT s) { \
        return A_STRING_MANGLE_STRING(name)(s); \
    } 
#endif

#ifdef __cplusplus
#define A_STRING_CXX_OVERLOAD_STRING_CONST(attr_ret, name) \
    inline attr_ret name (const string_t* A_RESTRICT s) { \
        return A_STRING_MANGLE_STRING(name)(s); \
    } 
#endif

#ifdef __cplusplus
#define A_STRING_CXX_OVERLOAD_BOTH(attr_ret, name) \
    A_STRING_CXX_OVERLOAD_STR   (attr_ret, name) \
    A_STRING_CXX_OVERLOAD_STRING(attr_ret, name)
#endif

#ifdef __cplusplus
#define A_STRING_CXX_OVERLOAD_BOTH_CONST(attr_ret, name) \
    A_STRING_CXX_OVERLOAD_STR         (attr_ret, name) \
    A_STRING_CXX_OVERLOAD_STRING_CONST(attr_ret, name)
#endif

#ifdef __cplusplus
#define A_STRING_CXX_OVERLOAD_STRING2(attr_ret, name) \
    inline attr_ret name ( \
        string_t* A_RESTRICT s, const str_t* A_RESTRICT t \
    ) { \
        return A_STRING_MANGLE_STRING_STR(name)(s, t); \
    } \
    inline attr_ret name ( \
        string_t* A_RESTRICT s, const string_t* A_RESTRICT t \
    ) { \
        return A_STRING_MANGLE_STRING_STRING(name)(s, t); \
    } 
#endif

#ifdef __cplusplus
#define A_STRING_CXX_OVERLOAD_STRING2_CONST(attr_ret, name) \
    inline attr_ret name ( \
        const string_t* A_RESTRICT s, const str_t* A_RESTRICT t \
    ) { \
        return A_STRING_MANGLE_STRING_STR(name)(s, t); \
    } \
    inline attr_ret name ( \
        const string_t* A_RESTRICT s, const string_t* A_RESTRICT t \
    ) { \
        return A_STRING_MANGLE_STRING_STRING(name)(s, t); \
    } 
#endif

#ifdef __cplusplus
#define A_STRING_CXX_OVERLOAD_BOTH2(attr_ret, name) \
    inline attr_ret name ( \
        const str_t* A_RESTRICT s, const str_t* A_RESTRICT t \
    ) { \
        return A_STRING_MANGLE_STR_STR(name)(s, t); \
    } \
    inline attr_ret name ( \
        string_t* A_RESTRICT s, const str_t* A_RESTRICT t \
    ) { \
        return A_STRING_MANGLE_STRING_STR(name)(s, t); \
    } \
    inline attr_ret name ( \
        const str_t* A_RESTRICT s, const string_t* A_RESTRICT t \
    ) { \
        return A_STRING_MANGLE_STR_STRING(name)(s, t); \
    } \
    inline attr_ret name ( \
        string_t* A_RESTRICT s, const string_t* A_RESTRICT t \
    ) { \
        return A_STRING_MANGLE_STRING_STRING(name)(s, t); \
    }
#endif

#ifdef __cplusplus
#define A_STRING_CXX_OVERLOAD_BOTH2_CONST(attr_ret, name) \
    inline attr_ret name ( \
        const str_t* A_RESTRICT s, const str_t* A_RESTRICT t \
    ) { \
        return A_STRING_MANGLE_STR_STR(name)(s, t); \
    } \
    inline attr_ret name ( \
        const string_t* A_RESTRICT s, const str_t* A_RESTRICT t \
    ) { \
        return A_STRING_MANGLE_STRING_STR(name)(s, t); \
    } \
    inline attr_ret name ( \
        const str_t* A_RESTRICT s, const string_t* A_RESTRICT t \
    ) { \
        return A_STRING_MANGLE_STR_STRING(name)(s, t); \
    } \
    inline attr_ret name ( \
        const string_t* A_RESTRICT s, const string_t* A_RESTRICT t \
    ) { \
        return A_STRING_MANGLE_STRING_STRING(name)(s, t); \
    }
#endif

#ifdef __cplusplus
#define A_STRING_CXX_OVERLOAD_INTEGRAL(attr_ret, name) \
    inline attr_ret name (size_t n) { \
        return A_STRING_MANGLE_SIZE_T(name)(n); \
    } 
#endif

#ifdef __cplusplus
#define A_STRING_CXX_OVERLOAD_LITERAL(attr_ret, name) \
    inline attr_ret name (const char* s) { \
        return A_STRING_MANGLE_LITERAL(name)(s); \
    } 
#endif
// ============================================================================

A_STRING_DECLARE_VOID      (A_EXTERN_C str_t, A_str);
A_STRING_DECLARE_CSTR      (A_EXTERN_C str_t, A_str, s);
A_STRING_DECLARE_BOTH_CONST(A_EXTERN_C str_t, A_str, s);
#ifndef __cplusplus
// str_t A_str(T s) => T == `void`, cstr, `str_t*`, `[const] string_t*`
// Creates a `str_t` from a cstr, a `string_t`, or another `str_t`, 
// or an empty `str_t`.
// See the documentation of `str_t` for info on the circumstances where a
// `str_t` can be invalidated.
#define A_str(s) (_Generic((s), \
    A_STRING_GENERIC_MATCH_VOID(A_str), \
    A_STRING_GENERIC_MATCH_CSTR(A_str), \
    A_STRING_GENERIC_MATCH_BOTH(A_str) \
))(s)
#else
A_STRING_CXX_OVERLOAD_VOID      (str_t, A_str);
A_STRING_CXX_OVERLOAD_CSTR      (str_t, A_str);
A_STRING_CXX_OVERLOAD_BOTH_CONST(str_t, A_str);
#endif

A_STRING_DECLARE_BOTH_CONST(A_EXTERN_C string_t, A_string, s);
A_STRING_DECLARE_INTEGRAL  (A_EXTERN_C string_t, A_string, s);
#ifndef __cplusplus
// string_t A_string(T* s) => T == integral, `str_t`, `[const] string_t`
// Creates a `string_t` from a `str_t` or another `string_t`, or creates an
// empty string with a given capacity.
#define A_string(s) (_Generic((s), \
    A_STRING_GENERIC_MATCH_INTEGRAL(A_string), \
    A_STRING_GENERIC_MATCH_BOTH(A_string) \
))(s)
#else
A_STRING_CXX_OVERLOAD_BOTH_CONST(string_t, A_string);
A_STRING_CXX_OVERLOAD_INTEGRAL  (string_t, A_string);
#endif

A_STRING_DECLARE_STR    (A_EXTERN_C const char*, A_cstr, s);
A_STRING_DECLARE_STRING (A_EXTERN_C char*,       A_cstr, s);
A_STRING_DECLARE_LITERAL(A_EXTERN_C const char*, A_cstr, s);
#ifndef __cplusplus
// [const] char* A_cstr(T* s) => T == `str_t`, `[const] string_t`
// Gets a pointer to a null-terminated cstr from a `str_t` or `string_t`.
// If `T` == (non-const) `string_t`, the pointer is also not const. Otherwise,
// it is const.
#define A_cstr(s) (_Generic((s), \
    const str_t*:    A_STRING_MANGLE_STR    (A_cstr), \
          string_t*: A_STRING_MANGLE_STRING (A_cstr), \
    const string_t*: A_STRING_MANGLE_LITERAL(A_cstr) \
))(s)
#endif // __cplusplus

A_STRING_DECLARE_BOTH_CONST(A_EXTERN_C char, A_strat, s, size_t i);
#ifndef __cplusplus
// char A_strat(T* s, size_t i) => T == `str_t`, `[const] string_t`
// Gets the character at index `i` within `s`. If `i >= A_strlen(s)`, returns
// '\0'.
#define A_strat(s, i) A_STRING_GENERIC_BOTH(s, A_strat)(s, i)
#else
A_STRING_CXX_DECLARE_OVERLOAD_STR(char, A_strat, s, size_t i) {
    return A_STRING_CXX_CALL_OVERLOAD_STR(A_strat, s, i);
}
A_STRING_CXX_DECLARE_OVERLOAD_STRING(char, A_strat, s, size_t i) {
    return A_STRING_CXX_CALL_OVERLOAD_STRING(A_strat, s, i);
}
A_STRING_CXX_DECLARE_OVERLOAD_STRING_CONST(char, A_strat, s, size_t i) {
    return A_STRING_CXX_CALL_OVERLOAD_STRING_CONST(A_strat, s, i);
}
#endif // __cplusplus

A_STRING_DECLARE_STR    (A_EXTERN_C const char*, A_stratp, s, size_t i);
A_STRING_DECLARE_STRING (A_EXTERN_C       char*, A_stratp, s, size_t i);
A_STRING_DECLARE_LITERAL(A_EXTERN_C const char*, A_stratp, s, size_t i);
#ifndef __cplusplus
// [const] char* A_stratp(T* s, size_t i) => T == `str_t`, `[const] string_t`
// Gets a pointer to the character at index `i` within `s`. 
// If `i >= A_strlen(s)`, returns `NULL`. If `T` == (non-const) string_t, the
// pointer is also non-const. Otherwise, the pointer is const.
//
// `str_t` and `string_t` aren't guaranteed to be null-terminated, so this
// function should be used with care when interacting with cstr APIs.
#define A_stratp(s, i) (_Generic((s), \
    A_GENERIC_MATCH_CONST(str_t*, A_STRING_MANGLE_STR(A_stratp)), \
          string_t*: A_STRING_MANGLE_STRING(A_stratp), \
    const string_t*: A_STRING_MANGLE_LITERAL(A_stratp) \
))(s, i)
#else
A_STRING_CXX_DECLARE_OVERLOAD_STR(const char*, A_stratp, s, size_t i) {
    return A_STRING_CXX_CALL_OVERLOAD_STR(A_stratp, s, i);
}
A_STRING_CXX_DECLARE_OVERLOAD_STRING(char*, A_stratp, s, size_t i) {
    return A_STRING_CXX_CALL_OVERLOAD_STRING(A_stratp, s, i);
}
A_STRING_CXX_DECLARE_OVERLOAD_STRING_CONST(const char*, A_stratp, s, size_t i) {
    return A_STRING_CXX_CALL_OVERLOAD_LITERAL(A_stratp, s, i);
}
#endif // __cplusplus

A_STRING_DECLARE_BOTH_CONST(A_EXTERN_C size_t, A_strlen, s);
#ifndef __cplusplus
// size_t A_strlen(T* s) => T == `str_t`, `[const] string_t`
// Returns the length of `s`.
#define A_strlen(s) A_STRING_GENERIC_BOTH(s, A_strlen)(s)
#else
A_STRING_CXX_OVERLOAD_BOTH_CONST(size_t, A_strlen);
#endif // __cplusplus
       
// Returns the capacity of `s`.
A_EXTERN_C size_t A_strcap(const string_t* A_RESTRICT s);

A_EXTERN_C bool A_STRING_MANGLE_STR(A_strncpy)(
    string_t* A_RESTRICT dest, size_t dest_off, 
    const str_t* A_RESTRICT src, size_t src_off, 
    size_t n
);
A_EXTERN_C bool A_STRING_MANGLE_STRING(A_strncpy)(
    string_t* A_RESTRICT dest, size_t dest_off, 
    const string_t* A_RESTRICT src, size_t src_off,
    size_t n
);

#ifndef __cplusplus
// bool A_strncpy(
//     string_t* dest, size_t dest_off, 
//     T* src, size_t src_off, 
//     size_t n
// ) => T == `str_t`, `[const] string_t`
// 
// Copies `src[src_off..n]` into `dest[dest_off..n]`. 
//
// If `dest_off >= A_strlen(dest)` or `src_off >= A_strlen(src)`, this function
// is a nop.
//
// If `dest_off + n >= A_strlen(dest)` or `src_off + n >= A_strlen(src)`, the 
// copy is truncated.
//
// This function should never write out of bounds.
#define A_strncpy(d, do, s, so, n) \
    A_STRING_GENERIC_BOTH(s, A_strncpy)(d, do, s, so, n)
#else 
inline bool A_strncpy(
    string_t* A_RESTRICT dest, size_t dest_off, 
    const str_t* A_RESTRICT src, size_t src_off, 
    size_t n
) {
    return A_STRING_MANGLE_STR(A_strncpy)(dest, dest_off, src, src_off, n);
}
inline bool A_strncpy(
    string_t* A_RESTRICT dest, size_t dest_off, 
    const string_t* A_RESTRICT src, size_t src_off, 
    size_t n
) {
    return A_STRING_MANGLE_STRING(A_strncpy)(dest, dest_off, src, src_off, n);
}
#endif // __cplusplus

A_STRING_DECLARE_BOTH_CONST(A_EXTERN_C string_t, A_strdup, s);
#ifndef __cplusplus
// string_t A_strdup(T* s) => T == `str_t`, `[const] string_t`
// 
// Duplicates `s` into a new `string_t`.
#define A_strdup(s) A_STRING_GENERIC_BOTH(s, A_strdup)(s)
#else
A_STRING_CXX_OVERLOAD_BOTH_CONST(string_t, A_strdup);
#endif // __cplusplus

// Moves `s` into a new `string_t`, invalidating `s`.
A_EXTERN_C string_t A_strmove(string_t* A_RESTRICT s);

// Extends `s` by `n`.
A_EXTERN_C bool A_strext (string_t* A_RESTRICT s, size_t n);
// Pushes `c` onto the end of `s`.
A_EXTERN_C bool A_strpush(string_t* A_RESTRICT s, char   c);

// Shrinks `s` by `n`.
A_EXTERN_C bool A_strshrnk(string_t* A_RESTRICT s, size_t n);
// Pops the character at the end of `s`.
A_EXTERN_C char A_strpop  (string_t* A_RESTRICT s);

A_STRING_DECLARE_STRING2(A_EXTERN_C bool, A_strcat, s, t);
#ifndef __cplusplus
// bool A_strcat(string_t* dest, T* src) => T == `str_t`, `[const] string_t`
// 
// Concatenates `src` onto the end of `dest`.
#define A_strcat(d, s) A_STRING_GENERIC_BOTH(s, A_strcat)(d, s)
#else
A_STRING_CXX_OVERLOAD_STRING2(bool, A_strcat)
#endif

A_STRING_DECLARE_BOTH_CONST(A_EXTERN_C size_t, A_strchr, 
    s, char c, size_t off, size_t n
);
#ifndef __cplusplus
// size_t A_strchr(T* s, char c, size_t off, size_t n) => 
//      T == `str_t`, `[const] string_t`
//
// Returns the index of the first occurrence of `c` within `s[off..off + n]`.
#define A_strchr(s, c, off, n) A_STRING_GENERIC_BOTH(s, A_strchr)(s, c, off, n)
#else
inline size_t A_strchr(
    const str_t* A_RESTRICT s, char c, size_t off, size_t n
) { 
    return A_STRING_MANGLE_STR(A_strchr)(s, c, off, n);
} 
inline size_t A_strchr(
    const string_t* A_RESTRICT s, char c, size_t off, size_t n
) { 
    return A_STRING_MANGLE_STRING(A_strchr)(s, c, off, n); 
} 
#endif // __cplusplus

A_STRING_DECLARE_BOTH_CONST(A_EXTERN_C size_t, A_strrchr, 
    s, char c, size_t off, size_t n
);
#ifndef __cplusplus
// size_t A_strrchr(T* s, char c, size_t off, size_t n) => 
//      T == `str_t`, `[const] string_t`
//
// Returns the index of the last occurrence of `c` within `s[off..off + n]`.
#define A_strrchr(s, c) A_STRING_GENERIC_BOTH(s, A_strrchr)(s, c, off, n)
#else
inline size_t A_strrchr(
    const str_t* A_RESTRICT s, char c, size_t off, size_t n
) { 
    return A_STRING_MANGLE_STR(A_strrchr)(s, c, off, n); 
} 
inline size_t A_strrchr(
    const string_t* A_RESTRICT s, char c, size_t off, size_t n
) { 
    return A_STRING_MANGLE_STRING(A_strrchr)(s, c, off, n); 
} 
#endif // __cplusplus

A_STRING_DECLARE_BOTH_CONST(A_EXTERN_C bool, A_strcont, s, char c);
#ifndef __cplusplus
// bool A_strcont(T* s, char c) => T == `str_t`, `[const] string_t`
//
// Checks if `s` contains `c`. 
// Shorthand for `A_strchr(s, c, 0, A_NPOS) != A_NPOS`.
#define A_strcont(s, c) A_STRING_GENERIC_BOTH(s, A_strcont)(s, c)
#endif

A_STRING_DECLARE_BOTH2_CONST(A_EXTERN_C bool, A_strcmp, a, b);
#ifndef __cplusplus
// bool A_strcmp(T* a, U* b) => T == U == `str_t`, `[const] string_t`
//
// Compares `a` to `b`. 
//
// Returns true if `A_strlen(a) == A_strlen(b)` and 
// `A_strat(a, i) == A_strat(b, i)` for `i == 0..A_strlen(a)`,
// false otherwise.
#define A_strcmp(a, b) A_STRING_GENERIC_BOTH2(a, b, A_strcmp)(a, b)
#else
A_STRING_CXX_OVERLOAD_BOTH2_CONST(bool, A_strcmp)
#endif // __cplusplus

A_STRING_DECLARE_BOTH2_CONST(A_EXTERN_C bool, A_stricmp, a, b);
#ifndef __cplusplus
// bool A_stricmp(T* a, U* b) => T == U == `str_t`, `[const] string_t`
//
// Case insensitive version of `A_strcmp`.
//
// Returns true if `A_strlen(a) == A_strlen(b)` and 
// `A_tolower(A_strat(a, i)) == A_tolower(A_strat(b, i))` 
// for `i == 0..A_strlen(a)`, false otherwise.
//
// As an implementation detail, this function assumes `a` and `b` don't match
// in case, and calls `A_tolower` on every character of both, without first 
// checking if it needs to. Thus, it SHOULD NOT be used as a more generic form
// of `A_strcmp`, as it will have (potentially significantly) worse 
// performance.
#define A_stricmp(a, b) A_STRING_GENERIC_BOTH2(a, b, A_stricmp)(a, b)
#else
A_STRING_CXX_OVERLOAD_BOTH2_CONST(bool, A_stricmp)
#endif // __cplusplus

A_STRING_DECLARE_BOTH2_CONST(A_EXTERN_C size_t, A_strpbrk, a, b);
#ifndef __cplusplus
// bool A_strpbrk(T* a, U* b) => T == U == `str_t`, `[const] string_t`
//
// Finds the first occurrence of any character of `b` within `a`.
#define A_strpbrk(a, b) A_STRING_GENERIC_BOTH2(a, b, A_strpbrk)(a, b)
#else
A_STRING_CXX_OVERLOAD_BOTH2_CONST(size_t, A_strpbrk)
#endif // __cplusplus

A_STRING_DECLARE_BOTH2_CONST(A_EXTERN_C size_t, A_strrpbrk, a, b);
#ifndef __cplusplus
// bool A_strrpbrk(T* a, U* b) => T == U == `str_t`, `[const] string_t`
//
// Finds the last occurrence of any character of `b` within `a`.
#define A_strrpbrk(a, b) A_STRING_GENERIC_BOTH2(a, b, A_strrpbrk)(a, b)
#else
A_STRING_CXX_OVERLOAD_BOTH2_CONST(size_t, A_strrpbrk)
#endif // __cplusplus

A_STRING_DECLARE_BOTH2_CONST(A_EXTERN_C size_t, A_strpcnt, a, b);
#ifndef __cplusplus
// bool A_strpcnt(T* a, U* b) => T == U == `str_t`, `[const] string_t`
//
// Finds the first occurrence of any character not in `b` within `a`.
#define A_strpcnt(a, b) A_STRING_GENERIC_BOTH2(a, b, A_strpcnt)(a, b)
#else
A_STRING_CXX_OVERLOAD_BOTH2_CONST(size_t, A_strpcnt)
#endif // __cplusplus

A_STRING_DECLARE_BOTH2_CONST(A_EXTERN_C size_t, A_strrpcnt, a, b);
#ifndef __cplusplus
// bool A_strrpcnt(T* a, U* b) => T == U == `str_t`, `[const] string_t`
//
// Finds the last occurrence of any character not in `b` within `a`.
#define A_strrpcnt(a, b) A_STRING_GENERIC_BOTH2(a, b, A_strrpcnt)(a, b)
#else
A_STRING_CXX_OVERLOAD_BOTH2_CONST(size_t, A_strrpcnt)
#endif // __cplusplus

A_STRING_DECLARE_BOTH2_CONST(A_EXTERN_C size_t, A_strstr, a, b);
#ifndef __cplusplus
// bool A_strstr(T* a, U* b) => T == U == `str_t`, `[const] string_t`
//
// Finds the first occurrence of `b` within `a`.
#define A_strstr(a, b) A_STRING_GENERIC_BOTH2(a, b, A_strstr)(a, b)
#else
A_STRING_CXX_OVERLOAD_BOTH2_CONST(size_t, A_strstr)
#endif // __cplusplus

A_STRING_DECLARE_BOTH2_CONST(A_EXTERN_C size_t, A_strrstr, a, b);
#ifndef __cplusplus
// bool A_strrstr(T* a, U* b) => T == U == `str_t`, `[const] string_t`
//
// Finds the last occurrence of `b` within `a`.
#define A_strrstr(a, b) A_STRING_GENERIC_BOTH2(a, b, A_strrstr)(a, b)
#else
A_STRING_CXX_OVERLOAD_BOTH2_CONST(size_t, A_strrstr)
#endif // __cplusplus

A_STRING_DECLARE_BOTH_CONST(
    A_EXTERN_C str_t, A_substr, s, size_t i, size_t len
);
#ifndef __cplusplus
// str_t A_substr(T* s, size_t i, size_t len) 
//     => T == U == `str_t`, `[const] string_t`
//
// Creates a `str_t` pointing to `s[i..len]`. 
// Truncates if `i + len >= A_strlen(s)`.
#define A_substr(s, i, n) A_STRING_GENERIC_BOTH(s, A_substr)(s, i, n)
#else
inline str_t A_substr(const str_t* A_RESTRICT s, size_t i, size_t len) { 
    return A_STRING_MANGLE_STR(A_substr)(s, i, len); 
}
inline str_t A_substr(const string_t* A_RESTRICT s, size_t i, size_t len) {
    return A_STRING_MANGLE_STRING(A_substr)(s, i, len); 
}
#endif // __cplusplus

A_STRING_DECLARE_BOTH_CONST(
    A_EXTERN_C string_t, A_substring, s, size_t i, size_t len
);
#ifndef __cplusplus
// string_t A_substring(T* s, size_t i, size_t len) 
//     => T == U == `str_t`, `[const] string_t`
//
// Creates a `string_t` copied from `s[i..len]`. 
// Truncates if `i + len >= A_strlen(s)`.
#define A_substring(s, i, n) A_STRING_GENERIC_BOTH(s, A_substring)(s, i, n)
#else
inline string_t A_substring(const str_t* A_RESTRICT s, size_t i, size_t len) {
    return A_STRING_MANGLE_STR(A_substring)(s, i, len); 
}
inline string_t A_substring(
    const string_t* A_RESTRICT s, size_t i, size_t len
) { 
    return A_STRING_MANGLE_STRING(A_substring)(s, i, len); 
}
#endif // __cplusplus

A_STRING_DECLARE_BOTH_CONST(
    A_EXTERN_C size_t, A_strtok, s, char delim, size_t n, str_t* toks
);
#ifndef __cplusplus
// size_t A_strtok(T* s, char delim, size_t n, str_t* toks) 
//     => T == U == `str_t`, `[const] string_t`
//
// Tokenizes `s` around each occurrence of `delim`, not including `delim`, and
// copies up to `n` tokens into `toks`. Returns the number of tokens actually 
// copied into `toks`.
#define A_strtok(s, d, n, t) A_STRING_GENERIC_BOTH(s, A_strtok)(s, d, n, t)
#else
inline size_t A_strtok(
    const str_t* A_RESTRICT s, char delim, size_t n, str_t* toks
) {
    return A_STRING_MANGLE_STR(A_strtok)(s, delim, n, toks); 
}
inline size_t A_strtok(
    const string_t* A_RESTRICT s, char delim, size_t n, str_t* toks
) {
    return A_STRING_MANGLE_STRING(A_strtok)(s, delim, n, toks); 
}
#endif // __cplusplus

// Clears a `string_t`, setting its length to zero. No guarantees about its
// capacity.
A_EXTERN_C void A_strclear(string_t* A_RESTRICT s);
// Drops a `string_t`, freeing its allocation and setting its length and
// capacity to zero.
A_EXTERN_C void A_strdrop (string_t* A_RESTRICT s);

