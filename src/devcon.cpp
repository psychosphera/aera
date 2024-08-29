#include "devcon.hpp"

#include <iostream>
#include <string>
#include <deque>

#include <cstdio>
#include <cerrno>

// for select() - select(stdin) doesn't work on Windows
// so don't include the headers there
#if !A_TARGET_OS_IS_WINDOWS
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#endif // !A_TARGET_OS_IS_WINDOWS

#include <SDL3/SDL.h>

#include "com_print.hpp"

bool       devcon_hasText = false;
SDL_Mutex* devcon_ioMutex = NULL;

#if !A_TARGET_OS_IS_WINDOWS
std::string devcon_in;
SDL_Mutex*  devcon_inMutex     = NULL;
SDL_Mutex*  devcon_selectMutex = NULL;
fd_set      devcon_fds;
timeval     devcon_timeval = { .tv_sec = 0, .tv_usec = 0 };
#endif

// Check if stdin has a line
//static bool DevCon_StdinHasLine();

#if A_TARGET_OS_IS_WINDOWS
/*
static bool DevCon_StdinHasLine() {
    return false;
}
*/
#else 
static bool DevCon_StdinHasLine() {
    SDL_LockMutex(devcon_selectMutex);
    FD_ZERO(&devcon_fds);
    FD_CLR(STDIN_FILENO, &devcon_fds);
    FD_SET(STDIN_FILENO, &devcon_fds);

    if (select(1, &devcon_fds, NULL, NULL, &devcon_timeval) < 0) {
        SDL_UnlockMutex(devcon_selectMutex);
        Com_Errorln("DevCon: select() failed with errno={}", errno);
        return;
    }

    bool hasLine = FD_ISSET(STDIN_FILENO, &devcon_fds);
    SDL_UnlockMutex(devcon_selectMutex);
    return hasLine;
}
#endif

#if A_TARGET_OS_IS_WINDOWS
void DevCon_Frame() {
    return;
}
#else
void DevCon_Frame() {
    // Don't even try to read a new line if the previous one hasn't 
    // been taken
    if (devcon_hasText)
        return;

    // If stdin has a new line, read it.
    if (DevCon_StdinHasLine()) {
        // stdin and stdout aren't necessarily safe to concurrently 
        // access, so make sure that doesn't happen
        SDL_LockMutex(devcon_ioMutex);
        SDL_LockMutex(devcon_inMutex);
        std::getline(std::cin, devcon_in);
        SDL_UnlockMutex(devcon_inMutex);
        SDL_UnlockMutex(devcon_ioMutex);
        devcon_hasText = true;
    }
}
#endif // A_TARGET_OS_IS_WINDOWS

#if A_TARGET_OS_IS_WINDOWS
void DevCon_Init() {
    devcon_ioMutex = SDL_CreateMutex();
    DevCon_PrintMessage("DevCon doesn't work correctly on Windows.\n");
    DevCon_PrintMessage("Output works just fine but input doesn't.\n");
    DevCon_PrintMessage("Use DevGui for input instead.\n");
}
#else
void DevCon_Init() {
	devcon_in.resize(4 * 1024);
	devcon_inMutex     = SDL_CreateMutex();
    devcon_ioMutex     = SDL_CreateMutex();
    devcon_selectMutex = SDL_CreateMutex();
    DevCon_PrintMessage("Hello from DevCon!\n");
}
#endif // A_TARGET_OS_IS_WINDOWS

A_NO_DISCARD bool DevCon_HasText() {
	return devcon_hasText;
}

#if A_TARGET_OS_IS_WINDOWS
A_NO_DISCARD std::string DevCon_TakeText() {
    return "";
}
#else
A_NO_DISCARD std::string DevCon_TakeText() {
    SDL_LockMutex(devcon_inMutex);
    devcon_hasText = false;
    std::string s = std::move(devcon_in);
    devcon_in.clear();
    SDL_UnlockMutex(devcon_inMutex);
    return s;
}
#endif

void DevCon_PrintMessage(std::string_view s) {
    SDL_LockMutex(devcon_ioMutex);
    printf("%*s", (int)s.length(), s.data());
    SDL_UnlockMutex(devcon_ioMutex);
}

#if A_TARGET_OS_IS_WINDOWS
void DevCon_Shutdown() {
    SDL_DestroyMutex(devcon_ioMutex);
}
#else
void DevCon_Shutdown() {
    SDL_DestroyMutex(devcon_inMutex);
    SDL_DestroyMutex(devcon_ioMutex);
    SDL_DestroyMutex(devcon_selectMutex);
    devcon_inMutex     = NULL;
    devcon_ioMutex     = NULL;
    devcon_selectMutex = NULL;
    devcon_in.clear();
    devcon_hasText     = false;
}
#endif