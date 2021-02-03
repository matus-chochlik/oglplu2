# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
add_custom_command(
	OUTPUT draw.oglpprog
	COMMAND oglplus-bake_program_source
		--vertex vs_draw.glsl
		--fragment fs_draw.glsl
		--output "${CMAKE_CURRENT_BINARY_DIR}/draw.oglpprog"
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	DEPENDS oglplus-bake_program_source vs_draw.glsl fs_draw.glsl
)
set_source_files_properties(
	draw.oglpprog
	PROPERTIES GENERATED 1
)

add_custom_command(
	OUTPUT screen.oglpprog
	COMMAND oglplus-bake_program_source
		--vertex vs_screen.glsl
		--fragment fs_screen.glsl
		--output "${CMAKE_CURRENT_BINARY_DIR}/screen.oglpprog"
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	DEPENDS oglplus-bake_program_source vs_screen.glsl fs_screen.glsl
)
set_source_files_properties(
	screen.oglpprog
	PROPERTIES GENERATED 1
)

add_executable(application-024_overdraw main.cpp resources.cpp)
eagine_embed_packed_target_resources(
	application-024_overdraw
	draw.oglpprog
	screen.oglpprog
)
eagine_add_exe_analysis(application-024_overdraw)

add_dependencies(application-024_overdraw application-examples)

target_link_libraries(
	application-024_overdraw
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-024_overdraw
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-024_overdraw
	DESTINATION share/oglplus/examples
)
