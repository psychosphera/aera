#include "con_console.h"

#include "cmd_commands.h"
#include "com_print.h"
#include "dvar.h"

bool Con_ProcessInput(const char* input) {
    if (!Cmd_TakeInput(input))
        return false;

    void(*fn)(void) = Cmd_FindCommand(Cmd_Argv(0));
    if (fn) {
        fn();
        return true;
    } else {
        dvar_t* d = Dvar_Find(Cmd_Argv(0));
        if (d != NULL) {
            const char* argv[4];
            int argc = 0;

            if (Cmd_Argc() == 1) {
                Com_Println(CON_DEST_CLIENT, "%s", Dvar_GetString(d));
                return true;
            }
            else {
                argv[0] = Cmd_Argv(1);
                argc++;

                if (Dvar_IsVec2(d) || Dvar_IsVec3(d) || Dvar_IsVec4(d)) {
                    argv[1] = Cmd_Argv(2);
                    argc++;
                }

                if (Dvar_IsVec3(d) || Dvar_IsVec4(d)) {
                    argv[2] = Cmd_Argv(3);
                    argc++;
                }

                if (Dvar_IsVec4(d)) {
                    argv[3] = Cmd_Argv(4);
                    argc++;
                }

                return Dvar_SetFromString(d, argc, argv);
            }
        }
    }
    return false;
}

bool Con_ProcessLocalInput(const char* input, size_t localClientNum) {
    if (!Cmd_TakeInput(input))
        return false;

    if (Cmd_Argc() < 1)
        return true;

    CmdFn fn = Cmd_FindCommand(Cmd_Argv(0));
    if (fn) {
        fn();
        return true;
    } else {
        dvar_t* d = Dvar_FindLocal(localClientNum, Cmd_Argv(0));
        if (d == NULL) d = Dvar_Find(Cmd_Argv(0));
        if (d != NULL) {
            const char* argv[4];
            int argc = 0;

            if (Cmd_Argc() == 1) {
                Com_Println(CON_DEST_CLIENT, "%s", Dvar_GetString(d));
                return true;
            } else {
                argv[0] = Cmd_Argv(1);
                argc++;

                if (Dvar_IsVec2(d) || Dvar_IsVec3(d) || Dvar_IsVec4(d)) {
                    argv[1] = Cmd_Argv(2);
                    argc++;
                }

                if (Dvar_IsVec3(d) || Dvar_IsVec4(d)) {
                    argv[2] = Cmd_Argv(3);
                    argc++;
                }

                if (Dvar_IsVec4(d)) {
                    argv[3] = Cmd_Argv(4);
                   argc++;
                }

                return Dvar_SetFromString(d, argc, argv);
            }
        }
    }
    return false;
}
