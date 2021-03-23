# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
oglplus_add_glsl_program(checker_torus)
add_executable(application-016_torus main.cpp resources.cpp)
eagine_embed_packed_target_resources(
	application-016_torus
	checker_torus.oglpprog
)
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
