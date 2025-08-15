#pragma once

#include "acommon/acommon.h"
#include "acommon/a_math.h"

#define TAGS_BASE_ADDR_XBOX    0x803A6000
#define TAGS_BASE_ADDR_GEARBOX 0x40440000

enum {
	MAP_HEADER_HEAD        = A_MAKE_FOURCC('h', 'e', 'a', 'd'),
	MAP_HEADER_FOOT        = A_MAKE_FOURCC('f', 'o', 'o', 't'),
	TAGS_FOOT              = A_MAKE_FOURCC('t', 'a', 'g', 's'),

	TAGS_MAX_SIZE_XBOX     = 22 * 1024 * 1024,
	TAGS_MAX_SIZE_GEARBOX  = 23 * 1024 * 1024,
};

typedef enum MapEngine {
	MAP_ENGINE_XBOX = 5,
	MAP_ENGINE_GEARBOX = 7
} MapEngine;

typedef enum ScenarioType {
	SCENARIO_TYPE_SINGELPLAYER,
	SCENARIO_TYPE_MULTILPLAYER,
	SCENARIO_TYPE_UI,
	SCENARIO_TYPE_COUNT
} ScenarioType;

typedef enum TagFourCC {
	TAG_FOURCC_SCENARIO           = A_MAKE_FOURCC('s', 'c', 'n', 'r'),
	TAG_FOURCC_SBSP               = A_MAKE_FOURCC('s', 'b', 's', 'p'),
	TAG_FOURCC_BITMAP             = A_MAKE_FOURCC('b', 'i', 't', 'm'),
	TAG_FOURCC_SHADER             = A_MAKE_FOURCC('s', 'h', 'd', 'r'),
	TAG_FOURCC_SHADER_ENVIRONMENT = A_MAKE_FOURCC('s', 'e', 'n', 'v'),
	TAG_FOURCC_SHADER_MODEL       = A_MAKE_FOURCC('s', 'o', 's', 'o'),
	TAG_FOURCC_SKY                = A_MAKE_FOURCC('s', 'k', 'y', ' '),
	TAG_FOURCC_MODEL              = A_MAKE_FOURCC('m', 'o', 'd', 'e'),
	TAG_FOURCC_SCENERY            = A_MAKE_FOURCC('s', 'c', 'e', 'n'),
	TAG_FOURCC_OBJECT             = A_MAKE_FOURCC('o', 'b', 'j', 'e')
} TagFourCC;

A_PACK(struct MapHeader {
	uint32_t     head_magic;
	MapEngine    engine;
	uint32_t     decompressed_file_size;
	uint32_t     compressed_padding;
	uint32_t     tag_data_offset;
	uint32_t     tag_data_size;
	char         __pad1[8];
	char         name[32];
	char         build[32];
	uint16_t     type; // ScenarioType
	char         __pad2[2];
	uint32_t     crc32;
	char         __pad3[1940];
	uint32_t     foot_magic;
});
typedef struct MapHeader MapHeader;
A_STATIC_ASSERT(sizeof(MapHeader) == 2048);

typedef union TagId {
	uint32_t id;
	uint16_t index;
} TagId;
A_STATIC_ASSERT(sizeof(TagId) == 4);

A_PACK(struct Tag {
	uint32_t primary_class;
	uint32_t secondary_class;
	uint32_t tertiary_class;
	TagId    tag_id;
	uint32_t tag_path;
	uint32_t tag_data;
	uint32_t external;
	uint32_t __pad;
});
typedef struct Tag Tag;
A_STATIC_ASSERT(sizeof(Tag) == 32);

A_PACK(struct TagDependency {
	uint32_t fourcc;
	uint32_t path_pointer;
	uint32_t path_size;
	TagId id;
});
typedef struct TagDependency TagDependency;
A_STATIC_ASSERT(sizeof(TagDependency) == 16);

#if A_PTR_SIZE_IS_32BIT
#define NATIVE_PTR(T, name) T* name; uint32_t pad__##__LINE__
#elif A_PTR_SIZE_IS_64BIT
#define NATIVE_PTR(T, name) T* name
#else
#error nani the fuck?
#endif // A_ARCH_IS_32BIT

A_PACK(struct TagDataOffset {
	uint32_t size;
	uint32_t external;
	uint32_t file_offset;
	NATIVE_PTR(void, pointer);
});
typedef struct TagDataOffset TagDataOffset;
A_STATIC_ASSERT(sizeof(TagDataOffset) == 20);

A_PACK(struct TagReflexive {
	uint32_t count;
	NATIVE_PTR(void, pointer);
});
typedef struct TagReflexive TagReflexive;
A_STATIC_ASSERT(sizeof(TagReflexive) == 12);

A_PACK(struct TagHeaderPC {
	uint32_t tag_ptr;
	TagId scenario_tag_id;
	uint32_t checksum;
	uint32_t tag_count;
	uint32_t model_part_count;
	uint32_t model_data_file_offset;
	uint32_t model_part_count_2;
	uint32_t vertex_data_size;
	uint32_t model_data_size;
	uint32_t magic;
});
typedef struct TagHeaderPC TagHeaderPC;
A_STATIC_ASSERT(sizeof(TagHeaderPC) == 40);

A_PACK(struct TagHeaderXbox {
	uint32_t tag_ptr;
	TagId scenario_tag_id;
	uint32_t checksum;
	uint32_t tag_count;
	uint32_t model_part_count;
	uint32_t vertex_data_ptr;
	uint32_t model_part_count_2;
	uint32_t triangle_data_ptr;
	uint32_t magic;
});
typedef struct TagHeaderXbox TagHeaderXbox;
A_STATIC_ASSERT(sizeof(TagHeaderXbox) == 36);

A_PACK(struct TagHeaderCommon {
	uint32_t tag_ptr;
	TagId scenario_tag_id;
	uint32_t checksum;
	uint32_t tag_count;
	uint32_t model_part_count;
});
typedef struct TagHeaderCommon TagHeaderCommon;
A_STATIC_ASSERT(sizeof(TagHeaderCommon) == 20);

typedef enum BSPScenarioType {
	BSP_SCENARIO_TYPE_SINGLEPLAYER = 0,
	BSP_SCENARIO_TYPE_MULTIPLAYER = 1,
	BSP_SCENARIO_TYPE_UI = 2
} BSPScenarioType;

typedef enum BSPScenarioFlags {
	BSP_SCENARIO_FLAG_CORTANA_HACK                             = 0x01,
	BSP_SCENARIO_FLAG_USE_DEMO_UI                              = 0x02,
	BSP_SCENARIO_FLAG_COLOR_CORRECTION_NTSC_TO_SRGB            = 0x04,
	BSP_SCENARIO_FLAG_DO_NOT_APPLY_BUNGIE_CAMPAIGN_TAG_PATCHES = 0x08
} BSPScenarioFlags;

A_PACK(struct BSPScenario {
	char          __pad1[48];
	TagReflexive  skies;
	// BSPScenarioType
	uint16_t      type;
	// BSPScenarioFlags
	uint16_t      flags;
	TagReflexive  child_scenarios;
	float         local_north;
	char          __pad2[156];
	TagReflexive  predicted_resources;
	TagReflexive  functions;
	TagDataOffset editor_scenario_data;
	TagReflexive  comments;
	TagReflexive  scavenger_hunt_objects;
	char          __pad3[212];
	TagReflexive  object_names;
	TagReflexive  scenery;
	TagReflexive  scenery_palette;
	TagReflexive  bipeds;
	TagReflexive  biped_palette;
	TagReflexive  vehicles;
	TagReflexive  vehicle_palette;
	TagReflexive  equipment;
	TagReflexive  equipment_palette;
	TagReflexive  weapons;
	TagReflexive  weapon_palette;
	TagReflexive  device_groups;
	TagReflexive  machines;
	TagReflexive  machine_palette;
	TagReflexive  controls;
	TagReflexive  control_palette;
	TagReflexive  light_fixtures;
	TagReflexive  light_fixture_palette;
	TagReflexive  sound_scenery;
	TagReflexive  sound_scenery_palette;
	char          __pad4[84];
	TagReflexive  player_starting_profile;
	TagReflexive  player_starting_locations;
	TagReflexive  trigger_volumes;
	TagReflexive  recorded_animations;
	TagReflexive  netgame_flags;
	TagReflexive  netgame_equipment;
	TagReflexive  starting_equipment;
	TagReflexive  bsp_switch_trigger_volumes;
	TagReflexive  decals;
	TagReflexive  decal_palette;
	TagReflexive  detail_object_collection_palette;
	char          __pad5[84];
	TagReflexive  actor_palette;
	TagReflexive  encounters;
	TagReflexive  command_lists;
	TagReflexive  ai_animation_references;
	TagReflexive  ai_script_references;
	TagReflexive  ai_recording_references;
	TagReflexive  ai_conversations;
	TagDataOffset script_syntax_data;
	TagDataOffset script_string_data;
	TagReflexive  scripts;
	TagReflexive  globals;
	TagReflexive  references;
	TagReflexive  source_files;
	char          __pad6[24];
	TagReflexive  cutscene_flags;
	TagReflexive  cutscene_camera_points;
	TagReflexive  cutscene_titles;
	char          __pad7[108];
	TagDependency custom_object_names;
	TagDependency ingame_help_text;
	TagDependency hud_messages;
	TagReflexive  structure_bsps;
});
typedef struct BSPScenario BSPScenario;
A_STATIC_ASSERT(sizeof(BSPScenario) == 1456);

A_PACK(struct BSPScenarioStructureBSP {
	TagDependency lightmaps_bitmap;
	float vehicle_floor;
	float vehicle_ceiling;
	char __pad1[20];
	acolor_rgb_t default_ambient_color;
	char __pad2[4];
	acolor_rgb_t default_distant_light_0_color;
	avec3f_t default_distant_light_0_dir;
	acolor_rgb_t default_distant_light_1_color;
	avec3f_t default_distant_light_1_dir;
	char __pad3[12];
	acolor_argb_t default_reflection_tint;
	avec3f_t default_shadow_vector;
	acolor_rgb_t default_shadow_color;
	char __pad4[4];
	TagReflexive collision_materials;
	TagReflexive collision_bsp;
	TagReflexive nodes;
	float world_bounds_x_min;
	float world_bounds_x_max;
	float world_bounds_y_min;
	float world_bounds_y_max;
	float world_bounds_z_min;
	float world_bounds_z_max;
	TagReflexive leaves;
	TagReflexive leaf_surfaces;
	TagReflexive surfaces;
	TagReflexive lightmaps;
	char __pad5[12];
	TagReflexive lens_flares;
	TagReflexive lens_flare_markers;
	TagReflexive clusters;
	TagDataOffset cluster_data;
	TagReflexive cluster_portals;
	char __pad6[12];
	TagReflexive breakable_surfaces;
	TagReflexive fog_planes;
	TagReflexive fog_regions;
	TagReflexive fog_palette;
	char __pad7[24];
	TagReflexive weather_palette;
	TagReflexive weather_polyhedra;
	char __pad8[24];
	TagReflexive pathfinding_surfaces;
	TagReflexive pathfinding_edges;
	TagReflexive background_sound_palette;
	TagReflexive sound_environment_palette;
	TagDataOffset sound_pas_data;
	char __pad9[24];
	TagReflexive markers;
	TagReflexive detail_objects;
	TagReflexive runtime_decals;
	char __pad10[12];
	TagReflexive leaf_map_leaves;
	TagReflexive leaf_map_portals;
});
typedef struct BSPScenarioStructureBSP BSPScenarioStructureBSP;
A_STATIC_ASSERT(sizeof(BSPScenarioStructureBSP) == 648);

A_PACK(struct BSPScenarioStructureBSPLightmap {
	uint16_t bitmap;
	char __pad[18];
	TagReflexive materials;
});
typedef struct BSPScenarioStructureBSPLightmap BSPScenarioStructureBSPLightmap;
A_STATIC_ASSERT(sizeof(BSPScenarioStructureBSPLightmap) == 32);

A_PACK(struct BSPModelPartVerticesIndirect {
	uint32_t __pad1;
	uint32_t vertices;
	uint32_t __pad2;
});
typedef struct BSPModelPartVerticesIndirect BSPModelPartVerticesIndirect;
A_STATIC_ASSERT(sizeof(BSPModelPartVerticesIndirect) == 12);

A_PACK(struct BSPModelPartIndicesIndirect {
	uint32_t __pad1;
	uint32_t indices;
	uint32_t __pad2;
});
typedef struct BSPModelPartIndicesIndirect BSPModelPartIndicesIndirect;
A_STATIC_ASSERT(sizeof(BSPModelPartIndicesIndirect) == 12);

A_PACK(struct ScenarioBSP {
	uint32_t bsp_start;
	uint32_t bsp_size;
	uint32_t bsp_address;
	char __pad[4];
	TagDependency structure_bsp;
});
typedef struct ScenarioBSP ScenarioBSP;
A_STATIC_ASSERT(sizeof(ScenarioBSP) == 32);

typedef enum ScenarioPlayerSpawnType {
	SCENARIO_PLAYER_SPAWN_TYPE_NONE,
	// ...
} ScenarioPlayerSpawnType;

A_PACK(struct ScenarioPlayerSpawn {
	apoint3f_t pos;
	float      facing;
	uint16_t   team_index;
	uint16_t   bsp_index;
	// ScenarioPlayerSpawnType
	uint16_t   type0;
	uint16_t   type1;
	uint16_t   type2;
	uint16_t   type3; 
	char       __pad[24];
});
typedef struct ScenarioPlayerSpawn ScenarioPlayerSpawn;
A_STATIC_ASSERT(sizeof(ScenarioPlayerSpawn) == 52);

A_PACK(struct BSPHeader {
	uint32_t pointer;
	uint32_t lightmap_material_count;
	uint32_t rendered_vertices;
	uint32_t lightmap_material_count_2;
	uint32_t lightmap_vertices;
	uint32_t magic;
});
typedef struct BSPHeader BSPHeader;
A_STATIC_ASSERT(sizeof(BSPHeader) == 24);

typedef union TagHeader {
	TagHeaderPC     pc;
	TagHeaderXbox   xbox;
	TagHeaderCommon common;
} TagHeader;

A_PACK(struct BSPSurf {
	uint16_t verts[3];
});
typedef struct BSPSurf BSPSurf;
A_STATIC_ASSERT(sizeof(BSPSurf) == 6);

A_PACK(struct BSPRenderedVertex {
	apoint3f_t pos;
	avec3f_t   normal;
	avec3f_t   binormal;
	avec3f_t   tangent;
	apoint2f_t tex_coords;
});
typedef struct BSPRenderedVertex BSPRenderedVertex;
A_STATIC_ASSERT(sizeof(BSPRenderedVertex) == 56);

A_PACK(struct BSPRenderedVertexCompressed {
	apoint3f_t pos;
	uint32_t   normal;
	uint32_t   binormal;
	uint32_t   tangent;
	apoint2f_t tex_coords;
});
typedef struct BSPRenderedVertexCompressed BSPRenderedVertexCompressed;
A_STATIC_ASSERT(sizeof(BSPRenderedVertexCompressed) == 32);

A_PACK(struct BSPLightmapVertex {
	avec3f_t   normal;
	apoint2f_t tex_coords;
});
typedef struct BSPLightmapVertex BSPLightmapVertex;
A_STATIC_ASSERT(sizeof(BSPLightmapVertex) == 20);

A_PACK(struct BSPLightmapVertexCompressed {
	uint32_t   normal;
	apoint2f_t tex_coords;
});
typedef struct BSPLightmapVertexCompressed BSPLightmapVertexCompressed;
A_STATIC_ASSERT(sizeof(BSPLightmapVertexCompressed) == 12);

A_PACK(struct BSPCollSurf {
	uint32_t plane;
	uint32_t first_edge;
	uint8_t  flags;
	int8_t   breakable_surface;
	uint16_t material;
});
typedef struct BSPCollSurf BSPCollSurf;
A_STATIC_ASSERT(sizeof(BSPCollSurf) == 12);

A_PACK(struct BSPCollEdge {
	uint32_t start_vert;
	uint32_t end_vert;
	uint32_t forward_edge;
	uint32_t reverse_edge;
	uint32_t left_surf;
	uint32_t right_surf;
});
typedef struct BSPCollEdge BSPCollEdge;
A_STATIC_ASSERT(sizeof(BSPCollEdge) == 24);

A_PACK(struct BSPCollVertex {
	avec3f_t point;
	uint32_t first_edge;
});
typedef struct BSPCollVertex BSPCollVertex;
A_STATIC_ASSERT(sizeof(BSPCollVertex) == 16);

typedef enum BSPMaterialType {
	BSP_MATERIAL_DIRT,
	BSP_MATERIAL_SAND,
	BSP_MATERIAL_STONE,
	BSP_MATERIAL_SNOW,
	BSP_MATERIAL_WOOD,
	BSP_MATERIAL_METAL_HOLLOW,
	BSP_MATERIAL_METAL_THIN,
	BSP_MATERIAL_METAL_THICK,
	BSP_MATERIAL_RUBBER,
	BSP_MATERIAL_GLASS,
	BSP_MATERIAL_FORCE_FIELD,
	BSP_MATERIAL_GRUNT,
	BSP_MATERIAL_HUNTER_ARMOR,
	BSP_MATERIAL_HUNTER_SKIN,
	BSP_MATERIAL_ELITE,
	BSP_MATERIAL_JACKAL,
	BSP_MATERIAL_JACKAL_ENERGY_SHIELD,
	BSP_MATERIAL_ENGINEER_SKIN,
	BSP_MATERIAL_ENGINERR_FORCE_FIELD,
	BSP_MATERIAL_FLOOD_COMBAT_FORM,
	BSP_MATERIAL_FLOOD_CARRIER_FORM,
	BSP_MATERIAL_CYBORG_ARMOR,
	BSP_MATERIAL_CYBORT_ENERGY_SHIELD,
	BSP_MATERIAL_HUMAN_ARMOR,
	BSP_MATERIAL_HUMAN_SKIN,
	BSP_MATERIAL_SENTINEL,
	BSP_MATERIAL_MONITOR,
	BSP_MATERIAL_PLASTIC,
	BSP_MATERIAL_WATER,
	BSP_MATERIAL_LEAVES,
	BSP_MATERIAL_ELITE_ENERGY_SHIELD,
	BSP_MATERIAL_ICE,
	BSP_MATERIAL_HUNTER_SHIELD,
	BSP_MATERIAL_COUNT,
} BSPMaterialType;

typedef enum BSPBitmapDataType {
	BSP_BITMAP_DATA_TYPE_2D_TEXTURE,
	BSP_BITMAP_DATA_TYPE_3D_TEXTURE,
	BSP_BITMAP_DATA_TYPE_CUBE_MAP,
	BSP_BITMAP_DATA_TYPE_WHITE,
	BSP_BITMAP_DATA_TYPE_COUNT
} BSPBitmapDataType;

typedef enum BSPBitmapDataFormat {
	BSP_BITMAP_DATA_FORMAT_A8,
	BSP_BITMAP_DATA_FORMAT_Y8,
	BSP_BITMAP_DATA_FORMAT_AY8,
	BSP_BITMAP_DATA_FORMAT_A8Y8,
	BSP_BITMAP_DATA_FORMAT_R5G6B5 = 6,
	BSP_BITMAP_DATA_FORMAT_A1R5G5B5 = 8,
	BSP_BITMAP_DATA_FORMAT_A4R4G4B4,
	BSP_BITMAP_DATA_FORMAT_X8R8G8B8,
	BSP_BITMAP_DATA_FORMAT_A8R8G8B8,
	BSP_BITMAP_DATA_FORMAT_DXT1 = 14,
	BSP_BITMAP_DATA_FORMAT_DXT3,
	BSP_BITMAP_DATA_FORMAT_DXT5,
	BSP_BITMAP_DATA_FORMAT_P8_BUMP,
	BSP_BITMAP_DATA_FORMAT_BC7,
	BSP_BITMAP_DATA_FORMAT_COUNT
} BSPBitmapDataFormat;

typedef enum BSPBitmapType {
	BSP_BITMAP_TYPE_2D_TEXTURES,
	BSP_BITMAP_TYPE_3D_TEXTURES,
	BSP_BITMAP_TYPE_CUBE_MAPS,
	BSP_BITMAP_TYPE_SPRITES,
	BSP_BITMAP_TYPE_UI,
	BSP_BITMAP_TYPE_COUNT
} BSPBitmapType;

typedef enum BSPBitmapFormat {
	BSP_BITMAP_FORMAT_DXT1,
	BSP_BITMAP_FORMAT_DXT3,
	BSP_BITMAP_FORMAT_DXT5,
	BSP_BITMAP_FORMAT_16_BIT,
	BSP_BITMAP_FORMAT_32_BIT,
	BSP_BITMAP_FORMAT_MONOCHROME,
	BSP_BITMAP_FORMAT_BC7,
	BSP_BITMAP_FORMAT_COUNT
} BSPBitmapFormat;

typedef enum BSPBitmapUsage {
	BSP_BITMAP_USAGE_ALPHA_BLEND,
	BSP_BITMAP_USAGE_DEFAULT,
	BSP_BITMAP_USAGE_HEIGHT_MAP,
	BSP_BITMAP_USAGE_DETAIL_MAP,
	BSP_BITMAP_USAGE_LIGHT_MAP,
	BSP_BITMAP_USAGE_VECTOR_MAP,
	BSP_BITMAP_USAGE_COUNT
} BSPBitmapUsage;

typedef enum BSPBitmapSpriteBudgetSize {
	BSP_BITMAP_SPRITE_BUDGET_SIZE_32x32,
	BSP_BITMAP_SPRITE_BUDGET_SIZE_64x64,
	BSP_BITMAP_SPRITE_BUDGET_SIZE_128x128,
	BSP_BITMAP_SPRITE_BUDGET_SIZE_256x256,
	BSP_BITMAP_SPRITE_BUDGET_SIZE_512x512,
	BSP_BITMAP_SPRITE_BUDGET_SIZE_1024x1024,
	BSP_BITMAP_SPRITE_BUDGET_SIZE_COUNT
} BSPBitmapSpriteBudgetSize;

typedef enum BSPBitmapSpriteUsage {
	BSP_BITMAP_SPRITE_USAGE_BLEND_ADD_SUBTRACT_MAX,
	BSP_BITMAP_SPRITE_USAGE_MULTIPLY_MIN,
	BSP_BITMAP_SPRITE_USAGE_DOUBLE_MULTIPLY,
	BSP_BITMAP_SPRITE_USAGE_COUNT
} BSPBitmapSpriteUsage;

typedef enum BSPShaderDetailLevel {
	BSP_SHADER_DETAIL_LEVEL_HIGH,
	BSP_SHADER_DETAIL_LEVEL_MEDIUM,
	BSP_SHADER_DETAIL_LEVEL_LOW,
	BSP_SHADER_DETAIL_LEVEL_AWFUL
} BSPShaderDetailLevel;

typedef enum BSPShaderType {
	BSP_SHADER_TYPE_ENVIRONMENT
	// TODO
} BSPShaderType;

typedef enum BSPShaderEnvironmentType {
	BSP_SHADER_ENVIRONMENT_TYPE_NORMAL,
	BSP_SHADER_ENVIRONMENT_TYPE_BLENDED,
	BSP_SHADER_ENVIRONMENT_TYPE_BLENDED_BASE_SPECULAR
} BSPShaderEnvironmentType;

typedef enum BSPShaderDetailFunction {
	BSP_SHADER_DETAIL_FUNCTION_DOUBLE_BIASED_MULTIPLY,
	BSP_SHADER_DETAIL_FUNCTION_MULTIPLY,
	BSP_SHADER_DETAIL_FUNCTION_DOUBLE_BIASED_ADD,
	BSP_SHADER_DETAIL_FUNCTION_COUNT
} BSPShaderDetailFunction;

// #define DISCRIMINANT_TO_STRING(a) [a] = A_STRINGIFY(a)

// inline const char* BSPMaterialType_to_string(BSPMaterialType type) {
// 	static const char* names[] = {
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_DIRT),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_SAND),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_STONE),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_SNOW),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_WOOD),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_METAL_HOLLOW),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_METAL_THIN),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_METAL_THICK),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_RUBBER),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_GLASS),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_FORCE_FIELD),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_GRUNT),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_HUNTER_ARMOR),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_HUNTER_SKIN),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_ELITE),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_JACKAL),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_JACKAL_ENERGY_SHIELD),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_ENGINEER_SKIN),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_ENGINERR_FORCE_FIELD),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_FLOOD_COMBAT_FORM),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_FLOOD_CARRIER_FORM),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_CYBORG_ARMOR),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_CYBORT_ENERGY_SHIELD),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_HUMAN_ARMOR),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_HUMAN_SKIN),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_SENTINEL),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_MONITOR),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_PLASTIC),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_WATER),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_LEAVES),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_ELITE_ENERGY_SHIELD),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_ICE),
// 		DISCRIMINANT_TO_STRING(BSP_MATERIAL_HUNTER_SHIELD)
// 	};

// 	if(type >= BSP_MATERIAL_COUNT) 
// 		return NULL;

// 	return names[type];
// }

// inline const char* BSPBitmapDataType_to_string(BSPBitmapDataType type) {
// 	assert(type < BSP_BITMAP_DATA_TYPE_COUNT && "invalid type");

// 	static const char* names[] = {
// 		DISCRIMINANT_TO_STRING(BSP_BITMAP_DATA_TYPE_2D_TEXTURE),
// 		DISCRIMINANT_TO_STRING(BSP_BITMAP_DATA_TYPE_3D_TEXTURE),
// 		DISCRIMINANT_TO_STRING(BSP_BITMAP_DATA_TYPE_CUBE_MAP),
// 		DISCRIMINANT_TO_STRING(BSP_BITMAP_DATA_TYPE_WHITE)
// 	};

// 	if (type >= BSP_BITMAP_DATA_TYPE_COUNT)
// 		return NULL;

// 	return names[type];
// }

// inline const char* BSPBitmapType_to_string(BSPBitmapType type) {
// 	assert(type < BSP_BITMAP_TYPE_COUNT && "invalid type");

// 	static const char* names[] = {
// 		DISCRIMINANT_TO_STRING(BSP_BITMAP_TYPE_2D_TEXTURES),
//     	DISCRIMINANT_TO_STRING(BSP_BITMAP_TYPE_3D_TEXTURES),
//     	DISCRIMINANT_TO_STRING(BSP_BITMAP_TYPE_CUBE_MAPS),
//     	DISCRIMINANT_TO_STRING(BSP_BITMAP_TYPE_SPRITES),
//     	DISCRIMINANT_TO_STRING(BSP_BITMAP_TYPE_UI)
// 	};

// 	return names[type];
// }

// inline const char* BSPBitmapDataFormat_to_string(BSPBitmapDataFormat format) {
// 	assert(format < BSP_BITMAP_DATA_FORMAT_COUNT && "invalid format");

// 	static const char* names[] = {
// 		DISCRIMINANT_TO_STRING(BSP_BITMAP_DATA_FORMAT_A8),
// 		DISCRIMINANT_TO_STRING(BSP_BITMAP_DATA_FORMAT_Y8),
// 		DISCRIMINANT_TO_STRING(BSP_BITMAP_DATA_FORMAT_AY8),
// 		DISCRIMINANT_TO_STRING(BSP_BITMAP_DATA_FORMAT_A8Y8),
// 		DISCRIMINANT_TO_STRING(BSP_BITMAP_DATA_FORMAT_R5G6B5),
// 		DISCRIMINANT_TO_STRING(BSP_BITMAP_DATA_FORMAT_A1R5G5B5),
// 		DISCRIMINANT_TO_STRING(BSP_BITMAP_DATA_FORMAT_A4R4G4B4),
// 		DISCRIMINANT_TO_STRING(BSP_BITMAP_DATA_FORMAT_X8R8G8B8),
// 		DISCRIMINANT_TO_STRING(BSP_BITMAP_DATA_FORMAT_A8R8G8B8),
// 		DISCRIMINANT_TO_STRING(BSP_BITMAP_DATA_FORMAT_DXT1),
// 		DISCRIMINANT_TO_STRING(BSP_BITMAP_DATA_FORMAT_DXT3),
// 		DISCRIMINANT_TO_STRING(BSP_BITMAP_DATA_FORMAT_DXT5),
// 		DISCRIMINANT_TO_STRING(BSP_BITMAP_DATA_FORMAT_P8_BUMP),
// 		DISCRIMINANT_TO_STRING(BSP_BITMAP_DATA_FORMAT_BC7)
// 	};

// 	return names[format];
// }

// inline const char* BSPBitmapFormat_to_string(BSPBitmapFormat format) {
// 	assert(format < BSP_BITMAP_FORMAT_COUNT && "invalid format");

// 	static const char* names[] = {
// 		DISCRIMINANT_TO_STRING(BSP_BITMAP_FORMAT_DXT1),
//     	DISCRIMINANT_TO_STRING(BSP_BITMAP_FORMAT_DXT3),
//     	DISCRIMINANT_TO_STRING(BSP_BITMAP_FORMAT_DXT5),
//     	DISCRIMINANT_TO_STRING(BSP_BITMAP_FORMAT_16_BIT),
//     	DISCRIMINANT_TO_STRING(BSP_BITMAP_FORMAT_32_BIT),
//     	DISCRIMINANT_TO_STRING(BSP_BITMAP_FORMAT_MONOCHROME),
//     	DISCRIMINANT_TO_STRING(BSP_BITMAP_FORMAT_BC7)
// 	};

// 	return names[format];
// }

// inline const char* BSPBitmapUsage_to_string(BSPBitmapUsage usage) {
// 	assert(usage < BSP_BITMAP_USAGE_COUNT && "invalid usage");

// 	static const char* names[] = {
// 		DISCRIMINANT_TO_STRING(BSP_BITMAP_USAGE_ALPHA_BLEND),
//     	DISCRIMINANT_TO_STRING(BSP_BITMAP_USAGE_DEFAULT),
//     	DISCRIMINANT_TO_STRING(BSP_BITMAP_USAGE_HEIGHT_MAP),
//     	DISCRIMINANT_TO_STRING(BSP_BITMAP_USAGE_DETAIL_MAP),
//     	DISCRIMINANT_TO_STRING(BSP_BITMAP_USAGE_LIGHT_MAP),
//     	DISCRIMINANT_TO_STRING(BSP_BITMAP_USAGE_VECTOR_MAP)
// 	};

// 	return names[usage];
// }

// inline const char* BSPBitmapSpriteBudgetSize_to_string(BSPBitmapSpriteBudgetSize size) {
// 	assert(size < BSP_BITMAP_SPRITE_BUDGET_SIZE_COUNT && "invalid size");

// 	static const char* names[] = {
// 		DISCRIMINANT_TO_STRING(BSP_BITMAP_SPRITE_BUDGET_SIZE_32x32),
//     	DISCRIMINANT_TO_STRING(BSP_BITMAP_SPRITE_BUDGET_SIZE_64x64),
//     	DISCRIMINANT_TO_STRING(BSP_BITMAP_SPRITE_BUDGET_SIZE_128x128),
//     	DISCRIMINANT_TO_STRING(BSP_BITMAP_SPRITE_BUDGET_SIZE_256x256),
//     	DISCRIMINANT_TO_STRING(BSP_BITMAP_SPRITE_BUDGET_SIZE_512x512),
//     	DISCRIMINANT_TO_STRING(BSP_BITMAP_SPRITE_BUDGET_SIZE_1024x1024)
// 	};

// 	return names[size];
// }

// inline const char* BSPBitmapSpriteUsage_to_string(BSPBitmapSpriteUsage usage) {
// 	assert(usage < BSP_BITMAP_SPRITE_USAGE_COUNT && "invalid usage");

// 	static const char* names[] = {
// 		DISCRIMINANT_TO_STRING(BSP_BITMAP_SPRITE_USAGE_BLEND_ADD_SUBTRACT_MAX),
//     	DISCRIMINANT_TO_STRING(BSP_BITMAP_SPRITE_USAGE_MULTIPLY_MIN),
//     	DISCRIMINANT_TO_STRING(BSP_BITMAP_SPRITE_USAGE_DOUBLE_MULTIPLY)
// 	};

// 	return names[usage];
// }

// #undef DISCRIMINANT_TO_STRING

A_PACK(struct BSPCollisionMaterial {
	TagDependency shader;
	uint16_t      __pad;
	uint16_t      material; // BSPMaterialType
});
typedef struct BSPCollisionMaterial BSPCollisionMaterial;
A_STATIC_ASSERT(sizeof(BSPCollisionMaterial) == 20);

A_PACK(struct BSPBitmapData {
	uint32_t   klass;
	uint16_t   width;
	uint16_t   height;
	uint16_t   depth;
	uint16_t   type;   // BSPBitmapDataType
	uint16_t   format; // BSPBitmapDataType
	uint16_t   flags;
	apoint2s_t registration_point;
	uint16_t   mipmap_count;
	uint16_t   __pad1;
	uint32_t   pixel_data_offset;
	uint32_t   pixel_data_size;
	TagId      bitmap_tag_id;
	NATIVE_PTR(void, pixels);
	uint32_t   actual_size;
});
typedef struct BSPBitmapData BSPBitmapData;
A_STATIC_ASSERT(sizeof(BSPBitmapData) == 48);

A_PACK(struct BSPBitmap {
	// BSPBitmapType
	uint16_t      type;   
	// BSPBitmapFormat
	uint16_t      format; 
	// BSPBitmapUsage
	uint16_t      usage;  
	uint16_t      flags;
	float         detail_fade_factor;
	float         sharpen_amount;
	float         bump_height;
	// BSPBitmapSpriteBudgetSize
	uint16_t      size; 
	uint16_t      sprite_budget_count;
	uint16_t      color_palate_width;
	uint16_t      color_palate_height;
	TagDataOffset compressed_color_palate_data;
	TagDataOffset processed_pixel_data;
	float         blur_filter_size;
	float         alpha_bias;
	uint16_t      mipmap_count;
	// BSPBitmapSpriteUsage
	uint16_t      sprite_usage;
	uint16_t      sprite_spacing;
	uint16_t      __pad;
	TagReflexive  bitmap_group_sequence;
	TagReflexive  bitmap_data;
});
typedef struct BSPBitmap BSPBitmap;
A_STATIC_ASSERT(sizeof(BSPBitmap) == 108);

typedef enum BSPVertexType {
	BSP_VERTEX_TYPE_UNCOMPRESSED_RENDERED,
	BSP_VERTEX_TYPE_COMPRESSED_RENDERED,
	BSP_VERTEX_TYPE_UNCOMPRESSED_LIGHTMAP,
	BSP_VERTEX_TYPE_COMPRESSED_LIGHTMAP,
	BSP_VERTEX_TYPE_UNCOMPRESSED_MODEL,
	BSP_VERTEX_TYPE_COMPRESSED_MODEL,
	BSP_VERTEX_TYPE_COUNT
} BSPVertexType;

A_PACK(struct BSPMaterial {
	TagDependency shader;
	uint16_t      shader_permutation;
	uint16_t      flags;
	uint32_t      surfaces;
	uint32_t      surface_count;
	apoint3f_t    centroid;
	acolor_rgb_t  ambient_color;
	uint16_t      distant_light_count;
	char          __pad1[2];
	acolor_rgb_t  distant_light_0_color;
	avec3f_t      distant_light_0_direction;
	acolor_rgb_t  distant_light_1_color;
	avec3f_t      distant_light_1_direction;
	uint8_t       __pad2[12];
	acolor_argb_t reflection_tint;
	avec3f_t      shadow_vector;
	acolor_rgb_t  shadow_color;
	aplane3f_t    plane;
	uint16_t      breakable_surface;
	char          __pad3[2];
	// BSPVertexType
	uint16_t      rendered_vertices_type; 
	char          __pad4[2];
	uint32_t      rendered_vertices_count;
	uint32_t      rendered_vertices_offset;
	char          __pad5[4];
	uint32_t      rendered_vertices_index_pointer;
	// BSPVertexType
	uint16_t      lightmap_vertices_type; 
	char          __pad6[2];
	uint32_t      lightmap_vertices_count;
	uint32_t      lightmap_vertices_offset;
	char          __pad7[4];
	uint32_t      lightmap_vertices_index_pointer;
	TagDataOffset uncompressed_vertices;
	TagDataOffset compressed_vertices;
});
typedef struct BSPMaterial BSPMaterial;
A_STATIC_ASSERT(sizeof(BSPMaterial) == 256);

A_PACK(struct BSPLightmap {
	uint16_t bitmap_data_index;
	uint8_t __pad[18];
	TagReflexive materials;
});
typedef struct BSPLightmap BSPLightmap;
A_STATIC_ASSERT(sizeof(BSPLightmap) == 32);

A_PACK(struct BSPShader {
	uint16_t     flags;
	uint16_t     detail_level;  // BSPShaderDetailLevel
	float        power;
	acolor_rgb_t emitted_light_color;
	acolor_rgb_t tint_color;
	uint16_t     physics_flags;
	uint16_t     material_type; // BSPMaterialType
	uint16_t     type;          // BSPShaderType
	char         __pad[2];
});
typedef struct BSPShader BSPShader;
A_STATIC_ASSERT(sizeof(BSPShader) == 40);

typedef enum ShaderWaveFunction {
	SHADER_WAVE_FUNCTION_ONE
	// ...
} ShaderWaveFunction;

A_PACK(struct BSPShaderEnvironment {
	BSPShader     base;
	uint16_t      flags;
	uint16_t      type; // BSPShaderEnvironmentType
	float         lens_flare_spacing;
	TagDependency lens_flare;
	char          __pad1[44];
	uint16_t      diffuse_flags;
	char          __pad2[26];
	TagDependency base_map;
	char          __pad3[24];
	uint16_t      detail_map_function; // BSPShaderDetailFunction
	char          __pad4[2];
	float         primary_detail_map_scale;
	TagDependency primary_detail_map;
	float         secondary_detail_map_scale;
	TagDependency secondary_detail_map;
	char          __pad5[24];
	uint16_t     micro_detail_map_function;
	uint16_t      __pad6;
	float         micro_detail_map_scale;
	TagDependency micro_detail_map;
	acolor_rgb_t  material_color;
	char          __pad7[12];
	float         bump_map_scale;
	TagDependency bump_map;
	apoint2f_t    bump_map_scale_xy;
	char          __pad8[16];
	uint16_t      u_anim_fn; // ShaderWaveFunction
	uint16_t      __pad9;
	float         u_anim_period;
	float         u_anim_scale;
	uint16_t      v_anim_function; // ShaderWaveFunction
	char          __pad10[2];
	float         v_anim_period;
	float         v_anim_scale;
	char          __pad11[24];
	uint16_t      self_illumination_flags;
	char          __pad12[26];
	acolor_rgb_t  primary_on_color;
	acolor_rgb_t  primary_off_color;
	uint16_t      primary_anim_function; // ShaderWaveFunction
	char          __pad13[2];
	float         primary_anim_period;
	float         primary_anim_phase;
	char          __pad14[24];
	acolor_rgb_t  secondary_on_color;
	acolor_rgb_t  secondary_off_color;
	uint16_t      secondary_anim_function; // ShaderWaveFunction
	char          __pad15[2];
	float         secondary_anim_period;
	float         secondary_anim_phase;
	char          __pad16[24];
	acolor_rgb_t  plasma_on_color;
	acolor_rgb_t  plasma_off_color;
	uint16_t      plasma_anim_function; // ShaderWaveFunction
	uint16_t      __pad17;
	float         plasma_anim_period;
	float         plasma_anim_phase;
	char          __pad18[24];
	float         map_scale;
	TagDependency map;
	char          __pad19[224];
});
typedef struct BSPShaderEnvironment BSPShaderEnvironment;
A_STATIC_ASSERT(sizeof(BSPShaderEnvironment) == 836);

typedef enum BSPShaderModelFlags {
	BSP_SHADER_MODEL_FLAGS_FLAG_DETAIL_AFTER_REFLECTION             = 0x01,
	BSP_SHADER_MODEL_FLAGS_FLAG_TWO_SIDED                           = 0x02,
	BSP_SHADER_MODEL_FLAGS_FLAG_NOT_ALPHA_TESTED                    = 0x04,
	BSP_SHADER_MODEL_FLAGS_FLAG_ALPHA_BLENDED_DECAL                 = 0x08,
	BSP_SHADER_MODEL_FLAGS_FLAG_TRUE_ATMOSPHERIC_FOG                = 0x10,
	BSP_SHADER_MODEL_FLAGS_FLAG_DISABLE_TWO_SIDED_CULLING           = 0x20,
	BSP_SHADER_MODEL_FLAGS_FLAG_USE_XBOX_MULTIPURPOSE_CHANNEL_ORDER = 0x40
} BSPShaderModelFlags;

typedef enum BSPShaderModelDetailMask {
	BSP_SHADER_MODEL_DETAIL_MASK_NONE                           = 0,
	BSP_SHADER_MODEL_DETAIL_MASK_REFLECTION_MASK_INVERSE        = 1,
	BSP_SHADER_MODEL_DETAIL_MASK_REFLECTION_MASK                = 2,
	BSP_SHADER_MODEL_DETAIL_MASK_SELF_ILLUMINATION_MASK_INVERSE = 3,
	BSP_SHADER_MODEL_DETAIL_MASK_SELF_ILLUMINATION_MASK         = 4,
	BSP_SHADER_MODEL_DETAIL_MASK_CHANGE_COLOR_MASK_INVERSE      = 5,
	BSP_SHADER_MODEL_DETAIL_MASK_CHANGE_COLOR_MASK              = 6,
	BSP_SHADER_MODEL_DETAIL_MASK_AUXILIARY_MASK_INVERSE         = 7,
	BSP_SHADER_MODEL_DETAIL_MASK_AUXILIARY_MASK                 = 8,
} BSPShaderModelDetailMask;

A_PACK(struct BSPShaderModel {
	BSPShader     base;
	// BSPShaderModelFlags
	uint16_t      flags;
	char          __pad1[14];
	float         translucency;
	char          __pad2[16];
	// BSPObjectFunctionNameNullable
	uint16_t      change_color_sequence;
	char          __pad3[30];
	uint16_t      more_flags;
	char          __pad4[2];
	// BSPObjectFunctionNameNullable
	uint16_t      color_sequence;
	// BSPObjectWaveFunction
	uint16_t      animation_function;
	float         animation_period;
	acolor_rgb_t  animation_color_upper_bound;
	acolor_rgb_t  animation_color_lower_bound;
	char          __pad5[12];
	float         map_u_scale;
	float         map_v_scale;
	TagDependency base_map;
	char          __pad6[8];
	TagDependency multipurpose_map;
	char          __pad7[8];
	// BSPShaderDetailFunction
	uint16_t      detail_function;
	// BSPShaderModelDetailMask
	uint16_t      detail_mask;
	float         detail_map_scale;
	TagDependency detail_map;
	float         detail_map_v_scale;
	char          __pad8[12];
	// BSPObjectFunctionOut 
	uint16_t      u_animation_source;
	// BSPObjectWaveFunction
	uint16_t      u_anumation_function;
	float         u_animation_period;
	float         u_animation_phase;
	float         u_animation_scale;
	// BSPObjectFunctionOut 
	uint16_t      v_animation_source;
	// BSPObjectWaveFunction
	uint16_t      v_anumation_function;
	float         v_animation_period;
	float         v_animation_phase;
	float         v_animation_scale;
	// BSPObjectFunctionOut 
	uint16_t      rotation_animation_source;
	// BSPObjectWaveFunction
	uint16_t      rotation_anumation_function;
	float         rotation_animation_period;
	float         rotation_animation_phase;
	float         rotation_animation_scale;
	apoint2f_t    rotation_animation_center;
	char          __pad9[8];
	float         reflection_falloff_distance;
	float         reflextion_curoff_distance;
	float         perpendicular_brightness;
	acolor_rgb_t  perpendicular_tint_color;
	float         parallel_brightness;
	acolor_rgb_t  parallel_tint_color;
	TagDependency reflection_cube_map;
	char          __pad10[68];
});
typedef struct BSPShaderModel BSPShaderModel;
A_STATIC_ASSERT(sizeof(BSPShaderModel) == 440);

A_PACK(struct BSPSky {
	TagDependency model;
	TagDependency anim_graph;
	char          __pad1[24];
	acolor_rgb_t  indoor_ambient_color;
	float         indoor_ambient_power;
	acolor_rgb_t  outdoor_ambient_color;
	float         outdoor_ambient_power;
	acolor_rgb_t  outdoor_fog_color;
	char          __pad2[8];
	float         outdoor_fog_maximum_density;
	float         outdoor_fog_start_distance;
	float         outdoor_fog_opaque_distance;
	acolor_rgb_t  indoor_fog_color;
	char          __pad3[8];
	float         indoor_fog_maximum_density;
	float         indoor_fog_start_distance;
	float         indoor_fog_opaque_distance;
	TagDependency indoor_fog_screen;
	char          __pad4[4];
	TagReflexive  shader_functions;
	TagReflexive  anims;
	TagReflexive  lights;
});
typedef struct BSPSky BSPSky;
A_STATIC_ASSERT(sizeof(BSPSky) == 208);

typedef enum BSPModelFlags {
	BSP_MODEL_FLAG_SHARED_NORMALS         = 0x01,
	BSP_MODEL_FLAG_PARTS_HAVE_LOCAL_NODES = 0x02,
	BSP_MODEL_FLAG_IGNORE_SKINNING        = 0x04
} BSPModelFlags;

A_PACK(struct BSPModelMarkerInstance {
	uint8_t    region_index;
	uint8_t    permutation_index;
	uint8_t    node_index;
	char       __pad;
	apoint3f_t translation;
	aquatf_t   rotation;
});
typedef struct BSPModelMarkerInstance BSPModelMarkerInstance;
A_STATIC_ASSERT(sizeof(BSPModelMarkerInstance) == 32);

A_PACK(struct BSPModelMarker {
	char         name[32];
	uint16_t     magic;
	char         __pad[18];
	TagReflexive instances;
});
typedef struct BSPModelMarker BSPModelMarker;
A_STATIC_ASSERT(sizeof(BSPModelMarker) == 64);

A_PACK(struct BSPModelNode {
	char       name[32];
	uint16_t   next_sibling_node_index;
	uint16_t   first_child_node_index;
	uint16_t   parent_node_index;
	char       __pad1[2];
	apoint3f_t default_translation;
	aquatf_t   default_rotation;
	float      node_distance_from_parent;
	char       __pad2[32];
	float      scale;
	amat3f_t   rotation;
	apoint3f_t translation;
});
typedef struct BSPModelNode BSPModelNode;
A_STATIC_ASSERT(sizeof(BSPModelNode) == 156);

typedef enum BSPModelRegionPermutationFlags {
	BSP_MODEL_REGION_PERMUTATION_FLAG_NO_RANDOM = 0x01
} BSPModelRegionPermutationFlags;

A_PACK(struct BSPModelRegionPermutation {
	char name[32];
	// BSPModelRegionPermutationFlags
	int flags;
	uint16_t permutation_number;
	char __pad1[26];
	uint16_t super_low_geometry_index;
	uint16_t low_geometry_index;
	uint16_t medium_geometry_index;
	uint16_t high_geometry_index;
	uint16_t super_high_geometry_index;
	char __pad2[2];
	TagReflexive markers;
});
typedef struct BSPModelRegionPermutation BSPModelRegionPermutation;
A_STATIC_ASSERT(sizeof(BSPModelRegionPermutation) == 88);

A_PACK(struct ModelRegion {
	char name[32];
	char __pad[32];
	TagReflexive permutations;
});
typedef struct ModelRegion ModelRegion;
A_STATIC_ASSERT(sizeof(ModelRegion) == 76);

A_PACK(struct BSPModelTri {
	uint16_t vert_indices[3];
});
typedef struct BSPModelTri BSPModelTri;
A_STATIC_ASSERT(sizeof(BSPModelTri) == 6);

typedef enum BSPModelGeometryPartFlags {
	BSP_MODEL_GEOMETRY_PART_FLAG_STRIPPED_INTERNAL = 0x01,
	BSP_MODEL_GEOMETRY_PART_FLAG_ZONER = 0x02,

} BSPModelGeometryPartFlags;

typedef enum BSPModelTriBufferType {
	BSP_MODEL_TRI_BUFFER_TYPE_TRIANGLE_LIST = 0,
	BSP_MODEL_TRI_BUFFER_TYPE_TRIANGLE_STRIP = 1
} BSPModelTriBufferType;

A_PACK(struct BSPModelDecompressedVertex {
	apoint3f_t position;
	avec3f_t   normal;
	avec3f_t   binormal;
	avec3f_t   tangent;
	apoint2f_t texcoords;
	uint16_t   node0_index;
	uint16_t   node1_index;
	float      node0_weight;
	float      node1_weight;
});
typedef struct BSPModelDecompressedVertex BSPModelDecompressedVertex;
A_STATIC_ASSERT(sizeof(BSPModelDecompressedVertex) == 68);

A_PACK(struct BSPModelCompressedVertex {
	apoint3f_t position;
	uint32_t   normal;
	uint32_t   binormal;
	uint32_t   tangent;
	apoint2s_t texcoords;
	uint8_t    node0_index;
	uint8_t    node1_index;
	uint16_t   node0_weight;
});
typedef struct BSPModelCompressedVertex BSPModelCompressedVertex;
A_STATIC_ASSERT(sizeof(BSPModelCompressedVertex) == 32);

A_PACK(struct BSPModelGeometryPart {
	int          flags;
	uint16_t     shader_index;
	uint8_t      prev_filthy_part_index;
	uint8_t      next_filthy_part_index;
	uint16_t     centroid_primary_node;
	uint16_t     centroid_secondary_node;
	float        centroid_primary_weight;
	float        centroid_secondary_weight;
	apoint3f_t   centroid;
	TagReflexive decompressed_vertices;
	TagReflexive compressed_vertices;
	TagReflexive triangles;
	// BSPModelTriBufferType
	uint16_t     tri_buffer_type;
	char         __pad1[2];
	uint32_t     tri_count;
	uint32_t     tri_offset;
	uint32_t     tri_offset2;
	// BSPVertexType
	uint16_t     vertex_type;
	char         __pad2[2];
	uint32_t     vertex_count;
	char         __pad3[4];
	uint32_t     vertex_pointer;
	uint32_t     vertex_offset;
});
typedef struct BSPModelGeometryPart BSPModelGeometryPart;
A_STATIC_ASSERT(sizeof(BSPModelGeometryPart) == 104);

typedef enum BSPModelGeometryFlags {
	BSP_MODEL_GEOMETRY_FLAG_UNUSED = 0x01
} BSPModelGeometryFlags;

A_PACK(struct BSPModelGeometry {
	// BSPModelGeometryFlags
	int          flags;
	char         __pad[32];
	TagReflexive parts;
});
typedef struct BSPModelGeometry BSPModelGeometry;
A_STATIC_ASSERT(sizeof(BSPModelGeometry) == 48);

A_PACK(struct BSPModelShaderReference {
	TagDependency shader;
	uint16_t      permutation;
	char          __pad[14];
});
typedef struct BSPModelShaderReference BSPModelShaderReference;
A_STATIC_ASSERT(sizeof(BSPModelShaderReference) == 32);

A_PACK(struct BSPModel {
	// BSPModelFlags
	uint32_t     flags;
	int32_t      node_list_checksum;
	float        super_high_detail_cutoff;
	float        high_detail_cutoff;
	float        medium_detail_cutoff;
	float        low_detail_cutoff;
	float        super_low_detail_cutoff;
	uint16_t     super_low_detail_node_count;
	uint16_t     low_detail_node_count;
	uint16_t     medium_detail_node_count;
	uint16_t     high_detail_node_count;
	uint16_t     super_high_detail_node_count;
	char         __pad1[10];
	float        base_map_u_scale;
	float        base_map_v_scale;
	char         __pad2[116];
	TagReflexive markers;
	TagReflexive nodes;
	TagReflexive regions;
	TagReflexive geometries;
	TagReflexive shaders;
});
typedef struct BSPModel BSPModel;
A_STATIC_ASSERT(sizeof(BSPModel) == 232);

typedef enum BSPObjectType {
	BSP_OBJECT_TYPE_BIPED = 0,
	BSP_OBJECT_TYPE_VEHICLE = 1,
	BSP_OBJECT_TYPE_WEAPON = 2,
	BSP_OBJECT_TYPE_EQUIPMENT = 3,
	BSP_OBJECT_TYPE_GARBAGE = 4,
	BSP_OBJECT_TYPE_PROJECTILE = 5,
	BSP_OBJECT_TYPE_SCENERY = 6,
	BSP_OBJECT_TYPE_DEVICE_MACHINE = 7,
	BSP_OBJECT_TYPE_DEVICE_CONTROL = 8,
	BSP_OBJECT_TYPE_DEVICE_LIGHT_FIXTURE = 9,
	BSP_OBJECT_TYPE_PLACEHOLDER = 10,
	BSP_OBJECT_TYPE_SOUND_SCENERY = 11
} BSPObjectType;

typedef enum BSPObjectFlags {
	BSP_OBJECT_FLAG_DOES_NOT_CAST_SHADOW = 0x01,
	BSP_OBJECT_FLAG_TRANSPARENT_SELF_OCCLUSION = 0x02,
	BSP_OBJECT_FLAG_BRIGHTER_THAN_IT_SHOULD_BE = 0x04,
	BSP_OBJECT_FLAG_NOT_A_PATHFINDING_OBSTACLE = 0x08,
	BSP_OBJECT_FLAG_EXTENSION_OF_PARENT = 0x10,
	BSP_OBJECT_FLAG_CAST_SHADOW_BY_DEFAULT = 0x20,
	BSP_OBJECT_FLAG_DOES_NOT_HAVE_ANNIVERSARY_GEOMETRY = 0x40
} BSPObjectFlags;

typedef enum BSPObjectFunctionIn {
	BSP_OBJECT_FUNCTION_IN_NONE = 0,
	BSP_OBJECT_FUNCTION_IN_BODY_VITALITY = 1,
	BSP_OBJECT_FUNCTION_IN_SHIELD_VITALITY = 2,
	BSP_OBJECT_FUNCTION_IN_RECENT_BODY_DAMAGE = 3,
	BSP_OBJECT_FUNCTION_IN_RECENT_SHIELD_DAMAGE = 4,
	BSP_OBJECT_FUNCTION_IN_RANDOM_CONSTANT = 5,
	BSP_OBJECT_FUNCTION_IN_UMBRELLA_SHIELD_VITALITY = 6,
	BSP_OBJECT_FUNCTION_IN_SHIELD_STUN = 7,
	BSP_OBJECT_FUNCTION_IN_RECENT_UMBRELLA_SHIELD_VITALITY = 8,
	BSP_OBJECT_FUNCTION_IN_UMBRELLA_SHIELD_STUN = 9,
	BSP_OBJECT_FUNCTION_IN_REGION = 10,
	BSP_OBJECT_FUNCTION_IN_REGION_1 = 11,
	BSP_OBJECT_FUNCTION_IN_REGION_2 = 12,
	BSP_OBJECT_FUNCTION_IN_REGION_3 = 13,
	BSP_OBJECT_FUNCTION_IN_REGION_4 = 14,
	BSP_OBJECT_FUNCTION_IN_REGION_5 = 15,
	BSP_OBJECT_FUNCTION_IN_REGION_6 = 16,
	BSP_OBJECT_FUNCTION_IN_REGION_7 = 17,
	BSP_OBJECT_FUNCTION_IN_ALIVE = 18,
	BSP_OBJECT_FUNCTION_IN_COMPASS = 19
} BSPObjectFunctionIn;

typedef enum BSPObjectFunctionOut {
	BSP_OBJECT_FUNCTION_OUT_NONE = 0,
	BSP_OBJECT_FUNCTION_OUT_A_OUT = 1,
	BSP_OBJECT_FUNCTION_OUT_B_OUT = 2,
	BSP_OBJECT_FUNCTION_OUT_C_OUT = 3,
	BSP_OBJECT_FUNCTION_OUT_D_OUT = 4,
} BSPObjectFunctionOut;

typedef enum BSPObjectFunctionNameNullable {
	BSP_OBJECT_FUNCTION_NAME_NULLABLE_NONE,
	BSP_OBJECT_FUNCTION_NAME_NULLABLE_A,
	BSP_OBJECT_FUNCTION_NAME_NULLABLE_B,
	BSP_OBJECT_FUNCTION_NAME_NULLABLE_C,
	BSP_OBJECT_FUNCTION_NAME_NULLABLE_D,
} BSPObjectFunctionNameNullable;

A_PACK(struct BSPObjectAttachment {
	TagDependency type;
	char          marker[32];
	// BSPObjectFunctionOut
	uint16_t      primary_scale;
	uint16_t      secondary_scale;
	// BSPObjectFunctionNameNullable
	uint16_t      change_color;
	char          __pad[18];
});
typedef struct BSPObjectAttachment BSPObjectAttachment;
A_STATIC_ASSERT(sizeof(BSPObjectAttachment) == 72);

A_PACK(struct BSPObjectWidget {
	TagDependency reference;
	char          __pad[16];
});
typedef struct BSPObjectWidget BSPObjectWidget;
A_STATIC_ASSERT(sizeof(BSPObjectWidget) == 32);

typedef enum BSPObjectFunctionFlags {
	BSP_OBJECT_FUNCTION_FLAGS_FLAG_INVERT        = 0x01,
	BSP_OBJECT_FUNCTION_FLAGS_FLAG_ADDITIVE      = 0x02,
	BSP_OBJECT_FUNCTION_FLAGS_FLAG_ALWAYS_ACTIVE = 0x04,
} BSPObjectFunctionFlags;

typedef enum BSPObjectFunctionScaleBy {
	BSP_OBJECT_FUNCTION_SCALE_BY_NONE  = 0,
	BSP_OBJECT_FUNCTION_SCALE_BY_A_IN  = 1,
	BSP_OBJECT_FUNCTION_SCALE_BY_B_IN  = 2,
	BSP_OBJECT_FUNCTION_SCALE_BY_C_IN  = 3,
	BSP_OBJECT_FUNCTION_SCALE_BY_D_IN  = 4,
	BSP_OBJECT_FUNCTION_SCALE_BY_A_OUT = 5,
	BSP_OBJECT_FUNCTION_SCALE_BY_B_OUT = 6,
	BSP_OBJECT_FUNCTION_SCALE_BY_C_OUT = 7,
	BSP_OBJECT_FUNCTION_SCALE_BY_D_OUT = 8
} BSPObjectFunctionScaleBy;

typedef enum BSPObjectWaveFunction {
	BSP_OBJECT_WAVE_FUNCTION_ONE,
	BSP_OBJECT_WAVE_FUNCTION_ZERO,
	BSP_OBJECT_WAVE_FUNCTION_COSINE,
	BSP_OBJECT_WAVE_FUNCTION_COSINE_VARIABLE_PERIOD,
	BSP_OBJECT_WAVE_FUNCTION_DIAGONAL_WAVE,
	BSP_OBJECT_WAVE_FUNCTION_DIAGONAL_WAVE_VARIABLE_PERIOD,
	BSP_OBJECT_WAVE_FUNCTION_SLIDE,
	BSP_OBJECT_WAVE_FUNCTION_SLIDE_VARIABLE_PERIOD,
	BSP_OBJECT_WAVE_FUNCTION_NOISE,
	BSP_OBJECT_WAVE_FUNCTION_JITTER,
	BSP_OBJECT_WAVE_FUNCTION_WANDER,
	BSP_OBJECT_WAVE_FUNCTION_SPARK
} BSPObjectWaveFunction;

typedef enum BSPObjectFunctionType {
	BSP_OBJECT_FUNCTION_TYPE_LINEAR,
	BSP_OBJECT_FUNCTION_TYPE_EARLY,
	BSP_OBJECT_FUNCTION_TYPE_VERY_EARLY,
	BSP_OBJECT_FUNCTION_TYPE_LATE,
	BSP_OBJECT_FUNCTION_TYPE_VERY_LATE,
	BSP_OBJECT_FUNCTION_TYPE_COSINE
} BSPObjectFunctionType;

typedef enum BSPObjectFunctionBoundsMode {
	BSP_OBJECT_FUNCTION_BOUNDS_MODE_CLIP,
	BSP_OBJECT_FUNCTION_BOUNDS_MODE_CLIP_AND_NORMALIZE,
	BSP_OBJECT_FUNCTION_BOUNDS_MODE_SCALE_TO_FIT
} BSPObjectFunctionBoundsMode;

A_PACK(struct BSPObjectFunction {
	BSPObjectFunctionFlags flags;
	float                  period;
	// BSPObjectFunctionScaleBy
	uint16_t               scale_period_by;
	// BSPObjectWaveFunction
	uint16_t               function;
	// BSPObjectFunctionScaleBy
	uint16_t               scale_function_by;
	// BSPObjectWaveFunction
	uint16_t               wobble_function;
	float                  wobble_period;
	float                  wobble_magnitude;
	float                  square_wave_threshold;
	uint16_t               step_count;
	// BSPObjectFunctionType
	uint16_t               map_to;
	uint16_t               sawtooth_count;
	// BSPObjectFunctionScaleBy
	uint16_t               add;
	uint16_t               scale_result_by;
	// BSPObjectFunctionBoundsMode
	uint16_t    bounds_mode;
	abounds2f_t bounds;
	char         __pad1[6];
	uint16_t     turn_off_with;
	float        scale_by;
	char         __pad2[252];
	float        inverse_bounds;
	float        inverse_sawtooth;
	float        inverse_step;
	float        inverse_period;
	char         usage[32];
});
typedef struct BSPObjectFunction BSPObjectFunction;
A_STATIC_ASSERT(sizeof(BSPObjectFunction) == 360);

typedef enum BSPObjectColorInterpolationFlags {
	BSP_OBJECT_COLOR_INTERPOLATION_FLAG_BLEND_IN_HSV = 0x01,
	BSP_OBJECT_COLOR_INTERPOLATION_FLAG_MORE_COLORS  = 0x02
} BSPObjectColorInterpolationFlags;

A_PACK(struct BSPObjectChangeColorsPermutation {
	float        weight;
	acolor_rgb_t color_lower_bound;
	acolor_rgb_t color_upper_bound;
});
typedef struct BSPObjectChangeColorsPermutation 
	BSPObjectChangeColorsPermutation;
A_STATIC_ASSERT(sizeof(BSPObjectChangeColorsPermutation) == 28);

A_PACK(struct BSPObjectChangeColors {
	// BSPObjectFunctionScaleBy
	uint16_t                         darken_by;
	uint16_t                         scale_by;
	BSPObjectColorInterpolationFlags flags;
	acolor_rgb_t                     color_lower_bound;
	acolor_rgb_t                     color_upper_bound;
	TagReflexive                     permutations;
});
typedef struct BSPObjectChangeColors BSPObjectChangeColors;
A_STATIC_ASSERT(sizeof(BSPObjectChangeColors) == 44);

typedef enum BSPObjectPredictedResourceType {
	BSP_OBJECT_PREDICTED_RESOURCE_TYPE_BITMAP = 0,
	BSP_OBJECT_PREDICTED_RESOURCE_TYPE_SOUND  = 1
} BSPObjectPredictedResourceType;

A_PACK(struct BSPObjectPredictedResource {
	// BSPObjectPredictedResourceType
	uint16_t type;
	uint16_t index;
	TagId    id;
});
typedef struct BSPObjectPredictedResource BSPObjectPredictedResource;
A_STATIC_ASSERT(sizeof(BSPObjectPredictedResource) == 8);

A_PACK(struct BSPObject {
	// BSPObjectType
	uint16_t      type;
	// BSPObjectFlags
	uint16_t      flags;
	float         bounding_radius;
	apoint3f_t    bounding_offset;
	apoint3f_t    origin_offset;
	float         accel_scale;
	uint32_t      scales_change_colors;
	TagDependency model;
	TagDependency anim_graph;
	char          __pad1[40];
	TagDependency collision_model;
	TagDependency physics;
	TagDependency modifier_shader;
	TagDependency creation_effect;
	char          __pad2[84];
	float         render_bounding_radius;
	// BSPObjectFunctionIn
	uint16_t      a_in;
	uint16_t      b_in;
	uint16_t      c_in;
	uint16_t      d_in;
	char          __pad3[44];
	uint16_t      hud_message_text_index;
	uint16_t      forced_shader_permutation_index;
	TagReflexive  attachments;
	TagReflexive  widgets;
	TagReflexive  functions;
	TagReflexive  change_colors;
	TagReflexive  predicted_resources;
});
typedef struct BSPObject BSPObject;
A_STATIC_ASSERT(sizeof(BSPObject) == 380);

typedef enum BSPBaseObjectFlags {
	BSP_BASE_OBJECT_FLAG_OFF_IN_PEGASUS = 0x01
} BSPBaseObjectFlags;

A_PACK(struct BSPBasicObject {
	BSPObject object;
	char      __pad1[2];
	// BSPBaseObjectFlags
	uint16_t  more_flags;
	char      __pad2[124];
});
typedef struct BSPBasicObject BSPBasicObject;
A_STATIC_ASSERT(sizeof(BSPBasicObject) == 508);

typedef BSPBasicObject BSPScenery;

typedef enum BSPScenarioSceneryFlags {
	BSP_SCENARIO_SCENERY_FLAG_NOT_AUTOMATICALLY_PLACED = 0x01,
	BSP_SCENARIO_SCENERY_FLAG_PRESENT_ON_EASY          = 0x02,
	BSP_SCENARIO_SCENERY_FLAG_PRESENT_ON_NORMAL        = 0x04,
	BSP_SCENARIO_SCENERY_FLAG_PRESENT_ON_HARD          = 0x08
} BSPScenarioSceneryFlags;

A_PACK(struct BSPScenarioScenery {
	uint16_t   type;
	uint16_t   name_index;
	// BSPScenarioSceneryFlags
	uint16_t   flags;
	uint16_t   desired_permutation;
	apoint3f_t pos;
	float      yaw;
	float      pitch;
	float      roll;
	uint16_t   bsp_indices;
	char       __pad1[2];
	uint8_t    appearance_player_index;
	char       __pad2[35];
});
typedef struct BSPScenarioScenery BSPScenarioScenery;
A_STATIC_ASSERT(sizeof(BSPScenarioScenery) == 72);

A_PACK(struct BSPScenarioObjectName {
	char     name[32];
	uint16_t object_type;
	uint16_t object_index;
});
typedef struct BSPScenarioObjectName BSPScenarioObjectName;
A_STATIC_ASSERT(sizeof(BSPScenarioObjectName) == 36);

A_PACK(struct BSPScenarioSceneryPalette {
	TagDependency name;
	char          __pad[32];
});
typedef struct BSPScenarioSceneryPalette BSPScenarioSceneryPalette;
A_STATIC_ASSERT(sizeof(BSPScenarioSceneryPalette) == 48);

A_EXTERN_C void                       CL_InitMap(void);
A_EXTERN_C bool                       CL_LoadMap(const char* map_name);
A_EXTERN_C bool                       CL_UnloadMap(void);
A_EXTERN_C void                       CL_ShutdownMap(void);
							          
A_EXTERN_C Tag*                       CL_Map_Tag(TagId id);
A_EXTERN_C BSPSurf*                   CL_Map_Surfs(void);
A_EXTERN_C uint32_t       	          CL_Map_SurfCount(void);
A_EXTERN_C BSPRenderedVertex*         CL_Map_RenderedVertices(void);
A_EXTERN_C BSPLightmapVertex*         CL_Map_LightmapVertices(void);
A_EXTERN_C BSPCollSurf*               CL_Map_CollSurfs(void);
A_EXTERN_C uint32_t       	          CL_Map_CollSurfCount(void);
A_EXTERN_C BSPCollEdge*               CL_Map_CollEdges(void);
A_EXTERN_C uint32_t        	          CL_Map_CollEdgeCount(void);
A_EXTERN_C BSPCollVertex*             CL_Map_CollVertices(void);
A_EXTERN_C uint32_t       	          CL_Map_CollVertexCount(void);
A_EXTERN_C BSPLightmap*               CL_Map_Lightmap(uint16_t i);
A_EXTERN_C uint32_t                   CL_Map_LightmapCount(void);
A_EXTERN_C BSPScenarioScenery*        CL_Map_ScenarioScenery(uint16_t i);
A_EXTERN_C uint32_t                   CL_Map_ScenarioSceneryCount(void);
A_EXTERN_C BSPScenarioSceneryPalette* CL_Map_ScenarioSceneryPalette(uint16_t i);
A_EXTERN_C uint32_t                   CL_Map_ScenarioSceneryPaletteCount(void);

A_EXTERN_C bool                       CL_BitmapDataFormatIsCompressed(BSPBitmapDataFormat format);
A_EXTERN_C size_t                     CL_BitmapDataFormatBPP(BSPBitmapDataFormat format);
