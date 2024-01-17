#include "com_defs.hpp"

int main() {      
    Com_Init();

    while (Com_Frame())
        ;

    Sys_NormalExit(0);
}