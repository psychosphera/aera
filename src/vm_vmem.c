#include "vm_vmem.h"

#include <assert.h>

#include "acommon/a_string.h"
#include "acommon/z_mem.h"

#include "com_print.h"

typedef struct VmAllocation {
    void*       p;
    size_t      n;
    VmAllocType type;
} VmAllocation;

static VmAllocation s_allocs[VM_MAX_ALLOCATIONS];
static size_t       s_totalAllocForType[VM_ALLOC_COUNT];
static size_t       s_totalAlloc;

void VM_Init(void) {
    A_memset(s_allocs, 0, sizeof(s_allocs));
    A_memset(s_totalAllocForType, 0, sizeof(s_totalAllocForType));
    s_totalAlloc = 0;
}

static VmAllocation* VM_FindFreeAlloction(void) {
    for (int i = 0; i < A_countof(s_allocs); i++) {
        VmAllocation* a = &s_allocs[i];
        if (a->p == NULL)
            return a;
    }

    return NULL;
}

static VmAllocation* VM_FindAllocForPointer(void* p) {
    assert(p);
    for (int i = 0; i < A_countof(s_allocs); i++) {
        VmAllocation* a = &s_allocs[i];
        if (a->p == p)
            return a;
    }
    assert(false && "pointer not found");

    return NULL;
}

A_NO_DISCARD void* VM_Alloc(size_t n, VmAllocType type) {
    void* p = Z_Alloc(n);
    assert(p);
    assert((size_t)p != 0xDDDDDDDD);
    assert((size_t)p != 0xDDDDDDE1);
    VmAllocation* a = VM_FindFreeAlloction();
    assert(a);
    a->p = p;
    a->n = n;
    a->type = type;

    s_totalAlloc += n;
    s_totalAllocForType[type] += n;

    return p;
}

A_NO_DISCARD void* VM_Zalloc(size_t n, VmAllocType type) {
    void* p = Z_Zalloc(n);
    assert(p);
    assert((size_t)p != 0xDDDDDDDD);
    assert((size_t)p != 0xDDDDDDE1);
    VmAllocation* a = VM_FindFreeAlloction();
    assert(a);
    a->p = p;
    a->n = n;
    a->type = type;

    s_totalAlloc += n;
    s_totalAllocForType[type] += n;

    return p;
}

A_NO_DISCARD void* VM_AllocAt(const void* p, size_t n, VmAllocType type) {
    p = Z_AllocAt(p, n);
    assert(p);
    VmAllocation* a = VM_FindFreeAlloction();
    assert(a);
    a->p = (void*)p;
    a->n = n;
    a->type = type;

    s_totalAlloc += n;
    s_totalAllocForType[type] += n;

    return (void*)p;
}

bool VM_Free(void* p, VmAllocType type) {
    assert((size_t)p != 0xDDDDDDDD);
    assert((size_t)p != 0xDDDDDDE1);
    if (p == NULL)
        return true;

    VmAllocation* a = VM_FindAllocForPointer(p);
    assert(a);
    if (a == NULL) {
        Com_Errorln(-1, "VM_Free: Attempt to free pointer %p not allocated by VM_Alloc.", p);
        return false;
    }
    assert(a->type == type);
    if (a->type != type) {
        Com_Errorln(-1, "VM_Free: alloc type mismatch.", p);
        return false;
    }

    Z_Free(p);
    s_totalAllocForType[a->type] -= a->n;
    s_totalAlloc -= a->n;
    a->p = NULL;
    a->n = 0;
    a->type = VM_ALLOC_UNKNOWN;
    return true;
}

bool VM_FreeAt(void* p, VmAllocType type) {
    assert((size_t)p != 0xDDDDDDDD);
    assert((size_t)p != 0xDDDDDDE1);
    VmAllocation* a = VM_FindAllocForPointer(p);
    assert(a);
    if (a == NULL) {
        Com_Errorln(-1, "VM_Free: Attempt to free pointer %p not allocated by VM_Alloc.", p);
        return false;
    }
    assert(a->type == type);
    if (a->type != type) {
        Com_Errorln(-1, "VM_Free: alloc type mismatch.", p);
        return false;
    }

    Z_FreeAt(p, a->n);
    s_totalAllocForType[a->type] -= a->n;
    s_totalAlloc                 -= a->n;
    a->p                          = NULL;
    a->n                          = 0;
    a->type                       = VM_ALLOC_UNKNOWN;
    return true;
}

void VM_Shutdown(void) {
    //assert(s_totalAlloc == 0);
    for (int i = 0; i < A_countof(s_allocs); i++) {
        VmAllocation* a = &s_allocs[i];
        //if (a->p != NULL)
        //    Z_Free(a->p);
        s_totalAlloc -= a->n;
        s_totalAllocForType[a->type] -= a->n;
        a->n = 0;
        a->type = VM_ALLOC_UNKNOWN;
    }
    A_memset(s_allocs, 0, sizeof(s_allocs));
    A_memset(s_totalAllocForType, 0, sizeof(s_totalAllocForType));
    s_totalAlloc = 0;
}
