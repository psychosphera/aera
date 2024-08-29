#pragma once

#include <array>
#include <charconv>
#include <deque>
#include <format>
#include <vector>

#include <glm/glm.hpp>

#include "acommon/acommon.h"
#include "acommon/a_type.h"
#include "acommon/a_format.hpp"

#include "devcon.hpp"
#include "sys.hpp"

enum print_msg_dest_t {
    CON_DEST_DEVCON,
    CON_DEST_CLIENT, // once DevGui printing is implemented, this will alias to
                     // DevCon and DevGui
    CON_DEST_ERR,
};

void inline Com_PrintMessage(
    print_msg_dest_t dest, std::string_view msg
) {
    const char* fmt = "%*s";

    if (dest == CON_DEST_CLIENT)
        dest = CON_DEST_DEVCON;

    if (dest == CON_DEST_ERR || dest == CON_DEST_ERR)
        fprintf(stderr, fmt, msg.size(), msg.data());
    else if (dest == CON_DEST_DEVCON)
        DevCon_PrintMessage(msg);
}

template<typename ...Args>
void inline Com_Print(
    print_msg_dest_t dest, std::string_view fmt, Args&&... args
) {
    Com_PrintMessage(dest, A_Format(fmt, args...));
}

// Shorthand for Com_Print(dest, "{}", t)
template<typename T>
void inline Com_Print(print_msg_dest_t dest, T t) {
    Com_Print(dest, "{}", t);
}

template<typename ...Args>
void inline Com_Println(
    print_msg_dest_t dest, std::string_view fmt, Args&&... args
) {
    Com_Print(dest, "{}\n", A_Format(fmt, args...));
}

// Shorthand for Com_Println(dest, "")
void inline Com_Println(print_msg_dest_t dest) {
    Com_Println(dest, "");
}

// Shorthand for Com_Println(dest, "{}", t)
template<typename T>
void inline Com_Println(print_msg_dest_t dest, T t) {
    Com_Println(dest, "{}", t);
}

// Alias for Com_Print in Debug mode, nop in Release mode
#ifdef _DEBUG
template<typename ...Args>
void inline Com_DPrint(
    print_msg_dest_t dest, std::string_view fmt, Args&&... args
) {
    Com_Print(dest, fmt, args...);
}
#else // _DEBUG
template<typename ...Args>
void inline Com_DPrint(
    print_msg_dest_t dest, std::string_view fmt, Args&&... args
) {
    NOP();
}
#endif // _DEBUG

// Shorthand for Com_DPrint(CON_DEST_CLIENT, fmt, args...)
template<typename ...Args>
void inline Com_DPrint(
    std::string_view fmt, Args&&... args
) {
    Com_DPrint(CON_DEST_CLIENT, fmt, args...);
}

// Shorthand for Com_DPrint(dest, "{}", t)
template<typename T>
void inline Com_DPrint(print_msg_dest_t dest, T t) {
    Com_DPrint(dest, "{}", t);
}

// Shorthand for Com_DPrint(CON_DEST_CLIENT, t)
template<typename T>
void inline Com_DPrint(T t) {
    Com_DPrint(CON_DEST_CLIENT, t);
}

template<typename ...Args>
void inline Com_DPrintln(
    print_msg_dest_t dest, std::string_view fmt, Args&&... args
) {
    Com_DPrint(
        dest, "{}\n", A_Format(fmt, args...)
    );
}

// Shorthand for Com_DPrintln(CON_DEST_CLIENT, fmt, args...)
template<typename ...Args>
void inline Com_DPrintln(std::string_view fmt, Args&&... args) {
    Com_DPrintln(CON_DEST_CLIENT, fmt, args...);
}

// Shorthand for Com_DPrintln(dest, "")
void inline Com_DPrintln(print_msg_dest_t dest) {
    Com_DPrintln(dest, "");
}

// Shorthand for Com_DPrintln(CON_DEST_CLIENT)
void inline Com_DPrintln() {
    Com_DPrintln(CON_DEST_CLIENT);
}

// Shorthand for Com_DPrintln(dest, "{}", t)
template<typename T>
void inline Com_DPrintln(print_msg_dest_t dest, T t) {
    Com_DPrintln(dest, "{}", t);
}

// Shorthand for Com_DPrintln(CON_DEST_CLIENT, t)
template<typename T>
void inline Com_DPrintln(T t) {
    Com_DPrintln(CON_DEST_CLIENT, t);
}

template<typename ...Args>
A_NO_RETURN inline Com_Error(int ec, std::string_view fmt, Args&&... args) {
    Com_Print(
        CON_DEST_ERR, "FATAL ERROR: {}",
        A_Format(fmt, args...)
    );
    Sys_NormalExit(ec);
}

// Shorthand for Com_Error(-1, fmt, args...)
template<typename ...Args>
A_NO_RETURN inline Com_Error(std::string_view fmt, Args&&... args) {
    Com_Error(-1, fmt, args...);
}

// Shorthand for Com_Error(ec, "{}", t)
template<typename T>
A_NO_RETURN inline Com_Error(int ec, T t) {
    Com_Error(ec, "{}", t);
}

// Shorthand for Com_Error(-1, t)
template<typename T>
A_NO_RETURN inline Com_Error(T t) {
    Com_Error(-1, t);
}

template<typename ...Args>
A_NO_RETURN inline Com_Errorln(int ec, std::string_view fmt, Args&&... args) {
    Com_Println(
        CON_DEST_ERR, "FATAL ERROR: {} ()",
        A_Format(fmt, args...),
        ec
    );
#if _DEBUG
    assert(false);
#endif // _DEBUG
    Sys_NormalExit(ec);
}

// Shorthand for Com_Errorln(-1, fmt, args...)
template<typename ...Args>
A_NO_RETURN inline Com_Errorln(std::string_view fmt, Args&&... args) {
    Com_Errorln(-1, fmt, args...);
}

// Shorthand for Com_Errorln(ec, "{}", t)
template<typename T>
A_NO_RETURN inline Com_Errorln(int ec, T t) {
    Com_Errorln(ec, "{}", t);
}

// Shorthand for Com_Errorln(-1, t)
template<typename T>
A_NO_RETURN inline Com_Errorln(T t) {
    Com_Errorln(-1, t);
}
