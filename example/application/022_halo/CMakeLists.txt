# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
add_custom_command(
	OUTPUT surface.oglpprog
	COMMAND oglplus-bake_program_source
		--vertex vertex_surface.glsl
		--fragment fragment_surface.glsl
		--output "${CMAKE_CURRENT_BINARY_DIR}/surface.oglpprog"
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	DEPENDS
		oglplus-bake_program_source
		vertex_surface.glsl
		fragment_surface.glsl
)
set_source_files_properties(
	surface.oglpprog
	PROPERTIES GENERATED 1
)

add_custom_command(
	OUTPUT halo.oglpprog
	COMMAND oglplus-bake_program_source
		--vertex vertex_halo.glsl
		--geometry geometry_halo.glsl
		--fragment fragment_halo.glsl
		--output "${CMAKE_CURRENT_BINARY_DIR}/halo.oglpprog"
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	DEPENDS
		oglplus-bake_program_source
		vertex_halo.glsl
		geometry_halo.glsl
		fragment_halo.glsl
)
set_source_files_properties(
	halo.oglpprog
	PROPERTIES GENERATED 1
)

add_executable(application-022_halo main.cpp resources.cpp)
eagine_embed_packed_target_resources(
	application-022_halo
	surface.oglpprog
	halo.oglpprog
)
eagine_add_exe_analysis(application-022_halo)

add_dependencies(application-022_halo application-examples)

target_link_libraries(
	application-022_halo
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-022_halo
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-022_halo
	DESTINATION share/oglplus/examples
)
