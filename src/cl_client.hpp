#pragma once

#include <string_view>

#include <glm/glm.hpp>

#include "fs_files.hpp"

enum KeyFocus {
	KF_DEVGUI,
	KF_GAME,
};

struct BSPSurf {
	uint32_t plane, first_edge;
	uint8_t  flags;
	int8_t   breakable_surface;
	uint16_t material;
};

struct BSPEdge {
	uint32_t start_vert, end_vert;
	uint32_t forward_edge, reverse_edge;
	uint32_t left_surf, right_surf;
};

struct BSPVertex {
	glm::vec3 point;
	uint32_t  first_edge;
};

struct BSPTri {
	BSPVertex v[3];
};

BSPSurf*   CL_Map_Surfs();
uint32_t   CL_Map_SurfCount();
BSPEdge*   CL_Map_Edges();
uint32_t   CL_Map_EdgeCount();
BSPVertex* CL_Map_Vertices();
uint32_t   CL_Map_VertexCount();

void       CL_Init              ();
void       CL_EnableFpsCounter  (size_t localClientNum, bool enable);
void       CL_Frame             ();
void       CL_EnterSplitscreen  (size_t activeLocalClient);
void       CL_LeaveSplitscreen  (size_t activeLocalClient);
void	   CL_GiveKbmFocus	    (size_t localClientNum);
bool	   CL_HasKbmFocus		(size_t localClientNum);
size_t     CL_ClientWithKbmFocus();
KeyFocus   CL_KeyFocus		    (size_t localClientNum);
void       CL_SetKeyFocus		(size_t localClientNum, KeyFocus f);
bool       CL_LoadMap			(std::string_view map_name);
bool       CL_UnloadMap         ();
bool       CL_IsMapLoaded       ();
void       CL_Shutdown          ();
