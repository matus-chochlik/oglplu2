# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
oglplus_add_glsl_program(scaled_cubes)
add_executable(application-019_scaled_cubes main.cpp resources.cpp)
eagine_embed_packed_target_resources(
	application-019_scaled_cubes
	scaled_cubes.oglpprog
)
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
