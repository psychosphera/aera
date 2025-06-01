#include "in_input.h"

#include <assert.h>

#include "com_defs.h"

#if !A_TARGET_PLATFORM_IS_XBOX
#include "in_kbm.h"
#endif // !A_TARGET_PLATFORM_IS_XBOX
#include "in_gpad.h"

static inl_t s_in[MAX_LOCAL_CLIENTS];

inl_t* IN_GetLocalClientLocals(size_t localClientNum) {
	assert(localClientNum < MAX_LOCAL_CLIENTS);
	return &s_in[localClientNum];
}

void IN_Init(void) {
#if !A_TARGET_PLATFORM_IS_XBOX
	IN_Key_Init();
	IN_Mouse_Init();
#endif // !A_TARGET_PLATFORM_IS_XBOX
	IN_GPad_Init();
}

bool IN_LocalClientHasGPad(size_t localClientNum) {
	return IN_GetLocalClientLocals(localClientNum)->hasGPad;
}

void IN_Frame(void) {
#if !A_TARGET_PLATFORM_IS_XBOX
	IN_Key_Frame();
	IN_Mouse_Frame();
#endif // !A_TARGET_PLATFORM_IS_XBOX
	IN_GPad_Frame();
}

void IN_Shutdown(void) {
#if !A_TARGET_PLATFORM_IS_XBOX
	IN_Key_Shutdown();
	IN_Mouse_Shutdown();
#endif // !A_TARGET_PLATFORM_IS_XBOX
	IN_GPad_Shutdown();
}
