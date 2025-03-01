#include "gfx_backend.h"

#include <stdio.h>

#include <GL/glew.h>
#include <SDL3/SDL.h>

#include "com_print.h"
#include "dvar.h"
#include "gfx.h"
#include "sys.h"

extern SDL_Window* g_sdlWindow;
A_EXTERN_C dvar_t* r_vsync;
A_EXTERN_C dvar_t* r_fullscreen;
A_EXTERN_C dvar_t* r_noBorder;

static SDL_GLContext s_glContext;

A_EXTERN_C void RB_Init(void) {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, 
                        SDL_GL_CONTEXT_PROFILE_CORE);
#if _DEBUG
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG);
#endif // _DEBUG
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    s_glContext = SDL_GL_CreateContext(g_sdlWindow);
    if (s_glContext == NULL) {
        printf("GL context creation failed: %s\n", SDL_GetError());
        Sys_NormalExit(-1);
    }

    GLenum err = glewInit();
    if (err != GLEW_OK) {
        printf("GLEW init failed: %s", glewGetErrorString(err));
        Sys_NormalExit(-2);
    }
}

extern dvar_t* vid_width;
extern dvar_t* vid_height;
extern dvar_t* vid_xpos;
extern dvar_t* vid_ypos;

A_EXTERN_C bool RB_EnableVsync(bool enable) {
    return SDL_GL_SetSwapInterval((int)enable) == 0;
}

A_EXTERN_C void RB_BeginFrame(void) {
    if (Dvar_WasModified(r_vsync)) {
        bool enable = Dvar_GetBool(r_vsync);
        if (!RB_EnableVsync(enable)) {
            Com_Println(
                CON_DEST_ERR, "Failed to %s vsync: %s",
                enable ? "enable" : "disable", SDL_GetError()
            );
        }
    }

    if (Dvar_WasModified(r_fullscreen)) {
        if (Dvar_GetBool(r_fullscreen)) {
            Dvar_LatchValue(vid_width);
            Dvar_LatchValue(vid_height);
            Dvar_LatchValue(vid_xpos);
            Dvar_LatchValue(vid_ypos);
            SDL_DisplayID d = SDL_GetDisplayForWindow(g_sdlWindow);
            const SDL_DisplayMode* mode = SDL_GetCurrentDisplayMode(d);
            SDL_SetWindowSize(g_sdlWindow, mode->w, mode->h + 1);
            Dvar_SetInt(vid_width, mode->w);
            Dvar_SetInt(vid_height, mode->h);
            R_WindowResized();
            SDL_SetWindowPosition(g_sdlWindow, 0, 0);
            SDL_SetWindowResizable(g_sdlWindow, SDL_FALSE);
            Dvar_SetBool(r_fullscreen, true);
        }
        else {
            Dvar_SetBool(r_fullscreen, false);
            SDL_SetWindowResizable(g_sdlWindow, SDL_TRUE);
            Dvar_RestoreValue(vid_xpos);
            Dvar_RestoreValue(vid_ypos);
            Dvar_RestoreValue(vid_width);
            Dvar_RestoreValue(vid_height);
            SDL_SetWindowPosition(g_sdlWindow, 
                                  Dvar_GetInt(vid_xpos), 
                                  Dvar_GetInt(vid_ypos));
            SDL_SetWindowSize(g_sdlWindow, 
                              Dvar_GetInt(vid_width), 
                              Dvar_GetInt(vid_height));
            R_WindowResized();
        }

        Dvar_ClearModified(r_fullscreen);
    }

    if (Dvar_WasModified(r_noBorder)) {
        if (Dvar_GetBool(r_noBorder))
            SDL_SetWindowBordered(g_sdlWindow, SDL_FALSE);
        else
            SDL_SetWindowBordered(g_sdlWindow, SDL_TRUE);

        Dvar_ClearModified(r_noBorder);
    }
}

A_EXTERN_C void RB_EndFrame(void) {
    SDL_GL_SwapWindow(g_sdlWindow);
}

A_EXTERN_C void RB_Shutdown(void) {
    SDL_GL_DeleteContext(s_glContext);
}
