#pragma once

#include "acommon/z_mem.h"

#include "com_defs.h"
#include "fs_files.h"

A_EXTERN_C A_NO_DISCARD const char* DB_ImagePath(const char* image_name);

A_EXTERN_C A_NO_DISCARD char*       DB_LoadShader(const char* shader_name);
A_EXTERN_C              void        DB_UnloadShader    (char* shader);
A_EXTERN_C A_NO_DISCARD void*       DB_LoadFont        (const char* font_name, 
                                                        A_OUT size_t* sz);
A_EXTERN_C              void        DB_UnloadFont      (void* font);
A_EXTERN_C A_NO_DISCARD void*       DB_LoadImage       (const char* image_name);
A_EXTERN_C              void        DB_UnloadImage     (void* image);
A_EXTERN_C A_NO_DISCARD StreamFile  DB_LoadMap_Stream  (const char* map_name);
A_EXTERN_C              void        DB_UnloadMap_Stream(A_INOUT StreamFile* s);
A_EXTERN_C A_NO_DISCARD FileMapping DB_LoadMap_Mmap    (const char* map_name);
A_EXTERN_C void DB_UnloadMap_Mmap  (A_INOUT FileMapping* m);
