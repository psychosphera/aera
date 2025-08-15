#include "gfx.h"

#include <assert.h>
#include <stdio.h>
#include <stddef.h>

#if A_RENDER_BACKEND_GL
#include <cglm/cglm.h>
#endif // A_RENDER_BACKEND_GL

#if !A_TARGET_PLATFORM_IS_XBOX
#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>
#endif // !A_TARGET_PLATFORM_IS_XBOX

#include "acommon/acommon.h"
#include "acommon/a_string.h"

#include "cg_cgame.h"
#include "cl_client.h"
#include "cl_map.h"
#include "com_print.h"
#include "db_files.h"
#include "dvar.h"
#include "font.h"
#include "gfx_backend.h"
#include "gfx_map.h"
#include "gfx_shader.h"
#include "gfx_text.h"
#include "gfx_uniform.h"
#include "sys.h"

extern dvar_t* vid_width;
extern dvar_t* vid_height;

#if A_RENDER_BACKEND_GL
A_NO_DISCARD const char* R_GLDebugErrorString(GLenum err) {
    switch (err) {
    case GL_NO_ERROR:
        return "GL_NO_ERROR";
    case GL_INVALID_ENUM:
        return "GL_INVALID_ENUM";
    case GL_INVALID_VALUE:
        return "GL_INVALID_VALUE";
    case GL_INVALID_OPERATION:
        return "GL_INVALID_OPERATION";
    case GL_STACK_OVERFLOW:
        return "GL_STACK_OVERFLOW";
    case GL_STACK_UNDERFLOW:
        return "GL_STACK_UNDERFLOW";
    case GL_OUT_OF_MEMORY:
        return "GL_OUT_OF_MEMORY";
    case GL_INVALID_FRAMEBUFFER_OPERATION:
        return "GL_INVALID_FRAMEBUFFER_OPERATION";
    default:
        Com_DPrintln(
            CON_DEST_CLIENT, 
            "R_GlErrorStr called with unknown value (err=%d)", 
            err
        );
        return "";
    }
}

A_NO_DISCARD static const char* R_GLDebugSourceString(GLenum source) {
    switch (source) {
    case GL_DEBUG_SOURCE_API:
        return "API";
    case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
        return "WindowSystem";
    case GL_DEBUG_SOURCE_SHADER_COMPILER:
        return "ShaderCompiler";
    case GL_DEBUG_SOURCE_THIRD_PARTY:
        return "ThirdParty";
    case GL_DEBUG_SOURCE_APPLICATION:
        return "Application";
    case GL_DEBUG_SOURCE_OTHER:
        return "Other";
    default:
        return "<unknown>";
    };
}

A_NO_DISCARD static const char* R_GLDebugTypeString(GLenum type) {
    switch (type) {
    case GL_DEBUG_TYPE_ERROR:
        return "Error";
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
        return "DeprecatedBehaviour";
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
        return "UndefinedBehaviour";
    case GL_DEBUG_TYPE_PORTABILITY:
        return "Portability";
    case GL_DEBUG_TYPE_PERFORMANCE:
        return "Performance";
    case GL_DEBUG_TYPE_MARKER:
        return "Marker";
    case GL_DEBUG_TYPE_PUSH_GROUP:
        return "PushGroup";
    case GL_DEBUG_TYPE_POP_GROUP:
        return "PopGroup";
    case GL_DEBUG_TYPE_OTHER:
        return "Other";
    default:
        return "<unknown>";
    };
}

A_NO_DISCARD static const char* R_GLDebugSeverityString(GLenum severity) {
    switch (severity) {
    case GL_DEBUG_SEVERITY_HIGH:
        return "High";
    case GL_DEBUG_SEVERITY_MEDIUM:
        return "Medium";
    case GL_DEBUG_SEVERITY_LOW:
        return "Low";
    case GL_DEBUG_SEVERITY_NOTIFICATION:
        return "Notification";
    default:
        return "<unknown>";
    };
}

#if _DEBUG
static void GLAPIENTRY R_GLDebugOutput(
    GLenum source, GLenum type, unsigned int id, GLenum severity,
    GLsizei length, const char* message, const void* user
) {
    A_UNUSED(length);
    A_UNUSED(user);

    if (/*id == 131169 ||*/ id == 131185 || /*
        id == 131218 ||*/ id == 131204/* || id == 131139 */
    ) {
        return;
    }

    const char* i   = R_GLDebugErrorString(id);
    const char* src = R_GLDebugSourceString(source);
    const char* t   = R_GLDebugTypeString(type);
    const char* sev = R_GLDebugSeverityString(severity);
    
    Com_DPrintln(CON_DEST_CLIENT,
        "OpenGL debug message (id=%s, source=%s, type=%s, severity=%s): %s", 
        i, src, t, sev, message
    );
}

GLenum R_GLCheckError(const char* func, int line, const char* file) {
    GLenum err = glGetError();
    assert(err == GL_NO_ERROR);
    if (err != GL_NO_ERROR) {
        const char* s = R_GLDebugErrorString(err);
        Com_Errorln(-1,
                    "%s (%s:%d): GL call failed with %s.",
                    func, line, file, s
        );
    }
    return err;
}
#endif // _DEBUG
#elif A_RENDER_BACKEND_D3D9
HRESULT s_lastError;
HRESULT R_SetLastD3DError(HRESULT hr) {
    s_lastError = hr;
    return hr;
}

HRESULT R_GetLastD3DError(void) {
    return s_lastError;
}

void R_D3DCheckError(const char* func, int line, const char* file) {
    HRESULT hr = R_GetLastD3DError();
    assert(SUCCEEDED(hr));
    if (FAILED(hr)) {
        Com_Errorln(
            -1,
            "%s (%s:%d): D3D error (hr=%l)",
            func, file, line, R_GetLastD3DError()
        );
    }
}
#endif // A_RENDER_BACKEND_GL

static void R_RegisterDvars        (void);
static void R_DrawFrameInternal    (size_t localClientNum);
static void R_InitLocalClient      (size_t localClientNum);
static void R_UpdateLocalClientView(size_t localClientNum);

#define R_NEAR_PLANE_DEFAULT 0.1f
#define R_FAR_PLANE_DEFAULT  1000.0f

dvar_t* r_vsync;
dvar_t* r_fullscreen;
dvar_t* r_noBorder;
dvar_t* r_renderDistance;
dvar_t* r_wireframe;

extern FontDef r_defaultFont;

size_t r_testDrawId = 0;

typedef struct RenderGlob {
    acolor_rgba_t clear_color;
} RenderGlob;
RenderGlob r_renderGlob;

#if A_RENDER_BACKEND_D3D9
D3D9RenderGlob r_d3d9Glob;
#elif A_RENDER_BACKEND_D3D8
D3D8RenderGlob r_d3d8Glob;
#endif // A_RENDER_BACKEND_D3D9

#if A_RENDER_BACKEND_GL
static bool R_InitGL(void) {
#if _DEBUG
    //GLint flags = 0;
    //GL_CALL(glGetIntegerv, GL_CONTEXT_FLAGS, &flags);
    //if ((flags & GL_CONTEXT_FLAG_DEBUG_BIT) == 0)
    //    Com_Errorln(
    //      "Failed to initialize OpenGL debug context in debug build."
    //    );

    GLint num_extensions = 0;
    GL_CALL(glGetIntegerv, GL_NUM_EXTENSIONS, &num_extensions);
    for (GLint i = 0; i < num_extensions; i++) {
        Com_Println(
            CON_DEST_CLIENT,
            "%s ",
            (const char*)glGetStringi(GL_EXTENSIONS, i)
        );
    }

    GL_CALL(glEnable, GL_DEBUG_OUTPUT);
    GL_CALL(glEnable, GL_DEBUG_OUTPUT_SYNCHRONOUS);
    GL_CALL(glDebugMessageCallback, R_GLDebugOutput, NULL);
    GL_CALL(glDebugMessageControl,  GL_DONT_CARE,    GL_DONT_CARE,
                                    GL_DONT_CARE, 0, NULL, GL_TRUE);
#endif // _DEBUG

    GL_CALL(glClearColor, r_renderGlob.clear_color.r, 
                          r_renderGlob.clear_color.g, 
                          r_renderGlob.clear_color.b, 
                          r_renderGlob.clear_color.a);

    GL_CALL(glBlendFunc, GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    return true;
}
#elif A_RENDER_BACKEND_D3D9
static HWND R_GetHwnd(SDL_Window* window) {
    SDL_SysWMinfo info;
    SDL_VERSION(&info.version);
    int res = SDL_GetWindowWMInfo(window, &info);
    assert(res == SDL_TRUE);
    HWND hWnd = info.info.win.window;
    return hWnd;
}

static UINT R_ChooseAdapter(IDirect3D9* d3d9) {
    (void)d3d9;
    return D3DADAPTER_DEFAULT;
}

static IDirect3DDevice9* R_CreateDevice(HWND hWnd, 
                                        IDirect3D9* d3d9, 
                                        UINT adapter
) {
    DWORD flags = D3DCREATE_HARDWARE_VERTEXPROCESSING;

    UINT interval = Dvar_GetBool(r_vsync) ?
        D3DPRESENT_INTERVAL_ONE :
        D3DPRESENT_INTERVAL_IMMEDIATE;

    D3DPRESENT_PARAMETERS d3dpp;
    A_memset(&d3dpp, 0, sizeof(d3dpp));
    d3dpp.Windowed               = TRUE;
    d3dpp.hDeviceWindow          = hWnd;
    d3dpp.SwapEffect             = D3DSWAPEFFECT_DISCARD;
    d3dpp.EnableAutoDepthStencil = TRUE;
    d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
    d3dpp.PresentationInterval   = interval;
        //.BackBufferWidth            = 0,
        //.BackBufferHeight           = 0,
        //.BackBufferFormat           = D3DFMT_UNKNOWN,
        //.BackBufferCount            = 1,
        
        //.MultiSampleType            = D3DMULTISAMPLE_NONE,
        //.MultiSampleQuality         = 0,

        //.FullScreen_RefreshRateInHz = 0,
        //.Flags                      = 0,
   
    IDirect3DDevice9* d3ddev = NULL;
    HRESULT hr = D3D_CALL(d3d9, CreateDevice, adapter, D3DDEVTYPE_HAL,
                                              hWnd, flags, &d3dpp, &d3ddev);

    if (hr == D3D_OK)
        assert(d3ddev);

    return d3ddev;
}

// TODO: Come up with a more robust system. We only need to check for scissor
// test currently, so this works
static bool R_CheckD3DDeviceCaps(void) {
    D3DCAPS9 caps;
    D3D_CALL(r_d3d9Glob.d3ddev, GetDeviceCaps, &caps);
    return caps.RasterCaps & D3DPRASTERCAPS_SCISSORTEST;
}

static bool R_InitD3D9(void) {
    A_memset(&r_d3d9Glob, 0, sizeof(r_d3d9Glob));

    s_lastError = D3D_OK;

    HWND hWnd = R_GetHwnd(sys_sdlGlob.window);
    r_d3d9Glob.hWnd = hWnd;

    IDirect3D9* d3d9 = Direct3DCreate9(D3D_SDK_VERSION);
    assert(d3d9);
    r_d3d9Glob.d3d9 = d3d9;

    UINT adapterCount = D3D_CALL_NO_ERR(d3d9, GetAdapterCount);
    assert(adapterCount > 0);
    if (adapterCount == 0)
        return false;
    UINT adapter = R_ChooseAdapter(d3d9); 

    IDirect3DDevice9* d3ddev = R_CreateDevice(hWnd, d3d9, adapter);
    assert(d3ddev);
    if (!d3ddev)
        return false;
    r_d3d9Glob.d3ddev = d3ddev;

    r_d3d9Glob.clear_color_argb = 
        R_ColorRGBAToD3DARGB(r_renderGlob.clear_color);

    D3D_CALL(r_d3d9Glob.d3ddev, SetRenderState, D3DRS_BLENDOP, 
                                                D3DBLENDOP_ADD);

    D3D_CALL(r_d3d9Glob.d3ddev, SetRenderState, D3DRS_SRCBLEND, 
                                                D3DBLEND_SRCALPHA);

    D3D_CALL(r_d3d9Glob.d3ddev, SetRenderState, D3DRS_DESTBLEND, 
                                                D3DBLEND_INVSRCALPHA);
    return true;
}
#elif A_RENDER_BACKEND_D3D8
#if !A_TARGET_PLATFORM_IS_XBOX
static HWND R_GetHwnd(SDL_Window* window) {
    SDL_SysWMinfo info;
    SDL_VERSION(&info.version);
    int res = SDL_GetWindowWMInfo(window, &info);
    assert(res == SDL_TRUE);
    HWND hWnd = info.info.win.window;
    return hWnd;
}
#endif // !A_TARGET_PLATFORM_IS_XBOX

static UINT R_ChooseAdapter(IDirect3D8* d3d8) {
    (void)d3d8;
    return D3DADAPTER_DEFAULT;
}

static IDirect3DDevice8* R_CreateDevice(HWND hWnd, IDirect3D8* d3d8, UINT adapter) {
#if A_TARGET_PLATFORM_IS_XBOX
    assert(hWnd    == NULL);
    assert(adapter == D3DADAPTER_DEFAULT);
#endif // A_TARGET_PLATFORM_IS_XBOX
    DWORD behavior_flags = D3DCREATE_HARDWARE_VERTEXPROCESSING;

    UINT interval = Dvar_GetBool(r_vsync) ?
        D3DPRESENT_INTERVAL_ONE :
        D3DPRESENT_INTERVAL_IMMEDIATE;

#if A_TARGET_PLATFORM_IS_XBOX
    D3DDISPLAYMODE d3dmode;
    HRESULT hr = IDirect3D8_GetAdapterDisplayMode(d3d8, D3DADAPTER_DEFAULT, &d3dmode);
    assert(hr == D3D_OK);
    UINT      width  = d3dmode.Width;
    UINT      height = d3dmode.Height;
    D3DFORMAT format = d3dmode.Format;
    Dvar_SetInt(vid_width,  width);
    Dvar_SetInt(vid_height, height);
#else
    HRESULT   hr     = D3D_OK;
    UINT      width  = 0;
    UINT      height = 0;
    D3DFORMAT format = D3DFMT_UNKNOWN;
#endif // A_TARGET_PLATFORM_IS_XBOX
    D3DPRESENT_PARAMETERS d3dpp;
    A_memset(&d3dpp, 0, sizeof(d3dpp));
    d3dpp.BackBufferWidth                 = width;
    d3dpp.BackBufferHeight                = height;
    d3dpp.BackBufferFormat                = format;
    d3dpp.BackBufferCount                 = 1;
    d3dpp.EnableAutoDepthStencil          = TRUE;
    d3dpp.AutoDepthStencilFormat          = D3DFMT_D24S8;
    d3dpp.SwapEffect                      = D3DSWAPEFFECT_DISCARD;
    d3dpp.FullScreen_PresentationInterval = interval;

    IDirect3DDevice8* d3ddev = NULL;
    hr = IDirect3D8_CreateDevice(d3d8, D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, 
                                 hWnd, behavior_flags, &d3dpp, &d3ddev);
    assert(hr == D3D_OK);

    if (hr == D3D_OK)
        assert(d3ddev);

    return d3ddev;
}

static bool R_InitD3D8(void) {
    A_memset(&r_d3d8Glob, 0, sizeof(r_d3d8Glob));

#if !A_TARGET_PLATFORM_IS_XBOX
    HWND hWnd = R_GetHwnd(sys_sdlGlob.window);
    r_d3d8Glob.hWnd = hWnd;
#else 
    HWND hWnd = NULL;
#endif // !A_TARGET_PLATFORM_IS_XBOX

    IDirect3D8* d3d8 = Direct3DCreate8(D3D_SDK_VERSION);
    assert(d3d8);
    r_d3d8Glob.d3d8 = d3d8;

    UINT adapter = R_ChooseAdapter(d3d8);

    IDirect3DDevice8* d3ddev = R_CreateDevice(hWnd, d3d8, adapter);
    assert(d3ddev);
    r_d3d8Glob.d3ddev = d3ddev;

    r_d3d8Glob.clear_color_argb =
        R_ColorRGBAToD3DARGB(r_renderGlob.clear_color);

    HRESULT hr = IDirect3DDevice8_SetRenderState(d3ddev, D3DRS_BLENDOP, D3DBLENDOP_ADD);
    assert(hr == D3D_OK);
    hr = IDirect3DDevice8_SetRenderState(d3ddev, D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
    assert(hr == D3D_OK);
    hr = IDirect3DDevice8_SetRenderState(d3ddev, D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
    assert(hr == D3D_OK);
    return true;
}
#endif // A_RENDER_BACKEND_GL

void R_Init(void) {
    RB_Init();

    r_renderGlob.clear_color.r = 0.2f;
    r_renderGlob.clear_color.g = 0.3f;
    r_renderGlob.clear_color.b = 0.3f;
    r_renderGlob.clear_color.a = 1.0f;

    R_RegisterDvars();

#if A_RENDER_BACKEND_GL
    bool b = R_InitGL();
    assert(b && "Failed to initialize OpenGL.");
    if (!b)
        Com_Errorln(-1, "Failed to initialize OpenGL.");
#elif A_RENDER_BACKEND_D3D9
    bool b = R_InitD3D9();
    assert(b && "Failed to initialize D3D9.");
    if (!b)
        Com_Errorln(-1, "Failed to initialize D3D9.");
#elif A_RENDER_BACKEND_D3D8
    bool b = R_InitD3D8();
    assert(b && "Failed to initialize D3D8.");
    if (!b)
        Com_Errorln(-1, "Failed to initialize D3D8.");
#endif // A_RENDER_BACKEND_GL
    
    for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
        R_InitLocalClient(i);
        R_ClearTextDrawDefs(i);
    }

    //b = Font_Load("consola.ttf", 0, 48, &r_defaultFont);
    //assert(b);
    (void)b;

    RectDef rect = { /*.x =*/ 0.1f, /*.y =*/ 0.1f, /*.w =*/ 0.8f, /*.h =*/ 0.2f };
    acolor_rgb_t color = A_color_rgb(0.77, 0.77, 0.2);
    R_AddTextDrawDef(
        0, NULL, &rect, "This is a test.\nWhere the fuck i am?", 1.0f, 1.0f,
        color, true, false, &r_testDrawId
    );
    R_InitMap();

    //glEnable(GL_POINT_SMOOTH);
    //glPointSize(4);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
}

static void R_InitLocalClient(size_t localClientNum) {
    cg_t* cg      = CG_GetLocalClientGlobals(localClientNum);
    cg->nearPlane = R_NEAR_PLANE_DEFAULT;
    cg->farPlane  = R_FAR_PLANE_DEFAULT;
    R_UpdateLocalClientView(localClientNum);
}

static void R_UpdateOrtho(size_t localClientNum) {
    cg_t* cg = CG_GetLocalClientGlobals(localClientNum);

    float left   = cg->viewport.x * Dvar_GetInt(vid_width);
    float right  = cg->viewport.w * Dvar_GetInt(vid_width)  + left;
    float bottom = cg->viewport.y * Dvar_GetInt(vid_height);
    float top    = cg->viewport.h * Dvar_GetInt(vid_height) + bottom;
#if A_RENDER_BACKEND_D3D9 || A_RENDER_BACKEND_D3D8
    D3DXMATRIX ortho;
    D3DXMatrixOrthoLH(&ortho, right - left, top - bottom, cg->nearPlane, cg->farPlane);
#elif A_RENDER_BACKEND_GL
    mat4 ortho;
    glm_ortho(left, right, bottom, top, cg->nearPlane, cg->farPlane, ortho);
#endif // A_RENDER_BACKEND_D3D9
    cg->camera.orthoProjection = *(amat4f_t*)&ortho;
}

void R_UpdateProjection(size_t localClientNum) {
    cg_t* cg = CG_GetLocalClientGlobals(localClientNum);

    float w = cg->viewport.w * Dvar_GetInt(vid_width);
    float h = cg->viewport.h * Dvar_GetInt(vid_height);

#if A_RENDER_BACKEND_GL
    mat4 perspective;
    glm_perspective(A_radians(cg->fovy), w / h, cg->nearPlane, cg->farPlane, perspective);
#elif A_RENDER_BACKEND_D3D9 || A_RENDER_BACKEND_D3D8
    D3DXMATRIX perspective;
    D3DXMatrixPerspectiveFovLH(&perspective, A_radians(cg->fovy), w / h, cg->nearPlane, cg->farPlane);
#endif // A_RENDER_BACKEND_GL
    cg->camera.perspectiveProjection = *(amat4f_t*)&perspective;
}

static void R_UpdateLocalClientView(size_t localClientNum) {
    R_UpdateOrtho(localClientNum);
    R_UpdateProjection(localClientNum);
}

static void R_RegisterDvars(void) {
    r_vsync          = Dvar_RegisterBool("r_vsync", DVAR_FLAG_NONE, true);
    r_fullscreen     = Dvar_RegisterBool("r_fullscreen", DVAR_FLAG_NONE, false);
    r_noBorder       = Dvar_RegisterBool("r_noBorder", DVAR_FLAG_NONE, false);
    r_renderDistance = Dvar_RegisterFloat("r_renderDistance", DVAR_FLAG_NONE, 
                                          R_FAR_PLANE_DEFAULT, 
                                          10.0f, 1000000.0f);
    r_wireframe      = Dvar_RegisterBool("r_wireframe", DVAR_FLAG_NONE, false);
}

void R_DrawFrame(size_t localClientNum) {
    GfxCamera* camera = &CG_GetLocalClientGlobals(localClientNum)->camera;
    avec3f_t* front = &camera->front;
    Com_DPrintln(CON_DEST_CLIENT, "R_DrawFrame: camera %i dir = (%f, %f, %f)", localClientNum, front->x, front->y, front->z);
    R_DrawFrameInternal(localClientNum);
}

static bool R_EnableScissorTest(void) {
#if A_RENDER_BACKEND_GL
    GL_CALL(glEnable, GL_SCISSOR_TEST);
#elif A_RENDER_BACKEND_D3D9
    D3D_CALL(r_d3d9Glob.d3ddev, SetRenderState, D3DRS_SCISSORTESTENABLE, TRUE);
#elif A_RENDER_BACKEND_D3D8
    return false;
#endif // A_RENDER_BACKEND_GL
    return true;
}

static bool R_DisableScissorTest(void) {
#if A_RENDER_BACKEND_GL
    GL_CALL(glDisable, GL_SCISSOR_TEST);
#elif A_RENDER_BACKEND_D3D9
    D3D_CALL(r_d3d9Glob.d3ddev, SetRenderState, D3DRS_SCISSORTESTENABLE, 
                                                FALSE);
#elif A_RENDER_BACKEND_D3D8
    return false;
#endif // A_RENDER_BACKEND_GL
    return true;
}

static void R_BeginFrame(void) {
    // intentionally a no-op for GL since there's nothing to do
#if A_RENDER_BACKEND_D3D9
    D3D_CALL(r_d3d9Glob.d3ddev, BeginScene);
#elif A_RENDER_BACKEND_D3D8
    HRESULT hr = IDirect3DDevice8_BeginScene(r_d3d8Glob.d3ddev);
    assert(hr == D3D_OK);
#endif // A_RENDER_BACKEND_D3D9
}

static void R_EndFrame(void) {
    // intentionally a no-op for GL since RB_EndFrame handles
    // the equivalent operations
    // (R_EndFrame and RB_EndFrame could probably be consolidated to simplify
    // implementation, but semantically the backend handles the buffer swap
    // for GL, whereas D3D handles the buffer swap on its own)
#if A_RENDER_BACKEND_D3D9
    D3D_CALL(r_d3d9Glob.d3ddev, EndScene);
    D3D_CALL(r_d3d9Glob.d3ddev, Present, NULL, NULL, NULL, NULL);
#elif A_RENDER_BACKEND_D3D8
    HRESULT hr = IDirect3DDevice8_EndScene(r_d3d8Glob.d3ddev);
    assert(hr == D3D_OK);
    hr = IDirect3DDevice8_Present(r_d3d8Glob.d3ddev, NULL, NULL, NULL, NULL);
    assert(hr == D3D_OK);
#endif // A_RENDER_BACKEND_D3D9
}

void R_Frame(void) {
    RB_BeginFrame();
    R_BeginFrame();
    R_EnableScissorTest();
    for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
        if (!CG_LocalClientIsActive(i))
            continue;

        R_DrawFrame(i);
    }
    R_DisableScissorTest();
    R_EndFrame();
    RB_EndFrame();
}

void R_WindowResized(void) {
    for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++)
        R_UpdateLocalClientView(i);
}

#if A_RENDER_BACKEND_GL
static GLint R_ImageFormatToTypeGL(ImageFormat format) {
    switch (format) {
    case R_IMAGE_FORMAT_A8:
    case R_IMAGE_FORMAT_R8:
    case R_IMAGE_FORMAT_P8:
        return GL_UNSIGNED_BYTE;
    case R_IMAGE_FORMAT_RGB565:
        return GL_UNSIGNED_SHORT_5_6_5;
    case R_IMAGE_FORMAT_ARGB8888:
    case R_IMAGE_FORMAT_RGBA8888:
        return GL_UNSIGNED_INT_8_8_8_8;
    default:
        assert(false &&
            "R_ImageSubData: Unimplemented GL type for image format");
        Com_Errorln(
            -1,
            "R_ImageSubData: Unimplemented GL type for image format %d.",
            format
        );
        return 0;
    }
}
#endif // A_RENDER_BACKEND_GL

A_NO_DISCARD bool R_CreateImage2D(const void* pixels, size_t pixels_size, 
                                  int width, int height, int depth,
                                  ImageFormat format,
                                  bool auto_generate_mipmaps,
                                  bool wrap_s, bool wrap_t,
                                  ImageFilter minfilter, ImageFilter magfilter,
                                  A_OUT GfxImage* image
) {
    (void)depth;
    assert(image);
    if (!image)
        return false;

    if (pixels) {
        assert(pixels_size > 0);
        if (pixels_size < 1)
            return false;
    } else {
        assert(pixels_size == 0);
        if (pixels_size != 0)
            return false;
    }

    A_memset(image, 0, sizeof(*image));
#if A_RENDER_BACKEND_GL
    GLenum target = GL_TEXTURE_2D;
    texture_t tex;
    GL_CALL(glActiveTexture, GL_TEXTURE0);
    GL_CALL(glGenTextures, 1, &tex);
    GL_CALL(glBindTexture, target, tex);

    if (wrap_s)
        GL_CALL(glTexParameteri, target, GL_TEXTURE_WRAP_S, GL_REPEAT);
    if (wrap_t)
        GL_CALL(glTexParameteri, target, GL_TEXTURE_WRAP_T, GL_REPEAT);

    GLint gl_minfilter = R_ImageFilterToGL(minfilter);
    GLint gl_magfilter = R_ImageFilterToGL(magfilter);

    GL_CALL(glTexParameteri, target, GL_TEXTURE_MIN_FILTER, gl_minfilter);
    GL_CALL(glTexParameteri, target, GL_TEXTURE_MAG_FILTER, gl_magfilter);
    
    if (format == R_IMAGE_FORMAT_A8)
        format = R_IMAGE_FORMAT_R8;

    bool compressed  = R_ImageFormatIsCompressed(format);
    GLenum gl_format = R_ImageFormatToGL(format);
    ImageFormat internal_format = format;
    GLenum gl_internal_format   = R_ImageFormatToGL(internal_format);
   
    if (compressed) {
        GL_CALL(glCompressedTexImage2D, GL_TEXTURE_2D, 0,
                                        gl_internal_format, 
                                        width, height, 0, 
                                        pixels_size, pixels);
    } else {
        GLint gl_type = R_ImageFormatToTypeGL(format);
        GL_CALL(glTexImage2D, GL_TEXTURE_2D, 0, gl_internal_format,
                              width, height, 0, gl_format, 
                              gl_type, pixels);
    }

    if (auto_generate_mipmaps)
        GL_CALL(glGenerateMipmap, target);
#elif A_RENDER_BACKEND_D3D9
    (void)wrap_s;
    (void)wrap_t;
    (void)auto_generate_mipmaps;
    D3DFORMAT          d3dfmt          = R_ImageFormatToD3D(format);
    ImageFormat        internal_format = format;
    IDirect3DTexture9* tex             = NULL;
    D3D_CALL(r_d3d9Glob.d3ddev, CreateTexture, width, height, 1, 0, d3dfmt, D3DPOOL_MANAGED, &tex, NULL)
    assert(tex);
    D3DLOCKED_RECT locked_rect;
    const RECT rect = {
        .left   = 0,
        .right  = width,
        .top    = 0,
        .bottom = height
    };
    D3D_CALL(tex, LockRect, 0, &locked_rect, &rect, D3DLOCK_DISCARD);
    INT pitch = locked_rect.Pitch;
    if (format == R_IMAGE_FORMAT_DXT1)
        pitch /= 16;
    else if (format == R_IMAGE_FORMAT_DXT3 || format == R_IMAGE_FORMAT_DXT5)
        pitch /= 4;

    int bpp = R_ImageFormatBPP(format);
    int block_size = R_ImageFormatIsDXT(format) ? 4 : 1;
    // pitch can be greater than width * pixel_size, 
    // but it should never be less
    assert(width * bpp / 8 / block_size <= pitch);

    // if they're equal, a single full copy will work
    if (width * bpp / 8 == pitch) {
        A_memcpy(locked_rect.pBits, pixels, width * height * bpp / 8);
    }
    // if not, copy line-by-line
    else if (pixels_size > 0) {
        for (int i = 0; i < height; i++) {
            A_memcpy((char*)locked_rect.pBits + i * pitch * block_size,
                     (char*)pixels + i * pitch * block_size,
                     pitch * block_size
            );
        }
    }
    D3D_CALL(tex, UnlockRect, 0);
#elif A_RENDER_BACKEND_D3D8
	(void)wrap_s;
    (void)wrap_t;
    (void)auto_generate_mipmaps;
    D3DFORMAT          d3dfmt          = R_ImageFormatToD3D(format);
    ImageFormat        internal_format = format;
    IDirect3DTexture8* tex             = NULL;

    HRESULT hr = IDirect3DDevice8_CreateTexture(r_d3d8Glob.d3ddev, width, height, 
                                                1, 0, d3dfmt, D3DPOOL_MANAGED, &tex);
    assert(hr == D3D_OK);
    assert(tex);
    D3DLOCKED_RECT locked_rect;
    RECT rect;
    rect.left   = 0;
    rect.right  = width;
    rect.top    = 0;
    rect.bottom = height;
#if !A_TARGET_PLATFORM_IS_XBOX
    DWORD flags = D3DLOCK_DISCARD;
#else
    DWORD flags = 0;
#endif // !A_TARGET_PLATFORM_IS_XBOX
    hr = IDirect3DTexture8_LockRect(tex, 0, &locked_rect, &rect, flags);
    assert(hr == D3D_OK);

    INT pitch = locked_rect.Pitch;
    if (format == R_IMAGE_FORMAT_DXT1)
        pitch /= 16;
    else if (format == R_IMAGE_FORMAT_DXT3 || format == R_IMAGE_FORMAT_DXT5)
        pitch /= 4;

    int bpp = R_ImageFormatBPP(format);
    int block_size = R_ImageFormatIsDXT(format) ? 4 : 1;
    // pitch can be greater than width * pixel_size, 
    // but it should never be less
    assert(width * bpp / 8 / block_size <= pitch);

    // if they're equal, a single full copy will work
    if (width * bpp / 8 == pitch) {
        A_memcpy(locked_rect.pBits, pixels, width * height * bpp / 8);
    }
    // if not, copy line-by-line
    else if (pixels_size > 0) {
        for (int i = 0; i < height; i++) {
            A_memcpy((char*)locked_rect.pBits + i * pitch * block_size,
                (char*)pixels + i * pitch * block_size,
                pitch * block_size
            );
        }
    }
    hr = IDirect3DTexture8_UnlockRect(tex, 0);
    assert(hr == D3D_OK);
#endif // A_RENDER_BACKEND_GL
    image->width           = width;
    image->height          = height;
    image->depth           = 1;
    image->type            = R_IMAGE_TYPE_2D_TEXTURE;
    image->format          = format;
    image->internal_format = internal_format;
    image->tex             = tex;
    image->wrap_s          = true;
    image->wrap_t          = true;
    image->minfilter       = minfilter;
    image->magfilter       = magfilter;

    return true;
}

A_NO_DISCARD bool R_ImageSubData(A_INOUT GfxImage* image,
                                 const void* pixels, size_t pixels_size, 
                                 int xoff, int yoff, 
                                 int width, int height, 
                                 ImageFormat format
) {
    assert(image);
    assert(pixels);
    assert(pixels_size > 0);
    assert(xoff + width  <= image->width);
    assert(yoff + height <= image->height);
#if A_RENDER_BACKEND_GL
    GLenum gl_format = R_ImageFormatToGL(format);
    GLenum gl_type = 0;
    switch (format) {
    case R_IMAGE_FORMAT_A8:
    case R_IMAGE_FORMAT_R8:
        gl_type = GL_UNSIGNED_BYTE;
        break;
    case R_IMAGE_FORMAT_RGB565:
        gl_type = GL_UNSIGNED_SHORT_5_6_5;
        break;
    case R_IMAGE_FORMAT_ARGB8888:
    case R_IMAGE_FORMAT_RGBA8888:
        gl_type = GL_UNSIGNED_INT_8_8_8_8;
        break;
    default:
        assert(false && 
               "R_ImageSubData: Unimplemented GL type for image format");
        Com_Errorln(
            -1, 
            "R_ImageSubData: Unimplemented GL type for image format %d.",
            format
        );
        return false;
    }
    GL_CALL(glBindTexture, GL_TEXTURE_2D, image->tex);
    GL_CALL(glTexSubImage2D,
        GL_TEXTURE_2D, 0, xoff, yoff, width, height,
        gl_format, gl_type, pixels
    );
#elif A_RENDER_BACKEND_D3D9
    IDirect3DTexture9* tex = image->tex;
    D3DLOCKED_RECT locked_rect;
    RECT rect = {
        .left   = xoff,
        .right  = xoff + width,
        .top    = yoff,
        .bottom = yoff + height
    };
    D3D_CALL(tex, LockRect, 0, &locked_rect, &rect, D3DLOCK_DISCARD);
    INT pitch = locked_rect.Pitch;
    int bpp = R_ImageFormatBPP(format);
    // pitch can be greater than width * pixel_size,
    // but it should never be less
    assert(width * bpp / 8 <= pitch);
    // if they're equal, a single full copy will work
    if (width * bpp / 8 == pitch && xoff == 0 && yoff == 0) {
        A_memcpy(locked_rect.pBits, pixels, pixels_size);
    }
    // if not, copy line-by-line
    else {
        for (int i = yoff; i < height; i++) {
            A_memcpy((char*)locked_rect.pBits + i * pitch,
                (char*)pixels + i * width,
                width
            );
        }
    }
    D3D_CALL(tex, UnlockRect, 0);
#elif A_RENDER_BACKEND_D3D8
    IDirect3DTexture8* tex = image->tex;
    D3DLOCKED_RECT locked_rect;
    RECT rect;
    rect.left   = xoff;
    rect.right  = xoff + width;
    rect.top    = yoff;
    rect.bottom = yoff + height;
#if A_TARGET_PLATFORM_IS_XBOX
    DWORD flags = 0;
#else
    DWORD flags = D3DLOCK_DISCARD;
#endif // A_TARGET_PLATFORM_IS_XBOX
    HRESULT hr = IDirect3DTexture8_LockRect(tex, 0, &locked_rect, &rect, flags);
    assert(hr == D3D_OK);
    INT pitch = locked_rect.Pitch;
    int bpp = R_ImageFormatBPP(format);
    // pitch can be greater than width * pixel_size,
    // but it should never be less
    assert(width * bpp / 8 <= pitch);
    // if they're equal, a single full copy will work
    if (width * bpp / 8 == pitch && xoff == 0 && yoff == 0) {
        A_memcpy(locked_rect.pBits, pixels, pixels_size);
    }
    // if not, copy line-by-line
    else {
        for (int i = yoff; i < height; i++) {
            A_memcpy((char*)locked_rect.pBits + i * pitch,
                (char*)pixels + i * width,
                width
            );
        }
    }
    hr = IDirect3DTexture8_UnlockRect(tex, 0);
    assert(hr == D3D_OK);
#endif // A_RENDER_BACKEND_GL
    return true;
}

void R_DeleteImage(A_INOUT GfxImage* image) {
#if A_RENDER_BACKEND_GL
    GL_CALL(glDeleteTextures, 1, &image->tex);
#elif A_RENDER_BACKEND_D3D9
    if (image->tex) {
        D3D_CALL(image->tex, Release);
        image->tex = NULL;
    }
#elif A_RENDER_BACKEND_D3D8
    if (image->tex) {
        IDirect3DTexture8_Release(image->tex);
        image->tex = NULL;
    }
#endif // A_RENDER_BACKEND_GL
}

bool R_EnableDepthTest(void) {
#if A_RENDER_BACKEND_GL
    GL_CALL(glEnable, GL_DEPTH_TEST);
#elif A_RENDER_BACKEND_D3D9
    D3D_CALL(r_d3d9Glob.d3ddev, SetRenderState, D3DRS_ZENABLE, TRUE);
#elif A_RENDER_BACKEND_D3D8
    HRESULT hr = IDirect3DDevice8_SetRenderState(r_d3d8Glob.d3ddev, D3DRS_ZENABLE, TRUE);
    assert(hr == D3D_OK);
#endif // A_RENDER_BACKEND_GL
    return true;
}

bool R_DisableDepthTest(void) {
#if A_RENDER_BACKEND_GL
    GL_CALL(glDisable, GL_DEPTH_TEST);
#elif A_RENDER_BACKEND_D3D9
    D3D_CALL(r_d3d9Glob.d3ddev, SetRenderState, D3DRS_ZENABLE, FALSE);
#elif A_RENDER_BACKEND_D3D8
    HRESULT hr = IDirect3DDevice8_SetRenderState(r_d3d8Glob.d3ddev, D3DRS_ZENABLE, FALSE);
    assert(hr == D3D_OK);
#endif // A_RENDER_BACKEND_GL
    return true;
}

bool R_EnableBackFaceCulling(void) {
#if A_RENDER_BACKEND_GL
    GL_CALL(glEnable, GL_CULL_FACE);
#elif A_RENDER_BACKEND_D3D9
    D3D_CALL(r_d3d9Glob.d3ddev, SetRenderState, D3DRS_CULLMODE, D3DCULL_CCW);
#elif A_RENDER_BACKEND_D3D8
    HRESULT hr = IDirect3DDevice8_SetRenderState(r_d3d8Glob.d3ddev, D3DRS_CULLMODE, D3DCULL_CCW);
    assert(hr == D3D_OK);
#endif // A_RENDER_BACKEND_GL
    return true;
}

bool R_DisableBackFaceCulling(void) {
#if A_RENDER_BACKEND_GL
    GL_CALL(glDisable, GL_CULL_FACE);
#elif A_RENDER_BACKEND_D3D9
    D3D_CALL(r_d3d9Glob.d3ddev, SetRenderState, D3DRS_CULLMODE, 0);
#elif A_RENDER_BACKEND_D3D8
    HRESULT hr = IDirect3DDevice8_SetRenderState(r_d3d8Glob.d3ddev, D3DRS_CULLMODE, 0);
    assert(hr == D3D_OK);
#endif // A_RENDER_BACKEND_GL
    return true;
}

bool R_EnableTransparencyBlending(void) {
#if A_RENDER_BACKEND_GL
    GL_CALL(glEnable, GL_BLEND);
#elif A_RENDER_BACKEND_D3D9
    D3D_CALL(r_d3d9Glob.d3ddev, SetRenderState, D3DRS_ALPHABLENDENABLE, TRUE);
#elif A_RENDER_BACKEND_D3D8
    HRESULT hr = IDirect3DDevice8_SetRenderState(r_d3d8Glob.d3ddev, D3DRS_ALPHABLENDENABLE, TRUE);
    assert(hr == D3D_OK);
#endif // A_RENDER_BACKEND_GL
    return true;
}

bool R_DisableTransparencyBlending(void) {
#if A_RENDER_BACKEND_GL
    GL_CALL(glDisable, GL_BLEND);
#elif A_RENDER_BACKEND_D3D9
    D3D_CALL(r_d3d9Glob.d3ddev, SetRenderState, D3DRS_ALPHABLENDENABLE, FALSE);
#elif A_RENDER_BACKEND_D3D8
    HRESULT hr = IDirect3DDevice8_SetRenderState(r_d3d8Glob.d3ddev, D3DRS_ALPHABLENDENABLE, FALSE);
    assert(hr == D3D_OK);
#endif // A_RENDER_BACKEND_GL
    return true;
}

#if A_RENDER_BACKEND_GL
static GLenum R_PolygonModeToGL(GfxPolygonMode mode) {
    switch (mode) {
    case R_POLYGON_MODE_FILL:
        return GL_FILL;
    case R_POLYGON_MODE_LINE:
        return GL_LINE;
    default:
        assert(false && "Unimplemented polygon mode");
        Com_Errorln(-1, "Unimplemented polygon mode %d.", mode);
        return 0;
    }
}
#endif // A_RENDER_BACKEND_GL

#if A_RENDER_BACKEND_D3D
static DWORD R_PolygonModeToD3D(GfxPolygonMode mode) {
    switch (mode) {
    case R_POLYGON_MODE_FILL:
        return D3DFILL_SOLID;
    case R_POLYGON_MODE_LINE:
        return D3DFILL_WIREFRAME;
    default:
        assert(false && "Unimplemented polygon mode");
        Com_Errorln(-1, "Unimplemented polygon mode %d.", mode);
        return 0;
    }
}
#endif // A_RENDER_BACKEND_D3D9

bool R_SetPolygonMode(GfxPolygonMode mode) {
#if A_RENDER_BACKEND_GL
    GLenum fill_mode = R_PolygonModeToGL(mode);
    GL_CALL(glPolygonMode, GL_FRONT_AND_BACK, fill_mode);
#elif A_RENDER_BACKEND_D3D
    DWORD fill_mode = R_PolygonModeToD3D(mode);
#if A_RENDER_BACKEND_D3D9
    D3D_CALL(r_d3d9Glob.d3ddev, SetRenderState, D3DRS_FILLMODE, fill_mode);   
#elif A_RENDER_BACKEND_D3D8
    HRESULT hr = IDirect3DDevice8_SetRenderState(r_d3d8Glob.d3ddev, D3DRS_FILLMODE, fill_mode);
    assert(hr == D3D_OK);
#endif // A_RENDER_BACKEND_D3D9
#endif // A_RENDER_BACKEND_GL
    return true;
}

void R_SetViewport(int x, int y, int w, int h) {
#if A_RENDER_BACKEND_GL
    GL_CALL(glViewport, x, y, w, h);
#elif A_RENDER_BACKEND_D3D9
    D3DVIEWPORT9 viewport = {
        .X      = x,
        .Y      = y,
        .Width  = w,
        .Height = h,
        .MinZ   = 0.0f,
        .MaxZ   = 1.0f
    };
    D3D_CALL(r_d3d9Glob.d3ddev, SetViewport, &viewport);
#elif A_RENDER_BACKEND_D3D8
    D3DVIEWPORT8 viewport = {
        .X      = x,
        .Y      = y,
        .Width  = w,
        .Height = h,
        .MinZ   = 0.0f,
        .MaxZ   = 1.0f
    };
    HRESULT hr = IDirect3DDevice8_SetViewport(r_d3d8Glob.d3ddev, &viewport);
    assert(hr == D3D_OK);
#endif // A_RENDER_BACKEND_GL
}

void R_SetScissorRect(int x, int y, int w, int h) {
#if A_RENDER_BACKEND_GL
    GL_CALL(glScissor, x, y, w, h);
#elif A_RENDER_BACKEND_D3D9
    RECT rect = {
        .left   = x,
        .right  = x + w,
        .top    = y,
        .bottom = y + h
    };
    D3D_CALL(r_d3d9Glob.d3ddev, SetScissorRect, &rect);
#endif // A_RENDER_BACKEND_GL
}

void R_Clear(void) {
#if A_RENDER_BACKEND_GL
    GL_CALL(glClear, GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
#elif A_RENDER_BACKEND_D3D9
    D3D_CALL(r_d3d9Glob.d3ddev, Clear, 0, NULL, 
                                       D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
                                       r_d3d9Glob.clear_color_argb, 0.0f, 0);
#elif A_RENDER_BACKEND_D3D8
    HRESULT hr = IDirect3DDevice8_Clear(r_d3d8Glob.d3ddev, 0, NULL,
                                        D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
                                        r_d3d8Glob.clear_color_argb, 0.0f, 0);
    assert(hr == D3D_OK);
#endif // A_RENDER_BACKEND_GL
}

bool R_BindVertexBuffer(const GfxVertexBuffer* vb, int stream) {
#if A_RENDER_BACKEND_GL
    assert(stream == 0);
    if (vb) {
        GL_CALL(glBindVertexArray, vb->vao);
        GL_CALL(glBindBuffer, GL_ARRAY_BUFFER, vb->vbo);
    } else {
        GL_CALL(glBindVertexArray, 0);
        GL_CALL(glBindBuffer, GL_ARRAY_BUFFER, 0);
    }
#elif A_RENDER_BACKEND_D3D
    if (vb) {
#if A_RENDER_BACKEND_D3D9
        D3D_CALL(r_d3d9Glob.d3ddev, SetStreamSource, stream, vb->buffer,
                                                     0, vb->stride);
#elif A_RENDER_BACKEND_D3D8
        HRESULT hr = IDirect3DDevice8_SetStreamSource(r_d3d8Glob.d3ddev, stream, 
                                                      vb->buffer, vb->stride);
        assert(hr == D3D_OK);
#endif // A_RENDER_BACKEND_D3D9
    } else {
#if A_RENDER_BACKEND_D3D9
        D3D_CALL(r_d3d9Glob.d3ddev, SetStreamSource, stream, NULL, 0, 0);
#elif A_RENDER_BACKEND_D3D8
        HRESULT hr = IDirect3DDevice8_SetStreamSource(r_d3d8Glob.d3ddev, stream, NULL, 0);
        assert(hr == D3D_OK);
#endif // A_RENDER_BACKEND_D3D9
    }
#endif // A_RENDER_BACKEND_GL
    return true;
}

bool R_BindImage(A_INOUT GfxImage* image, int index) {
#if A_RENDER_BACKEND_GL
    if (image) {
        GL_CALL(glActiveTexture, GL_TEXTURE0 + index);
        GL_CALL(glBindTexture, GL_TEXTURE_2D, image->tex);
    } else {
        GL_CALL(glActiveTexture, GL_TEXTURE0 + index);
        GL_CALL(glBindTexture, GL_TEXTURE_2D, 0);
    }
#elif A_RENDER_BACKEND_D3D
    if (image) {
#if A_RENDER_BACKEND_D3D9
        D3D_CALL(r_d3d9Glob.d3ddev, SetTexture, index, 
                 (IDirect3DBaseTexture9*)image->tex);
#elif A_RENDER_BACKEND_D3D8
        HRESULT hr = IDirect3DDevice8_SetTexture(r_d3d8Glob.d3ddev, index, (IDirect3DBaseTexture8*)image->tex);
        assert(hr == D3D_OK);
#endif // A_RENDER_BACKEND_D3D9
    } else {
#if A_RENDER_BACKEND_D3D9
        D3D_CALL(r_d3d9Glob.d3ddev, SetTexture, index, NULL);
#elif A_RENDER_BACKEND_D3D8
        HRESULT hr = IDirect3DDevice8_SetTexture(r_d3d8Glob.d3ddev, index, NULL);
        assert(hr == D3D_OK);
#endif // A_RENDER_BACKEND_D3D9
    }
#endif // A_RENDER_BACKEND_GL
    return true;
}

bool R_BindShaderProgram(const GfxShaderProgram* prog) {
#if A_RENDER_BACKEND_GL
    if (prog) {
        GL_CALL(glUseProgram, prog->program);
    } else {
        GL_CALL(glUseProgram, 0);
    }
#elif A_RENDER_BACKEND_D3D9
    if (prog) {
        D3D_CALL(r_d3d9Glob.d3ddev, SetVertexShader, prog->vertex_shader.vs);
        D3D_CALL(r_d3d9Glob.d3ddev, SetPixelShader,  prog->pixel_shader.ps);
    } else {
        D3D_CALL(r_d3d9Glob.d3ddev, SetVertexShader, NULL);
        D3D_CALL(r_d3d9Glob.d3ddev, SetPixelShader,  NULL);
    }
#else
    assert(false && "unimplemented"); // FIXME
#endif // A_RENDER_BACKEND_GL
    return true;
}

#if A_RENDER_BACKEND_GL
static GLenum R_PrimitiveTypeToGL(GfxPrimitiveType type) {
    switch (type) {
    case PRIMITIVE_TYPE_TRI:
        return GL_TRIANGLES;
    case PRIMITIVE_TYPE_TRI_STRIP:
        return GL_TRIANGLE_STRIP;
    default:
        assert(false && "R_PrimitiveTypeToGL: invalid GfxPrimitiveType");
        Com_Errorln(
            -1,
            "R_PrimitiveTypeToGL: invalid GfxPrimitiveType %d",
            type
        );
    }
}
#elif A_RENDER_BACKEND_D3D
static D3DPRIMITIVETYPE R_PrimitiveTypeToD3D(GfxPrimitiveType type) {
    switch (type) {
    case PRIMITIVE_TYPE_TRI:
        return D3DPT_TRIANGLELIST;
    case PRIMITIVE_TYPE_TRI_STRIP:
        return D3DPT_TRIANGLESTRIP;
    default:
        assert(false && "R_PrimitiveTypeToGL: invalid GfxPrimitiveType");
        Com_Errorln(
            -1,
            "R_PrimitiveTypeToGL: invalid GfxPrimitiveType %d",
            type
        );
    }
}
#endif // A_RENDER_BACKEND_GL

bool R_DrawPrimitives(GfxPrimitiveType type, int primitive_count, int primitive_off) {
    int off = type == PRIMITIVE_TYPE_TRI ? 3 * primitive_off : type == PRIMITIVE_TYPE_TRI_STRIP ? 1 * primitive_off : -1;
#if A_RENDER_BACKEND_GL
    GLenum mode = R_PrimitiveTypeToGL(type);
    GLsizei count = type == PRIMITIVE_TYPE_TRI ? primitive_count * 3 : type == PRIMITIVE_TYPE_TRI_STRIP ? primitive_count + 2 : -1;
    GL_CALL(glDrawArrays, mode, off, count);
#elif A_RENDER_BACKEND_D3D
    D3DPRIMITIVETYPE primitive_type = R_PrimitiveTypeToD3D(type);
#if A_RENDER_BACKEND_D3D9
    HRESULT hr = IDirect3DDevice9_DrawPrimitive(r_d3d9Glob.d3ddev, 
                                                primitive_type,
                                                off, primitive_count);
#elif A_RENDER_BACKEND_D3D8
    HRESULT hr = IDirect3DDevice8_DrawPrimitive(r_d3d8Glob.d3ddev, primitive_type, off, primitive_count);
#endif // A_RENDER_BACKEND_D3D9
    assert(hr == D3D_OK);
#endif // A_RENDER_BACKEND_GL
    return true;
}

static void R_DrawFrameInternal(size_t localClientNum) {
    cg_t* cg = CG_GetLocalClientGlobals(localClientNum);

    int x = (cg->viewport.x * Dvar_GetInt(vid_width));
    int y = (cg->viewport.y * Dvar_GetInt(vid_height));
    int w = (cg->viewport.w * Dvar_GetInt(vid_width));
    int h = (cg->viewport.h * Dvar_GetInt(vid_height));
    if (Dvar_WasModified(cg->fov)) {
        R_UpdateProjection(localClientNum);
        Dvar_ClearModified(cg->fov);
    }

    R_SetViewport(x, y, w, h);
    R_SetScissorRect(x, y, w, h);
    R_Clear();

    const RectDef rect = {
        /*.x =*/ x,
        /*.y =*/ y,
        /*.w =*/ w,
        /*.h =*/ h
    };
    acolor_rgb_t color = A_color_rgb(0.5f, 0.8f, 0.2f);
    //R_DrawText(localClientNum,
    //    NULL, &rect, "Testing 123...", 
    //    1.0f, 1.0f, color, false
    //);

    avec4f_t pos   = A_vec4(cg->camera.pos.x,   
                            cg->camera.pos.y,   
                            cg->camera.pos.z,
                            1.0f);
    avec4f_t front = A_vec4(cg->camera.front.x, 
                            cg->camera.front.y, 
                            cg->camera.front.z,
                            1.0f);
    avec4f_t center = A_vec4f_add(pos, front);
#if A_RENDER_BACKEND_GL
    mat4 view;
    glm_lookat(pos.array, center.array, cg->camera.up.array, view);
#elif A_RENDER_BACKEND_D3D9 || A_RENDER_BACKEND_D3D8
    D3DXMATRIX view;
    D3DXMatrixLookAtLH(&view, (D3DXVECTOR3*)&pos, (D3DXVECTOR3*)&center, (D3DXVECTOR3*)&cg->camera.up);
#endif // A_RENDER_BACKEND_GL
#if !A_TARGET_PLATFORM_IS_XBOX
    R_ShaderSetUniformMat4fByName(&r_mapGlob.prog, "uView", 
                                  SHADER_TYPE_VERTEX, *(amat4f_t*)&view);
    R_ShaderSetUniformMat4fByName(&r_mapGlob.model_prog, "uView",
                                  SHADER_TYPE_VERTEX, *(amat4f_t*)&view);
    R_ShaderSetUniformMat4fByName(&r_mapGlob.prog, "uPerspectiveProjection",
                                  SHADER_TYPE_VERTEX,
                                  cg->camera.perspectiveProjection);
    R_ShaderSetUniformMat4fByName(&r_mapGlob.model_prog, "uPerspectiveProjection",
                                  SHADER_TYPE_VERTEX,
                                  cg->camera.perspectiveProjection);
#else
	assert(false); // FIXME
#endif // !A_TARGET_PLATFORM_IS_XBOX
    R_RenderMap();
    
    //R_DrawTextDrawDefs(localClientNum);
}

static void R_UnregisterDvars(void) {
    Dvar_Unregister("r_wireframe");
    Dvar_Unregister("r_renderDistance");
    Dvar_Unregister("r_noBorder");
    Dvar_Unregister("r_fullscreen");
    Dvar_Unregister("r_vsync");
    r_wireframe      = NULL;
    r_renderDistance = NULL;
    r_noBorder       = NULL;
    r_fullscreen     = NULL;
    r_vsync          = NULL;
}

#if A_RENDER_BACKEND_GL
static void R_ShutdownGL(void) {
#if _DEBUG
    GL_CALL(glDisable, GL_DEBUG_OUTPUT);
    GL_CALL(glDisable, GL_DEBUG_OUTPUT_SYNCHRONOUS);
    GL_CALL(glDebugMessageCallback, NULL, NULL);
#endif // _DEBUG

    GL_CALL(glClearColor, 0.0f, 0.0f, 0.0f, 0.0f);
}
#elif A_RENDER_BACKEND_D3D9
static void R_ShutdownD3D9(void) {
    if (r_d3d9Glob.d3ddev) {
        D3D_CALL(r_d3d9Glob.d3ddev, Release);
        r_d3d9Glob.d3ddev = NULL;
    }

    if (r_d3d9Glob.d3d9) {
        D3D_CALL(r_d3d9Glob.d3d9, Release);
        r_d3d9Glob.d3d9 = NULL;
    }

    r_d3d9Glob.clear_color_argb = 0;
    r_d3d9Glob.hWnd             = NULL;
}
#elif A_RENDER_BACKEND_D3D8
static void R_ShutdownD3D8(void) {
    if (r_d3d8Glob.d3ddev) {
        IDirect3DDevice8_Release(r_d3d8Glob.d3ddev);
        r_d3d8Glob.d3ddev = NULL;
    }

    if (r_d3d8Glob.d3d8) {
        IDirect3D8_Release(r_d3d8Glob.d3d8);
        r_d3d8Glob.d3d8 = NULL;
    }

    r_d3d8Glob.clear_color_argb = 0;
#if !A_TARGET_PLATFORM_IS_XBOX
    r_d3d8Glob.hWnd = NULL;
#endif // !A_TARGET_PLATFORM_IS_XBOX
}
#endif // A_RENDER_BACKEND_D3D9

A_EXTERN_C void R_Shutdown(void) {
    for(size_t i = 0; i < MAX_LOCAL_CLIENTS; i++)
        R_ClearTextDrawDefs(i);

    R_ShutdownMap();

    R_UnregisterDvars();
#if A_RENDER_BACKEND_GL
    R_ShutdownGL();
#elif A_RENDER_BACKEND_D3D9
    R_ShutdownD3D9();
#elif A_RENDER_BACKEND_D3D8
    R_ShutdownD3D8();
#endif // A_RENDER_BACKEND_D3D9

    RB_Shutdown();
}
