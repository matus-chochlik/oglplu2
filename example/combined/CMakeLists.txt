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

add_library(EAGXharness::GLX INTERFACE IMPORTED)
if(GLX_FOUND)
	set_target_properties(
		EAGXharness::GLX PROPERTIES
		INTERFACE_INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/source/utils/"
	)
	set_target_properties(
		EAGXharness::GLX PROPERTIES
		INTERFACE_LINK_LIBRARIES GLX::GLX
	)
endif()

foreach(LIB GLFW3 GLFW GLUT SDL)
	add_library(EAGXharness::${LIB} INTERFACE IMPORTED)
	if(${LIB}_FOUND)
		set_target_properties(
			EAGXharness::${LIB} PROPERTIES
			INTERFACE_LINK_LIBRARIES ${LIB}::${LIB}
		)
	endif()
endforeach()

add_library(
	combined_example_harness STATIC
	EXCLUDE_FROM_ALL
		example/args.cpp
		example/wrapper.cpp
		example/params.cpp
		example/state_view.cpp
		example/context.cpp
		example/camera.cpp
		example/random.cpp
		example/main.cpp
		example/main_glx.cpp
		example/main_glfw3.cpp
		example/main_glfw.cpp
		example/main_glut.cpp
		example/main_sdl.cpp
)
eagine_add_lib_analysis(combined_example_harness)
set_target_properties(
	combined_example_harness
	PROPERTIES FOLDER "Example/Combined"
)
target_link_libraries(
	combined_example_harness
	PUBLIC
		eagine
		oglplus
		EAGXharness::GLX
		EAGXharness::GLFW3
		EAGXharness::GLFW
		EAGXharness::GLUT
		EAGXharness::SDL
)

# helper function used in the directories containing examples
function(add_examples EXAMPLE_PATTERN)
	file(GLOB EXAMPLES "${CMAKE_CURRENT_SOURCE_DIR}/${EXAMPLE_PATTERN}.cpp")

	foreach(EXAMPLE_PATH ${EXAMPLES})
		get_filename_component(EXAMPLE_NAME "${EXAMPLE_PATH}" NAME_WE)
		set(TARGET_NAME "combined-${EXAMPLE_NAME}")

		add_executable(
			${TARGET_NAME} EXCLUDE_FROM_ALL
			${EXAMPLE_PATH}
		)
		eagine_add_exe_analysis(${TARGET_NAME})
		set_target_properties(
			${TARGET_NAME}
			PROPERTIES FOLDER "Example/Combined"
		)
		add_dependencies("combined-examples" ${TARGET_NAME})
		target_link_libraries(
			${TARGET_NAME}
			PUBLIC
				GLEW::GLEW
				combined_example_harness
		)
	endforeach()
endfunction(add_examples)

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

