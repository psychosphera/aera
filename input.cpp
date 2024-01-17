#include <array>
#include <unordered_map>

#include <cassert>

#include "input.hpp"

extern int vid_width, vid_height;

constexpr size_t MAX_LOCAL_CLIENTS = 1;

union MouseButtons {
	struct { bool ml, mm, mr, m4, m5; };
	bool array[5];
};

struct Mouse {
	MouseButtons buttons;
	float x, y;
};

static std::array<
	std::unordered_map<SDL_Keycode, bool>, MAX_LOCAL_CLIENTS
> playerKeys;
static std::array<Mouse, MAX_LOCAL_CLIENTS> playerMouse;

static int IN_Mouse_SDLButtonToIndex(Uint8 button) {
	switch (button) {
	case SDL_BUTTON_LEFT:
		return 0;
	case SDL_BUTTON_RIGHT:
		return 1;
	case SDL_BUTTON_MIDDLE:
		return 2;
	case SDL_BUTTON_X1:
		return 3;
	case SDL_BUTTON_X2:
		return 4;
	default:
		assert(false);
	}
}

void IN_Init() {
	IN_Key_Init();
	IN_Mouse_Init();
}

void IN_Key_Init() {
	for (auto& c: playerKeys)
		c.clear();
}

bool IN_Key_IsDown(SDL_Keycode k) {
	return playerKeys.at(0)[k] == true;
}

bool IN_Key_IsUp(SDL_Keycode k) {
	return playerKeys.at(0)[k] == false;
}

bool IN_Key_Down(SDL_Keycode k) {
	bool b = IN_Key_IsDown(k);
	playerKeys.at(0)[k] = true;
	return b;
}

bool IN_Key_Up(SDL_Keycode k) {
	bool b = IN_Key_IsUp(k);
	playerKeys.at(0)[k] = false;
	return b;
}

void IN_Key_Shutdown() {
	for (auto& c : playerKeys)
		c.clear();
}

void IN_Mouse_Init() {
	for (auto& c : playerMouse) {
		memset(&c, 0, sizeof(c));
		c.x = (float)vid_width / 2.0f;
		c.y = (float)vid_height / 2.0f;
	}
}

bool IN_Mouse_IsDown(Uint8 button) {
	int i = IN_Mouse_SDLButtonToIndex(button);
	return playerMouse.at(0).buttons.array[i] == true;
}

bool IN_Mouse_IsUp(Uint8 button) {
	int i = IN_Mouse_SDLButtonToIndex(button);
	return playerMouse.at(0).buttons.array[i] == false;
}

bool IN_Mouse_Down(Uint8 button) {
	int i = IN_Mouse_SDLButtonToIndex(button);
	bool b = IN_Mouse_IsDown(button);
	playerMouse.at(0).buttons.array[i] = true;
	return b;
}

bool IN_Mouse_Up(Uint8 button) {
	int i = IN_Mouse_SDLButtonToIndex(button);
	bool b = IN_Mouse_IsDown(button);
	playerMouse.at(0).buttons.array[i] = false;
	return b;
}

void IN_Mouse_Move(float x, float y) {
	playerMouse.at(0).x -= x;
	playerMouse.at(0).y -= y;
}

float IN_Mouse_X() {
	return playerMouse.at(0).x;
}

float IN_Mouse_Y() {
	return playerMouse.at(0).y;
}

void IN_Mouse_Shutdown() {
	for (auto& c : playerMouse) {
		memset(&c, 0, sizeof(c));
	}
}

void IN_Shutdown() {
	IN_Key_Shutdown();
}