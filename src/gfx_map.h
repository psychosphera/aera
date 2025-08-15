#pragma once

#include "cl_map.h"
#include "gfx_defs.h"
#include "gfx_shader.h"

#define R_MODEL_MAX_SHADERS 32

#define SHADER_ENVIRONMENT_BASE_MAP_INDEX             0
#define SHADER_ENVIRONMENT_PRIMARY_DETAIL_MAP_INDEX   1
#define SHADER_ENVIRONMENT_SECONDARY_DETAIL_MAP_INDEX 2
#define SHADER_ENVIRONMENT_MICRO_DETAIL_MAP_INDEX     3
#define SHADER_ENVIRONMENT_BUMP_MAP_INDEX             4
#define SHADER_ENVIRONMENT_MAP_INDEX                  5

#define SHADER_MODEL_BASE_MAP_INDEX                   0
#define SHADER_MODEL_MULTIPURPOSE_MAP_INDEX           1
#define SHADER_MODEL_DETAIL_MAP_INDEX                 2

typedef struct GfxShaderEnvironment {
    GfxImage                base_map, primary_detail_map, secondary_detail_map;
    GfxImage                micro_detail_map, bump_map, map;
    bool                    alpha_tested;
    BSPShaderDetailFunction detail_map_function, micro_detail_map_function;
} GfxShaderEnvironment;

typedef struct GfxShaderModel {
    GfxImage                base_map, multipurpose_map, detail_map;
    BSPShaderDetailFunction detail_function;
} GfxShaderModel;

typedef enum GfxShaderType {
    SHADER_TYPE_ENVIRONMENT,
    SHADER_TYPE_MODEL
} GfxShaderType;

typedef struct GfxShader {
    GfxShaderType type;
    union {
        GfxShaderEnvironment environment;
        GfxShaderModel       model;
    };
} GfxShader;

typedef struct GfxMaterial {
    size_t               vertices_count;
    GfxVertexDeclaration vertex_declaration;
    GfxShader            shader;
    acolor_rgb_t         ambient_color;
    avec3f_t             distant_light_0_dir;
    avec3f_t             distant_light_1_dir;
    acolor_rgb_t         distant_light_0_color;
    acolor_rgb_t         distant_light_1_color;
} GfxMaterial;

typedef struct GfxLightmap {
    GfxMaterial* materials;
    uint32_t     material_count;
} GfxLightmap;

typedef struct GfxModelPart {
    GfxPrimitiveType     primitive_type;
    GfxVertexDeclaration vertex_declaration;
    uint32_t             shader_index;
    apoint3f_t           position;
} GfxModelPart;

typedef struct GfxModelGeometry {
    GfxModelPart* parts;
    uint32_t      part_count;
} GfxModelGeometry;

typedef struct GfxModel {
    GfxShader         shaders[R_MODEL_MAX_SHADERS];
    GfxModelGeometry* geometries;
    uint32_t          geometry_count;
} GfxModel;

typedef struct GfxObject {
    GfxModel model;
} GfxObject;

typedef struct GfxScenery {
    apoint3f_t pos;
    avec3f_t   rotation;
    uint16_t   palette_index;
} GfxScenery;

typedef struct GfxSceneryPalette {
    GfxObject obj;
} GfxSceneryPalette;

typedef struct MapRenderGlob {
    GfxLightmap*       lightmaps;
    uint32_t           lightmap_count;
    GfxScenery*        scenery;
    uint32_t           scenery_count;
    GfxSceneryPalette* scenery_palette;
    uint32_t           scenery_palette_count;
    GfxShaderProgram   prog;
    GfxShaderProgram   model_prog;
} MapRenderGlob;
extern MapRenderGlob r_mapGlob;

A_EXTERN_C void R_InitMap(void);
A_EXTERN_C void R_LoadMap(void);
A_EXTERN_C void R_RenderMap(void);
A_EXTERN_C void R_UnloadMap(void);
A_EXTERN_C void R_ShutdownMap(void);
