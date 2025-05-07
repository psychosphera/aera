#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "acommon/acommon.h"

typedef enum KeyFocus {
	KF_DEVGUI,
	KF_GAME,
} KeyFocus;

A_EXTERN_C void     CL_Init(void);
A_EXTERN_C void     CL_EnableFpsCounter(size_t localClientNum, bool enable);
A_EXTERN_C void     CL_Frame(void);
A_EXTERN_C void     CL_EnterSplitscreen(size_t activeLocalClient);
A_EXTERN_C void     CL_LeaveSplitscreen(size_t activeLocalClient);
A_EXTERN_C void	    CL_GiveKbmFocus(size_t localClientNum);
A_EXTERN_C bool	    CL_HasKbmFocus(size_t localClientNum);
A_EXTERN_C size_t   CL_ClientWithKbmFocus(void);
A_EXTERN_C KeyFocus CL_KeyFocus(size_t localClientNum);
A_EXTERN_C void     CL_SetKeyFocus(size_t localClientNum, KeyFocus f);
A_EXTERN_C bool     CL_UnloadMap(void);
A_EXTERN_C bool     CL_IsMapLoaded(void);
A_EXTERN_C void     CL_Shutdown(void);
