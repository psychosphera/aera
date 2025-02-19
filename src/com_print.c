#include "com_print.h"

#include <stdarg.h>
#include <stdio.h>

#include "devcon.h"
#include "sys.h"

void Com_PrintMessage(print_msg_dest_t dest, const char* msg) {
    if (msg == NULL)
        return;

    if (dest == CON_DEST_CLIENT)
        dest = CON_DEST_DEVCON;

    if (dest == CON_DEST_ERR || dest == CON_DEST_ERR)
        fprintf(stderr, "%s", msg);
    else if (dest == CON_DEST_DEVCON)
        DevCon_PrintMessage(msg);
}

char* Com_VFormat(char* buf, size_t n, const char* fmt, va_list ap) {
    if (vsnprintf(buf, n, fmt, ap) < 0)
        return NULL;
    return buf;
}

static char s_printBuf[4096];
void Com_Print(print_msg_dest_t dest, const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    Com_PrintMessage(dest, Com_VFormat(s_printBuf, sizeof(s_printBuf), fmt, ap));
}

void Com_Println(print_msg_dest_t dest, const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    Com_PrintMessage(dest, Com_VFormat(s_printBuf, sizeof(s_printBuf), fmt, ap));
    Com_PrintMessage(dest, "\n");
}

void Com_DPrint(print_msg_dest_t dest, const char* fmt, ...) {
#if _DEBUG
    va_list ap;
    va_start(ap, fmt);
    Com_PrintMessage(dest, Com_VFormat(s_printBuf, sizeof(s_printBuf), fmt, ap));
#else
    A_UNUSED(dest);
    A_UNUSED(fmt);
#endif // _DEBUG
}

void Com_DPrintln(print_msg_dest_t dest, const char* fmt, ...) {
#if _DEBUG
    va_list ap;
    va_start(ap, fmt);
    Com_PrintMessage(dest, Com_VFormat(s_printBuf, sizeof(s_printBuf), fmt, ap));
    Com_PrintMessage(dest, "\n");
#else
    A_UNUSED(dest);
    A_UNUSED(fmt);
#endif // _DEBUG
}

A_NO_RETURN Com_Error(int ec, const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    Com_PrintMessage(CON_DEST_ERR, Com_VFormat(s_printBuf, sizeof(s_printBuf), fmt, ap));
    Sys_NormalExit(ec);
}

void Com_Errorln(int ec, const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    Com_PrintMessage(CON_DEST_ERR, Com_VFormat(s_printBuf, sizeof(s_printBuf), fmt, ap));
    Com_PrintMessage(CON_DEST_ERR, "\n");
    Sys_NormalExit(ec);
}