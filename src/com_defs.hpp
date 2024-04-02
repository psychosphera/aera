#pragma once

#include <cstddef>
#include <cstdint>

#include "acommon/acommon.h"

// can't #include sys.hpp because sys.hpp #includes this file
NO_RETURN Sys_NormalExit(int ec);
uint64_t Sys_Milliseconds();

constexpr size_t MAX_LOCAL_CLIENTS = 4;

struct RectDef {
	float x, y, w, h;
};

bool     Com_Init();
bool     Com_Frame();
uint64_t Com_LastFrameTime();
uint64_t Com_LastFrameTimeDelta();
void     Com_Shutdown();
