#include "cl_client.hpp"

#include <cassert>

#include "acommon/a_format.hpp"
#include "acommon/z_mem.h"

#include "cg_cgame.hpp"
#include "db_files.hpp"
#include "dvar.hpp"
#include "gfx.hpp"
#include "gfx_text.hpp"
#include "in_input.hpp"

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
	StreamFile  f;
	std::string map_name;
	void* p;
	size_t      n;
	BSPSurf* surfs;
	uint32_t    surf_count;
	BSPEdge* edges;
	uint32_t    edge_count;
	BSPVertex* vertices;
	uint32_t    vertex_count;
} g_load;

void CL_Init() {
	A_memset((void*)&g_load, 0, sizeof(g_load));

	cl_splitscreen = &Dvar_RegisterBool("cl_splitscreen", DVAR_FLAG_NONE, false);

	for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
		cl_t& cl = CL_GetLocalClientGlobals(i);
		cl.drawfps = Dvar_RegisterLocalBool(i, "cl_drawfps", DVAR_FLAG_NONE, false);
		CL_GetLocalClientLocals(i).drawDevGui = false;
		CL_SetKeyFocus(i, KF_GAME);
		RectDef rect = { .x = 0.985f, .y = 0.99f, .w = 0.0498f, .h = 0.0498f };
		bool b = R_AddTextDraw(
			i, NULL, rect,
			A_Format("FPS: {:.0f}", 1000.0f / s_lastFpsDrawDelta),
			0.5f, 0.5f,
			glm::vec3(0.5, 0.8f, 0.2f), Dvar_GetBool(*cl.drawfps), true,
			CL_GetLocalClientLocals(i).fpsTextDrawId
		);
		assert(b);
	}

	CL_GiveKbmFocus(0);
	
	bool b = CL_LoadMap("c40.map");
	assert(b);
}

void CL_EnableFpsCounter(size_t localClientNum, bool enable) {
	Dvar_SetBool(*CL_GetLocalClientGlobals(localClientNum).drawfps, enable);
}

void CL_DrawFps(size_t localClientNum) {
	R_UpdateTextDraw(
		localClientNum, CL_GetLocalClientLocals(localClientNum).fpsTextDrawId,
		A_Format("FPS: {:.0f}", 1000.0f / (float)s_lastFpsDrawDelta)
	);
}

void CL_Frame() {
	for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
		cl_t&  cl  = CL_GetLocalClientGlobals(i);
		cll_t& cll = CL_GetLocalClientLocals(i);
		R_ActivateTextDraw(i, cll.fpsTextDrawId, Dvar_GetBool(*cl.drawfps));

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

/*
struct BSP3DNode {
	uint32_t plane, back_child, front_child;
};

struct BSPLeaf {
	uint16_t ref_count;
	uint32_t first_ref;
};

struct BSP2DRef {
	uint32_t plane, bsp2d_node;
};

struct BSP2DNode {
	glm::vec3 plane;
	uint32_t left_child, right_child;
};
*/

bool CL_LoadMap(std::string_view map_name) {
	g_load.f = DB_LoadMap(map_name);
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

	if (header.engine != Invader::HEK::CacheFileEngine::CACHE_FILE_RETAIL) {
		Com_Errorln("CL_LoadMap: Wrong engine version.");
		return false;
	}

	size_t tag_data_size = header.tag_data_size;
	size_t tag_data_offset = header.tag_data_offset;

	FS_SeekStream(g_load.f, FS_SEEK_BEGIN, tag_data_offset);
	Invader::HEK::CacheFileTagDataHeaderPC tag_header;
	if (!FS_ReadStream(g_load.f, tag_header)) {
		Com_Errorln("CL_LoadMap: Failed to load tag header.");
		return false;
	}

	if (tag_header.tags_literal != Invader::HEK::CacheFileLiteral::CACHE_FILE_TAGS) {
		Com_Errorln("CL_LoadMap: Invalid tag header.");
		return false;
	}

	uint32_t tag_array_offset = tag_header.tag_array_address - 0x40440000;
	uint32_t off = tag_array_offset - sizeof(tag_header);
	FS_SeekStream(g_load.f, FS_SEEK_CUR, off);
	auto v = FS_ReadStream(g_load.f, tag_data_size);
	g_load.n = 23 * 1024 * 1024;
	g_load.p = Z_AllocAt((void*)0x40440000, g_load.n);
	A_memcpy((void*)((intptr_t)g_load.p + (intptr_t)sizeof(tag_header) + (intptr_t)off), v.data(), v.size());
	A_memcpy(g_load.p, &tag_header, sizeof(tag_header));

	Invader::HEK::CacheFileTagDataTag* tags = (Invader::HEK::CacheFileTagDataTag*)(tag_header.tag_array_address.read());
	uint32_t scenario_id = tag_header.scenario_tag.read().index;

	Invader::HEK::CacheFileTagDataTag* scenario_tag = NULL;
	for (size_t i = 0; i < tag_header.tag_count; i++) {
		if (tags[i].tag_id.read().index == scenario_id) {
			scenario_tag = &tags[i];
			break;
		}
	}

	if (scenario_tag == NULL) {
		Com_Errorln("CL_LoadMap: Unable to locate scenario tag.");
		return false;
	}

	if (scenario_tag->primary_class != Invader::HEK::TagFourCC::TAG_FOURCC_SCENARIO) {
		Com_Errorln("CL_LoadMap: Invalid scenario tag fourcc ({}).", (uint32_t)scenario_tag->primary_class.read());
		return false;
	}

	Invader::HEK::Scenario<Invader::HEK::NativeEndian>* scenario_ptr = (Invader::HEK::Scenario<Invader::HEK::NativeEndian>*)scenario_tag->tag_data.read();
	
	if (!scenario_ptr) {
		Com_Errorln("CL_LoadMap: NULL scenario pointer.");
		return false;
	}

	Invader::HEK::ScenarioBSP<Invader::HEK::NativeEndian>* sbsp_ptr = (Invader::HEK::ScenarioBSP<Invader::HEK::NativeEndian>*)scenario_ptr->structure_bsps.pointer.read();
	size_t bsp_size = sbsp_ptr->bsp_size.read();
	size_t bsp_start = sbsp_ptr->bsp_start.read();
	FS_SeekStream(g_load.f, FS_SEEK_BEGIN, bsp_start);
	Invader::HEK::ScenarioStructureBSPCompiledHeader<Invader::HEK::NativeEndian> bsp_header;
	if (!FS_ReadStream(g_load.f, bsp_header)) {
		Com_Errorln("CL_LoadMap: Failed to read BSP header.");
		return false;
	}

	if (bsp_header.signature != Invader::HEK::TagFourCC::TAG_FOURCC_SCENARIO_STRUCTURE_BSP) {
		Com_Errorln("CL_LoadMap: Invalid signature for BSP header.");
		return false;
	}

	v = FS_ReadStream(g_load.f, bsp_size - sizeof(bsp_header));
	Invader::HEK::ScenarioStructureBSP<Invader::HEK::NativeEndian>* bsp_ptr = (Invader::HEK::ScenarioStructureBSP<Invader::HEK::NativeEndian>*)(sbsp_ptr->bsp_address.read() + sizeof(bsp_header));
	A_memcpy(bsp_ptr, v.data(), v.size());

	if (bsp_ptr->lightmaps_bitmap.tag_fourcc != Invader::HEK::TagFourCC::TAG_FOURCC_BITMAP) {
		Com_Errorln("CL_LoadMap: Invalid lightmaps bitmap fourcc ({}).", (uint32_t)bsp_ptr->lightmaps_bitmap.tag_fourcc.read());
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

	// why are we off by 24? sizeof(bsp_header) == 24, so that could be a hint
	Invader::HEK::ModelCollisionGeometryBSP<Invader::HEK::NativeEndian>* cbsp = (Invader::HEK::ModelCollisionGeometryBSP<Invader::HEK::NativeEndian>*)((uint32_t)bsp_ptr->collision_bsp.pointer.read());
	Com_DPrintln("3d nodes: {} ({})\nplanes: {} ({})\nleaves: {} ({})\n2d refs: {} ({})\n2d nodes: {} ({})\nsurfs: {} ({})\nedges: {} ({})\nverts: {} ({})",
		(void*)(uint32_t)cbsp->bsp3d_nodes.pointer.read(),	    (uint32_t)cbsp->bsp3d_nodes.count.read(),
		(void*)(uint32_t)cbsp->planes.pointer.read(),			(uint32_t)cbsp->planes.count.read(),
		(void*)(uint32_t)cbsp->leaves.pointer.read(),			(uint32_t)cbsp->leaves.count.read(),
		(void*)(uint32_t)cbsp->bsp2d_references.pointer.read(), (uint32_t)cbsp->bsp2d_references.count.read(),
		(void*)(uint32_t)cbsp->bsp2d_nodes.pointer.read(),	    (uint32_t)cbsp->bsp2d_nodes.count.read(),
		(void*)(uint32_t)cbsp->surfaces.pointer.read(),		    (uint32_t)cbsp->surfaces.count.read(),
		(void*)(uint32_t)cbsp->edges.pointer.read(),			(uint32_t)cbsp->edges.count.read(),
		(void*)(uint32_t)cbsp->vertices.pointer.read(),		    (uint32_t)cbsp->vertices.count.read()
	);
	Invader::HEK::ModelCollisionGeometryBSPVertex<Invader::HEK::NativeEndian>* vertices = (Invader::HEK::ModelCollisionGeometryBSPVertex<Invader::HEK::NativeEndian>*)((uint32_t)cbsp->vertices.pointer);
	uint32_t vertices_count = cbsp->vertices.count.read();
	Com_DPrintln("CBSP has {} vertices ({}).", vertices_count, (void*)vertices);

	g_load.surfs        = (BSPSurf*)(uint32_t)cbsp->surfaces.pointer.read();
	g_load.surf_count   = cbsp->surfaces.count;
	g_load.edges        = (BSPEdge*)(uint32_t)cbsp->edges.pointer.read();
	g_load.edge_count   = cbsp->edges.count;
	g_load.vertices     = (BSPVertex*)vertices;
	g_load.vertex_count = cbsp->vertices.count;


	R_LoadMap();
	return true;
}

BSPSurf* CL_Map_Surfs() {
	assert(g_load.surfs);
	return g_load.surfs;
}

uint32_t CL_Map_SurfCount() {
	assert(g_load.surfs);
	return g_load.surf_count;
}

BSPEdge* CL_Map_Edges() {
	assert(g_load.edges);
	return g_load.edges;
}

uint32_t CL_Map_EdgeCount() {
	assert(g_load.edges);
	return g_load.edge_count;
}

BSPVertex* CL_Map_Vertices() {
	assert(g_load.vertices);
	return g_load.vertices;
}

uint32_t CL_Map_VertexCount() {
	assert(g_load.vertices);
	return g_load.vertex_count;
}

bool CL_UnloadMap() {
	R_UnloadMap();

	if (g_load.f.f)
		FS_CloseStream(g_load.f);

	if (g_load.p && g_load.n > 0) {
		Z_FreeAt(g_load.p, g_load.n);
		g_load.p		= NULL;
		g_load.n		= 0;
		g_load.surfs	= NULL;
		g_load.edges	= NULL;
		g_load.vertices = NULL;
	}

	return true;
}

bool CL_IsMapLoaded() {
	return g_load.f.f && g_load.p && g_load.n > 0;
}

void CL_Shutdown() {
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
