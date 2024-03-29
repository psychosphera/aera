#include "acommon.h"

#include <stdint.h>

size_t A_npow2(size_t n) {
    if(n == 0)
        return 1;

    if(n == 1)
        return 2;

    uint8_t i = 0;
    for(; i < (uint8_t)SIZE_BIT; i++) {
        n >>= 1;
        if(n == 0)
            break;
    }

    return 1 << (i + 1);
}

size_t A_ppow2(size_t n) {
    return A_npow2(n) >> 1;
}
