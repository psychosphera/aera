#pragma once

#include <vector>
#include <string_view>
#include <string>

std::vector<std::byte> FS_ReadFile(std::string_view fname);
std::string            FS_ReadFileText(std::string_view fname);