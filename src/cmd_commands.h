#pragma once

#include "acommon/acommon.h"

#include "com_defs.h"

#define CMD_MAX_COMMANDS 16
#define CMD_MAX_ARGS     4 

typedef void(*CmdFn)(void);

A_EXTERN_C void        Cmd_Init         (void);
A_EXTERN_C bool        Cmd_AddCommand   (const char* cmdName, void(*fn)(void));
A_EXTERN_C bool		   Cmd_CommandExists(const char* cmdName);
A_EXTERN_C CmdFn       Cmd_FindCommand  (const char* cmdName);
A_EXTERN_C void        Cmd_RemoveCommand(const char* cmdName);
A_EXTERN_C void        Cmd_ClearCommands(void);
A_EXTERN_C int         Cmd_Argc         (void);
A_EXTERN_C const char* Cmd_Argv         (int i);
A_EXTERN_C bool        Cmd_TakeInput    (const char* input);
A_EXTERN_C void        Cmd_Shutdown     (void);
