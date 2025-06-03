#include "in_gpad.h"

#include <assert.h>

#include "acommon/a_string.h"

#include "com_defs.h"
#include "com_print.h"
#include "cl_client.h"
#include "in_input.h"

static void IN_GPad_InitLocalClient(size_t localClientNum) {
	inl_t* inl = IN_GetLocalClientLocals(localClientNum);
	A_memset(inl->buttons,  0, sizeof(inl->buttons));
	A_memset(inl->triggers, 0, sizeof(inl->triggers));
	A_memset(inl->sticks,   0, sizeof(inl->sticks));
}

static void IN_GPad_ShutdownLocalClient(size_t localClientNum) {
	inl_t* inl = IN_GetLocalClientLocals(localClientNum);
	if (inl->hasGPad == false)
		return;

	A_memset(inl->buttons,  0, sizeof(inl->buttons));
	A_memset(inl->sticks,   0, sizeof(inl->sticks));
	A_memset(inl->triggers, 0, sizeof(inl->triggers));
}

#if !A_TARGET_PLATFORM_IS_XBOX
GPadButtonCode IN_GPad_ButtonFromSDL(Uint8 button) {
	switch (button) {
	case SDL_CONTROLLER_BUTTON_A:             return IN_GPAD_BUTTON_SOUTH;
    case SDL_CONTROLLER_BUTTON_B:             return IN_GPAD_BUTTON_EAST;
    case SDL_CONTROLLER_BUTTON_X:             return IN_GPAD_BUTTON_WEST;
    case SDL_CONTROLLER_BUTTON_Y:             return IN_GPAD_BUTTON_NORTH;

    case SDL_CONTROLLER_BUTTON_DPAD_UP:       return IN_GPAD_BUTTON_DPAD_UP;
    case SDL_CONTROLLER_BUTTON_DPAD_DOWN:     return IN_GPAD_BUTTON_DPAD_DOWN;
    case SDL_CONTROLLER_BUTTON_DPAD_LEFT:     return IN_GPAD_BUTTON_DPAD_LEFT;
    case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:    return IN_GPAD_BUTTON_DPAD_RIGHT;
										      
    case SDL_CONTROLLER_BUTTON_START:         return IN_GPAD_BUTTON_START;
    case SDL_CONTROLLER_BUTTON_BACK:          return IN_GPAD_BUTTON_BACK;

    case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:  return IN_GPAD_BUTTON_LEFT_BUMPER;
    case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER: return IN_GPAD_BUTTON_RIGHT_BUMPER;

    case SDL_CONTROLLER_BUTTON_LEFTSTICK:     return IN_GPAD_BUTTON_LEFT_STICK;
    case SDL_CONTROLLER_BUTTON_RIGHTSTICK:    return IN_GPAD_BUTTON_RIGHT_STICK;

    case SDL_CONTROLLER_BUTTON_GUIDE:       
	case SDL_CONTROLLER_BUTTON_TOUCHPAD:
		return IN_GPAD_BUTTON_NONE;

	default:
		assert(false && "invalid SDL controller button");
		return IN_GPAD_BUTTON_NONE;
	}
}
#endif // !A_TARGET_PLATFORM_IS_XBOX

void IN_GPad_Init(void) {
	for (size_t localClientNum = 0;
		localClientNum < MAX_LOCAL_CLIENTS;
		localClientNum++
	) {
		IN_GPad_InitLocalClient(localClientNum);
		inl_t* inl = IN_GetLocalClientLocals(localClientNum);
		inl->hasGPad = false;
		inl->gpad_id = -1;
#if A_TARGET_PLATFORM_IS_XBOX
		DWORD devices = XGetDevices(XDEVICE_TYPE_GAMEPAD);
		for (int i = 0; i < MAX_LOCAL_CLIENTS; i++) {
			if (devices & (1 << 1))
				IN_GPad_Add(i, i);
		}
#endif // A_TARGET_PLATFORM_IS_XBOX
	}
}

bool IN_GPad_Add(size_t localClientNum, int gpad_id) {
	if (IN_LocalClientHasGPad(localClientNum))
		return false;

	IN_GPad_InitLocalClient(localClientNum);
	inl_t* inl = IN_GetLocalClientLocals(localClientNum);
	inl->hasGPad = true;
	inl->gpad_id = gpad_id;
#if !A_TARGET_PLATFORM_IS_XBOX
	inl->gpad_internal = SDL_GameControllerOpen(gpad_id);
#else
	XINPUT_POLLING_PARAMETERS polling_params;
	polling_params.fAutoPoll       = TRUE;
	polling_params.fInterruptOut   = FALSE;
	polling_params.ReservedMBZ1    = 0;
	polling_params.bInputInterval  = 8;
	polling_params.bOutputInterval = 0;
	polling_params.ReservedMBZ2    = 0;
	inl->gpad_internal = XInputOpen(XDEVICE_TYPE_GAMEPAD, gpad_id, XDEVICE_NO_SLOT, &polling_params);
#endif // !A_TARGET_PLATFORM_IS_XBOX
	return inl->gpad_internal != NULL;
}

bool IN_GPad_Remove(size_t localClientNum) {
	if (!IN_LocalClientHasGPad(localClientNum))
		return false;

	IN_GPad_ShutdownLocalClient(localClientNum);
	inl_t* inl = IN_GetLocalClientLocals(localClientNum);
	inl->hasGPad = false;
	inl->gpad_id = -1;
#if !A_TARGET_PLATFORM_IS_XBOX
	SDL_GameControllerClose(inl->gpad_internal);
#else
	XInputClose(inl->gpad_internal);
#endif // !A_TARGET_PLATFORM_IS_XBOX
	inl->gpad_internal = NULL;
	return true;
}

int IN_GPad_Id(size_t localClientNum) {
	return IN_GetLocalClientLocals(localClientNum)->gpad_id;
}

#if !A_TARGET_PLATFORM_IS_XBOX
SDL_GameController* IN_GPad_SDLController(size_t localClientNum) {
	return IN_GetLocalClientLocals(localClientNum)->gpad_internal;
}
#endif // !A_TARGET_PLATFORM_IS_XBOX

A_NO_DISCARD bool IN_GPad_IsDown(size_t localClientNum, GPadButtonCode b) {
	inl_t* inl = IN_GetLocalClientLocals(localClientNum);
	if (inl->hasGPad == false)
		return false;

	return inl->buttons[b].down == true;
}

A_NO_DISCARD bool IN_GPad_IsUp(size_t localClientNum, GPadButtonCode b) {
	inl_t* inl = IN_GetLocalClientLocals(localClientNum);
	if (inl->hasGPad == false)
		return false;

	return inl->buttons[b].down == false;
}

A_NO_DISCARD bool IN_GPad_IsToggled(size_t localClientNum, GPadButtonCode b) {
	inl_t* inl = IN_GetLocalClientLocals(localClientNum);
	if (inl->hasGPad == false)
		return false;

	return inl->buttons[b].toggle == true;
}

bool IN_GPad_Down(size_t localClientNum, GPadButtonCode b) {
	inl_t* inl = IN_GetLocalClientLocals(localClientNum);
	if (inl->hasGPad == false)
		return false;

	bool down = IN_GPad_IsDown(localClientNum, b);

	GPadButton* button = &inl->buttons[b];

	button->down     = true;
	button->justDown = true;
	button->toggle   = !button->toggle;

	Com_DPrintln(CON_DEST_CLIENT, "IN_GPad_Down: pressed %d.", b);

	return down;
}

bool IN_GPad_Up(size_t localClientNum, GPadButtonCode b) {
	inl_t* inl = IN_GetLocalClientLocals(localClientNum);
	if (inl->hasGPad == false)
		return false;

	bool up                  = IN_GPad_IsUp(localClientNum, b);
	inl->buttons[b].down     = false;
	inl->buttons[b].justDown = false;
	
	Com_DPrintln(CON_DEST_CLIENT, "IN_GPad_Down: released %d.", b);
	
	return up;
}

void IN_GPad_Clear(size_t localClientNum) {
	inl_t* inl = IN_GetLocalClientLocals(localClientNum);
	if (inl->hasGPad == false)
		return;

	for (int i = 0; i < IN_GPAD_BUTTON_COUNT; i++) {
		GPadButton* b = &inl->buttons[i];
		b->down     = false;
		b->justDown = false;
	}
}

static void IN_GPad_ClearCurrent(size_t localClientNum) {
	inl_t* inl = IN_GetLocalClientLocals(localClientNum);
	if (inl->hasGPad == false)
		return;

	for (int i = 0; i < IN_GPAD_BUTTON_COUNT; i++) {
		GPadButton* b = &inl->buttons[i];
		b->justDown = false;
	}
}

#if A_TARGET_PLATFORM_IS_XBOX
#define IN_GPAD_STICK_FLOAT(pos) (32768.0f / (float)(pos))
static WORD IN_GPad_ButtonCodeToXInput(GPadButtonCode b) {
	switch (b) {
	case IN_GPAD_BUTTON_DPAD_UP:     return XINPUT_GAMEPAD_DPAD_UP;
	case IN_GPAD_BUTTON_DPAD_DOWN:   return XINPUT_GAMEPAD_DPAD_DOWN;
	case IN_GPAD_BUTTON_DPAD_LEFT:   return XINPUT_GAMEPAD_DPAD_LEFT;
	case IN_GPAD_BUTTON_DPAD_RIGHT:  return XINPUT_GAMEPAD_DPAD_RIGHT;
									 
	case IN_GPAD_BUTTON_START:       return XINPUT_GAMEPAD_START;
	case IN_GPAD_BUTTON_BACK:        return XINPUT_GAMEPAD_BACK;
	case IN_GPAD_BUTTON_LEFT_STICK:  return XINPUT_GAMEPAD_LEFT_THUMB;
	case IN_GPAD_BUTTON_RIGHT_STICK: return XINPUT_GAMEPAD_RIGHT_THUMB;
	default:
		assert(false && "invalid GPadButtonCode");
		return 0;
	}
}

static void IN_GPad_HandleXInputButton(size_t localClientNum, GPadButtonCode b, WORD wButtons) {
	WORD wButton = IN_GPad_ButtonCodeToXInput(b);
	if (IN_GPad_IsDown(localClientNum, b) && ((wButtons & wButton) == 0))
		IN_GPad_Up(localClientNum, b);
	if (IN_GPad_IsUp(localClientNum, b) && (wButtons & wButton) != 0)
		IN_GPad_Down(localClientNum, b);
}

static void IN_GPad_HandleXInputAnalogButton(size_t localClientNum, GPadButtonCode b, BYTE analogButton) {
	if (IN_GPad_IsDown(localClientNum, b) && ((analogButton == FALSE)))
		IN_GPad_Up(localClientNum, b);
	if (IN_GPad_IsUp(localClientNum, b) && (analogButton == TRUE))
		IN_GPad_Down(localClientNum, b);
}

static void IN_GPad_HandleXInputTrigger(size_t localClientNum, GPadTriggerCode t, BOOL b) {
	GPadButtonCode button = t == IN_GPAD_TRIGGER_LEFT ? IN_GPAD_BUTTON_LEFT_TRIGGER : IN_GPAD_BUTTON_RIGHT_TRIGGER;
	if (IN_GPad_IsDown(localClientNum, button) && b == FALSE) {
		IN_GPad_Up(localClientNum, button);
		IN_GPad_MoveTrigger(localClientNum, t, 0.0f);
	} else if (IN_GPad_IsUp(localClientNum, button) && b == TRUE) {
		IN_GPad_Down(localClientNum, button);
		IN_GPad_MoveTrigger(localClientNum, t, 1.0f);
	}
}

void IN_GPad_UpdateXInput(size_t localClientNum, XINPUT_GAMEPAD* gamepad) {
	float lx = IN_GPAD_STICK_FLOAT(gamepad->sThumbLX);
	float ly = IN_GPAD_STICK_FLOAT(gamepad->sThumbLY);
	float rx = IN_GPAD_STICK_FLOAT(gamepad->sThumbRX);
	float ry = IN_GPAD_STICK_FLOAT(gamepad->sThumbRY);

	if (IN_GPad_StickX(localClientNum, IN_GPAD_STICK_LEFT) != lx ||
		IN_GPad_StickY(localClientNum, IN_GPAD_STICK_LEFT) != ly
	) { 
		IN_GPad_MoveStick(localClientNum, IN_GPAD_STICK_LEFT, lx, ly);
	}
	if (IN_GPad_StickX(localClientNum, IN_GPAD_STICK_RIGHT) != rx || 
		IN_GPad_StickY(localClientNum, IN_GPAD_STICK_RIGHT) != ry
	) { 
		IN_GPad_MoveStick(localClientNum, IN_GPAD_STICK_LEFT, rx, ry);
	}

	IN_GPad_HandleXInputButton(localClientNum, IN_GPAD_BUTTON_DPAD_UP,     gamepad->wButtons);
	IN_GPad_HandleXInputButton(localClientNum, IN_GPAD_BUTTON_DPAD_DOWN,   gamepad->wButtons);
	IN_GPad_HandleXInputButton(localClientNum, IN_GPAD_BUTTON_DPAD_LEFT,   gamepad->wButtons);
	IN_GPad_HandleXInputButton(localClientNum, IN_GPAD_BUTTON_DPAD_RIGHT,  gamepad->wButtons);
	IN_GPad_HandleXInputButton(localClientNum, IN_GPAD_BUTTON_START,       gamepad->wButtons);
	IN_GPad_HandleXInputButton(localClientNum, IN_GPAD_BUTTON_BACK,        gamepad->wButtons);
	IN_GPad_HandleXInputButton(localClientNum, IN_GPAD_BUTTON_LEFT_STICK,  gamepad->wButtons);
	IN_GPad_HandleXInputButton(localClientNum, IN_GPAD_BUTTON_RIGHT_STICK, gamepad->wButtons);

	static const GPadButtonCode s_analogButtons[6] = {
		IN_GPAD_BUTTON_SOUTH,
		IN_GPAD_BUTTON_EAST,
		IN_GPAD_BUTTON_WEST,
		IN_GPAD_BUTTON_NORTH,
		IN_GPAD_BUTTON_LEFT_BUMPER,
		IN_GPAD_BUTTON_RIGHT_BUMPER
	};

	for (int i = 0; i < A_countof(s_analogButtons); i++) 
		IN_GPad_HandleXInputAnalogButton(localClientNum, s_analogButtons[i], gamepad->bAnalogButtons[i]);
	
	IN_GPad_HandleXInputTrigger(localClientNum, IN_GPAD_TRIGGER_LEFT,  gamepad->bAnalogButtons[XINPUT_GAMEPAD_LEFT_TRIGGER]);
	IN_GPad_HandleXInputTrigger(localClientNum, IN_GPAD_TRIGGER_RIGHT, gamepad->bAnalogButtons[XINPUT_GAMEPAD_RIGHT_TRIGGER]);
}
#endif // A_TARGET_PLATFORM_IS_XBOX

void IN_GPad_Frame(void) {
#if A_TARGET_PLATFORM_IS_XBOX
	DWORD insertions = 0, removals = 0;
	if (XGetDeviceChanges(XDEVICE_TYPE_GAMEPAD, &insertions, &removals) == TRUE) {
		if (insertions != 0) {
			for (int i = 0; i < MAX_LOCAL_CLIENTS; i++) {
				if (insertions & (1 << 1))
					IN_GPad_Add(i, i);
			}
		}

		if (removals != 0) {
			for (int i = 0; i < MAX_LOCAL_CLIENTS; i++) {
				if (removals & (1 << 1))
					IN_GPad_Remove(i);
			}
		}
	}
#endif // A_TARGET_PLATFORM_IS_XBOX
	for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
		inl_t* inl = IN_GetLocalClientLocals(i);
		if (inl->hasGPad == false)
			continue;

		IN_GPad_ClearCurrent(i);
		inl->sticks[IN_GPAD_STICK_LEFT].last_x  = inl->sticks[IN_GPAD_STICK_LEFT].x;
		inl->sticks[IN_GPAD_STICK_LEFT].last_y  = inl->sticks[IN_GPAD_STICK_LEFT].y;
		inl->sticks[IN_GPAD_STICK_RIGHT].last_x = inl->sticks[IN_GPAD_STICK_RIGHT].x;
		inl->sticks[IN_GPAD_STICK_RIGHT].last_y = inl->sticks[IN_GPAD_STICK_RIGHT].y;

#if A_TARGET_PLATFORM_IS_XBOX
		XINPUT_STATE state;
		DWORD err = XInputGetState(inl->gpad_internal, &state);
		assert(err == ERROR_SUCCESS);
		if (err == ERROR_SUCCESS)
			IN_GPad_UpdateXInput(i, &state.Gamepad);
#endif // A_TARGET_PLATFORM_IS_XBOX
	}
}

// `x` and `y` are absolute, not relative
void IN_GPad_MoveStick(size_t localClientNum, GPadStickCode s, float x, float y) {
	inl_t* inl = IN_GetLocalClientLocals(localClientNum);
	if (inl->hasGPad == false)
		return;

	inl->sticks[s].x = x;
	inl->sticks[s].y = y;
}

float IN_GPad_StickX(size_t localClientNum, GPadStickCode s) {
	inl_t* inl = IN_GetLocalClientLocals(localClientNum);
	if (inl->hasGPad == false)
		return 0.0f;

	return inl->sticks[s].x;
}

float IN_GPad_StickY(size_t localClientNum, GPadStickCode s) {
	inl_t* inl = IN_GetLocalClientLocals(localClientNum);
	if (inl->hasGPad == false)
		return 0.0f; 

	return inl->sticks[s].y;
}

// `value` is absolute, not relative
void IN_GPad_MoveTrigger(size_t localClientNum, GPadTriggerCode t, float value) {
	inl_t* inl = IN_GetLocalClientLocals(localClientNum);
	if (inl->hasGPad == false)
		return;

	inl->triggers[t].value = value;
}

void IN_GPad_Shutdown(void) {
	for (size_t localClientNum = 0;
		localClientNum < MAX_LOCAL_CLIENTS;
		localClientNum++
	) {
		IN_GPad_ShutdownLocalClient(localClientNum);
		inl_t* inl = IN_GetLocalClientLocals(localClientNum);
		inl->hasGPad = false;
		inl->gpad_id = -1;
	}
}
