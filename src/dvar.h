#pragma once

#include <assert.h>

#include "acommon/acommon.h"
#include "acommon/a_math.h"

#define DVAR_MAX_DVARS 4096

void Dvar_Init(void);
void Dvar_Shutdown(void);

typedef enum dvarFlags_t {
	DVAR_FLAG_NONE     = 0x00000000,
	DVAR_FLAG_ARCHIVE  = 0x00000001,
	DVAR_FLAG_READONLY = 0x00000002,
} dvarFlags_t;

struct dvar_t;
typedef struct dvar_t dvar_t;

A_EXTERN_C A_NO_DISCARD bool Dvar_WasModified  (const   dvar_t* d);
A_EXTERN_C              void Dvar_SetModified  (A_INOUT dvar_t* d);
A_EXTERN_C              void Dvar_ClearModified(A_INOUT dvar_t* d);

A_EXTERN_C A_NO_DISCARD bool Dvar_IsBool  (const dvar_t* d);
A_EXTERN_C A_NO_DISCARD bool Dvar_IsInt   (const dvar_t* d);
A_EXTERN_C A_NO_DISCARD bool Dvar_IsFloat (const dvar_t* d);
A_EXTERN_C A_NO_DISCARD bool Dvar_IsString(const dvar_t* d);
A_EXTERN_C A_NO_DISCARD bool Dvar_IsEnum  (const dvar_t* d);
A_EXTERN_C A_NO_DISCARD bool Dvar_IsVec2  (const dvar_t* d);
A_EXTERN_C A_NO_DISCARD bool Dvar_IsVec3  (const dvar_t* d);
A_EXTERN_C A_NO_DISCARD bool Dvar_IsVec4  (const dvar_t* d);
 
A_EXTERN_C              void Dvar_LatchValue     (A_INOUT dvar_t* d);
A_EXTERN_C              bool Dvar_RestoreValue   (A_INOUT dvar_t* d);
A_EXTERN_C A_NO_DISCARD bool Dvar_HasLatchedValue(const   dvar_t* d);

A_EXTERN_C void Dvar_SetBool  (A_INOUT dvar_t* d, bool b);
A_EXTERN_C void Dvar_SetInt   (A_INOUT dvar_t* d, int i);
A_EXTERN_C void Dvar_SetFloat (A_INOUT dvar_t* d, float f);
A_EXTERN_C void Dvar_SetString(A_INOUT dvar_t* d, const char* s);
A_EXTERN_C void Dvar_SetVec2  (A_INOUT dvar_t* d, avec2f_t v);
A_EXTERN_C void Dvar_SetVec3  (A_INOUT dvar_t* d, avec3f_t v);
A_EXTERN_C void Dvar_SetVec4  (A_INOUT dvar_t* d, avec4f_t v);

A_EXTERN_C A_NO_DISCARD bool        Dvar_GetBool  (const dvar_t* d);
A_EXTERN_C A_NO_DISCARD int         Dvar_GetInt   (const dvar_t* d);
A_EXTERN_C A_NO_DISCARD float       Dvar_GetFloat (const dvar_t* d);
A_EXTERN_C A_NO_DISCARD const char* Dvar_GetString(const dvar_t* d);
A_EXTERN_C A_NO_DISCARD avec2f_t    Dvar_GetVec2  (const dvar_t* d);
A_EXTERN_C A_NO_DISCARD avec3f_t    Dvar_GetVec3  (const dvar_t* d);
A_EXTERN_C A_NO_DISCARD avec4f_t    Dvar_GetVec4  (const dvar_t* d);

A_EXTERN_C void Dvar_AddFlags(A_INOUT dvar_t* d, int flags);

A_EXTERN_C A_NO_DISCARD bool    Dvar_Exists(const char* name);
A_EXTERN_C A_NO_DISCARD dvar_t* Dvar_Find  (const char* name);

A_EXTERN_C dvar_t* Dvar_RegisterNewBool(
	const char* name, int flags, 
	bool value
);
A_EXTERN_C dvar_t* Dvar_RegisterNewInt(
	const char* name, int flags, 
	int value, int min, int max
);
A_EXTERN_C dvar_t* Dvar_RegisterNewFloat(
	const char* name, int flags, 
	float value, float min, float max
);
A_EXTERN_C dvar_t* Dvar_RegisterNewString(
	const char* name, int flags, 
	const char* value
);
A_EXTERN_C dvar_t* Dvar_RegisterNewEnum(
	const char* name, int flags, int value, 
	const char** domain, size_t domain_count
);
A_EXTERN_C dvar_t* Dvar_RegisterNewVec2(
	const char* name, int flags, 
	avec2f_t value, float min, float max
);
A_EXTERN_C dvar_t* Dvar_RegisterNewVec3(
	const char* name, int flags, 
	avec3f_t value, float min, float max
);
A_EXTERN_C dvar_t* Dvar_RegisterNewVec4(
	const char* name, int flags, 
	avec4f_t value, float min, float max
);

A_EXTERN_C dvar_t* Dvar_ReregisterBool(
	const char* name, int flags, 
	bool value
);
A_EXTERN_C dvar_t* Dvar_ReregisterInt(
	const char* name, int flags, 
	int value, int min, int max
);
A_EXTERN_C dvar_t* Dvar_ReregisterFloat(
	const char* name, int flags, 
	float value, float min, float max
);
A_EXTERN_C dvar_t* Dvar_ReregisterString(
	const char* name, int flags, 
	const char* value
);
A_EXTERN_C dvar_t* Dvar_ReregisterEnum(
	const char* name, int flags, 
	int value, const char** domain, size_t domain_count
);
A_EXTERN_C dvar_t* Dvar_ReregisterVec2(
	const char* name, int flags, 
	const avec2f_t value, float min, float max
);
A_EXTERN_C dvar_t* Dvar_ReregisterVec3(
	const char* name, int flags, 
	const avec3f_t value, float min, float max
);
A_EXTERN_C dvar_t* Dvar_ReregisterVec4(
	const char* name, int flags, 
	const avec4f_t value, float min, float max
);

A_EXTERN_C dvar_t* Dvar_RegisterBool(
	const char* name, int flags, bool value
);
A_EXTERN_C dvar_t* Dvar_RegisterInt(
	const char* name, int flags, 
	int value, int min, int max
);
A_EXTERN_C dvar_t* Dvar_RegisterFloat(
	const char* name, int flags, 
	float value, float min, float max
);
A_EXTERN_C dvar_t* Dvar_RegisterString(
	const char* name, int flags, 
	const char* value
);
A_EXTERN_C dvar_t* Dvar_RegisterEnum(
	const char* name, int flags,
	int value, const char** domain, size_t domain_count
);
A_EXTERN_C dvar_t* Dvar_RegisterVec2(
	const char* name, int flags, 
	avec2f_t value, float min, float max
);
A_EXTERN_C dvar_t* Dvar_RegisterVec3(
	const char* name, int flags, 
	avec3f_t value, float min, float max
);
A_EXTERN_C dvar_t* Dvar_RegisterVec4(
	const char* name, int flags, 
	avec4f_t value, float min, float max
);

A_EXTERN_C bool Dvar_Unregister(const char* name);
A_EXTERN_C void Dvar_ClearDvars(void);

A_EXTERN_C A_NO_DISCARD bool    Dvar_LocalExists(int localClientNum, 
	                                             const char* name);
A_EXTERN_C A_NO_DISCARD dvar_t* Dvar_FindLocal  (int localClientNum, 
	                                             const char* name);

A_EXTERN_C dvar_t* Dvar_RegisterNewLocalBool(int localClientNum,
	const char* name, int flags,
	bool value
);
A_EXTERN_C dvar_t* Dvar_RegisterNewLocalInt(int localClientNum,
	const char* name, int flags,
	int value, int min, int max
);
A_EXTERN_C dvar_t* Dvar_RegisterNewLocalFloat(int localClientNum,
	const char* name, int flags,
	float value, float min, float max
);
A_EXTERN_C dvar_t* Dvar_RegisterNewLocalString(int localClientNum,
	const char* name, int flags,
	const char* value
);
A_EXTERN_C dvar_t* Dvar_RegisterNewLocalEnum(int localClientNum,
	const char* name, int flags, int value,
	const char** domain, size_t domain_count
	);
A_EXTERN_C dvar_t* Dvar_RegisterNewLocalVec2(int localClientNum,
	const char* name, int flags,
	avec2f_t value, float min, float max
);
A_EXTERN_C dvar_t* Dvar_RegisterNewLocalVec3(int localClientNum,
	const char* name, int flags,
	avec3f_t value, float min, float max
);
A_EXTERN_C dvar_t* Dvar_RegisterNewLocalVec4(int localClientNum,
	const char* name, int flags,
	avec4f_t value, float min, float max
);

A_EXTERN_C dvar_t* Dvar_ReregisterLocalBool(int localClientNum,
	const char* name, int flags,
	bool value
);
A_EXTERN_C dvar_t* Dvar_ReregisterLocalInt(int localClientNum,
	const char* name, int flags,
	int value, int min, int max
);
A_EXTERN_C dvar_t* Dvar_ReregisterLocalFloat(int localClientNum,
	const char* name, int flags,
	float value, float min, float max
);
A_EXTERN_C dvar_t* Dvar_ReregisterLocalString(int localClientNum,
	const char* name, int flags,
	const char* value
);
A_EXTERN_C dvar_t* Dvar_ReregisterLocalEnum(int localClientNum,
	const char* name, int flags,
	int value, const char** domain, size_t domain_count
);
A_EXTERN_C dvar_t* Dvar_ReregisterLocalVec2(int localClientNum,
	const char* name, int flags,
	avec2f_t value, float min, float max
);
A_EXTERN_C dvar_t* Dvar_ReregisterLocalVec3(int localClientNum,
	const char* name, int flags,
	avec3f_t value, float min, float max
);
A_EXTERN_C dvar_t* Dvar_ReregisterLocalVec4(int localClientNum,
	const char* name, int flags,
	avec4f_t value, float min, float max
);

A_EXTERN_C dvar_t* Dvar_RegisterLocalBool(
	int localClientNum, const char* name, int flags, bool value
);
A_EXTERN_C dvar_t* Dvar_RegisterLocalInt(
	int localClientNum, const char* name, int flags,
	int value, int min, int max
);
A_EXTERN_C dvar_t* Dvar_RegisterLocalFloat(
	int localClientNum, const char* name, int flags,
	float value, float min, float max
);
A_EXTERN_C dvar_t* Dvar_RegisterLocalString(
	int localClientNum, const char* name, int flags,
	const char* value
);
A_EXTERN_C dvar_t* Dvar_RegisterLocalEnum(
	int localClientNum, const char* name, int flags,
	int value, const char** domain, size_t domain_count
);
A_EXTERN_C dvar_t* Dvar_RegisterLocalVec2(
	int localClientNum, const char* name, int flags,
	avec2f_t value, float min, float max
);
A_EXTERN_C dvar_t* Dvar_RegisterLocalVec3(
	int localClientNum, const char* name, int flags,
	avec3f_t value, float min, float max
);
A_EXTERN_C dvar_t* Dvar_RegisterLocalVec4(
	int localClientNum, const char* name, int flags,
	avec4f_t value, float min, float max
);

A_EXTERN_C bool    Dvar_UnregisterLocal(int localClientNum, const char* name);
A_EXTERN_C void    Dvar_ClearLocalDvars(int localClientNum);

A_EXTERN_C bool    Dvar_SetFromString        (A_INOUT dvar_t* d,
	                                          int argc, const char** argv);
A_EXTERN_C dvar_t* Dvar_RegisterNewFromString(const char* name, int flags,
	                                          int argc, const char** argv);
A_EXTERN_C dvar_t* Dvar_ReregisterFromString (const char* name, int flags,
	                                          int argc, const char** argv);
A_EXTERN_C dvar_t* Dvar_RegisterFromString   (const char* name, int flags,
	                                          int argc, const char** argv);
A_EXTERN_C void Dvar_Set_f  (void);
A_EXTERN_C void Dvar_SetA_f (void);
A_EXTERN_C void Dvar_SetL_f (void);
A_EXTERN_C void Dvar_SetLA_f(void);
