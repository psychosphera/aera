#include <vector>
#include <string_view>
#include <string>

#include <cstdio>
#include <cstdlib>

#include "com_defs.hpp"

NO_DISCARD std::vector<std::byte> FS_ReadFile(std::string_view fname) {
	FILE* f = fopen(fname.data(), "rb");

	fseek(f, 0, SEEK_END);
	size_t len = ftell(f);
	rewind(f);

	std::vector<std::byte> v;
	v.resize(len);

	size_t c = fread(v.data(), 1, len, f);

	return v;
}

NO_DISCARD std::string FS_ReadFileText(std::string_view fname) {
	FILE* f = fopen(fname.data(), "r");

	fseek(f, 0, SEEK_END);
	size_t len = ftell(f);
	rewind(f);

	std::string s;
	s.resize(len);

	size_t c = fread(s.data(), 1, len, f);
	if (s[len - 1] != '\0')
		s.push_back('\0');

	return s;
}