#pragma once

#include <stdbool.h>

#include "acommon/a_math.h"

#include "com_defs.h"
#include "dvar.h"
#include "gfx_defs.h"
#include "cl_client.h"

typedef struct SpawnPoint {
	apoint3f_t pos;
	float      front;
} SpawnPoint;
	
typedef struct cg_t {
	float	   fovy;
	dvar_t*	   fov;
	float	   sensitivity;
	GfxCamera  camera;
	bool	   active;
	RectDef	   viewport;
	float	   nearPlane, farPlane;
	KeyFocus   keyfocus;
	uint32_t   cluster;
	SpawnPoint spawn;
} cg_t;

A_EXTERN_C void       CG_Init(void);
A_EXTERN_C cg_t*      CG_GetLocalClientGlobals(size_t localClientNum);
A_EXTERN_C void       CG_Teleport             (size_t localClientNum, apoint3f_t pos);
A_EXTERN_C void       CG_SetSpawn             (size_t localClientNum, 
                 							   apoint3f_t spawn, float facing);
A_EXTERN_C apoint3f_t CG_GetSpawnPos          (size_t localClientNum);
A_EXTERN_C float      CG_GetSpawnDir          (size_t localClientNum);
A_EXTERN_C void       CG_Respawn              (size_t localClientNum);
A_EXTERN_C bool       CG_LocalClientIsActive  (size_t localClientNum);
A_EXTERN_C void       CG_ActivateLocalClient  (size_t localClientNum);
A_EXTERN_C void       CG_DectivateLocalClient (size_t localClientNum);

A_EXTERN_C void       CG_Frame(uint64_t deltaTime);
A_EXTERN_C void       CG_Shutdown(void);
