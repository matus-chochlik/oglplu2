# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

add_subdirectory(lib)
add_subdirectory(app)
add_subdirectory(message_bus)
add_subdirectory(tools)

set(
	OGLPLUS_EXPORT_TARGETS
		eagine
		eagine-application
		eagine-message_bus-router
		eagine-message_bus-bridge
		eagine-message_bus-pingable
		eagine-message_bus-pinger
		eagine-message_bus-sudoku_helper
		eagine-message_bus-sudoku_tiling
		oglplus
		oglplus-bake_program_source
		oglplus-bake_noise_image
		oglplus-bake_tiling_image
		oglplus-bake_checker_image
		oglplus-texgen
)
if(TARGET oglplus-bake_png_image)
	list(APPEND OGLPLUS_EXPORT_TARGETS oglplus-bake_png_image)
endif()
if(TARGET eglplus)
	list(APPEND OGLPLUS_EXPORT_TARGETS eglplus)
endif()

if(TARGET oalplus)
	list(APPEND OGLPLUS_EXPORT_TARGETS oalplus)
endif()

if(TARGET ryml)
	list(APPEND OGLPLUS_EXPORT_TARGETS ryml)
endif()

if(TARGET eagine-message_bus-monitor)
	list(APPEND OGLPLUS_EXPORT_TARGETS eagine-message_bus-monitor)
endif()

install(
	TARGETS ${OGLPLUS_EXPORT_TARGETS}
	EXPORT OGLplusTargets
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin
	INCLUDES DESTINATION include
)

install(
	EXPORT OGLplusTargets
	FILE Targets.cmake
	NAMESPACE OGLplus::
	DESTINATION lib/cmake/OGLplus
)

