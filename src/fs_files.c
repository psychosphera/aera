#include "fs_files.h"

#include <assert.h>
#include <stdio.h>

#include "acommon/a_io.h"
#include "acommon/a_string.h"

#include "com_defs.h"
#include "com_print.h"
#include "vm_vmem.h"

static void* FS_Alloc(size_t n) {
	return VM_Alloc(n, VM_ALLOC_FILE);
}

static bool FS_Free(void* p) {
	return VM_Free(p, VM_ALLOC_FILE);
}

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

	void* p = FS_Alloc(len);
	assert(p);
	if (p == NULL)
		return NULL;

	size_t c = SDL_RWread(ops, p, 1, len);
	if ((Sint64)c < len) {
		Com_Println(
			CON_DEST_ERR,
			"Truncated read of file '%s' (expected %lli bytes, got %zu).",
			path, len, c
		);
		assert(false && "Truncated read of file");
	}
#else
	HANDLE hFile = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == NULL)
		return NULL;

	LARGE_INTEGER file_size;
	if (GetFileSizeEx(hFile, &file_size) == FALSE) {
		CloseHandle(hFile);
		return NULL;
	}
		
	assert(file_size.HighPart == 0);

	if (file_size.QuadPart == 0) {
		CloseHandle(hFile);
		return NULL;
	}

	size_t len = file_size.QuadPart;
	void* p = FS_Alloc(len);
	assert(p);
	if (p == NULL) {
		CloseHandle(hFile);
		return NULL;
	}

	DWORD bytes_read = 0;
	BOOL b = ReadFile(hFile, p, len, &bytes_read, NULL);
	CloseHandle(hFile);
	if (b == FALSE || bytes_read != len) {
		FS_Free(p);
		return NULL;
	}
#endif // !A_TARGET_PLATFORM_IS_XBOX
	if (sz)
		*sz = len + 1;

	return p;
}

void FS_FreeFile(void* p) {
	FS_Free(p);
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

	char* p = (char*)FS_Alloc(len + 1);

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
#else 
	FILE* f = fopen(path, "r");
	assert(f);
	if (f == NULL)
		return NULL;

	int i = fseek(f, 0, SEEK_END);
	assert(i == 0);
	if (i != 0) {
		fclose(f);
		return NULL;
	}
	long len = ftell(f);
	if (len == -1) {
		fclose(f);
		return NULL;
	}
	i = fseek(f, 0, SEEK_SET);
	assert(i == 0);
	if (i != 0) {
		fclose(f);
		return NULL;
	}

	char* p = (char*)FS_Alloc(len + 1);
	assert(p);
	if (p == NULL) {
		fclose(f);
		return NULL;
	}

	size_t bytes_read = fread(p, 1, len, f);
	fclose(f);
	if (bytes_read != len) {
		FS_Free(p);
		return NULL;
	}
#endif // !A_TARGET_PLATFORM_IS_XBOX
	if (sz)
		*sz = len + 1;

	return p;
}

void FS_FreeFileText(char* text) {
	FS_Free(text);
}

A_NO_DISCARD StreamFile FS_StreamFile(
	const char* path, SeekFrom from, StreamMode mode, size_t off
) {
#if !A_TARGET_PLATFORM_IS_XBOX
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

	SDL_RWops* f = SDL_RWFromFile(path, mode_str);
	if (f == NULL) {
		Com_Errorln(-1, "FS_StreamFile: failed to open or create '%s': %s", path, SDL_GetError());
	}
	size_t size  = SDL_RWsize(f);
	SDL_RWseek(f, 0, RW_SEEK_SET);
	StreamFile s = { .f = f, .size = size };
#else
	DWORD desired_access = 0;
	DWORD creation_disposition = 0;
	switch (mode) {
	case FS_STREAM_READ_EXISTING:
		desired_access       = OPEN_EXISTING;
		creation_disposition = GENERIC_READ;
		break;
	case FS_STREAM_WRITE_NEW:
		desired_access       = CREATE_ALWAYS;
		creation_disposition = GENERIC_WRITE;
		break;
	case FS_STREAM_READ_WRITE_EXISTING:
		desired_access       = OPEN_EXISTING;
		creation_disposition = GENERIC_WRITE;
		break;
	case FS_STREAM_READ_WRITE_NEW:
		desired_access       = CREATE_ALWAYS;
		creation_disposition = GENERIC_READ | GENERIC_WRITE;
		break;
	case FS_STREAM_APPEND:
		assert(false && "unimplemented");
	default:
		break;
	}

	StreamFile s;
	HANDLE hFile = CreateFileA(path, desired_access, 0, NULL, creation_disposition, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == NULL) {
		s.f = NULL;
		return s;
	}
	LARGE_INTEGER file_size;
	if (GetFileSizeEx(hFile, &file_size) == FALSE) {
		CloseHandle(hFile);
		s.f = NULL;
		return s;
	}
	s.f             = hFile;
	s.size          = file_size.QuadPart;
	s.off           = 0;
#endif // !A_TARGET_PLATFORM_IS_XBOX
	if (from == FS_SEEK_END || off != 0)
		FS_SeekStream(&s, from, off);
	return s;
}

A_NO_DISCARD size_t FS_StreamPos(A_INOUT StreamFile* file) {
#if !A_TARGET_PLATFORM_IS_XBOX
	return SDL_RWtell(file->f);
#else
	return file->off;
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
	switch (from) {
	case FS_SEEK_BEGIN:
		file->off = off;
		return off;
	case FS_SEEK_CUR:
		file->off += off;
		return file->off;
	case FS_SEEK_END:
		file->off = file->size + off;
		return file->off;
	}
	return file->off;
#endif // !A_TARGET_PLATFORM_IS_XBOX
}

A_NO_DISCARD size_t FS_FileSize(A_INOUT StreamFile* file) {
#if !A_TARGET_PLATFORM_IS_XBOX
	size_t pos = FS_StreamPos(file);
	long long seek = FS_SeekStream(file, FS_SEEK_END, 0);
	assert(seek >= 0);
	size_t size = FS_StreamPos(file);
	seek = FS_SeekStream(file, FS_SEEK_BEGIN, pos);
	assert(seek >= 0);
	return size;
#else
	return file->size;
#endif // !A_TARGET_PLATFORM_IS_XBOX
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
	DWORD bytes_read = 0;
	OVERLAPPED overlapped;
	overlapped.Offset     = file->off & 0xFFFFFFFF;
	overlapped.OffsetHigh = (file->off >> 32) & 0xFFFFFFFF;
	BOOL b = ReadFile(file->f, dst, count, &bytes_read, &overlapped);
	if (b == FALSE || bytes_read != count)
		return false;

	file->off += count;

	return true;
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
	DWORD bytes_written = 0;
	OVERLAPPED overlapped;
	overlapped.Offset = file->off & 0xFFFFFFFF;
	overlapped.OffsetHigh = (file->off >> 32) & 0xFFFFFFFF;
	BOOL b = WriteFile(file->f, src, count, &bytes_written, &overlapped);
	if (b == FALSE || bytes_written != count)
		return false;

	file->off += count;
	return true;
#endif // !A_TARGET_PLATFORM_IS_XBOX
}

void FS_CloseStream(A_INOUT StreamFile* file) {
#if !A_TARGET_PLATFORM_IS_XBOX
	SDL_RWclose(file->f);
	file->f    = NULL;
#else
	CloseHandle(file->f);
	file->f    = NULL;
	file->off  = 0;
#endif // !A_TARGET_PLATFORM_IS_XBOX
	file->size = 0;
}

bool FS_DeleteFile(const char* filename) {
#if !A_TARGET_PLATFORM_IS_XBOX
	return A_remove(filename) == 0;
#else
	return DeleteFile(filename) != FALSE;
#endif // !A_TARGET_PLATFORM_IS_XBOX
}

#ifndef INVALID_FILE_ATTRIBUTES
#define INVALID_FILE_ATTRIBUTES -1
#endif // INVALID_FILE_ATTRIBUTES

bool FS_FileExists(const char* filename) {
#if !A_TARGET_PLATFORM_IS_XBOX
	return SDL_RWFromFile(filename, "r") != NULL;
#else
	DWORD attrib = GetFileAttributesA(filename);

	return (attrib != INVALID_FILE_ATTRIBUTES &&
		  !(attrib & FILE_ATTRIBUTE_DIRECTORY));
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
