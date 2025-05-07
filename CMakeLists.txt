cmake_minimum_required(VERSION 3.10)

project(cecomp)

if (MSVC)
    add_definitions("/MP")
endif()

if(MSVC)
    foreach(flag_var
        CMAKE_C_FLAGS
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_RELEASE
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE)
        if(${flag_var} MATCHES "/MD")
            string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
        endif()
    endforeach()
endif()

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/lib/cmake-modules")

if(UNIX)
	set(CMAKE_CXX_FLAGS "-m32 -std=c++11")
	set(CMAKE_CXX_FLAGS_RELEASE "-O2")
	set(CMAKE_C_FLAGS "-m32")
	set_property(GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS OFF)
endif()

if(WIN32 AND MVC)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/test/plugins")
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/test/plugins")
endif()

if(NOT WIN32)
	if(NOT TARGET_ARCH OR TARGET_ARCH EQUAL x86)
		set(CMAKE_C_FLAGS "-m32 ${CMAKE_C_FLAGS}")
		set(CMAKE_CXX_FLAGS "-m32 ${CMAKE_CXX_FLAGS}")
	endif()
endif()

# removes the sprintf warnings from plugin-natives
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/test/plugins)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_subdirectory(lib/open.mp-sdk)
add_subdirectory(lib/open.mp-gdk)
include_directories(${OMP_GDK_PATH})
add_subdirectory(lib/open.mp-network)

add_subdirectory(src)
