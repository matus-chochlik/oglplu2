# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
oglplus_add_glsl_program(metaball_prog)
oglplus_add_glsl_program(field_prog)
oglplus_add_glsl_program(surface_prog)

add_executable(application-040_metaballs main.cpp resources.cpp)
eagine_embed_packed_target_resources(
	application-040_metaballs
	metaball_prog
	field_prog
	surface_prog
)
eagine_add_exe_analysis(application-040_metaballs)

add_dependencies(application-040_metaballs application-examples)

target_link_libraries(
	application-040_metaballs
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-040_metaballs
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-040_metaballs
	DESTINATION share/oglplus/examples
)
