#include "cmd_commands.h"

#include <assert.h>

#include "acommon/a_string.h"
#include "acommon/a_type.h"
#include "acommon/z_mem.h"

typedef struct Cmd {
	bool free;
	void (*cmd)(void);
	char* name;
} Cmd;

Cmd s_cmds[CMD_MAX_COMMANDS];
size_t s_cmds_idx;

typedef struct CmdArgs {
	char* args[CMD_MAX_ARGS];
	size_t idx;
} CmdArgs;
CmdArgs cmd_args;

void Cmd_Init(void) {
	A_memset(s_cmds, 0, sizeof(s_cmds));
	s_cmds_idx = 0;
}

void Cmd_ArgsPushFront(const char* s) {
	assert(cmd_args.idx < CMD_MAX_ARGS);
	cmd_args.args[cmd_args.idx++] = A_cstrdup(s);
}

bool Cmd_AddCommand(const char* cmdName, void(*fn)(void)) {
	if (Cmd_CommandExists(cmdName))
		return false;
	
	if (s_cmds_idx < CMD_MAX_COMMANDS) {
		s_cmds[s_cmds_idx].cmd = fn;
		s_cmds[s_cmds_idx].free = false;
		s_cmds[s_cmds_idx].name = A_cstrdup(cmdName);
		s_cmds_idx++;
		
		return true;
	}

	for (size_t i = 0; i < CMD_MAX_COMMANDS; i++) {
		if (s_cmds[i].free) {
			s_cmds[i].free = false;
			s_cmds[i].cmd = fn;
			s_cmds[i].name = A_cstrdup(cmdName);
			return true;
		}
	}

	return false;
}

bool Cmd_CommandExists(const char* cmdName) {
	for (size_t i = 0; i < s_cmds_idx; i++) {
		if (A_cstrcmp(s_cmds[i].name, cmdName) == true)
			return true;
	}
	return false;
}

CmdFn Cmd_FindCommand(const char* cmdName) {
	if (!Cmd_CommandExists(cmdName))
		return NULL;

	for (size_t i = 0; i < CMD_MAX_COMMANDS; i++) {
		if (A_cstrcmp(cmdName, s_cmds[i].name)) {
			if (s_cmds[i].cmd)
				return s_cmds[i].cmd;
		}
	}
	
	return NULL;
}

void Cmd_RemoveCommand(const char* cmdName) {
	for (size_t i = 0; i < CMD_MAX_COMMANDS; i++) {
		if (A_cstrcmp(cmdName, s_cmds[i].name)) {
			A_cstrfree(s_cmds[i].name);
			s_cmds[i].name = NULL;
			s_cmds[i].cmd  = NULL;
			s_cmds[i].free = true;
			return;
		}
	}
}

void Cmd_ClearCommands(void) {
	for (size_t i = 0; i < s_cmds_idx; i++) {
		A_cstrfree(s_cmds[i].name);
		s_cmds[i].name = NULL;
		s_cmds[i].cmd  = NULL;
		s_cmds[i].free = true;
	}
		
}

int Cmd_Argc(void) {
	return (int)cmd_args.idx;
}

const char* Cmd_Argv(int i) {
	assert(i < Cmd_Argc());

	return cmd_args.args[i];
}

bool Cmd_TakeInput(const char* input) {	
	for (size_t i = 0; i < cmd_args.idx; i++)
		A_cstrfree(cmd_args.args[i]);

	int last_arg_i = 0;
	int i          = 0;
	for (const char* p = input; *p != '\0'; p++) {
		if (A_isspace(*p)) {
			size_t len = i - last_arg_i;
			cmd_args.args[i] = Z_Alloc(len + 1);
			A_cstrncpyz(cmd_args.args[cmd_args.idx++], &input[last_arg_i], len + 1);
			last_arg_i = i + 1;
			while (A_isspace(*(p++)));
		}
		i++;
	}
	return true;
}

void Cmd_Shutdown(void) {
	Cmd_ClearCommands();
}
