#pragma once

#include <string_view>

enum KeyFocus {
	KF_DEVGUI,
	KF_GAME,
};

void     CL_Init();
void     CL_EnableFpsCounter(size_t localClientNum, bool enable);
void     CL_Frame();
void     CL_EnterSplitscreen(size_t activeLocalClient);
void     CL_LeaveSplitscreen(size_t activeLocalClient);
void	 CL_GiveKbmFocus(size_t localClientNum);
bool	 CL_HasKbmFocus(size_t localClientNum);
size_t   CL_ClientWithKbmFocus();
KeyFocus CL_KeyFocus(size_t localClientNum);
void     CL_SetKeyFocus(size_t localClientNum, KeyFocus f);
bool     CL_LoadMap(std::string_view map_name);
void     CL_Shutdown();
