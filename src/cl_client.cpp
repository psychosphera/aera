#include "cl_client.hpp"

#include <cassert>

#include "acommon/a_format.hpp"

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

void CL_Init() {
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

struct TagData {
	uint32_t primary_fourcc, secondary_fourcc, tertiary_fourcc;
	std::string path;
	uint32_t id;
	uint32_t data_offset;
};

struct ScenarioData {
	uint32_t sbsps_offset;
	uint32_t sbsp_count;
};

struct LoadData {
	StreamFile stream;
	uint32_t base_mem_addr;
	uint32_t tag_data_offset;
	uint32_t tag_data_size;
	uint32_t tag_array_address;
	std::vector<TagData> tag_data;
	ScenarioData scenario_data;
	std::vector<Invader::HEK::ScenarioStructureBSP<Invader::HEK::NativeEndian>> sbsps;
} g_load;

static constexpr size_t GEARBOX_BASE_MEMORY_ADDRESS = 0x40440000;

bool CL_Map_Seek_Offset(size_t off) {
	return FS_SeekStream(g_load.stream, FS_SEEK_BEGIN, off) != -1;
}

bool CL_Map_Seek_Pointer(uint32_t ptr) {
	return FS_SeekStream(g_load.stream, FS_SEEK_BEGIN, ptr - g_load.base_mem_addr) != -1;
}

bool CL_Map_Seek_TagPointer(uint32_t ptr) {
	return FS_SeekStream(g_load.stream, FS_SEEK_BEGIN, ptr - g_load.base_mem_addr + g_load.tag_data_offset) != -1;
}

template<typename T>
bool CL_Map_Read(T& t) {
	return FS_ReadStream(g_load.stream, t);
}

bool CL_LoadMap_Header() {
	Invader::HEK::CacheFileHeader header;
	bool b = CL_Map_Read(header);
	assert(b);
	if (header.head_literal != Invader::HEK::CacheFileLiteral::CACHE_FILE_HEAD ||
		header.foot_literal != Invader::HEK::CacheFileLiteral::CACHE_FILE_FOOT
	) {
		Com_Errorln("CL_LoadMap: Bad header magic (map is probably either corrupt or\
			not a Halo 1 map.");
	}

	if (
		header.engine == Invader::HEK::CacheFileEngine::CACHE_FILE_MCC_CEA
	) {
		Com_Errorln("CL_LoadMap: Refusing to load a CEA map.");
	}
	else if (
		header.engine == Invader::HEK::CacheFileEngine::CACHE_FILE_DEMO
	) {
		Com_Errorln("CL_LoadMap: Refusing to load a demo map\
						 (may be implemented later).");
	}
	else if (
		header.engine ==
			Invader::HEK::CacheFileEngine::CACHE_FILE_CUSTOM_EDITION
	) {
		Com_Errorln("CL_LoadMap: Refusing to load a Custom Edition\
						 map (may be implemented later).");
	}
	else if(
		header.engine != Invader::HEK::CacheFileEngine::CACHE_FILE_RETAIL
	) {
		Com_Errorln("CL_LoadMap: Bad engine version\
						(map is either corrupt or for a later Halo game.");
	}

	g_load.base_mem_addr = GEARBOX_BASE_MEMORY_ADDRESS;

	if (header.tag_data_offset.read() == 0 || header.tag_data_size.read() == 0)
		Com_Errorln("CL_LoadMap: corrupted or missing tag data.");
	

	if (header.map_type >=
		Invader::HEK::CacheFileType::SCENARIO_TYPE_ENUM_COUNT
	) {
		Com_Errorln("CL_LoadMap: bad map type ({})", (int)header.map_type);
	}

	g_load.tag_data_offset = header.tag_data_offset.read();
	g_load.tag_data_size   = header.tag_data_size.read();
	return true;
}

bool CL_LoadMap_TagData() {
	Invader::HEK::CacheFileTagDataHeaderPC tag_data;
	if (CL_Map_Read(tag_data) == false)
		Com_Errorln("CL_LoadMap: Couldn't read tag data.");
	
	if(tag_data.tags_literal != Invader::HEK::CacheFileLiteral::CACHE_FILE_TAGS)
		Com_Errorln("CL_LoadMap: Bad tag data magic (map is probably corrupt).");

	uint32_t tag_count = tag_data.tag_count.read();
	g_load.tag_data.reserve((size_t)tag_count);
	
	uint32_t tag_array_address = tag_data.tag_array_address.read();
	if(!CL_Map_Seek_TagPointer(tag_array_address))
		Com_Errorln("CL_LoadMap: Couldn't read tag data.");

	g_load.tag_array_address = tag_array_address;

	for (int i = 0; i < (int)tag_count; i++) {
		Invader::HEK::CacheFileTagDataTag tag;
		if(!CL_Map_Read(tag))
			Com_Errorln("CL_LoadMap: Couldn't read tag {}.", i);

		TagData d;
		d.id = tag.tag_id.read().id;
		if (tag.tag_id.read().is_null() || tag.tag_data.read() == 0)
			continue;

		d.data_offset = tag.tag_data.read();
		d.primary_fourcc = tag.primary_class.read();
		d.secondary_fourcc = tag.secondary_class.read();
		d.tertiary_fourcc = tag.tertiary_class.read();

		if (tag.tag_path.read() != 0x00000000) {
			size_t pos = FS_StreamPos(g_load.stream);
			if (!CL_Map_Seek_TagPointer(tag.tag_path.read()))
				Com_Errorln("CL_LoadMap: Couldn't read tag path.");
			if (!CL_Map_Read(d.path))
				Com_Errorln("CL_LoadMap: Couldn't read tag path.");
			if (!CL_Map_Seek_Offset(pos))
				Com_Errorln("CL_LoadMap: Couldn't read tag path.");
		}
		g_load.tag_data.push_back(d);

		//Com_Println(CON_DEST_CLIENT, "Loaded tag {}.\n", d.path);
	}
	return true;
}

bool CL_LoadMap_Scenario() {
	Invader::HEK::Scenario<Invader::HEK::NativeEndian> scenario;
	if (!CL_Map_Read(scenario))
		Com_Errorln("CL_LoadMap: Failed to read scenario.");

	g_load.scenario_data = { 
		.sbsps_offset = (uint32_t)scenario.structure_bsps.pointer, 
		.sbsp_count = scenario.structure_bsps.count 
	};

	return true;
}

bool CL_LoadMap_SBSPs() {
	Invader::HEK::ScenarioStructureBSP<Invader::HEK::NativeEndian> sbsp;
	for (uint32_t i = 0; i < g_load.scenario_data.sbsp_count; i++) {
		if (!CL_Map_Read(sbsp))
			Com_Errorln("CL_LoadMap: Failed to read SBSP {}", i);
		g_load.sbsps.push_back(sbsp);
	}
	return true;
}

bool CL_LoadMap(std::string_view map_name) {
	StreamFile f = DB_LoadMap(map_name);
	size_t pos = FS_StreamPos(f);
	if(pos == (size_t)-1)
		Com_Errorln("CL_LoadMap: Failed to open {}.", map_name);

	g_load.stream = f;
	if (!CL_LoadMap_Header())
		Com_Errorln("CL_LoadMap: Failed to load header.");
	if (!CL_Map_Seek_Offset(g_load.tag_data_offset))
		Com_Errorln("CL_LoadMap: Couldn't seek to tag data.");
	if (!CL_LoadMap_TagData())
		Com_Errorln("CL_LoadMap: Couldn't load tag data.");

	const TagData* scenario = NULL;
	for (const auto& tag : g_load.tag_data) {
		if (tag.primary_fourcc == Invader::HEK::TAG_FOURCC_SCENARIO) {
			scenario = &tag;
			break;
		}
	}

	if (!CL_Map_Seek_TagPointer(scenario->data_offset))
		Com_Errorln("CL_LoadMap: Couldn't seek to scenario.");

	if(!CL_LoadMap_Scenario())
		Com_Errorln("CL_LoadMap: Couldn't load scenario.");

	if (!CL_Map_Seek_TagPointer(g_load.scenario_data.sbsps_offset))
		Com_Errorln("CL_LoadMap: Couldn't seek to SBSPs.");

	if (!CL_LoadMap_SBSPs())
		Com_Errorln("CL_LoadMap: Couldn't load SBSPs.");

	return true;
}

void CL_Shutdown() {
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
