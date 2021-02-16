# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#

add_executable(application-006_writing main.cpp)
eagine_embed_target_resources(
	application-006_writing
	vertex.glsl
	geometry.glsl
	fragment.glsl
)
eagine_add_exe_analysis(application-006_writing)

add_dependencies(application-006_writing application-examples)

target_link_libraries(
	application-006_writing
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-006_writing
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-006_writing
	DESTINATION share/oglplus/examples
)
