# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#

# add a target for the examples
add_custom_target(combined-examples ALL)
set_target_properties(
	combined-examples
	PROPERTIES FOLDER "Example/Combined"
)

add_subdirectory(example)

function(eagine_example_use_model FILE_NAME)
	configure_file(
		"${PROJECT_SOURCE_DIR}/assets/models/${FILE_NAME}"
		"${CMAKE_CURRENT_BINARY_DIR}/${FILE_NAME}"
	)
endfunction()

function(eagine_add_directory_resources)
	get_filename_component(
		EXAMPLE_NAME
		"${CMAKE_CURRENT_SOURCE_DIR}"
		NAME
	)
	set(TARGET_NAME "combined-${EXAMPLE_NAME}")
	eagine_embed_target_resources(${TARGET_NAME} ${ARGN})
endfunction()

function(eagine_pack_directory_resources)
	get_filename_component(
		EXAMPLE_NAME
		"${CMAKE_CURRENT_SOURCE_DIR}"
		NAME
	)
	set(TARGET_NAME "combined-${EXAMPLE_NAME}")
	eagine_embed_packed_target_resources(${TARGET_NAME} ${ARGN})
endfunction()

function(eagine_add_directory_example)
	get_filename_component(
		EXAMPLE_NAME
		"${CMAKE_CURRENT_SOURCE_DIR}"
		NAME
	)
	set(TARGET_NAME "combined-${EXAMPLE_NAME}")

	add_executable(
		${TARGET_NAME} EXCLUDE_FROM_ALL
		${ARGN}
	)
	eagine_add_exe_analysis(${TARGET_NAME})
	set_target_properties(
		${TARGET_NAME}
		PROPERTIES FOLDER "Example/Combined/${EXAMPLE_NAME}"
	)
	add_dependencies("combined-examples" ${TARGET_NAME})
	target_link_libraries(
		${TARGET_NAME}
		PUBLIC
			$<TARGET_NAME:GLEW::GLEW>
			combined_example_harness
	)
	eagine_install_example(${TARGET_NAME})
endfunction()

add_subdirectory(005_pick_triangle)
add_subdirectory(007_cube)
add_subdirectory(008_yaml_shape)
add_subdirectory(009_json_shape)
add_subdirectory(011_mandelbrot)
add_subdirectory(014_voronoi)
add_subdirectory(016_torus)
add_subdirectory(017_occlusion)
add_subdirectory(018_uv_map)
add_subdirectory(019_scaled_cubes)
add_subdirectory(025_recursive_cube)
add_subdirectory(026_cel_shading)
add_subdirectory(027_single_pass_edges)
add_subdirectory(032_translucent_arrow)
