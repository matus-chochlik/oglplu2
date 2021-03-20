# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#

# add a target for the examples
add_custom_target(application-examples ALL)
set_target_properties(
	application-examples
	PROPERTIES FOLDER "Example/Application"
)

add_subdirectory(001_clear)
add_subdirectory(002_spectrum)
add_subdirectory(003_checker)
add_subdirectory(004_triangle)
add_subdirectory(005_pick_triangle)
add_subdirectory(006_writing)
add_subdirectory(007_cube)
add_subdirectory(008_yaml_shape)
add_subdirectory(009_json_shape)
add_subdirectory(010_newton)
add_subdirectory(011_mandelbrot)
add_subdirectory(012_atomic_counters)
add_subdirectory(014_voronoi)
add_subdirectory(015_worley)
add_subdirectory(016_torus)
add_subdirectory(017_occlusion)
add_subdirectory(018_uv_map)
add_subdirectory(019_scaled_cubes)
add_subdirectory(020_bezier_patch)
add_subdirectory(022_halo)
add_subdirectory(024_overdraw)
add_subdirectory(025_recursive_cube)
add_subdirectory(026_cel_shading)
add_subdirectory(027_single_pass_edges)
add_subdirectory(028_compute_particles)
add_subdirectory(031_tessellation)
add_subdirectory(032_translucent_arrow)
add_subdirectory(040_metaballs)
