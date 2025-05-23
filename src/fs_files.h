#pragma once

#include "acommon/acommon.h"

#if !A_TARGET_PLATFORM_IS_XBOX
#include <SDL2/SDL.h>
#endif // !A_TARGET_PLATFORM_IS_XBOX

#include "com_defs.h"

typedef struct StreamFile {
#if !A_TARGET_PLATFORM_IS_XBOX
	SDL_RWops* f;
#endif // !A_TARGET_PLATFORM_IS_XBOX
	size_t size;
} StreamFile;

A_EXTERN_C A_NO_DISCARD void* FS_ReadFile    (const char* path,
	                                          A_OPTIONAL_OUT size_t* sz);
A_EXTERN_C              void  FS_FreeFile    (void* p);
A_EXTERN_C A_NO_DISCARD char* FS_ReadFileText(const char* path, 
	                                          A_OPTIONAL_OUT size_t* sz);
A_EXTERN_C              void  FS_FreeFileText(char* text);

typedef enum SeekFrom {
	FS_SEEK_BEGIN,
	FS_SEEK_CUR,
	FS_SEEK_END
} SeekFrom;

typedef enum StreamMode {
	FS_STREAM_READ_EXISTING,
	FS_STREAM_WRITE_NEW,
	FS_STREAM_READ_WRITE_EXISTING,
	FS_STREAM_READ_WRITE_NEW,
	FS_STREAM_APPEND
} StreamMode;

A_EXTERN_C A_NO_DISCARD StreamFile FS_StreamFile(
	const char* path, SeekFrom from, StreamMode mode, size_t off
);

A_EXTERN_C long long FS_SeekStream (A_INOUT StreamFile* file, 
	                                SeekFrom from, size_t off);
A_EXTERN_C void      FS_CloseStream(A_INOUT StreamFile* file);

A_EXTERN_C A_NO_DISCARD size_t FS_StreamPos(A_INOUT StreamFile* file);
A_EXTERN_C A_NO_DISCARD size_t FS_FileSize (A_INOUT StreamFile* file);

A_EXTERN_C A_NO_DISCARD bool FS_ReadStream (A_INOUT StreamFile* file,       
	                                        void* dst, size_t count);
A_EXTERN_C A_NO_DISCARD bool FS_WriteStream(A_INOUT StreamFile* file, 
	                                        const void* src, size_t count);

A_EXTERN_C bool FS_DeleteFile(const char* filename);
A_EXTERN_C bool FS_FileExists(const char* filename);

A_EXTERN_C char* FS_BuildOsPath(const char* gamedir, const char* subdir,
	                            const char* file,    const char* ext);
