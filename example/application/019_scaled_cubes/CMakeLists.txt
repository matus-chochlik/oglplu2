# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
add_custom_command(
	OUTPUT example.oglpprog
	COMMAND oglplus-bake_program_source
		--vertex vertex.glsl
		--fragment fragment.glsl
		--output "${CMAKE_CURRENT_BINARY_DIR}/example.oglpprog"
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	DEPENDS oglplus-bake_program_source vertex.glsl fragment.glsl
)
set_source_files_properties(
	example.oglpprog
	PROPERTIES GENERATED 1
)
add_executable(application-019_scaled_cubes main.cpp resources.cpp)
eagine_embed_packed_target_resources(application-019_scaled_cubes example.oglpprog)
eagine_add_exe_analysis(application-019_scaled_cubes)

add_dependencies(application-019_scaled_cubes application-examples)

target_link_libraries(
	application-019_scaled_cubes
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-019_scaled_cubes
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-019_scaled_cubes
	DESTINATION share/oglplus/examples
)
