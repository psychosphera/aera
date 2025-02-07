#include "devgui.hpp"

#include <array>

#include "cl_client.hpp"
#include "gfx_text.hpp"
#include "in_input.hpp"

struct dgl_t {
	size_t promptDrawId;
	std::string buffer;
	std::string saved_lines[DEVGUI_MAX_SAVED_LINES];
	size_t saved_idx;
};

std::array<dgl_t, MAX_LOCAL_CLIENTS> s_dgl;
 
constexpr RectDef devgui_rect = { .x = 0.1f, .y = 0.8f, .w = 0.8f, .h = 0.2f };

dgl_t& DevGui_GetLocalClientLocals(size_t localClientNum) {
	return s_dgl.at(localClientNum);
}

void DevGui_Init() {
	for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
		dgl_t& dgl = DevGui_GetLocalClientLocals(i);
		dgl.saved_idx = 0;
		dgl.buffer = "> ";

		R_AddTextDrawDef(
			i, nullptr, devgui_rect, dgl.buffer,
			1.0f, 1.0f, glm::vec3(0.9f, 0.2f, 0.2f),
			false, false, dgl.promptDrawId
		);
	}
}

bool DevGui_HasText(size_t localClientNum) {
	return DevGui_GetLocalClientLocals(localClientNum).buffer.contains('\n');
}

void DevGui_SaveLine(size_t localClientNum, const std::string& line) {
	dgl_t& dgl = DevGui_GetLocalClientLocals(localClientNum);
	
	if (dgl.saved_idx == DEVGUI_MAX_SAVED_LINES - 1) {
		for (size_t i = 0; i < DEVGUI_MAX_SAVED_LINES - 2; i++) 
			dgl.saved_lines[i] = dgl.saved_lines[i + 1];
		dgl.saved_lines[DEVGUI_MAX_SAVED_LINES - 1] = line;
		return;

	}
	dgl.saved_lines[dgl.saved_idx++] = line;
}

std::string DevGui_TakeText(size_t localClientNum) {
	dgl_t& dgl = DevGui_GetLocalClientLocals(localClientNum);

	size_t pos = dgl.buffer.find('\n');
	size_t len = pos - 2;
	std::string input = dgl.buffer.substr(2, len);
	dgl.buffer.erase(2, len + 1);
	DevGui_SaveLine(localClientNum, input);
	return input;
}

void DevGui_Frame() {
	for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
		dgl_t& dgl = DevGui_GetLocalClientLocals(i);
		if (CL_KeyFocus(i) != KF_DEVGUI) {
			R_ActivateTextDrawDef(i, dgl.promptDrawId, false);
			continue;
		}

 		for (auto k : IN_Key_AllPressedOnCurrentFrame(i)) {
			char c = IN_Key_Char(i, k);
			if (c != 0 && k != SDLK_BACKQUOTE)
				dgl.buffer.push_back(c);
			else if (k == SDLK_BACKSPACE && dgl.buffer.length() > 2)
				dgl.buffer.pop_back();
			else if (k == SDLK_DELETE)
				dgl.buffer = "> ";
			else if (k == SDLK_UP) {
				if (dgl.saved_idx > 0)
					dgl.buffer = "> " + dgl.saved_lines[--dgl.saved_idx];
			}
			else if (k == SDLK_DOWN) {
				if (dgl.saved_idx + 1 < DEVGUI_MAX_SAVED_LINES &&
					!dgl.saved_lines[dgl.saved_idx + 1].empty()
				) {
					dgl.buffer = "> " + dgl.saved_lines[++dgl.saved_idx];
				}
			}
		}

		R_UpdateTextDrawDef(i, dgl.promptDrawId, dgl.buffer);
		R_ActivateTextDrawDef(i, dgl.promptDrawId, true);
	}
}

void DevGui_Shutdown() {
	for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
		dgl_t& dgl = DevGui_GetLocalClientLocals(i);
		R_RemoveTextDrawDef(i, dgl.promptDrawId);
		dgl.buffer.clear();
		dgl.saved_idx = 0;
	}
}
