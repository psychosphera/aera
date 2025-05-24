#include "dvar.h"

#include <assert.h>
#include <float.h>
#include <limits.h>

#include "acommon/a_string.h"

#include "cl_client.h"
#include "cmd_commands.h"
#include "com_print.h"
#include "vm_vmem.h"

typedef enum DvarType {
	DVAR_TYPE_NONE,
	DVAR_TYPE_BOOL,
	DVAR_TYPE_INT,
	DVAR_TYPE_FLOAT,
	DVAR_TYPE_STRING,
	DVAR_TYPE_ENUM,
	DVAR_TYPE_VEC2,
	DVAR_TYPE_VEC3,
	DVAR_TYPE_VEC4
} DvarType;

typedef union DvarDomain {
	struct { int   min, max; } i;
	struct { float min, max; } f;
	int e;
} DvarDomain;

typedef union DvarValue {
	bool     b;
	int      i;
	float    f;
	avec2f_t v2;
	avec3f_t v3;
	avec4f_t v4;
} DvarValue;

typedef struct dvar_t {
	char*      name;
	uint32_t   name_hash;
	DvarType   type;
	DvarDomain domain;
	DvarValue  value;
	DvarValue  latched;
	int        flags;
	char**     e;
	int        i;
	bool       modified;
	bool       hasLatched;
} dvar_t;

static dvar_t* s_dvars[DVAR_MAX_DVARS];
static int     s_dvarCount;

static uint32_t Dvar_HashName(const char* name) {
	assert(name);
	uint32_t hash = 0;
	for (uint32_t i = 0; name[i] != '\0'; i++) {
		char c = A_tolower(name[i]);
		hash += (uint32_t)c * (i+119);
	}
	return hash;
}

static void* Dvar_Alloc(size_t n) {
	return VM_Alloc(n, VM_ALLOC_DVAR);
}

static bool Dvar_Free(void* p) {
	return VM_Free(p, VM_ALLOC_DVAR);
}

void Dvar_Init(void) {
	Cmd_AddCommand("set",   Dvar_Set_f  );
	Cmd_AddCommand("seta",  Dvar_SetA_f );
	Cmd_AddCommand("setl",  Dvar_SetL_f );
	Cmd_AddCommand("setla", Dvar_SetLA_f);


	A_memset(s_dvars, 0, sizeof(s_dvars));
	s_dvarCount = 0;
}

A_NO_DISCARD bool Dvar_WasModified(const dvar_t* d) {
	return d->modified;
}

void Dvar_SetModified(A_INOUT dvar_t* d) {
	d->modified = true;
}

void Dvar_ClearModified(A_INOUT dvar_t* d) {
	d->modified = false;
}

A_NO_DISCARD bool Dvar_IsBool(const dvar_t* d) {
	return d->type == DVAR_TYPE_BOOL;
}

A_NO_DISCARD bool Dvar_IsInt(const dvar_t* d) {
	return d->type == DVAR_TYPE_INT;
}

A_NO_DISCARD bool Dvar_IsFloat(const dvar_t* d) {
	return d->type == DVAR_TYPE_FLOAT;
}

A_NO_DISCARD bool Dvar_IsString(const dvar_t* d) {
	return d->type == DVAR_TYPE_STRING;
}

A_NO_DISCARD bool Dvar_IsEnum(const dvar_t* d) {
	return d->type == DVAR_TYPE_ENUM;
}

A_NO_DISCARD bool Dvar_IsVec2(const dvar_t* d) {
	return d->type == DVAR_TYPE_VEC2;
}

A_NO_DISCARD bool Dvar_IsVec3(const dvar_t* d) {
	return d->type == DVAR_TYPE_VEC3;
}

A_NO_DISCARD bool Dvar_IsVec4(const dvar_t* d) {
	return d->type == DVAR_TYPE_VEC4;
}

void Dvar_LatchValue(A_INOUT dvar_t* d) {
	d->latched = d->value;
	d->hasLatched = true;
}

bool Dvar_RestoreValue(A_INOUT dvar_t* d) {
	if (d->hasLatched) {
		d->value = d->latched;
		d->hasLatched = false;
		return true;
	}

	return false;
}

A_NO_DISCARD bool Dvar_HasLatchedValue(const dvar_t* d) {
	return d->hasLatched;
}

static void Dvar_DestroyDvar(dvar_t* d) {
	A_cstrfree(d->name);
	if (d->type == DVAR_TYPE_ENUM) {
		for (int i = 0; i < d->domain.e; i++)
			A_cstrfree(d->e[i]);
		Dvar_Free(d->e);
	}
	else if (d->type == DVAR_TYPE_STRING || d->type == DVAR_TYPE_BOOL) {
		A_cstrfree(d->e[0]);
		Dvar_Free(d->e);
	}
	else if (d->type == DVAR_TYPE_INT || d->type == DVAR_TYPE_FLOAT ||
		d->type == DVAR_TYPE_VEC2 || d->type == DVAR_TYPE_VEC3 ||
		d->type == DVAR_TYPE_VEC4
		) {
		Dvar_Free(d->e[0]);
		Dvar_Free(d->e);
	}
}

dvar_t Dvar_CreateBool(const char* name, int flags, bool value) {
	char** e = (char**)Dvar_Alloc(sizeof(*e));
	e[0] = (char*)Dvar_Alloc(6);
	if (value == true)
		A_cstrncpyz(e[0], "true", 5);
	else
		A_cstrncpyz(e[0], "false", 6);

	dvar_t d;
	d.name       = (char*)name;
	d.name_hash  = Dvar_HashName(name);
	d.type       = DVAR_TYPE_BOOL;
	d.value.b    = value;
	d.latched.b  = false;
	d.e          = e;
	d.modified   = false;
	d.hasLatched = false;

	return d;
}

dvar_t Dvar_CreateInt(const char* name, int flags, 
	                  int value, int min, int max
) {
	char** e = (char**)Dvar_Alloc(sizeof(*e));
	e[0] = (char*)Dvar_Alloc(12);
	A_itoa(value, e[0], 12);

	dvar_t d;
	d.name         = (char*)name;
	d.name_hash    = Dvar_HashName(name);
	d.type         = DVAR_TYPE_INT;
	d.domain.i.min = min;
	d.domain.i.max = max;
	d.value.i      = value;
	d.latched.i    = 0;
	d.e            = e;
	d.modified     = false;
	d.hasLatched   = false;

	return d;
}

dvar_t Dvar_CreateFloat(const char* name, int flags, 
	                    float value, float min, float max
) {
	char** e = (char**)Dvar_Alloc(sizeof(*e));
	e[0] = (char*)Dvar_Alloc(32);
	A_itoa(value, e[0], 32);

	dvar_t d;
	d.name         = (char*)name;
	d.name_hash    = Dvar_HashName(name);
	d.type         = DVAR_TYPE_FLOAT;
	d.domain.f.min = min;
	d.domain.f.max = max;
	d.value.f      = value;
	d.latched.f    = 0.0f;
	d.e            = e;
	d.modified     = false;
	d.hasLatched   = false;

	return d;
}

dvar_t Dvar_CreateString(const char* name, int flags, const char* value) {
	char** e = (char**)Dvar_Alloc(sizeof(*e));
	e[0] = (char*)A_cstrdup(value);

	dvar_t d;
	d.name       = (char*)name;
	d.name_hash  = Dvar_HashName(name);
	d.type       = DVAR_TYPE_STRING;
	d.e          = e;
	d.modified   = false;
	d.hasLatched = false;

	return d;
}

dvar_t Dvar_CreateEnum(
	const char* name, int flags, int value,
	const char** domain, size_t domain_count
) {
	char** e = (char**)Dvar_Alloc(sizeof(*e) * domain_count);
	for (size_t i = 0; i < domain_count; i++)
		e[i] = (char*)A_cstrdup(domain[i]);

	dvar_t d;
	d.name       = (char*)name;
	d.name_hash  = Dvar_HashName(name);
	d.type       = DVAR_TYPE_ENUM;
	d.domain.e   = domain_count;
	d.e          = e;
	d.i          = value;
	d.modified   = false;
	d.hasLatched = false;
	return d;
}

dvar_t Dvar_CreateVec2(const char* name, int flags, 
                       avec2f_t value, float min, float max
) {
	char** e = (char**)Dvar_Alloc(sizeof(*e));
	e[0] = (char*)Dvar_Alloc(32 + 1 + 32);
	size_t pos = A_itoa(value.x, e[0], 32);
	e[0][pos] = ' ';
	A_itoa(value.y, &e[0][pos + 1], 32);

	dvar_t d;
	d.name         = (char*)name;
	d.name_hash    = Dvar_HashName(name);
	d.type         = DVAR_TYPE_VEC2;
	d.domain.f.min = min;
	d.domain.f.max = max;
	d.value.v2     = value;
	d.e            = e;
	d.modified     = false;
	d.hasLatched   = false;

	return d;
}

dvar_t Dvar_CreateVec3(const char* name, int flags, 
	                   avec3f_t value, float min, float max
) {
	char** e = (char**)Dvar_Alloc(sizeof(*e));
	e[0] = (char*)Dvar_Alloc(32 + 1 + 32 + 1 + 32);
	size_t pos = A_itoa(value.x, e[0], 32);
	e[0][pos] = ' ';
	pos = A_itoa(value.y, &e[0][pos + 1], 32);
	e[0][pos] = ' ';
	A_itoa(value.y, &e[0][pos + 1], 32);

	dvar_t d;
	d.name         = (char*)name;
	d.name_hash    = Dvar_HashName(name);
	d.type         = DVAR_TYPE_VEC3;
	d.domain.f.min = min;
	d.domain.f.max = max;
	d.value.v3     = value;
	d.e            = e;
	d.modified     = false;
	d.hasLatched   = false;

	return d;
}

dvar_t Dvar_CreateVec4(const char* name, int flags, 
	                   avec4f_t value, float min, float max
) {
	char** e = (char**)Dvar_Alloc(sizeof(*e));
	e[0] = (char*)Dvar_Alloc(32 + 1 + 32 + 1 + 32 + 1 + 32);
	size_t pos = A_itoa(value.x, e[0], 32);
	e[0][pos] = ' ';
	pos = A_itoa(value.y, &e[0][pos + 1], 32);
	e[0][pos] = ' ';
	pos = A_itoa(value.y, &e[0][pos + 1], 32);
	e[0][pos] = ' ';
	A_itoa(value.y, &e[0][pos + 1], 32);

	dvar_t d;
	d.name         = (char*)name;
	d.name_hash    = Dvar_HashName(name);
	d.type         = DVAR_TYPE_VEC4;
	d.domain.f.min = min;
	d.domain.f.max = max;
	d.value.v4     = value;
	d.e            = e;
	d.modified     = false;
	d.hasLatched   = false;

	return d;
}


A_NO_DISCARD bool Dvar_GetBool(const dvar_t* d) {
	if (d->type != DVAR_TYPE_BOOL)
		return false;
	return d->value.b;
}

A_NO_DISCARD int Dvar_GetInt(const dvar_t* d) {
	if (d->type == DVAR_TYPE_INT)
		return d->value.i;
	else if (d->type == DVAR_TYPE_ENUM)
		return d->i;

	return 0;
}

A_NO_DISCARD float Dvar_GetFloat(const dvar_t* d) {
	if (d->type != DVAR_TYPE_FLOAT)
		return 0;
	return d->value.f;
}

A_NO_DISCARD const char* Dvar_GetString(const dvar_t* d) {
	if (d->type == DVAR_TYPE_ENUM)
		return d->e[d->i];
	return d->e[0];
}

A_NO_DISCARD avec2f_t Dvar_GetVec2(const dvar_t* d) {
	if (d->type != DVAR_TYPE_VEC2)
		return A_VEC2F_ZERO;
	return d->value.v2;
}

A_NO_DISCARD avec3f_t Dvar_GetVec3(const dvar_t* d) {
	if (d->type != DVAR_TYPE_VEC3)
		return A_VEC3F_ZERO;
	return d->value.v3;
}

A_NO_DISCARD avec4f_t Dvar_GetVec4(const dvar_t* d) {
	if (d->type != DVAR_TYPE_VEC4)
		return A_VEC4F_ZERO;
	return d->value.v4;
}

void Dvar_SetBool(A_INOUT dvar_t* d, bool b) {
	if (d->flags & DVAR_FLAG_READONLY)
		return;

	if (d->type == DVAR_TYPE_BOOL) {
		d->value.b = b;
		if (b)
			A_cstrncpyz(d->e[0], "true", 6);
		else
			A_cstrncpyz(d->e[0], "false", 6);
		d->modified = true;
	}
}

void Dvar_SetInt(A_INOUT dvar_t* d, int i) {
	if (d->flags & DVAR_FLAG_READONLY)
		return;

	if (d->type == DVAR_TYPE_INT &&
		(i <= d->domain.i.max && i >= d->domain.i.min)
	) {
		d->value.i = i;
		d->modified = true;
	}
	else if (d->type == DVAR_TYPE_ENUM && i < d->i) {
		d->i = i;
	}
}

void Dvar_SetFloat(A_INOUT dvar_t* d, float f) {
	if (d->flags & DVAR_FLAG_READONLY)
		return;

	if (d->type == DVAR_TYPE_FLOAT &&
		(f <= d->domain.f.max && f >= d->domain.f.min)
	) {
		d->value.f = f;
		A_ftoa(f, d->e[0], 32);
		d->modified = true;
	}
}

void Dvar_SetString(A_INOUT dvar_t* d, const char* s) {
	if (d->flags & DVAR_FLAG_READONLY)
		return;

	if (d->type == DVAR_TYPE_STRING) {
		d->e[0] = A_cstrdup(s);
		d->modified = true;
	} else if (d->type == DVAR_TYPE_ENUM) {
		d->e[d->i] = A_cstrdup(s);
		d->modified = true;
	}
}

void Dvar_SetVec2(A_INOUT dvar_t* d, avec2f_t v) {
	if (d->flags & DVAR_FLAG_READONLY)
		return;

	if (d->type == DVAR_TYPE_VEC2 &&
		(v.x <= d->domain.f.max && v.x >= d->domain.f.min) &&
		(v.y <= d->domain.f.max && v.y >= d->domain.f.min)
	) {
		d->value.v2 = v;
		size_t pos = A_ftoa(v.x, d->e[0], 32);
		d->e[0][pos] = ' ';
		A_ftoa(v.y, d->e[0] + pos + 1, 32);
		d->modified = true;
	}
}

void Dvar_SetVec3(A_INOUT dvar_t* d, avec3f_t v) {
	if (d->flags & DVAR_FLAG_READONLY)
		return;

	if (d->type == DVAR_TYPE_VEC3 &&
		(v.x <= d->domain.f.max && v.x >= d->domain.f.min) &&
		(v.y <= d->domain.f.max && v.y >= d->domain.f.min) &&
		(v.z <= d->domain.f.max && v.z >= d->domain.f.min)
	) {
		d->value.v3 = v;
		size_t pos = A_ftoa(v.x, d->e[0], 32);
		d->e[0][pos] = ' ';
		pos = A_ftoa(v.y, d->e[0] + pos + 1, 32);
		d->e[0][pos] = ' ';
		A_ftoa(v.z, d->e[0] + pos + 1, 32);
		d->modified = true;
		
	}
}

void Dvar_SetVec4(A_INOUT dvar_t* d, avec4f_t v) {
	if (d->flags & DVAR_FLAG_READONLY)
		return;

	if (d->type == DVAR_TYPE_VEC4 &&
		(v.x <= d->domain.f.max && v.x >= d->domain.f.min) &&
		(v.y <= d->domain.f.max && v.y >= d->domain.f.min) &&
		(v.z <= d->domain.f.max && v.z >= d->domain.f.min) &&
		(v.w <= d->domain.f.max && v.w >= d->domain.f.min)
	) {
		d->value.v4 = v;
		size_t pos = A_ftoa(v.x, d->e[0], 32);
		d->e[0][pos] = ' ';
		pos = A_ftoa(v.y, d->e[0] + pos + 1, 32);
		d->e[0][pos] = ' ';
		pos = A_ftoa(v.z, d->e[0] + pos + 1, 32);
		d->e[0][pos] = ' ';
		A_ftoa(v.w, d->e[0] + pos + 1, 32);
		d->modified = true;
	}
}

void Dvar_AddFlags(A_INOUT dvar_t* d, int flags) {
	d->flags |= flags;
}

void Dvar_ClearFlags(A_INOUT dvar_t* d, int flags) {
	d->flags &= ~flags;
}

A_NO_DISCARD bool Dvar_Exists(const char* name) {
	for (int i = 0; i < s_dvarCount; i++) {
		if (s_dvars[i] &&
			s_dvars[i]->name_hash == Dvar_HashName(name)) {
			return true;
		}
	}
	
	return false;
}

A_NO_DISCARD dvar_t* Dvar_Find(const char* name) {
	for (int i = 0; i < s_dvarCount; i++) {
		if (s_dvars[i] &&
			s_dvars[i]->name_hash == Dvar_HashName(name)) 
		{
			return s_dvars[i];
		}
	}

	return NULL;
}

static dvar_t** Dvar_TakeFreeDvar(void) {
	if (s_dvarCount < DVAR_MAX_DVARS) {
		dvar_t** d = &s_dvars[s_dvarCount++];
		assert(*d == NULL);
		return d;
	}

	for (int i = 0; i < DVAR_MAX_DVARS; i++) {
		if (s_dvars[i] == NULL)
			return &s_dvars[i];
	}
	
	return NULL;
}

static dvar_t* Dvar_RegisterDvar(const char* name, const dvar_t* d) {
	dvar_t** dvar = Dvar_TakeFreeDvar();
	if (d == NULL)
		return NULL;

	*dvar = (dvar_t*)Dvar_Alloc(sizeof(*d));
	A_memcpy(*dvar, d, sizeof(*d));
	(*dvar)->name = A_cstrdup(name);
	return *dvar;
}

static dvar_t* Dvar_RegisterNewDvar(const char* name, const dvar_t* d) {
	if (Dvar_Exists(name))
		return NULL;

	return Dvar_RegisterDvar(name, d);
}

dvar_t* Dvar_RegisterNewBool(
	const char* name, int flags, bool value
) {
	dvar_t d = Dvar_CreateBool(name, flags, value);
	return Dvar_RegisterNewDvar(name, &d);
}

dvar_t* Dvar_RegisterNewInt(
	const char* name, int flags, 
	int value, int min, int max
) {
	dvar_t d = Dvar_CreateInt(name, flags, value, min, max);
	return Dvar_RegisterNewDvar(name, &d);
}

dvar_t* Dvar_RegisterNewFloat(
	const char* name, int flags, 
	float value, float min, float max
) {
	dvar_t d = Dvar_CreateFloat(name, flags, value, min, max);
	return Dvar_RegisterNewDvar(name, &d);
}

dvar_t* Dvar_RegisterNewString(
	const char* name, int flags, 
	const char* value
) {
	dvar_t d = Dvar_CreateString(name, flags, value);
	return Dvar_RegisterNewDvar(name, &d);
}

dvar_t* Dvar_RegisterNewEnum(
	const char* name, int flags, int value,
	const char** domain, size_t domain_count
) {
	dvar_t d = Dvar_CreateEnum(name, flags, value, domain, domain_count);
	return Dvar_RegisterNewDvar(name, &d);
}

dvar_t* Dvar_RegisterNewVec2(
	const char* name, int flags, avec2f_t value, 
	float min, float max
) {
	dvar_t d = Dvar_CreateVec2(name, flags, value, min, max);
	return Dvar_RegisterNewDvar(name, &d);
}

dvar_t* Dvar_RegisterNewVec3(
	const char* name, int flags, avec3f_t value,
	float min, float max
) {
	dvar_t d = Dvar_CreateVec3(name, flags, value, min, max);
	return Dvar_RegisterNewDvar(name, &d);
}

dvar_t* Dvar_RegisterNewVec4(
	const char* name, int flags, avec4f_t value,
	float min, float max
) {
	dvar_t d = Dvar_CreateVec4(name, flags, value, min, max);
	return Dvar_RegisterNewDvar(name, &d);
}

static dvar_t* Dvar_ReregisterDvar(const char* name, const dvar_t* d) {
	if (!Dvar_Exists(name))
		return NULL;

	Dvar_Unregister(name);
	return Dvar_RegisterDvar(name, d);
}

dvar_t* Dvar_ReregisterBool(
	const char* name, int flags, bool value
) {
	dvar_t d = Dvar_CreateBool(name, flags, value);
	return Dvar_ReregisterDvar(name, &d);
}

dvar_t* Dvar_ReregisterInt(
	const char* name, int flags, 
	int value, int min, int max
) {
	dvar_t d = Dvar_CreateInt(name, flags, value, min, max);
	return Dvar_RegisterDvar(name, &d);
}

dvar_t* Dvar_ReregisterFloat(
	const char* name, int flags, 
	float value, float min, float max
) {
	dvar_t d = Dvar_CreateFloat(name, flags, value, min, max);
	return Dvar_RegisterDvar(name, &d);
}

dvar_t* Dvar_ReregisterString(
	const char* name, int flags, 
	const char* value
) {
	dvar_t d = Dvar_CreateString(name, flags, value);
	return Dvar_RegisterDvar(name, &d);
}

dvar_t* Dvar_ReregisterEnum(
	const char* name, int flags, 
	int value, const char** domain, size_t domain_count
) {
	dvar_t d = Dvar_CreateEnum(name, flags, value, domain, domain_count);
	return Dvar_RegisterDvar(name, &d);
}

dvar_t* Dvar_ReregisterVec2(
	const char* name, int flags, 
	avec2f_t value, float min, float max
) {
	dvar_t d = Dvar_CreateVec2(name, flags, value, min, max);
	return Dvar_RegisterDvar(name, &d);
}

dvar_t* Dvar_ReregisterVec3(
	const char* name, int flags,
	avec3f_t value, float min, float max
) {
	dvar_t d = Dvar_CreateVec3(name, flags, value, min, max);
	return Dvar_RegisterDvar(name, &d);
}

dvar_t* Dvar_ReregisterVec4(
	const char* name, int flags,
	avec4f_t value, float min, float max
) {
	dvar_t d = Dvar_CreateVec4(name, flags, value, min, max);
	return Dvar_RegisterDvar(name, &d);
}

dvar_t* Dvar_RegisterBool(
	const char* name, int flags, bool value
) {
	if (Dvar_Exists(name))
		return Dvar_ReregisterBool(name, flags, value);
	else
		return Dvar_RegisterNewBool(name, flags, value);
}

dvar_t* Dvar_RegisterInt(
	const char* name, int flags, int value, int min, int max
) {
	if (Dvar_Exists(name))
		return Dvar_ReregisterInt(name, flags, value, min, max);
	else
		return Dvar_RegisterNewInt(name, flags, value, min, max);
}

dvar_t* Dvar_RegisterFloat(
	const char* name, int flags, 
	float value, float min, float max
) {
	if (Dvar_Exists(name))
		return Dvar_ReregisterFloat(name, flags, value, min, max);
	else
		return Dvar_RegisterNewFloat(name, flags, value, min, max);
}

dvar_t* Dvar_RegisterString(
	const char* name, int flags, const char* value
) {
	if (Dvar_Exists(name))
		return Dvar_ReregisterString(name, flags, value);
	else
		return Dvar_RegisterNewString(name, flags, value);
}

dvar_t* Dvar_RegisterEnum(
	const char* name, int flags, 
	int value, const char** domain, size_t domain_count
) {
	if (Dvar_Exists(name))
		return Dvar_ReregisterEnum(name, flags, value, domain, domain_count);
	else
		return Dvar_RegisterNewEnum(name, flags, value, domain, domain_count);
}

dvar_t* Dvar_RegisterVec2(
	const char* name, int flags, 
	avec2f_t value, float min, float max
) {
	if (Dvar_Exists(name))
		return Dvar_ReregisterVec2(name, flags, value, min, max);
	else
		return Dvar_RegisterNewVec2(name, flags, value, min, max);
}

dvar_t* Dvar_RegisterVec3(
	const char* name, int flags, 
	avec3f_t value, float min, float max
) {
	if (Dvar_Exists(name))
		return Dvar_ReregisterVec3(name, flags, value, min, max);
	else
		return Dvar_RegisterNewVec3(name, flags, value, min, max);
}

dvar_t* Dvar_RegisterVec4(
	const char* name, int flags, 
	avec4f_t value, float min, float max
) {
	if (Dvar_Exists(name))
		return Dvar_ReregisterVec4(name, flags, value, min, max);
	else
		return Dvar_RegisterNewVec4(name, flags, value, min, max);
}

bool Dvar_Unregister(const char* name) {
	for (int i = 0; i < s_dvarCount; i++) {
		if (s_dvars[i] && s_dvars[i]->name_hash == Dvar_HashName(name)) {
			dvar_t** d = &s_dvars[i];
			Dvar_DestroyDvar(*d);
			Dvar_Free(*d);
			*d = NULL;
			return true;
		}
	}

	return false;
}

void Dvar_ClearDvars(void) {
	for (int i = 0; i < s_dvarCount; i++) {
		dvar_t** d = &s_dvars[i];
		if (*d != NULL) {
			Dvar_DestroyDvar(*d);
			Dvar_Free(*d);
			*d = NULL;
		}
	}
}

static dvar_t* s_localDvars[MAX_LOCAL_CLIENTS][DVAR_MAX_DVARS];
static int s_localDvarCount;

A_NO_DISCARD bool Dvar_LocalExists(int localClientNum, const char* name) {
	for (int i = 0; i < s_localDvarCount; i++) {
		if (s_localDvars[localClientNum][i] &&
			s_localDvars[localClientNum][i]->name_hash == Dvar_HashName(name)
		) {
			return true;
		}
	}

	return false;
}

A_NO_DISCARD dvar_t* Dvar_FindLocal(int localClientNum, const char* name) {
	for (int i = 0; i < s_localDvarCount; i++) {
		if (s_localDvars[localClientNum][i] &&
			s_localDvars[localClientNum][i]->name_hash == Dvar_HashName(name)
		) {
			return s_localDvars[localClientNum][i];
		}
	}

	return NULL;
}

static dvar_t** Dvar_TakeFreeLocalDvar(int localClientNum) {
	if (s_localDvarCount < DVAR_MAX_DVARS) {
		dvar_t** d = &s_localDvars[localClientNum][s_localDvarCount++];
		assert(*d == NULL);
		return d;
	}

	for (int i = 0; i < DVAR_MAX_DVARS; i++) {
		if (s_localDvars[localClientNum][i] == NULL)
			return &s_localDvars[localClientNum][i];
	}

	return NULL;
}

static dvar_t* Dvar_RegisterLocalDvar(int localClientNum, 
	                                  const char* name, 
									  const dvar_t* d
) {
	dvar_t** dvar = Dvar_TakeFreeLocalDvar(localClientNum);
	if (d == NULL)
		return NULL;

	*dvar = (dvar_t*)Dvar_Alloc(sizeof(*d));
	A_memcpy(*dvar, d, sizeof(*d));
	(*dvar)->name = A_cstrdup(name);
	return *dvar;
}

static dvar_t* Dvar_RegisterNewLocalDvar(int localClientNum, 
	                                     const char* name, 
										 const dvar_t* d
) {
	if (Dvar_LocalExists(localClientNum, name))
		return NULL;

	return Dvar_RegisterLocalDvar(localClientNum, name, d);
}

dvar_t* Dvar_RegisterNewLocalBool(int localClientNum,
	const char* name, int flags, bool value
) {
	dvar_t d = Dvar_CreateBool(name, flags, value);
	return Dvar_RegisterNewLocalDvar(localClientNum, name, &d);
}

dvar_t* Dvar_RegisterNewLocalInt(int localClientNum,
	const char* name, int flags,
	int value, int min, int max
) {
	dvar_t d = Dvar_CreateInt(name, flags, value, min, max);
	return Dvar_RegisterNewLocalDvar(localClientNum, name, &d);
}

dvar_t* Dvar_RegisterNewLocalFloat(int localClientNum,
	const char* name, int flags,
	float value, float min, float max
) {
	dvar_t d = Dvar_CreateFloat(name, flags, value, min, max);
	return Dvar_RegisterNewLocalDvar(localClientNum, name, &d);
}

dvar_t* Dvar_RegisterNewLocalString(int localClientNum,
	const char* name, int flags,
	const char* value
) {
	dvar_t d = Dvar_CreateString(name, flags, value);
	return Dvar_RegisterNewLocalDvar(localClientNum, name, &d);
}

dvar_t* Dvar_RegisterNewLocalEnum(int localClientNum,
	const char* name, int flags, int value,
	const char** domain, size_t domain_count
) {
	dvar_t d = Dvar_CreateEnum(name, flags, value, domain, domain_count);
	return Dvar_RegisterNewLocalDvar(localClientNum, name, &d);
}

dvar_t* Dvar_RegisterNewLocalVec2(int localClientNum,
	const char* name, int flags, avec2f_t value,
	float min, float max
) {
	dvar_t d = Dvar_CreateVec2(name, flags, value, min, max);
	return Dvar_RegisterNewLocalDvar(localClientNum, name, &d);
}

dvar_t* Dvar_RegisterNewLocalVec3(int localClientNum,
	const char* name, int flags, avec3f_t value,
	float min, float max
) {
	dvar_t d = Dvar_CreateVec3(name, flags, value, min, max);
	return Dvar_RegisterNewLocalDvar(localClientNum, name, &d);
}

dvar_t* Dvar_RegisterNewLocalVec4(int localClientNum,
	const char* name, int flags, avec4f_t value,
	float min, float max
) {
	dvar_t d = Dvar_CreateVec4(name, flags, value, min, max);
	return Dvar_RegisterNewLocalDvar(localClientNum, name, &d);
}

static dvar_t* Dvar_ReregisterLocalDvar(int localClientNum, 
	                                    const char* name, 
										const dvar_t* d
) {
	if (!Dvar_LocalExists(localClientNum, name))
		return NULL;

	Dvar_UnregisterLocal(localClientNum, name);
	return Dvar_RegisterLocalDvar(localClientNum, name, d);
}

dvar_t* Dvar_ReregisterLocalBool(int localClientNum,
	const char* name, int flags, bool value
) {
	dvar_t d = Dvar_CreateBool(name, flags, value);
	return Dvar_ReregisterLocalDvar(localClientNum, name, &d);
}

dvar_t* Dvar_ReregisterLocalInt(int localClientNum,
	const char* name, int flags,
	int value, int min, int max
) {
	dvar_t d = Dvar_CreateInt(name, flags, value, min, max);
	return Dvar_RegisterLocalDvar(localClientNum, name, &d);
}

dvar_t* Dvar_ReregisterLocalFloat(int localClientNum,
	const char* name, int flags,
	float value, float min, float max
) {
	dvar_t d = Dvar_CreateFloat(name, flags, value, min, max);
	return Dvar_RegisterLocalDvar(localClientNum, name, &d);
}

dvar_t* Dvar_ReregisterLocalString(int localClientNum,
	const char* name, int flags,
	const char* value
) {
	dvar_t d = Dvar_CreateString(name, flags, value);
	return Dvar_RegisterLocalDvar(localClientNum, name, &d);
}

dvar_t* Dvar_ReregisterLocalEnum(int localClientNum,
	const char* name, int flags,
	int value, const char** domain, size_t domain_count
) {
	dvar_t d = Dvar_CreateEnum(name, flags, value, domain, domain_count);
	return Dvar_RegisterLocalDvar(localClientNum, name, &d);
}

dvar_t* Dvar_ReregisterLocalVec2(int localClientNum,
	const char* name, int flags,
	avec2f_t value, float min, float max
) {
	dvar_t d = Dvar_CreateVec2(name, flags, value, min, max);
	return Dvar_RegisterLocalDvar(localClientNum, name, &d);
}

dvar_t* Dvar_ReregisterLocalVec3(int localClientNum,
	const char* name, int flags,
	avec3f_t value, float min, float max
) {
	dvar_t d = Dvar_CreateVec3(name, flags, value, min, max);
	return Dvar_RegisterLocalDvar(localClientNum, name, &d);
}

dvar_t* Dvar_ReregisterLocalVec4(int localClientNum,
	const char* name, int flags,
	avec4f_t value, float min, float max
) {
	dvar_t d = Dvar_CreateVec4(name, flags, value, min, max);
	return Dvar_RegisterLocalDvar(localClientNum, name, &d);
}

dvar_t* Dvar_RegisterLocalBool(int localClientNum,
	const char* name, int flags, bool value
) {
	if (Dvar_LocalExists(localClientNum, name))
		return Dvar_ReregisterLocalBool(localClientNum, name, flags, value);
	else
		return Dvar_RegisterNewLocalBool(localClientNum, name, flags, value);
}

dvar_t* Dvar_RegisterLocalInt(int localClientNum,
	const char* name, int flags, int value, int min, int max
) {
	if (Dvar_LocalExists(localClientNum, name))
		return Dvar_ReregisterLocalInt(localClientNum, name, flags, 
			                           value, min, max);
	else
		return Dvar_RegisterNewLocalInt(localClientNum, name, flags, 
			                            value, min, max);
}

dvar_t* Dvar_RegisterLocalFloat(int localClientNum,
	const char* name, int flags,
	float value, float min, float max
) {
	if (Dvar_LocalExists(localClientNum, name))
		return Dvar_ReregisterLocalFloat(localClientNum, name, flags, 
			                             value, min, max);
	else
		return Dvar_RegisterNewLocalFloat(localClientNum, name, flags, 
			                              value, min, max);
}

dvar_t* Dvar_RegisterLocalString(int localClientNum,
	const char* name, int flags, const char* value
) {
	if (Dvar_LocalExists(localClientNum, name))
		return Dvar_ReregisterLocalString(localClientNum, name, flags, value);
	else
		return Dvar_RegisterNewLocalString(localClientNum, name, flags, value);
}

dvar_t* Dvar_RegisterLocalEnum(int localClientNum,
	const char* name, int flags,
	int value, const char** domain, size_t domain_count
) {
	if (Dvar_LocalExists(localClientNum, name))
		return Dvar_ReregisterLocalEnum(localClientNum, name, flags, 
			                            value, domain, domain_count);
	else
		return Dvar_RegisterNewLocalEnum(localClientNum, name, flags, 
			                             value, domain, domain_count);
}

dvar_t* Dvar_RegisterLocalVec2(int localClientNum,
	const char* name, int flags,
	avec2f_t value, float min, float max
) {
	if (Dvar_LocalExists(localClientNum, name))
		return Dvar_ReregisterLocalVec2(localClientNum, name, flags, 
			                            value, min, max);
	else
		return Dvar_RegisterNewLocalVec2(localClientNum, name, flags, 
			                             value, min, max);
}

dvar_t* Dvar_RegisterLocalVec3(int localClientNum,
	const char* name, int flags,
	avec3f_t value, float min, float max
) {
	if (Dvar_LocalExists(localClientNum, name))
		return Dvar_ReregisterLocalVec3(localClientNum, name, flags, 
			                            value, min, max);
	else
		return Dvar_RegisterNewLocalVec3(localClientNum, name, flags, 
			                             value, min, max);
}

dvar_t* Dvar_RegisterLocalVec4(int localClientNum,
	const char* name, int flags,
	avec4f_t value, float min, float max
) {
	if (Dvar_LocalExists(localClientNum, name))
		return Dvar_ReregisterLocalVec4(localClientNum, name, flags, 
			                            value, min, max);
	else
		return Dvar_RegisterNewLocalVec4(localClientNum, name, flags, 
			                             value, min, max);
}

bool Dvar_UnregisterLocal(int localClientNum, const char* name) {
	for (int i = 0; i < s_localDvarCount; i++) {
		if (s_localDvars[localClientNum][i] &&
			s_localDvars[localClientNum][i]->name_hash == Dvar_HashName(name)
		) {
			dvar_t** d = &s_localDvars[localClientNum][i];
			Dvar_DestroyDvar(*d);
			Dvar_Free(*d);
			*d = NULL;
			return true;
		}
	}

	return false;
}

void Dvar_ClearLocalDvars(int localClientNum) {
	for (int i = 0; i < s_localDvarCount; i++) {
		dvar_t** d = &s_localDvars[localClientNum][i];
		if (*d != NULL) {
			Dvar_DestroyDvar(*d);
			Dvar_Free(*d);
			*d = NULL;
		}
	}
}

bool Dvar_SetFromString(A_INOUT dvar_t* d, int argc, const char** argv) {
	assert(d);
	assert(argc > 0);
	assert(argv);
	
	if (argc == 4 && d->type == DVAR_TYPE_VEC4) {
		avec4f_t v;
		A_atof(argv[0], &v.x);
		A_atof(argv[1], &v.y);
		A_atof(argv[2], &v.z);
		A_atof(argv[3], &v.w);
		Dvar_SetVec4(d, v);
		return true;
	} 
	if (argc == 3 && d->type == DVAR_TYPE_VEC3) {
		avec3f_t v;
		A_atof(argv[0], &v.x);
		A_atof(argv[1], &v.y);
		A_atof(argv[2], &v.z);
		Dvar_SetVec3(d, v);
		return true;
	}
	if (argc == 2 && d->type == DVAR_TYPE_VEC2) {
		avec2f_t v;
		A_atof(argv[0], &v.x);
		A_atof(argv[1], &v.y);
		Dvar_SetVec2(d, v);
		return true;
	}
	
	if (d->type == DVAR_TYPE_BOOL) {
		bool b = false;
		A_atob(argv[0], &b);
		Dvar_SetBool(d, b);
		return true;
	}

	if (d->type == DVAR_TYPE_FLOAT) {
		float f = 0.0f;
		A_atof(argv[0], &f);
		Dvar_SetFloat(d, f);
		return true;
	}

	if (d->type == DVAR_TYPE_INT) {
		int i = 0;
		A_atoi(argv[0], &i);
		Dvar_SetInt(d, i);
		return true;
	}

	return false;
}

dvar_t* Dvar_RegisterNewFromString(const char* name, int flags,
	                               int argc, const char** argv
) {
	assert(argc > 0);
	assert(argv);
	assert(name);
	if (argc == 4) {
		avec4f_t v;
		A_atof(argv[0], &v.x);
		A_atof(argv[1], &v.y);
		A_atof(argv[2], &v.z);
		A_atof(argv[3], &v.w);
		return Dvar_RegisterNewVec4(name, flags, v, FLT_MIN, FLT_MAX);
	}

	if (argc == 3) {
		avec3f_t v;
		A_atof(argv[0], &v.x);
		A_atof(argv[1], &v.y);
		A_atof(argv[2], &v.z);
		return Dvar_RegisterNewVec3(name, flags, v, FLT_MIN, FLT_MAX);
	}

	if (argc == 2) {
		avec2f_t v;
		A_atof(argv[0], &v.x);
		A_atof(argv[1], &v.y);
		return Dvar_RegisterNewVec2(name, flags, v, FLT_MIN, FLT_MAX);
	}

	int i = 0;
	if (A_atoi(argv[0], &i))
		return Dvar_RegisterNewInt(name, flags, i, INT_MIN, INT_MAX);
	bool b = false;
	if (A_atob(argv[0], &b))
		return Dvar_RegisterNewBool(name, flags, b);
	float f = 0.0f;
	if (A_atof(name, &f))
		return Dvar_RegisterNewFloat(name, flags, f, FLT_MIN, FLT_MAX);

	return NULL;
}

dvar_t* Dvar_ReregisterFromString(const char* name, int flags, 
	                              int argc, const char** argv
) {
	assert(argc > 0);
	assert(argv);
	assert(name);
	if (argc == 4) {
		avec4f_t v;
		A_atof(argv[0], &v.x);
		A_atof(argv[1], &v.y);
		A_atof(argv[2], &v.z);
		A_atof(argv[3], &v.w);
		return Dvar_ReregisterVec4(name, flags, v, FLT_MIN, FLT_MAX);
	}

	if (argc == 3) {
		avec3f_t v;
		A_atof(argv[0], &v.x);
		A_atof(argv[1], &v.y);
		A_atof(argv[2], &v.z);
		return Dvar_ReregisterVec3(name, flags, v, FLT_MIN, FLT_MAX);
	}

	if (argc == 2) {
		avec2f_t v;
		A_atof(argv[0], &v.x);
		A_atof(argv[1], &v.y);
		return Dvar_ReregisterVec2(name, flags, v, FLT_MIN, FLT_MAX);
	}

	int i = 0;
	if (A_atoi(argv[0], &i))
		return Dvar_ReregisterInt(name, flags, i, INT_MIN, INT_MAX);
	bool b = false;
	if (A_atob(argv[0], &b))
		return Dvar_ReregisterBool(name, flags, b);
	float f = 0.0f;
	if (A_atof(name, &f))
		return Dvar_ReregisterFloat(name, flags, f, FLT_MIN, FLT_MAX);

	return NULL;
}

dvar_t* Dvar_RegisterFromString(const char* name, int flags,
	                           int argc, const char** argv
) {
	if (Dvar_Exists(name))
		return Dvar_ReregisterFromString(name, flags, argc, argv);
	return Dvar_RegisterNewFromString(name, flags, argc, argv);
}

dvar_t* Dvar_RegisterNewLocalFromString(int localClientNum, const char* name, 
	                               int flags, int argc, const char** argv
) {
	assert(argc > 0);
	assert(argv);
	assert(name);
	if (argc == 4) {
		avec4f_t v;
		A_atof(argv[0], &v.x);
		A_atof(argv[1], &v.y);
		A_atof(argv[2], &v.z);
		A_atof(argv[3], &v.w);
		return Dvar_RegisterNewLocalVec4(localClientNum, name, flags,
			                             v, FLT_MIN, FLT_MAX);
	}

	if (argc == 3) {
		avec3f_t v;
		A_atof(argv[0], &v.x);
		A_atof(argv[1], &v.y);
		A_atof(argv[2], &v.z);
		return Dvar_RegisterNewLocalVec3(localClientNum, name, flags,
			                             v, FLT_MIN, FLT_MAX);
	}

	if (argc == 2) {
		avec2f_t v;
		A_atof(argv[0], &v.x);
		A_atof(argv[1], &v.y);
		return Dvar_RegisterNewLocalVec2(localClientNum, name, flags, 
			                             v, FLT_MIN, FLT_MAX);
	}

	int i = 0;
	if (A_atoi(argv[0], &i))
		return Dvar_RegisterNewLocalInt(localClientNum, name, flags, 
			                            i, INT_MIN, INT_MAX);
	bool b = false;
	if (A_atob(argv[0], &b))
		return Dvar_RegisterNewLocalBool(localClientNum, name, flags, b);
	float f = 0.0f;
	if (A_atof(name, &f))
		return Dvar_RegisterNewLocalFloat(localClientNum, name, flags, 
			                              f, FLT_MIN, FLT_MAX);

	return NULL;
}

dvar_t* Dvar_ReregisterLocalFromString(int localClientNum, const char* name,
	                                   int flags, int argc, const char** argv
) {
	assert(argc > 0);
	assert(argv);
	assert(name);
	if (argc == 4) {
		avec4f_t v;
		A_atof(argv[0], &v.x);
		A_atof(argv[1], &v.y);
		A_atof(argv[2], &v.z);
		A_atof(argv[3], &v.w);
		return Dvar_ReregisterLocalVec4(localClientNum, name, flags, 
			                            v, FLT_MIN, FLT_MAX);
	}

	if (argc == 3) {
		avec3f_t v;
		A_atof(argv[0], &v.x);
		A_atof(argv[1], &v.y);
		A_atof(argv[2], &v.z);
		return Dvar_ReregisterLocalVec3(localClientNum, name, flags, 
			                            v, FLT_MIN, FLT_MAX);
	}

	if (argc == 2) {
		avec2f_t v;
		A_atof(argv[0], &v.x);
		A_atof(argv[1], &v.y);
		return Dvar_ReregisterLocalVec2(localClientNum, name, flags, 
			                            v, FLT_MIN, FLT_MAX);
	}

	int i = 0;
	if (A_atoi(argv[0], &i))
		return Dvar_ReregisterLocalInt(localClientNum, name, flags, 
			                           i, INT_MIN, INT_MAX);
	bool b = false;
	if (A_atob(argv[0], &b))
		return Dvar_ReregisterLocalBool(localClientNum, name, flags, b);
	float f = 0.0f;
	if (A_atof(name, &f))
		return Dvar_ReregisterLocalFloat(localClientNum, name, flags, 
			                             f, FLT_MIN, FLT_MAX);

	return NULL;
}

dvar_t* Dvar_RegisterLocalFromString(int localClientNum, const char* name,
	                                 int flags, int argc, const char** argv
) {
	if (Dvar_LocalExists(localClientNum, name))
		return Dvar_ReregisterLocalFromString(localClientNum, name, flags, argc, argv);
	return Dvar_RegisterNewLocalFromString(localClientNum, name, flags, argc, argv);
}

void Dvar_Set_f(void) {
	int argc = Cmd_Argc();
	if (argc < 3) {
		Com_Println(CON_DEST_CLIENT, "USAGE: set <variable> <value>");
		return;
	}

	const char* name = Cmd_Argv(1);

	const char* argv[4];
	if (argc <= 3)
		argv[0] = Cmd_Argv(2);
	if (argc <= 4)
		argv[1] = Cmd_Argv(3);
	if (argc <= 5)
		argv[2] = Cmd_Argv(4);
	if (argc <= 6)
		argv[3] = Cmd_Argv(5);

	dvar_t* d = Dvar_Find(name);
	if (d) {
		if (!Dvar_SetFromString(d, A_MIN(argc - 2, 4), argv))
			Dvar_ReregisterFromString(
				name, DVAR_FLAG_NONE, A_MIN(argc - 2, 4), argv);
	} else {
		Dvar_RegisterNewFromString(
			name, DVAR_FLAG_NONE, A_MIN(argc - 2, 4), argv);
	}
}

void Dvar_SetA_f(void) {
	int argc = Cmd_Argc();
	if (argc < 3) {
		Com_Println(CON_DEST_CLIENT, "USAGE: seta <variable> <value>");
		return;
	}

	Dvar_Set_f();
	const char* name = Cmd_Argv(1);
	dvar_t* d = Dvar_Find(name);
	Dvar_AddFlags(d, DVAR_FLAG_ARCHIVE);
}

void Dvar_SetL_f(void) {
	int argc = Cmd_Argc();
	if (argc < 3) {
		Com_Println(CON_DEST_CLIENT, "USAGE: setl <variable> <value>");
		return;
	}

	const char* name = Cmd_Argv(1);

	const char* argv[4];
	if (argc <= 3)
		argv[0] = Cmd_Argv(2);
	if (argc <= 4)
		argv[1] = Cmd_Argv(3);
	if (argc <= 5)
		argv[2] = Cmd_Argv(4);
	if (argc <= 6)
		argv[3] = Cmd_Argv(5);

#if !A_TARGET_PLATFORM_IS_XBOX
	int activeLocalClient = CL_ClientWithKbmFocus();
	dvar_t* d = Dvar_FindLocal(activeLocalClient, name);
	if (d) {
		if (!Dvar_SetFromString(d, A_MIN(argc - 2, 4), argv))
			Dvar_ReregisterLocalFromString(activeLocalClient,
				name, DVAR_FLAG_NONE, A_MIN(argc - 2, 4), argv);
	} else {
		Dvar_RegisterNewLocalFromString(activeLocalClient,
			name, DVAR_FLAG_NONE, A_MIN(argc - 2, 4), argv);
	}
#else
	assert(false && "unimplemented"); // FIXME
#endif // !A_TARGET_PLATFORM_IS_XBOX
}

void Dvar_SetLA_f(void) {
	int argc = Cmd_Argc();
	if (argc < 3) {
		Com_Println(CON_DEST_CLIENT, "USAGE: setla <variable> <value>");
		return;
	}

	Dvar_SetL_f();
	const char* name = Cmd_Argv(1);

#if !A_TARGET_PLATFORM_IS_XBOX
	int activeLocalClient = CL_ClientWithKbmFocus();
	dvar_t* d = Dvar_FindLocal(activeLocalClient, name);
	Dvar_AddFlags(d, DVAR_FLAG_ARCHIVE);
#else
	assert(false && "unimplemented"); // FIXME
#endif // !A_TARGET_PLATFORM_IS_XBOX
}


void Dvar_Shutdown(void) {
	Cmd_RemoveCommand("set");
	Cmd_RemoveCommand("seta");
	Cmd_RemoveCommand("setl");
	Cmd_RemoveCommand("setla");

	Dvar_ClearDvars();
	for(size_t i = 0; i < MAX_LOCAL_CLIENTS; i++)
		Dvar_ClearLocalDvars(i);
}
