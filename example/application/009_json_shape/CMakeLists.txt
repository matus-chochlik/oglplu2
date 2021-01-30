# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#

add_executable(application-009_json_shape main.cpp)
eagine_embed_target_resources(
	application-009_json_shape
	vertex.glsl fragment.glsl
	shape.json
)
eagine_add_exe_analysis(application-009_json_shape)

add_dependencies(application-009_json_shape application-examples)

target_link_libraries(
	application-009_json_shape
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-009_json_shape
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-009_json_shape
	DESTINATION share/oglplus/examples
)
