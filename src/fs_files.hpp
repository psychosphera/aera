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

enum SeekFrom {
	FS_SEEK_BEGIN,
	FS_SEEK_CUR,
	FS_SEEK_END
};

A_NO_DISCARD StreamFile FS_StreamFile(
	std::filesystem::path path, SeekFrom from = FS_SEEK_BEGIN, size_t off = 0
);

long long FS_SeekStream(A_INOUT StreamFile& file, SeekFrom from, size_t off);
std::vector<std::byte> FS_ReadStream(StreamFile& file, size_t count);

A_NO_DISCARD size_t FS_StreamPos(const StreamFile& file);

template<typename T>
A_NO_DISCARD inline bool FS_ReadStream(StreamFile& file, T& t) {
	size_t sz = SDL_RWread(file.f, (void*)&t, sizeof(t));
	return sz == sizeof(t);
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