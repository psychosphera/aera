#pragma once

#include "acommon/acommon.h"
#include "acommon/a_type.h"

typedef enum print_msg_dest_t {
    CON_DEST_DEVCON,
    CON_DEST_CLIENT, // once DevGui printing is implemented, this will alias to
                     // DevCon and DevGui
    CON_DEST_ERR,
} print_msg_dest_t;

A_EXTERN_C void        Com_PrintMessage(print_msg_dest_t dest, 
                                        const char* msg);
A_EXTERN_C void        Com_Print       (print_msg_dest_t dest, 
                                        const char* fmt, ...);
A_EXTERN_C void        Com_Println     (print_msg_dest_t dest, 
                                        const char* fmt, ...);
A_EXTERN_C void        Com_DPrint      (print_msg_dest_t dest, 
                                        const char* fmt, ...);
A_EXTERN_C void        Com_DPrintln    (print_msg_dest_t dest, 
                                        const char* fmt, ...);
A_EXTERN_C A_NO_RETURN Com_Error       (int              ec,   
                                        const char* fmt, ...);
A_EXTERN_C A_NO_RETURN Com_Errorln     (int              ec,   
                                        const char* fmt, ...);