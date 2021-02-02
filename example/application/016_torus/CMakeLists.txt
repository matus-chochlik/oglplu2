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
add_executable(application-016_torus main.cpp resources.cpp)
eagine_embed_packed_target_resources(application-016_torus example.oglpprog)
eagine_add_exe_analysis(application-016_torus)

add_dependencies(application-016_torus application-examples)

target_link_libraries(
	application-016_torus
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-016_torus
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-016_torus
	DESTINATION share/oglplus/examples
)
