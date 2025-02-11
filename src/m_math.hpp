#pragma once

#include "cl_client.hpp"
#include "gfx_defs.hpp"

void M_AngleVectors(
	float yaw, float pitch, float roll, A_OPTIONAL_OUT glm::vec3* forward,
	A_OPTIONAL_OUT glm::vec3* right, A_OPTIONAL_OUT glm::vec3* up
);