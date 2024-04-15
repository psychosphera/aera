#include "com_print.hpp"
#include "sys.hpp"

int main(int /*argc */, const char** argv) {    
    Sys_Init(argv);
    Com_Init();
#if _DEBUG
    Com_DPrintln("Running in debug mode.");
#endif // _DEBUG

    while (Com_Frame())
        ;

    Sys_NormalExit(0);
}
