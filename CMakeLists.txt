cmake_minimum_required(VERSION 3.27)
project(h1_map_viewer C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_REQUIRED ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_REQUIRED ON)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	set(GCC true)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	set(CLANG true)
endif()

if(APPLE)
    enable_language(OBJC)
endif()

#set(VCPKG_TOOLCHAIN ) 
#if(EXISTS VCPKG_TOOLCHAIN)
#    include("F:/vcpkg/scripts/buildsystems/vcpkg.cmake")
#endif()

find_package(Freetype REQUIRED)
find_package(GLEW     REQUIRED)
find_package(OpenGL   REQUIRED)
find_package(glm      REQUIRED)
find_package(ZLIB     REQUIRED)

add_executable(h1_map_viewer
    src/acommon/a_string.c src/acommon/a_common.c src/acommon/a_type.c
    src/acommon/z_mem.c src/acommon/a_math.c src/acommon/a_math.h

	src/cg_cgame.cpp src/com.cpp src/font.cpp src/fs_files.cpp src/gfx.cpp 
	src/gfx_backend.cpp  src/in_input.cpp src/main.cpp src/sys.cpp
 	src/db_files.cpp src/cmd_commands.cpp src/cl_client.cpp src/devgui.cpp 
	src/gfx_text.cpp src/gfx_shaders.cpp src/devcon.cpp src/dvar.cpp 
	src/con_console.cpp src/pm_pmove.cpp src/m_math.cpp
)


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

target_link_libraries(h1_map_viewer PRIVATE SDL3::SDL3)
target_link_libraries(h1_map_viewer PRIVATE SDL3_image::SDL3_image)
target_link_libraries(h1_map_viewer PRIVATE Freetype::Freetype)
target_link_libraries(h1_map_viewer PRIVATE GLEW::GLEW)
target_link_libraries(h1_map_viewer PRIVATE OpenGL::GL)
target_link_libraries(h1_map_viewer PRIVATE ZLIB::ZLIB)

if(WIN32)
	target_link_libraries(h1_map_viewer PRIVATE wsock32 ws2_32)
endif()

target_include_directories(h1_map_viewer PRIVATE SDL3::SDL3)
target_include_directories(h1_map_viewer PRIVATE SDL3_image::SDL3_image)
target_include_directories(h1_map_viewer PRIVATE Freetype::Freetype)
target_include_directories(h1_map_viewer PRIVATE GLEW::GLEW)
target_include_directories(h1_map_viewer PRIVATE glm::glm)
target_include_directories(
	h1_map_viewer PRIVATE ${CMAKE_SOURCE_DIR}/deps/invader/include
)

set_target_properties(
	h1_map_viewer PROPERTIES WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/build
)

target_compile_definitions(
    h1_map_viewer PRIVATE A_PROJECT_ROOT="${CMAKE_SOURCE_DIR}"
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	target_compile_definitions(h1_map_viewer PRIVATE _DEBUG=1)
else()
	target_compile_definitions(h1_map_viewer PRIVATE _DEBUG=0)
endif()

if(MSVC)
	target_compile_options(h1_map_viewer PRIVATE 
		"/permissive-" "/W4" "/wd4005" "/bigobj" "/WX"
	)
endif()

if(GCC)
    target_compile_options(h1_map_viewer PRIVATE
        "-Wno-sign-compare"
    ) 
endif()

if(CLANG)
    target_compile_options(h1_map_viewer PRIVATE
        "-Wno-gnu-zero-variadic-macro-arguments"
        "-Wno-unreachable-code-generic-assoc"
	"-Wno-sign-compare" "-Wno-macro-redefined"
    	"-Wno-pointer-to-int-cast"
    ) 
endif()

if(CLANG OR GCC)
    target_compile_options(h1_map_viewer PRIVATE
	"-Wno-int-to-pointer-cast"
    )
endif()

if(MSVC AND NOT CLANG)
	target_compile_options(h1_map_viewer PRIVATE 
		"/Zc:preprocessor" "/Zc:__cplusplus" "/Zc:__STDC__"
	)
endif()

if(CLANG AND APPLE)
    target_compile_options(h1_map_viewer PRIVATE 
        "-Wno-undef-prefix"
    )
endif()

if((CLANG AND NOT MSVC) OR GCC)
    target_compile_options(h1_map_viewer PRIVATE 
        "-Wall" "-Wextra" "-Werror" "-pedantic" "-pedantic-errors" 
        "-Wno-type-limits"
    ) 
endif()
