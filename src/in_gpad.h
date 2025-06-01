#pragma once

#include "acommon/acommon.h"

#if !A_TARGET_PLATFORM_IS_XBOX
#include <SDL2/SDL.h>
#endif // !A_TARGET_PLATFORM_IS_XBOX

typedef enum GPadButtonCode {
	IN_GPAD_BUTTON_NONE,

	IN_GPAD_BUTTON_LEFT_TRIGGER,
	IN_GPAD_BUTTON_RIGHT_TRIGGER,
	IN_GPAD_BUTTON_LEFT_BUMPER,   // Black button on Original Xbox
	IN_GPAD_BUTTON_RIGHT_BUMPER,  // White button on Original Xbox

	IN_GPAD_BUTTON_NORTH,         // Y on Xbox, Triangle on PS, etc.
	IN_GPAD_BUTTON_SOUTH,         // A on Xbox, X on PS, etc.
	IN_GPAD_BUTTON_EAST,          // B on Xbox, Circle on PS, etc.
	IN_GPAD_BUTTON_WEST,          // X on Xbox, Square on PS, etc.

	IN_GPAD_BUTTON_DPAD_UP,
	IN_GPAD_BUTTON_DPAD_DOWN,
	IN_GPAD_BUTTON_DPAD_RIGHT,
	IN_GPAD_BUTTON_DPAD_LEFT,

	IN_GPAD_BUTTON_START,
	IN_GPAD_BUTTON_BACK,  

	IN_GPAD_BUTTON_HOME,

	IN_GPAD_BUTTON_LEFT_STICK,
	IN_GPAD_BUTTON_RIGHT_STICK,

	IN_GPAD_BUTTON_COUNT
} GPadButtonCode;

typedef struct GPadButton {
	bool  down;
	bool  toggle;
	bool  justDown;
	char* bind;
} GPadButton;

typedef enum GPadStickCode {
	IN_GPAD_STICK_LEFT  = 0,
	IN_GPAD_STICK_RIGHT = 1
} GPadStickCode;

typedef struct GPadStick {
	float x, y;
	float last_x, last_y;
} GPadStick;

typedef enum GPadTriggerCode {
	IN_GPAD_TRIGGER_LEFT = 0,
	IN_GPAD_TRIGGER_RIGHT = 1
} GPadTriggerCode;

typedef struct GPadTrigger {
	float value, last_value;
} GPadTrigger;


#if !A_TARGET_PLATFORM_IS_XBOX
A_EXTERN_C              GPadButtonCode IN_GPad_ButtonFromSDL(Uint8 button);
#endif // !A_TARGET_PLATFORM_IS_XBOX
A_EXTERN_C              void  IN_GPad_Init(void);
A_EXTERN_C              bool  IN_GPad_Add(size_t localClientNum, int gpad_id);
A_EXTERN_C              bool  IN_GPad_Remove(size_t localClientNum);
A_EXTERN_C              int IN_GPad_Id(size_t localClientNum);
#if !A_TARGET_PLATFORM_IS_XBOX
A_EXTERN_C              SDL_GameController* IN_GPad_SDLController(size_t localClientNum);
#endif // !A_TARGET_PLATFORM_IS_XBOX
A_EXTERN_C A_NO_DISCARD bool  IN_GPad_IsDown(size_t localClientNum,
	                                         GPadButtonCode b);
A_EXTERN_C A_NO_DISCARD bool  IN_GPad_IsUp(size_t localClientNum,
	                                       GPadButtonCode b);
A_EXTERN_C A_NO_DISCARD bool  IN_GPad_IsToggled(size_t localClientNum,
	                                            GPadButtonCode b);
A_EXTERN_C              bool  IN_GPad_Down(size_t localClientNum,
	                                       GPadButtonCode b);
A_EXTERN_C              bool  IN_GPad_Up(size_t localClientNum,
	                                     GPadButtonCode b);
A_EXTERN_C              void  IN_GPad_Frame(void);
A_EXTERN_C              void IN_GPad_MoveStick(size_t localClientNum, 
	                                           GPadStickCode s, 
	                                           float x, float y);
A_EXTERN_C              float IN_GPad_StickX(size_t localClientNum, 
	                                         GPadStickCode s);
		                
A_EXTERN_C              float IN_GPad_StickY(size_t localClientNum, 
	                                         GPadStickCode s);
A_EXTERN_C              void  IN_GPad_MoveTrigger(size_t localClientNum,
	                                              GPadTriggerCode t, 
	                                              float value);
A_EXTERN_C              void  IN_GPad_Shutdown(void);