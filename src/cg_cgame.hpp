#pragma once

#include "com_defs.hpp"
#include "gfx_defs.hpp"
#include "cl_client.hpp"

struct cg_t {
	float fovy;
	dvar_t* fov;
	float sensitivity;
	GfxCamera camera;
	bool active;
	RectDef viewport;
	float nearPlane, farPlane;
	KeyFocus keyfocus;
};

void  CG_Init();
cg_t& CG_GetLocalClientGlobals(size_t localClientNum);
bool  CG_LocalClientIsActive  (size_t localClientNum);
void  CG_ActivateLocalClient  (size_t localClientNum);
void  CG_DectivateLocalClient (size_t localClientNum);

void  CG_Frame(uint64_t deltaTime);
void  CG_Shutdown();
