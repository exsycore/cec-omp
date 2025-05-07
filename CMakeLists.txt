cmake_minimum_required(VERSION 3.19)
project(cec-omp LANGUAGES C CXX VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/open.mp-sdk)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/lib/cmake-modules")

set(SAMP_SDK_ROOT "${PROJECT_SOURCE_DIR}/lib/samp-plugin-sdk")
find_package(SAMPSDK REQUIRED)

include_directories(
	${SAMPSDK_INCLUDE_DIR}
)

include_directories(
	.

    lib
)

add_definitions(
	-DHAVE_STDINT_H=1
	-DPAWN_CELL_SIZE=32
)

add_library(${PROJECT_NAME} SHARED
    ${SAMPSDK_DIR}/amxplugin.cpp
    ${SAMPSDK_DIR}/amxplugin2.cpp
    ${SAMPSDK_DIR}/amx/getch.c

    src/main.cpp
    src/natives.cpp
    src/natives.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    OMP-SDK
)
