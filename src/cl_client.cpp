#include "cl_client.hpp"

#include <cassert>

#include <zlib.h>

#include "acommon/a_format.hpp"
#include "acommon/z_mem.h"

#include "cg_cgame.hpp"
#include "db_files.hpp"
#include "dvar.hpp"
#include "gfx.hpp"
#include "gfx_text.hpp"
#include "in_input.hpp"

#define BSP_MAX_COLLISION_MATERIALS 512

BSPTag* CL_Map_Tag(BSPTagId id);

struct cll_t {
	KeyFocus keyfocus    = KF_GAME;
	bool drawDevGui      = false;
	size_t fpsTextDrawId = (size_t)-1;
};

std::array<cll_t, MAX_LOCAL_CLIENTS> s_cll;
struct cl_t {
	dvar_t* drawfps  = NULL;
	bool hasKbmFocus = false;
};

std::array<cl_t, MAX_LOCAL_CLIENTS> s_cl;

dvar_t* cl_splitscreen = NULL;

static uint64_t s_lastFpsDrawTime;
static uint64_t s_lastFpsDrawDelta;

cll_t& CL_GetLocalClientLocals(size_t localClientNum) {
	return s_cll.at(localClientNum);
}

cl_t& CL_GetLocalClientGlobals(size_t localClientNum) {
	return s_cl.at(localClientNum);
}

struct MapLoadData {
	StreamFile  		  f;
	std::string 		  map_name;
	void*       		  p;
	size_t      		  n;
	FileMapping           bitmaps_map;

	BSPTag*               tags;
	uint32_t              tag_count;
	BSPSurf*              surfs;
	uint32_t              surf_count;
	BSPRenderedVertex*    rendered_vertices;
	BSPLightmapVertex*    lightmap_vertices;
	BSPCollSurf*    	  coll_surfs;
	uint32_t    		  coll_surf_count;
	BSPCollEdge*    	  coll_edges;
	uint32_t    		  coll_edge_count;
	BSPCollVertex*  	  coll_vertices;
	uint32_t    		  coll_vertex_count;
	BSPCollisionMaterial* collision_materials;
} g_load;

void CL_Init() {
	A_memset((void*)&g_load, 0, sizeof(g_load));
	g_load.bitmaps_map = DB_LoadMap_Mmap("bitmaps.map");
	assert(g_load.bitmaps_map.p && g_load.bitmaps_map.n > 0);
	Com_DPrintln(
		"CL_Init: Successfully mapped bitmaps.map at 0x{:08X} ({} bytes)",
		(size_t)g_load.bitmaps_map.p, g_load.bitmaps_map.n
	);

	cl_splitscreen = &Dvar_RegisterBool("cl_splitscreen", DVAR_FLAG_NONE, false);

	for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
		cl_t& cl = CL_GetLocalClientGlobals(i);
		cl.drawfps = Dvar_RegisterLocalBool(i, "cl_drawfps", DVAR_FLAG_NONE, false);
		CL_GetLocalClientLocals(i).drawDevGui = false;
		CL_SetKeyFocus(i, KF_GAME);
		RectDef rect = { .x = 0.985f, .y = 0.99f, .w = 0.0498f, .h = 0.0498f };
		bool b = R_AddTextDrawDef(
			i, NULL, rect,
			A_Format("FPS: {:.0f}", 1000.0f / s_lastFpsDrawDelta),
			0.5f, 0.5f,
			glm::vec3(0.5, 0.8f, 0.2f), Dvar_GetBool(*cl.drawfps), true,
			CL_GetLocalClientLocals(i).fpsTextDrawId
		);
		assert(b);
	}

	CL_GiveKbmFocus(0);
	
	bool b = CL_LoadMap("c40_xbox.map");
	assert(b);
}

void CL_EnableFpsCounter(size_t localClientNum, bool enable) {
	Dvar_SetBool(*CL_GetLocalClientGlobals(localClientNum).drawfps, enable);
}

void CL_DrawFps(size_t localClientNum) {
	R_UpdateTextDrawDef(
		localClientNum, CL_GetLocalClientLocals(localClientNum).fpsTextDrawId,
		A_Format("FPS: {:.0f}", 1000.0f / (float)s_lastFpsDrawDelta)
	);
}

void CL_Frame() {
	for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
		cl_t&  cl  = CL_GetLocalClientGlobals(i);
		cll_t& cll = CL_GetLocalClientLocals(i);
		R_ActivateTextDrawDef(i, cll.fpsTextDrawId, Dvar_GetBool(*cl.drawfps));

		// Updating the FPS counter too often makes it flicker
		if (Sys_Milliseconds() - s_lastFpsDrawTime > 40) {
			s_lastFpsDrawTime  = Sys_Milliseconds();
			s_lastFpsDrawDelta = Com_LastFrameTimeDelta();
		}

		if (Dvar_GetBool(*cl.drawfps))
			CL_DrawFps(i);

		cll.drawDevGui = IN_Key_IsToggled(i, SDLK_BACKQUOTE);
		if (cll.drawDevGui)
			CL_SetKeyFocus(i, KF_DEVGUI);
		else
			CL_SetKeyFocus(i, KF_GAME);
	}	
} 

void CL_EnterSplitscreen(size_t activeLocalClient) {
	cg_t& cg0 = CG_GetLocalClientGlobals(0);

	cg0.viewport.x = 0.0f;
	cg0.viewport.y = 0.5f;
	cg0.viewport.w = 1.0f;
	cg0.viewport.h = 0.5f;

	float w0 = cg0.viewport.w * Dvar_GetInt(*vid_width);
	float h0 = cg0.viewport.h * Dvar_GetInt(*vid_height);
	cg0.fovy = FOV_HORZ_TO_VERTICAL(Dvar_GetFloat(*cg0.fov), h0 / w0);

	cg_t& cg1 = CG_GetLocalClientGlobals(1);

	cg1.viewport.x = 0.0f;
	cg1.viewport.y = 0.0f;
	cg1.viewport.w = 1.0f;
	cg1.viewport.h = 0.5f;

	float w1 = cg1.viewport.w * Dvar_GetInt(*vid_width);
	float h1 = cg1.viewport.h * Dvar_GetInt(*vid_height);
	cg1.fovy = FOV_HORZ_TO_VERTICAL(Dvar_GetFloat(*cg1.fov), h1 / w1);

	if (activeLocalClient != 0)
		CG_ActivateLocalClient(0);
	if (activeLocalClient != 1)
		CG_ActivateLocalClient(1);
}

void CL_LeaveSplitscreen(size_t activeLocalClient) {
	for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
		cg_t& cg = CG_GetLocalClientGlobals(i);
		cg.viewport.x = 0.0f;
		cg.viewport.y = 0.0f;
		cg.viewport.w = 1.0f;
		cg.viewport.h = 1.0f;

		float w = cg.viewport.w * Dvar_GetInt(*vid_width);
		float h = cg.viewport.h * Dvar_GetInt(*vid_height);
		cg.fovy = FOV_HORZ_TO_VERTICAL(Dvar_GetFloat(*cg.fov), h / w);

		if (i != activeLocalClient)
			CG_DectivateLocalClient(i);
	}
}


void CL_GiveKbmFocus(size_t localClientNum) {
	for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++)
		CL_GetLocalClientGlobals(i).hasKbmFocus = i == localClientNum;
}

bool CL_HasKbmFocus(size_t localClientNum) {
	return CL_GetLocalClientGlobals(localClientNum).hasKbmFocus;
}

size_t CL_ClientWithKbmFocus() {
	for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
		if (CL_HasKbmFocus(i))
			return i;
	}

	assert(false);
	return (size_t)-1;
}

KeyFocus CL_KeyFocus(size_t localClientNum) {
	return CG_GetLocalClientGlobals(localClientNum).keyfocus;
}

void CL_SetKeyFocus(size_t localClientNum, KeyFocus f) {
	CG_GetLocalClientGlobals(localClientNum).keyfocus = f;
}

// static const void* CL_BitmapOffsetToPointer(size_t off) {
// 	assert(g_load.bitmaps_map.p);
// 	assert(g_load.bitmaps_map.n >= off);

// 	return (const void*)((const char*)g_load.bitmaps_map.p + off);
// }

bool CL_LoadMap(std::string_view map_name) {
	g_load.f = DB_LoadMap_Stream(map_name);
	if (g_load.f.f == NULL) {
		return false;
	}

	Invader::HEK::CacheFileHeader header;
	if (!FS_ReadStream(g_load.f, header)) {
		Com_Errorln("CL_LoadMap: Read failed.");
		return false;
	}

	if (header.head_literal != Invader::HEK::CacheFileLiteral::CACHE_FILE_HEAD) {
		Com_Errorln("CL_LoadMap: Invalid header head literal.");
		return false;
	}

	if (header.foot_literal != Invader::HEK::CacheFileLiteral::CACHE_FILE_FOOT) {
		Com_Errorln("CL_LoadMap: Invalid header foot literal.");
		return false;
	}

	bool b = true;
	size_t n = (size_t)header.decompressed_file_size.read();
	if (header.engine != Invader::HEK::CacheFileEngine::CACHE_FILE_RETAIL) {
		if (header.engine != Invader::HEK::CacheFileEngine::CACHE_FILE_XBOX) {
			Com_Errorln("CL_LoadMap: Wrong engine version.");
			return false;
		}

		const std::string decompressed_map_name = std::string("decompressed_") + std::string(map_name);
		if (!FS_FileExists(decompressed_map_name.data())) {
			FileMapping f = DB_LoadMap_Mmap(map_name);
			void* decompressed = Z_Zalloc(n - sizeof(header));

			z_stream stream;
			stream.zalloc    = Z_NULL;
            stream.zfree     = Z_NULL;
            stream.opaque    = Z_NULL;
            stream.avail_in  = f.n - sizeof(header);
            stream.next_in   = (Bytef*)f.p + sizeof(header);
            stream.avail_out = n - sizeof(header);
            stream.next_out  = (Bytef*)decompressed;
			int ret = inflateInit(&stream);
			assert(ret == Z_OK);
			ret = inflate(&stream, Z_FINISH);
			assert(ret == Z_STREAM_END);
			ret = inflateEnd(&stream);
			assert(ret == Z_OK);

			Com_DPrintln(
				"CL_LoadMap: Decompressed {} bytes ({} {}), expected {}.", 
				stream.total_out, ret, stream.msg ? stream.msg : "<NULL>", 
				n - sizeof(header));
			StreamFile decompressed_map = FS_StreamFile(
				decompressed_map_name.data(), FS_SEEK_BEGIN, 
				FS_STREAM_READ_WRITE_NEW, 0
			);
			assert(decompressed_map.f);
			b = FS_WriteStream(decompressed_map, header);
			assert(b);
			b = FS_WriteStream(decompressed_map, decompressed, n - sizeof(header));
			assert(b);
			FS_CloseStream(g_load.f);
			g_load.f = decompressed_map;
			b = Z_UnmapFile(&f);
			assert(b);
		} else {
			g_load.f = FS_StreamFile(
				decompressed_map_name.data(), FS_SEEK_BEGIN, 
				FS_STREAM_READ_EXISTING, 0
			);
		 	assert(g_load.f.f);
		}
	}

	size_t tag_data_size = header.tag_data_size;
	size_t tag_data_offset = header.tag_data_offset;
	Com_DPrintln("CL_LoadMap: tag_data_offset=0x{:08X}", tag_data_offset);

	b = FS_SeekStream(g_load.f, FS_SEEK_BEGIN, tag_data_offset);
	assert(b);
	BSPTagHeader tag_header = {};
	if (header.engine == Invader::HEK::CacheFileEngine::CACHE_FILE_XBOX) {
		if (!FS_ReadStream(g_load.f, tag_header.xbox)) {
			Com_Errorln("CL_LoadMap: Failed to load tag header.");
			return false;
		}

		if (tag_header.xbox.magic != BSP_TAGS_FOOT) {
			Com_Errorln("CL_LoadMap: Invalid tag header.");
			return false;
		}
	} else {
		if (!FS_ReadStream(g_load.f, tag_header.pc)) {
			Com_Errorln("CL_LoadMap: Failed to load tag header.");
			return false;
		}

		if (tag_header.pc.magic != BSP_TAGS_FOOT) {
			Com_Errorln("CL_LoadMap: Invalid tag header.");
			return false;
		}
	}
	

	const void* tag_base = header.engine == Invader::HEK::CacheFileEngine::CACHE_FILE_RETAIL ? 
		(const void*)0x40440000 : (const void*)0x803A6000;
	uint32_t tag_array_offset = tag_header.common.tag_ptr - (uint32_t)tag_base;
	Com_DPrintln("CL_LoadMap: tag_array_offset=0x{:08X}", tag_array_offset);
	const size_t tag_header_size = header.engine == Invader::HEK::CacheFileEngine::CACHE_FILE_XBOX ?
		sizeof(tag_header.xbox) : sizeof(tag_header.pc); 
	uint32_t off = tag_array_offset - tag_header_size;
	FS_SeekStream(g_load.f, FS_SEEK_CUR, off);
	std::vector<std::byte> v = FS_ReadStream(g_load.f, tag_data_size);
	assert(v.size() > 0);
	Com_DPrintln("CL_LoadMap: allocating {} bytes for decompressed map.", n);
	g_load.n = n;
	g_load.p = Z_AllocAt(tag_base, g_load.n);
	assert(g_load.p == tag_base);
	A_memcpy((void*)((intptr_t)g_load.p + (intptr_t)tag_header_size + (intptr_t)off), v.data(), v.size());
	A_memcpy(g_load.p, &tag_header, tag_header_size);

	g_load.tags          = (BSPTag*)tag_header.common.tag_ptr;
	g_load.tag_count     = tag_header.common.tag_count;
	if(header.engine == Invader::HEK::CacheFileEngine::CACHE_FILE_XBOX) {
		Com_DPrintln(
			"CL_LoadMap: map contains {} tags, vertex data=0x{:08X}, tri data=0x{:08X}",
			tag_header.common.tag_count, tag_header.xbox.vertex_data_ptr, tag_header.xbox.triangle_data_ptr
		);
	}
	

	BSPTag* scenario_tag = NULL;
	for (size_t i = 0; i < tag_header.common.tag_count; i++) {
		if (g_load.tags[i].tag_id.id == tag_header.common.scenario_tag_id.id) {
			scenario_tag = &g_load.tags[i];
			break;
		}
	}

	if (scenario_tag == NULL) {
		Com_Errorln("CL_LoadMap: Unable to locate scenario tag.");
		return false;
	}

	if (scenario_tag->primary_class != Invader::HEK::TagFourCC::TAG_FOURCC_SCENARIO) {
		Com_Errorln(
			"CL_LoadMap: Invalid scenario tag fourcc ({}).", 
			scenario_tag->primary_class
		);
		return false;
	}

	Invader::HEK::Scenario<Invader::HEK::NativeEndian>* scenario_ptr = 
		(Invader::HEK::Scenario<Invader::HEK::NativeEndian>*)
			scenario_tag->tag_data;
	
	if (!scenario_ptr) {
		Com_Errorln("CL_LoadMap: NULL scenario pointer.");
		return false;
	}

	Com_DPrintln("CL_LoadMap: Scenario at 0x{:08X}", (uint32_t)scenario_ptr);

	size_t bsp_size = 0;
	size_t bsp_start = 0;
	Invader::HEK::ScenarioBSP<Invader::HEK::NativeEndian>* sbsps_ptr = 
		(Invader::HEK::ScenarioBSP<Invader::HEK::NativeEndian>*)
			scenario_ptr->structure_bsps.pointer.read();
	Invader::HEK::ScenarioBSP<Invader::HEK::NativeEndian>* sbsp_ptr = sbsps_ptr;
	int sbsp_idx = 0;
	Invader::HEK::ScenarioStructureBSPCompiledHeader<Invader::HEK::NativeEndian> bsp_header;
	bool found = false;
	for(; sbsp_idx < scenario_ptr->structure_bsps.count.read(); sbsp_idx++) {
		sbsp_ptr = &sbsps_ptr[sbsp_idx];
		bsp_size = sbsp_ptr->bsp_size.read();
		bsp_start = sbsp_ptr->bsp_start.read();
		// Invader::HEK::ScenarioStructureBSPCompiledHeader<Invader::HEK::NativeEndian>* bsp_header =
		// 	(Invader::HEK::ScenarioStructureBSPCompiledHeader<Invader::HEK::NativeEndian>*)((char*)tag_base + bsp_start);
		// Com_DPrintln("CL_LoadMap: BSP ptr=0x{:08X}, offset=0x{:08X}, size={}", (uint32_t)bsp_header, bsp_start, bsp_size);
		// assert(bsp_header->signature == A_MAKE_FOURCC('s', 'b', 's', 'p'));
		// Invader::HEK::ScenarioStructureBSP<Invader::HEK::NativeEndian>* bsp_ptr = 
		// 	(Invader::HEK::ScenarioStructureBSP<Invader::HEK::NativeEndian>*)bsp_header->pointer.read();
		b = FS_SeekStream(g_load.f, FS_SEEK_BEGIN, bsp_start);
		assert(b);
		
		if (!FS_ReadStream(g_load.f, bsp_header)) {
			Com_Errorln("CL_LoadMap: Failed to read BSP header.");
			return false;
		}

		if (bsp_header.signature != Invader::HEK::TagFourCC::TAG_FOURCC_SCENARIO_STRUCTURE_BSP) {
			Com_Errorln("CL_LoadMap: Invalid signature for BSP header.");
			return false;
		}

		if (bsp_header.lightmap_vertices.read() != 0 || bsp_header.rendered_vertices.read() != 0) {
			found = true;
			break;
		}
	}
	
	if (header.engine == Invader::HEK::CacheFileEngine::CACHE_FILE_XBOX) {
		if (found) {
			Com_DPrintln(
				"CL_LoadMap: Found SBSP ({}) at 0x{:08X} with lightmap vertices (0x{:08X})",
				sbsp_idx, bsp_header.pointer.read(), (uint32_t)bsp_header.lightmap_vertices.read()
			);
		}
		else {
			Com_Errorln("CL_LoadMap: Map has no lightmap vertices.");
		}
	}

	v = FS_ReadStream(g_load.f, bsp_size - sizeof(bsp_header));
	void* bsp_data = (void*)sbsps_ptr->bsp_address.read();
	A_memcpy(bsp_data, (const void*)&bsp_header, sizeof(bsp_header));
	A_memcpy((void*)((char*)bsp_data + sizeof(bsp_header)), v.data(), v.size());
	Invader::HEK::ScenarioStructureBSP<Invader::HEK::NativeEndian>* bsp_ptr = 
		(Invader::HEK::ScenarioStructureBSP<Invader::HEK::NativeEndian>*)bsp_header.pointer.read();
	Com_DPrintln("CL_LoadMap: BSP begin=0x{:08X}, offset=0x{:08X}, size={}, ptr=0x{:08X}", (uint32_t)bsp_data, bsp_start, bsp_size, (uint32_t)bsp_ptr);

	if (bsp_ptr->lightmaps_bitmap.tag_fourcc != Invader::HEK::TagFourCC::TAG_FOURCC_BITMAP) {
		Com_Errorln("CL_LoadMap: Invalid lightmaps bitmap fourcc (0x{:08X}).", (uint32_t)bsp_ptr->lightmaps_bitmap.tag_fourcc.read());
		return false;
	}

	uint32_t cbsp_count = bsp_ptr->collision_bsp.count.read();
	if (bsp_ptr->collision_bsp.count.read() > 1) {
		Com_Errorln("CL_LoadMap: More than one collision BSP ({}).", cbsp_count);
		return false;
	}

	if (bsp_ptr->collision_bsp.count.read() < 1) {
		Com_Errorln("CL_LoadMap: No collision BSPs.");
		return false;
	}

	Com_DPrintln("CL_LoadMap: found BSP with rendered vertices at 0x{:08X}", (uint32_t)bsp_header.rendered_vertices.read());

	Invader::HEK::ModelCollisionGeometryBSP<Invader::HEK::NativeEndian>* cbsp = 
		(Invader::HEK::ModelCollisionGeometryBSP<Invader::HEK::NativeEndian>*)
			((uint32_t)bsp_ptr->collision_bsp.pointer.read());
	Com_DPrintln(
		"3d nodes: {} ({})\nplanes: {} ({})\nleaves: {} ({})\n2d refs: {} ({})\n2d nodes: {} ({})\nsurfs: {} ({})\nedges: {} ({})\nverts: {} ({})",
		(void*)(uint32_t)cbsp->bsp3d_nodes.pointer.read(),	    
		(uint32_t)cbsp->bsp3d_nodes.count.read(),
		(void*)(uint32_t)cbsp->planes.pointer.read(),			
		(uint32_t)cbsp->planes.count.read(),
		(void*)(uint32_t)cbsp->leaves.pointer.read(),			
		(uint32_t)cbsp->leaves.count.read(),
		(void*)(uint32_t)cbsp->bsp2d_references.pointer.read(), 
		(uint32_t)cbsp->bsp2d_references.count.read(),
		(void*)(uint32_t)cbsp->bsp2d_nodes.pointer.read(),	    
		(uint32_t)cbsp->bsp2d_nodes.count.read(),
		(void*)(uint32_t)cbsp->surfaces.pointer.read(),		    
		(uint32_t)cbsp->surfaces.count.read(),
		(void*)(uint32_t)cbsp->edges.pointer.read(),			
		(uint32_t)cbsp->edges.count.read(),
		(void*)(uint32_t)cbsp->vertices.pointer.read(),		    
		(uint32_t)cbsp->vertices.count.read()
	);
	Invader::HEK::ModelCollisionGeometryBSPVertex<Invader::HEK::NativeEndian>* vertices = 
		(Invader::HEK::ModelCollisionGeometryBSPVertex<Invader::HEK::NativeEndian>*)
			((uint32_t)cbsp->vertices.pointer);
	uint32_t vertices_count = cbsp->vertices.count.read();
	Com_DPrintln("CBSP has {} vertices ({}).", vertices_count, (void*)vertices);

	BSPCollisionMaterial* collision_materials = 
		(BSPCollisionMaterial*)bsp_ptr->collision_materials.pointer.read();
	uint32_t collision_materials_count = bsp_ptr->collision_materials.count;
	assert(collision_materials_count < BSP_MAX_COLLISION_MATERIALS);
	Com_DPrintln(
		"collision_materials=0x{:08X}, count={}", 
		bsp_ptr->collision_materials.pointer.read(), 
		collision_materials_count
	);
	for(int i = 0; i < collision_materials_count; i++) {
		BSPCollisionMaterial* mat = &collision_materials[i];
		const char* path = (const char*)mat->shader.path_pointer;
		const char* type = BSPMaterialType_to_string(mat->material);
		Com_DPrintln(
			"Collision Material {}: type={}, fourcc=0x{:08X}, path={}", 
			i, type ? type : "<INVALID>", mat->shader.fourcc, path ? path : "<NULL>"
		);
	}

	g_load.rendered_vertices   = (BSPRenderedVertex*)(uint32_t)bsp_header.rendered_vertices.read();
	g_load.lightmap_vertices   = (BSPLightmapVertex*)(uint32_t)bsp_header.lightmap_vertices.read();
	g_load.surfs               = (BSPSurf*)(uint32_t)bsp_ptr->surfaces.pointer.read();
	g_load.surf_count          = bsp_ptr->surfaces.count.read();
	g_load.coll_surfs          = (BSPCollSurf*)(uint32_t)cbsp->surfaces.pointer.read();
	g_load.coll_surf_count     = cbsp->surfaces.count;
	g_load.coll_edges          = (BSPCollEdge*)(uint32_t)cbsp->edges.pointer.read();
	g_load.coll_edge_count     = cbsp->edges.count;
	g_load.coll_vertices       = (BSPCollVertex*)vertices;
	g_load.coll_vertex_count   = cbsp->vertices.count;
	g_load.collision_materials = collision_materials;
	g_load.tag_count           = tag_header.common.tag_count;

	Invader::HEK::ScenarioStructureBSPLightmap<Invader::HEK::NativeEndian>* lightmaps =
		(Invader::HEK::ScenarioStructureBSPLightmap<Invader::HEK::NativeEndian>*)bsp_ptr->lightmaps.pointer.read();
	for(uint32_t i = 0; i < bsp_ptr->lightmaps.count; i++) {
		Invader::HEK::ScenarioStructureBSPLightmap<Invader::HEK::NativeEndian>* lightmap = &lightmaps[i];
		Invader::HEK::ScenarioStructureBSPMaterial<Invader::HEK::NativeEndian>* materials =
			(Invader::HEK::ScenarioStructureBSPMaterial<Invader::HEK::NativeEndian>*)lightmap->materials.pointer.read();
		for(uint32_t j = 0; j < lightmap->materials.count; j++) {
			Invader::HEK::ScenarioStructureBSPMaterial<Invader::HEK::NativeEndian>* material = &materials[j];
			BSPTagId shader_id = BSPTagId { .id = material->shader.tag_id.read().id };
			if(shader_id.index == 0xFFFF)
					continue;
			BSPTag* shader_tag = CL_Map_Tag(shader_id);
			const char* shader_path = (const char *)shader_tag->tag_path;
			assert(shader_tag);
			assert(shader_path);
			Com_DPrintln(
				"Lightmap {} Material {} (0x{:08X}, 0x{:08X}, 0x{:08X}): {} (0x{:08X}), rendered vertices: type={}, count={}, offset=0x{:08X}, lightmap vertices: type={}, count={}, offset=0x{:08X}", i, j,
				shader_tag->primary_class, shader_tag->secondary_class,
				shader_tag->tertiary_class, shader_path,
				shader_tag->tag_data, 
				(uint16_t)material->rendered_vertices_type.read(), 
				(uint32_t)material->rendered_vertices_count.read(),
				(uint32_t)material->rendered_vertices_offset.read(),
				(uint16_t)material->lightmap_vertices_type.read(), 
				(uint32_t)material->lightmap_vertices_count.read(),
				(uint32_t)material->lightmap_vertices_offset.read()
			);
			//assert((uint16_t)material->rendered_vertices_type.read() == 0);
			//assert((uint16_t)material->lightmap_vertices_type.read() == 0);

			assert(shader_tag->tag_data);
			if(shader_tag->primary_class == A_MAKE_FOURCC('s', 'c', 'n', 'r'))
				continue;
			assert(shader_tag->secondary_class == A_MAKE_FOURCC('s', 'h', 'd', 'r'));
			if (shader_tag->primary_class == A_MAKE_FOURCC('s', 'e', 'n', 'v')) {
				BSPShaderEnvironment* shader = (BSPShaderEnvironment*)shader_tag->tag_data;
				BSPTagId tag_id = BSPTagId { .id = shader_tag->tag_id.id };

				// const char* base_map_path = (const char*)shader->base_map.path_pointer;
				// Com_DPrintln(
				// 	"{} ({}): base_map: {} (0x{:08X})", shader_path, tag_id.index,
				// 	base_map_path ? base_map_path : "<NULL>", shader->base_map.fourcc
				// );
				tag_id = shader->base_map.id;
				if(tag_id.index == 0xFFFF)
					continue;
				BSPTag* base_map_tag = CL_Map_Tag(tag_id);
				assert(base_map_tag->primary_class == A_MAKE_FOURCC('b', 'i', 't', 'm'));

				// Com_DPrintln(
				// 	"{}: base_map tag: primary_group=0x{:08X}, secondary_group=0x{:08X}, tertiary_group=0x{:08X}, data=0x{:08X}, external={}",
				// 	shader_path, base_map_tag->primary_class, base_map_tag->secondary_class,
				// 	base_map_tag->tertiary_class, base_map_tag->tag_data, base_map_tag->external
				// );

				// BSPBitmap* base_map_bitmap = (BSPBitmap*)base_map_tag->tag_data;

				// tag_id = base_map_tag->tag_id;
				// Com_DPrintln(
				// 	"{} ({}): Found {} bitmap data.", 
				// 	base_map_path, tag_id.index, base_map_bitmap->bitmap_data.count
				// );
				// BSPBitmapData* bitmap_data = (BSPBitmapData*)base_map_bitmap->bitmap_data.pointer;
				// for (uint32_t k = 0; k < base_map_bitmap->bitmap_data.count; k++) {
				// 	// const void* pixels = CL_BitmapOffsetToPointer((size_t)bitmap_data[k].pixel_data_offset);
				// 	// Com_DPrintln(
				// 	// 	"Lightmap {} Material {} Bitmap Data {}: class=0x{:08X}, type={}, width={}, height={}, depth={}, format={}, pixel_data_size={}, pixels=0x{:08X} (offset=0x{:08X})", i, j, k,
				// 	// 	bitmap_data[k].klass,
				// 	// 	BSPBitmapDataType_to_string(bitmap_data[k].type),
				// 	// 	bitmap_data[k].width, bitmap_data[k].height, bitmap_data[k].depth, 
				// 	// 	BSPBitmapDataFormat_to_string(bitmap_data[k].format),
				// 	// 	bitmap_data[k].pixel_data_size, (size_t)pixels, 
				// 	// 	bitmap_data[k].pixel_data_offset
				// 	// );
				// }
			}
		}
	}

	R_LoadMap();
	return true;
}

BSPTag* CL_Map_Tag(BSPTagId id) {
	assert(g_load.tags);
	if(id.index >= g_load.tag_count)
		Com_DPrintln("invalid tag ({} > g_load.tag_count {})", id.index, g_load.tag_count);
	assert(id.index < g_load.tag_count);
	return &g_load.tags[id.index];
}

BSPSurf* CL_Map_Surfs() {
	assert(g_load.surfs);
	return g_load.surfs;
}

uint32_t CL_Map_SurfCount() {
	assert(g_load.surfs);
	return g_load.surf_count;
}

BSPRenderedVertex* CL_Map_RenderedVertices() {
	assert(g_load.rendered_vertices);
	return g_load.rendered_vertices;
}

BSPLightmapVertex* CL_Map_LightmapVertices() {
	assert(g_load.lightmap_vertices);
	return g_load.lightmap_vertices;
}

BSPCollSurf* CL_Map_CollSurfs() {
	assert(g_load.coll_surfs);
	return g_load.coll_surfs;
}

uint32_t CL_Map_CollSurfCount() {
	assert(g_load.coll_surfs);
	return g_load.coll_surf_count;
}

BSPCollEdge* CL_Map_CollEdges() {
	assert(g_load.coll_edges);
	return g_load.coll_edges;
}

uint32_t CL_Map_CollEdgeCount() {
	assert(g_load.coll_edges);
	return g_load.coll_edge_count;
}

BSPCollVertex* CL_Map_CollVertices() {
	assert(g_load.coll_vertices);
	return g_load.coll_vertices;
}

uint32_t CL_Map_CollVertexCount() {
	assert(g_load.coll_vertices);
	return g_load.coll_vertex_count;
}

BSPCollisionMaterial* CL_Map_CollisionMaterial(uint16_t i) {
	assert(g_load.collision_materials);
	assert(i < BSP_MAX_COLLISION_MATERIALS);
	return &g_load.collision_materials[i];
}

bool CL_UnloadMap() {
	R_UnloadMap();

	if (g_load.f.f)
		FS_CloseStream(g_load.f);

	if (g_load.p && g_load.n > 0) {
		Z_FreeAt(g_load.p, g_load.n);
		g_load.p			       = NULL;
		g_load.n			       = 0;
		g_load.collision_materials = NULL;
		g_load.rendered_vertices   = NULL;
		g_load.surfs               = NULL;
		g_load.coll_surfs	       = NULL;
		g_load.coll_edges	       = NULL;
		g_load.coll_vertices       = NULL;
	}

	return true;
}

bool CL_IsMapLoaded() {
	return g_load.f.f && g_load.p && g_load.n > 0;
}

void CL_Shutdown() {
	Z_UnmapFile(&g_load.bitmaps_map);
	A_memset((void*)&g_load, 0, sizeof(g_load));
	CL_UnloadMap();

	Dvar_SetBool(*cl_splitscreen, false);
	Dvar_Unregister("cl_splitscreen");
	cl_splitscreen = NULL;

	for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
		cl_t& cl = CL_GetLocalClientGlobals(i);
		Dvar_SetBool(*cl.drawfps, false);
		Dvar_UnregisterLocal(i, "cl_drawfps");
		cl.drawfps = NULL;

		cll_t& cll = CL_GetLocalClientLocals(i);
		cll.drawDevGui = false;
		cll.keyfocus = KF_GAME;
	}
}
