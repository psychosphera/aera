#include "devcon.hpp"

#include <iostream>
#include <string>
#include <deque>

#include <cstdio>

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
std::deque<std::string> devcon_out;
bool devcon_hasText;

SDL_Mutex* devcon_inMutex;
SDL_Mutex* devcon_outMutex;
SDL_Mutex* devcon_ioMutex;

fd_set  devcon_fds;

#define DEVCON_TV_USEC 1000
timeval devcon_timeval = { .tv_sec = 0, .tv_usec = DEVCON_TV_USEC };

int DevCon_Thread(void*) {
    for(;;) {
	    DevCon_Init();
	    for (;;) {
            if (!devcon_out.empty()) {
                SDL_LockMutex(devcon_ioMutex);
                printf("%s", devcon_out.front().c_str());
                SDL_UnlockMutex(devcon_ioMutex);
                SDL_LockMutex(devcon_outMutex);
                devcon_out.pop_front();
                SDL_UnlockMutex(devcon_outMutex);
            }

		    if (devcon_hasText)
                continue;

            FD_ZERO(&devcon_fds);
            FD_CLR(STDIN_FILENO, &devcon_fds);
            FD_SET(STDIN_FILENO, &devcon_fds);

            if(select(1, &devcon_fds, NULL, NULL, &devcon_timeval) < 0) {
                Com_Println(CON_DEST_ERR, 
                    "DevCon: error with select(), restarting."
                );
                DevCon_Shutdown();
                break;
            }
            
            if(FD_ISSET(STDIN_FILENO, &devcon_fds)) {
                SDL_LockMutex(devcon_ioMutex);
			    std::getline(std::cin, devcon_in);
                Com_DPrintln("DevCon: received {}", devcon_in);
                SDL_UnlockMutex(devcon_ioMutex);
			    devcon_hasText = true;
            }
        }
	}
}

void DevCon_Init() {
	devcon_in.resize(4 * 1024);
    devcon_out.clear();
	devcon_inMutex  = SDL_CreateMutex();
    devcon_outMutex = SDL_CreateMutex();
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
    SDL_LockMutex(devcon_outMutex);
    devcon_out.push_back(std::string(s));
    SDL_UnlockMutex(devcon_outMutex);
}

void DevCon_Shutdown() {
	SDL_DestroyMutex(devcon_inMutex);
	SDL_DestroyMutex(devcon_outMutex);
	SDL_DestroyMutex(devcon_ioMutex);
	devcon_in.clear();
    devcon_out.clear();
	devcon_hasText = false;
}
