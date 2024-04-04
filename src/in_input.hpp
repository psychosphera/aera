#pragma once

#include <span>

#include <SDL3/SDL.h>

#include "com_defs.hpp"

void IN_Init();

void IN_Key_Init();
NO_DISCARD bool  IN_Key_IsDown(size_t localClientNum, SDL_Keycode k);
NO_DISCARD bool  IN_Key_IsUp(size_t localClientNum, SDL_Keycode k);
NO_DISCARD bool  IN_Key_IsToggled(size_t localClientNum, SDL_Keycode k);
NO_DISCARD bool  IN_Key_WasPressedOnCurrentFrame(size_t localClientNum, SDL_Keycode k);
NO_DISCARD std::span<int> IN_Key_AllPressedOnCurrentFrame(size_t localClientNum);
           bool  IN_Key_Down(size_t localClientNum, SDL_Keycode k);
           bool  IN_Key_Up(size_t localClientNum, SDL_Keycode k);
NO_DISCARD char  IN_Key_Char(size_t localClientNum, SDL_Keycode k);
void IN_Key_Shutdown();
	  
void IN_Mouse_Init();
NO_DISCARD bool  IN_Mouse_IsDown(size_t localClientNum, Uint8 button);
NO_DISCARD bool  IN_Mouse_IsUp(size_t localClientNum, Uint8 button);
           bool  IN_Mouse_Down(size_t localClientNum, Uint8 button);
           bool  IN_Mouse_Up(size_t localClientNum, Uint8 button);
           void  IN_Mouse_Move(size_t localClientNum, float xOff, float yOff);
NO_DISCARD float IN_Mouse_X(size_t localClientNum);
NO_DISCARD float IN_Mouse_Y(size_t localClientNum);
void IN_Mouse_Shutdown();

void IN_Key_Clear(size_t localClientNum);
void IN_Frame();
void IN_Shutdown();