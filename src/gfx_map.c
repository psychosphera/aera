#include "gfx_map.h"

#include <assert.h>

#if A_RENDER_BACKEND_GL
#include <cglm/cglm.h>
#endif // A_RENDER_BACKEND_GL

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
    case BSP_BITMAP_DATA_FORMAT_P8_BUMP:
        img_format = R_IMAGE_FORMAT_A8;
        break;
    default:
        assert(false && "R_BSPGetImageFormat: Unimplemented BSPBitmapDataFormat");
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
    assert(b);
    DB_UnloadShader(vertSource);
    DB_UnloadShader(pixelSource);

    vertSource  = DB_LoadShader("model.vs");
    pixelSource = DB_LoadShader("model.ps");
    b = R_CreateShaderProgram(vertSource, pixelSource, &r_mapGlob.model_prog);
    DB_UnloadShader(vertSource);
    DB_UnloadShader(pixelSource);

#if !A_TARGET_PLATFORM_IS_XBOX
    GfxShaderUniformDef uniform;

    R_CreateUniformMat4f("uModel", A_MAT4F_IDENTITY, &uniform);
    GfxShaderUniformDef* pUniform = R_ShaderAddUniform(&r_mapGlob.prog, 
                                                      SHADER_TYPE_VERTEX, 
                                                      &uniform);
    assert(pUniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.model_prog, SHADER_TYPE_VERTEX, &uniform);
    assert(pUniform);

    R_CreateUniformMat4f("uView", A_MAT4F_IDENTITY, &uniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.prog, 
                                  SHADER_TYPE_VERTEX, 
                                  &uniform);
    assert(pUniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.model_prog, SHADER_TYPE_VERTEX, &uniform);
    assert(pUniform);

    R_CreateUniformMat4f("uPerspectiveProjection", A_MAT4F_IDENTITY, &uniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.prog, 
                                  SHADER_TYPE_VERTEX, 
                                  &uniform);
    assert(pUniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.model_prog, SHADER_TYPE_VERTEX, &uniform);
    assert(pUniform);

    //R_CreateUniformBool("uAlphaTested", false, &uniform);
    //pUniform = R_ShaderAddUniform(&r_mapGlob.prog, 
    //                              SHADER_TYPE_PIXEL, 
    //                              &uniform);
    //assert(pUniform);

    R_CreateUniformBool("uWireframe", 0, &uniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.prog, 
                                  SHADER_TYPE_PIXEL, 
                                  &uniform);
    assert(pUniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.model_prog, SHADER_TYPE_PIXEL, &uniform);
    assert(pUniform);

    //R_CreateUniformInt("uMap", 0, &uniform);
    //pUniform = R_ShaderAddUniform(&r_mapGlob.prog, 
    //                              SHADER_TYPE_PIXEL, 
    //                              &uniform);
    //assert(pUniform);

    R_CreateUniformInt("uBaseMap", 0, &uniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.prog, 
                                  SHADER_TYPE_PIXEL, 
                                  &uniform);
    assert(pUniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.model_prog, SHADER_TYPE_PIXEL, &uniform);
    assert(pUniform);

    //R_CreateUniformInt("uPrimaryDetailMap", 0, &uniform);
    //pUniform = R_ShaderAddUniform(&r_mapGlob.prog, 
    //                              SHADER_TYPE_PIXEL, 
    //                              &uniform);
    //assert(pUniform);
    //
    //R_CreateUniformInt("uSecondaryDetailMap", 0, &uniform);
    //pUniform = R_ShaderAddUniform(&r_mapGlob.prog, 
    //                              SHADER_TYPE_PIXEL, 
    //                              &uniform);
    //assert(pUniform);

    //R_CreateUniformInt("uMicroDetailMap", 0, &uniform);
    //pUniform = R_ShaderAddUniform(&r_mapGlob.prog, 
    //                              SHADER_TYPE_PIXEL, 
    //                              &uniform);
    //assert(pUniform);

    //R_CreateUniformInt("uBumpMap", 0, &uniform);
    //pUniform = R_ShaderAddUniform(&r_mapGlob.prog, 
    //                              SHADER_TYPE_PIXEL, 
    //                              &uniform);
    //assert(pUniform);

    //R_CreateUniformInt("uDetailMapFunction", 0, &uniform);
    //pUniform = R_ShaderAddUniform(&r_mapGlob.prog, 
    //                              SHADER_TYPE_PIXEL, 
    //                              &uniform);
    //assert(pUniform);

    //R_CreateUniformInt("uMicroDetailMapFunction", 0, &uniform);
    //pUniform = R_ShaderAddUniform(&r_mapGlob.prog, 
    //                              SHADER_TYPE_PIXEL, 
    //                              &uniform);
    //assert(pUniform);

    R_CreateUniformVec4f("uAmbientColor", A_VEC4F_ZERO, &uniform);
    pUniform = R_ShaderAddUniform(&r_mapGlob.prog, 
                                  SHADER_TYPE_PIXEL, 
                                  &uniform);
    assert(pUniform);

    //R_CreateUniformVec3f("uDistantLight0Dir", A_VEC3F_ZERO, &uniform);
    //pUniform = R_ShaderAddUniform(&r_mapGlob.prog, 
    //                              SHADER_TYPE_PIXEL, 
    //                              &uniform);
    //assert(pUniform);

    //R_CreateUniformVec3f("uDistantLight1Dir", A_VEC3F_ZERO, &uniform);
    //pUniform = R_ShaderAddUniform(&r_mapGlob.prog, 
    //                              SHADER_TYPE_PIXEL,
    //                              &uniform);
    //assert(pUniform);

    //R_CreateUniformVec3f("uDistantLight0Color", A_VEC3F_ZERO, &uniform);
    //pUniform = R_ShaderAddUniform(&r_mapGlob.prog, 
    //                              SHADER_TYPE_PIXEL, 
    //                              &uniform);
    //assert(pUniform);

    //R_CreateUniformVec3f("uDistantLight1Color", A_VEC3F_ZERO, &uniform);
    //pUniform = R_ShaderAddUniform(&r_mapGlob.prog, 
    //                              SHADER_TYPE_PIXEL, 
    //                              &uniform);
    //assert(pUniform);

    assert(b);
#else
	assert(false && "unimplemented"); // FIXME
#endif // !A_TARGET_PLATFORM_IS_XBOX
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
            (BSPBitmapDataType)bitmap_data->type,
            (BSPBitmapDataFormat)bitmap_data->format,
            image
        );
        if (bitmap_data->type == BSP_BITMAP_DATA_TYPE_2D_TEXTURE)
            assert(b);
        (void)b;
    }
    return true;
}

static void R_LoadShaderEnvironment(BSPShaderEnvironment* bsp_shader, 
                                    A_OUT GfxShaderEnvironment* shader) {
    bool b = true;
    assert(bsp_shader->base_map.fourcc == TAG_FOURCC_BITMAP);
    if (bsp_shader->base_map.id.index != 0xFFFF) {
        b = R_LoadBitmap(bsp_shader->base_map.id, &shader->base_map);
    }

    assert(b);
    assert(bsp_shader->primary_detail_map.fourcc == TAG_FOURCC_BITMAP);
    if (bsp_shader->primary_detail_map.id.index != 0xFFFF) {
        b = R_LoadBitmap(bsp_shader->primary_detail_map.id, &shader->primary_detail_map);
    }
    assert(b);
    assert(bsp_shader->secondary_detail_map.fourcc == TAG_FOURCC_BITMAP);
    if (bsp_shader->secondary_detail_map.id.index != 0xFFFF) {
        b = R_LoadBitmap(bsp_shader->secondary_detail_map.id, &shader->secondary_detail_map);
    }
    assert(b);
    assert(bsp_shader->micro_detail_map.fourcc == TAG_FOURCC_BITMAP);
    if (bsp_shader->micro_detail_map.id.index != 0xFFFF) {
        b = R_LoadBitmap(bsp_shader->micro_detail_map.id, &shader->micro_detail_map);
    }
    assert(b);
    assert(bsp_shader->bump_map.fourcc == TAG_FOURCC_BITMAP);
    if (bsp_shader->bump_map.id.index != 0xFFFF) {
        b = R_LoadBitmap(bsp_shader->bump_map.id, &shader->bump_map);
    }

    assert(bsp_shader->map.fourcc == TAG_FOURCC_BITMAP);
    if (bsp_shader->map.id.index != 0xFFFF) {
        b = R_LoadBitmap(bsp_shader->map.id, &shader->map);
    }

    assert(b);
    shader->detail_map_function =
        shader->detail_map_function;
    shader->micro_detail_map_function =
        shader->micro_detail_map_function;
    (void)b;
}

static void R_LoadShaderModel(BSPShaderModel* bsp_shader,
                              A_OUT GfxShaderModel* shader
) {

    bool b = true;
    assert(bsp_shader->base_map.fourcc == TAG_FOURCC_BITMAP);
    if (bsp_shader->base_map.id.index != 0xFFFF) {
        b = R_LoadBitmap(bsp_shader->base_map.id, &shader->base_map);
    }

    assert(b);
    assert(bsp_shader->detail_map.fourcc == TAG_FOURCC_BITMAP);
    if (bsp_shader->detail_map.id.index != 0xFFFF) {
        b = R_LoadBitmap(bsp_shader->detail_map.id, &shader->detail_map);
    }
    assert(b);
    assert(bsp_shader->multipurpose_map.fourcc == TAG_FOURCC_BITMAP);
    if (bsp_shader->multipurpose_map.id.index != 0xFFFF) {
        b = R_LoadBitmap(bsp_shader->multipurpose_map.id, &shader->multipurpose_map);
    }
    assert(b);
    (void)b;
    shader->detail_function = (BSPShaderDetailFunction)bsp_shader->detail_function;
}

static void R_LoadShader(TagId shader_id, GfxShader* shader) {
    Tag* shader_tag = CL_Map_Tag(shader_id);
    assert(shader_tag);
    assert(shader_tag->secondary_class == TAG_FOURCC_SHADER);
    if (shader_tag->primary_class == TAG_FOURCC_SHADER_ENVIRONMENT) {
        BSPShaderEnvironment* shader_environment =
            (BSPShaderEnvironment*)shader_tag->tag_data;
        assert(shader);
        shader->type = SHADER_TYPE_ENVIRONMENT;
        R_LoadShaderEnvironment(shader_environment, &shader->environment);
    }
    else if (shader_tag->primary_class == TAG_FOURCC_SHADER_MODEL) {
        BSPShaderModel* shader_model =
            (BSPShaderModel*)shader_tag->tag_data;
        assert(shader);
        shader->type = SHADER_TYPE_MODEL;
        R_LoadShaderModel(shader_model, &shader->model);
    }
    else {
        const char* shader_path = (const char*)shader_tag->tag_path;
        Com_DPrintln(CON_DEST_CLIENT,
            "R_LoadMap: Cannot create shader %s: shader type 0x%08X unsupported.",
            shader_path, (uint32_t)shader_tag->primary_class
        );
    }
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
        (BSPRenderedVertex*)Z_Alloc(3 * surf_count * sizeof(BSPRenderedVertex));
    BSPLightmapVertex* lightmap_vertices = bsp_material->lightmap_vertices_count > 0 ?
        (BSPLightmapVertex*)Z_Alloc(3 * surf_count * sizeof(BSPLightmapVertex)) : NULL;
    const BSPRenderedVertex* bsp_rendered_vertices =
        (const BSPRenderedVertex*)bsp_material->uncompressed_vertices.pointer;
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
    
    size_t vertices_count = surf_count * 3;

    material->ambient_color = bsp_material->ambient_color;

    material->distant_light_0_dir = bsp_material->distant_light_0_direction;
    material->distant_light_1_dir = bsp_material->distant_light_1_direction;
    material->distant_light_0_color = bsp_material->distant_light_0_color;
    material->distant_light_1_color = bsp_material->distant_light_1_color;

    R_LoadShader(bsp_material->shader.id, &material->shader);

    size_t rendered_vertices_size = vertices_count * sizeof(BSPRenderedVertex);
    size_t lightmap_vertices_size = bsp_material->lightmap_vertices_count > 0 ? 
        vertices_count * sizeof(BSPLightmapVertex) : 0;
    size_t vertices_size = rendered_vertices_size + lightmap_vertices_size;

    GfxVertexBuffer vb;
    bool b = R_CreateVertexBuffer(rendered_vertices,
                                  rendered_vertices_size,
                                  vertices_size, 0,
                                  sizeof(BSPRenderedVertex),      
                                  &vb);
    assert(b);
    GfxVertexBuffer* pVb = R_AddVertexBufferToVertexDeclaration(&material->vertex_declaration, &vb);
    assert(pVb);
    (void)pVb;
    material->vertex_declaration.vertices_count = vertices_count;
#if A_RENDER_BACKEND_GL
    if (bsp_material->lightmap_vertices_count > 0) {
        b = R_AppendVertexData(&material->vertex_declaration.vbs[0],
                               lightmap_vertices, lightmap_vertices_size);
        assert(b);
    }
    GL_CALL(glBindVertexArray, material->vertex_declaration.vbs[0].vao);
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
    if (bsp_material->lightmap_vertices_count > 0) {
        b = R_CreateVertexBuffer(lightmap_vertices,
                                 lightmap_vertices_size,
                                 lightmap_vertices_size, 0,
                                 sizeof(BSPLightmapVertex),
                                 &vb);
        assert(b);
        pVb = R_AddVertexBufferToVertexDeclaration(&material->vertex_declaration, &vb);
        assert(pVb);
        (void)pVb;
    }
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
            .Usage      = D3DDECLUSAGE_TEXCOORD,
            .UsageIndex = 1
        },
        D3DDECL_END()
    };
    IDirect3DVertexDeclaration9* decl = NULL;
    D3D_CALL(r_d3d9Glob.d3ddev, CreateVertexDeclaration, vertex_elements, 
                                                         &decl);
    assert(decl);
    material->vertex_declaration.decl = decl;
#endif // A_RENDER_BACKEND_GL
    Z_Free(rendered_vertices);
    Z_Free(lightmap_vertices);
}

static void R_LoadLightmap(const BSPLightmap* bsp_lightmap, GfxLightmap* lightmap) {
    lightmap->materials = (GfxMaterial*)Z_Zalloc(
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

static GfxPrimitiveType R_PrimitiveTypeFromBSP(BSPModelTriBufferType type) {
    switch (type) {
    case BSP_MODEL_TRI_BUFFER_TYPE_TRIANGLE_LIST:
        return PRIMITIVE_TYPE_TRI;
    case BSP_MODEL_TRI_BUFFER_TYPE_TRIANGLE_STRIP:
        return PRIMITIVE_TYPE_TRI_STRIP;
    default:
        assert(false && "R_PrimitiveTypeFromBSP: invalid BSPModelTriBufferType");
        Com_Errorln(
            -1,
            "R_PrimitiveTypeFromBSP: invalid BSPModelTriBufferType %d",
            type
        );
    }
}

static void R_LoadModelPart(const BSPModelGeometryPart* bsp_part, GfxModelPart* part) {
    BSPModelDecompressedVertex* vertices = (BSPModelDecompressedVertex*)bsp_part->decompressed_vertices.pointer;
    int vertex_count = bsp_part->decompressed_vertices.count;
    part->primitive_type = R_PrimitiveTypeFromBSP((BSPModelTriBufferType)bsp_part->tri_buffer_type);

    GfxVertexBuffer vb;
    bool b = R_CreateVertexBuffer(vertices, vertex_count, vertex_count, 0, sizeof(*vertices), &vb);
    assert(b);
    GfxVertexBuffer* pVb = R_AddVertexBufferToVertexDeclaration(&part->vertex_declaration, &vb);
    assert(pVb);
    (void)pVb;
    part->vertex_declaration.vertices_count = vertex_count;
#if A_RENDER_BACKEND_GL
    GL_CALL(glBindVertexArray, part->vertex_declaration.vbs[0].vao);
    GL_CALL(glVertexAttribPointer,
        0, 3, GL_FLOAT, GL_FALSE, sizeof(BSPModelDecompressedVertex),
        (const void*)offsetof(BSPModelDecompressedVertex, position)
    );
    GL_CALL(glVertexAttribPointer,
        1, 3, GL_FLOAT, GL_FALSE, sizeof(BSPModelDecompressedVertex),
        (const void*)offsetof(BSPModelDecompressedVertex, normal)
    );
    GL_CALL(glVertexAttribPointer,
        2, 3, GL_FLOAT, GL_FALSE, sizeof(BSPModelDecompressedVertex),
        (const void*)offsetof(BSPModelDecompressedVertex, binormal)
    );
    GL_CALL(glVertexAttribPointer,
        3, 3, GL_FLOAT, GL_FALSE, sizeof(BSPModelDecompressedVertex),
        (const void*)offsetof(BSPModelDecompressedVertex, tangent)
    );
    GL_CALL(glVertexAttribPointer,
        4, 2, GL_FLOAT, GL_FALSE, sizeof(BSPModelDecompressedVertex),
        (const void*)offsetof(BSPModelDecompressedVertex, texcoords)
    );

    GL_CALL(glEnableVertexAttribArray, 0);
    GL_CALL(glEnableVertexAttribArray, 1);
    GL_CALL(glEnableVertexAttribArray, 2);
    GL_CALL(glEnableVertexAttribArray, 3);
    GL_CALL(glEnableVertexAttribArray, 4);
#elif A_RENDER_BACKEND_D3D9 
    D3DVERTEXELEMENT9 vertex_elements[] = {
        {
            .Stream = 0,
            .Offset = offsetof(BSPModelDecompressedVertex, position),
            .Type = D3DDECLTYPE_FLOAT3,
            .Method = D3DDECLMETHOD_DEFAULT,
            .Usage = D3DDECLUSAGE_POSITION,
            .UsageIndex = 0
        },
        {
            .Stream = 0,
            .Offset = offsetof(BSPModelDecompressedVertex, normal),
            .Type = D3DDECLTYPE_FLOAT3,
            .Method = D3DDECLMETHOD_DEFAULT,
            .Usage = D3DDECLUSAGE_NORMAL,
            .UsageIndex = 0
        },
        {
            .Stream = 0,
            .Offset = offsetof(BSPModelDecompressedVertex, binormal),
            .Type = D3DDECLTYPE_FLOAT3,
            .Method = D3DDECLMETHOD_DEFAULT,
            .Usage = D3DDECLUSAGE_BINORMAL,
            .UsageIndex = 0
        },
        {
            .Stream = 0,
            .Offset = offsetof(BSPModelDecompressedVertex, tangent),
            .Type = D3DDECLTYPE_FLOAT3,
            .Method = D3DDECLMETHOD_DEFAULT,
            .Usage = D3DDECLUSAGE_TANGENT,
            .UsageIndex = 0
        },
        {
            .Stream = 0,
            .Offset = offsetof(BSPModelDecompressedVertex, texcoords),
            .Type = D3DDECLTYPE_FLOAT2,
            .Method = D3DDECLMETHOD_DEFAULT,
            .Usage = D3DDECLUSAGE_TEXCOORD,
            .UsageIndex = 0
        },
        D3DDECL_END()
    };
    IDirect3DVertexDeclaration9* decl = NULL;
    D3D_CALL(r_d3d9Glob.d3ddev, CreateVertexDeclaration, vertex_elements,
        &decl);
    assert(decl);
    part->vertex_declaration.decl = decl;
#endif // A_RENDER_BACKEND_GL
}

static void R_LoadModelGeometry(const BSPModelGeometry* bsp_geometry, GfxModelGeometry* geometry) {
    geometry->part_count = bsp_geometry->parts.count;
    geometry->parts = (GfxModelPart*)Z_Zalloc(geometry->part_count * sizeof(*geometry->parts));
    assert(geometry->parts);
    BSPModelGeometryPart* bsp_parts = (BSPModelGeometryPart*)bsp_geometry->parts.pointer;
    for (int i = 0; i < bsp_geometry->parts.count; i++) {
        R_LoadModelPart(&bsp_parts[i], &geometry->parts[i]);
    }
}

static void R_LoadModel(const BSPModel* bsp_model, GfxModel* model) {
    model->geometry_count = bsp_model->geometries.count;
    model->geometries = (GfxModelGeometry*)Z_Zalloc(model->geometry_count * sizeof(*model->geometries));
    assert(model->geometries);
    BSPModelGeometry* bsp_geometries = (BSPModelGeometry*)bsp_model->geometries.pointer;
    for (int i = 0; i < bsp_model->geometries.count; i++) {
        R_LoadModelGeometry(&bsp_geometries[i], &model->geometries[i]);
    }
    BSPModelShaderReference* shader_refs = (BSPModelShaderReference*)bsp_model->shaders.pointer;
    for (int i = 0; i < bsp_model->shaders.count; i++) {
        BSPModelShaderReference* shader_ref = &shader_refs[i];
        R_LoadShader(shader_ref->shader.id, &model->shaders[i]);
    }
}

static void R_LoadObject(const BSPObject* bsp_object, GfxObject* object) {
    Tag* model_tag = CL_Map_Tag(bsp_object->model.id);
    assert(model_tag);
    BSPModel* bsp_model = (BSPModel*)model_tag->tag_data;
    R_LoadModel(bsp_model, &object->model);
}

static void R_LoadScenarioScenery(const BSPScenarioScenery* bsp_scenario_scenery, GfxScenery* scenery) {
    scenery->pos = bsp_scenario_scenery->pos;
    scenery->rotation.x = bsp_scenario_scenery->yaw;
    scenery->rotation.y = bsp_scenario_scenery->pitch;
    scenery->rotation.z = bsp_scenario_scenery->roll;
}

static void R_LoadSceneryPalette(const BSPScenarioSceneryPalette* bsp_scenery_palette, GfxSceneryPalette* scenery_palette) {
    const Tag* bsp_scenery_tag = CL_Map_Tag(bsp_scenery_palette->name.id);
    assert(bsp_scenery_tag);
    assert(bsp_scenery_tag->primary_class == TAG_FOURCC_SCENERY);
    const BSPScenery* bsp_scenery = (BSPScenery*)bsp_scenery_tag->tag_data;
    R_LoadObject(&bsp_scenery->object, &scenery_palette->obj);
}

void R_LoadMap(void) {
    r_mapGlob.lightmap_count = CL_Map_LightmapCount();
    r_mapGlob.lightmaps = (GfxLightmap*)Z_Zalloc(
        r_mapGlob.lightmap_count * sizeof(*r_mapGlob.lightmaps)
    );
    for (uint32_t i = 0; i < r_mapGlob.lightmap_count; i++) {
        const BSPLightmap* bsp_lightmap = CL_Map_Lightmap(i);
        GfxLightmap* lightmap = &r_mapGlob.lightmaps[i];
        R_LoadLightmap(bsp_lightmap, lightmap);
    }

    r_mapGlob.scenery_palette_count = CL_Map_ScenarioSceneryPaletteCount();
    r_mapGlob.scenery_palette = (GfxSceneryPalette*)Z_Zalloc(r_mapGlob.scenery_palette_count * sizeof(*r_mapGlob.scenery_palette));
    for (uint32_t i = 0; i < r_mapGlob.scenery_palette_count; i++) {
        BSPScenarioSceneryPalette* bsp_scenery_palette = CL_Map_ScenarioSceneryPalette(i);
        R_LoadSceneryPalette(bsp_scenery_palette, &r_mapGlob.scenery_palette[i]);
    }

    r_mapGlob.scenery_count = CL_Map_ScenarioSceneryCount();
    r_mapGlob.scenery = (GfxScenery*)Z_Zalloc(r_mapGlob.scenery_count * sizeof(*r_mapGlob.scenery));
    for (uint32_t i = 0; i < r_mapGlob.scenery_count; i++) {
        BSPScenarioScenery* bsp_scenery = CL_Map_ScenarioScenery(i);
        R_LoadScenarioScenery(bsp_scenery, &r_mapGlob.scenery[i]);
    }
}

static bool R_RenderShaderEnvironment(GfxShaderEnvironment* shader_environment, 
                                      GfxVertexDeclaration* vertex_declaration, 
                                      GfxPrimitiveType primitive_type, 
                                      int primitive_offset, GfxPolygonMode mode
) {
    assert(vertex_declaration->vb_count > 0);
    if (vertex_declaration->vb_count < 1)
        return false;

    assert(vertex_declaration->vertices_count > 0);
#if A_RENDER_BACKEND_GL
    assert(vertex_declaration->vb_count == 1 &&
        "R_RenderVertexBuffer: GL backend only supports one vertex buffer at a time");
#elif A_RENDER_BACKEND_D3D9
    assert(vertex_declaration->decl);
    D3D_CALL(r_d3d9Glob.d3ddev, SetVertexDeclaration, vertex_declaration->decl);
#endif

    bool b = true;
    for (int i = 0; i < vertex_declaration->vb_count; i++) {
        b = R_BindVertexBuffer(&vertex_declaration->vbs[i], i);
        assert(b);
        if (!b)
            return false;
    }

    b = R_BindImage(&shader_environment->base_map,             0);
    assert(b);
    b = R_BindImage(&shader_environment->primary_detail_map,   1);
    assert(b);
    b = R_BindImage(&shader_environment->secondary_detail_map, 2);
    assert(b);
    b = R_BindImage(&shader_environment->micro_detail_map,     3);
    assert(b);
    b = R_BindImage(&shader_environment->bump_map,             4);
    assert(b);
    b = R_BindImage(&shader_environment->map,                  5);
    assert(b);

    b = R_SetPolygonMode(mode);
    assert(b);
    if (!b)
        return false;

    b = R_DrawPrimitives(primitive_type, vertex_declaration->vertices_count / 3, primitive_offset / 3);
    assert(b);
    if (!b)
        return false;

    b = R_SetPolygonMode(R_POLYGON_MODE_FILL);
    assert(b);

    return b;
}

static bool R_RenderShaderModel(GfxShaderModel* shader_model,
                                GfxVertexDeclaration* vertex_declaration,
                                GfxPrimitiveType primitive_type,
                                int primitive_offset, GfxPolygonMode mode
) {
    assert(vertex_declaration->vb_count > 0);
    if (vertex_declaration->vb_count < 1)
        return false;

    assert(vertex_declaration->vertices_count > 0);
#if A_RENDER_BACKEND_GL
    assert(vertex_declaration->vb_count == 1 &&
        "R_RenderVertexBuffer: GL backend only supports one vertex buffer at a time");
#elif A_RENDER_BACKEND_D3D9
    assert(vertex_declaration->decl);
    D3D_CALL(r_d3d9Glob.d3ddev, SetVertexDeclaration, vertex_declaration->decl);
#endif

    bool b = true;
    for (int i = 0; i < vertex_declaration->vb_count; i++) {
        b = R_BindVertexBuffer(&vertex_declaration->vbs[i], i);
        assert(b);
        if (!b)
            return false;
    }

    b = R_BindImage(&shader_model->base_map, 0);
    assert(b);
    b = R_BindImage(&shader_model->multipurpose_map, 1);
    assert(b);
    b = R_BindImage(&shader_model->detail_map, 2);
    assert(b);

    b = R_SetPolygonMode(mode);
    assert(b);
    if (!b)
        return false;

    b = R_DrawPrimitives(primitive_type, vertex_declaration->vertices_count / 3, primitive_offset / 3);
    assert(b);
    if (!b)
        return false;

    b = R_SetPolygonMode(R_POLYGON_MODE_FILL);
    assert(b);

    return b;
}

static void R_RenderShader(GfxShader* shader,
                           GfxVertexDeclaration* vertex_declaration,
                           GfxPrimitiveType primitive_type,
                           int primitive_offset, GfxPolygonMode mode
) {
    switch (shader->type) {
    case SHADER_TYPE_ENVIRONMENT:
        R_RenderShaderEnvironment(&shader->environment, vertex_declaration, primitive_type, primitive_offset, mode);
        return;
    case SHADER_TYPE_MODEL:
        R_RenderShaderModel(&shader->model, vertex_declaration, primitive_type, primitive_offset, mode);
        return;
    default:
        assert(false && "R_RenderShader: invalid shader type");
        Com_Errorln(
            -1,
            "R_RenderShader: invalid shader type %d",
            shader->type
        );
    }
}

static void R_RenderMaterial(GfxMaterial* material) {
#if !A_TARGET_PLATFORM_IS_XBOX
    //R_ShaderSetUniformBoolByName(&r_mapGlob.prog, "uAlphaTested",
    //                             material->alpha_tested);

    //R_ShaderSetUniformIntByName(&r_mapGlob.prog, "uDetailMapFunction",
    //                           (int)material->detail_map_function);
    //R_ShaderSetUniformIntByName(&r_mapGlob.prog, "uMicroDetailMapFunction",
    //                           (int)material->micro_detail_map_function);

    avec4f_t color = A_vec4(
        material->ambient_color.r,
        material->ambient_color.g,
        material->ambient_color.b,
        1.0f
    );
    R_ShaderSetUniformVec4fByName(&r_mapGlob.prog, "uAmbientColor", 
                                  SHADER_TYPE_PIXEL, color);

    //R_ShaderSetUniformVec3fByName(
    //    &r_mapGlob.prog, "uDistantLight0Dir",
    //    material->distant_light_0_dir);
    //R_ShaderSetUniformVec3fByName(
    //    &r_mapGlob.prog, "uDistantLight1Dir",
    //    material->distant_light_1_dir);

    //color.x =
    //    material->distant_light_0_color.r;
    //color.y =
    //    material->distant_light_0_color.g;
    //color.z =
    //    material->distant_light_0_color.b;
    //R_ShaderSetUniformVec3fByName(&r_mapGlob.prog,
    //    "uDistantLight0Color", color);

    //color.x =
    //    material->distant_light_1_color.r;
    //color.y =
    //    material->distant_light_1_color.g;
    //color.z =
    //    material->distant_light_1_color.b;
    //R_ShaderSetUniformVec3fByName(&r_mapGlob.prog,
    //    "uDistantLight1Color", color);

    //bool wireframe = Dvar_GetBool(r_wireframe);

    R_RenderShader(&material->shader, &material->vertex_declaration, PRIMITIVE_TYPE_TRI, 0, R_POLYGON_MODE_FILL);
    if (Dvar_GetBool(r_wireframe)) {
        R_ShaderSetUniformBoolByName(&r_mapGlob.prog, "uWireframe", SHADER_TYPE_PIXEL, true);
        R_RenderShader(&material->shader, &material->vertex_declaration, PRIMITIVE_TYPE_TRI, 0, R_POLYGON_MODE_LINE);
        R_ShaderSetUniformBoolByName(&r_mapGlob.prog, "uWireframe", SHADER_TYPE_PIXEL, false);
    }
#else
	assert(false && "unimplemented"); // FIXME
#endif // !A_TARGET_PLATFORM_IS_XBOX
}

static void R_RenderModelPart(GfxModel* model, GfxModelPart* part, apoint3f_t position, avec3f_t rotation) {
#if !A_TARGET_PLATFORM_IS_XBOX
    amat4f_t pos = A_MAT4F_IDENTITY;
    avec3f_t p = A_vec3(position.x, position.y, position.z);
    pos = A_mat4f_translate_vec3(pos, p);
    amat4f_t r = A_mat4f_euler(rotation);
    amat4f_t m = A_mat4f_mul(pos, r);
    R_ShaderSetUniformMat4fByName(&r_mapGlob.model_prog, "uModel", SHADER_TYPE_VERTEX, m);

    GfxShader* shader = &model->shaders[part->shader_index];
    R_RenderShader(shader, &part->vertex_declaration, part->primitive_type, 0, R_POLYGON_MODE_FILL);
    if (Dvar_GetBool(r_wireframe)) {
        R_ShaderSetUniformBoolByName(&r_mapGlob.prog, "uWireframe", SHADER_TYPE_PIXEL, true);
        R_RenderShader(shader, &part->vertex_declaration, part->primitive_type, 0, R_POLYGON_MODE_LINE);
        R_ShaderSetUniformBoolByName(&r_mapGlob.prog, "uWireframe", SHADER_TYPE_PIXEL, false);
    }
#else
	assert(false && "unimplemented"); // FIXME
#endif // !A_TARGET_PLATFORM_IS_XBOX
}

static void R_RenderModel(GfxModel* model, apoint3f_t pos, avec3f_t rotation) {
    GfxModelGeometry* geometries = model->geometries;
    for (int i = 0; i < model->geometry_count; i++) {
        GfxModelGeometry* geometry = &geometries[i];
        for (int j = 0; j < geometry->part_count; j++) {
            GfxModelPart* part = &geometry->parts[j];
            R_RenderModelPart(model, part, pos, rotation);
        }
    }
}

static void R_RenderObject(GfxObject* obj, apoint3f_t pos, avec3f_t rotation) {
    R_RenderModel(&obj->model, pos, rotation);
}

static void R_RenderScenery(GfxScenery* scenery) {
    GfxSceneryPalette* palette = &r_mapGlob.scenery_palette[scenery->palette_index];
    R_RenderObject(&palette->obj, scenery->pos, scenery->rotation);
}

static void R_RenderMapInternal(void) {
    R_EnableDepthTest();
    R_EnableBackFaceCulling();
#if A_RENDER_BACKEND_GL
    R_ShaderSetUniformIntByName(&r_mapGlob.prog,       "uBaseMap",            SHADER_TYPE_PIXEL, 0);
    R_ShaderSetUniformIntByName(&r_mapGlob.model_prog, "uBaseMap",            SHADER_TYPE_PIXEL, 0);
//    R_ShaderSetUniformIntByName(&r_mapGlob.prog, "uPrimaryDetailMap",   SHADER_TYPE_PIXEL, 1);
//    R_ShaderSetUniformIntByName(&r_mapGlob.prog, "uSecondaryDetailMap", SHADER_TYPE_PIXEL, 2);
//    R_ShaderSetUniformIntByName(&r_mapGlob.prog, "uMicroDetailMap",     SHADER_TYPE_PIXEL, 3);
//    R_ShaderSetUniformIntByName(&r_mapGlob.prog, "uBumpMap",            SHADER_TYPE_PIXEL, 4);
//    R_ShaderSetUniformIntByName(&r_mapGlob.prog, "uMap",                SHADER_TYPE_PIXEL, 5);
#endif // A_RENDER_BACKEND_GL

    bool b = R_BindShaderProgram(&r_mapGlob.prog);
    assert(b);
    if (!b)
        return;
#if !A_TARGET_PLATFORM_IS_XBOX
	amat4f_t model = A_MAT4F_IDENTITY;
    R_ShaderSetUniformMat4fByName(&r_mapGlob.prog, "uModel", 
                                  SHADER_TYPE_VERTEX, model);
#else
	assert(false); // FIXME
#endif // !A_TARGET_PLATFORM_IS_XBOX
    for (uint32_t i = 0; i < r_mapGlob.lightmap_count; i++) {
        GfxLightmap* lightmap = &r_mapGlob.lightmaps[i];
        for (uint32_t j = 0; j < lightmap->material_count; j++) {
            GfxMaterial* material = &lightmap->materials[j];
            //R_RenderMaterial(material);
        }
    }

    for (uint32_t i = 0; i < r_mapGlob.scenery_count; i++) {
        R_RenderScenery(&r_mapGlob.scenery[i]);
    }

    R_BindShaderProgram(NULL);
    R_DisableBackFaceCulling();
    R_DisableDepthTest();
}

void R_RenderMap(void) {
    if (!CL_IsMapLoaded())
        return;

    R_RenderMapInternal();
}

static void R_UnloadShaderEnvironment(A_IN GfxShaderEnvironment* shader) {
    R_DeleteImage(&shader->base_map);
    R_DeleteImage(&shader->primary_detail_map);
    R_DeleteImage(&shader->secondary_detail_map);
    R_DeleteImage(&shader->micro_detail_map);
    R_DeleteImage(&shader->bump_map);
    R_DeleteImage(&shader->map);
}

static void R_UnloadShaderModel(A_IN GfxShaderModel* shader) {
    R_DeleteImage(&shader->base_map);
    R_DeleteImage(&shader->detail_map);
    R_DeleteImage(&shader->multipurpose_map);
}

static void R_UnloadShader(A_IN GfxShader* shader) {
    switch (shader->type) {
    case SHADER_TYPE_ENVIRONMENT:
        R_UnloadShaderEnvironment(&shader->environment);
        return;
    case SHADER_TYPE_MODEL:
        R_UnloadShaderModel(&shader->model);
        return;
    default:
        assert(false && "R_UnloadShader: invalid shader type");
        Com_Errorln(
            -1,
            "R_UnloadShader: invalid shader type %d",
            shader->type
        );
    }
}

void R_UnloadMaterial(A_IN GfxMaterial* material) {
    R_UnloadShader(&material->shader);
    R_DeleteVertexDeclaration(&material->vertex_declaration);
}

void R_UnloadLightmap(A_IN GfxLightmap* lightmap) {
    for (uint32_t i = 0; i < lightmap->material_count; i++) {
        GfxMaterial* material = &lightmap->materials[i];
        R_UnloadMaterial(material);
    }
    Z_Free(lightmap->materials);
}

void R_UnloadModelPart(A_IN GfxModelPart* part) {
    R_DeleteVertexDeclaration(&part->vertex_declaration);
}

void R_UnloadModel(A_IN GfxModel* model) {
    GfxModelGeometry* geometries = model->geometries;
    for (int i = 0; i < model->geometry_count; i++) {
        GfxModelGeometry* geometry = &geometries[i];
        for (int j = 0; j < geometry->part_count; j++) {
            GfxModelPart* part = &geometry->parts[j];
            R_UnloadModelPart(part);
        }
    }

    for (int i = 0; i < A_countof(model->shaders); i++) {
        R_UnloadShader(&model->shaders[i]);
    }
}

void R_UnloadObject(A_IN GfxObject* obj) {
    R_UnloadModel(&obj->model);
}

void R_UnloadSceneryPalette(A_IN GfxSceneryPalette* scenery_palette) {
    R_UnloadObject(&scenery_palette->obj);
}

void R_UnloadMap(void) {
    for (uint32_t i = 0; i < r_mapGlob.lightmap_count; i++)
        R_UnloadLightmap(&r_mapGlob.lightmaps[i]);

    for (uint32_t i = 0; i < r_mapGlob.scenery_palette_count; i++)
        R_UnloadSceneryPalette(&r_mapGlob.scenery_palette[i]);
    
    Z_Free(r_mapGlob.lightmaps);
}

void R_ShutdownMap(void) {
    if (CL_IsMapLoaded())
        R_UnloadMap();

    R_DeleteShaderProgram(&r_mapGlob.prog);
}
