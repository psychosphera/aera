#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H

#include "com_defs.h"
#include "gfx_defs.h"
#include "gfx_shader.h"

typedef struct GlyphDef {
	char  c;
	int   width, height;
	int   left;
	int   top;
	int   advance_x, advance_y;
    float atlas_x, atlas_y;
	void* pixels;
} GlyphDef;

typedef struct FontDef {
    int atlas_width,     atlas_height;
    GfxShaderProgram     prog;
	GfxVertexDeclaration vertex_declaration;
	GfxImage             atlas;
    GlyphDef             glyphs[95];
} FontDef;

A_EXTERN_C void Font_Init(void);
A_EXTERN_C A_NO_DISCARD bool Font_Load(
	const char* font_name, int width, int height, A_OUT FontDef* fd
);
A_EXTERN_C bool Font_AddGlyph(
	A_INOUT FontDef* fd, char c, const GlyphDef* g);
A_EXTERN_C       GlyphDef* Font_GetGlyph     (        FontDef* fd, char c);
A_EXTERN_C const GlyphDef* Font_GetGlyphConst(const   FontDef* fd, char c);
A_EXTERN_C bool            Font_RemoveGlyph  (A_INOUT FontDef* fd, char c);
A_EXTERN_C const GlyphDef* Font_Glyphs       (const   FontDef* fd);
A_EXTERN_C size_t          Font_GlyphCount   (const   FontDef* fd);
A_EXTERN_C void            Font_Unload       (A_INOUT FontDef* fd);
A_EXTERN_C void            Font_Shutdown     (void);
