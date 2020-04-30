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

function(eagine_add_example)
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
	eagine_embed_resources(${TARGET_NAME})
	eagine_add_exe_analysis(${TARGET_NAME})
	set_target_properties(
		${TARGET_NAME}
		PROPERTIES FOLDER "Example/Combined/${EXAMPLE_NAME}"
	)
	add_dependencies("combined-examples" ${TARGET_NAME})
	target_link_libraries(
		${TARGET_NAME}
		PUBLIC
			GLEW::GLEW
			combined_example_harness
	)
	eagine_install_example(${TARGET_NAME})
endfunction()

add_subdirectory(001_clear)
add_subdirectory(002_spectrum_compat)
add_subdirectory(003_checker_compat)
add_subdirectory(004_triangle)
add_subdirectory(005_pick_triangle)
add_subdirectory(007_cube)
add_subdirectory(010_newton)
add_subdirectory(011_mandelbrot)

add_subdirectory(shaders)
add_subdirectory(programs)

