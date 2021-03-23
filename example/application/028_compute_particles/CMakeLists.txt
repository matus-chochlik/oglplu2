# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
oglplus_add_glsl_program(compute_particles_draw)
oglplus_add_glsl_program(compute_particles_emit)

add_executable(application-028_compute_particles main.cpp resources.cpp)
eagine_embed_packed_target_resources(
	application-028_compute_particles
	compute_particles_draw.oglpprog
	compute_particles_emit.oglpprog
)
eagine_add_exe_analysis(application-028_compute_particles)

add_dependencies(application-028_compute_particles application-examples)

target_link_libraries(
	application-028_compute_particles
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-028_compute_particles
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-028_compute_particles
	DESTINATION share/oglplus/examples
)
