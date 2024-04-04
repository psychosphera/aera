#pragma once

#include <string>
#include <string_view>

#include "com_defs.hpp"
#include "gfx_defs.hpp"


A_NO_DISCARD bool R_CreateTextureAtlas(A_INOUT FontDef& f);
void R_DrawText(
    size_t localClientNum, A_OPTIONAL_IN const FontDef* font,
    const RectDef& rect, std::string_view text,
    float xscale, float yscale, const glm::vec3& color,
    bool right
);
bool R_AddTextDraw(
    size_t localClientNum, FontDef* font, const RectDef& rect, std::string text,
    float xscale, float yscale, glm::vec3 color, bool active, bool right,
    A_OUT size_t& id
);

bool R_UpdateTextDraw(size_t localClientNum, size_t id, std::string text);
bool R_ActivateTextDraw(size_t localClientNum, size_t id, bool active);
bool R_RemoveTextDraw(size_t localClientNum, size_t id);