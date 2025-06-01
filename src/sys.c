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

#if A_TARGET_PLATFORM_IS_XBOX
static uint64_t s_counterFreq;
static uint64_t s_timeBase;
#endif // A_TARGET_PLATFORM_IS_XBOX

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
    int i = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER);
    assert(i == 0);
    if (i < 0) {
        fprintf(stderr, "Sys_Init: Failed to initialize SDL: %s", SDL_GetError());
        exit(-1);
    }
#else
    LARGE_INTEGER count;
    BOOL b = QueryPerformanceCounter(&count);
    assert(b != FALSE);
    s_timeBase = count.QuadPart;
    LARGE_INTEGER freq;
    b = QueryPerformanceFrequency(&freq);
    assert(b != FALSE);
    s_counterFreq = freq.QuadPart;

    XDEVICE_PREALLOC_TYPE deviceTypes[1];
    deviceTypes[0].DeviceType      = XDEVICE_TYPE_GAMEPAD;
    deviceTypes[0].dwPreallocCount = 4;
    
    XInitDevices(A_countof(deviceTypes), deviceTypes);
#endif // !A_TARGET_PLATFORM_IS_XBOX
    vid_width = Dvar_RegisterInt(
        "vid_width", DVAR_FLAG_NONE, VID_WIDTH_DEFAULT, 1, INT_MAX);
    vid_height = Dvar_RegisterInt(
        "vid_height", DVAR_FLAG_NONE, VID_HEIGHT_DEFAULT, 1, INT_MAX);

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
    vid_xpos = Dvar_RegisterInt("vid_xpos", DVAR_FLAG_NONE, 0, 0, INT_MAX);
    vid_ypos = Dvar_RegisterInt("vid_ypos", DVAR_FLAG_NONE, 0, 0, INT_MAX);
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
#if !A_TARGET_PLATFORM_IS_XBOX
bool Sys_HandleEvent(void) {
    SDL_Event ev;
    if (SDL_PollEvent(&ev)) {
        switch (ev.type) {
        case SDL_KEYDOWN:
            if (ev.key.keysym.sym == SDLK_ESCAPE) {
                Sys_NormalExit(1);
            }
            else {
                IN_Key_Down(CL_ClientWithKbmFocus(),
                    IN_Key_SDLKToKeycode(ev.key.keysym.sym));
            }
            break;
        case SDL_KEYUP:
            IN_Key_Up(CL_ClientWithKbmFocus(),
                IN_Key_SDLKToKeycode(ev.key.keysym.sym));
            break;
        case SDL_MOUSEBUTTONDOWN:
            IN_Mouse_Down(CL_ClientWithKbmFocus(), IN_Mouse_SDLButtonToIndex(ev.button.button));
            break;
        case SDL_MOUSEBUTTONUP:
            IN_Mouse_Up(CL_ClientWithKbmFocus(), IN_Mouse_SDLButtonToIndex(ev.button.button));
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
            // FIXME: add controller support for multiple local clients
        case SDL_CONTROLLERDEVICEREMOVED:
        case SDL_CONTROLLERDEVICEADDED:
        case SDL_CONTROLLERBUTTONUP:
        case SDL_CONTROLLERAXISMOTION:
            SDL_GameController* controller = IN_GPad_SDLController(0);
            SDL_Joystick* joystick = SDL_GameControllerGetJoystick(controller);
            switch (ev.type) {
            case SDL_CONTROLLERDEVICEADDED:
                if (!IN_LocalClientHasGPad(0))
                    IN_GPad_Add(0, ev.cdevice.which);
                break;
            case SDL_CONTROLLERDEVICEREMOVED:
                if (ev.cdevice.which == SDL_JoystickInstanceID(joystick) && IN_LocalClientHasGPad(0))
                    IN_GPad_Remove(0);
                break;
            case SDL_CONTROLLERBUTTONDOWN:
                if (ev.cdevice.which != SDL_JoystickInstanceID(joystick) || !IN_LocalClientHasGPad(0))
                    break;

                GPadButtonCode button = IN_GPad_ButtonFromSDL(ev.cbutton.button);
                IN_GPad_Down(0, button);
                break;
            case SDL_CONTROLLERBUTTONUP:
                if (ev.cdevice.which != SDL_JoystickInstanceID(joystick) || !IN_LocalClientHasGPad(0))
                    break;

                button = IN_GPad_ButtonFromSDL(ev.cbutton.button);
                IN_GPad_Up(0, button);
                break;
            case SDL_CONTROLLERAXISMOTION:
                if (ev.cdevice.which != SDL_JoystickInstanceID(joystick) || !IN_LocalClientHasGPad(0))
                    break;

                float x = 0.0f, y = 0.0f, value = 0.0f;
                switch (ev.caxis.axis) {
                case SDL_CONTROLLER_AXIS_LEFTX:
                    x = 1.0f / (float)((Sint32)ev.caxis.value + 32768);
                    IN_GPad_MoveStick(0, IN_GPAD_STICK_LEFT, x, 0.0f);
                    break;
                case SDL_CONTROLLER_AXIS_LEFTY:
                    y = 1.0f / (float)((Sint32)ev.caxis.value + 32768);
                    IN_GPad_MoveStick(0, IN_GPAD_STICK_LEFT, 0.0f, y);
                    break;
                case SDL_CONTROLLER_AXIS_RIGHTX:
                    x = 1.0f / (float)((Sint32)ev.caxis.value + 32768);
                    IN_GPad_MoveStick(0, IN_GPAD_STICK_RIGHT, x, 0.0f);
                    break;
                case SDL_CONTROLLER_AXIS_RIGHTY:
                    y = 1.0f / (float)((Sint32)ev.caxis.value + 32768);
                    IN_GPad_MoveStick(0, IN_GPAD_STICK_RIGHT, 0.0f, y);
                    break;
                case SDL_CONTROLLER_AXIS_TRIGGERLEFT:
                    value = 1.0f / (float)((Sint32)ev.caxis.value + 32768);
                    IN_GPad_MoveTrigger(0, IN_GPAD_TRIGGER_LEFT, value);
                    break;
                case SDL_CONTROLLER_AXIS_TRIGGERRIGHT:
                    value = 1.0f / (float)((Sint32)ev.caxis.value + 32768);
                    IN_GPad_MoveTrigger(0, IN_GPAD_TRIGGER_RIGHT, value);
                    break;
                default:
                    assert(false);
                    break;
                }
                break;
            }
            break;
        }
        return true;
    }
    return false;
}
#endif // !A_TARGET_PLATFORM_IS_XBOX

uint64_t Sys_Milliseconds(void) {
#if !A_TARGET_PLATFORM_IS_XBOX
    return (uint64_t)SDL_GetTicks();
#else
    LARGE_INTEGER count;
    BOOL b = QueryPerformanceCounter(&count);
    assert(b != FALSE);
    return (count.QuadPart - s_timeBase) / (s_counterFreq * 1000);
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
