#include "font.h"

#include "com_print.hpp"
#include "db_files.hpp"
#include "gfx_text.h"

static FT_Library s_ft;

A_EXTERN_C void Font_Init() {
	if (FT_Init_FreeType(&s_ft))
		Com_Errorln("FreeType init failed.");
}

A_EXTERN_C bool Font_Load(
	const char* font_name, int width, int height, A_OUT FontDef* fd
) {
	A_memset(fd, 0, sizeof(*fd));

	std::vector<std::byte> font_buf = DB_LoadFont(font_name);
	if (font_buf.empty()) {
		Com_Println(CON_DEST_ERR, "Failed to open font '{}'.", font_name);
		return false;
	}

	FT_Face face;
	if (FT_New_Memory_Face(s_ft, (FT_Byte*)font_buf.data(), (FT_Long)font_buf.size(), 0, &face)) {
		Com_Println(CON_DEST_ERR, "Failed to create font '{}'.", font_name);
		return false;
	}

	FT_Set_Pixel_Sizes(face, width, height);

	for (char c = 32; c < 127; c++) {
		if (FT_Load_Char(face, c, FT_LOAD_RENDER))
			Com_DPrintln(
				"Failed to load glyph '{}' from font {}.", 
				c, font_name
			);

		GlyphDef glyph = {};
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

A_EXTERN_C void Font_Shutdown() {
	FT_Done_FreeType(s_ft);
}
