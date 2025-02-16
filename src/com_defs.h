#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include "acommon/acommon.h"

// can't #include sys.hpp because sys.hpp #includes this file
A_NO_RETURN Sys_NormalExit(int ec);
uint64_t Sys_Milliseconds();

#define MAX_LOCAL_CLIENTS 4

typedef struct RectDef {
	float x, y, w, h;
} RectDef;

bool     Com_Init();
bool     Com_Frame();
uint64_t Com_LastFrameTime();
uint64_t Com_LastFrameTimeDelta();
void     Com_Shutdown();
