#pragma once

#include "com_defs.h"

typedef enum thread_t {
	THREAD_MAIN = 0,
} thread_t;

#define VID_WIDTH_DEFAULT  1024
#define VID_HEIGHT_DEFAULT 768

#define SYS_MAX_ARGV 256

A_EXTERN_C void Sys_Init          (const char** argv);
A_EXTERN_C bool Sys_HandleEvent   (void);
A_EXTERN_C bool Sys_AwaitingThread(thread_t thread);
A_EXTERN_C void Sys_Shutdown      (void);
//A_NO_RETURN Sys_NormalExit(int ec);
//uint64_t Sys_Milliseconds();
