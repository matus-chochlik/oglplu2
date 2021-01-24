# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#

add_executable(application-004_triangle main.cpp)
eagine_embed_target_resources(application-004_triangle vertex.glsl fragment.glsl)
eagine_add_exe_analysis(application-004_triangle)

add_dependencies(application-004_triangle application-examples)

target_link_libraries(
	application-004_triangle
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-004_triangle
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-004_triangle
	DESTINATION share/oglplus/examples
)
