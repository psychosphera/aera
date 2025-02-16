#include "con_console.h"

#include "cmd_commands.h"
#include "dvar.h"

bool Con_ProcessInput(const char* input) {
    if (!Cmd_TakeInput(input))
        return false;

    void(*fn)(void);
    if (Cmd_FindCommand(Cmd_Argv(0), &fn)) {
        fn();
        return true;
    } else {
        dvar_t* d = Dvar_Find(Cmd_Argv(0));
        if (d != NULL) {
            const char* argv[4];
            /*int argc = 0;*/

            if (Cmd_Argc() == 1) {
                /*Com_Println(CON_DEST_CLIENT, "{}", Dvar_GetString(*d));*/
                return true;
            }
            else {
                argv[0] = Cmd_Argv(1);
                /*argc++;*/

                if (Dvar_IsVec2(d) || Dvar_IsVec3(d) || Dvar_IsVec4(d)) {
                    argv[1] = Cmd_Argv(2);
                    /*argc++;*/
                }

                if (Dvar_IsVec3(d) || Dvar_IsVec4(d)) {
                    argv[2] = Cmd_Argv(3);
                    /*argc++;*/
                }

                if (Dvar_IsVec4(d)) {
                    argv[3] = Cmd_Argv(4);
                    /*argc++;*/
                }

                return false;/* Dvar_SetFromString(d, DVAR_FLAG_NONE, argv, argc);*/
            }
        }
    }
    return false;
}

bool Con_ProcessLocalInput(const char* input, size_t localClientNum) {
    if (!Cmd_TakeInput(input))
        return false;

    void(*fn)(void);
    if (Cmd_FindCommand(Cmd_Argv(0), &fn)) {
        fn();
        return true;
    } else {
        dvar_t* d = Dvar_Find(Cmd_Argv(0));
        if (d != NULL) {
            const char* argv[4];
            /*int argc = 0;*/

            if (Cmd_Argc() == 1) {
                /*Com_Println(CON_DEST_CLIENT, "{}", Dvar_GetString(*d));*/
                return true;
            } else {
                argv[0] = Cmd_Argv(1);
                /*argc++;*/

                if (Dvar_IsVec2(d) || Dvar_IsVec3(d) || Dvar_IsVec4(d)) {
                    argv[1] = Cmd_Argv(2);
                    /*argc++;*/
                }

                if (Dvar_IsVec3(d) || Dvar_IsVec4(d)) {
                    argv[2] = Cmd_Argv(3);
                    /*argc++;*/
                }

                if (Dvar_IsVec4(d)) {
                    argv[3] = Cmd_Argv(4);
                   /* argc++;*/
                }

                return false; /*Dvar_SetFromString(d, DVAR_FLAG_NONE, argv, argc);*/
            }
        }
        dvar_t* dl = Dvar_FindLocal(localClientNum, Cmd_Argv(0));
        if (dl != NULL) {
            const char* argv[4];
            /*int argc = 0;*/

            if (Cmd_Argc() == 1) {
               /* Com_Println(CON_DEST_CLIENT, "{}", Dvar_GetString(*dl));*/
                return true;
            }
            else {
                argv[0] = Cmd_Argv(1);
                /*argc++;*/

                if (Dvar_IsVec2(dl) || Dvar_IsVec3(dl) || Dvar_IsVec4(dl)) {
                    argv[1] = Cmd_Argv(2);
                    /*argc++;*/
                }

                if (Dvar_IsVec3(dl) || Dvar_IsVec4(dl)) {
                    argv[2] = Cmd_Argv(3);
                    /*argc++;*/
                }

                if (Dvar_IsVec4(dl)) {
                    argv[3] = Cmd_Argv(4);
                    /*argc++;*/
                }

                return false;/*Dvar_SetFromString(dl, DVAR_FLAG_NONE, argv, argc);*/
            }
        }

    }
    return false;
}
