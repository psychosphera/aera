#pragma once

#include <SDL3/SDL.h>

#include "com_defs.h"

typedef enum Keycode {
	IN_KEYCODE_UNKNOWN,

	IN_KEYCODE_ESCAPE,
	IN_KEYCODE_F1,
	IN_KEYCODE_F2,
	IN_KEYCODE_F3,
	IN_KEYCODE_F4,
	IN_KEYCODE_F5,
	IN_KEYCODE_F6,
	IN_KEYCODE_F7,
	IN_KEYCODE_F8,
	IN_KEYCODE_F9,
	IN_KEYCODE_F10,
	IN_KEYCODE_F11,
	IN_KEYCODE_F12,
	IN_KEYCODE_PRINT_SCREEN_SYS_RQ,
	IN_KEYCODE_SCROLL_LOCK,
	IN_KEYCODE_PAUSE_BREAK,

	IN_KEYCODE_TILDE,
	IN_KEYCODE_1,
	IN_KEYCODE_2,
	IN_KEYCODE_3,
	IN_KEYCODE_4,
	IN_KEYCODE_5,
	IN_KEYCODE_6,
	IN_KEYCODE_7,
	IN_KEYCODE_8,
	IN_KEYCODE_9,
	IN_KEYCODE_0,
	IN_KEYCODE_MINUS,
	IN_KEYCODE_EQUALS,
	IN_KEYCODE_BACKSPACE,
	IN_KEYCODE_INSERT,
	IN_KEYCODE_HOME,
	IN_KEYCODE_PAGEUP,
	IN_KEYCODE_NUM_LOCK,
	IN_KEYCODE_NUMPAD_SLASH,
	IN_KEYCODE_NUMPAD_ASTERISK,
	IN_KEYCODE_NUMPAD_MINUS,

	IN_KEYCODE_TAB,
	IN_KEYCODE_Q,
	IN_KEYCODE_W,
	IN_KEYCODE_E,
	IN_KEYCODE_R,
	IN_KEYCODE_T,
	IN_KEYCODE_Y,
	IN_KEYCODE_U,
	IN_KEYCODE_I,
	IN_KEYCODE_O,
	IN_KEYCODE_P,
	IN_KEYCODE_LEFTBRACKET,
	IN_KEYCODE_RIGHTBRACKET,
	IN_KEYCODE_BACKSLASH,
	IN_KEYCODE_DELETE,
	IN_KEYCODE_END,
	IN_KEYCODE_PAGEDOWN,
	IN_KEYCODE_NUMPAD_7,
	IN_KEYCODE_NUMPAD_8,
	IN_KEYCODE_NUMPAD_9,
	IN_KEYCODE_NUMPAD_PLUS,

	IN_KEYCODE_CAPS_LOCK,
	IN_KEYCODE_A,
	IN_KEYCODE_S,
	IN_KEYCODE_D,
	IN_KEYCODE_F,
	IN_KEYCODE_G,
	IN_KEYCODE_H,
	IN_KEYCODE_J,
	IN_KEYCODE_K,
	IN_KEYCODE_L,
	IN_KEYCODE_SEMICOLON,
	IN_KEYCODE_QUOTE,
	IN_KEYCODE_ENTER,
	IN_KEYCODE_NUMPAD_4,
	IN_KEYCODE_NUMPAD_5,
	IN_KEYCODE_NUMPAD_6,

	IN_KEYCODE_LEFT_SHIFT,
	IN_KEYCODE_Z,
	IN_KEYCODE_X,
	IN_KEYCODE_C,
	IN_KEYCODE_V,
	IN_KEYCODE_B,
	IN_KEYCODE_N,
	IN_KEYCODE_M,
	IN_KEYCODE_COMMA,
	IN_KEYCODE_PERIOD,
	IN_KEYCODE_SLASH,
	IN_KEYCODE_RIGHT_SHIFT,
	IN_KEYCODE_UP_ARROW,
	IN_KEYCODE_NUMPAD_1,
	IN_KEYCODE_NUMPAD_2,
	IN_KEYCODE_NUMPAD_3,
	IN_KEYCODE_NUMPAD_ENTER,

	IN_KEYCODE_LEFT_CTRL,
	IN_KEYCODE_LEFT_SUPER,
	IN_KEYCODE_LEFT_ALT,
	IN_KEYCODE_SPACE,
	IN_KEYCODE_RIGHT_ALT,
	IN_KEYCODE_RIGHT_SUPER,
	IN_KEYCODE_FN,
	IN_KEYCODE_RIGHT_CTRL,
	IN_KEYCODE_LEFT_ARROW,
	IN_KEYCODE_DOWN_ARROW,
	IN_KEYCODE_RIGHT_ARROW,
	IN_KEYCODE_NUMPAD_0,
	IN_KEYCODE_NUMPAD_DOT,

	IN_KEYCODE_NONE,

	IN_KEYCODE_COUNT
} Keycode;

A_EXTERN_C              Keycode IN_Key_SDLKToKeycode(SDL_Keycode k);

A_EXTERN_C              void IN_Init         (void);
A_EXTERN_C              void IN_Key_Init     (void);
A_EXTERN_C A_NO_DISCARD bool IN_Key_IsDown   (size_t localClientNum, 
	                                          Keycode k);
A_EXTERN_C A_NO_DISCARD bool IN_Key_IsUp     (size_t localClientNum, 
	                                          Keycode k);
A_EXTERN_C A_NO_DISCARD bool IN_Key_IsToggled(size_t localClientNum, 
                                              Keycode k);
A_EXTERN_C              bool IN_Key_Down     (size_t localClientNum, 
                                              Keycode k);
A_EXTERN_C              bool IN_Key_Up       (size_t localClientNum, 
                                              Keycode k);
A_EXTERN_C A_NO_DISCARD char IN_Key_Char     (size_t localClientNum, 
	                                          Keycode k);

A_EXTERN_C A_NO_DISCARD bool IN_Key_WasPressedOnCurrentFrame(
	size_t localClientNum, 
	Keycode k
);
A_EXTERN_C A_NO_DISCARD Keycode* IN_Key_AllPressedOnCurrentFrame(
    size_t localClientNum,
    A_OUT size_t* nKeys
);
A_EXTERN_C              void IN_Key_Shutdown   (void);
	  
A_EXTERN_C              void IN_Mouse_Init     (void);
A_EXTERN_C A_NO_DISCARD bool  IN_Mouse_IsDown  (size_t localClientNum, 
	                                            Uint8 button);
A_EXTERN_C A_NO_DISCARD bool  IN_Mouse_IsUp    (size_t localClientNum, 
	                                            Uint8 button);
A_EXTERN_C              bool  IN_Mouse_Down    (size_t localClientNum, 
	                                            Uint8 button);
A_EXTERN_C              bool  IN_Mouse_Up      (size_t localClientNum, 
	                                            Uint8 button);
A_EXTERN_C              void  IN_Mouse_Move    (size_t localClientNum, 
	                                            float xOff, float yOff);
A_EXTERN_C A_NO_DISCARD float IN_Mouse_X       (size_t localClientNum);
A_EXTERN_C A_NO_DISCARD float IN_Mouse_Y       (size_t localClientNum);
A_EXTERN_C              void  IN_Mouse_Shutdown(void);

A_EXTERN_C              void IN_Key_Clear      (size_t localClientNum);
A_EXTERN_C              void IN_Frame          (void);
A_EXTERN_C              void IN_Shutdown       (void);
