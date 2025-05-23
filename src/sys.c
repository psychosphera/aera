#include "sys.h"

#include <stdio.h>

#include "acommon/a_string.h"

#include "cl_client.h"
#include "devcon.h"
#include "dvar.h"
#include "gfx.h"
#include "in_input.h"

#if !A_TARGET_PLATFORM_IS_XBOX
SDLGlob sys_sdlGlob;
#endif // !A_TARGET_PLATFORM_IS_XBOX

dvar_t* vid_xpos;
dvar_t* vid_ypos;
dvar_t* vid_width;
dvar_t* vid_height;

static uint64_t s_timeBase;

//static size_t Sys_InitCmdline(const char** argv);
static void   Sys_InitThreads(void);
/*
static bool   Sys_CreateThread(
    thread_t thread, const std::string& name, int(*f)(void*)
);
*/

void Sys_Init(const char** argv) {
    A_UNUSED(argv);

#if !A_TARGET_PLATFORM_IS_XBOX
    s_timeBase = (uint64_t)SDL_GetTicks();

    SDL_Init(SDL_INIT_VIDEO);
#else
	assert(false && "unimplemented"); // FIXME
#endif // !A_TARGET_PLATFORM_IS_XBOX

    vid_width  = Dvar_RegisterInt(
        "vid_width", DVAR_FLAG_NONE, VID_WIDTH_DEFAULT,  1, INT_MAX
    );
    vid_height = Dvar_RegisterInt(
        "vid_hight", DVAR_FLAG_NONE, VID_HEIGHT_DEFAULT, 1, INT_MAX
    );

#if !A_TARGET_PLATFORM_IS_XBOX
    sys_sdlGlob.window = SDL_CreateWindow(
        "Halo 1 Map Viewer",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        Dvar_GetInt(vid_width),
        Dvar_GetInt(vid_height),
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
    );

    int x, y;
    SDL_GetWindowPosition(sys_sdlGlob.window, &x, &y);
    vid_xpos = Dvar_RegisterInt("vid_xpos", DVAR_FLAG_NONE, x, 0, INT_MAX);
    vid_ypos = Dvar_RegisterInt("vid_ypos", DVAR_FLAG_NONE, y, 0, INT_MAX);
    SDL_SetRelativeMouseMode(SDL_TRUE);

    if (sys_sdlGlob.window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        Sys_NormalExit(-2);
    }
#else
	assert(false && "unimplemented"); // FIXME
#endif // !A_TARGET_PLATFORM_IS_XBOX

    //Sys_InitCmdline(argv);
    Sys_InitThreads();
    IN_Init();
#if !A_TARGET_PLATFORM_IS_XBOX
    DevCon_Init();
#endif // !A_TARGET_PLATFORM_IS_XBOX
}

// Returns true if an event was handled, false if not 
// (most likely, if event queue was empty).
bool Sys_HandleEvent(void) {
#if !A_TARGET_PLATFORM_IS_XBOX
    SDL_Event ev;
    if (SDL_PollEvent(&ev)) {
        switch (ev.type) {
        case SDL_KEYDOWN:
            if (ev.key.keysym.sym == SDLK_ESCAPE) {
                Sys_NormalExit(1);
            } else {
                IN_Key_Down(CL_ClientWithKbmFocus(),
                    IN_Key_SDLKToKeycode(ev.key.keysym.sym));
            }
            break;
        case SDL_KEYUP:
            IN_Key_Up(CL_ClientWithKbmFocus(), 
                      IN_Key_SDLKToKeycode(ev.key.keysym.sym));
            break;
        case SDL_MOUSEBUTTONDOWN:
            IN_Mouse_Down(CL_ClientWithKbmFocus(), ev.button.button);
            break;
        case SDL_MOUSEBUTTONUP:
            IN_Mouse_Up(CL_ClientWithKbmFocus(), ev.button.button);
            break;
        case SDL_MOUSEMOTION:
            IN_Mouse_Move(
                CL_ClientWithKbmFocus(), ev.motion.xrel, ev.motion.yrel
            );
            break;
        case SDL_WINDOWEVENT:
            switch (ev.window.type) {
            case SDL_WINDOWEVENT_SIZE_CHANGED:
                Dvar_SetInt(vid_width, ev.window.data1);
                Dvar_SetInt(vid_height, ev.window.data2);
                R_WindowResized();
                break;
            case SDL_WINDOWEVENT_MOVED:
                Dvar_SetInt(vid_xpos, ev.window.data1);
                Dvar_SetInt(vid_ypos, ev.window.data2);
                break;
            case SDL_WINDOWEVENT_CLOSE:
                SDL_DestroyWindow(sys_sdlGlob.window);
                Sys_NormalExit(2);
                break;
            }
            break;
        }

        return true;
    }
#else
	assert(false && "unimplemented");
#endif // !A_TARGET_PLATFORM_IS_XBOX
    return false;
}

uint64_t Sys_Milliseconds(void) {
#if !A_TARGET_PLATFORM_IS_XBOX
    return (uint64_t)SDL_GetTicks() - s_timeBase;
#else
	assert(false && "unimplemented");
	return 0;
#endif // !A_TARGET_PLATFORM_IS_XBOX
}

#if !A_TARGET_PLATFORM_IS_XBOX
SDL_Thread* sys_hThreads[32];
#endif // !A_TARGET_PLATFORM_IS_XBOX
int(*sys_threadFuncs[32])(void*);
bool sys_awaitingThreads[32];

int Sys_ThreadMain(void* data) {
    return sys_threadFuncs[(int)data](data);
}

void Sys_InitThreads(void) {

}

/*
bool Sys_CreateThread(
    thread_t thread, const std::string& name, int(*f)(void*)
) {
    sys_threadFuncs.at(thread) = f;
    SDL_Thread* t = SDL_CreateThread(
        Sys_ThreadMain, name.c_str(), (void*)thread
    );
    if (t == nullptr)
        return false;

    sys_hThreads.at(thread) = t;
    return true;
}
*/

bool Sys_AwaitingThread(thread_t thread) {
    return sys_awaitingThreads[thread];
}

void Sys_WaitThread(thread_t thread) {
#if !A_TARGET_PLATFORM_IS_XBOX
    SDL_WaitThread(sys_hThreads[thread], NULL);
#else 
	assert(false && "unimplemented"); // FIXME
#endif // !A_TARGET_PLATFORM_IS_XBOX
}

void Sys_ShutdownThreads(void) {

}

// str_t sys_argv[SYS_MAX_ARGV];
// size_t sys_argc = 0;

// size_t Sys_InitCmdline(const char** argv) {
//     if(argv == NULL)
//         return 0;

//     if(argv[0] == NULL)
//         return 0;
    
//     size_t argc = 0;
//     for(; argv[argc] != NULL; argc++) {
//         str_t arg = A_str(argv[argc]);
//         sys_argv[argc] = arg;
//     }
    
//     sys_argc = argc;
//     return argc;
// }

// A_NO_DISCARD str_t Sys_Argv(size_t i) {
//     if(i >= sys_argc)
//         return A_str();
//     else
//         return sys_argv[i];
// }

// void Sys_ShutdownCmdline() {
//     sys_argc = 0;
//     A_memset(&sys_argv, 0, sizeof(sys_argv));
// }

A_NO_RETURN Sys_Exit(int ec) {
    A_exit(ec);
}

void Sys_Shutdown(void) {
#if !A_TARGET_PLATFORM_IS_XBOX
    DevCon_Shutdown();
#endif // !A_TARGET_PLATFORM_IS_XBOX
    Sys_ShutdownThreads();
    //Sys_ShutdownCmdline();
    IN_Shutdown();
#if !A_TARGET_PLATFORM_IS_XBOX
    SDL_DestroyWindow(sys_sdlGlob.window);
    SDL_Quit();
#endif // !A_TARGET_PLATFORM_IS_XBOX
}

A_NO_RETURN Sys_NormalExit(int ec) {
    Com_Shutdown();
    Sys_Shutdown();
    Sys_Exit(ec);
}
