#pragma once

#include <filesystem>
#include <string>
#include <string_view>
#include <vector>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4244)
#pragma warning(disable : 4245)
#endif
#include <invader/tag/hek/definition.hpp>
#include <invader/tag/hek/header.hpp>
#include <invader/hek/map.hpp>
#ifdef _MSC_VER
#pragma warning(pop) 
#endif

#include "com_defs.hpp"
#include "fs_files.hpp"

NO_DISCARD std::filesystem::path  DB_ImagePath (std::string_view image_name );
NO_DISCARD std::string            DB_LoadShader(std::string_view shader_name);
NO_DISCARD std::vector<std::byte> DB_LoadFont  (std::string_view font_name  );
NO_DISCARD std::vector<std::byte> DB_LoadImage (std::string_view image_name );
NO_DISCARD StreamFile             DB_LoadMap   (std::string_view map_name   );
Invader::HEK::ScenarioStructureBSP<Invader::HEK::NativeEndian> DB_LoadSbsp(std::string_view sbsp_name);