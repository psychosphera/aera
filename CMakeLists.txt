cmake_minimum_required(VERSION 3.27)
project(h1_map_viewer C CXX)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_REQUIRED ON)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	set(GCC true)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	set(CLANG true)
endif()

if(APPLE)
    enable_language(OBJC)
endif()

#set(VCPKG_TOOLCHAIN ) 
#if(EXISTS VCPKG_TOOLCHAIN)
if (MSVC)
    include("F:/vcpkg/scripts/buildsystems/vcpkg.cmake")
endif()
#endif()

find_package(cglm     REQUIRED)
find_package(Freetype REQUIRED)
find_package(ZLIB     REQUIRED)

# SDL3 and SDL3_image aren't available from vcpkg. SDL_image contains SDL as a
# dependency, so it can be used instead of downloading another copy.
#
# Both have to be built out-of-tree.
add_subdirectory(
	${CMAKE_SOURCE_DIR}/deps/SDL_image/external/SDL 
	${CMAKE_SOURCE_DIR}/deps/SDL_image/external/SDL_build
)
add_subdirectory(
	${CMAKE_SOURCE_DIR}/deps/SDL_image 
	${CMAKE_SOURCE_DIR}/deps/SDL_image_build
)


set(SDL3_LIB_DIR ${CMAKE_SOURCE_DIR}/deps/SDL_image/external/SDL_build)
set(SDL3_LIB_NAME 
	${CMAKE_SHARED_LIBRARY_PREFIX}SDL3${CMAKE_SHARED_LIBRARY_SUFFIX}
)
set(SDL3_PATH ${SDL3_LIB_DIR}/${SDL3_LIB_NAME})
message(STATUS ${SDL3_PATH})
add_custom_target(SDL3_lib)
add_custom_command(
	TARGET SDL3_lib POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
	        SDL3_LIB_DIR/SDL3_LIB_NAME
	        ${CMAKE_CURRENT_BINARY_DIR}/SDL3_LIB_NAME
)

set(SDL3_IMAGE_LIB_DIR ${CMAKE_SOURCE_DIR}/deps/SDL_image_build)
set(SDL3_IMAGE_LIB_NAME 
	${CMAKE_SHARED_LIBRARY_PREFIX}SDL3_image${CMAKE_SHARED_LIBRARY_SUFFIX}
)
set(SDL3_IMAGE_PATH ${SDL3_IMAGE_LIB_DIR}/${SDL3_IMAGE_LIB_NAME})
message(STATUS ${SDL3_IMAGE_PATH})
add_custom_target(SDL3_image_lib)
add_custom_command(
	TARGET SDL3_image_lib POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy SDL3_IMAGE_PATH
	        
	        ${CMAKE_CURRENT_BINARY_DIR}/SDL3_LIB_NAME
)

set(COMMON_SRC 
	src/acommon/a_common.c src/acommon/a_io.c src/acommon/a_math.c 
	src/acommon/a_string.c src/acommon/a_type.c 
	
	src/acommon/z_mem.c
	
	src/cg_cgame.c src/cl_client.c src/cl_map.cpp src/cmd_commands.c 
	src/com.c src/com_print.c src/con_console.c src/db_files.c 
	src/devcon.c  src/devgui.c src/dvar.c src/font.c src/fs_files.c 
	src/gfx.c src/gfx_backend.c src/gfx_defs.c src/gfx_map.c 
	src/gfx_shader.c  src/gfx_text.c src/gfx_uniform.c  src/in_input.c
	src/main.c src/m_math.c src/pm_pmove.c src/sys.c
)

set(COMMON_LIBS 
	SDL3::SDL3 SDL3_image::SDL3_image cglm::cglm Freetype::Freetype ZLIB::ZLIB
)

set(COMMON_INCLUDE_DIRS       ${CMAKE_SOURCE_DIR}/deps/invader/include)
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
)

set(GCC_CLANG_NON_CL_OPTIONS 
	"-Wall" "-Wextra" "-Werror" "-Wno-type-limits" "-Og"
)

set(CLANG_COMPILE_OPTIONS
	"-Wno-gnu-zero-variadic-macro-arguments"
	"-Wno-unreachable-code-generic-assoc"
	"-Wno-sign-compare" "-Wno-macro-redefined"
	"-Wno-pointer-to-int-cast" 
	"-Wno-c99-designator" 
	"-Wno-gnu-anonymous-struct"
	"-Wno-address-of-packed-member"
	"-Wno-sign-compare"
	"-Wno-embedded-directive"
	"-Wno-c23-extensions"
	"-fmacro-backtrace-limit=1"
)

set(CLANG_NON_CL_COMMON_OPTIONS "-pedantic" "-pedantic-errors")

set(CLANG_GCC_COMPILE_OPTIONS "-Wno-int-to-pointer-cast")

set(APPLE_CLANG_COMPILE_OPTIONS "-Wno-undef-prefix")

# =============================================================================
if (DEFINED RENDER_BACKEND_GL)
	set(GL_LIBS GLEW::GLEW OpenGL::GL)
	set(GL_COMPILE_DEFS A_RENDER_BACKEND_GL=1 A_RENDER_BACKEND_D3D9=0)

	find_package(GLEW   REQUIRED)
	find_package(OpenGL REQUIRED)
	
	add_executable(h1_map_viewer_gl ${COMMON_SRC})
	
	target_link_libraries(h1_map_viewer_gl PRIVATE ${COMMON_LIBS} ${GL_LIBS})
	target_include_directories(h1_map_viewer_gl PRIVATE ${COMMON_INCLUDE_DIRS})
	target_compile_definitions(h1_map_viewer_gl PRIVATE 
		${COMMON_COMPILE_DEFS} ${GL_COMPILE_DEFS}
	)
	
	if(CMAKE_BUILD_TYPE STREQUAL "Debug")
		target_compile_definitions(h1_map_viewer_gl PRIVATE 
			${COMMON_DEBUG_DEFS}
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
	
	if(CLANG)
	    target_compile_options(h1_map_viewer_gl PRIVATE 
			${CLANG_COMPILE_OPTIONS}
		) 
	endif()
	
	if(CLANG AND NOT MSVC)
		target_compile_options(h1_map_viewer_gl PRIVATE
			${CLANG_NON_CL_COMMON_OPTIONS}
		)
	endif()
	
	if(CLANG OR GCC)
	    target_compile_options(h1_map_viewer_gl PRIVATE 
			${CLANG_GCC_COMPILE_OPTIONS}
		)
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
	endif()
	
	if((CLANG AND NOT MSVC) OR GCC)
	    target_compile_options(h1_map_viewer_gl PRIVATE 
			${GCC_CLANG_NON_CL_OPTIONS}
		)
	endif()
endif()
# =============================================================================

# =============================================================================
if (DEFINED RENDER_BACKEND_D3D9)
	set(D3D9_LIBS d3d9.lib d3dx9.lib)
	set(D3D9_INCLUDE_DIRS "$ENV{DXSDK_DIR}Include")
	set(D3D9_COMPILE_DEFS A_RENDER_BACKEND_GL=0 A_RENDER_BACKEND_D3D9=1)

	add_executable(h1_map_viewer_d3d9 ${COMMON_SRC})
	
	if (CMAKE_SIZEOF_VOID_P EQUAL 8)
		set(DXSDK_LIB_DIR $ENV{DXSDK_DIR}lib\\x64)
	elseif (CMAKE_SIZEOF_VOID_P EQUAL 4)
		set(DXSDK_LIB_DIR $ENV{DXSDK_DIR}lib\\x86)
	endif()

	set(D3D9_LIB_DIRS ${DXSDK_LIB_DIR})

	target_link_directories(h1_map_viewer_d3d9 PRIVATE ${D3D9_LIB_DIRS})
	
	target_link_libraries(h1_map_viewer_d3d9 PRIVATE 
		${COMMON_LIBS} ${D3D9_LIBS}
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
endif()
# =============================================================================