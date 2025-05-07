#include "acommon.h"

#include <stdio.h>

int A_remove(const char* A_RESTRICT pathname) {
    return remove(pathname);
}
