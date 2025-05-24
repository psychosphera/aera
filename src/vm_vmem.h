#pragma once

#include "acommon/acommon.h"

#define VM_MAX_ALLOCATIONS 16384

typedef enum VmAllocType {
    VM_ALLOC_UNKNOWN,
    VM_ALLOC_BSP,
    VM_ALLOC_MODEL,
    VM_ALLOC_BITMAP,
    VM_ALLOC_DVAR,
    VM_ALLOC_TAG_DATA,
    VM_ALLOC_FILE,
    VM_ALLOC_FONT,
    VM_ALLOC_DEVGUI,
    VM_ALLOC_MAP,

    VM_ALLOC_COUNT
} VmAllocType;

A_EXTERN_C              void  VM_Init    (void);
A_EXTERN_C A_NO_DISCARD void* VM_Alloc   (size_t n, VmAllocType type);
A_EXTERN_C A_NO_DISCARD void* VM_Zalloc  (size_t n, VmAllocType type);
A_EXTERN_C A_NO_DISCARD void* VM_AllocAt (const void* p, size_t n, VmAllocType type);
A_EXTERN_C              bool  VM_Free    (void* p, VmAllocType type);
A_EXTERN_C              bool  VM_FreeAt  (void* p, VmAllocType type);
A_EXTERN_C              void  VM_Shutdown(void);
