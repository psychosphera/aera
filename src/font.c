#include "font.h"

#include <assert.h>

#include "acommon/a_string.h"

#include "com_print.h"
#include "db_files.h"
#include "gfx_text.h"

static FT_Library s_ft;

A_EXTERN_C void Font_Init(void) {
	if (FT_Init_FreeType(&s_ft))
		Com_Errorln(-1, "FreeType init failed.");
}

A_EXTERN_C bool Font_Load(
	const char* font_name, int width, int height, A_OUT FontDef* fd
) {
	A_memset(fd, 0, sizeof(*fd));

	size_t sz = 0;
	void* font = DB_LoadFont(font_name, &sz);
	if (font == NULL) {
		Com_Println(CON_DEST_ERR, "Failed to open font '%s'.", font_name);
		return false;
	}

	FT_Face face;
	if (FT_New_Memory_Face(s_ft, (FT_Byte*)font, (FT_Long)sz, 0, &face)) {
		Com_Println(CON_DEST_ERR, "Failed to create font '%s'.", font_name);
		return false;
	}

	FT_Set_Pixel_Sizes(face, width, height);

	for (char c = 32; c < 127; c++) {
		if (FT_Load_Char(face, c, FT_LOAD_RENDER))
			Com_DPrintln(CON_DEST_CLIENT,
				"Failed to load glyph '%c' from font %s.", 
				c, font_name
			);

		GlyphDef glyph;
		glyph.c         = c;
		glyph.width     = face->glyph->bitmap.width;
		glyph.height    = face->glyph->bitmap.rows;
		glyph.left      = face->glyph->bitmap_left;
		glyph.top       = face->glyph->bitmap_top;
		glyph.advance_x = face->glyph->advance.x >> 6;
		glyph.advance_y = face->glyph->advance.y >> 6;
		glyph.pixels    = Z_Alloc(glyph.width * glyph.height);
		A_memcpy(
			glyph.pixels, face->glyph->bitmap.buffer,
			glyph.width * glyph.height
		);
		Font_AddGlyph(fd, c, &glyph);
	}

	bool b = R_CreateTextureAtlas(fd);
	assert(b);
	(void)b;

	FT_Done_Face(face);

	DB_UnloadFont(font);

	return true;
}

A_EXTERN_C bool Font_AddGlyph(A_INOUT FontDef* fd, char c, const GlyphDef* g) {
	if (c < 32 || c > 127)
		return false;

	fd->glyphs[c - 32] = *g;
	return true;
}

A_EXTERN_C GlyphDef* Font_GetGlyph(FontDef* fd, char c) {
	if (c < 32 || c > 127) {
		return NULL;
	}

	return &fd->glyphs[c - 32];
}

A_EXTERN_C const GlyphDef* Font_GetGlyphConst(const FontDef* fd, char c) {
	if (c < 32 || c > 127) {
		return NULL;
	}

	return &fd->glyphs[c - 32];
}

A_EXTERN_C bool Font_RemoveGlyph(A_INOUT FontDef* fd, char c) {
	if (c < 32 || c > 127)
		return false;

	Z_Free(fd->glyphs[c - 32].pixels);
	A_memset(&fd->glyphs[c - 32], 0, sizeof(GlyphDef));
	return true;
}

A_EXTERN_C const GlyphDef* Font_Glyphs(const FontDef* fd) {
	return fd->glyphs;
}

A_EXTERN_C size_t Font_GlyphCount(const FontDef* fd) {
	return A_countof(fd->glyphs);
}

A_EXTERN_C void Font_Unload(A_INOUT FontDef* fd) {
	R_DeleteTextureAtlas(fd);
	for (char c = 32; c < 127; c++)	
		Font_RemoveGlyph(fd, c);
}

A_EXTERN_C void Font_Shutdown(void) {
	FT_Done_FreeType(s_ft);
}
