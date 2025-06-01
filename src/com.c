#include "acommon/a_string.h"

#include "cg_cgame.h"
#include "cl_client.h"
#include "cmd_commands.h"
#include "con_console.h"
#include "devcon.h"
#include "devgui.h"
#include "dvar.h"
#include "font.h"
#include "gfx.h"
#include "in_input.h"
#include "pm_pmove.h"
#include "sys.h"
#include "vm_vmem.h"

static uint64_t s_lastFrameTime;
static uint64_t s_deltaTime;

dvar_t* com_maxfps;

void Com_Quit_f(void) {
    Sys_NormalExit(3);
}

bool Com_Init(void) {
    VM_Init();
    Cmd_Init();
    Cmd_AddCommand("quit", Com_Quit_f);
    Dvar_Init();
    com_maxfps = Dvar_RegisterInt("com_maxfps", DVAR_FLAG_NONE, 165, 1, 1000);
    //Font_Init();
    PM_Init();
    CG_Init();
    R_Init();
    CL_Init();
#if !A_TARGET_PLATFORM_IS_XBOX
    DevGui_Init();
#endif // !A_TARGET_PLATFORM_IS_XBOX
    s_lastFrameTime = Sys_Milliseconds();
    s_deltaTime = s_lastFrameTime;
    return true;
}

bool Com_Frame(void) {
    uint64_t wait_msec = 1000 / (uint64_t)Dvar_GetInt(com_maxfps);
    while (Sys_Milliseconds() - s_lastFrameTime < wait_msec);

    s_deltaTime = Sys_Milliseconds() - s_lastFrameTime;
    s_lastFrameTime = Sys_Milliseconds();

    IN_Frame();

#if !A_TARGET_PLATFORM_IS_XBOX
    while (Sys_HandleEvent())
        ;

    DevCon_Frame();
#endif // !A_TARGET_PLATFORM_IS_XBOX

    CG_Frame(s_deltaTime);
    CL_Frame();
#if !A_TARGET_PLATFORM_IS_XBOX
    DevGui_Frame();
    for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
        if(!CG_LocalClientIsActive(i))
            continue;

        if (DevGui_HasText(i)) {
            char* t = DevGui_TakeText(i);
            Con_ProcessLocalInput(t, i);
            A_cstrfree(t);
        }
    }
    if (DevCon_HasText()) {
        char* t = DevCon_TakeText();
        Con_ProcessInput(t);
        A_cstrfree(t);
    }
#endif // !A_TARGET_PLATFORM_IS_XBOX
    
    R_Frame();

    return true;
}

uint64_t Com_LastFrameTimeDelta(void) {
    return s_deltaTime;
}

uint64_t Com_LastFrameTime(void) {
    return s_lastFrameTime;
}

void Com_Shutdown(void) {
#if !A_TARGET_PLATFORM_IS_XBOX
    DevGui_Shutdown();
#endif // !A_TARGET_PLATFORM_IS_XBOX
    CL_Shutdown();
    CG_Shutdown();
    R_Shutdown();
    //Font_Shutdown();
    Dvar_Unregister("com_maxfps");
    com_maxfps = NULL;
    Dvar_Shutdown();
    Cmd_Shutdown();
    VM_Shutdown();
}
