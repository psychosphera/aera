#pragma once

#include "com_defs.h"
#include "gfx_defs.h"

A_EXTERN_C void R_Init(void);

A_EXTERN_C void R_Frame(void);
A_EXTERN_C void R_WindowResized(void);

A_EXTERN_C A_NO_DISCARD bool R_CreateSdlImage(const char* image_name,
                                   A_INOUT GfxImage* image);

A_EXTERN_C void R_LoadMap(void);
A_EXTERN_C void R_UnloadMap(void);

A_EXTERN_C void R_Shutdown(void);
