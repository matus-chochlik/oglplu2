# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#

add_executable(application-008_yaml_shape main.cpp)
eagine_embed_target_resources(
	application-008_yaml_shape
	vertex.glsl fragment.glsl
	shape.yaml
)
eagine_add_exe_analysis(application-008_yaml_shape)

add_dependencies(application-008_yaml_shape application-examples)

target_link_libraries(
	application-008_yaml_shape
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-008_yaml_shape
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-008_yaml_shape
	DESTINATION share/oglplus/examples
)
