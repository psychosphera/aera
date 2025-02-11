#pragma once

#include <filesystem>
#include <string>
#include <vector>

#include <SDL3/SDL.h>

#include "com_defs.hpp"

struct StreamFile {
	SDL_RWops* f;
	size_t size;
};

A_NO_DISCARD std::vector<std::byte> FS_ReadFile    (std::filesystem::path path);
A_NO_DISCARD std::string            FS_ReadFileText(std::filesystem::path path);
A_NO_DISCARD bool                   FS_ReadInto    (std::filesystem::path path, void* p, size_t n);

enum SeekFrom {
	FS_SEEK_BEGIN,
	FS_SEEK_CUR,
	FS_SEEK_END
};

enum StreamMode {
	FS_STREAM_READ_EXISTING,
	FS_STREAM_WRITE_NEW,
	FS_STREAM_READ_WRITE_EXISTING,
	FS_STREAM_READ_WRITE_NEW,
	FS_STREAM_APPEND
};

A_NO_DISCARD StreamFile FS_StreamFile(
	std::filesystem::path path, SeekFrom from, StreamMode mode, size_t off
);

long long FS_SeekStream(A_INOUT StreamFile& file, SeekFrom from, size_t off);
void FS_CloseStream(StreamFile& f);

A_NO_DISCARD size_t FS_StreamPos(const StreamFile& file);

A_NO_DISCARD bool FS_ReadStream(StreamFile& file, void* p, size_t count);
A_NO_DISCARD std::vector<std::byte> FS_ReadStream(StreamFile& file, size_t count);

template<typename T>
A_NO_DISCARD inline bool FS_ReadStream(StreamFile& file, T& t) {
	return FS_ReadStream(file, (void*)&t, sizeof(t));
}

template<>
A_NO_DISCARD inline bool FS_ReadStream(StreamFile& file, std::string& t) {
	if(!t.empty())	
		t.clear();

	char c;
	while (1) {
		if (!FS_ReadStream(file, c))
			return false;

		t.push_back(c);
		if (c == '\0')
			break;
	}

	return true;
}

A_NO_DISCARD bool FS_WriteStream(StreamFile& file, const void* src, size_t count);

template<typename T>
A_NO_DISCARD inline bool FS_WriteStream(StreamFile& file, T& t) {
	return FS_WriteStream(file, (const void*)&t, sizeof(t));
}

template<>
A_NO_DISCARD inline bool FS_WriteStream(StreamFile& file, std::string& t) {
	return FS_WriteStream(file, (const void*)t.data(), (size_t)t.length());
}

bool FS_DeleteFile(const char* filename);
bool FS_FileExists(const char* filename);
