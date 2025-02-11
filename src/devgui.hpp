#pragma once

#include <string>

#define DEVGUI_MAX_SAVED_LINES 16

void DevGui_Init();
bool DevGui_HasText(size_t localClientNum);
std::string DevGui_TakeText(size_t localClientNum);
void DevGui_Frame();
void DevGui_Shutdown();
