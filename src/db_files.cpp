#include "db_files.hpp"

#include <filesystem>
#include <map>

#include <cassert>

#include "com_print.hpp"

#ifndef A_PROJECT_ROOT
#define A_PROJECT_ROOT ""
#endif

enum AssetType {
	AT_SHADER,
	AT_FONT,
	AT_IMAGE,
	AT_MAP,
	AT_SBSP,
};

std::map<AssetType, std::string_view> s_assetDirs = {
	{ AT_SHADER, "shaders"   },
	{ AT_FONT,   "fonts"     },
	{ AT_IMAGE,  "images"    },
	{ AT_MAP,    "maps"      },
};

A_NO_DISCARD std::string_view DB_AssetDirForType(AssetType at) {
	return s_assetDirs.at(at);
}

static const std::filesystem::path ASSETS_BASE_DIR = 
	std::filesystem::path(A_PROJECT_ROOT "/assets");

A_NO_DISCARD std::filesystem::path DB_AssetPath(
	AssetType at, std::string_view assetName
) {
	return std::filesystem::path(ASSETS_BASE_DIR) / 
		DB_AssetDirForType(at) / 
		assetName;
}

A_NO_DISCARD std::filesystem::path DB_ImagePath(std::string_view image_name) {
	return DB_AssetPath(AT_IMAGE, image_name);
}

A_NO_DISCARD std::filesystem::path DB_MapPath(std::string_view map_name) {
	return DB_AssetPath(AT_MAP, map_name);
}

A_NO_DISCARD std::filesystem::path DB_SbspPath(std::string_view sbsp_name) {
	return DB_AssetPath(AT_SBSP, sbsp_name);
}

A_NO_DISCARD std::string DB_LoadAsset_Text(
	AssetType assetType, std::string_view assetName
) {
	return FS_ReadFileText(DB_AssetPath(assetType, assetName));
}

A_NO_DISCARD std::vector<std::byte> DB_LoadAsset_Binary(
	AssetType assetType, std::string_view assetName
) {
	return FS_ReadFile(DB_AssetPath(assetType, assetName));
}

A_NO_DISCARD std::string DB_LoadShader(std::string_view shader_name) {
	return DB_LoadAsset_Text(AT_SHADER, shader_name);
}

A_NO_DISCARD std::vector<std::byte> DB_LoadFont(std::string_view font_name) {
	return DB_LoadAsset_Binary(AT_FONT, font_name);
}

A_NO_DISCARD std::vector<std::byte> DB_LoadImage(std::string_view image_name) {
	return DB_LoadAsset_Binary(AT_IMAGE, image_name);
}

A_NO_DISCARD StreamFile DB_LoadMap_Stream(std::string_view map_name) {
	return FS_StreamFile(DB_MapPath(map_name), FS_SEEK_BEGIN, FS_STREAM_READ_EXISTING, 0);
}

A_NO_DISCARD FileMapping DB_LoadMap_Mmap(std::string_view map_name) {
	return Z_MapFile(DB_MapPath(map_name).string().c_str());
}
