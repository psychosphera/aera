#include "acommon.h"

#if !A_TARGET_PLATFORM_IS_XBOX
#include <stdio.h>
#else
#include <Xtl.h>
#endif // !A_TARGET_PLATFORM_IS_XBOX

A_EXTERN_C int A_remove(const char* A_RESTRICT pathname) {
#if !A_TARGET_PLATFORM_IS_XBOX
    return remove(pathname);
#else 
	return DeleteFileA(pathname);
#endif // !A_TARGET_PLATFORM_IS_XBOX
}
