#pragma once

#include <SDL3/SDL.h>

#include "com_defs.h"
#include "dvar.h"

#define VID_WIDTH_DEFAULT  1024
#define VID_HEIGHT_DEFAULT 768

#define SYS_MAX_ARGV 256

typedef enum thread_t {
	THREAD_MAIN = 0,
} thread_t;

typedef struct SDLGlob {
    SDL_Window*   window;
#if A_RENDER_BACKEND_GL
    SDL_GLContext glContext;
#endif // A_RENDER_BACKEND_GL
} SDLGlob;
extern SDLGlob sys_sdlGlob;

extern dvar_t*     vid_width;
extern dvar_t*     vid_height;
extern dvar_t*     vid_xpos;
extern dvar_t*     vid_ypos;

A_EXTERN_C void Sys_Init          (const char** argv);
A_EXTERN_C bool Sys_HandleEvent   (void);
A_EXTERN_C bool Sys_AwaitingThread(thread_t thread);
A_EXTERN_C void Sys_Shutdown      (void);
//A_NO_RETURN Sys_NormalExit(int ec);
//uint64_t Sys_Milliseconds();
