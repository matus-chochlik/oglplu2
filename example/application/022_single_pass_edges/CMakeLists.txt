# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
oglplus_add_glsl_program(single_pass_edges)
add_executable(application-022_single_pass_edges main.cpp resources.cpp)
eagine_embed_packed_target_resources(
	application-022_single_pass_edges
	single_pass_edges.oglpprog
)
eagine_add_exe_analysis(application-022_single_pass_edges)

add_dependencies(application-022_single_pass_edges application-examples)

target_link_libraries(
	application-022_single_pass_edges
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-022_single_pass_edges
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-022_single_pass_edges
	DESTINATION share/oglplus/examples
)
