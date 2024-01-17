#include <cstdint>

void Sys_Init();
bool Sys_HandleEvent();
void R_Init();
void R_DrawFrame(uint64_t deltaTime);
void CG_Init();
void CG_Frame(uint64_t deltaTime);
void Font_Init();
uint64_t Sys_Milliseconds();

static uint64_t s_lastFrameTime;

//int com_maxfps = 30;

bool Com_Init() {
    Sys_Init();
    s_lastFrameTime = Sys_Milliseconds();
    Font_Init();
    CG_Init();
    R_Init();
    return true;
}

bool Com_Frame() {
    uint64_t deltaTime = Sys_Milliseconds() - s_lastFrameTime;
    s_lastFrameTime = Sys_Milliseconds();

    while (Sys_HandleEvent())
        ;

    R_DrawFrame(deltaTime);
    CG_Frame(deltaTime);

	return true;
}

void Com_Shutdown() {

}