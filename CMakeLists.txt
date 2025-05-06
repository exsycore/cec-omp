cmake_minimum_required(VERSION 3.19)
project(cec-omp LANGUAGES C CXX VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/open.mp-sdk)

include_directories(
	.
	lib/compiler/source
	lib/compiler/source/linux

    lib
)

add_definitions(
	-DHAVE_STDINT_H=1
	-DPAWN_CELL_SIZE=32
)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
    src/natives.cpp
    src/natives.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    OMP-SDK
)