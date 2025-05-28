#include "pm_pmove.h"

#include <assert.h>

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
#if A_RENDER_BACKEND_GL
	float currentspeed = glm_vec3_dot(pm->ps->velocity.array, wishdir.array);
#elif A_RENDER_BACKEND_D3D9 || A_RENDER_BACKEND_D3D8
	float currentspeed = D3DXVec3Dot((D3DXVECTOR3*)pm->ps->velocity.array, (D3DXVECTOR3*)wishdir.array);
#endif // A_RENDER_BACKEND_GL

	float addspeed = wishspeed - currentspeed;

	if (addspeed <= 0)
		return;

	float accelspeed = accel * pml->frametime * wishspeed;
	if (accelspeed > addspeed)
		accelspeed = addspeed;

#if A_RENDER_BACKEND_GL
	vec3 velocity;
	glm_vec3_scale(wishdir.array, accelspeed, velocity);
	glm_vec3_add(pm->ps->velocity.array, velocity, pm->ps->velocity.array);
#elif A_RENDER_BACKEND_D3D9 || A_RENDER_BACKEND_D3D8
	D3DXVECTOR3 velocity;
	D3DXVec3Scale(&velocity, (D3DXVECTOR3*)wishdir.array, accelspeed);
	D3DXVec3Add((D3DXVECTOR3*)pm->ps->velocity.array, &velocity, (D3DXVECTOR3*)pm->ps->velocity.array);
#endif // A_RENDER_BACKEND_GL
}

static void PM_NoclipMove(A_INOUT pmove_t* pm, A_INOUT pml_t* pml) {
#if A_RENDER_BACKEND_GL
	float speed = glm_vec3_norm(pm->ps->velocity.array);
#elif A_RENDER_BACKEND_D3D9 || A_RENDER_BACKEND_D3D8
	float speed = D3DXVec3Length((D3DXVECTOR3*)pm->ps->velocity.array);
#endif // A_RENDER_BACKEND_GL
	if (speed < 1.0f) {
		pm->ps->velocity = A_VEC3F_ZERO;
	}
	else {
		float friction = PM_FRICTION * 1.5f;
		float control = speed < PM_STOPSPEED ? PM_STOPSPEED : speed;
		float drop = control * friction * pml->frametime;

		float newspeed = speed - drop;
		if (newspeed < 0)
			newspeed = 0;
		newspeed /= speed;

#if A_RENDER_BACKEND_GL
		vec3 velocity;
		glm_vec3_scale(pm->ps->velocity.array, newspeed, velocity);
#elif A_RENDER_BACKEND_D3D9 || A_RENDER_BACKEND_D3D8
		D3DXVECTOR3 velocity;
		D3DXVec3Scale(&velocity, (D3DXVECTOR3*)pm->ps->velocity.array, newspeed);
#endif // A_RENDER_BACKEND_GL
		pm->ps->velocity = *(avec3f_t*)&velocity;
	}

#if A_RENDER_BACKEND_GL
	vec3 forward, right;
	glm_vec3_scale(pml->forward.array, pm->cmd.vel.z, forward);
	glm_vec3_scale(pml->right.array, pm->cmd.vel.x, right);
	avec3f_t wishvel;
	glm_vec3_sub(forward, right, wishvel.array);
#elif A_RENDER_BACKEND_D3D9 || A_RENDER_BACKEND_D3D8
	D3DXVECTOR3 forward, right;
	D3DXVec3Scale(&forward, (D3DXVECTOR3*)pml->forward.array, pm->cmd.vel.z);
	D3DXVec3Scale(&right, (D3DXVECTOR3*)pml->right.array, pm->cmd.vel.x);
	avec3f_t wishvel;
	D3DXVec3Subtract((D3DXVECTOR3*)wishvel.array, &forward, &right);
#endif // A_RENDER_BACKEND_GL

	wishvel.y += pm->cmd.vel.y;

	avec3f_t wishdir = wishvel;
#if A_RENDER_BACKEND_GL
	glm_vec3_normalize(wishdir.array);
	float wishspeed = glm_vec3_norm(wishvel.array);
#elif A_RENDER_BACKEND_D3D9 || A_RENDER_BACKEND_D3D8
	D3DXVec3Normalize((D3DXVECTOR3*)wishdir.array, (D3DXVECTOR3*)wishdir.array);
	float wishspeed = D3DXVec3Length((D3DXVECTOR3*)wishvel.array);
#endif // A_RENDER_BACKEND_GL
	if (A_memcmp(&wishvel, &A_VEC3F_ZERO, sizeof(wishvel))) {
		wishdir = A_VEC3F_ZERO;
		wishspeed = 0;
	}

	PM_Accelerate(pm, pml, wishdir, wishspeed, PM_ACCELERATE);

	avec3f_t pos = A_vec3(pm->ps->origin.x, pm->ps->origin.y, pm->ps->origin.z);
#if A_RENDER_BACKEND_GL
	vec3 velocity;
	glm_vec3_scale(pm->ps->velocity.array, pml->frametime, velocity);
	glm_vec3_add(pos.array, velocity, pos.array);
#elif A_RENDER_BACKEND_D3D9 || A_RENDER_BACKEND_D3D8
	D3DXVECTOR3 velocity;
	D3DXVec3Scale(&velocity, (D3DXVECTOR3*)pm->ps->velocity.array, pml->frametime);
	D3DXVec3Add((D3DXVECTOR3*)pos.array, &velocity, (D3DXVECTOR3*)pos.array);
#endif // A_RENDER_BACKEND_GL
	pm->ps->origin.x = pos.x;
	pm->ps->origin.y = pos.y;
	pm->ps->origin.z = pos.z;

}

void PM_UpdateViewAngles(A_INOUT playerState_t* ps, const usercmd_t* cmd) {
	if (ps->pm_type != PM_NOCLIP)
		return;

	ps->viewyaw += ps->deltayaw + cmd->yaw;
	ps->viewroll += ps->deltaroll + cmd->roll;
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
	pml->frametime = pml->msec * 0.001f;

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