#pragma once

#include "acommon/acommon.h"

#if !A_TARGET_PLATFORM_IS_XBOX
#include "in_kbm.h"
#endif // !A_TARGET_PLATFORM_IS_XBOX
#include "in_gpad.h"

#define IN_KEYCODE_COUNT_ON_CURRENT_FRAME 8

#if A_TARGET_PLATFORM_IS_XBOX
typedef HANDLE GPadInternal;
#else
typedef SDL_GameController* GPadInternal;
#endif // A_TARGET_PLATFORM_IS_XBOX

typedef struct inl_t {
#if !A_TARGET_PLATFORM_IS_XBOX
	Key     keys[IN_KEYCODE_COUNT];
	size_t  numKeysPressedOnCurrentFrame;
	Keycode keysPressedOnCurrentFrame[IN_KEYCODE_COUNT_ON_CURRENT_FRAME];
	Mouse   mouse;
#endif // !A_TARGET_PLATFORM_IS_XBOX
	GPadButton   buttons[IN_GPAD_BUTTON_COUNT];
	GPadStick    sticks[2];
	GPadTrigger  triggers[2];
	int          gpad_id;
	GPadInternal gpad_internal;
	bool         hasGPad;
} inl_t;

A_EXTERN_C void   IN_Init                (void);
A_EXTERN_C inl_t* IN_GetLocalClientLocals(size_t localClientNum);
A_EXTERN_C bool   IN_LocalClientHasGPad(size_t localClientNum);
A_EXTERN_C void   IN_Frame               (void);
A_EXTERN_C void   IN_Shutdown            (void);
