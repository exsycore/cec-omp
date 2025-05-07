include(AMXConfig)
include(AddSAMPPlugin)

set(SAMP_SDK_ROOT "${PROJECT_SOURCE_DIR}/lib/samp-plugin-sdk")
find_package(SAMPSDK REQUIRED)

include_directories(
	${SAMPSDK_INCLUDE_DIR}
)

add_samp_plugin(cecomp
	plugin.def

	${SAMPSDK_DIR}/amxplugin.cpp
	${SAMPSDK_DIR}/amxplugin2.cpp
	${SAMPSDK_DIR}/amx/getch.c
	common.hpp
	main.cpp
	main.hpp
	impl.cpp
	impl.hpp
	natives.cpp
	natives.hpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE OMP-SDK omp-gdk OMP-Network)
