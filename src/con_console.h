#pragma once

#include <stdbool.h>

#include "acommon/acommon.h"

A_EXTERN_C bool Con_ProcessInput(const char* input);
A_EXTERN_C bool Con_ProcessLocalInput(const char* input, size_t localClientNum);
