#pragma once

#include "cl_client.hpp"

void M_AngleVectors(
	float yaw, float pitch, float roll, A_OPTIONAL_OUT glm::vec3* forward,
	A_OPTIONAL_OUT glm::vec3* right, A_OPTIONAL_OUT glm::vec3* up
);
size_t M_TriangulateSurf(const BSPVertex* verts, size_t num_verts, A_OUT BSPTri* tris, size_t max_tris);