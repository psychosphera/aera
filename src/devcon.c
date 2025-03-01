#include "devcon.h"

#include <stdio.h>
//#include <errno.h>

// for select() - select(stdin) doesn't work on Windows
// so don't include the headers there
#if !A_TARGET_OS_IS_WINDOWS
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#endif // !A_TARGET_OS_IS_WINDOWS

#include <SDL3/SDL.h>

#define DEVCON_MAX_IN 4096

bool       devcon_hasText;
SDL_Mutex* devcon_ioMutex;

#if !A_TARGET_OS_IS_WINDOWS
static char        devcon_in[DEVCON_MAX_IN];
static SDL_Mutex*  devcon_inMutex;
static SDL_Mutex*  devcon_selectMutex;
static fd_set      devcon_fds;
static timeval     devcon_timeval;
#endif

#if A_TARGET_OS_IS_WINDOWS
/*
static bool DevCon_StdinHasLine(void) {
    return false;
}
*/
#else 
static bool DevCon_StdinHasLine(void) {
    SDL_LockMutex(devcon_selectMutex);
    FD_ZERO(&devcon_fds);
    FD_CLR(STDIN_FILENO, &devcon_fds);
    FD_SET(STDIN_FILENO, &devcon_fds);

    if (select(1, &devcon_fds, NULL, NULL, &devcon_timeval) < 0) {
        SDL_UnlockMutex(devcon_selectMutex);
        Com_Errorln("DevCon: select() failed with errno=%d", errno);
        return false;
    }

    bool hasLine = FD_ISSET(STDIN_FILENO, &devcon_fds);
    SDL_UnlockMutex(devcon_selectMutex);
    return hasLine;
}
#endif

#if A_TARGET_OS_IS_WINDOWS
A_EXTERN_C void DevCon_Frame(void) {
    return;
}
#else
void DevCon_Frame(void) {
    // Don't even try to read a new line if the previous one hasn't 
    // been taken
    if (DevCon_HasText())
        return;

    // If stdin has a new line, read it.
    if (DevCon_StdinHasLine()) {
        // stdin and stdout aren't necessarily safe to concurrently 
        // access, so make sure that doesn't happen
        SDL_LockMutex(devcon_ioMutex);
        SDL_LockMutex(devcon_inMutex);
        fgets(devcon_in, sizeof(devcon_in), stdin);
        SDL_UnlockMutex(devcon_inMutex);
        SDL_UnlockMutex(devcon_ioMutex);
        devcon_hasText = true;
    }
}
#endif // A_TARGET_OS_IS_WINDOWS

#if A_TARGET_OS_IS_WINDOWS
A_EXTERN_C void DevCon_Init(void) {
    devcon_hasText = false;
    devcon_ioMutex = SDL_CreateMutex();
    DevCon_PrintMessage("DevCon doesn't work correctly on Windows.\n");
    DevCon_PrintMessage("Output works just fine but input doesn't.\n");
    DevCon_PrintMessage("Use DevGui for input instead.\n");
}
#else
A_EXTERN_C void DevCon_Init(void) {
    devcon_hasText = false;
    A_memset(devcon_in,       0, sizeof(devcon_in));
    A_memset(&devcon_timeval, 0, sizeof(devcon_timeval));
	devcon_inMutex     = SDL_CreateMutex();
    devcon_ioMutex     = SDL_CreateMutex();
    devcon_selectMutex = SDL_CreateMutex();
    DevCon_PrintMessage("Hello from DevCon!\n");
}
#endif // A_TARGET_OS_IS_WINDOWS

A_EXTERN_C A_NO_DISCARD bool DevCon_HasText(void) {
	return devcon_hasText;
}

#if A_TARGET_OS_IS_WINDOWS
A_EXTERN_C A_NO_DISCARD char* DevCon_TakeText(void) {
    return "";
}
#else
A_EXTERN_C A_NO_DISCARD char* DevCon_TakeText(void) {
    SDL_LockMutex(devcon_inMutex);
    devcon_hasText = false;
    char* s = A_cstrdup(devcon_in);
    A_memset(devcon_in, 0, sizeof(devcon_in));
    SDL_UnlockMutex(devcon_inMutex);
    return s;
}
#endif

A_EXTERN_C void DevCon_PrintMessage(const char* s) {
    SDL_LockMutex(devcon_ioMutex);
    printf("%s", s);
    SDL_UnlockMutex(devcon_ioMutex);
}

#if A_TARGET_OS_IS_WINDOWS
A_EXTERN_C void DevCon_Shutdown(void) {
    SDL_DestroyMutex(devcon_ioMutex);
}
#else
A_EXTERN_C void DevCon_Shutdown(void) {
    SDL_DestroyMutex(devcon_inMutex);
    SDL_DestroyMutex(devcon_ioMutex);
    SDL_DestroyMutex(devcon_selectMutex);
    devcon_inMutex     = NULL;
    devcon_ioMutex     = NULL;
    devcon_selectMutex = NULL;
    devcon_hasText     = false;
    A_memset(devcon_in,       0, sizeof(devcon_in));
    A_memset(&devcon_timeval, 0, sizeof(devcon_timeval));
}
#endif
