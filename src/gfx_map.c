#include "gfx_map.h"

#include <assert.h>

#include "acommon/a_string.h"
#include "acommon/z_mem.h"

#include "cl_client.h"
#include "cl_map.h"
#include "com_print.h"
#include "db_files.h"
#include "dvar.h"
#include "gfx.h"
#include "gfx_defs.h"
#include "gfx_shader.h"
#include "gfx_uniform.h"

extern dvar_t* r_wireframe;

MapRenderGlob r_mapGlob;

static ImageFormat R_BSPGetImageFormat(BSPBitmapDataFormat format) {
    ImageFormat img_format;
    switch (format) {
    case BSP_BITMAP_DATA_FORMAT_A8:
        img_format = R_IMAGE_FORMAT_A8;
        break;
    case BSP_BITMAP_DATA_FORMAT_R5G6B5:
        img_format = R_IMAGE_FORMAT_RGB565;
        break;
    case BSP_BITMAP_DATA_FORMAT_DXT1:
        img_format = R_IMAGE_FORMAT_DXT1;
        break;
    case BSP_BITMAP_DATA_FORMAT_DXT3:
        img_format = R_IMAGE_FORMAT_DXT3;
        break;
    case BSP_BITMAP_DATA_FORMAT_DXT5:
        img_format = R_IMAGE_FORMAT_DXT5;
        break;
    default:
        Com_Errorln(-1,
            "R_BSPGetImageFormat: Unimplemented BSPBitmapDataFormat %d.",
            (int)format
        );
    };

    return img_format;
}

//static ImageType R_BSPGetImageType(BSPBitmapDataType type) {
//    ImageType img_type;
//    switch (type) {
//    case BSP_BITMAP_DATA_TYPE_2D_TEXTURE:
//        img_type = R_IMAGE_TYPE_2D_TEXTURE;
//        break;
//    case BSP_BITMAP_DATA_TYPE_3D_TEXTURE:
//        img_type = R_IMAGE_TYPE_3D_TEXTURE;
//        break;
//    case BSP_BITMAP_DATA_TYPE_CUBE_MAP:
//        img_type = R_IMAGE_TYPE_CUBE_MAP;
//        break;
//    default:
//        Com_Errorln(-1,
//            "R_BSPGetImageType: Unimplemented BSPBitmapDataType %d.",
//            (int)type
//        );
//    }
//
//    return img_type;
//}

A_NO_DISCARD bool R_CreateBSPImage(
    const void* pixels, size_t pixels_size, int width, int height, int depth,
    BSPBitmapDataType type, BSPBitmapDataFormat bsp_format,
    A_OUT GfxImage* image
) {
    if (type == BSP_BITMAP_DATA_TYPE_2D_TEXTURE)
        assert(depth == 1);

    assert(type == BSP_BITMAP_DATA_TYPE_2D_TEXTURE ||
        type == BSP_BITMAP_DATA_TYPE_3D_TEXTURE);

    ImageFormat format = R_BSPGetImageFormat(bsp_format);

    if (type == BSP_BITMAP_DATA_TYPE_2D_TEXTURE) {
        return R_CreateImage2D(pixels, pixels_size, width, height, depth,
            format, true, true, true,
            R_IMAGE_FILTER_LINEAR,
            R_IMAGE_FILTER_LINEAR,
            image);
    }
    else {
        return false;
    }
}

void R_InitMap(void) {
    char* vertSource  = DB_LoadShader("bsp.vs");
    char* pixelSource = DB_LoadShader("bsp.ps");

    bool b = R_CreateShaderProgram(vertSource, pixelSource, &r_mapGlob.prog);
    GfxShaderUniformDef uniform;

    R_CreateUniformMat4f("uModel", A_MAT4F_IDENTITY, &uniform);
    GfxShaderUniformDef* pUniform = R_ShaderAddUniform(&r_mapGlob.prog, &uniform);
    assert(pUniform);

    R_CreateUniformMat4f("uView", A_MAT4F_IDENTITY, &uniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.prog, &uniform);
    assert(pUniform);

    R_CreateUniformMat4f("uPerspectiveProjection", A_MAT4F_IDENTITY, &uniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.prog, &uniform);
    assert(pUniform);

    R_CreateUniformBool("uAlphaTested", false, &uniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.prog, &uniform);
    assert(pUniform);

    R_CreateUniformInt("uFlags", 0, &uniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.prog, &uniform);
    assert(pUniform);

    R_CreateUniformInt("uMap", 0, &uniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.prog, &uniform);
    assert(pUniform);

    R_CreateUniformInt("uBaseMap", 0, &uniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.prog, &uniform);
    assert(pUniform);

    R_CreateUniformInt("uPrimaryDetailMap", 0, &uniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.prog, &uniform);
    assert(pUniform);
    
    R_CreateUniformInt("uSecondaryDetailMap", 0, &uniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.prog, &uniform);
    assert(pUniform);

    R_CreateUniformInt("uMicroDetailMap", 0, &uniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.prog, &uniform);
    assert(pUniform);

    R_CreateUniformInt("uBumpMap", 0, &uniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.prog, &uniform);
    assert(pUniform);

    R_CreateUniformInt("uDetailMapFunction", 0, &uniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.prog, &uniform);
    assert(pUniform);

    R_CreateUniformInt("uMicroDetailMapFunction", 0, &uniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.prog, &uniform);
    assert(pUniform);

    R_CreateUniformVec3f("uMaterialColor", A_VEC3F_ZERO, &uniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.prog, &uniform);
    assert(pUniform);

    R_CreateUniformVec3f("uAmbientColor", A_VEC3F_ZERO, &uniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.prog, &uniform);
    assert(pUniform);

    R_CreateUniformVec3f("uDistantLight0Dir", A_VEC3F_ZERO, &uniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.prog, &uniform);
    assert(pUniform);

    R_CreateUniformVec3f("uDistantLight1Dir", A_VEC3F_ZERO, &uniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.prog, &uniform);
    assert(pUniform);

    R_CreateUniformVec3f("uDistantLight0Color", A_VEC3F_ZERO, &uniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.prog, &uniform);
    assert(pUniform);

    R_CreateUniformVec3f("uDistantLight1Color", A_VEC3F_ZERO, &uniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.prog, &uniform);
    assert(pUniform);

    assert(b);
    DB_UnloadShader(vertSource);
    DB_UnloadShader(pixelSource);
}

static void R_SwapYZPoint3(A_INOUT apoint3f_t* p) {
    float tmp = p->y;
    p->y = p->z;
    p->z = tmp;
}

static void R_SwapYZVec3(A_INOUT avec3f_t* p) {
    float tmp = p->y;
    p->y = p->z;
    p->z = tmp;
}

static void R_SwapRenderedVertexYZ(A_INOUT BSPRenderedVertex* v) {
    R_SwapYZPoint3(&v->pos);
    R_SwapYZVec3(&v->normal);
    R_SwapYZVec3(&v->binormal);
    R_SwapYZVec3(&v->tangent);
}

static void R_SwapLightmapVertexYZ(A_INOUT BSPLightmapVertex* v) {
    R_SwapYZVec3(&v->normal);
}

static bool R_LoadBitmap(TagId tag_id, A_OUT GfxImage* image) {
    assert(image);
    if (!image)
        return false;
    A_memset(image, 0, sizeof(*image));

    Tag* tag = CL_Map_Tag(tag_id);
    assert(tag);
    if (!tag)
        return false;
    assert(tag->primary_class == TAG_FOURCC_BITMAP);
    if (tag->primary_class != TAG_FOURCC_BITMAP)
        return false;
    BSPBitmap* bitmap = (BSPBitmap*)tag->tag_data;
    assert(bitmap);
    if (!bitmap)
        return false;
    BSPBitmapData* bitmap_data = (BSPBitmapData*)bitmap->bitmap_data.pointer;
    if (!bitmap_data)
        return false;
    if (bitmap_data->pixels != (void*)0xFFFFFFFF &&
        (bitmap_data->type == BSP_BITMAP_DATA_TYPE_2D_TEXTURE ||
            bitmap_data->type == BSP_BITMAP_DATA_TYPE_3D_TEXTURE)
        ) {
        bool b = R_CreateBSPImage(
            bitmap_data->pixels,
            bitmap_data->actual_size,
            bitmap_data->width,
            bitmap_data->height,
            bitmap_data->depth,
            bitmap_data->type,
            bitmap_data->format,
            image
        );
        if (bitmap_data->type == BSP_BITMAP_DATA_TYPE_2D_TEXTURE)
            assert(b);
        (void)b;
    }
    return true;
}

static void R_LoadMaterial(const BSPMaterial* bsp_material, 
                           A_OUT GfxMaterial* material
) {
    uint32_t start_surf = bsp_material->surfaces;
    uint32_t surf_count = bsp_material->surface_count;
    assert(surf_count > 0);
    assert(bsp_material->rendered_vertices_count > 0);
    if (bsp_material->lightmap_vertices_count > 0) {
        assert(bsp_material->lightmap_vertices_count == 
               bsp_material->rendered_vertices_count);
    }
    BSPRenderedVertex* rendered_vertices = 
        Z_Alloc(3 * surf_count * sizeof(BSPRenderedVertex));
    BSPLightmapVertex* lightmap_vertices = bsp_material->lightmap_vertices_count > 0 ?
        Z_Alloc(3 * surf_count * sizeof(BSPLightmapVertex)) : NULL;
    const BSPRenderedVertex* bsp_rendered_vertices =
        bsp_material->uncompressed_vertices.pointer;
    const BSPLightmapVertex* bsp_lightmap_vertices =
        (BSPLightmapVertex*)
            (bsp_rendered_vertices + bsp_material->rendered_vertices_count);

    const BSPSurf* bsp_surfs = &CL_Map_Surfs()[start_surf];
    for (uint32_t k = 0; k < surf_count; k++) {
        const BSPSurf* bsp_surf = &bsp_surfs[k];
        for (int l = 0; l < 3; l++) {
            uint16_t bsp_vert = bsp_surf->verts[l];
            BSPRenderedVertex* rendered_vertex = &rendered_vertices[k * 3 + l];
            const BSPRenderedVertex* bsp_rendered_vertex = &bsp_rendered_vertices[bsp_vert];
            *rendered_vertex = *bsp_rendered_vertex;
            R_SwapRenderedVertexYZ(rendered_vertex);
        }
    }
    if (bsp_material->lightmap_vertices_count > 0) {
        for (uint32_t k = 0; k < surf_count; k++) {
            const BSPSurf* bsp_surf = &bsp_surfs[k];
            for (int l = 0; l < 3; l++) {
                uint16_t bsp_vert = bsp_surf->verts[l];
                BSPLightmapVertex* lightmap_vertex = &lightmap_vertices[k * 3 + l];
                const BSPLightmapVertex* bsp_lightmap_vertex = &bsp_lightmap_vertices[bsp_vert];
                *lightmap_vertex = *bsp_lightmap_vertex;
                R_SwapLightmapVertexYZ(lightmap_vertex);
            }
        }
    }
    
    material->vertices_count = surf_count * 3;

    material->color = bsp_material->ambient_color;
    material->ambient_color = bsp_material->ambient_color;

    material->distant_light_0_dir = bsp_material->distant_light_0_direction;
    material->distant_light_1_dir = bsp_material->distant_light_1_direction;
    material->distant_light_0_color = bsp_material->distant_light_0_color;
    material->distant_light_1_color = bsp_material->distant_light_1_color;

    Tag* shader_tag = CL_Map_Tag(bsp_material->shader.id);
    assert(shader_tag);
    assert(shader_tag->secondary_class == TAG_FOURCC_SHADER);
    if (shader_tag->primary_class == TAG_FOURCC_SHADER_ENVIRONMENT) {
        BSPShaderEnvironment* shader =
            (BSPShaderEnvironment*)shader_tag->tag_data;
        assert(shader);
        material->alpha_tested = shader->flags & 0x01;

        bool b = true;
        assert(shader->map.fourcc == TAG_FOURCC_BITMAP);
        if (shader->map.id.index != 0xFFFF) {
            GfxImage map;
            b = R_LoadBitmap(shader->map.id, &map);
            if (R_AddImageToMaterialPass(&material->pass, &map) == NULL)
                b = false;
        }
        
        assert(b);
        assert(shader->base_map.fourcc == TAG_FOURCC_BITMAP);
        if (shader->base_map.id.index != 0xFFFF) {
            GfxImage base_map;
            b = R_LoadBitmap(shader->base_map.id, &base_map);
            if (R_AddImageToMaterialPass(&material->pass, &base_map) == NULL)
                b = false;
        }
     
        assert(b);
        assert(shader->primary_detail_map.fourcc == TAG_FOURCC_BITMAP);
        if (shader->primary_detail_map.id.index != 0xFFFF) {
            GfxImage primary_detail_map;
            b = R_LoadBitmap(shader->primary_detail_map.id, &primary_detail_map);
            if (R_AddImageToMaterialPass(&material->pass, &primary_detail_map) == NULL)
                b = false;
        }
        assert(b);
        assert(shader->secondary_detail_map.fourcc == TAG_FOURCC_BITMAP);
        if (shader->secondary_detail_map.id.index != 0xFFFF) {
            GfxImage secondary_detail_map;
            b = R_LoadBitmap(shader->secondary_detail_map.id, &secondary_detail_map);
            if (R_AddImageToMaterialPass(&material->pass, &secondary_detail_map) == NULL)
                b = false;
        }
        assert(b);
        assert(shader->micro_detail_map.fourcc == TAG_FOURCC_BITMAP);
        if (shader->micro_detail_map.id.index != 0xFFFF) {
            GfxImage micro_detail_map;
            b = R_LoadBitmap(shader->micro_detail_map.id, &micro_detail_map);
            if (R_AddImageToMaterialPass(&material->pass, &micro_detail_map) == NULL)
                b = false;
        }
        assert(b);
        assert(shader->bump_map.fourcc == TAG_FOURCC_BITMAP);
        if (shader->bump_map.id.index != 0xFFFF) {
            GfxImage bump_map;
            b = R_LoadBitmap(shader->bump_map.id, &bump_map);
            if (R_AddImageToMaterialPass(&material->pass, &bump_map) == NULL)
                b = false;
        }
       
        assert(b);
        material->detail_map_function = 
            shader->detail_map_function;
        material->micro_detail_map_function = 
            shader->micro_detail_map_function;
        (void)b;
    } else {
        const char* shader_path = (const char*)shader_tag->tag_path;
        Com_DPrintln(CON_DEST_CLIENT,
            "R_LoadMap: Cannot create shader %s: shader type 0x%08X unsupported.",
            shader_path, (uint32_t)shader_tag->primary_class
        );
    }

    size_t rendered_vertices_size =
        material->vertices_count * sizeof(BSPRenderedVertex);
    size_t lightmap_vertices_size = bsp_material->lightmap_vertices_count > 0 ?
        material->vertices_count * sizeof(BSPLightmapVertex) : 0;
    size_t vertices_size = rendered_vertices_size + lightmap_vertices_size;

    GfxVertexBuffer vb;
    bool b = R_CreateVertexBuffer(rendered_vertices,
                                  rendered_vertices_size,
                                  vertices_size, 0,
                                  sizeof(BSPRenderedVertex),      
                                  &vb);
    assert(b);
    GfxVertexBuffer* pVb = R_AddVertexBufferToMaterialPass(&material->pass, 
                                                           &vb);
    assert(pVb);
#if A_RENDER_BACKEND_GL
    if (bsp_material->lightmap_vertices_count > 0) {
        R_AppendVertexData(&material->pass.vbs[0],
                           lightmap_vertices, lightmap_vertices_size);
    }
    GL_CALL(glBindVertexArray, material->pass.vbs[0].vao);
    GL_CALL(glVertexAttribPointer,
        0, 3, GL_FLOAT, GL_FALSE, sizeof(BSPRenderedVertex),
        (const void*)offsetof(BSPRenderedVertex, pos)
    );
    GL_CALL(glVertexAttribPointer,
        1, 3, GL_FLOAT, GL_FALSE, sizeof(BSPRenderedVertex),
        (const void*)offsetof(BSPRenderedVertex, normal)
    );
    GL_CALL(glVertexAttribPointer,
        2, 3, GL_FLOAT, GL_FALSE, sizeof(BSPRenderedVertex),
        (const void*)offsetof(BSPRenderedVertex, binormal)
    );
    GL_CALL(glVertexAttribPointer,
        3, 3, GL_FLOAT, GL_FALSE, sizeof(BSPRenderedVertex),
        (const void*)offsetof(BSPRenderedVertex, tangent)
    );
    GL_CALL(glVertexAttribPointer,
        4, 2, GL_FLOAT, GL_FALSE, sizeof(BSPRenderedVertex),
        (const void*)offsetof(BSPRenderedVertex, tex_coords)
    );
    GL_CALL(glVertexAttribPointer,
        5, 3, GL_FLOAT, GL_FALSE, sizeof(BSPLightmapVertex),
        (const void*)(rendered_vertices_size +
            offsetof(BSPLightmapVertex, normal))
    );
    GL_CALL(glVertexAttribPointer,
        6, 2, GL_FLOAT, GL_FALSE, sizeof(BSPLightmapVertex),
        (const void*)(rendered_vertices_size +
            offsetof(BSPLightmapVertex, tex_coords))
    );

    GL_CALL(glEnableVertexAttribArray, 0);
    GL_CALL(glEnableVertexAttribArray, 1);
    GL_CALL(glEnableVertexAttribArray, 2);
    GL_CALL(glEnableVertexAttribArray, 3);
    GL_CALL(glEnableVertexAttribArray, 4);
    GL_CALL(glEnableVertexAttribArray, 5);
    GL_CALL(glEnableVertexAttribArray, 6);
#elif A_RENDER_BACKEND_D3D9 
    b = R_CreateVertexBuffer(lightmap_vertices,
                             lightmap_vertices_size,
                             lightmap_vertices_size, 0,
                             sizeof(BSPLightmapVertex),  
                             &vb);
    assert(b);
    pVb = R_AddVertexBufferToMaterialPass(&material->pass, &vb);
    assert(pVb);
    D3DVERTEXELEMENT9 vertex_elements[] = {
        {
            .Stream     = 0,
            .Offset     = offsetof(BSPRenderedVertex, pos),
            .Type       = D3DDECLTYPE_FLOAT3,
            .Method     = D3DDECLMETHOD_DEFAULT,
            .Usage      = D3DDECLUSAGE_POSITION,
            .UsageIndex = 0
        },
        {
            .Stream     = 0,
            .Offset     = offsetof(BSPRenderedVertex, normal),
            .Type       = D3DDECLTYPE_FLOAT3,
            .Method     = D3DDECLMETHOD_DEFAULT,
            .Usage      = D3DDECLUSAGE_NORMAL,
            .UsageIndex = 0
        },
        {
            .Stream     = 0,
            .Offset     = offsetof(BSPRenderedVertex, binormal),
            .Type       = D3DDECLTYPE_FLOAT3,
            .Method     = D3DDECLMETHOD_DEFAULT,
            .Usage      = D3DDECLUSAGE_BINORMAL,
            .UsageIndex = 0
        },
        {
            .Stream     = 0,
            .Offset     = offsetof(BSPRenderedVertex, tangent),
            .Type       = D3DDECLTYPE_FLOAT3,
            .Method     = D3DDECLMETHOD_DEFAULT,
            .Usage      = D3DDECLUSAGE_TANGENT,
            .UsageIndex = 0
        },
        {
            .Stream     = 0,
            .Offset     = offsetof(BSPRenderedVertex, tex_coords),
            .Type       = D3DDECLTYPE_FLOAT2,
            .Method     = D3DDECLMETHOD_DEFAULT,
            .Usage      = D3DDECLUSAGE_TEXCOORD,
            .UsageIndex = 0
        },
        {
            .Stream     = 1,
            .Offset     = offsetof(BSPLightmapVertex, normal),
            .Type       = D3DDECLTYPE_FLOAT3,
            .Method     = D3DDECLMETHOD_DEFAULT,
            .Usage      = D3DDECLUSAGE_NORMAL,
            .UsageIndex = 1
        },
        {
            .Stream     = 1,
            .Offset     = offsetof(BSPLightmapVertex, tex_coords),
            .Type       = D3DDECLTYPE_FLOAT2,
            .Method     = D3DDECLMETHOD_DEFAULT,
            .Usage      = D3DDECLUSAGE_NORMAL,
            .UsageIndex = 1
        },
        D3DDECL_END()
    };
    IDirect3DVertexDeclaration9* decl = NULL;
    D3D_CALL(r_d3d9Glob.d3ddev, CreateVertexDeclaration, vertex_elements, 
                                                         &decl);
    assert(decl);
    material->pass.decl = decl;
#endif // A_RENDER_BACKEND_GL
    Z_Free(rendered_vertices);
    Z_Free(lightmap_vertices);
}

static void R_LoadLightmap(const BSPLightmap* bsp_lightmap, GfxLightmap* lightmap) {
    lightmap->materials = Z_Zalloc(
        bsp_lightmap->materials.count *
        sizeof(*lightmap->materials)
    );
    lightmap->material_count = bsp_lightmap->materials.count;
    const BSPMaterial* bsp_materials =
        (const BSPMaterial*)bsp_lightmap->materials.pointer;
    for (uint32_t j = 0; j < bsp_lightmap->materials.count; j++) {
        const BSPMaterial* bsp_material = &bsp_materials[j];
        GfxMaterial* material = &lightmap->materials[j];
        R_LoadMaterial(bsp_material, material);
    }
}

void R_LoadMap(void) {
    r_mapGlob.lightmap_count = CL_Map_LightmapCount();
    r_mapGlob.lightmaps = Z_Zalloc(
        r_mapGlob.lightmap_count * sizeof(*r_mapGlob.lightmaps)
    );
    for (uint32_t i = 0; i < r_mapGlob.lightmap_count; i++) {
        const BSPLightmap* bsp_lightmap = CL_Map_Lightmap(i);
        GfxLightmap* lightmap = &r_mapGlob.lightmaps[i];
        R_LoadLightmap(bsp_lightmap, lightmap);
    }
}

static void R_RenderMaterial(GfxMaterial* material) {
    bool b = R_BindShaderProgram(&r_mapGlob.prog);
    assert(b);
    if (!b)
        return;

    R_ShaderSetUniformBoolByName(&r_mapGlob.prog, "uAlphaTested",
                                 material->alpha_tested);

    R_ShaderSetUniformIntByName(&r_mapGlob.prog, "uDetailMapFunction",
                               (int)material->detail_map_function);
    R_ShaderSetUniformIntByName(&r_mapGlob.prog, "uMicroDetailMapFunction",
                               (int)material->micro_detail_map_function);

    avec3f_t color = A_vec3(
        material->color.r,
        material->color.g,
        material->color.b
    );
    R_ShaderSetUniformVec3fByName(&r_mapGlob.prog, "uMaterialColor", color);

    color.x = material->ambient_color.r;
    color.y = material->ambient_color.g;
    color.z = material->ambient_color.b;
    R_ShaderSetUniformVec3fByName(&r_mapGlob.prog, "uAmbientColor", color);

    R_ShaderSetUniformVec3fByName(
        &r_mapGlob.prog, "uDistantLight0Dir",
        material->distant_light_0_dir);
    R_ShaderSetUniformVec3fByName(
        &r_mapGlob.prog, "uDistantLight1Dir",
        material->distant_light_1_dir);

    color.x =
        material->distant_light_0_color.r;
    color.y =
        material->distant_light_0_color.g;
    color.z =
        material->distant_light_0_color.b;
    R_ShaderSetUniformVec3fByName(&r_mapGlob.prog,
        "uDistantLight0Color", color);

    color.x =
        material->distant_light_1_color.r;
    color.y =
        material->distant_light_1_color.g;
    color.z =
        material->distant_light_1_color.b;
    R_ShaderSetUniformVec3fByName(&r_mapGlob.prog,
        "uDistantLight1Color", color);

    bool has_map                  = material->pass.images[0].tex != 0;
    bool has_base_map             = material->pass.images[1].tex != 0;
    bool has_primary_detail_map   = material->pass.images[2].tex != 0;
    bool has_secondary_detail_map = material->pass.images[3].tex != 0;
    bool has_bump_map             = material->pass.images[4].tex != 0;
    bool has_micro_detail_map     = material->pass.images[5].tex != 0;
    bool wireframe = Dvar_GetBool(r_wireframe);
    int flags = wireframe | has_map << 1 | has_base_map << 2 |
        has_primary_detail_map << 3 | has_secondary_detail_map << 4 |
        has_micro_detail_map << 5 | has_bump_map << 6;

    R_ShaderSetUniformIntByName(&r_mapGlob.prog, "uFlags", flags & 0x7E);
    size_t vertices_count =
        material->vertices_count;
    R_RenderMaterialPass(&material->pass, vertices_count, 0, R_POLYGON_MODE_FILL);
    if (Dvar_GetBool(r_wireframe)) {
        R_ShaderSetUniformIntByName(&r_mapGlob.prog, "uFlags", flags & 0x7F);
        R_RenderMaterialPass(&material->pass, vertices_count, 0, R_POLYGON_MODE_LINE);
    }
}

static void R_RenderMapInternal(void) {
    R_EnableDepthTest();
    R_EnableBackFaceCulling();
    R_ShaderSetUniformIntByName(&r_mapGlob.prog, "uMap", 0);
    R_ShaderSetUniformIntByName(&r_mapGlob.prog, "uBaseMap", 1);
    R_ShaderSetUniformIntByName(&r_mapGlob.prog, "uPrimaryDetailMap", 2);
    R_ShaderSetUniformIntByName(&r_mapGlob.prog, "uSecondaryDetailMap", 3);
    R_ShaderSetUniformIntByName(&r_mapGlob.prog, "uMicroDetailMap", 4);
    R_ShaderSetUniformIntByName(&r_mapGlob.prog, "uBumpMap", 5);

    amat4f_t model = A_MAT4F_IDENTITY;
    R_ShaderSetUniformMat4fByName(&r_mapGlob.prog, "uModel", model);
    for (uint32_t i = 0; i < r_mapGlob.lightmap_count; i++) {
        GfxLightmap* lightmap = &r_mapGlob.lightmaps[i];
        for (uint32_t j = 0; j < lightmap->material_count; j++) {
            GfxMaterial* material = &lightmap->materials[j];
            R_RenderMaterial(material);
        }
    }
    R_DisableBackFaceCulling();
    R_DisableDepthTest();
}

void R_RenderMap(void) {
    if (!CL_IsMapLoaded())
        return;

    R_RenderMapInternal();
}

void R_UnloadMaterial(A_IN GfxMaterial* material) {
    R_DeleteMaterialPass(&material->pass);
    A_memset(material, 0, sizeof(*material));
}

void R_UnloadLightmap(A_IN GfxLightmap* lightmap) {
    for (uint32_t i = 0; i < lightmap->material_count; i++) {
        GfxMaterial* material = &lightmap->materials[i];
        R_UnloadMaterial(material);
    }
    Z_Free(lightmap->materials);
}

void R_UnloadMap(void) {
    for (uint32_t i = 0; i < r_mapGlob.lightmap_count; i++)
        R_UnloadLightmap(&r_mapGlob.lightmaps[i]);
    
    Z_Free(r_mapGlob.lightmaps);
}

void R_ShutdownMap(void) {
    if (CL_IsMapLoaded())
        R_UnloadMap();

    R_DeleteShaderProgram(&r_mapGlob.prog);
}
