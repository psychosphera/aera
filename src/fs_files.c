#include "fs_files.h"

#include <assert.h>

#include "acommon/a_io.h"
#include "acommon/a_string.h"
#include "acommon/z_mem.h"

#include "com_defs.h"
#include "com_print.h"

A_NO_DISCARD void* FS_ReadFile(const char* path, A_OPTIONAL_OUT size_t* sz) {
	if (sz)
		*sz = 0;

#if !A_TARGET_PLATFORM_IS_XBOX
	SDL_RWops* ops = SDL_RWFromFile(path, "r");
	if (ops == NULL) {
		Com_Println(
			CON_DEST_CLIENT,
			"Failed to open file '%s' for reading: %s",
			path, SDL_GetError()
		);
		assert(false && "Failed to open file for reading");
		return NULL;
	}

	Sint64 len = SDL_RWsize(ops);

	void* p = Z_Alloc(len + 1);

	size_t c = SDL_RWread(ops, p, 1, len);
	if ((Sint64)c < len) {
		Com_Println(
			CON_DEST_ERR,
			"Truncated read of file '%s' (expected %lli bytes, got %zu).",
			path, len, c
		);
		assert(false && "Truncated read of file");
	}

	if (sz)
		*sz = len + 1;

	return p;
#else
	assert(false && "unimplemented"); // FIXME
	return NULL;
#endif // !A_TARGET_PLATFORM_IS_XBOX
}

void FS_FreeFile(void* p) {
	Z_Free(p);
}

A_NO_DISCARD char* FS_ReadFileText(const char* path, 
	                               A_OPTIONAL_OUT size_t* sz
) {
	if (sz)
		*sz = 0;

#if !A_TARGET_PLATFORM_IS_XBOX
	SDL_RWops* ops = SDL_RWFromFile(path, "r");
	if (ops == NULL) {
		Com_Println(
			CON_DEST_CLIENT, 
			"Failed to open file '%s' for reading: %s", 
			path, SDL_GetError()
		);
		assert(false && "Failed to open file for reading");
		return NULL;
	}

	Sint64 len = SDL_RWsize(ops);

	char* p = (char*)Z_Alloc(len + 1);

	size_t c = SDL_RWread(ops, p, 1, len);
	if ((Sint64)c < len) {
		Com_Println(
			CON_DEST_ERR,
			"Truncated read of file '%s' (expected %lld bytes, got %zu).",
			path, len, c
		);
		assert(false && "Truncated read of file");
	}

	if (p[len] != '\0')
		p[len]  = '\0';

	if(sz)
		*sz = len + 1;

	return p;
#else 
	assert(false && "unimplemented"); // FIXME
	return NULL;
#endif // !A_TARGET_PLATFORM_IS_XBOX
}

void FS_FreeFileText(char* text) {
	Z_Free(text);
}

A_NO_DISCARD StreamFile FS_StreamFile(
	const char* path, SeekFrom from, StreamMode mode, size_t off
) {
	const char* mode_str = NULL;
	switch(mode) {
	case FS_STREAM_READ_EXISTING:
		mode_str = "rb";
		break;
	case FS_STREAM_WRITE_NEW:
		mode_str = "wb";
		break;
	case FS_STREAM_READ_WRITE_EXISTING:
		mode_str = "r+b";
		break;
	case FS_STREAM_READ_WRITE_NEW:
		mode_str = "w+b";
		break;
	case FS_STREAM_APPEND:
		mode_str = "a";
	};

#if !A_TARGET_PLATFORM_IS_XBOX
	SDL_RWops* f = SDL_RWFromFile(path, mode_str);
	size_t size  = SDL_RWsize(f);
	SDL_RWseek(f, 0, RW_SEEK_SET);
	StreamFile s = { .f = f, .size = size };
	if(from == FS_SEEK_END || off != 0)
		FS_SeekStream(&s, from, off);
	return s;
#else
	assert(false && "unimplemented"); // FIXME
	StreamFile s;
	return s;
#endif // !A_TARGET_PLATFORM_IS_XBOX
}

A_NO_DISCARD size_t FS_StreamPos(A_INOUT StreamFile* file) {
#if !A_TARGET_PLATFORM_IS_XBOX
	return SDL_RWtell(file->f);
#else
	assert(false && "unimplemented"); // FIXME
	return 0;
#endif // !A_TARGET_PLATFORM_IS_XBOX
}

long long FS_SeekStream(A_INOUT StreamFile* file, SeekFrom from, size_t off) {
	if (off > file->size) {
		Com_DPrintln(
			CON_DEST_CLIENT, 
			"FS_SeekStream: attempted to seek beyond bounds of file (off=%zu, expected <%zu)", 
			off, file->size
		);
		assert(false && "Attempted to seek beyond bounds of file");
	}
	assert(off <= file->size);

#if !A_TARGET_PLATFORM_IS_XBOX
	Sint64 res       = -1;
	switch (from) {
	case FS_SEEK_BEGIN:
		res = SDL_RWseek(file->f, off, RW_SEEK_SET);
		break;
	case FS_SEEK_END:
		res = SDL_RWseek(file->f, off, RW_SEEK_END);
		break;
	case FS_SEEK_CUR:
		res = SDL_RWseek(file->f, (long long)off, RW_SEEK_CUR);
		break;
	default:
		assert(false && "Bad SeekFrom value");
	}
	if (res < 0) {
		Com_DPrintln(CON_DEST_CLIENT, "FS_SeekStream failed: %s", SDL_GetError());
		assert(false && "Seek failed");
	}

	return res;
#else
	assert(false && "unimplemented"); // FIXME
	return -1;
#endif // !A_TARGET_PLATFORM_IS_XBOX
}

A_NO_DISCARD size_t FS_FileSize(A_INOUT StreamFile* file) {
	size_t pos = FS_StreamPos(file);
	long long seek = FS_SeekStream(file, FS_SEEK_END, 0);
	assert(seek >= 0);
	size_t size = FS_StreamPos(file);
	seek = FS_SeekStream(file, FS_SEEK_BEGIN, pos);
	assert(seek >= 0);
	return size;
}

A_NO_DISCARD bool FS_ReadStream(A_INOUT StreamFile* file, 
	                            void* dst, size_t count
) {
#if !A_TARGET_PLATFORM_IS_XBOX
	size_t sz = SDL_RWread(file->f, dst, 1, count);
	if (sz <= 0) {
		Com_DPrintln(
			CON_DEST_CLIENT, 
			"FS_ReadStream: failed to read %zu bytes (read %zu): %s", 
			count, sz, SDL_GetError()
		);
		assert(false && "Failed to read all bytes");
	}
	return sz > 0;
#else
	assert(false && "unimplemented"); // FIXME
	return false;
#endif // !A_TARGET_PLATFORM_IS_XBOX
}

A_NO_DISCARD bool FS_WriteStream(A_INOUT StreamFile* file, 
	                             const void* src, size_t count
) {
#if !A_TARGET_PLATFORM_IS_XBOX
	size_t sz = SDL_RWwrite(file->f, src, 1, count);
	if(sz > 0)
		file->size += sz;
	if (sz != count) {
		Com_DPrintln(
			CON_DEST_CLIENT, 
			"FS_WriteStream: failed to write %zu bytes (wrote %zu): %s", 
			count, sz, SDL_GetError()
		);
		assert(false && "Failed to write all bytes");
	}
	return sz == count;
#else
	assert(false && "unimplemented"); // FIXME
	return false;
#endif // !A_TARGET_PLATFORM_IS_XBOX
}

void FS_CloseStream(A_INOUT StreamFile* file) {
#if !A_TARGET_PLATFORM_IS_XBOX
	SDL_RWclose(file->f);
	file->f    = NULL;
#else
	assert(false && "unimplemented"); // FIXME
#endif // !A_TARGET_PLATFORM_IS_XBOX
	file->size = 0;
}

bool FS_DeleteFile(const char* filename) {
	return A_remove(filename) == 0;
}

bool FS_FileExists(const char* filename) {
#if !A_TARGET_PLATFORM_IS_XBOX
	return SDL_RWFromFile(filename, "r") != NULL;
#else
	assert(false && "unimplemented"); // FIXME
	return false;
#endif // !A_TARGET_PLATFORM_IS_XBOX
}

static char s_osPathBuf[1024];
char* FS_BuildOsPath(const char* gamedir, const char* subdir, 
	                 const char* file,    const char* ext
) {
	if (gamedir == NULL)
		gamedir = "";
	if (subdir == NULL)
		subdir = "";
	if (file == NULL)
		file = "";

	if (A_snprintf(s_osPathBuf, sizeof(s_osPathBuf), "%s/%s/%s%s%s",
		           gamedir, subdir, file, ext ? "." : "", ext ? ext : "") < 1
	) {
		return NULL;
	}
	return s_osPathBuf;
}
