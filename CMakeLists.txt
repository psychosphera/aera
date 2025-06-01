cmake_minimum_required(VERSION 3.27)

project(h1_map_viewer C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_REQUIRED ON)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	set(GCC true)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	set(CLANG true)
endif()

if(MSVC)
	message(STATUS "Compiler: MSVC")
elseif(GCC)
	message(STATUS "Compiler: GCC")
elseif(CLANG)
	message(STATUS "Compiler: Clang")
else()
	message(STATUS "Compiler: Unknown")
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

if(APPLE)
    enable_language(OBJC)
endif()

if(DEFINED PLATFORM_XBOX)
	enable_language(CXX)
endif()

#set(VCPKG_TOOLCHAIN) 
#if(EXISTS VCPKG_TOOLCHAIN)
if (MSVC AND NOT DEFINED PLATFORM_XBOX)
    include("F:/vcpkg/scripts/buildsystems/vcpkg.cmake")
endif()
#endif()

find_package(Freetype)
if (NOT PLATFORM_XBOX)
	set(ZLIB_BUILD_STATIC 1)
	set(ZLIB_BUILD_SHARED 0)
	find_package(ZLIB)
endif()
if (NOT DEFINED ZLIB_DIR AND NOT PLATFORM_XBOX)
	add_subdirectory(
		${CMAKE_SOURCE_DIR}/deps/zlib 
		${CMAKE_SOURCE_DIR}/deps/zlib_build
	)
endif()

if (NOT DEFINED PLATFORM_XBOX)
	add_subdirectory(
		${CMAKE_SOURCE_DIR}/deps/SDL 
		${CMAKE_SOURCE_DIR}/deps/SDL_build
	)
endif()

set(COMMON_SRC 
	src/acommon/a_common.c src/acommon/a_io.c src/acommon/a_math.c 
	src/acommon/a_string.c src/acommon/a_type.c 
	
	src/acommon/z_mem.c
	
	src/cg_cgame.c src/cl_client.c src/cl_map.c src/cmd_commands.c 
	src/com.c src/com_print.c src/db_files.c src/dvar.c src/font.c 
    src/fs_files.c src/gfx.c src/gfx_backend.c src/gfx_defs.c src/gfx_map.c
	src/gfx_shader.c  src/gfx_text.c src/gfx_uniform.c  src/in_input.c 
    src/in_gpad.c src/m_math.c src/main.c  src/pm_pmove.c src/sys.c 
    src/vm_vmem.c
)

set(PC_SRC src/con_console.c src/devcon.c src/devgui.c src/in_kbm.c)

set(PC_LIBS SDL2::SDL2 Freetype::Freetype ZLIB::ZLIB)

set(COMMON_COMPILE_DEFS       A_PROJECT_ROOT="${CMAKE_SOURCE_DIR}")
set(COMMON_DEBUG_COMPILE_DEFS _DEBUG=1)

set(MSVC_COMPILE_OPTIONS       "/permissive-" "/W4" "/bigobj")
set(MSVC_DEBUG_COMPILE_OPTIONS "/Od")
set(MSVC_RELEASE_OPTIONS       "/O2")
set(MSVC_NON_CLANG_OPTIONS 
	"/Zc:preprocessor" "/Zc:__cplusplus" "/Zc:__STDC__" "/wd4005" "/wd4244"
	"/wd4267" "/wd4311" "/wd4305" "/wd4312" "/wd4201" "/wd4018"
)

set(GCC_COMPILE_OPTIONS 
	"-ftrack-macro-expansion=0" 
	"-Wno-address-of-packed-member"
	"-Wno-comment"
	"-Wno-pointer-to-int-cast"
)

set(GCC_CLANG_NON_CL_OPTIONS 
	"-Wall" "-Wextra" "-Wno-type-limits" "-Og" "-Wno-sign-compare"
)

set(CLANG_COMPILE_OPTIONS
	"-Wno-gnu-zero-variadic-macro-arguments"
	"-Wno-unreachable-code-generic-assoc"
	"-Wno-macro-redefined"
	"-Wno-pointer-to-int-cast" 
	"-Wno-c99-designator" 
	"-Wno-gnu-anonymous-struct"
	"-Wno-address-of-packed-member"
	"-Wno-embedded-directive"
	"-Wno-c23-extensions"
	"-Wno-c11-extensions"
)

set(CLANG_NON_CL_COMMON_OPTIONS "-pedantic")

set(CLANG_GCC_COMPILE_OPTIONS "-Wno-int-to-pointer-cast" "-Wno-sign-compare")

set(APPLE_CLANG_COMPILE_OPTIONS "-Wno-undef-prefix")

if(WIN32)
	set(OS_LIBS ntdll)
else()
	set(OS_LIBS)
endif()

# =============================================================================
if (DEFINED RENDER_BACKEND_GL)
	message(STATUS "Compiling with GL backend.")
	find_package(cglm REQUIRED)
	set(GL_LIBS GLEW::GLEW OpenGL::GL cglm::cglm)
	set(GL_COMPILE_DEFS A_RENDER_BACKEND_GL=1 A_RENDER_BACKEND_D3D9=0 A_RENDER_BACKEND_D3D8=0)

	find_package(GLEW   REQUIRED)
	find_package(OpenGL REQUIRED)
	
	add_executable(h1_map_viewer_gl ${COMMON_SRC} ${PC_SRC})
	
	target_link_libraries(h1_map_viewer_gl PRIVATE ${PC_LIBS} ${OS_LIBS} ${GL_LIBS})
	target_include_directories(h1_map_viewer_gl PRIVATE ${COMMON_INCLUDE_DIRS})
	target_compile_definitions(h1_map_viewer_gl PRIVATE 
		${COMMON_COMPILE_DEFS} ${GL_COMPILE_DEFS}
	)
	
	if(CMAKE_BUILD_TYPE STREQUAL "Debug")
		message(STATUS "Compiling with debug mode.")
		target_compile_definitions(h1_map_viewer_gl PRIVATE 
			${COMMON_DEBUG_COMPILE_DEFS}
		)
	endif()

	if(MSVC)
		target_compile_options(h1_map_viewer_gl PRIVATE 
			${MSVC_COMPILE_OPTIONS}
		)
	
		if (CMAKE_BUILD_TYPE STREQUAL "Debug")
			target_compile_options(h1_map_viewer_gl PRIVATE
				${MSVC_DEBUG_COMPILE_OPTIONS}
			)
	    elseif (CMAKE_BUILD_TYPE STREQUAL "Release" OR 
		        CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo"
		)
	        target_compile_options(h1_map_viewer_gl PRIVATE 
				${MSVC_RELEASE_OPTIONS}
			)
	    endif()
	endif()
	
	if(GCC)
	    target_compile_options(h1_map_viewer_gl PRIVATE ${GCC_COMPILE_OPTIONS}) 
	endif()
	
	message("CLANG: ${CLANG}")
	if(CLANG)
	    target_compile_options(h1_map_viewer_gl PRIVATE 
			${CLANG_COMPILE_OPTIONS}
		) 
		message(STATUS "Using clang compile opts.")
	endif()
	
	if(CLANG AND NOT MSVC)
		target_compile_options(h1_map_viewer_gl PRIVATE
			${CLANG_NON_CL_COMMON_OPTIONS}
		)
		message(STATUS "Using clang non-cl compile opts.")
	endif()
	
	if(CLANG OR GCC)
	    target_compile_options(h1_map_viewer_gl PRIVATE 
			${CLANG_GCC_COMPILE_OPTIONS}
		)
		message(STATUS "Using clang/gcc compile opts.")
	endif()
	
	if(MSVC AND NOT CLANG)
		target_compile_options(h1_map_viewer_gl PRIVATE 
			${MSVC_NON_CLANG_OPTIONS}
		)
	endif()
	
	if(CLANG AND APPLE)
	    target_compile_options(h1_map_viewer_gl PRIVATE 
			${APPLE_CLANG_COMPILE_OPTIONS}
		)
		message(STATUS "Using apple clang compile opts.")
	endif()
	
	if((CLANG AND NOT MSVC) OR GCC)
	    target_compile_options(h1_map_viewer_gl PRIVATE 
			${GCC_CLANG_NON_CL_OPTIONS}
		)
		message(STATUS "Using non-cl clang/gcc compile opts.")
	endif()
	if (MSVC AND CMAKE_SIZEOF_VOID_P EQUAL 4)
		target_link_options(h1_map_viewer_gl PRIVATE "/LARGEADDRESSAWARE")
	endif()
endif()
# =============================================================================

# =============================================================================
if (DEFINED RENDER_BACKEND_D3D9)
	set(D3D9_LIBS d3d9.lib d3dx9.lib)
	set(D3D9_INCLUDE_DIRS "$ENV{DXSDK_DIR}Include")
	set(D3D9_COMPILE_DEFS A_RENDER_BACKEND_GL=0 A_RENDER_BACKEND_D3D9=1 A_RENDER_BACKEND_D3D8=0)

	add_executable(h1_map_viewer_d3d9 ${COMMON_SRC} ${PC_SRC})
	
	if (CMAKE_SIZEOF_VOID_P EQUAL 8)
		set(DXSDK_LIB_DIR "$ENV{DXSDK_DIR}lib\\x64")
	elseif (CMAKE_SIZEOF_VOID_P EQUAL 4)
		set(DXSDK_LIB_DIR "$ENV{DXSDK_DIR}lib\\x86")
	endif()

	set(D3D9_LIB_DIRS ${DXSDK_LIB_DIR})

	target_link_directories(h1_map_viewer_d3d9 PRIVATE ${D3D9_LIB_DIRS})
	
	target_link_libraries(h1_map_viewer_d3d9 PRIVATE 
		${PC_LIBS} ${OS_LIBS} ${D3D9_LIBS}
	)
	
	target_include_directories(h1_map_viewer_d3d9 PRIVATE 
		${COMMON_INCLUDE_DIRS} ${D3D9_INCLUDE_DIRS}
	)
	
	target_compile_definitions(h1_map_viewer_d3d9 PRIVATE 
		${COMMON_COMPILE_DEFS} ${D3D9_COMPILE_DEFS}
	)
	
	if(CMAKE_BUILD_TYPE STREQUAL "Debug")
		target_compile_definitions(h1_map_viewer_d3d9 PRIVATE 
			${COMMON_DEBUG_COMPILE_DEFS}
		)
	endif()
	
	if(MSVC)
		target_compile_options(h1_map_viewer_d3d9 PRIVATE 
			${MSVC_COMPILE_OPTIONS}
		)
	
		if (CMAKE_BUILD_TYPE STREQUAL "Debug")
			target_compile_options(h1_map_viewer_d3d9 PRIVATE 
				${MSVC_DEBUG_COMPILE_OPTIONS}
			)
	    elseif (CMAKE_BUILD_TYPE STREQUAL "Release" OR 
		        CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo"
		)
	        target_compile_options(h1_map_viewer_d3d9 PRIVATE 
			    ${MSVC_RELEASE_OPTIONS}
		    )
	    endif()
	endif()
	
	if(GCC)
	    target_compile_options(h1_map_viewer_d3d9 PRIVATE
	        ${GCC_COMPILE_OPTIONS}
	    ) 
	endif()
	
	if(CLANG)
	    target_compile_options(h1_map_viewer_d3d9 PRIVATE
	        ${CLANG_COMPILE_OPTIONS}
	    ) 
	endif()
	
	if(CLANG AND NOT MSVC)
		target_compile_options(h1_map_viewer_d3d9 PRIVATE
			${CLANG_NON_CL_COMMON_OPTIONS}
		)
	endif()
	
	if(CLANG OR GCC)
	    target_compile_options(h1_map_viewer_d3d9 PRIVATE
			${CLANG_GCC_COMPILE_OPTIONS}
	    )
	endif()
	
	if(MSVC AND NOT CLANG)
		target_compile_options(h1_map_viewer_d3d9 PRIVATE 
			${MSVC_NON_CLANG_OPTIONS}
		)
	endif()
	
	if(CLANG AND APPLE)
	    target_compile_options(h1_map_viewer_d3d9 PRIVATE 
	        ${APPLE_CLANG_COMPILE_OPTIONS}
	    )
	endif()
	
	if((CLANG AND NOT MSVC) OR GCC)
	    target_compile_options(h1_map_viewer_d3d9 PRIVATE 
	        ${GCC_CLANG_NON_CL_OPTIONS}
	    ) 
	endif()
	if (MSVC AND CMAKE_SIZEOF_VOID_P EQUAL 4)
		target_link_options(h1_map_viewer_d3d9 PRIVATE "/LARGEADDRESSAWARE")
	endif()
endif()
# =============================================================================

# =============================================================================
if (DEFINED RENDER_BACKEND_D3D8)
	set(D3D8_LIBS d3d8.lib d3dx8.lib)
	set(D3D8_INCLUDE_DIRS "$ENV{DXSDK_DIR}Include")
	set(D3D8_COMPILE_DEFS A_RENDER_BACKEND_GL=0 A_RENDER_BACKEND_D3D9=0 A_RENDER_BACKEND_D3D8=1)

	add_executable(h1_map_viewer_d3d8 ${COMMON_SRC} ${PC_SRC})
	
	if (CMAKE_SIZEOF_VOID_P EQUAL 8)
		set(DXSDK_LIB_DIR $ENV{DXSDK_DIR}lib\\x64)
	elseif (CMAKE_SIZEOF_VOID_P EQUAL 4)
		set(DXSDK_LIB_DIR $ENV{DXSDK_DIR}lib\\x86)
	endif()

	set(D3D8_LIB_DIRS ${DXSDK_LIB_DIR})

	target_link_directories(h1_map_viewer_d3d8 PRIVATE ${D3D8_LIB_DIRS})
	
	target_link_libraries(h1_map_viewer_d3d8 PRIVATE 
		${PC_LIBS} ${OS_LIBS} ${D3D8_LIBS}
	)
	
	target_include_directories(h1_map_viewer_d3d8 PRIVATE 
		${COMMON_INCLUDE_DIRS} ${D3D8_INCLUDE_DIRS}
	)
	
	target_compile_definitions(h1_map_viewer_d3d8 PRIVATE 
		${COMMON_COMPILE_DEFS} ${D3D8_COMPILE_DEFS}
	)
	
	if(CMAKE_BUILD_TYPE STREQUAL "Debug")
		target_compile_definitions(h1_map_viewer_d3d8 PRIVATE 
			${COMMON_DEBUG_COMPILE_DEFS}
		)
	endif()
	
	if(MSVC)
		target_compile_options(h1_map_viewer_d3d8 PRIVATE 
			${MSVC_COMPILE_OPTIONS}
		)
	
		if (CMAKE_BUILD_TYPE STREQUAL "Debug")
			target_compile_options(h1_map_viewer_d3d8 PRIVATE 
				${MSVC_DEBUG_COMPILE_OPTIONS}
			)
	    elseif (CMAKE_BUILD_TYPE STREQUAL "Release" OR 
		        CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo"
		)
	        target_compile_options(h1_map_viewer_d3d8 PRIVATE 
			    ${MSVC_RELEASE_OPTIONS}
		    )
	    endif()
	endif()
	
	if(GCC)
	    target_compile_options(h1_map_viewer_d3d8 PRIVATE
	        ${GCC_COMPILE_OPTIONS}
	    ) 
	endif()
	
	if(CLANG)
	    target_compile_options(h1_map_viewer_d3d8 PRIVATE
	        ${CLANG_COMPILE_OPTIONS}
	    ) 
	endif()
	
	if(CLANG AND NOT MSVC)
		target_compile_options(h1_map_viewer_d3d8 PRIVATE
			${CLANG_NON_CL_COMMON_OPTIONS}
		)
	endif()
	
	if(CLANG OR GCC)
	    target_compile_options(h1_map_viewer_d3d8 PRIVATE
			${CLANG_GCC_COMPILE_OPTIONS}
	    )
	endif()
	
	if(MSVC AND NOT CLANG)
		target_compile_options(h1_map_viewer_d3d8 PRIVATE 
			${MSVC_NON_CLANG_OPTIONS}
		)
	endif()
	
	if(CLANG AND APPLE)
	    target_compile_options(h1_map_viewer_d3d8 PRIVATE 
	        ${APPLE_CLANG_COMPILE_OPTIONS}
	    )
	endif()
	
	if((CLANG AND NOT MSVC) OR GCC)
	    target_compile_options(h1_map_viewer_d3d8 PRIVATE 
	        ${GCC_CLANG_NON_CL_OPTIONS}
	    ) 
	endif()
	if (MSVC AND CMAKE_SIZEOF_VOID_P EQUAL 4)
	target_link_options(h1_map_viewer_d3d8 PRIVATE "/LARGEADDRESSAWARE")
	endif()
endif()

if (DEFINED PLATFORM_XBOX)
	set(XBOX_DEBUG_LIBS   xapilibd.lib d3d8d.lib d3dx8d.lib xgraphicsd.lib 
                          dsoundd.lib dmusicd.lib xactengd.lib xsndtrkd.lib 
                          xvoiced.lib xonlined.lib xboxkrnl.lib xbdm.lib)
	set(XBOX_RELEASE_LIBS xapilib.lib d3d8.lib d3dx8.lib xgraphics.lib
                          dsound.lib dmusic.lib xacteng.lib xsndtrk.lib
                          xvoice.lib xonline.lib xboxkrnl.lib xbdm.lib)
	
	if (CMAKE_BUILD_TYPE STREQUAL "Debug")
		set(XBOX_LIBS ${XBOX_DEBUG_LIBS})
	else()
		set(XBOX_LIBS ${XBOX_RELEASE_LIBS})
	endif()

	set(XBOX_COMPILE_DEFS A_RENDER_BACKEND_D3D8=1 
                          A_RENDER_BACKEND_D3D9=0 
                          A_RENDER_BACKEND_GL=0)

	add_executable(h1_map_viewer_xbox ${COMMON_SRC})
	
	target_compile_definitions(h1_map_viewer_xbox PRIVATE 
		${COMMON_COMPILE_DEFS} ${XBOX_COMPILE_DEFS}
	)
	message("CMAKE_C_FLAGS_DEBUG: ${CMAKE_C_FLAGS_DEBUG}")
	message("CMAKE_CXX_FLAGS_DEBUG: ${CMAKE_CXX_FLAGS_DEBUG}")
	if(CMAKE_BUILD_TYPE STREQUAL "Debug")
		target_compile_definitions(h1_map_viewer_xbox PRIVATE _DEBUG)
	endif()
	
	target_compile_options(h1_map_viewer_xbox PRIVATE "/TP")

	target_link_libraries(h1_map_viewer_xbox PRIVATE ${XBOX_LIBS})
endif()
# =============================================================================
