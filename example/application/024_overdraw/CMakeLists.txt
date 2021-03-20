# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
oglplus_add_glsl_program(overdraw_draw)
oglplus_add_glsl_program(overdraw_screen)

add_executable(application-024_overdraw main.cpp resources.cpp)
eagine_embed_packed_target_resources(
	application-024_overdraw
	overdraw_draw.oglpprog
	overdraw_screen.oglpprog
)
eagine_add_exe_analysis(application-024_overdraw)

add_dependencies(application-024_overdraw application-examples)

target_link_libraries(
	application-024_overdraw
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-024_overdraw
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-024_overdraw
	DESTINATION share/oglplus/examples
)
