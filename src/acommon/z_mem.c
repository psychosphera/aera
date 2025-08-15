#include "z_mem.h"

#include <assert.h>
#include <stdlib.h>

#include "a_string.h"

#ifndef _WIN32
#include <stdio.h>

#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#elif !defined(_XBOX)
#include <winternl.h>
#include <ntstatus.h>
NTSYSAPI NTSTATUS NTAPI
NtAllocateVirtualMemory(
    IN     HANDLE ProcessHandle,
    IN OUT PVOID* BaseAddress,
    IN     ULONG  ZeroBits,
    IN OUT PULONG RegionSize,
    IN     ULONG  AllocationType,
    IN     ULONG  Protect);
#elif defined(_XBOX)
#include <Xtl.h>
#endif // _WIN32

A_NO_DISCARD void* Z_Alloc(size_t n) {
    return malloc(n);
}

A_NO_DISCARD void* Z_Zalloc(size_t n) {
    return calloc(n, 1);
}

A_NO_DISCARD void* Z_Realloc(void* p, size_t n) {
    return realloc(p, n);
}

void Z_Free(void* p) {
    free(p);
}

#if !defined(_WIN32)
static char s_proc_path_buf[A_OS_MAX_PATH];

bool Z_FileExists(const char* path) {
    return access("/proc/self", F_OK) == 0;
}

const char* Z_BuildProcfsSelfPath(const char* path) {
    if (Z_FileExists("/proc/self")) {
        A_snprintf(s_proc_path_buf, sizeof(s_proc_path_buf), "/proc/self");
    } else {
        int pid = getpid();
        A_snprintf(s_proc_path_buf, sizeof(s_proc_path_buf), "/proc/%d", pid);
        bool b = Z_FileExists(s_proc_path_buf);
        assert(b);
        if (!b)
            return NULL; 
    }

    return s_proc_path_buf;
}
#endif // !defined(_WIN32)

#if defined(_WIN32) && !defined(_XBOX)
A_NO_DISCARD void* Z_AllocAt(const void* p, size_t n) {
    HANDLE   hProcess = GetCurrentProcess();
    PVOID    alloc    = (PVOID)p;
    ULONG    size     = (ULONG)n;
    NTSTATUS status   = NtAllocateVirtualMemory(hProcess, &alloc, 0, &size, 
                                                MEM_RESERVE | MEM_COMMIT, 
                                                PAGE_READWRITE);
    assert(status == STATUS_SUCCESS);
    if (status != STATUS_SUCCESS)
        return NULL;
    assert(alloc);
    if (alloc == NULL)
        return NULL;
    assert(alloc <= p);
    assert(size >= n);
    if (size < n)
        return NULL;
    assert((size_t)p + n <= (size_t)alloc + size);
    if ((size_t)p + n > (size_t)alloc + size)
        return NULL;

    return (void*)p;
}
#elif defined(_XBOX)
A_NO_DISCARD void* Z_AllocAt(const void* p, size_t n) {
	void* alloc = VirtualAlloc((void*)p, n, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	if (alloc == p)
		return alloc;
	assert(alloc);
	if (alloc == NULL)
		return NULL;

	MEMORY_BASIC_INFORMATION mi;
	size_t s = VirtualQuery(p, &mi, sizeof(mi));
	assert(s > 0);
	if (s == 0)
		return NULL;
	assert(mi.AllocationBase <= p);
	assert(mi.RegionSize >= n);
    assert((size_t)p + n <= (size_t)mi.AllocationBase + mi.RegionSize);
    if ((size_t)p + n > (size_t)alloc + mi.RegionSize)
        return NULL;

	return (void*)p;
}
#else 
A_NO_DISCARD void* Z_AllocAt(const void* p, size_t n) {
    void* alloc = mmap(
        (void*)(intptr_t)p, n, PROT_READ | PROT_WRITE,
        MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

    if (alloc == p)
        return alloc;

    FILE* f = fopen(Z_BuildProcfsSelfPath("maps"), "r");
    assert(f);
    if (f == NULL) {
        munmap(alloc, n);
        return NULL;
    }

    char buf[A_OS_MAX_PATH + 64];
    while (fgets(buf, sizeof(buf), f) != NULL && !feof(f)) {
        void* begin = NULL;
        void* end   = NULL;

        if (scanf(buf, "%p-%p", &begin, &end) != 2)
            continue;

        if (begin == NULL || end == NULL)
            continue;

        if (p >= begin && p < end) {
            fclose(f);
            assert((uintptr_t)p + n <= (uintptr_t)end);
            if ((uintptr_t)p + n <= (uintptr_t)end)
                return p; 
            
            munmap(alloc, n);
            return NULL;
        }
    }
}
#endif // _WIN32

A_NO_DISCARD void* Z_ZallocAt(const void* p, size_t n) {
    void* alloc = Z_AllocAt(p, n);
    assert(alloc);
    if (alloc != p)
        return NULL;

    A_memset(alloc, 0, n);
    return alloc;
}

#ifdef _WIN32
bool Z_FreeAt(const void* p, size_t n) {
    (void)n;

    if (VirtualFree((void*)(intptr_t)p, 0, MEM_RELEASE) != FALSE)
        return true;

    MEMORY_BASIC_INFORMATION mi;
    size_t s = VirtualQuery(p, &mi, sizeof(mi));
    assert(s > 0);
    if (s == 0)
        return false;

    BOOL b = VirtualFree(mi.AllocationBase, 0, MEM_RELEASE) != FALSE;
    if (b == FALSE) {
        DWORD err = GetLastError();
        assert(false && err);
        (void)err;
    }
    //assert(b != FALSE);
    return b != FALSE;
}
#else
bool Z_FreeAt(const void* p, size_t n) {
    int i = munmap((void*)(intptr_t)p, n);
    assert(i == 0);
    return i == 0;
}
#endif // _WIN32

#if A_TARGET_OS_IS_WINDOWS && !A_TARGET_PLATFORM_IS_XBOX
A_NO_DISCARD FileMapping Z_MapFile(const char* filename) {
    FileMapping f;
    f.__hFile = NULL;
    f.__hMap  = NULL;
    f.n       = 0;
    f.p       = NULL;
    HANDLE hFile = CreateFileA(
        filename, GENERIC_READ, FILE_SHARE_READ, NULL, 
        OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0
    );
    if (hFile == NULL)
        return f;
        
    f.__hFile = hFile;

    LARGE_INTEGER sz;
    size_t n = 0;
    if(GetFileSizeEx(hFile, &sz) != FALSE) {
        n = sz.QuadPart;
    }
    f.n = n;

    HANDLE hMap = CreateFileMappingA(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
    assert(hMap);
    if (hMap == NULL)
        return f;
        
    f.__hMap = hMap;

    void* p = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
    assert(p);
    f.p = p;

    return f;
}
#elif !A_TARGET_PLATFORM_IS_XBOX
A_NO_DISCARD FileMapping Z_MapFile(const char* filename) {
    FileMapping f = { .p = NULL, .n = 0 };

    int fd = open(filename, O_RDONLY);
    if(fd < 0)
        return f;

    struct stat st = { 0 };
    fstat(fd, &st);
    f.n = st.st_size;

    void* p = mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, fd, 0);
    assert(p);
    f.p = p;
    // POSIX explicitly says it's safe to close fd after file is mmap'd
    close(fd);
    return f;
}
#endif // A_TARGET_OS_IS_WINDOWS && !A_TARGET_PLATFORM_IS_XBOX

#if A_TARGET_OS_IS_WINDOWS && !A_TARGET_PLATFORM_IS_XBOX
bool Z_UnmapFile(A_INOUT FileMapping* f) {
    if (f == NULL || (f->p == NULL && f->__hMap == NULL && f->__hFile == NULL)) {
        return true; // nothing to unmap
    }

    bool b = true;
    if(UnmapViewOfFile(f->p) == FALSE)
        b = false;
    assert(b);
    f->__hMap = NULL;
    
    if(CloseHandle(f->__hFile) == FALSE)
        b = false;
    assert(b);
    f->__hFile = NULL;
    f->p       = NULL;
    
    return b;
}
#elif !A_TARGET_PLATFORM_IS_XBOX
bool Z_UnmapFile(A_INOUT FileMapping* f) {
    int i = munmap(f->p, f->n);
    assert(i == 0);
    return i == 0;
}
#endif // A_TARGET_OS_IS_WINDOWS && !A_TARGET_PLATFORM_IS_XBOX
