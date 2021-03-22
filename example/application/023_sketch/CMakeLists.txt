# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
oglplus_add_glsl_program(sketch)

add_executable(application-023_sketch main.cpp resources.cpp)
eagine_embed_packed_target_resources(
	application-023_sketch
	sketch.oglpprog
)
eagine_add_exe_analysis(application-023_sketch)

add_dependencies(application-023_sketch application-examples)

target_link_libraries(
	application-023_sketch
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-023_sketch
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-023_sketch
	DESTINATION share/oglplus/examples
)
