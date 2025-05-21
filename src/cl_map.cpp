#include "cl_map.h"

#include <cassert>

#include <string>

#include <zlib.h>

#if !A_TARGET_PLATFORM_IS_XBOX
#ifdef _MSC_VER 
#pragma warning(push)
#pragma warning(disable : 4244)
#pragma warning(disable : 4245)
#endif // _MSC_VER
#include <invader/tag/hek/definition.hpp>
#include <invader/tag/hek/header.hpp>
#include <invader/hek/map.hpp>
#ifdef _MSC_VER
#pragma warning(pop) 
#endif // _MSC_VER
#endif // !A_TARGET_PLATFORM_IS_XBOX

#include "acommon/acommon.h"
#include "acommon/a_math.h"
#include "acommon/a_string.h"
#include "acommon/z_mem.h"

#include "cg_cgame.h"
#include "com_print.h"
#include "db_files.h"
#include "fs_files.h"
#include "gfx.h"

#define BSP_MAX_COLLISION_MATERIALS 512
#define BSP_MAX_SKIES 8

struct MapLoadData {
	StreamFile  		       f;
	const char* 		       map_name;
	void*                      p;
	size_t      		       n;
	FileMapping                bitmaps_map;
							   
	Tag*                       tags;
	uint32_t                   tag_count;
	BSPModelCompressedVertex*  model_vertices;
	uint16_t*                  model_indices;
	BSPSurf*                   surfs;
	uint32_t                   surf_count;
	BSPRenderedVertex*         rendered_vertices;
	BSPLightmapVertex*         lightmap_vertices;
	BSPCollSurf*               coll_surfs;
	uint32_t    		       coll_surf_count;
	BSPCollEdge*               coll_edges;
	uint32_t    		       coll_edge_count;
	BSPCollVertex*             coll_vertices;
	uint32_t    		       coll_vertex_count;
	BSPCollisionMaterial*      collision_materials;
	uint32_t                   lightmap_count;
	BSPLightmap*               lightmaps;
	BSPSky*                    skies[BSP_MAX_SKIES];
	uint32_t                   skies_count;
	BSPScenarioScenery*        scenario_scenery;
	uint32_t                   scenario_scenery_count;
	BSPScenarioSceneryPalette* scenario_scenery_palette;
	uint32_t                   scenario_scenery_palette_count;

	Invader::HEK::ScenarioStructureBSP<Invader::HEK::NativeEndian>* bsp_ptr;
} g_load;

static void CL_DecompressVector(A_OUT avec3f_t* decompressed, uint32_t compressed);
static void CL_DecompressRenderedVertex(
	A_OUT BSPRenderedVertex* decompressed,
	const BSPRenderedVertexCompressed* compressed
);
static void CL_DecompressLightmapVertex(
	A_OUT BSPLightmapVertex* decompressed,
	const BSPLightmapVertexCompressed* compressed
);

static bool CL_LoadMap_Header    (A_OUT MapHeader*   header);
static bool CL_LoadMap_TagHeader (const MapHeader*   header, bool is_xbox,
								  A_OUT TagHeader*   tag_header);
static bool CL_LoadMap_Decompress(const char*        map_name, 
	                              const MapHeader*   header);
static bool CL_LoadMap_TagData   (const MapHeader*   header,
	                              const TagHeader*   tag_header, bool is_xbox);
static bool CL_LoadMap_BSPHeader (const ScenarioBSP* sbsp,
	                              A_OUT BSPHeader**  bsp_header);
static bool CL_LoadMap_Scenario(
	const TagHeader* tag_header,
	A_OUT Invader::HEK::Scenario<Invader::HEK::NativeEndian>** scenario
);
static bool CL_LoadMap_BSP(
	const ScenarioBSP* sbsp,
	const BSPHeader* bsp_header,
	A_OUT Invader::HEK::ScenarioStructureBSP<Invader::HEK::NativeEndian>** bsp
);
static bool CL_LoadMap_CBSBVertices(
	const Invader::HEK::ModelCollisionGeometryBSP<Invader::HEK::NativeEndian>* cbsp,
	A_OUT Invader::HEK::ModelCollisionGeometryBSPVertex<Invader::HEK::NativeEndian>** vertices
);
static bool CL_LoadMap_CBSP(
	const Invader::HEK::ScenarioStructureBSP< Invader::HEK::NativeEndian>* bsp,
	A_OUT Invader::HEK::ModelCollisionGeometryBSPVertex<Invader::HEK::NativeEndian>** vertices,
	A_OUT Invader::HEK::ModelCollisionGeometryBSP<Invader::HEK::NativeEndian>** cbsp
);
static bool CL_LoadMap_CollisionMaterials(
	const Invader::HEK::ScenarioStructureBSP< Invader::HEK::NativeEndian>* bsp,
	A_OUT BSPCollisionMaterial** collision_materials
);
static size_t CL_BitmapDataSize(const BSPBitmapData* bitmap_data);
static bool   CL_LoadMap_Bitmap(TagId tag_id);
size_t CL_BitmapDataFormatBPP(BSPBitmapDataFormat format);

static bool CL_LoadMap_Shader(TagId shader_id);
static bool CL_LoadMap_Sky(TagId id);
static bool CL_LoadMap_Model(TagId id);
static bool CL_LoadMap_Object(TagId id);

//static const void* CL_BitmapOffsetToPointer(size_t off, MapEngine engine, void* bsp_base) {
//	assert(g_load.bitmaps_map.p);
//	assert(g_load.bitmaps_map.n >= off);
//
//	if (engine == MAP_ENGINE_XBOX) 
//		return (const void*)((char*)bsp_base + off);
//
//	return (const void*)((const char*)g_load.bitmaps_map.p + off);
//}

void CL_InitMap(void) {
	A_memset((void*)&g_load, 0, sizeof(g_load));
	Com_DPrintln(CON_DEST_CLIENT,
		"CL_Init: Successfully mapped bitmaps.map at 0x%08X (%zu bytes)",
		(size_t)g_load.bitmaps_map.p, g_load.bitmaps_map.n
	);
}

bool CL_LoadMap(const char* map_name) {
	g_load.f = DB_LoadMap_Stream(map_name);
	if (g_load.f.f == NULL) {
		return false;
	}

	MapHeader header;
	if (!CL_LoadMap_Header(&header)) return false;

	bool is_xbox = header.engine == MAP_ENGINE_XBOX;
	bool is_gearbox = header.engine == MAP_ENGINE_GEARBOX;

	if (!is_gearbox) {
		if (!is_xbox) {
			Com_Errorln(-1, "CL_LoadMap: Wrong engine version.");
		}

		CL_LoadMap_Decompress(map_name, &header);
	} else {
		g_load.bitmaps_map = DB_LoadMap_Mmap("bitmaps.map");
		assert(g_load.bitmaps_map.p && g_load.bitmaps_map.n > 0);
	}

	TagHeader tag_header;
	if (!CL_LoadMap_TagHeader(&header, is_xbox, &tag_header)) return false;
	g_load.tag_count = tag_header.common.tag_count;
	if (!CL_LoadMap_TagData(&header, &tag_header, is_xbox)) return false;
	if (is_xbox) {
		BSPModelPartVerticesIndirect* vert_ind = (BSPModelPartVerticesIndirect*)tag_header.xbox.vertex_data_ptr;
		g_load.model_vertices = (BSPModelCompressedVertex*)vert_ind->vertices;
		BSPModelPartIndicesIndirect* ind_ind = (BSPModelPartIndicesIndirect*)tag_header.xbox.triangle_data_ptr;
		g_load.model_indices = (uint16_t*)ind_ind->indices;
	}

	Invader::HEK::Scenario<Invader::HEK::NativeEndian>* scenario = NULL;
	if (!CL_LoadMap_Scenario(&tag_header, &scenario)) return false;

	ScenarioPlayerSpawn* spawns =
		(ScenarioPlayerSpawn*)scenario->player_starting_locations.pointer.read();

	for (size_t localClientNum = 0;
		localClientNum < MAX_LOCAL_CLIENTS;
		localClientNum++
		) {
		apoint3f_t pos = A_point3f_swap_yz(spawns[0].pos);
		CG_SetSpawn(localClientNum, pos, spawns[0].facing);
	}

	const ScenarioBSP* sbsps =
		(ScenarioBSP*)scenario->structure_bsps.pointer.read();
	BSPHeader* bsp_header = NULL;
	if (!CL_LoadMap_BSPHeader(&sbsps[0], &bsp_header)) return false;
	g_load.rendered_vertices = (BSPRenderedVertex*)bsp_header->rendered_vertices;
	g_load.lightmap_vertices = (BSPLightmapVertex*)bsp_header->lightmap_vertices;

	Invader::HEK::ScenarioStructureBSP<Invader::HEK::NativeEndian>* bsp = NULL;
	if (!CL_LoadMap_BSP(&sbsps[0], bsp_header, &bsp)) return false;
	assert(bsp);
	g_load.bsp_ptr = bsp;
	g_load.surfs = (BSPSurf*)(uint32_t)bsp->surfaces.pointer.read();
	g_load.surf_count = bsp->surfaces.count.read();
	g_load.lightmaps = (BSPLightmap*)bsp->lightmaps.pointer.read();
	g_load.lightmap_count = bsp->lightmaps.count.read();

	Invader::HEK::ModelCollisionGeometryBSPVertex<Invader::HEK::NativeEndian>* vertices = NULL;
	Invader::HEK::ModelCollisionGeometryBSP<Invader::HEK::NativeEndian>* cbsp = NULL;
	if (!CL_LoadMap_CBSP(bsp, &vertices, &cbsp)) return false;
	assert(vertices && cbsp);
	g_load.coll_surfs = (BSPCollSurf*)(uint32_t)cbsp->surfaces.pointer.read();
	g_load.coll_surf_count = cbsp->surfaces.count;
	g_load.coll_edges = (BSPCollEdge*)(uint32_t)cbsp->edges.pointer.read();
	g_load.coll_edge_count = cbsp->edges.count;
	g_load.coll_vertices = (BSPCollVertex*)vertices;
	g_load.coll_vertex_count = cbsp->vertices.count;

	BSPCollisionMaterial* collision_materials = NULL;
	if (!CL_LoadMap_CollisionMaterials(bsp, &collision_materials)) return false;
	assert(collision_materials);
	g_load.collision_materials = collision_materials;

	size_t total_vertex_count = 0;
	Invader::HEK::ScenarioStructureBSPLightmap<Invader::HEK::NativeEndian>* lightmaps =
		(Invader::HEK::ScenarioStructureBSPLightmap<Invader::HEK::NativeEndian>*)bsp->lightmaps.pointer.read();
	for (uint32_t i = 0; i < bsp->lightmaps.count; i++) {
		Invader::HEK::ScenarioStructureBSPLightmap<Invader::HEK::NativeEndian>* lightmap = &lightmaps[i];
		BSPMaterial* materials = (BSPMaterial*)lightmap->materials.pointer.read();
		for (uint32_t j = 0; j < lightmap->materials.count; j++) {
			BSPMaterial* material = &materials[j];
			uint32_t rendered_vertices_count =
				material->rendered_vertices_count;
			uint32_t lightmap_vertices_count =
				material->lightmap_vertices_count;

			if ((rendered_vertices_count == 0 || lightmap_vertices_count == 0) &&
				i < bsp->lightmaps.count.read() - 1
				) {
				Com_DPrintln(CON_DEST_CLIENT, "Lightmap %u Material %u: bitmap == -1", i, j);
				assert(false);
			}

			if (material->shader.id.index == 0xFFFF)
				continue;
			Tag* shader_tag = CL_Map_Tag(material->shader.id);
			assert(shader_tag);

			total_vertex_count += rendered_vertices_count;
			const BSPRenderedVertexCompressed* compressed_rendered_vertices =
				(const BSPRenderedVertexCompressed*)
				material->compressed_vertices.pointer;
			const BSPLightmapVertexCompressed* compressed_lightmap_vertices =
				(const BSPLightmapVertexCompressed*)(
					(const BSPRenderedVertexCompressed*)
						material->compressed_vertices.pointer +
					(uint64_t)material->rendered_vertices_count
				);

			size_t decompressed_rendered_vertices_size =
				rendered_vertices_count * sizeof(BSPRenderedVertex);
			size_t decompressed_lightmap_vertices_size =
				lightmap_vertices_count * sizeof(BSPLightmapVertex);
			size_t decompressed_vertices_size =
				decompressed_rendered_vertices_size + decompressed_lightmap_vertices_size;

			void* decompressed_vertices = Z_Alloc(decompressed_vertices_size);
			material->uncompressed_vertices.pointer = decompressed_vertices;
			material->uncompressed_vertices.size    = decompressed_vertices_size;
			BSPRenderedVertex* rendered_vertices =
				(BSPRenderedVertex*)decompressed_vertices;
			for (uint32_t k = 0; k < rendered_vertices_count; k++)
				CL_DecompressRenderedVertex(&rendered_vertices[k],
					&compressed_rendered_vertices[k]);
			BSPLightmapVertex* lightmap_vertices =
				(BSPLightmapVertex*)
				((char*)decompressed_vertices +
					decompressed_rendered_vertices_size);
			for (uint32_t k = 0; k < material->lightmap_vertices_count; k++)
				CL_DecompressLightmapVertex(&lightmap_vertices[k],
					&compressed_lightmap_vertices[k]);

			for (int32_t k = material->surfaces;
				k < material->surfaces + material->surface_count;
				k++
			) {
				for (int l = 0; l < 3; l++) {
					if (g_load.surfs[k].verts[l] >= rendered_vertices_count)
						Com_DPrintln(CON_DEST_CLIENT,
							"CL_LoadMap: Lightmap %u Material %u: out of bounds vertex index %u for surf %d, vert %d",
							i, j, (uint16_t)g_load.surfs[k].verts[l], k, l
						);
					assert(g_load.surfs[k].verts[l] < rendered_vertices_count);
				}
			}

			CL_LoadMap_Shader(shader_tag->tag_id);
		}
	}
	Com_DPrintln(CON_DEST_CLIENT, "CL_LoadMap: Total Vertex Count=%zu.", total_vertex_count);

	TagDependency* sky_dependencies = 
		(TagDependency*)scenario->skies.pointer.read();
	for (int i = 0; i < scenario->skies.count.read(); i++) {
		TagDependency* sky_dependency = &sky_dependencies[i];
		TagId sky_id = sky_dependency->id;
		CL_LoadMap_Sky(sky_id);
		g_load.skies[i] = (BSPSky*)CL_Map_Tag(sky_id)->tag_data;
	}
	g_load.skies_count = scenario->skies.count.read();

	BSPScenarioObjectName* object_names = 
		(BSPScenarioObjectName*)scenario->object_names.pointer.read();
	for (int i = 0; i < scenario->object_names.count; i++) {
		Com_Println(CON_DEST_CLIENT,
					"CL_LoadMap: found object %s (%d) of type %d",
					object_names[i].name, i, object_names[i].object_type);
	}

	BSPScenarioSceneryPalette* scenery_palette_tags = 
		(BSPScenarioSceneryPalette*)scenario->scenery_palette.pointer.read();
	int scenery_palette_count = scenario->scenery_palette.count;
	for (int i = 0; i < scenery_palette_count; i++) {
		BSPScenarioSceneryPalette* scenery_palette_tag = &scenery_palette_tags[i];
		if (scenery_palette_tag->name.fourcc == 0)
			continue;

		assert(scenery_palette_tag->name.fourcc == TAG_FOURCC_SCENERY);

		if (scenery_palette_tag->name.id.index == 0xFFFF)
			continue;
		Com_Println(CON_DEST_CLIENT,
					"CL_LoadMap: found scenery %s", 
					scenery_palette_tag->name.path_pointer);

		bool b = CL_LoadMap_Object(scenery_palette_tag->name.id);
		assert(b);
	}

	g_load.scenario_scenery = (BSPScenarioScenery*)scenario->scenery.pointer.read();
	g_load.scenario_scenery_count = scenario->scenery.count;
	g_load.scenario_scenery_palette = (BSPScenarioSceneryPalette*)scenario->scenery_palette.pointer.read();
	g_load.scenario_scenery_palette_count = scenario->scenery_palette.count;

	R_LoadMap();

	for (size_t localClientNum = 0;
		localClientNum < MAX_LOCAL_CLIENTS;
		localClientNum++
	) {
		CG_Respawn(localClientNum);
	}

	return true;
}

void CL_UnloadModel(BSPModel* model) {
	BSPModelGeometry* geometries = (BSPModelGeometry*)model->geometries.pointer;
	for (int i = 0; i < model->geometries.count; i++) {
		BSPModelGeometry* geometry = &geometries[i];
		BSPModelGeometryPart* parts = (BSPModelGeometryPart*)geometry->parts.pointer;
		for (int j = 0; j < geometry->parts.count; j++) {
			BSPModelGeometryPart* part = &parts[i];
			// FIXME: more heap corruption
			//Z_Free(part->decompressed_vertices.pointer);
			part->decompressed_vertices.count = 0;
			part->decompressed_vertices.pointer = NULL;
		}
		
	}
}

void CL_UnloadScenery(BSPScenery* scenery) {
	Tag* model_tag = CL_Map_Tag(scenery->object.model.id);
	BSPModel* model = (BSPModel*)model_tag->tag_data;
	CL_UnloadModel(model);
}

bool CL_UnloadMap(void) {
	R_UnloadMap();
	DB_UnloadMap_Stream(&g_load.f);

	if (!g_load.bsp_ptr)
		return false;

	BSPSky** skies = g_load.skies;
	for (int i = 0; i < g_load.skies_count; i++) {
		BSPSky* sky = skies[i];
		TagId id = sky->model.id;
		if (id.index == 0xFFFF)
			continue;

		Tag* model_tag = CL_Map_Tag(id);
		assert(model_tag->primary_class == TAG_FOURCC_MODEL);
		BSPModel* model = (BSPModel*)model_tag->tag_data;
		BSPModelGeometry* geoms = (BSPModelGeometry*)model->geometries.pointer;
		for (int j = 0; j < model->geometries.count; j++) {
			BSPModelGeometry* geom = &geoms[j];
			BSPModelGeometryPart* parts =
				(BSPModelGeometryPart*)geom->parts.pointer;
			for (int k = 0; k < geom->parts.count; k++) {
				BSPModelGeometryPart* part = &parts[k];
				assert(part->compressed_vertices.count ==
					part->decompressed_vertices.count);
				Z_Free(part->decompressed_vertices.pointer);
			}
		}
	}

	Invader::HEK::ScenarioStructureBSPLightmap<Invader::HEK::NativeEndian>* lightmaps =
		(Invader::HEK::ScenarioStructureBSPLightmap<Invader::HEK::NativeEndian>*)g_load.bsp_ptr->lightmaps.pointer.read();
	for (uint32_t i = 0; i < g_load.bsp_ptr->lightmaps.count; i++) {
		Invader::HEK::ScenarioStructureBSPLightmap<Invader::HEK::NativeEndian>* lightmap = &lightmaps[i];
		BSPMaterial* materials = (BSPMaterial*)lightmap->materials.pointer.read();
		for (uint32_t j = 0; j < lightmap->materials.count; j++) {
			BSPMaterial* material = &materials[j];
			Z_Free(material->uncompressed_vertices.pointer);

			if (material->shader.id.index == 0xFFFF)
				continue;
			Tag* shader_tag = CL_Map_Tag(material->shader.id);
			assert(shader_tag);
			assert(shader_tag->tag_data);

			assert(shader_tag->secondary_class == TAG_FOURCC_SHADER);
			if (shader_tag->primary_class == TAG_FOURCC_SHADER_ENVIRONMENT) {
				BSPShaderEnvironment* shader =
					(BSPShaderEnvironment*)shader_tag->tag_data;

				if (shader->base_map.id.index != 0xFFFF) {
					Tag* base_map_tag = CL_Map_Tag(shader->base_map.id);
					assert(base_map_tag->primary_class == TAG_FOURCC_BITMAP);
					BSPBitmap* base_map_bitmap = (BSPBitmap*)base_map_tag->tag_data;
					BSPBitmapData* bitmap_data =
						(BSPBitmapData*)base_map_bitmap->bitmap_data.pointer;
					for (uint32_t k = 0;
						k < base_map_bitmap->bitmap_data.count;
						k++
						) {
						if (bitmap_data[k].type !=
							BSP_BITMAP_DATA_TYPE_2D_TEXTURE &&
							bitmap_data[k].type !=
							BSP_BITMAP_DATA_TYPE_3D_TEXTURE
							) {
							continue;
						}

						assert(bitmap_data[k].pixels &&
							bitmap_data[k].pixels != (void*)0xFFFFFFFF);
						// FIXME: leak is intentional for now 
						// this call to Z_Free is corrupting the heap somehow
						//Z_Free(bitmap_data[k].pixels);
					}
				}

				if (shader->primary_detail_map.id.index != 0xFFFF) {
					Tag* primary_detail_map_tag =
						CL_Map_Tag(shader->primary_detail_map.id);
					assert(primary_detail_map_tag->primary_class ==
						TAG_FOURCC_BITMAP);
					BSPBitmap* primary_detail_map_bitmap =
						(BSPBitmap*)primary_detail_map_tag->tag_data;
					BSPBitmapData* bitmap_data =
						(BSPBitmapData*)
						primary_detail_map_bitmap->bitmap_data.pointer;
					for (uint32_t k = 0;
						k < primary_detail_map_bitmap->bitmap_data.count;
						k++
					) {
						if (bitmap_data[k].type !=
							BSP_BITMAP_DATA_TYPE_2D_TEXTURE &&
							bitmap_data[k].type !=
							BSP_BITMAP_DATA_TYPE_3D_TEXTURE
							) {
							continue;
						}

						assert(bitmap_data[k].pixels &&
							bitmap_data[k].pixels != (void*)0xFFFFFFFF);
						// FIXME: leak is intentional for now 
						// this call to Z_Free is corrupting the heap somehow
						//Z_Free(bitmap_data[k].pixels);
					}
				}

				if (shader->secondary_detail_map.id.index != 0xFFFF) {
					Tag* secondary_detail_map_tag =
						CL_Map_Tag(shader->secondary_detail_map.id);
					assert(secondary_detail_map_tag->primary_class ==
						TAG_FOURCC_BITMAP);
					BSPBitmap* secondary_detail_map_bitmap =
						(BSPBitmap*)secondary_detail_map_tag->tag_data;
					BSPBitmapData* bitmap_data =
						(BSPBitmapData*)
						secondary_detail_map_bitmap->bitmap_data.pointer;
					for (uint32_t k = 0;
						k < secondary_detail_map_bitmap->bitmap_data.count;
						k++
					) {
						if (bitmap_data[k].type != BSP_BITMAP_DATA_TYPE_2D_TEXTURE &&
							bitmap_data[k].type != BSP_BITMAP_DATA_TYPE_3D_TEXTURE
							) {
							continue;
						}

						assert(bitmap_data[k].pixels &&
							bitmap_data[k].pixels != (void*)0xFFFFFFFF);
						// FIXME: leak is intentional for now 
						// this call to Z_Free is corrupting the heap somehow
						//Z_Free(bitmap_data[k].pixels);
					}
				}

				if (shader->micro_detail_map.id.index != 0xFFFF) {
					Tag* micro_detail_map_tag =
						CL_Map_Tag(shader->micro_detail_map.id);
					assert(micro_detail_map_tag->primary_class ==
						TAG_FOURCC_BITMAP);
					BSPBitmap* micro_detail_map_bitmap =
						(BSPBitmap*)micro_detail_map_tag->tag_data;
					BSPBitmapData* bitmap_data =
						(BSPBitmapData*)
						micro_detail_map_bitmap->bitmap_data.pointer;
					for (uint32_t k = 0;
						k < micro_detail_map_bitmap->bitmap_data.count;
						k++
					) {
						if (bitmap_data[k].type != BSP_BITMAP_DATA_TYPE_2D_TEXTURE &&
							bitmap_data[k].type != BSP_BITMAP_DATA_TYPE_3D_TEXTURE
						) {
							continue;
						}

						assert(bitmap_data[k].pixels &&
							bitmap_data[k].pixels != (void*)0xFFFFFFFF);
						// FIXME: leak is intentional for now 
						// this call to Z_Free is corrupting the heap somehow
						//Z_Free(bitmap_data[k].pixels);
					}
				}
			}
		}
	}

	for (int i = 0; i < CL_Map_ScenarioSceneryPaletteCount(); i++) {
		BSPScenarioSceneryPalette* palette = CL_Map_ScenarioSceneryPalette(i);
		Tag* scenery_tag = CL_Map_Tag(palette->name.id);
		assert(scenery_tag);
		assert(scenery_tag->primary_class == TAG_FOURCC_SCENERY);
		BSPScenery* scenery = (BSPScenery*)scenery_tag->tag_data;
		CL_UnloadScenery(scenery);
	}

	if (g_load.p && g_load.n > 0) {
		Z_FreeAt(g_load.p, g_load.n);
		g_load.p                        = NULL;
		g_load.n                        = 0;
		g_load.collision_materials      = NULL;
		g_load.rendered_vertices        = NULL;
		g_load.surfs                    = NULL;
		g_load.coll_surfs               = NULL;
		g_load.coll_edges               = NULL;
		g_load.coll_vertices            = NULL;
		g_load.lightmaps                = NULL;
		g_load.scenario_scenery         = NULL;
		g_load.scenario_scenery_palette = NULL;
	}

	return true;
}

void CL_ShutdownMap(void) {
	CL_UnloadMap();
	DB_UnloadMap_Mmap(&g_load.bitmaps_map);
	A_memset((void*)&g_load, 0, sizeof(g_load));
}

bool CL_IsMapLoaded(void) {
	return g_load.f.f && g_load.p && g_load.n > 0;
}

bool CL_BitmapDataFormatIsCompressed(BSPBitmapDataFormat format) {
	switch (format) {
	case BSP_BITMAP_DATA_FORMAT_DXT1:
	case BSP_BITMAP_DATA_FORMAT_DXT3:
	case BSP_BITMAP_DATA_FORMAT_DXT5:
	case BSP_BITMAP_DATA_FORMAT_BC7:
		return true;
	default:
		return false;
	};
}

Tag* CL_Map_Tag(TagId id) {
	assert(g_load.tags);
	if (id.index >= g_load.tag_count)
		Com_DPrintln(CON_DEST_CLIENT, "invalid tag (%d > g_load.tag_count %u)",
			id.index, g_load.tag_count);
	assert(id.index < g_load.tag_count);
	return &g_load.tags[id.index];
}

BSPSurf* CL_Map_Surfs(void) {
	assert(g_load.surfs);
	return g_load.surfs;
}

uint32_t CL_Map_SurfCount(void) {
	assert(g_load.surfs);
	return g_load.surf_count;
}

BSPRenderedVertex* CL_Map_RenderedVertices(void) {
	assert(g_load.rendered_vertices);
	return g_load.rendered_vertices;
}

BSPLightmapVertex* CL_Map_LightmapVertices(void) {
	assert(g_load.lightmap_vertices);
	return g_load.lightmap_vertices;
}

BSPCollSurf* CL_Map_CollSurfs(void) {
	assert(g_load.coll_surfs);
	return g_load.coll_surfs;
}

uint32_t CL_Map_CollSurfCount(void) {
	assert(g_load.coll_surfs);
	return g_load.coll_surf_count;
}

BSPCollEdge* CL_Map_CollEdges(void) {
	assert(g_load.coll_edges);
	return g_load.coll_edges;
}

uint32_t CL_Map_CollEdgeCount(void) {
	assert(g_load.coll_edges);
	return g_load.coll_edge_count;
}

BSPCollVertex* CL_Map_CollVertices(void) {
	assert(g_load.coll_vertices);
	return g_load.coll_vertices;
}

uint32_t CL_Map_CollVertexCount(void) {
	assert(g_load.coll_vertices);
	return g_load.coll_vertex_count;
}

A_EXTERN_C BSPCollisionMaterial* CL_Map_CollisionMaterial(uint16_t i) {
	assert(g_load.collision_materials);
	assert(i < BSP_MAX_COLLISION_MATERIALS);
	return &g_load.collision_materials[i];
}

BSPLightmap* CL_Map_Lightmap(uint16_t i) {
	assert(g_load.lightmaps);
	assert(i < g_load.lightmap_count);
	return &g_load.lightmaps[i];
}

uint32_t CL_Map_LightmapCount(void) {
	assert(g_load.lightmaps);
	return g_load.lightmap_count;
}

BSPScenarioScenery* CL_Map_ScenarioScenery(uint16_t i) {
	assert(g_load.scenario_scenery);
	assert(i < g_load.scenario_scenery_count);
	return &g_load.scenario_scenery[i];
}

uint32_t CL_Map_ScenarioSceneryCount(void) {
	assert(g_load.scenario_scenery);
	return g_load.scenario_scenery_count;
}

BSPScenarioSceneryPalette* CL_Map_ScenarioSceneryPalette(uint16_t i) {
	assert(g_load.scenario_scenery_palette);
	assert(i < g_load.scenario_scenery_palette_count);
	return &g_load.scenario_scenery_palette[i];
}

uint32_t CL_Map_ScenarioSceneryPaletteCount(void) {
	assert(g_load.scenario_scenery_palette);
	return g_load.scenario_scenery_palette_count;
}


#define CL_DECOMPRESS_FLOAT_SIGN_BIT(bits) (1 << ((bits) - 1))
#define CL_DECOMPRESS_FLOAT_MASK(bits) (CL_DECOMPRESS_FLOAT_SIGN_BIT(bits) - 1)
#define CL_DECOMPRESS_FLOAT(f, bits) (                         \
(float)(                                                       \
	((f) & CL_DECOMPRESS_FLOAT_MASK(bits)) /                   \
		   CL_DECOMPRESS_FLOAT_MASK(bits)                      \
) * ((f) & CL_DECOMPRESS_FLOAT_SIGN_BIT(bits) ? -1.0f : 1.0f)) 

static void CL_DecompressVector(A_OUT avec3f_t* decompressed, uint32_t compressed) {
	// uint32_t compressed_x = compressed >> 0;
	uint32_t compressed_y = compressed >> 11;
	uint32_t compressed_z = compressed >> 22;

	decompressed->x = CL_DECOMPRESS_FLOAT(compressed, 11);
	decompressed->y = CL_DECOMPRESS_FLOAT(compressed_y, 11);
	decompressed->z = CL_DECOMPRESS_FLOAT(compressed_z, 10);

	*decompressed = A_vec3f_normalize(*decompressed);
}

static void CL_DecompressRenderedVertex(
	A_OUT BSPRenderedVertex* decompressed,
	const BSPRenderedVertexCompressed* compressed
) {
	decompressed->pos = compressed->pos;
	decompressed->tex_coords = compressed->tex_coords;
	CL_DecompressVector(&decompressed->normal, compressed->normal);
	CL_DecompressVector(&decompressed->binormal, compressed->binormal);
	CL_DecompressVector(&decompressed->tangent, compressed->tangent);
}

static void CL_DecompressLightmapVertex(
	A_OUT BSPLightmapVertex* decompressed,
	const BSPLightmapVertexCompressed* compressed
) {
	CL_DecompressVector(&decompressed->normal, compressed->normal);
	decompressed->tex_coords = compressed->tex_coords;
}

static bool CL_LoadMap_Header(A_OUT MapHeader* header) {
	long long pos = FS_SeekStream(&g_load.f, FS_SEEK_BEGIN, 0);
	assert(pos == 0);
	(void)pos;
	if (!FS_ReadStream(&g_load.f, header, sizeof(*header)))
		Com_Errorln(-1, "CL_LoadMap: Read failed.");

	if ((uint32_t)header->head_magic != MAP_HEADER_HEAD)
		Com_Errorln(-1, "CL_LoadMap: Invalid header head magic.");

	if ((uint32_t)header->foot_magic != MAP_HEADER_FOOT)
		Com_Errorln(-1, "CL_LoadMap: Invalid header foot magic.");
	return true;
}

static bool CL_LoadMap_Decompress(
	const char* map_name,
	const MapHeader* header
) {
	const std::string decompressed_map_name = std::string("decompressed_") + std::string(map_name);
	if (!FS_FileExists(decompressed_map_name.data())) {
		FileMapping f = DB_LoadMap_Mmap(map_name);
		size_t decompressed_map_size =
			(size_t)header->decompressed_file_size;
		void* decompressed = Z_Zalloc(decompressed_map_size);
		A_memcpy(decompressed, header, sizeof(*header));

		z_stream stream;
		stream.zalloc    = Z_NULL;
		stream.zfree     = Z_NULL;
		stream.opaque    = Z_NULL;
		stream.avail_in  = f.n - sizeof(*header);
		stream.next_in   = (Bytef*)f.p + sizeof(*header);
		stream.avail_out = decompressed_map_size - sizeof(*header);
		stream.next_out  = (Bytef*)decompressed + sizeof(*header);

		int ret = inflateInit(&stream);
		assert(ret == Z_OK);
		ret = inflate(&stream, Z_FINISH);
		assert(ret == Z_STREAM_END);
		ret = inflateEnd(&stream);
		assert(ret == Z_OK);

		Com_DPrintln(CON_DEST_CLIENT,
			"CL_LoadMap: Decompressed %lu bytes (%d %s), expected %zu.",
			stream.total_out, ret, stream.msg ? stream.msg : "<NULL>",
			decompressed_map_size - sizeof(header));
		StreamFile decompressed_map = FS_StreamFile(
			decompressed_map_name.data(), FS_SEEK_BEGIN,
			FS_STREAM_READ_WRITE_NEW, 0
		);
		assert(decompressed_map.f);
		
		bool b = FS_WriteStream(&decompressed_map, decompressed, decompressed_map_size);
		assert(b);
		FS_CloseStream(&g_load.f);
		g_load.f = decompressed_map;
		Z_Free(decompressed);
		b = Z_UnmapFile(&f);
		assert(b);
	}
	else {
		g_load.f = FS_StreamFile(
			decompressed_map_name.data(), FS_SEEK_BEGIN,
			FS_STREAM_READ_EXISTING, 0
		);
		assert(g_load.f.f);
	}

	return true;
}

static bool CL_LoadMap_TagHeader(
	const MapHeader* header, bool is_xbox,
	A_OUT TagHeader* tag_header
) {
	size_t tag_data_offset = header->tag_data_offset;
	Com_DPrintln(CON_DEST_CLIENT,
		"CL_LoadMap: tag data: offset=0x%08X, size=%u",
		tag_data_offset, header->tag_data_size
	);

	long long pos = FS_SeekStream(&g_load.f, FS_SEEK_BEGIN, tag_data_offset);
	assert(pos == (long long)tag_data_offset);
	(void)pos;

	if (is_xbox) {
		if (!FS_ReadStream(&g_load.f, &tag_header->xbox, sizeof(tag_header->xbox)))
			Com_Errorln(-1, "CL_LoadMap: Failed to load tag header.");

		if (tag_header->xbox.magic != TAGS_FOOT)
			Com_Errorln(-1, "CL_LoadMap: Invalid tag header.");
	}
	else {
		if (!FS_ReadStream(&g_load.f, &tag_header->pc, sizeof(tag_header->pc)))
			Com_Errorln(-1, "CL_LoadMap: Failed to load tag header.");

		if (tag_header->pc.magic != TAGS_FOOT)
			Com_Errorln(-1, "CL_LoadMap: Invalid tag header.");
	}
	return true;
}

static bool CL_LoadMap_TagData(
	const MapHeader* header,
	const TagHeader* tag_header,
	bool is_xbox
) {
	const void* tag_base = is_xbox ?
		(const void*)TAGS_BASE_ADDR_XBOX : 
			(const void*)TAGS_BASE_ADDR_GEARBOX;
	size_t total_tag_space = is_xbox ?
		TAGS_MAX_SIZE_XBOX : TAGS_MAX_SIZE_GEARBOX;
	uint32_t tag_array_offset =
		(uint32_t)((intptr_t)tag_header->common.tag_ptr - (intptr_t)tag_base);
	Com_DPrintln(CON_DEST_CLIENT, "CL_LoadMap: tag_array_offset=0x%08X", tag_array_offset);
	size_t tag_header_size = is_xbox ?
		sizeof(tag_header->xbox) : sizeof(tag_header->pc);
	uint32_t off = tag_array_offset - tag_header_size;
	FS_SeekStream(&g_load.f, FS_SEEK_CUR, off);
	Com_DPrintln(CON_DEST_CLIENT, "CL_LoadMap: allocating %zu bytes for tag data.",
		total_tag_space);
	g_load.n = total_tag_space;
	g_load.p = Z_AllocAt(tag_base, g_load.n);
	assert(g_load.p == tag_base);
	A_memcpy(g_load.p, tag_header, tag_header_size);
	bool b = FS_ReadStream(&g_load.f, (char*)g_load.p + tag_header_size, (size_t)header->tag_data_size);
	assert(b);
	(void)b;
	
	g_load.tags = (Tag*)tag_header->common.tag_ptr;
	g_load.tag_count = tag_header->common.tag_count;
	return true;
}

static bool CL_LoadMap_Scenario(
	const TagHeader* tag_header,
	A_OUT Invader::HEK::Scenario<Invader::HEK::NativeEndian>** scenario
) {
	Tag* scenario_tag = NULL;
	for (size_t i = 0; i < tag_header->common.tag_count; i++) {
		if (g_load.tags[i].tag_id.id ==
			tag_header->common.scenario_tag_id.id
			) {
			scenario_tag = &g_load.tags[i];
			break;
		}
	}

	if (scenario_tag == NULL)
		Com_Errorln(-1, "CL_LoadMap: Unable to locate scenario tag.");

	if (scenario_tag->primary_class != TAG_FOURCC_SCENARIO) {
		Com_Errorln(-1,
			"CL_LoadMap: Invalid scenario tag fourcc (%u).",
			(uint32_t)scenario_tag->primary_class
		);
	}

	*scenario = (Invader::HEK::Scenario<Invader::HEK::NativeEndian>*)scenario_tag->tag_data;

	if (!*scenario)
		Com_Errorln(-1, "CL_LoadMap: NULL scenario pointer.");

	Com_DPrintln(CON_DEST_CLIENT, "CL_LoadMap: Scenario at %p", *scenario);

	return true;
}

static bool CL_LoadMap_BSPHeader(const ScenarioBSP* sbsp,
								 A_OUT BSPHeader** bsp_header
) {
	long long pos = FS_SeekStream(&g_load.f, FS_SEEK_BEGIN, sbsp->bsp_start);
	assert(pos == sbsp->bsp_start);
	(void)pos;
	*bsp_header = (BSPHeader*)sbsp->bsp_address;
	bool b = FS_ReadStream(&g_load.f, *bsp_header, sizeof(**bsp_header));
	assert(b);
	(void)b;
	assert((*bsp_header)->pointer);

	void* bsp_data = (void*)sbsp->bsp_address;
	Com_DPrintln(CON_DEST_CLIENT,
		"CL_LoadMap: BSP at %p (offset=0x%08X, size=%zu)",
		bsp_data, sbsp->bsp_start, sbsp->bsp_size
	);

	if ((uint32_t)(*bsp_header)->magic != TAG_FOURCC_SBSP)
		Com_Errorln(-1, "CL_LoadMap: Invalid signature for BSP header.");

	if ((*bsp_header)->lightmap_vertices == 0 ||
		(*bsp_header)->rendered_vertices == 0
	) {
		Com_Errorln(-1, "CL_LoadMap: BSP has no renderable vertices.");
	}

	return true;
}

static bool CL_LoadMap_BSP(
	const ScenarioBSP* sbsp,
	const BSPHeader* bsp_header,
	A_OUT Invader::HEK::ScenarioStructureBSP<Invader::HEK::NativeEndian>** bsp
) {
	void* bsp_data = (void*)(sbsp->bsp_address + sizeof(*bsp_header));
	bool b = FS_ReadStream(&g_load.f, bsp_data, sbsp->bsp_size - sizeof(*bsp_header));
	assert(b);
	(void)b;

	*bsp = (Invader::HEK::ScenarioStructureBSP<Invader::HEK::NativeEndian>*)bsp_header->pointer;

	if ((uint32_t)(*bsp)->lightmaps_bitmap.tag_fourcc != TAG_FOURCC_BITMAP) {
		Com_Errorln(-1,
			"CL_LoadMap: Invalid lightmaps bitmap fourcc (0x%08X).",
			(uint32_t)(*bsp)->lightmaps_bitmap.tag_fourcc
		);
	}

	return true;
}

static bool CL_LoadMap_CBSBVertices(
	const Invader::HEK::ModelCollisionGeometryBSP<Invader::HEK::NativeEndian>* cbsp,
	A_OUT Invader::HEK::ModelCollisionGeometryBSPVertex<Invader::HEK::NativeEndian>** vertices
) {
	*vertices =
		(Invader::HEK::ModelCollisionGeometryBSPVertex<Invader::HEK::NativeEndian>*)
		((uint32_t)cbsp->vertices.pointer);
	uint32_t coll_vertices_count = cbsp->vertices.count.read();
	Com_DPrintln(CON_DEST_CLIENT, "CBSP has %u vertices (%p).", coll_vertices_count, vertices);
	return true;
}

static bool CL_LoadMap_CBSP(
	const Invader::HEK::ScenarioStructureBSP< Invader::HEK::NativeEndian>* bsp,
	A_OUT Invader::HEK::ModelCollisionGeometryBSPVertex<Invader::HEK::NativeEndian>** vertices,
	A_OUT Invader::HEK::ModelCollisionGeometryBSP<Invader::HEK::NativeEndian>** cbsp
) {
	uint32_t cbsp_count = bsp->collision_bsp.count.read();
	if (bsp->collision_bsp.count.read() > 1)
		Com_Errorln(-1, "CL_LoadMap: More than one collision BSP (%u).", cbsp_count);

	if (bsp->collision_bsp.count.read() < 1)
		Com_Errorln(-1, "CL_LoadMap: No collision BSPs.");

	*cbsp =
		(Invader::HEK::ModelCollisionGeometryBSP<Invader::HEK::NativeEndian>*)
		((uint32_t)bsp->collision_bsp.pointer.read());

	if (!CL_LoadMap_CBSBVertices(*cbsp, vertices)) return false;
	return true;
}

static bool CL_LoadMap_CollisionMaterials(
	const Invader::HEK::ScenarioStructureBSP<Invader::HEK::NativeEndian>* bsp,
	A_OUT BSPCollisionMaterial** collision_materials
) {
	*collision_materials =
		(BSPCollisionMaterial*)bsp->collision_materials.pointer.read();
	uint32_t collision_materials_count = bsp->collision_materials.count;
	assert(collision_materials_count < BSP_MAX_COLLISION_MATERIALS);
	(void)collision_materials_count;
	return true;
}

static size_t CL_BitmapDataSize(const BSPBitmapData* bitmap_data) {
	assert(bitmap_data->type == BSP_BITMAP_DATA_TYPE_2D_TEXTURE ||
		bitmap_data->type == BSP_BITMAP_DATA_TYPE_3D_TEXTURE);

	if (bitmap_data->type == BSP_BITMAP_DATA_TYPE_2D_TEXTURE)
		assert(bitmap_data->depth == 1);

	size_t bpp = CL_BitmapDataFormatBPP((BSPBitmapDataFormat)bitmap_data->format);

	size_t size = (bitmap_data->width * bitmap_data->height * bitmap_data->depth * bpp) / 8;
	if (bitmap_data->format == BSP_BITMAP_DATA_FORMAT_DXT1 && size == 8192 && bitmap_data->width == 256)
		__debugbreak();
	assert(A_IS_MULTIPLE_OF(size, 8));
	return size;
}

static bool CL_LoadMap_Bitmap(TagId tag_id) {
	Tag* bitmap_tag = CL_Map_Tag(tag_id);
	assert(bitmap_tag);
	assert(bitmap_tag->primary_class == TAG_FOURCC_BITMAP);

	BSPBitmap* bitmap = (BSPBitmap*)bitmap_tag->tag_data;
	assert(bitmap);

	BSPBitmapData* bitmap_data = (BSPBitmapData*)bitmap->bitmap_data.pointer;
	for (uint32_t i = 0; i < bitmap->bitmap_data.count; i++) {
		bitmap_data[i].pixels = NULL;

		if (bitmap_data[i].type != BSP_BITMAP_DATA_TYPE_2D_TEXTURE &&
			bitmap_data[i].type != BSP_BITMAP_DATA_TYPE_3D_TEXTURE
			) {
			continue;
		}

		bitmap_data[i].actual_size = CL_BitmapDataSize(&bitmap_data[i]);
		assert(bitmap_data[i].actual_size < 4 * 1024 * 1024);
		bitmap_data[i].pixels = Z_Alloc(bitmap_data[i].actual_size);
		assert(bitmap_data[i].pixels);
		long long pos = FS_SeekStream(&g_load.f, FS_SEEK_BEGIN, bitmap_data[i].pixel_data_offset);
		assert(pos == bitmap_data[i].pixel_data_offset);
		(void)pos;

		bool b = FS_ReadStream(&g_load.f, bitmap_data[i].pixels, bitmap_data[i].actual_size);
		assert(b);
		(void)b;
	}
	return true;
}

static bool CL_LoadMap_Sky(TagId id) {
	Tag* sky_tag = CL_Map_Tag(id);
	assert(sky_tag->primary_class == TAG_FOURCC_SKY);
	BSPSky* sky = (BSPSky*)sky_tag->tag_data;
	if (sky->model.id.index != 0xFFFF)
		return CL_LoadMap_Model(sky->model.id);
	return true;
}

static void CL_DecompressModelVertex(
	const BSPModelCompressedVertex* compressed,
	A_OUT BSPModelDecompressedVertex* decompressed
) {
	decompressed->position = compressed->position;
	CL_DecompressVector(&decompressed->normal, compressed->normal);
	CL_DecompressVector(&decompressed->binormal, compressed->binormal);
	CL_DecompressVector(&decompressed->tangent, compressed->tangent);
	decompressed->texcoords.u = compressed->texcoords.u;
	decompressed->texcoords.v = compressed->texcoords.v;
	decompressed->node0_index = compressed->node0_index;
	decompressed->node1_index = compressed->node1_index;
	decompressed->node0_weight = compressed->node0_weight;
	decompressed->node1_weight = compressed->node0_weight;
}

static bool CL_LoadMap_ShaderEnvironment(BSPShaderEnvironment* shader) {
	assert(shader);
	bool b = CL_LoadMap_Bitmap(shader->base_map.id);
	assert(b);
	if (shader->primary_detail_map.id.index != 0xFFFF)
		b = CL_LoadMap_Bitmap(shader->primary_detail_map.id);
	assert(b);
	if (shader->secondary_detail_map.id.index != 0xFFFF)
		b = CL_LoadMap_Bitmap(shader->secondary_detail_map.id);
	assert(b);
	if (shader->micro_detail_map.id.index != 0xFFFF)
		b = CL_LoadMap_Bitmap(shader->micro_detail_map.id);
	assert(b);
	if (shader->bump_map.id.index != 0xFFFF)
		b = CL_LoadMap_Bitmap(shader->bump_map.id);
	assert(b);
	if (shader->map.id.index != 0xFFFF)
		b = CL_LoadMap_Bitmap(shader->map.id);
	assert(b);
	return b;
}

static bool CL_LoadMap_ShaderModel(BSPShaderModel* shader) {
	assert(shader);
	bool b = CL_LoadMap_Bitmap(shader->base_map.id);
	assert(b);
	if (shader->multipurpose_map.id.index != 0xFFFF)
		b = CL_LoadMap_Bitmap(shader->multipurpose_map.id);
	assert(b);
	if (shader->detail_map.id.index != 0xFFFF)
		b = CL_LoadMap_Bitmap(shader->detail_map.id);
	assert(b);
	return b;
}

static bool CL_LoadMap_Shader(TagId shader_id) {
	if (shader_id.id == 0)
		return true;

	Tag* shader_tag = CL_Map_Tag(shader_id);
	assert(shader_tag);
	assert(shader_tag->secondary_class == TAG_FOURCC_SHADER);
	bool b = true;
	switch (shader_tag->primary_class) {
	case TAG_FOURCC_SHADER_ENVIRONMENT:
		b = CL_LoadMap_ShaderEnvironment((BSPShaderEnvironment*)shader_tag->tag_data);
		assert(b);
		break;
	case TAG_FOURCC_SHADER_MODEL:
		b = CL_LoadMap_ShaderModel((BSPShaderModel*)shader_tag->tag_data);
		assert(b);
		break;
	}
	return b;
}

static bool CL_LoadMap_Model(TagId id) {
	Tag* model_tag = CL_Map_Tag(id);
	assert(model_tag->primary_class == TAG_FOURCC_MODEL);
	BSPModel* model = (BSPModel*)model_tag->tag_data;
	BSPModelGeometry* geoms = (BSPModelGeometry*)model->geometries.pointer;
	for (int i = 0; i < model->geometries.count; i++) {
		BSPModelGeometry* geom = &geoms[i];
		BSPModelGeometryPart* parts = 
			(BSPModelGeometryPart*)geom->parts.pointer;
		for (int j = 0; j < geom->parts.count; j++) {
			BSPModelGeometryPart* part = &parts[j];
			BSPModelDecompressedVertex* decompressed_verts = NULL;
			assert(part->vertex_type == BSP_VERTEX_TYPE_COMPRESSED_MODEL);
			decompressed_verts = (BSPModelDecompressedVertex*)
				Z_Alloc(part->tri_count * sizeof(*decompressed_verts));
			uint16_t* tri_indices = (uint16_t*)part->tri_offset;
			assert(decompressed_verts);
			for (int k = 0; k < part->tri_count; k++) {
				const BSPModelCompressedVertex* compressed_vert = &g_load.model_vertices[tri_indices[k]];
				BSPModelDecompressedVertex* decompressed_vert = &decompressed_verts[k];
				CL_DecompressModelVertex(compressed_vert, decompressed_vert);
			}
			part->decompressed_vertices.pointer = decompressed_verts;
			part->decompressed_vertices.count = part->tri_count;
		}
	}

	TagDependency* shader_dependencies = (TagDependency*)model->shaders.pointer;
	bool b = true;
	for (int i = 0; i < model->shaders.count; i++) {
		TagDependency* shader_dependency = &shader_dependencies[i];
		b = CL_LoadMap_Shader(shader_dependency->id);
		assert(b);
	}
	return true;
}

static bool CL_LoadMap_Object(TagId id) {
	Tag* object_tag = CL_Map_Tag(id);
	assert(object_tag->secondary_class == TAG_FOURCC_OBJECT);
	BSPObject* object = (BSPObject*)object_tag->tag_data;
	return CL_LoadMap_Model(object->model.id);
}

size_t CL_BitmapDataFormatBPP(BSPBitmapDataFormat format) {
	switch (format) {
	case BSP_BITMAP_DATA_FORMAT_A8R8G8B8:
	case BSP_BITMAP_DATA_FORMAT_X8R8G8B8:
		return 32;
	case BSP_BITMAP_DATA_FORMAT_R5G6B5:
	case BSP_BITMAP_DATA_FORMAT_A1R5G5B5:
	case BSP_BITMAP_DATA_FORMAT_A4R4G4B4:
	case BSP_BITMAP_DATA_FORMAT_A8Y8:
		return 16;
	case BSP_BITMAP_DATA_FORMAT_P8_BUMP:
	case BSP_BITMAP_DATA_FORMAT_A8:
	case BSP_BITMAP_DATA_FORMAT_AY8:
	case BSP_BITMAP_DATA_FORMAT_Y8:
	case BSP_BITMAP_DATA_FORMAT_DXT5:
	case BSP_BITMAP_DATA_FORMAT_DXT3:
	case BSP_BITMAP_DATA_FORMAT_BC7:
		return 8;
	case BSP_BITMAP_DATA_FORMAT_DXT1:
		return 4;
	default:
		assert(false);
		return 0;
	}
}
