#include "m_math.hpp"

#include <glm/glm.hpp>

#include "acommon/a_math.h"

#include "com_defs.hpp"

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
