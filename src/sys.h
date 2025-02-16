#pragma once

#include "com_defs.h"

enum thread_t {
	THREAD_MAIN = 0,
};

#define VID_WIDTH_DEFAULT  1024
#define VID_HEIGHT_DEFAULT 768

#define SYS_MAX_ARGV 256

void Sys_Init          (const char** argv);
bool Sys_HandleEvent   (void);
bool Sys_AwaitingThread(thread_t thread);
void Sys_Shutdown      (void);
//A_NO_RETURN Sys_NormalExit(int ec);
//uint64_t Sys_Milliseconds();
