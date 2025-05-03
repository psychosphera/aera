#pragma once

#include "com_defs.h"
#include "gfx_defs.h"

A_EXTERN_C void R_Init(void);

A_EXTERN_C void R_Frame(void);
A_EXTERN_C void R_WindowResized(void);

A_EXTERN_C A_NO_DISCARD bool R_CreateSdlImage(const char* image_name,
                                              A_INOUT GfxImage* image);
A_EXTERN_C A_NO_DISCARD bool R_CreateImage2D(const void* pixels, 
                                             size_t pixels_size,
                                             int width, int height, int depth,
                                             ImageFormat format,
                                             bool auto_generate_mipmaps,
                                             bool wrap_s, bool wrap_t,
                                             GfxFilter minfilter, 
                                             GfxFilter magfilter,
                                             A_OUT GfxImage* image
);
A_EXTERN_C void R_DeleteImage(A_INOUT GfxImage* image);

A_EXTERN_C bool R_EnableDepthTest(void);
A_EXTERN_C bool R_DisableDepthTest(void);
A_EXTERN_C bool R_EnableBackFaceCulling(void);
A_EXTERN_C bool R_DisableBackFaceCulling(void);
A_EXTERN_C void R_SetViewport(int x, int y, int w, int h);
A_EXTERN_C void R_SetScissorRect(int x, int y, int w, int h);
A_EXTERN_C void R_Clear(void);

A_EXTERN_C void R_DrawTextDrawDefs(size_t localClientNum);
A_EXTERN_C void R_ClearTextDrawDefs(size_t localClientNum);

A_EXTERN_C void R_LoadMap(void);
A_EXTERN_C void R_UnloadMap(void);

A_EXTERN_C void R_Shutdown(void);
