#pragma once

#include "acommon/a_math.h"

A_EXTERN_C void M_AngleVectors(
	float yaw, float pitch, float roll, A_OPTIONAL_OUT avec3f_t* forward,
	A_OPTIONAL_OUT avec3f_t* right, A_OPTIONAL_OUT avec3f_t* up
);
