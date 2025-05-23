#include "acommon/z_mem.h"

#include "com_print.h"
#include "sys.h"

#ifdef main
#undef main
#endif // main
int main(int argc, const char** argv) {
    A_UNUSED(argc);
    Com_Println(CON_DEST_CLIENT, "Running.");  
    Sys_Init(argv);
    Com_Init();
    Com_DPrintln(CON_DEST_CLIENT, "Running in debug mode.");

    while (Com_Frame())
        ;

    Sys_NormalExit(0);
}
