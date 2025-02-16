#pragma once

#include "com_defs.h"

A_EXTERN_C              void  DevCon_Init();
A_EXTERN_C              void  DevCon_Frame();
A_EXTERN_C A_NO_DISCARD bool  DevCon_HasText();
A_EXTERN_C A_NO_DISCARD char* DevCon_TakeText();
A_EXTERN_C              void  DevCon_PrintMessage(const char* s);
A_EXTERN_C              void  DevCon_Shutdown();
