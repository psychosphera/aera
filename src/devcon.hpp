#pragma once

#include <string>

#include "com_defs.hpp"

             int         DevCon_Thread(void*);
             void        DevCon_Init();
A_NO_DISCARD bool        DevCon_HasText();
A_NO_DISCARD std::string DevCon_TakeText();
             void        DevCon_PrintMessage(std::string_view s);
             void        DevCon_Shutdown();
