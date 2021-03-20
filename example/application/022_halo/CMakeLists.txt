# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
oglplus_add_glsl_program(halo_surface)
oglplus_add_glsl_program(halo_halo)

add_executable(application-022_halo main.cpp resources.cpp)
eagine_embed_packed_target_resources(
	application-022_halo
	halo_surface.oglpprog
	halo_halo.oglpprog
	twisted_sphere.json
)
eagine_add_exe_analysis(application-022_halo)

add_dependencies(application-022_halo application-examples)

target_link_libraries(
	application-022_halo
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-022_halo
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-022_halo
	DESTINATION share/oglplus/examples
)
