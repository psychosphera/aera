#include "com_print.hpp"
#include "sys.hpp"

int main(int /* argc */, const char** argv) {
    Com_Println(CON_DEST_CLIENT, "Running.");  
    Sys_Init(argv);
    Com_Init();
    Com_DPrintln("Running in debug mode.");

    while (Com_Frame())
        ;

    Sys_NormalExit(0);
}
