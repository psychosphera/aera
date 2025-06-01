#include "gfx_backend.h"

#include <stdio.h>

#if A_RENDER_BACKEND_GL
#include <GL/glew.h>
#endif // A_RENDER_BACKEND_GL

#include "com_print.h"
#include "dvar.h"
#include "gfx.h"
#include "sys.h"

static bool s_windowResizeable;

bool RB_WindowResizeable(void) {
    return s_windowResizeable;
}

void RB_EnableWindowResize(bool resizeable) {
#if A_TARGET_PLATFORM_IS_XBOX
	assert(resizeable == false);
	return;
#else
    if (resizeable == RB_WindowResizeable())
        return;

    SDL_SetWindowResizable(sys_sdlGlob.window, resizeable);
    s_windowResizeable = resizeable;
    if (!resizeable) {
        int w = Dvar_GetInt(vid_width);
        int h = Dvar_GetInt(vid_height);
        vid_width = Dvar_ReregisterInt("vid_width", 
                                       DVAR_FLAG_READONLY,
                                       w, 0, INT_MAX);
        vid_height = Dvar_ReregisterInt("vid_height", 
                                        DVAR_FLAG_READONLY,
                                        h, 0, INT_MAX);
    }
#endif // A_TARGET_PLATFORM_IS_XBOX
}

A_EXTERN_C void RB_Init(void) {
#if A_RENDER_BACKEND_GL
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, 
                        SDL_GL_CONTEXT_PROFILE_CORE);
#if _DEBUG
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG);
#endif // _DEBUG
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    SDL_SetHint(SDL_HINT_VIDEO_MINIMIZE_ON_FOCUS_LOSS, "0");

    sys_sdlGlob.glContext = SDL_GL_CreateContext(sys_sdlGlob.window);
    if (sys_sdlGlob.glContext == NULL) {
        printf("GL context creation failed: %s\n", SDL_GetError());
        Sys_NormalExit(-1);
    }

    GLenum err = glewInit();
    if (err != GLEW_OK) {
        printf("GLEW init failed: %s", glewGetErrorString(err));
        Sys_NormalExit(-2);
    }
    
    RB_EnableWindowResize(true);
#elif A_RENDER_BACKEND_D3D9 || A_RENDER_BACKEND_D3D8
    RB_EnableWindowResize(false);
#endif // A_RENDER_BACKEND_GL
}

A_EXTERN_C bool RB_EnableVsync(bool enable) {
#if A_RENDER_BACKEND_GL
    return SDL_GL_SetSwapInterval((int)enable) == 0;
#else
    (void)enable;
    return false;
#endif // A_RENDER_BACKEND_GL
}

A_EXTERN_C void RB_BeginFrame(void) {
    if (Dvar_WasModified(r_vsync)) {
        bool enable = Dvar_GetBool(r_vsync);
        if (!RB_EnableVsync(enable)) {
#if !A_TARGET_PLATFORM_IS_XBOX
            Com_Println(
                CON_DEST_ERR, "Failed to %s vsync: %s",
                enable ? "enable" : "disable", SDL_GetError()
            );
#endif // !A_TARGET_PLATFORM_IS_XBOX
        }
    }

#if !A_TARGET_PLATFORM_IS_XBOX
    if (Dvar_WasModified(r_fullscreen) && RB_WindowResizeable()) {
        if (Dvar_GetBool(r_fullscreen)) {
            Dvar_LatchValue(vid_width);
            Dvar_LatchValue(vid_height);
            Dvar_LatchValue(vid_xpos);
            Dvar_LatchValue(vid_ypos);
            int d = SDL_GetWindowDisplayIndex(sys_sdlGlob.window);
            SDL_DisplayMode mode;
            SDL_GetCurrentDisplayMode(d, &mode);
            SDL_SetWindowFullscreen(sys_sdlGlob.window, SDL_WINDOW_FULLSCREEN_DESKTOP);
            Dvar_SetInt(vid_width,  mode.w);
            Dvar_SetInt(vid_height, mode.h);
            R_WindowResized();
            SDL_SetWindowPosition(sys_sdlGlob.window, 0, 0);
            SDL_SetWindowResizable(sys_sdlGlob.window, SDL_FALSE);
            Dvar_SetBool(r_fullscreen, true);
        }
        else {
            Dvar_SetBool(r_fullscreen, false);
            SDL_SetWindowResizable(sys_sdlGlob.window, SDL_TRUE);
            Dvar_RestoreValue(vid_xpos);
            Dvar_RestoreValue(vid_ypos);
            Dvar_RestoreValue(vid_width);
            Dvar_RestoreValue(vid_height);
            SDL_SetWindowPosition(sys_sdlGlob.window, 
                                  Dvar_GetInt(vid_xpos), 
                                  Dvar_GetInt(vid_ypos));
            SDL_SetWindowSize(sys_sdlGlob.window, 
                              Dvar_GetInt(vid_width), 
                              Dvar_GetInt(vid_height));
            R_WindowResized();
        }

        Dvar_ClearModified(r_fullscreen);
    } else {
        if (Dvar_WasModified(vid_width) || Dvar_WasModified(vid_height)) {
            SDL_SetWindowSize(sys_sdlGlob.window, 
                              Dvar_GetInt(vid_width), 
                              Dvar_GetInt(vid_height));
            Dvar_ClearModified(vid_width);
            Dvar_ClearModified(vid_height);
            R_WindowResized();
        }
    }

    if (!Dvar_GetBool(r_fullscreen)) {
        if (Dvar_WasModified(vid_xpos) || Dvar_WasModified(vid_ypos)) {
            SDL_SetWindowPosition(sys_sdlGlob.window, 
                                  Dvar_GetInt(vid_xpos), 
                                  Dvar_GetInt(vid_ypos));
            Dvar_ClearModified(vid_xpos);
            Dvar_ClearModified(vid_ypos);
        }
    }

    if (Dvar_WasModified(r_noBorder)) {
        if (Dvar_GetBool(r_noBorder))
            SDL_SetWindowBordered(sys_sdlGlob.window, SDL_FALSE);
        else
            SDL_SetWindowBordered(sys_sdlGlob.window, SDL_TRUE);

        Dvar_ClearModified(r_noBorder);
    }
#endif // !A_TARGET_PLATFORM_IS_XBOX
}

A_EXTERN_C void RB_EndFrame(void) {
#if A_RENDER_BACKEND_GL
    SDL_GL_SwapWindow(sys_sdlGlob.window);
#endif // A_RENDER_BACKEND_GL
}

A_EXTERN_C void RB_Shutdown(void) {
#if A_RENDER_BACKEND_GL
    SDL_GL_DeleteContext(sys_sdlGlob.glContext);
#endif // A_RENDER_BACKEND_GL
}
