#include "fs_files.hpp"

#include <filesystem>
#include <string>
#include <vector>

#include "com_defs.hpp"
#include "com_print.hpp"

A_NO_DISCARD std::vector<std::byte> FS_ReadFile(std::filesystem::path path) {
	SDL_RWops* ops = SDL_RWFromFile(path.string().c_str(), "rb");
	if (ops == NULL) {
		Com_Println(
			CON_DEST_CLIENT, 
			"Failed to open file '{}' for reading: {}",
			path.string(), SDL_GetError()
		);
		return std::vector<std::byte>();
	}

	Sint64 len = SDL_RWsize(ops);

	std::vector<std::byte> v;
	v.resize(len);

	size_t c = SDL_RWread(ops, v.data(), len);
	if ((Sint64)c < len)
		Com_Println(
			CON_DEST_ERR, 
			"Truncated read of file '{}' (expected {} bytes, got {}).",
			path.string(), len, c
		);

	return v;
}

A_NO_DISCARD std::string FS_ReadFileText(std::filesystem::path path) {
	SDL_RWops* ops = SDL_RWFromFile(path.string().c_str(), "r");
	if (ops == NULL) {
		Com_Println(
			CON_DEST_CLIENT, 
			"Failed to open file '{}' for reading: {}", 
			path.string(), SDL_GetError()
		);
		return std::string();
	}

	Sint64 len = SDL_RWsize(ops);

	std::string s;
	s.resize(len);

	size_t c = SDL_RWread(ops, s.data(), len);
	if ((Sint64)c < len)
		Com_Println(
			CON_DEST_ERR, 
			"Truncated read of file '{}' (expected {} bytes, got {}).",
			path.string(), len, c
		);

	if (s.at(len - 1) != '\0')
		s.push_back('\0');

	return s;
}

A_NO_DISCARD bool FS_ReadInto(std::filesystem::path path, void* p, size_t n) {
	SDL_RWops* f = SDL_RWFromFile(path.string().c_str(), "rb");
	size_t max = SDL_RWsize(f);
	if (n > max)
		n = max;

	bool b = SDL_RWread(f, p, n) == n;
	SDL_RWclose(f);
	return b;
}

A_NO_DISCARD StreamFile FS_StreamFile(
	std::filesystem::path path, SeekFrom from, StreamMode mode, size_t off
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

	SDL_RWops* f = SDL_RWFromFile(path.string().c_str(), mode_str);
	size_t size  = SDL_RWsize(f);
	SDL_RWseek(f, 0, SDL_RW_SEEK_SET);
	StreamFile s = { .f = f, .size = size };
	if(from == FS_SEEK_END || off != 0)
		FS_SeekStream(s, from, off);
	return s;
}

A_NO_DISCARD size_t FS_StreamPos(const StreamFile& file) {
	return SDL_RWtell(file.f);
}

long long FS_SeekStream(A_INOUT StreamFile& file, SeekFrom from, size_t off) {
	if (off > file.size) 
		Com_DPrintln("FS_SeekStream: attempted to seek beyond bounds of file (off={}, expected <{})", off, file.size);
	assert(off <= file.size);

	Sint64 res       = -1;
	switch (from) {
	case FS_SEEK_BEGIN:
		res = SDL_RWseek(file.f, off, SDL_RW_SEEK_SET);
		break;
	case FS_SEEK_END:
		res = SDL_RWseek(file.f, off, SDL_RW_SEEK_END);
		break;
	case FS_SEEK_CUR:
		res = SDL_RWseek(file.f, (long long)off, SDL_RW_SEEK_CUR);
		break;
	default:
		assert(false);
	}
	if (res < 0) {
		Com_DPrintln("FS_SeekStream failed: {}", SDL_GetError());
		
	}

	return res;
}

A_NO_DISCARD bool FS_ReadStream(StreamFile& file, void* p, size_t count) {
	size_t sz = SDL_RWread(file.f, p, count);
	if(sz <= 0) 
		Com_DPrintln("FS_ReadStream: failed to write {} bytes (wrote {}): {}", count, sz, SDL_GetError());
	return sz > 0;
}

A_NO_DISCARD std::vector<std::byte> FS_ReadStream(StreamFile& file, size_t count) {
	std::vector<std::byte> v;
	v.resize(count);
	bool b = FS_ReadStream(file, (void*)v.data(), count);
	if(b)
		return v;
	else
		return std::vector<std::byte>();
}

A_NO_DISCARD bool FS_WriteStream(StreamFile& file, const void* src, size_t count) {
	size_t sz = SDL_RWwrite(file.f, src, count);
	if(sz > 0)
		file.size += sz;
	if(sz != count) 
		Com_DPrintln("FS_WriteStream: failed to write {} bytes (wrote {}): {}", count, sz, SDL_GetError());
	return sz == count;
}

void FS_CloseStream(StreamFile& f) {
	SDL_RWclose(f.f);
	f.f = NULL;
	f.size = 0;
}

bool FS_DeleteFile(const char* filename) {
	return remove(filename) == 0;
}

bool FS_FileExists(const char* filename) {
	return SDL_RWFromFile(filename, "r") != NULL;
}