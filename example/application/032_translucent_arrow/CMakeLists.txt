# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
add_executable(application-032_translucent_arrow main.cpp resources.cpp)
eagine_embed_packed_target_resources(
	application-032_translucent_arrow
	vertex_depth.glsl
	vertex_draw.glsl
	fragment_draw.glsl
	arrow.json
)
eagine_add_exe_analysis(application-032_translucent_arrow)

add_dependencies(application-032_translucent_arrow application-examples)

target_link_libraries(
	application-032_translucent_arrow
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-032_translucent_arrow
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-032_translucent_arrow
	DESTINATION share/oglplus/examples
)
