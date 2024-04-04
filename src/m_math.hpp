#pragma once

void M_AngleVectors(
	float yaw, float pitch, float roll, A_OPTIONAL_OUT glm::vec3* forward,
	A_OPTIONAL_OUT glm::vec3* right, A_OPTIONAL_OUT glm::vec3* up
);