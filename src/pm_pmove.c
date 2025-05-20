#include "pm_pmove.h"

#include <assert.h>

#if A_RENDER_BACKEND_GL
#include <cglm/cglm.h>
#endif // A_RENDER_BACKEND_GL

#include "acommon/a_string.h"
#include "acommon/a_math.h"

#include "m_math.h"

pm_t s_pm[MAX_LOCAL_CLIENTS];

pm_t* PM_GetLocalClientGlobals(size_t localClientNum) {
	assert(localClientNum < MAX_LOCAL_CLIENTS);
	return &s_pm[localClientNum];
}

void PM_Init(void) {
	for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
		pm_t* pm = PM_GetLocalClientGlobals(i);
		pm->pm.ps = &pm->ps;
	}
}

static void PM_Accelerate(
	A_INOUT pmove_t* pm, A_INOUT pml_t* pml,
	avec3f_t wishdir, float wishspeed, float accel
) {
	float currentspeed = glm_vec3_dot(pm->ps->velocity.array, wishdir.array);
	float addspeed = wishspeed - currentspeed;

	if (addspeed <= 0)
		return;

	float accelspeed = accel * pml->frametime * wishspeed;
	if (accelspeed > addspeed)
		accelspeed = addspeed;

	vec3 velocity;
	glm_vec3_scale(wishdir.array, accelspeed, velocity);
	glm_vec3_add(pm->ps->velocity.array, velocity, pm->ps->velocity.array);
}

static void PM_NoclipMove(A_INOUT pmove_t* pm, A_INOUT pml_t* pml) {
	float speed = glm_vec3_norm(pm->ps->velocity.array);
	if (speed < 1.0f) {
		pm->ps->velocity = A_VEC3F_ZERO;
	} else {
		float friction = PM_FRICTION * 1.5f;
		float control = speed < PM_STOPSPEED ? PM_STOPSPEED : speed;
		float drop = control * friction * pml->frametime;

		float newspeed = speed - drop;
		if (newspeed < 0)
			newspeed = 0;
		newspeed /= speed;

		vec3 velocity;
		glm_vec3_scale(pm->ps->velocity.array, newspeed, velocity);
		pm->ps->velocity = *(avec3f_t*)&velocity;
	}

	vec3 forward, right;
	glm_vec3_scale(pml->forward.array, pm->cmd.vel.z, forward);
	glm_vec3_scale(pml->right.array, pm->cmd.vel.x, right);
	avec3f_t wishvel;
	glm_vec3_sub(forward, right, wishvel.array);

	wishvel.y += pm->cmd.vel.y;

	avec3f_t wishdir = wishvel;
	glm_vec3_normalize(wishdir.array);
	float wishspeed = glm_vec3_norm(wishvel.array);
	if (A_memcmp(&wishvel, &A_VEC3F_ZERO, sizeof(wishvel))) {
		wishdir   = A_VEC3F_ZERO;
		wishspeed = 0;
	}

	PM_Accelerate(pm, pml, wishdir, wishspeed, PM_ACCELERATE);

	avec3f_t pos = A_vec3(pm->ps->origin.x, pm->ps->origin.y, pm->ps->origin.z);
	vec3 velocity;
	glm_vec3_scale(pm->ps->velocity.array, pml->frametime, velocity);
	glm_vec3_add(pos.array, velocity, pos.array);
	pm->ps->origin.x = pos.x;
	pm->ps->origin.y = pos.y;
	pm->ps->origin.z = pos.z;

}

void PM_UpdateViewAngles(A_INOUT playerState_t* ps, const usercmd_t* cmd) {
	if (ps->pm_type != PM_NOCLIP)
		return;

	ps->viewyaw   += ps->deltayaw  + cmd->yaw;
	ps->viewroll  += ps->deltaroll + cmd->roll;
	ps->viewpitch = A_CLAMP(
		ps->viewpitch + ps->deltapitch + cmd->pitch, -89.0f, 89.0f
	);
}

void PmoveSingle(A_INOUT pmove_t* pm, A_INOUT pml_t* pml) {
	A_memset(pml, 0, sizeof(*pml));

	pml->msec = A_CLAMP(
		(uint64_t)((float)pm->cmd.serverTime - (float)pm->ps->commandTime), 
		(uint64_t)1, (uint64_t)200
	);
	pm->ps->commandTime = pm->cmd.serverTime;
	pml->frametime      = pml->msec * 0.001f;

	PM_UpdateViewAngles(pm->ps, &pm->cmd);
	M_AngleVectors(
		pm->ps->viewyaw, pm->ps->viewpitch, pm->ps->viewroll, 
		&pml->forward, &pml->right, &pml->up
	);

	if (pm->cmd.vel.y < 10.0f)
	    pm->ps->pm_flags &= ~PMF_JUMP_HELD;

	if (pm->ps->pm_type == PM_NOCLIP) {
	    PM_NoclipMove(pm, pml);
	}

	A_memset(&pm->cmd, 0, sizeof(pm->cmd));
}

void Pmove(A_INOUT pmove_t* pm, A_INOUT pml_t* pml) {
	uint64_t finalTime = pm->cmd.serverTime;

	if (finalTime < pm->ps->commandTime) {
		return;	
	}

	if (finalTime > pm->ps->commandTime + 1000) {
		pm->ps->commandTime = finalTime - 1000;
	}

	// chop the move up if it is too long, to prevent framerate
	// dependent behavior
	while (pm->ps->commandTime != finalTime) {
		int msec = finalTime - pm->ps->commandTime;

		if (msec > 66) {
			msec = 66;
		}
		pm->cmd.serverTime = pm->ps->commandTime + msec;
		PmoveSingle(pm, pml);

		if (pm->ps->pm_flags & PMF_JUMP_HELD) {
			pm->cmd.vel.y = 20;
		}
	}

	//PM_CheckStuck();
}
