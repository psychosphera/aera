#pragma once

#include "com_defs.h"
#include "dvar.h"
#include "gfx_defs.h"

extern dvar_t* r_vsync;
extern dvar_t* r_fullscreen;
extern dvar_t* r_noBorder;
extern dvar_t* r_renderDistance;
extern dvar_t* r_wireframe;

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
                                             ImageFilter minfilter, 
                                             ImageFilter magfilter,
                                             A_OUT GfxImage* image
);
A_EXTERN_C A_NO_DISCARD bool R_ImageSubData(A_INOUT GfxImage* image,
                                            const void* pixels, 
                                            size_t pixels_size,
                                            int xoff, int yoff,
                                            int width, int height,
                                            ImageFormat format
);
A_EXTERN_C void R_DeleteImage(A_INOUT GfxImage* image);

A_EXTERN_C bool R_EnableDepthTest(void);
A_EXTERN_C bool R_DisableDepthTest(void);
A_EXTERN_C bool R_EnableBackFaceCulling(void);
A_EXTERN_C bool R_DisableBackFaceCulling(void);
A_EXTERN_C bool R_EnableTransparencyBlending(void);
A_EXTERN_C bool R_DisableTransparencyBlending(void);
A_EXTERN_C bool R_SetPolygonMode(GfxPolygonMode mode);
A_EXTERN_C void R_SetViewport(int x, int y, int w, int h);
A_EXTERN_C void R_SetScissorRect(int x, int y, int w, int h);
A_EXTERN_C void R_Clear(void);
A_EXTERN_C bool R_BindVertexBuffer(const GfxVertexBuffer* vb, 
                                   int stream);
A_EXTERN_C bool R_BindImage(A_INOUT GfxImage* image, int index);
A_EXTERN_C bool R_DrawTris(int tri_count, int tri_off);

A_EXTERN_C void R_DrawTextDrawDefs(size_t localClientNum);
A_EXTERN_C void R_ClearTextDrawDefs(size_t localClientNum);

A_EXTERN_C void R_LoadMap(void);
A_EXTERN_C void R_UnloadMap(void);

A_EXTERN_C void R_Shutdown(void);
