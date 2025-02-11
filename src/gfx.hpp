#pragma once

#include <filesystem>
#include <memory>
#include <string_view>

#include "com_defs.hpp"
#include "gfx_defs.hpp"

void R_Init();

void R_Frame();
void R_WindowResized();

A_NO_DISCARD bool R_CreateImage(const char* image_name, 
                                A_INOUT GfxImage* image);

bool R_DeleteImage(A_INOUT GfxImage* image);

void R_LoadMap();
void R_UnloadMap();

void R_Shutdown();