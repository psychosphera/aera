#include "devgui.h"

#include <assert.h>

#include "acommon/a_string.h"
#include "acommon/z_mem.h"

//#include "cl_client.hpp"
typedef enum KeyFocus {
	KF_DEVGUI,
	KF_GAME,
} KeyFocus;
KeyFocus CL_KeyFocus(size_t localClientNum);

#include "gfx_text.h"
#include "in_input.h"

typedef struct dgl_t {
	size_t promptDrawId;
	char   buffer[DEVGUI_MAX_BUFFER];
	size_t buffer_idx;
	char*  saved_lines[DEVGUI_MAX_SAVED_LINES];
	size_t saved_idx;
} dgl_t;

dgl_t s_dgl[MAX_LOCAL_CLIENTS];
 
const RectDef devgui_rect = { .x = 0.1f, .y = 0.8f, .w = 0.8f, .h = 0.2f };

A_EXTERN_C dgl_t* DevGui_GetLocalClientLocals(size_t localClientNum) {
	assert(localClientNum < MAX_LOCAL_CLIENTS);
	return &s_dgl[localClientNum];
}

A_EXTERN_C void DevGui_Init() {
	for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
		dgl_t* dgl = DevGui_GetLocalClientLocals(i);
		A_cstrncpyz(dgl->buffer, "> ", sizeof(dgl->buffer));
		dgl->buffer_idx = 0;

		dgl->saved_idx = 0;
		
		acolor_rgb_t color = A_color_rgb(0.9f, 0.2f, 0.2f);
		R_AddTextDrawDef(
			i, NULL, &devgui_rect, dgl->buffer,
			1.0f, 1.0f, color,
			false, false, &dgl->promptDrawId
		);
	}
}

A_EXTERN_C bool DevGui_HasText(size_t localClientNum) {
	return A_cstrchr(
		DevGui_GetLocalClientLocals(localClientNum)->buffer, '\n');
}

A_EXTERN_C void DevGui_SaveLine(size_t localClientNum, const char* line) {
	dgl_t* dgl = DevGui_GetLocalClientLocals(localClientNum);
	
	if (dgl->saved_idx == DEVGUI_MAX_SAVED_LINES - 1) {
		for (size_t i = 0; i < DEVGUI_MAX_SAVED_LINES - 2; i++) 
			dgl->saved_lines[i] = dgl->saved_lines[i + 1];
		dgl->saved_lines[DEVGUI_MAX_SAVED_LINES - 1] = A_cstrdup(line);
		return;

	}
	dgl->saved_lines[dgl->saved_idx++] = A_cstrdup(line);
}

A_EXTERN_C char* DevGui_TakeText(size_t localClientNum) {
	dgl_t* dgl = DevGui_GetLocalClientLocals(localClientNum);

	size_t n = A_cstrchr(dgl->buffer, '\n');
	size_t pos = n == A_NPOS ? A_cstrlen(dgl->buffer) : n;
	size_t len = pos - 2;
	char* input = Z_Alloc(len + 1);
	A_memcpy(input, dgl->buffer + 2, len);
	input[len] = '\0';
	A_memset(dgl->buffer + 2, 0, len);
	DevGui_SaveLine(localClientNum, input);
	return input;
}

static void DevGui_PushChar(size_t localClientNum, char c) {
	dgl_t* dgl = DevGui_GetLocalClientLocals(localClientNum);
	if (dgl->buffer_idx == sizeof(dgl->buffer) - 1)
		return;
	dgl->buffer[dgl->buffer_idx++] = c;
}

static char DevGui_PopChar(size_t localClientNum) {
	dgl_t* dgl = DevGui_GetLocalClientLocals(localClientNum);
	if (dgl->buffer_idx == 0)
		return 0;
	return dgl->buffer[dgl->buffer_idx--];
}

A_EXTERN_C void DevGui_Frame() {
	for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
		dgl_t* dgl = DevGui_GetLocalClientLocals(i);
		if (CL_KeyFocus(i) != KF_DEVGUI) {
			R_ActivateTextDrawDef(i, dgl->promptDrawId, false);
			continue;
		}

		size_t nKeys = 0;
		Keycode* keys = IN_Key_AllPressedOnCurrentFrame(i, &nKeys);
		for (size_t j = 0; j < nKeys; j++) {
			Keycode* k = &keys[j];
			char c = IN_Key_Char(i, *k);
			if (c != 0 && *k != IN_KEYCODE_TILDE)
				DevGui_PushChar(i, c);
			else if (*k == IN_KEYCODE_BACKSPACE && dgl->buffer_idx > 2)
				DevGui_PopChar(i);
			else if (*k == IN_KEYCODE_DELETE) {
				A_cstrncpyz(dgl->buffer, "> ", sizeof(dgl->buffer));
				dgl->buffer_idx = 2;
			}
			else if (*k == IN_KEYCODE_UP_ARROW) {
				if (dgl->saved_idx > 0) {
					A_cstrncpyz(dgl->buffer, "> ", sizeof(dgl->buffer));
					A_cstrncpyz(dgl->buffer + 2, 
						        dgl->saved_lines[--dgl->saved_idx], 
						        sizeof(dgl->buffer) - 2);
					dgl->buffer_idx = A_cstrlen(dgl->buffer);
				}
			}
			else if (*k == IN_KEYCODE_DOWN_ARROW) {
				if (dgl->saved_idx + 1 < DEVGUI_MAX_SAVED_LINES &&
					A_cstrlen(dgl->saved_lines[dgl->saved_idx + 1]) > 0
				) {
					A_cstrncpyz(dgl->buffer, "> ", sizeof(dgl->buffer));
					A_cstrncpyz(dgl->buffer + 2, 
						        dgl->saved_lines[++dgl->saved_idx], 
						        sizeof(dgl->buffer) - 2);
					dgl->buffer_idx = A_cstrlen(dgl->buffer);
				}
			}
		}

		R_UpdateTextDrawDef(i, dgl->promptDrawId, dgl->buffer);
		R_ActivateTextDrawDef(i, dgl->promptDrawId, true);
	}
}

A_EXTERN_C void DevGui_Shutdown() {
	for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
		dgl_t* dgl = DevGui_GetLocalClientLocals(i);
		R_RemoveTextDrawDef(i, dgl->promptDrawId);
		A_memset(dgl->buffer, 0, sizeof(dgl->buffer));
		dgl->buffer_idx = 0;
		dgl->saved_idx = 0;
	}
}
