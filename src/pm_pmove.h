#include "acommon/a_math.h"

#include "com_defs.h"

typedef enum pmType_t {
	PM_NOCLIP,
} pmType_t;

typedef enum pmFlags_t {
	PMF_NONE      = 0x00000000,
	PMF_DUCKED    = 0x00000001,
	PMF_JUMP_HELD = 0x00000002,
} pmFlags_t;

typedef struct playerState_t {
	pmType_t   pm_type;
	int        pm_flags;
	apoint3f_t origin;
	avec3f_t   velocity;
	float      speed;
	float      viewyaw,  viewpitch,  viewroll;
	float      deltayaw, deltapitch, deltaroll;
	uint64_t   commandTime;
} playerState_t;

typedef struct usercmd_t {
	avec3f_t vel;
	float    roll, yaw, pitch;
	uint64_t serverTime;
} usercmd_t;

typedef struct pmove_t {
	playerState_t* ps;
	usercmd_t      cmd;
} pmove_t;

typedef struct pml_t {
	avec3f_t forward, right, up;
	float    frametime;
	uint64_t msec;
} pml_t;

typedef struct pm_t {
	playerState_t ps;
	pmove_t       pm;
	pml_t         pml;
} pm_t;

#define PM_FRICTION     6.0f
#define PM_STOPSPEED  100.0f
#define PM_ACCELERATE  10.0f

A_EXTERN_C pm_t* PM_GetLocalClientGlobals(size_t localClientNum);
A_EXTERN_C void  PM_Init    (void);
A_EXTERN_C void  PmoveSingle(A_INOUT pmove_t* pm, A_INOUT pml_t* pml);
A_EXTERN_C void  Pmove      (A_INOUT pmove_t* pm, A_INOUT pml_t* pml);
