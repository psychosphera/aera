#pragma once

#include "cl_map.h"
#include "gfx_defs.h"
#include "gfx_shader.h"

typedef struct GfxMaterial {
    GfxMaterialPass         pass;
    size_t                  vertices_count;
    bool                    alpha_tested;
    BSPShaderDetailFunction detail_map_function, micro_detail_map_function;
    acolor_rgb_t            color;
    acolor_rgb_t            ambient_color;
    avec3f_t                distant_light_0_dir;
    avec3f_t                distant_light_1_dir;
    acolor_rgb_t            distant_light_0_color;
    acolor_rgb_t            distant_light_1_color;
} GfxMaterial;

typedef struct GfxLightmap {
    GfxMaterial* materials;
    uint32_t     material_count;
} GfxLightmap;

typedef struct GfxModelPart {
    uint32_t vertex_count;
    BSPModelTriBufferType type;
    GfxVertexBuffer vb;
} GfxModelPart;

typedef struct GfxModelGeometry {
    GfxModelPart* parts;
    uint32_t      part_count;
} GfxModelGeometry;

typedef struct GfxModel {
    GfxModelGeometry* geometries;
    uint32_t          geometry_count;
} GfxModel;

typedef struct GfxObject {
    GfxModel model;
} GfxObject;

typedef struct GfxScenery {
    GfxObject obj;
} GfxScenery;

typedef struct MapRenderGlob {
    GfxLightmap*     lightmaps;
    uint32_t         lightmap_count;
    GfxScenery*      scenery;
    uint32_t         scenery_count;
    GfxShaderProgram prog;
} MapRenderGlob;
extern MapRenderGlob r_mapGlob;

A_EXTERN_C void R_InitMap(void);
A_EXTERN_C void R_LoadMap(void);
A_EXTERN_C void R_RenderMap(void);
A_EXTERN_C void R_UnloadMap(void);
A_EXTERN_C void R_ShutdownMap(void);
