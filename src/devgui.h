#pragma once

#include "acommon/acommon.h"

#define DEVGUI_MAX_SAVED_LINES 16
#define DEVGUI_MAX_BUFFER 4096

A_EXTERN_C void  DevGui_Init    (void);
A_EXTERN_C bool  DevGui_HasText (size_t localClientNum);
A_EXTERN_C char* DevGui_TakeText(size_t localClientNum);
A_EXTERN_C void  DevGui_Frame   (void);
A_EXTERN_C void  DevGui_Shutdown(void);
