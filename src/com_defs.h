#pragma once

#include <stddef.h>

#include "acommon/acommon.h"

// can't #include sys.hpp because sys.hpp #includes this file
A_EXTERN_C A_NO_RETURN Sys_NormalExit(int ec);
A_EXTERN_C uint64_t Sys_Milliseconds(void);

#define MAX_LOCAL_CLIENTS 4

typedef struct RectDef {
	float x, y, w, h;
} RectDef;

A_EXTERN_C bool     Com_Init(void);
A_EXTERN_C bool     Com_Frame(void);
A_EXTERN_C uint64_t Com_LastFrameTime(void);
A_EXTERN_C uint64_t Com_LastFrameTimeDelta(void);
A_EXTERN_C void     Com_Shutdown(void);
