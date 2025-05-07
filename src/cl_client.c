#include "cl_client.h"

#include <assert.h>

#include <zlib.h>

#include "acommon/a_string.h"
#include "acommon/z_mem.h"

#include "cg_cgame.h"
#include "cl_map.h"
#include "com_print.h"
#include "dvar.h"
#include "gfx.h"
#include "gfx_text.h"
#include "in_input.h"

extern dvar_t* vid_width;
extern dvar_t* vid_height;

typedef struct cll_t {
	KeyFocus keyfocus;
	bool     drawDevGui;
	size_t   fpsTextDrawId;
} cll_t;
cll_t s_cll[MAX_LOCAL_CLIENTS];

typedef struct cl_t {
	dvar_t* drawfps;
	bool    hasKbmFocus;
} cl_t;
cl_t s_cl[MAX_LOCAL_CLIENTS];

dvar_t* cl_splitscreen = NULL;

static uint64_t s_lastFpsDrawTime;
static uint64_t s_lastFpsDrawDelta;

cll_t* CL_GetLocalClientLocals(size_t localClientNum) {
	assert(localClientNum < MAX_LOCAL_CLIENTS);
	return &s_cll[localClientNum];
}

cl_t* CL_GetLocalClientGlobals(size_t localClientNum) {
	assert(localClientNum < MAX_LOCAL_CLIENTS);
	return &s_cl[localClientNum];
}

A_EXTERN_C void CL_Init(void) {
	cl_splitscreen = Dvar_RegisterBool("cl_splitscreen", DVAR_FLAG_NONE, false);

	for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
		cl_t* cl = CL_GetLocalClientGlobals(i);
		cl->drawfps = Dvar_RegisterLocalBool(i, "cl_drawfps", DVAR_FLAG_NONE, false);
		CL_GetLocalClientLocals(i)->drawDevGui = false;
		CL_SetKeyFocus(i, KF_GAME);
		RectDef rect = { .x = 0.985f, .y = 0.99f, .w = 0.0498f, .h = 0.0498f };
		acolor_rgb_t color = A_color_rgb(0.5, 0.8f, 0.2f);
		char text[10];
		A_snprintf(text, sizeof(text), "FPS: %.0f", 1000.0f / s_lastFpsDrawDelta);
		bool b = R_AddTextDrawDef(
			i, NULL, &rect, text,
			0.5f, 0.5f,
			color, Dvar_GetBool(cl->drawfps), true,
			&CL_GetLocalClientLocals(i)->fpsTextDrawId
		);
		assert(b);
		(void)b;
	}

	CL_GiveKbmFocus(0);
	
	CL_InitMap();

	bool b = CL_LoadMap("c40_xbox.map");
	assert(b);
	(void)b;
}

A_EXTERN_C void CL_EnableFpsCounter(size_t localClientNum, bool enable) {
	Dvar_SetBool(CL_GetLocalClientGlobals(localClientNum)->drawfps, enable);
}

A_EXTERN_C void CL_DrawFps(size_t localClientNum) {
	char text[10];
	A_snprintf(text, sizeof(text), "FPS: %.0f", 1000.0f / s_lastFpsDrawDelta);
	R_UpdateTextDrawDef(
		localClientNum, CL_GetLocalClientLocals(localClientNum)->fpsTextDrawId,
		text
	);
}

A_EXTERN_C void CL_Frame(void) {
	for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
		cl_t*  cl  = CL_GetLocalClientGlobals(i);
		cll_t* cll = CL_GetLocalClientLocals(i);
		R_ActivateTextDrawDef(i, cll->fpsTextDrawId, Dvar_GetBool(cl->drawfps));

		// Updating the FPS counter too often makes it flicker
		if (Sys_Milliseconds() - s_lastFpsDrawTime > 40) {
			s_lastFpsDrawTime  = Sys_Milliseconds();
			s_lastFpsDrawDelta = Com_LastFrameTimeDelta();
		}

		if (Dvar_GetBool(cl->drawfps))
			CL_DrawFps(i);

		cll->drawDevGui = IN_Key_IsToggled(i, IN_KEYCODE_TILDE);
		if (cll->drawDevGui)
			CL_SetKeyFocus(i, KF_DEVGUI);
		else
			CL_SetKeyFocus(i, KF_GAME);
	}	
} 

A_EXTERN_C void CL_EnterSplitscreen(size_t activeLocalClient) {
	cg_t* cg0 = CG_GetLocalClientGlobals(0);

	cg0->viewport.x = 0.0f;
	cg0->viewport.y = 0.5f;
	cg0->viewport.w = 1.0f;
	cg0->viewport.h = 0.5f;

	float w0 = cg0->viewport.w * Dvar_GetInt(vid_width);
	float h0 = cg0->viewport.h * Dvar_GetInt(vid_height);
	cg0->fovy = R_FovHorzToVertical(Dvar_GetFloat(cg0->fov), h0 / w0);

	cg_t* cg1 = CG_GetLocalClientGlobals(1);

	cg1->viewport.x = 0.0f;
	cg1->viewport.y = 0.0f;
	cg1->viewport.w = 1.0f;
	cg1->viewport.h = 0.5f;

	float w1 = cg1->viewport.w * Dvar_GetInt(vid_width);
	float h1 = cg1->viewport.h * Dvar_GetInt(vid_height);
	cg1->fovy = R_FovHorzToVertical(Dvar_GetFloat(cg1->fov), h1 / w1);

	if (activeLocalClient != 0)
		CG_ActivateLocalClient(0);
	if (activeLocalClient != 1)
		CG_ActivateLocalClient(1);
}

A_EXTERN_C void CL_LeaveSplitscreen(size_t activeLocalClient) {
	for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
		cg_t* cg = CG_GetLocalClientGlobals(i);
		cg->viewport.x = 0.0f;
		cg->viewport.y = 0.0f;
		cg->viewport.w = 1.0f;
		cg->viewport.h = 1.0f;

		float w = cg->viewport.w * Dvar_GetInt(vid_width);
		float h = cg->viewport.h * Dvar_GetInt(vid_height);
		cg->fovy = R_FovHorzToVertical(Dvar_GetFloat(cg->fov), h / w);

		if (i != activeLocalClient)
			CG_DectivateLocalClient(i);
	}
}


A_EXTERN_C void CL_GiveKbmFocus(size_t localClientNum) {
	for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++)
		CL_GetLocalClientGlobals(i)->hasKbmFocus = i == localClientNum;
}

A_EXTERN_C bool CL_HasKbmFocus(size_t localClientNum) {
	return CL_GetLocalClientGlobals(localClientNum)->hasKbmFocus;
}

A_EXTERN_C size_t CL_ClientWithKbmFocus(void) {
	for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
		if (CL_HasKbmFocus(i))
			return i;
	}

	assert(false);
	return (size_t)-1;
}

A_EXTERN_C KeyFocus CL_KeyFocus(size_t localClientNum) {
	return CG_GetLocalClientGlobals(localClientNum)->keyfocus;
}

A_EXTERN_C void CL_SetKeyFocus(size_t localClientNum, KeyFocus f) {
	CG_GetLocalClientGlobals(localClientNum)->keyfocus = f;
}

A_EXTERN_C void CL_Shutdown(void) {
	CL_ShutdownMap();
	Dvar_SetBool(cl_splitscreen, false);
	Dvar_Unregister("cl_splitscreen");
	cl_splitscreen = NULL;

	for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
		cl_t* cl = CL_GetLocalClientGlobals(i);
		Dvar_SetBool(cl->drawfps, false);
		Dvar_UnregisterLocal(i, "cl_drawfps");
		cl->drawfps = NULL;

		cll_t* cll = CL_GetLocalClientLocals(i);
		cll->drawDevGui = false;
		cll->keyfocus = KF_GAME;
	}
}
