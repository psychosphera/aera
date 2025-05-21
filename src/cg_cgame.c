#include "cg_cgame.h"

#include <assert.h>

#include "acommon/a_string.h"

#include "cmd_commands.h"
#include "com_print.h"
#include "dvar.h"
#include "gfx_defs.h"
#include "in_input.h"
#include "pm_pmove.h"

#if !A_TARGET_PLATFORM_IS_XBOX
static float s_lastMouseX, s_lastMouseY;
static bool  s_firstMouse;
#endif // !A_TARGET_PLATFORM_IS_XBOX

static cg_t s_cg[MAX_LOCAL_CLIENTS];

extern dvar_t* vid_width;
extern dvar_t* vid_height;

void CG_Teleport_f(void);

cg_t* CG_GetLocalClientGlobals(size_t localClientNum) {
	assert(localClientNum < MAX_LOCAL_CLIENTS);
	return &s_cg[localClientNum];
}

bool CG_LocalClientIsActive(size_t localClientNum) {
	return CG_GetLocalClientGlobals(localClientNum)->active;
}

void CG_ActivateLocalClient(size_t localClientNum) {
	CG_GetLocalClientGlobals(localClientNum)->active = true;
}

void CG_DectivateLocalClient(size_t localClientNum) {
	CG_GetLocalClientGlobals(localClientNum)->active = false;
}

void CG_Init(void) {
#if !A_TARGET_PLATFORM_IS_XBOX
	s_firstMouse = true;
	s_lastMouseX = IN_Mouse_X(0);
	s_lastMouseY = IN_Mouse_Y(0);
#endif // !A_TARGET_PLATFORM_IS_XBOX

	Cmd_AddCommand("teleport", CG_Teleport_f);

	for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
		cg_t* cg = CG_GetLocalClientGlobals(i);
		cg->camera.pos.x = 0.0f;
		cg->camera.pos.y = 0.0f;
		cg->camera.pos.z = 0.0f;

		cg->camera.worldUp.x = 0.0f;
		cg->camera.worldUp.y = 1.0f;
		cg->camera.worldUp.z = 0.0f;

		cg->camera.front.x =  0.0f;
		cg->camera.front.y =  0.0f;
		cg->camera.front.z = -1.0f;

		cg->camera.up      = cg->camera.worldUp;
		cg->camera.pitch   =  0.0f;
		cg->camera.yaw     = -90.0f;

		cg->viewport.x = 0.0f;
		cg->viewport.y = 0.0f;
		cg->viewport.w = 1.0f;
		cg->viewport.h = 1.0f;

		cg->fov = Dvar_RegisterLocalFloat(i, "cg_fov", DVAR_FLAG_NONE, 
									     90.0f, 1.0f, 179.0f);
		float w = cg->viewport.w * Dvar_GetInt(vid_width);
		float h = cg->viewport.h * Dvar_GetInt(vid_height);
		cg->fovy = R_FovHorzToVertical(Dvar_GetFloat(cg->fov), h / w);

		cg->sensitivity = 0.1f;
		cg->active      = false;
		cg->cluster     = 0;

		PM_GetLocalClientGlobals(i)->pm.ps->commandTime = Sys_Milliseconds();
	}

	CG_ActivateLocalClient(0);
}

void CG_Teleport(size_t localClientNum, apoint3f_t pos) {
	PM_GetLocalClientGlobals(localClientNum)->pm.ps->origin = pos;
}

void CG_Teleport_f(void) {
	int argc = Cmd_Argc();
	if (argc < 4) {
		Com_Println(CON_DEST_CLIENT, "USAGE: teleport <x> <y> <z>");
		return;
	}

	apoint3f_t p;
	A_atof(Cmd_Argv(1), &p.x);
	A_atof(Cmd_Argv(2), &p.y);
	A_atof(Cmd_Argv(3), &p.z);
#if !A_TARGET_PLATFORM_IS_XBOX
	CG_Teleport(CL_ClientWithKbmFocus(), p);
#else
	assert(false && "unimplemented"); // FIXME
#endif // !A_TARGET_PLATFORM_IS_XBOX
}

void CG_SetSpawn(size_t localClientNum, apoint3f_t spawn, float facing) {
	cg_t* cg = CG_GetLocalClientGlobals(localClientNum);
	cg->spawn.pos   = spawn;
	cg->spawn.front = facing;
}

apoint3f_t CG_GetSpawnPos(size_t localClientNum) {
	return CG_GetLocalClientGlobals(localClientNum)->spawn.pos;
}

float CG_GetSpawnDir(size_t localClientNum) {
	return CG_GetLocalClientGlobals(localClientNum)->spawn.front;
}

void CG_Respawn(size_t localClientNum) {
	CG_Teleport(localClientNum, CG_GetSpawnPos(localClientNum));
	avec3f_t forward = A_vec3(0.0f, CG_GetSpawnDir(localClientNum), 0.0f);
	PM_GetLocalClientGlobals(localClientNum)->pml.forward = forward;
}

extern dvar_t* r_fullscreen;
extern dvar_t* r_noBorder;
extern dvar_t* cl_splitscreen;
 
void CG_Frame(uint64_t deltaTime) {
	A_UNUSED(deltaTime);

	for (size_t localClientNum = 0; 
		 localClientNum < MAX_LOCAL_CLIENTS; 
		 localClientNum++
	) {
		cg_t* cg = CG_GetLocalClientGlobals(localClientNum);
		float w = cg->viewport.w * (float)Dvar_GetInt(vid_width);
		float h = cg->viewport.h * (float)Dvar_GetInt(vid_height);
		float aspect_inv = h / w;
		cg->fovy = R_FovHorzToVertical(Dvar_GetFloat(cg->fov), aspect_inv);
		
		pm_t* pm = PM_GetLocalClientGlobals(localClientNum);
#if !A_TARGET_PLATFORM_IS_XBOX
		if (CL_HasKbmFocus(localClientNum) && 
			CL_KeyFocus(localClientNum) == KF_GAME
		) {
			if (IN_Key_WasPressedOnCurrentFrame(localClientNum, IN_KEYCODE_N)) {
				CL_GiveKbmFocus(1);
				IN_Key_Clear(0);
				if (!Dvar_GetBool(cl_splitscreen)) {
					CG_ActivateLocalClient(1);
					CG_DectivateLocalClient(0);
				}
			}
			else if (IN_Key_WasPressedOnCurrentFrame(localClientNum, IN_KEYCODE_M)) {
				CL_GiveKbmFocus(0);
				IN_Key_Clear(1);
				if (!Dvar_GetBool(cl_splitscreen)) {
					CG_ActivateLocalClient(0);
					CG_DectivateLocalClient(1);
				}
			}

			if (IN_Key_WasPressedOnCurrentFrame(localClientNum, IN_KEYCODE_J)) {
				Dvar_SetBool(cl_splitscreen, !Dvar_GetBool(cl_splitscreen));
			}

			if (Dvar_WasModified(cl_splitscreen)) {
				if (Dvar_GetBool(cl_splitscreen)) {
					CL_EnterSplitscreen(localClientNum);
				}
				else {
					CL_LeaveSplitscreen(localClientNum);
				}
				Dvar_ClearModified(cl_splitscreen);
			}

			if (IN_Key_WasPressedOnCurrentFrame(localClientNum, IN_KEYCODE_F10))
				Dvar_SetBool(r_noBorder, !Dvar_GetBool(r_noBorder));

			if (IN_Key_WasPressedOnCurrentFrame(localClientNum, IN_KEYCODE_F11))
				Dvar_SetBool(r_fullscreen, !Dvar_GetBool(r_fullscreen));

			float vel = 100.0f;
			if (IN_Key_IsDown(localClientNum, IN_KEYCODE_LEFT_SHIFT))
				vel *= 1.5f;

			if (IN_Key_IsDown(localClientNum, IN_KEYCODE_W))
				pm->pm.cmd.vel.z += vel;
			if (IN_Key_IsDown(localClientNum, IN_KEYCODE_S))
				pm->pm.cmd.vel.z -= vel;
			if (IN_Key_IsDown(localClientNum, IN_KEYCODE_A))
				pm->pm.cmd.vel.x -= vel;
			if (IN_Key_IsDown(localClientNum, IN_KEYCODE_D))
				pm->pm.cmd.vel.x += vel;
			if (IN_Key_IsDown(localClientNum, IN_KEYCODE_SPACE))
				pm->pm.cmd.vel.y += vel;
			if (IN_Key_IsDown(localClientNum, IN_KEYCODE_LEFT_CTRL))
				pm->pm.cmd.vel.y -= vel;

			/*if (pm->pm.cmd.vel.x != 0 && pm->pm.cmd.vel.y != 0) {
				pm->pm.cmd.vel.x *= 0.5f;
				pm->pm.cmd.vel.y *= 0.5f;
			}*/

			float x = IN_Mouse_X(localClientNum);
			float y = IN_Mouse_Y(localClientNum);
			if (s_lastMouseX != x || s_lastMouseY != y) {
				if (s_firstMouse) {
					s_lastMouseX = x;
					s_lastMouseY = y;
					s_firstMouse = false;
				}

				float xoff   = x - s_lastMouseX;
				float yoff   = y - s_lastMouseY;
				s_lastMouseX = x;
				s_lastMouseY = y;

				xoff *= cg->sensitivity;
				yoff *= cg->sensitivity;
				pm->pm.cmd.yaw   = -xoff;
				pm->pm.cmd.pitch = -yoff;
			}

			pm->pm.cmd.serverTime = Sys_Milliseconds();
			Pmove(&pm->pm, &pm->pml);
		}
#endif // !A_TARGET_PLATFORM_IS_XBOX
		cg->camera.pos   = pm->pm.ps->origin;
		cg->camera.front = pm->pml.forward;
	}
}

void CG_Shutdown(void) {
	Cmd_RemoveCommand("teleport");
}
