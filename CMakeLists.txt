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

# =============================================================================
if (DEFINED RENDER_BACKEND_GL)
	find_package(GLEW     REQUIRED)
	find_package(OpenGL   REQUIRED)
	
	add_executable(h1_map_viewer_gl
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
	
	target_link_libraries(h1_map_viewer_gl PRIVATE 
		SDL3::SDL3 SDL3_image::SDL3_image cglm::cglm Freetype::Freetype 
		GLEW::GLEW OpenGL::GL ZLIB::ZLIB
	)
	
	target_include_directories(
		h1_map_viewer_gl PRIVATE ${CMAKE_SOURCE_DIR}/deps/invader/include
	)
	
	set_target_properties(
		h1_map_viewer_gl PROPERTIES WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/build
	)
	
	target_compile_definitions(
	    h1_map_viewer_gl PRIVATE A_PROJECT_ROOT="${CMAKE_SOURCE_DIR}"
	)
	
	if(CMAKE_BUILD_TYPE STREQUAL "Debug")
		target_compile_definitions(h1_map_viewer_gl PRIVATE 
			_DEBUG=1 A_RENDER_BACKEND_GL=1 A_RENDER_BACKEND_D3D9=0
		)
	endif()
	
	if(MSVC)
		target_compile_options(h1_map_viewer_gl PRIVATE 
			"/permissive-" "/W4" "/bigobj" 
		)
	
		if (CMAKE_BUILD_TYPE STREQUAL "Debug")
			target_compile_options(h1_map_viewer_gl PRIVATE 
			    "/Od"
		    )
	    elseif (CMAKE_BUILD_TYPE STREQUAL "Release" OR 
		        CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo"
		)
	        target_compile_options(h1_map_viewer_gl PRIVATE 
			    "/O2"
		    )
	    endif()
	endif()
	
	if(GCC)
	    target_compile_options(h1_map_viewer_gl PRIVATE
	        "-ftrack-macro-expansion=0" 
			"-Wno-address-of-packed-member"
			"-Wno-comment"
	    ) 
	endif()
	
	if(CLANG)
	    target_compile_options(h1_map_viewer_gl PRIVATE
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
	endif()
	
	if(CLANG AND NOT MSVC)
		target_compile_options(h1_map_viewer_gl PRIVATE
			"-pedantic" "-pedantic-errors" 
		)
	endif()
	
	if(CLANG OR GCC)
	    target_compile_options(h1_map_viewer_gl PRIVATE
			"-Wno-int-to-pointer-cast"
	    )
	endif()
	
	if(MSVC AND NOT CLANG)
		target_compile_options(h1_map_viewer_gl PRIVATE 
			"/Zc:preprocessor" "/Zc:__cplusplus" "/Zc:__STDC__" "/wd4005" "/wd4244"
			"/wd4267" "/wd4311" "/wd4305" "/wd4312" "/wd4201" "/wd4018"
		)
	endif()
	
	if(CLANG AND APPLE)
	    target_compile_options(h1_map_viewer_gl PRIVATE 
	        "-Wno-undef-prefix"
	    )
	endif()
	
	if((CLANG AND NOT MSVC) OR GCC)
	    target_compile_options(h1_map_viewer_gl PRIVATE 
	        "-Wall" "-Wextra" "-Werror" "-Wno-type-limits" "-Og"
	    ) 
	endif()
endif()
# =============================================================================

# =============================================================================
if (DEFINED RENDER_BACKEND_D3D9)
	add_executable(h1_map_viewer_d3d9
	    src/acommon/a_common.c src/acommon/a_io.c src/acommon/a_math.c 
		src/acommon/a_string.c src/acommon/a_type.c 
		
		src/acommon/z_mem.c
	
		src/cg_cgame.c src/cl_client.c src/cl_map.cpp src/cmd_commands.c 
		src/com.c src/com_print.c src/con_console.c src/db_files.c 
		src/devcon.c  src/devgui.c src/dvar.c src/font.c src/fs_files.c 
		src/gfx.c  src/gfx_backend.c src/gfx_defs.c src/gfx_map.c 
		src/gfx_shader.c  src/gfx_text.c src/gfx_uniform.c  src/in_input.c
		src/main.c src/m_math.c src/pm_pmove.c src/sys.c
	)

	if (CMAKE_SIZEOF_VOID_P EQUAL 8)
		target_link_directories(h1_map_viewer_d3d9 PRIVATE 
			$ENV{DXSDK_DIR}lib\\x64
		)
	elseif (CMAKE_SIZEOF_VOID_P EQUAL 4)
		target_link_directories(h1_map_viewer_d3d9 PRIVATE 
			$ENV{DXSDK_DIR}lib\\x86
		)
	endif()
	
	target_link_libraries(h1_map_viewer_d3d9 PRIVATE 
		SDL3::SDL3 SDL3_image::SDL3_image cglm::cglm Freetype::Freetype 
		ZLIB::ZLIB d3d9.lib d3dx9.lib
	)
	
	target_include_directories(h1_map_viewer_d3d9 PRIVATE 
		${CMAKE_SOURCE_DIR}/deps/invader/include 
		$ENV{DXSDK_DIR}Include
	)
	message(STATUS "$ENV{DXSDK_DIR}Include")
	
	set_target_properties(
		h1_map_viewer_d3d9 PROPERTIES WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/build
	)
	
	target_compile_definitions(
	    h1_map_viewer_d3d9 PRIVATE A_PROJECT_ROOT="${CMAKE_SOURCE_DIR}"
	)
	
	if(CMAKE_BUILD_TYPE STREQUAL "Debug")
		target_compile_definitions(h1_map_viewer_d3d9 PRIVATE 
			_DEBUG=1 A_RENDER_BACKEND_GL=0 A_RENDER_BACKEND_D3D9=1
		)
	endif()
	
	if(MSVC)
		target_compile_options(h1_map_viewer_d3d9 PRIVATE 
			"/permissive-" "/W4" "/bigobj" 
		)
	
		if (CMAKE_BUILD_TYPE STREQUAL "Debug")
			target_compile_options(h1_map_viewer_d3d9 PRIVATE 
			    "/Od"
		    )
	    elseif (CMAKE_BUILD_TYPE STREQUAL "Release" OR 
		        CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo"
		)
	        target_compile_options(h1_map_viewer_d3d9 PRIVATE 
			    "/O2"
		    )
	    endif()
	endif()
	
	if(GCC)
	    target_compile_options(h1_map_viewer_d3d9 PRIVATE
	        "-ftrack-macro-expansion=0" 
			"-Wno-address-of-packed-member"
			"-Wno-comment"
	    ) 
	endif()
	
	if(CLANG)
	    target_compile_options(h1_map_viewer_d3d9 PRIVATE
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
	endif()
	
	if(CLANG AND NOT MSVC)
		target_compile_options(h1_map_viewer_d3d9 PRIVATE
			"-pedantic" "-pedantic-errors" 
		)
	endif()
	
	if(CLANG OR GCC)
	    target_compile_options(h1_map_viewer_d3d9 PRIVATE
			"-Wno-int-to-pointer-cast"
	    )
	endif()
	
	if(MSVC AND NOT CLANG)
		target_compile_options(h1_map_viewer_d3d9 PRIVATE 
			"/Zc:preprocessor" "/Zc:__cplusplus" "/Zc:__STDC__" "/wd4005" "/wd4244"
			"/wd4267" "/wd4311" "/wd4305" "/wd4312" "/wd4201" "/wd4018"
		)
	endif()
	
	if(CLANG AND APPLE)
	    target_compile_options(h1_map_viewer_d3d9 PRIVATE 
	        "-Wno-undef-prefix"
	    )
	endif()
	
	if((CLANG AND NOT MSVC) OR GCC)
	    target_compile_options(h1_map_viewer_d3d9 PRIVATE 
	        "-Wall" "-Wextra" "-Werror" "-Wno-type-limits" "-Og"
	    ) 
	endif()
endif()
# =============================================================================