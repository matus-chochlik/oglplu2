# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
oglplus_add_glsl_program(recursive_cube)
add_executable(application-025_recursive_cube main.cpp resources.cpp)
eagine_embed_packed_target_resources(
	application-025_recursive_cube
	recursive_cube.oglpprog
)
eagine_add_exe_analysis(application-025_recursive_cube)

add_dependencies(application-025_recursive_cube application-examples)

target_link_libraries(
	application-025_recursive_cube
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-025_recursive_cube
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-025_recursive_cube
	DESTINATION share/oglplus/examples
)
