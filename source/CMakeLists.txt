# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

add_subdirectory(lib)
add_subdirectory(tools)
add_subdirectory(textures)

set(
	OGLPLUS_EXPORT_TARGETS
		eagine
		eagine-message_bus-router
		eagine-message_bus-bridge
		eglplus
		oglplus
		oglplus-bake_program_source
		oglplus-bake_png_image
		oglplus-bake_noise_image
		oglplus-bake_checker_image
		oglplus-texgen
		oalplus
)
if(TARGET ryml)
	list(APPEND OGLPLUS_EXPORT_TARGETS ryml)
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

