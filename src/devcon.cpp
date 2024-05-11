#include "devcon.hpp"

#include <iostream>
#include <string>
#include <deque>

#include <cstdio>
#include <cerrno>

// for select()
#if TARGET_OS_IS_WINDOWS
#include <winsock2.h>
#else
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#endif

#include <SDL3/SDL.h>

#include "com_print.hpp"

std::string devcon_in;
bool devcon_hasText;

SDL_Mutex* devcon_inMutex;
SDL_Mutex* devcon_ioMutex;

fd_set  devcon_fds;
timeval devcon_timeval = { .tv_sec = 0, .tv_usec = 0 };

void DevCon_Frame() {
    // Don't even try to read a new line if the previous one hasn't 
    // been taken
	if (devcon_hasText)
        return;
            
    // Check if stdin has a new line
    FD_ZERO(&devcon_fds);
    FD_CLR(STDIN_FILENO, &devcon_fds);
    FD_SET(STDIN_FILENO, &devcon_fds);

    if(select(1, &devcon_fds, NULL, NULL, &devcon_timeval) < 0) {
        Com_Errorln("DevCon: select() failed with errno={}", errno);
        return;
    }
    
    // If stdin has a new line, read it.
    if(FD_ISSET(STDIN_FILENO, &devcon_fds)) {
        // stdin and stdout aren't necessarily safe to concurrently 
        // access, so make sure that doesn't happen
        SDL_LockMutex(devcon_ioMutex);
		std::getline(std::cin, devcon_in);
        SDL_UnlockMutex(devcon_ioMutex);
		devcon_hasText = true;
    }
}

void DevCon_Init() {
	devcon_in.resize(4 * 1024);
	devcon_inMutex  = SDL_CreateMutex();
    devcon_ioMutex  = SDL_CreateMutex();
    DevCon_PrintMessage("Hello from DevCon!\n");
}

A_NO_DISCARD bool DevCon_HasText() {
	return devcon_hasText;
}

A_NO_DISCARD std::string DevCon_TakeText() {
	SDL_LockMutex(devcon_inMutex);
	devcon_hasText = false;
	std::string s = std::move(devcon_in);
	devcon_in.clear();
	SDL_UnlockMutex(devcon_inMutex);
	return s;
}

void DevCon_PrintMessage(std::string_view s) {
    SDL_LockMutex(devcon_ioMutex);
    printf("%*s", (int)s.length(), s.data());
    SDL_UnlockMutex(devcon_ioMutex);
}

void DevCon_Shutdown() {
	SDL_DestroyMutex(devcon_inMutex);
	SDL_DestroyMutex(devcon_ioMutex);
	devcon_in.clear();
	devcon_hasText = false;
}
