#include "gfx.h"

#include <assert.h>
#include <stdio.h>
#include <stddef.h>

#include <cglm/cglm.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_syswm.h>
#include <SDL3_image/SDL_image.h>

#if A_RENDER_BACKEND_GL
#include <GL/glew.h>
#elif A_RENDER_BACKEND_D3D9
#include <d3d9.h>
#endif // A_RENDER_BACKEND_GL

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
#include "m_math.h"
#include "sys.h"

extern dvar_t* vid_width;
extern dvar_t* vid_height;

#if A_RENDER_BACKEND_GL
A_NO_DISCARD const char* R_GlDebugErrorString(GLenum err) {
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

A_NO_DISCARD static const char* R_GlDebugSourceString(GLenum source) {
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

A_NO_DISCARD static const char* R_GlDebugTypeString(GLenum type) {
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

A_NO_DISCARD static const char* R_GlDebugSeverityString(GLenum severity) {
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

static void GLAPIENTRY R_GlDebugOutput(
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

    const char* i   = R_GlDebugErrorString(id);
    const char* src = R_GlDebugSourceString(source);
    const char* t   = R_GlDebugTypeString(type);
    const char* sev = R_GlDebugSeverityString(severity);
    
    Com_DPrintln(CON_DEST_CLIENT,
        "OpenGL debug message (id=%s, source=%s, type=%s, severity=%s): %s", 
        i, src, t, sev, message
    );
}
#endif // A_RENDER_BACKEND_GL

static void R_RegisterDvars        ();
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
    GL_CALL(glDebugMessageCallback, R_GlDebugOutput, NULL);
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
    int res = SDL_GetWindowWMInfo(window, &info, SDL_SYSWM_CURRENT_VERSION);
    assert(res == 0);
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

    const D3DPRESENT_PARAMETERS d3dpp = {
        .Windowed                   = TRUE,
        .hDeviceWindow              = hWnd,
        .BackBufferWidth            = 0,
        .BackBufferHeight           = 0,
        .BackBufferFormat           = D3DFMT_UNKNOWN,
        .BackBufferCount            = 1,
        .SwapEffect                 = D3DSWAPEFFECT_DISCARD,
        .MultiSampleType            = D3DMULTISAMPLE_NONE,
        .MultiSampleQuality         = 0,
        .EnableAutoDepthStencil     = TRUE,
        .AutoDepthStencilFormat     = D3DFMT_D32,
        .FullScreen_RefreshRateInHz = 0,
        .Flags                      = 0,
        .PresentationInterval       = interval
    };
    IDirect3DDevice9* d3ddev = NULL;
    HRESULT hr = d3d9->lpVtbl->CreateDevice(d3d9, adapter, D3DDEVTYPE_HAL,
                                            hWnd, flags, &d3dpp, &d3ddev);
    assert(hr == D3D_OK);

    if (hr == D3D_OK)
        assert(d3ddev);

    return d3ddev;
}

// TODO: Come up with a more robust system. We only need to check for scissor
// test currently, so this works
static bool R_CheckD3DDeviceCaps(void) {
    D3DCAPS9 caps;
    r_d3d9Glob.d3ddev->lpVtbl->GetDeviceCaps(r_d3d9Glob.d3ddev, &caps);
    return caps.RasterCaps & D3DPRASTERCAPS_SCISSORTEST;
}

static bool R_InitD3D9(void) {
    A_memset(&r_d3d9Glob, 0, sizeof(r_d3d9Glob));

    HWND hWnd = R_GetHwnd(sys_sdlGlob.window);
    r_d3d9Glob.hWnd = hWnd;

    IDirect3D9* d3d9 = Direct3DCreate9(D3D_SDK_VERSION);
    assert(d3d9);
    r_d3d9Glob.d3d9 = d3d9;

    UINT adapterCount = d3d9->lpVtbl->GetAdapterCount(d3d9);
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

    HRESULT hr = r_d3d9Glob.d3ddev->lpVtbl->SetRenderState(
        r_d3d9Glob.d3ddev,
        D3DRS_BLENDOP, D3DBLENDOP_ADD
    );
    assert(hr == D3D_OK);
    if (hr != D3D_OK)
        return false;
    hr = r_d3d9Glob.d3ddev->lpVtbl->SetRenderState(
        r_d3d9Glob.d3ddev,
        D3DRS_SRCBLEND, D3DBLEND_SRCALPHA
    );
    assert(hr == D3D_OK);
    if (hr != D3D_OK)
        return false;
    hr = r_d3d9Glob.d3ddev->lpVtbl->SetRenderState(
        r_d3d9Glob.d3ddev,
        D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA
    );
    assert(hr == D3D_OK);
    return hr == D3D_OK;
}
#endif // A_RENDER_BACKEND_GL

void R_Init(void) {
    RB_Init();

    int imgInitFlags = IMG_INIT_JPG | IMG_INIT_PNG;
    if ((IMG_Init(imgInitFlags) & imgInitFlags) != imgInitFlags)
        Com_Errorln(-1, "SDL_image init failed.");

    r_renderGlob.clear_color.r = 0.2f;
    r_renderGlob.clear_color.g = 0.3f;
    r_renderGlob.clear_color.b = 0.3f;
    r_renderGlob.clear_color.a = 1.0f;

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
#endif // A_RENDER_BACKEND_GL
    
    for (size_t i = 0; i < MAX_LOCAL_CLIENTS; i++) {
        R_InitLocalClient(i);
        R_ClearTextDrawDefs(i);
    }

    R_RegisterDvars();

    b = Font_Load("consola.ttf", 0, 48, &r_defaultFont);
    assert(b);
    (void)b;

    RectDef rect = { .x = 0.1f, .y = 0.1f, .w = 0.8f, .h = 0.2f };
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
    mat4 ortho;
    glm_ortho(left, right, bottom, top, cg->nearPlane, cg->farPlane, ortho);
    cg->camera.orthoProjection = *(amat4f_t*)&ortho;
}

void R_UpdateProjection(size_t localClientNum) {
    cg_t* cg = CG_GetLocalClientGlobals(localClientNum);

    float w = cg->viewport.w * Dvar_GetInt(vid_width);
    float h = cg->viewport.h * Dvar_GetInt(vid_height);

    mat4 perspective;
    glm_perspective(A_radians(cg->fovy), w / h, cg->nearPlane, cg->farPlane, perspective);
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
    R_DrawFrameInternal(localClientNum);
}

static bool R_EnableScissorTest(void) {
#if A_RENDER_BACKEND_GL
    GL_CALL(glEnable, GL_SCISSOR_TEST);
    return true;
#elif A_RENDER_BACKEND_D3D9
    HRESULT hr = r_d3d9Glob.d3ddev->lpVtbl->SetRenderState(
        r_d3d9Glob.d3ddev,
        D3DRS_SCISSORTESTENABLE, 1
    );
    assert(hr == D3D_OK);
    return hr == D3D_OK;
#endif // A_RENDER_BACKEND_GL
}

static bool R_DisableScissorTest(void) {
#if A_RENDER_BACKEND_GL
    GL_CALL(glDisable, GL_SCISSOR_TEST);
#elif A_RENDER_BACKEND_D3D9
    HRESULT hr = r_d3d9Glob.d3ddev->lpVtbl->SetRenderState(
        r_d3d9Glob.d3ddev,
        D3DRS_SCISSORTESTENABLE, 0
    );
    assert(hr == D3D_OK);
    return hr == D3D_OK;
#endif // A_RENDER_BACKEND_GL
}

static void R_BeginFrame(void) {
    // intentionally a no-op for GL since there's nothing to do
#if A_RENDER_BACKEND_D3D9
    r_d3d9Glob.d3ddev->lpVtbl->BeginScene(r_d3d9Glob.d3ddev);
#endif // A_RENDER_BACKEND_D3D9
}

static void R_EndFrame(void) {
    // intentionally a no-op for GL since RB_EndFrame handles
    // the equivalent operations
    // (R_EndFrame and RB_EndFrame could probably be consolidated to simplify
    // implementation, but semantically the backend handles the buffer swap
    // for GL, whereas D3D handles the buffer swap on its own)
#if A_RENDER_BACKEND_D3D9
    r_d3d9Glob.d3ddev->lpVtbl->EndScene(r_d3d9Glob.d3ddev);
    r_d3d9Glob.d3ddev->lpVtbl->Present(r_d3d9Glob.d3ddev,
                                       NULL, NULL, NULL, NULL);
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

A_NO_DISCARD bool R_CreateImage2D(const void* pixels, size_t pixels_size, 
                                  int width, int height, int depth,
                                  ImageFormat format,
                                  bool auto_generate_mipmaps,
                                  bool wrap_s, bool wrap_t,
                                  ImageFilter minfilter, ImageFilter magfilter,
                                  A_OUT GfxImage* image
) {
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
    GLenum target = 0;
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
                                                            
    bool compressed  = R_ImageFormatIsCompressed(format);
    GLenum gl_format = R_ImageFormatToGL(format);
    ImageFormat internal_format = compressed ? format : R_IMAGE_FORMAT_RGB888;
    GLenum gl_internal_format   = R_ImageFormatToGL(internal_format);
   
    if (compressed) {
        GL_CALL(glCompressedTexImage2D, GL_TEXTURE_2D, 0,
                                        gl_internal_format, 
                                        width, height, 0, 
                                        pixels_size, pixels);
    }
    else {
        GL_CALL(glTexImage2D, GL_TEXTURE_2D, 0, internal_format,
                              width, height, 0, gl_format, 
                              GL_UNSIGNED_BYTE, pixels);
    }

    if (auto_generate_mipmaps)
        GL_CALL(glGenerateMipmap, target);

    bool ret = true;
#elif A_RENDER_BACKEND_D3D9
    D3DFORMAT          d3dfmt          = R_ImageFormatToD3D(format);
    ImageFormat        internal_format = format;
    IDirect3DTexture9* tex             = NULL;
    r_d3d9Glob.d3ddev->lpVtbl->CreateTexture(r_d3d9Glob.d3ddev,
                                             width, height, 0, 0,
                                             d3dfmt, D3DPOOL_MANAGED, &tex,
                                             NULL);
    assert(tex);
    D3DLOCKED_RECT rect;
    HRESULT hr = tex->lpVtbl->LockRect(tex, 0, &rect, NULL, D3DLOCK_DISCARD);
    assert(hr == D3D_OK);
    bool ret = hr == D3D_OK;
    INT pitch = rect.Pitch;
    int pixel_size = R_ImageFormatPixelSize(format);
    // pitch can be greater than width * pixel_size, 
    // but it should never be less
    assert(width * pixel_size <= pitch);

    // if they're equal, a single full copy will work
    if (width * pixel_size == pitch) {
        A_memcpy(rect.pBits, pixels, width * height * pixel_size);
    }
    // if not, copy line-by-line
    else {
        for (int i = 0; i < height; i++) {
            A_memcpy((char*)rect.pBits + i * pitch,
                (char*)pixels + i * width * pixel_size,
                width * pixel_size
            );
        }
    }
    hr = tex->lpVtbl->UnlockRect(tex, 0);
    assert(hr == D3D_OK);
    if (ret == D3D_OK)
        ret = hr == D3D_OK;
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

    return ret;
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
        gl_format, GL_UNSIGNED_BYTE, pixels
    );
#elif A_RENDER_BACKEND_D3D9
    IDirect3DTexture9* tex = image->tex;
    D3DLOCKED_RECT locked_rect;
    RECT rect = {
        .left = xoff,
        .right = xoff + width,
        .top = yoff,
        .bottom = yoff + height
    };
    HRESULT hr = tex->lpVtbl->LockRect(tex, 0, &locked_rect, &rect, D3DLOCK_DISCARD);
    assert(hr == D3D_OK);
    if (hr != D3D_OK)
        return false;
    INT pitch = locked_rect.Pitch;
    int pixel_size = R_ImageFormatPixelSize(format);
    // pitch can be greater than width * pixel_size,
    // but it should never be less
    assert(width * pixel_size <= pitch);
    // if they're equal, a single full copy will work
    if (width * pixel_size == pitch) {
        A_memcpy(locked_rect.pBits, pixels, pixels_size);
    }
    // if not, copy line-by-line
    else {
        for (int i = 0; i < height; i++) {
            A_memcpy((char*)locked_rect.pBits + i * pitch,
                (char*)pixels + i * width * pixel_size,
                width * pixel_size
            );
        }
    }
    hr = tex->lpVtbl->UnlockRect(tex, 0);
    assert(hr == D3D_OK);
    if (hr != D3D_OK)
        return false;
#endif // A_RENDER_BACKEND_GL
    return true;
}

A_NO_DISCARD bool R_CreateSdlImage(const char* image_name, 
                                   A_INOUT GfxImage* image
) {
    assert(image_name);
    if (!image_name)
        return false;

    const char* image_path = DB_ImagePath(image_name);
    SDL_Surface* surf = IMG_Load(image_path);

    assert(surf);
    if (!surf)
        return false;

    assert(surf->pixels);
    if (!surf->pixels)
        return false;

    assert(surf->w > 0 && surf->h > 0);
    if (surf->w < 1 || surf->h < 1)
        return false;

    ImageFormat format;
    switch (surf->format->format) {
    case SDL_PIXELFORMAT_RGB24:
        format = R_IMAGE_FORMAT_RGB888;
        break;
    case SDL_PIXELFORMAT_RGBA32:
        format = R_IMAGE_FORMAT_RGBA8888;
        break;
    default:
        assert(false && "Unimplemented SDL pixel format");
        Com_Errorln(-1,
            "R_CreateSdlImage: Unimplemented SDL pixel format %d.",
            surf->format->format
        );
        return false;
    }

    size_t pixels_size = surf->w * surf->h * surf->format->BytesPerPixel;

    bool ret = R_CreateImage2D(surf->pixels, pixels_size, 
                               surf->w, surf->h, 1, format, 
                               true, true, true, 
                               R_IMAGE_FILTER_LINEAR, 
                               R_IMAGE_FILTER_LINEAR, 
                               image);

    SDL_DestroySurface(surf);

    return ret;
}

void R_DeleteImage(A_INOUT GfxImage* image) {
#if A_RENDER_BACKEND_GL
    GL_CALL(glDeleteTextures, 1, &image->tex);
#elif A_RENDER_BACKEND_D3D9
    if (image->tex) {
        image->tex->lpVtbl->Release(image->tex);
        image->tex = NULL;
    }
#endif // A_RENDER_BACKEND_GL
}

bool R_EnableDepthTest(void) {
#if A_RENDER_BACKEND_GL
    GL_CALL(glEnable, GL_DEPTH_TEST);
    return true;
#elif A_RENDER_BACKEND_D3D9
    HRESULT hr = r_d3d9Glob.d3ddev->lpVtbl->SetRenderState(
        r_d3d9Glob.d3ddev,
        D3DRS_ZENABLE, TRUE
    );
    assert(hr == D3D_OK);
    return hr == D3D_OK;
#endif // A_RENDER_BACKEND_GL
}

bool R_DisableDepthTest(void) {
#if A_RENDER_BACKEND_GL
    GL_CALL(glDisable, GL_DEPTH_TEST);
#elif A_RENDER_BACKEND_D3D9
    HRESULT hr = r_d3d9Glob.d3ddev->lpVtbl->SetRenderState(
        r_d3d9Glob.d3ddev,
        D3DRS_ZENABLE, FALSE
    );
    assert(hr == D3D_OK);
    return hr == D3D_OK;
#endif // A_RENDER_BACKEND_GL
}

bool R_EnableBackFaceCulling(void) {
#if A_RENDER_BACKEND_GL
    GL_CALL(glEnable, GL_CULL_FACE);
    return true;
#elif A_RENDER_BACKEND_D3D9
    HRESULT hr = r_d3d9Glob.d3ddev->lpVtbl->SetRenderState(
        r_d3d9Glob.d3ddev,
        D3DRS_CULLMODE, D3DCULL_CCW
    );
    assert(hr == D3D_OK);
    return hr == D3D_OK;
#endif // A_RENDER_BACKEND_GL
}

bool R_DisableBackFaceCulling(void) {
#if A_RENDER_BACKEND_GL
    GL_CALL(glDisable, GL_CULL_FACE);
#elif A_RENDER_BACKEND_D3D9
    HRESULT hr = r_d3d9Glob.d3ddev->lpVtbl->SetRenderState(
        r_d3d9Glob.d3ddev,
        D3DRS_CULLMODE, 0
    );
    assert(hr == D3D_OK);
    return hr == D3D_OK;
#endif // A_RENDER_BACKEND_GL
}

bool R_EnableTransparencyBlending(void) {
#if A_RENDER_BACKEND_GL
    GL_CALL(glEnable, GL_BLEND);
    return true;
#elif A_RENDER_BACKEND_D3D9
    HRESULT hr = r_d3d9Glob.d3ddev->lpVtbl->SetRenderState(
        r_d3d9Glob.d3ddev,
        D3DRS_ALPHABLENDENABLE, TRUE
    );
    assert(hr == D3D_OK);
    return hr == D3D_OK;
#endif // A_RENDER_BACKEND_GL
}

bool R_DisableTransparencyBlending(void) {
#if A_RENDER_BACKEND_GL
    GL_CALL(glDisable, GL_BLEND);
    return true;
#elif A_RENDER_BACKEND_D3D9
    HRESULT hr = r_d3d9Glob.d3ddev->lpVtbl->SetRenderState(
        r_d3d9Glob.d3ddev,
        D3DRS_ALPHABLENDENABLE, FALSE
    );
    assert(hr == D3D_OK);
    return hr == D3D_OK;
#endif // A_RENDER_BACKEND_GL
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

#if A_RENDER_BACKEND_D3D9
static DWORD R_PolygonModeToD3D9(GfxPolygonMode mode) {
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
    return true;
#elif A_RENDER_BACKEND_D3D9
    DWORD fill_mode = R_PolygonModeToD3D9(mode);
    HRESULT hr = r_d3d9Glob.d3ddev->lpVtbl->SetRenderState(r_d3d9Glob.d3ddev,
                                                           D3DRS_FILLMODE,
                                                           fill_mode);
    assert(hr == D3D_OK);
    return hr == D3D_OK;
#endif // A_RENDER_BACKEND_GL
}

void R_SetViewport(int x, int y, int w, int h) {
#if A_RENDER_BACKEND_GL
    GL_CALL(glViewport, x, y, w, h);
#elif A_RENDER_BACKEND_D3D9
    D3DVIEWPORT9 viewport = {
        .X = x,
        .Y = y,
        .Width = w,
        .Height = h,
        .MinZ = 0.0f,
        .MaxZ = 0.0f
    };
    r_d3d9Glob.d3ddev->lpVtbl->SetViewport(r_d3d9Glob.d3ddev, &viewport);
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
    r_d3d9Glob.d3ddev->lpVtbl->SetScissorRect(r_d3d9Glob.d3ddev, &rect);
#endif // A_RENDER_BACKEND_GL
}

void R_Clear(void) {
#if A_RENDER_BACKEND_GL
    GL_CALL(glClear, GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
#elif A_RENDER_BACKEND_D3D9
    r_d3d9Glob.d3ddev->lpVtbl->Clear(r_d3d9Glob.d3ddev, 0, NULL,
                                     D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
                                     r_d3d9Glob.clear_color_argb, 0.0f, 0);
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
    return true;
#elif A_RENDER_BACKEND_D3D9
    HRESULT hr = D3D_OK;
    if (vb) {
        hr = r_d3d9Glob.d3ddev->lpVtbl->SetStreamSource(r_d3d9Glob.d3ddev,
                                                        stream, vb->buffer,
                                                        0, vb->stride);
    } else {
        hr = r_d3d9Glob.d3ddev->lpVtbl->SetStreamSource(r_d3d9Glob.d3ddev,
                                                        stream, NULL, 0, 0);
    }
    assert(hr == D3D_OK);
    return hr == D3D_OK;
#endif // A_RENDER_BACKEND_GL
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
    return true;
#elif A_RENDER_BACKEND_D3D9
    HRESULT hr = D3D_OK;
    if (image) {
        hr = r_d3d9Glob.d3ddev->lpVtbl->SetTexture(r_d3d9Glob.d3ddev, 
                                                   index, 
                                  (IDirect3DBaseTexture9*)image->tex);
    } else {
        hr = r_d3d9Glob.d3ddev->lpVtbl->SetTexture(r_d3d9Glob.d3ddev,
                                                   index, NULL);
    }
    assert(hr == D3D_OK);
    return hr == D3D_OK;
#endif // A_RENDER_BACKEND_GL
}

bool R_DrawTris(int tri_count, int tri_off) {
#if A_RENDER_BACKEND_GL
    GL_CALL(glDrawArrays, GL_TRIANGLES, tri_off * 3, tri_count * 3);
    return true;
#elif A_RENDER_BACKEND_D3D9
    HRESULT hr = r_d3d9Glob.d3ddev->lpVtbl->DrawPrimitive(r_d3d9Glob.d3ddev,
                                                          D3DPT_TRIANGLELIST, 
                                                          tri_off * 3,
                                                          tri_count);
    assert(hr == D3D_OK);
    return hr == D3D_OK;
#endif // A_RENDER_BACKEND_GL
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
        .x = x,
        .y = y,
        .w = w,
        .h = h
    };
    acolor_rgb_t color = A_color_rgb(0.5f, 0.8f, 0.2f);
    R_DrawText(localClientNum,
        NULL, &rect, "Testing 123...", 
        1.0f, 1.0f, color, false
    );

    avec3f_t pos   = A_vec3(cg->camera.pos.x,   
                            cg->camera.pos.y,   
                            cg->camera.pos.z);
    avec3f_t front = A_vec3(cg->camera.front.x, 
                            cg->camera.front.y, 
                            cg->camera.front.z);
    avec3f_t center;
    glm_vec3_add(pos.array, front.array, center.array);
    mat4 view;
    glm_lookat(pos.array, center.array, cg->camera.up.array, view);
    
    R_ShaderSetUniformMat4fByName(
        &r_mapGlob.prog, "uView", *(amat4f_t*)&view
    );
    R_ShaderSetUniformMat4fByName(
        &r_mapGlob.prog, "uPerspectiveProjection",
        cg->camera.perspectiveProjection
    );
    R_RenderMap();
    
    R_DrawTextDrawDefs(localClientNum);
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
        r_d3d9Glob.d3ddev->lpVtbl->Release(r_d3d9Glob.d3ddev);
        r_d3d9Glob.d3ddev = NULL;
    }

    if (r_d3d9Glob.d3d9) {
        r_d3d9Glob.d3d9->lpVtbl->Release(r_d3d9Glob.d3d9);
        r_d3d9Glob.d3d9 = NULL;
    }

    r_d3d9Glob.clear_color_argb = 0;
    r_d3d9Glob.hWnd             = NULL;
}
#endif // A_RENDER_BACKEND_D3D9

A_EXTERN_C void R_Shutdown(void) {
    for(size_t i = 0; i < MAX_LOCAL_CLIENTS; i++)
        R_ClearTextDrawDefs(i);

    R_ShutdownMap();

    R_UnregisterDvars();
    IMG_Quit();
#if A_RENDER_BACKEND_GL
    R_ShutdownGL();
#elif A_RENDER_BACKEND_D3D9
    R_ShutdownD3D9();
#endif // A_RENDER_BACKEND_D3D9

    RB_Shutdown();
}
