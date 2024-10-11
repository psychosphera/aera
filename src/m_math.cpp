#include "m_math.hpp"

#include <glm/glm.hpp>

#include "acommon/a_math.h"

#include "com_defs.hpp"
#include "gfx_defs.hpp"

void M_AngleVectors(
	float yaw, float pitch, float roll, A_OPTIONAL_OUT glm::vec3* forward, 
	A_OPTIONAL_OUT glm::vec3* right, A_OPTIONAL_OUT glm::vec3* up
) {
	float ay = glm::radians(yaw);
	float sy = A_sinf(ay);
	float cy = A_cosf(ay);
	float ap = glm::radians(pitch);
	float sp = A_sinf(ap);
	float cp = A_cosf(ap);
	float ar = glm::radians(roll);
	float sr = A_sinf(ar);
	float cr = A_cosf(ar);

	if (forward) {
		forward->x =  cp * cy;
		forward->y = -sp;
		forward->z =  cp * sy;
	}
	if (right) {
		right->x = (-1.0f * sr * sp * cy) + (-1.0f * cr * -sy);
		right->y =  -1.0f * sr * cp;
		right->z = (-1.0f * sr * sp * sy) + (-1.0f * cr * cy);
	}
	if (up) {
		up->x = (cr * sp * cy) + (-sr * -sy);
		up->y =  cr * cp;
		up->z = (cr * sp * sy) + (-sr * cy);
	}
}

/// <summary>
/// Splits a surface into one or more triangles.
/// 
/// The current implementation is only valid for convex, not concave, surfaces.
/// It works by creating tris out of the first vertex and every following set 
/// of two vertices (i.e. the first tri consists of verts 0, 1, and 2, the
/// second consists of 0, 2, 3, etc.).
/// </summary>
/// <param name="verts">Pointer to the surface's vertices</param>
/// <param name="num_verts">Number of vertices in the surface (should never be
/// greater than 8 or less than 3)</param>
/// <param name="tris">Out-pointer for the new tris.</param>
/// <param name="max_tris">Maximum number of tris to process</param>
/// <returns>The actual number of tris processed, or -1 if num_verts is less 
/// than 3</returns>
size_t M_TriangulateSurf(const BSPVertex* verts, size_t num_verts, A_OUT BSPTri* tris, size_t max_tris) {
	assert(num_verts >= R_SURF_MIN_VERTS);
	assert(num_verts <= R_SURF_MAX_VERTS + 1);
	assert(max_tris  >= R_SURF_MIN_TRIS);
	assert(max_tris  <= R_SURF_MAX_TRIS);

	if (num_verts < 3)
		return -1;

	if (max_tris > num_verts - 2)
		max_tris = num_verts - 2;

	for (size_t i = 0; i < max_tris; i++)
		tris[i] = { verts[0], verts[i + 1], verts[i + 2] };

	return max_tris;
}