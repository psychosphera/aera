#pragma once

#include "com_defs.h"
#include "gfx_defs.h"


A_NO_DISCARD bool R_CreateTextureAtlas(A_INOUT FontDef* f);
void R_DeleteTextureAtlas(A_INOUT FontDef* f);
void R_DrawText(
    size_t localClientNum, A_OPTIONAL_IN const FontDef* font,
    const RectDef* rect, const char* text,
    float xscale, float yscale, acolor_rgb_t color,
    bool right
);
bool R_AddTextDrawDef(
    size_t localClientNum, FontDef* font, const RectDef* rect, const char* text,
    float xscale, float yscale, acolor_rgb_t color, bool active, bool right,
    A_OUT size_t* id
);

bool R_UpdateTextDrawDef  (size_t localClientNum, size_t id, const char* text);
bool R_ActivateTextDrawDef(size_t localClientNum, size_t id, bool active);
bool R_RemoveTextDrawDef  (size_t localClientNum, size_t id);
