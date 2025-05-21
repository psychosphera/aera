#include "in_input.h"

#include <assert.h>

#include "acommon/a_string.h"

#include "cl_client.h"
#include "dvar.h"

#if !A_TARGET_PLATFORM_IS_XBOX
#define IN_KEYCODE_COUNT_ON_CURRENT_FRAME 8
#endif // !A_TARGET_PLATFORM_IS_XBOX

extern dvar_t* vid_width;
extern dvar_t* vid_height;

#if !A_TARGET_PLATFORM_IS_XBOX
typedef union MouseButtons {
	struct { bool ml, mm, mr, m4, m5; } m;
	bool array[5];
} MouseButtons;

typedef struct Mouse {
	MouseButtons buttons;
	float x, y;
} Mouse;

typedef struct Key {
	bool  down;
	bool  toggle;
	bool  justDown;
	char* bind;
	char* bind2;
} Key;
#endif // !A_TARGET_PLATFORM_IS_XBOX

typedef struct inl_t {
#if !A_TARGET_PLATFORM_IS_XBOX
	Key     keys[IN_KEYCODE_COUNT];
	size_t  numKeysPressedOnCurrentFrame;
	Keycode keysPressedOnCurrentFrame[IN_KEYCODE_COUNT_ON_CURRENT_FRAME];
	Mouse   mouse;
#else
	int FIXME_unimplemented;
#endif // !A_TARGET_PLATFORM_IS_XBOX
} inl_t;

static inl_t s_in[MAX_LOCAL_CLIENTS];

#if !A_TARGET_PLATFORM_IS_XBOX
Keycode IN_Key_SDLKToKeycode(SDL_Keycode k) {
	switch (k) {
	case SDLK_ESCAPE:       return IN_KEYCODE_ESCAPE;
	case SDLK_F1:           return IN_KEYCODE_F1;
	case SDLK_F2:           return IN_KEYCODE_F2;
	case SDLK_F3:           return IN_KEYCODE_F3;
	case SDLK_F4:           return IN_KEYCODE_F4;
	case SDLK_F5:           return IN_KEYCODE_F5;
	case SDLK_F6:           return IN_KEYCODE_F6;
	case SDLK_F7:           return IN_KEYCODE_F7;
	case SDLK_F8:           return IN_KEYCODE_F8;
	case SDLK_F9:           return IN_KEYCODE_F9;
	case SDLK_F10:          return IN_KEYCODE_F10;
	case SDLK_F11:          return IN_KEYCODE_F11;
	case SDLK_F12:          return IN_KEYCODE_F12;
	case SDLK_SYSREQ:       return IN_KEYCODE_PRINT_SCREEN_SYS_RQ;
	case SDLK_SCROLLLOCK:   return IN_KEYCODE_SCROLL_LOCK;
	case SDLK_PAUSE:        return IN_KEYCODE_PAUSE_BREAK;

	case SDLK_BACKQUOTE:    return IN_KEYCODE_TILDE;
	case SDLK_1:            return IN_KEYCODE_1;
	case SDLK_2:            return IN_KEYCODE_2;
	case SDLK_3:            return IN_KEYCODE_3;
	case SDLK_4:            return IN_KEYCODE_4;
	case SDLK_5:            return IN_KEYCODE_5;
	case SDLK_6:            return IN_KEYCODE_6;
	case SDLK_7:            return IN_KEYCODE_7;
	case SDLK_8:            return IN_KEYCODE_8;
	case SDLK_9:            return IN_KEYCODE_9;
	case SDLK_0:            return IN_KEYCODE_0;
	case SDLK_MINUS:        return IN_KEYCODE_MINUS;
	case SDLK_EQUALS:       return IN_KEYCODE_EQUALS;
	case SDLK_BACKSPACE:    return IN_KEYCODE_BACKSPACE;
	case SDLK_INSERT:       return IN_KEYCODE_INSERT;
	case SDLK_HOME:         return IN_KEYCODE_HOME;
	case SDLK_PAGEUP:       return IN_KEYCODE_PAGEUP;
	case SDLK_NUMLOCKCLEAR: return IN_KEYCODE_NUM_LOCK;
	case SDLK_KP_DIVIDE:    return IN_KEYCODE_NUMPAD_SLASH;
	case SDLK_KP_MULTIPLY:  return IN_KEYCODE_NUMPAD_ASTERISK;
	case SDLK_KP_MINUS:     return IN_KEYCODE_NUMPAD_MINUS;

	case SDLK_TAB:			return IN_KEYCODE_TAB;
	case SDLK_q:           	return IN_KEYCODE_Q;
	case SDLK_w:           	return IN_KEYCODE_W;
	case SDLK_e:           	return IN_KEYCODE_E;
	case SDLK_r:           	return IN_KEYCODE_R;
	case SDLK_t:           	return IN_KEYCODE_T;
	case SDLK_y:           	return IN_KEYCODE_Y;
	case SDLK_u:           	return IN_KEYCODE_U;
	case SDLK_i:           	return IN_KEYCODE_I;
	case SDLK_o:           	return IN_KEYCODE_O;
	case SDLK_p:           	return IN_KEYCODE_P;
	case SDLK_LEFTBRACKET: 	return IN_KEYCODE_LEFTBRACKET;
	case SDLK_RIGHTBRACKET:	return IN_KEYCODE_RIGHTBRACKET;
	case SDLK_BACKSLASH:   	return IN_KEYCODE_BACKSLASH;
	case SDLK_DELETE:       return IN_KEYCODE_DELETE;
	case SDLK_END:          return IN_KEYCODE_END;
	case SDLK_PAGEDOWN:     return IN_KEYCODE_PAGEDOWN;
	case SDLK_KP_7:         return IN_KEYCODE_NUMPAD_7;
	case SDLK_KP_8:         return IN_KEYCODE_NUMPAD_8;
	case SDLK_KP_9:         return IN_KEYCODE_NUMPAD_9;
	case SDLK_KP_PLUS:      return IN_KEYCODE_NUMPAD_PLUS;

	case SDLK_CAPSLOCK:     return IN_KEYCODE_CAPS_LOCK;
	case SDLK_a:			return IN_KEYCODE_A;
	case SDLK_s:           	return IN_KEYCODE_S;
	case SDLK_d:           	return IN_KEYCODE_D;
	case SDLK_f:           	return IN_KEYCODE_F;
	case SDLK_g:           	return IN_KEYCODE_G;
	case SDLK_h:           	return IN_KEYCODE_H;
	case SDLK_j:           	return IN_KEYCODE_J;
	case SDLK_k:           	return IN_KEYCODE_K;
	case SDLK_l:           	return IN_KEYCODE_L;
	case SDLK_SEMICOLON:   	return IN_KEYCODE_SEMICOLON;
	case SDLK_QUOTE:       	return IN_KEYCODE_QUOTE;
	case SDLK_RETURN:		return IN_KEYCODE_ENTER;
	case SDLK_KP_4:         return IN_KEYCODE_NUMPAD_4;
	case SDLK_KP_5:         return IN_KEYCODE_NUMPAD_5;
	case SDLK_KP_6:         return IN_KEYCODE_NUMPAD_6;

	case SDLK_LSHIFT:       return IN_KEYCODE_LEFT_SHIFT;
	case SDLK_z:            return IN_KEYCODE_Z;
	case SDLK_x:            return IN_KEYCODE_X;
	case SDLK_c:            return IN_KEYCODE_C;
	case SDLK_v:            return IN_KEYCODE_V;
	case SDLK_b:            return IN_KEYCODE_B;
	case SDLK_n:            return IN_KEYCODE_N;
	case SDLK_m:            return IN_KEYCODE_M;
	case SDLK_COMMA:        return IN_KEYCODE_COMMA;
	case SDLK_PERIOD:       return IN_KEYCODE_PERIOD;
	case SDLK_SLASH:        return IN_KEYCODE_SLASH;
	case SDLK_RSHIFT:       return IN_KEYCODE_RIGHT_SHIFT;
	case SDLK_UP:           return IN_KEYCODE_UP_ARROW;
	case SDLK_KP_1:         return IN_KEYCODE_NUMPAD_1;
	case SDLK_KP_2:         return IN_KEYCODE_NUMPAD_2;
	case SDLK_KP_3:         return IN_KEYCODE_NUMPAD_3;
	case SDLK_KP_ENTER:     return IN_KEYCODE_NUMPAD_ENTER;

	case SDLK_LCTRL:        return IN_KEYCODE_LEFT_CTRL;
	case SDLK_LGUI:         return IN_KEYCODE_LEFT_SUPER;
	case SDLK_LALT:         return IN_KEYCODE_LEFT_ALT;
	case SDLK_SPACE:		return IN_KEYCODE_SPACE;
	case SDLK_RALT:         return IN_KEYCODE_RIGHT_ALT;
	case SDLK_RGUI:         return IN_KEYCODE_RIGHT_SUPER;
	case SDLK_RCTRL:        return IN_KEYCODE_RIGHT_CTRL;
	case SDLK_LEFT:         return IN_KEYCODE_LEFT_ARROW;
	case SDLK_DOWN:         return IN_KEYCODE_DOWN_ARROW;
	case SDLK_RIGHT:        return IN_KEYCODE_RIGHT_ARROW;
	case SDLK_KP_0:         return IN_KEYCODE_NUMPAD_0;
	case SDLK_KP_DECIMAL:   return IN_KEYCODE_NUMPAD_DOT;

	default:                return IN_KEYCODE_UNKNOWN;
	}
}

static char IN_Key_SDLKToChar(SDL_Keycode k, bool shift) {
	switch (k) {
	case IN_KEYCODE_TILDE:        return shift ? '~'  : '`';
	case IN_KEYCODE_1:            return shift ? '!'  : '1';
	case IN_KEYCODE_2:            return shift ? '@'  : '2';
	case IN_KEYCODE_3:            return shift ? '#'  : '3';
	case IN_KEYCODE_4:            return shift ? '$'  : '4';
	case IN_KEYCODE_5:            return shift ? '%'  : '5';
	case IN_KEYCODE_6:            return shift ? '^'  : '6';
	case IN_KEYCODE_7:            return shift ? '&'  : '7';
	case IN_KEYCODE_8:            return shift ? '*'  : '8';
	case IN_KEYCODE_9:            return shift ? '('  : '9';
	case IN_KEYCODE_0:            return shift ? ')'  : '0';
	case IN_KEYCODE_MINUS:        return shift ? '_'  : '-';
	case IN_KEYCODE_EQUALS:       return shift ? '+'  : '=';

	case IN_KEYCODE_TAB:		  return '\t';
	case IN_KEYCODE_Q:            return shift ? 'Q'  : 'q';
	case IN_KEYCODE_W:            return shift ? 'W'  : 'w';
	case IN_KEYCODE_E:            return shift ? 'E'  : 'e';
	case IN_KEYCODE_R:            return shift ? 'R'  : 'r';
	case IN_KEYCODE_T:            return shift ? 'T'  : 't';
	case IN_KEYCODE_Y:            return shift ? 'Y'  : 'y';
	case IN_KEYCODE_U:            return shift ? 'U'  : 'u';
	case IN_KEYCODE_I:            return shift ? 'I'  : 'i';
	case IN_KEYCODE_O:            return shift ? 'O'  : 'o';
	case IN_KEYCODE_P:            return shift ? 'P'  : 'p';
	case IN_KEYCODE_LEFTBRACKET:  return shift ? '['  : '{';
	case IN_KEYCODE_RIGHTBRACKET: return shift ? ']'  : '{';
	case IN_KEYCODE_BACKSLASH:    return shift ? '\\' : '|';

	case IN_KEYCODE_A:            return shift ? 'A'  : 'a';
	case IN_KEYCODE_S:            return shift ? 'S'  : 's';
	case IN_KEYCODE_D:            return shift ? 'D'  : 'd';
	case IN_KEYCODE_F:            return shift ? 'F'  : 'f';
	case IN_KEYCODE_G:            return shift ? 'G'  : 'g';
	case IN_KEYCODE_H:            return shift ? 'H'  : 'h';
	case IN_KEYCODE_J:            return shift ? 'J'  : 'j';
	case IN_KEYCODE_K:            return shift ? 'K'  : 'k';
	case IN_KEYCODE_L:            return shift ? 'L'  : 'l';
	case IN_KEYCODE_SEMICOLON:    return shift ? ':'  : ':';
	case IN_KEYCODE_QUOTE:        return shift ? '\'' : '"';
	case IN_KEYCODE_ENTER:		  return '\n';

	case IN_KEYCODE_Z:            return shift ? 'Z' : 'z';
	case IN_KEYCODE_X:            return shift ? 'X' : 'x';
	case IN_KEYCODE_C:            return shift ? 'C' : 'c';
	case IN_KEYCODE_V:            return shift ? 'V' : 'v';
	case IN_KEYCODE_B:            return shift ? 'B' : 'b';
	case IN_KEYCODE_N:            return shift ? 'N' : 'n';
	case IN_KEYCODE_M:            return shift ? 'M' : 'm';
	case IN_KEYCODE_COMMA:        return shift ? '<' : ',';
	case IN_KEYCODE_PERIOD:       return shift ? '>' : '.';
	case IN_KEYCODE_SLASH:        return shift ? '?' : '/';

	case SDLK_SPACE:		      return ' ';
	default:                      return 0;
	}
}

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
		return -1;
	}
}
#endif // !A_TARGET_PLATFORM_IS_XBOX

static inl_t* IN_GetLocalClientLocals(size_t localClientNum) {
	assert(localClientNum < MAX_LOCAL_CLIENTS);
	return &s_in[localClientNum];
}

void IN_Init(void) {
#if !A_TARGET_PLATFORM_IS_XBOX
	IN_Key_Init();
	IN_Mouse_Init();
#endif // !A_TARGET_PLATFORM_IS_XBOX
}

#if !A_TARGET_PLATFORM_IS_XBOX
void IN_Key_Init(void) {
	for (size_t localClientNum = 0; 
		 localClientNum < MAX_LOCAL_CLIENTS; 
		 localClientNum++
	) {
		inl_t* inl = IN_GetLocalClientLocals(localClientNum);
		A_memset(inl->keys, 0, sizeof(inl->keys));
		A_memset(inl->keysPressedOnCurrentFrame, 
			     0, 
			     sizeof(inl->keysPressedOnCurrentFrame));
		inl->numKeysPressedOnCurrentFrame = 0;
	}
}

A_NO_DISCARD bool IN_Key_IsDown(size_t localClientNum, Keycode k) {
	return IN_GetLocalClientLocals(localClientNum)->keys[k].down == true;
}

A_NO_DISCARD bool IN_Key_IsUp(size_t localClientNum, Keycode k) {
	return IN_GetLocalClientLocals(localClientNum)->keys[k].down == false;
}

A_NO_DISCARD bool IN_Key_IsToggled(size_t localClientNum, Keycode k) {
	return IN_GetLocalClientLocals(localClientNum)->keys[k].toggle;
}

A_NO_DISCARD bool IN_Key_WasPressedOnCurrentFrame(
	size_t localClientNum, Keycode k
) {
	return IN_GetLocalClientLocals(localClientNum)->keys[k].justDown;
}

A_NO_DISCARD Keycode* IN_Key_AllPressedOnCurrentFrame(
	size_t localClientNum,
	A_OUT size_t* nKeys
) {
	assert(nKeys);
	if (!nKeys)
		return NULL;

	inl_t* inl = IN_GetLocalClientLocals(localClientNum);
	*nKeys = inl->numKeysPressedOnCurrentFrame;
	return inl->keysPressedOnCurrentFrame;
}

bool IN_Key_Down(size_t localClientNum, Keycode k) {
	bool b = IN_Key_IsDown(localClientNum, k);

	inl_t* inl = IN_GetLocalClientLocals(localClientNum);
	Key* key = &inl->keys[k];

	key->down     = true;
	key->justDown = true;
	key->toggle   = !key->toggle;
	if (inl->numKeysPressedOnCurrentFrame < IN_KEYCODE_COUNT_ON_CURRENT_FRAME) {
		inl->keysPressedOnCurrentFrame[inl->numKeysPressedOnCurrentFrame++]
			= k;
	}

	return b;
}

bool IN_Key_Up(size_t localClientNum, Keycode k) {
	bool b = IN_Key_IsUp(localClientNum, k);
	IN_GetLocalClientLocals(localClientNum)->keys[k].down = false;
	return b;
}

char IN_Key_Char(size_t localClientNum, Keycode k) {
	bool shift = IN_Key_IsDown(localClientNum, IN_KEYCODE_LEFT_SHIFT) || 
				 IN_Key_IsDown(localClientNum, IN_KEYCODE_RIGHT_SHIFT);
	if (IN_Key_IsToggled(localClientNum, IN_KEYCODE_CAPS_LOCK))
		shift = !shift;

	return IN_Key_SDLKToChar(k, shift);
}

const char* IN_Key_GetBinding(
	size_t localClientNum, Keycode k, bool secondary
) {
	if (secondary)
		return IN_GetLocalClientLocals(localClientNum)->keys[k].bind2;
	else
		return IN_GetLocalClientLocals(localClientNum)->keys[k].bind;
}

Keycode IN_Key_GetNum(size_t localClientNum, const char* binding) {
	inl_t* inl = IN_GetLocalClientLocals(localClientNum);
	for (int i = 0; i < IN_KEYCODE_COUNT; i++) {
		const Key* k = &inl->keys[i];
		if (k->bind == binding || k->bind2 == binding)
			return (Keycode)i;
	}	

	return IN_KEYCODE_NONE;
}

void IN_Key_Clear(size_t localClientNum) {
	inl_t* inl = IN_GetLocalClientLocals(localClientNum);
	for (int i = 0; i < IN_KEYCODE_COUNT; i++) {
		Key* k = &inl->keys[i];
		k->down = false;
		k->justDown = false;
	}

	for (int i = 0; i < inl->numKeysPressedOnCurrentFrame; i++) {
		Keycode* k = &inl->keysPressedOnCurrentFrame[i];
		*k = IN_KEYCODE_NONE;
	}
}

static void IN_Key_ClearCurrent(size_t localClientNum) {
	inl_t* inl = IN_GetLocalClientLocals(localClientNum);
	for (int i = 0; i < IN_KEYCODE_COUNT; i++) {
		Key* k = &inl->keys[i];
		k->justDown = false;
	}

	for (int i = 0; i < inl->numKeysPressedOnCurrentFrame; i++) {
		Keycode* k = &inl->keysPressedOnCurrentFrame[i];
		*k = IN_KEYCODE_NONE;
	}
	inl->numKeysPressedOnCurrentFrame = 0;
}

void IN_Key_Frame(void) {
	for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
		if (CL_HasKbmFocus(i)) {
			IN_Key_ClearCurrent(i);
			break;
		}
	}
}

void IN_Key_Shutdown(void) {
	for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
		inl_t* inl = IN_GetLocalClientLocals(i);
		A_memset(inl->keys, 0, sizeof(inl->keys));
		A_memset(inl->keysPressedOnCurrentFrame, 0, sizeof(inl->keys));
	}
}

void IN_Mouse_Init(void) {
	for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
		inl_t* inl = IN_GetLocalClientLocals(i);
		inl->mouse.x = (float)Dvar_GetInt(vid_width)  / 2.0f;
		inl->mouse.y = (float)Dvar_GetInt(vid_height) / 2.0f;
	}
}

A_NO_DISCARD bool IN_Mouse_IsDown(size_t localClientNum, Uint8 button) {
	int i = IN_Mouse_SDLButtonToIndex(button);
	return IN_GetLocalClientLocals(localClientNum)->
		mouse.buttons.array[i] == true;
}

A_NO_DISCARD bool IN_Mouse_IsUp(size_t localClientNum, Uint8 button) {
	int i = IN_Mouse_SDLButtonToIndex(button);
	return IN_GetLocalClientLocals(
		localClientNum
	)->mouse.buttons.array[i] == false;
}

bool IN_Mouse_Down(size_t localClientNum, Uint8 button) {
	int i = IN_Mouse_SDLButtonToIndex(button);
	bool b = IN_Mouse_IsDown(localClientNum, button);
	IN_GetLocalClientLocals(localClientNum)->mouse.buttons.array[i] = true;
	return b;
}

bool IN_Mouse_Up(size_t localClientNum, Uint8 button) {
	int i = IN_Mouse_SDLButtonToIndex(button);
	bool b = IN_Mouse_IsDown(localClientNum, button);
	IN_GetLocalClientLocals(localClientNum)->mouse.buttons.array[i] = false;
	return b;
}

void IN_Mouse_Move(size_t localClientNum, float x, float y) {
	IN_GetLocalClientLocals(localClientNum)->mouse.x -= x;
	IN_GetLocalClientLocals(localClientNum)->mouse.y -= y;
}

A_NO_DISCARD float IN_Mouse_X(size_t localClientNum) {
	return IN_GetLocalClientLocals(localClientNum)->mouse.x;
}

A_NO_DISCARD float IN_Mouse_Y(size_t localClientNum) {
	return IN_GetLocalClientLocals(localClientNum)->mouse.y;
}

void IN_Mouse_Frame(void) {

}

void IN_Mouse_Shutdown(void) {
	for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
		inl_t* inl = IN_GetLocalClientLocals(i);
		A_memset(&inl->mouse, 0, sizeof(inl->mouse));
		inl->mouse.x = (float)Dvar_GetInt(vid_width)  / 2.0f;
		inl->mouse.y = (float)Dvar_GetInt(vid_height) / 2.0f;
	}
}
#endif // !A_TARGET_PLATFORM_IS_XBOX

void IN_Frame(void) {
#if !A_TARGET_PLATFORM_IS_XBOX
	IN_Key_Frame();
	IN_Mouse_Frame();
#endif // !A_TARGET_PLATFORM_IS_XBOX
}

void IN_Shutdown(void) {
#if !A_TARGET_PLATFORM_IS_XBOX
	IN_Key_Shutdown();
	IN_Mouse_Shutdown();
#endif // !A_TARGET_PLATFORM_IS_XBOX
}
