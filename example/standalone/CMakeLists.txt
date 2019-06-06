# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 3.5)


add_custom_target(standalone-examples ALL)
set_property(TARGET standalone-examples PROPERTY FOLDER "Example/Standalone")

function(standalone_example_common EXAMPLE_NAME)
	foreach(DEP OPENGL ${ARGN})
		do_use_single_dependency(${EXAMPLE_NAME} ${DEP})
	endforeach()
	add_executable(
		${EXAMPLE_NAME}
		EXCLUDE_FROM_ALL
		${EXAMPLE_NAME}.cpp
	)
	add_dependencies(standalone-examples ${EXAMPLE_NAME})
	foreach(DEP OPENGL ${ARGN})
		target_link_libraries(${EXAMPLE_NAME} ${${DEP}_LIBRARIES})
	endforeach()

	if(INVOKE_CLANG_TIDY)
		set_property(
			TARGET ${EXAMPLE_NAME}
			PROPERTY CXX_CLANG_TIDY "${INVOKE_CLANG_TIDY}"
		)
	endif()

	set_property(
		TARGET ${EXAMPLE_NAME}
		PROPERTY FOLDER "Example/Standalone"
	)
endfunction()

if(GLFW3_FOUND AND GLEW_FOUND)
	standalone_example_common(001_glfw3_glew_info GLFW3 GLEW)
	standalone_example_common(001_glfw3_glew_clear GLFW3 GLEW)
	standalone_example_common(002_glfw3_glew_triangle GLFW3 GLEW)
	standalone_example_common(003_glfw3_glew_checker GLFW3 GLEW)
	standalone_example_common(004_glfw3_glew_spiral GLFW3 GLEW)
	standalone_example_common(009_glfw3_glew_cube GLFW3 GLEW)
	standalone_example_common(012_glfw3_glew_cube GLFW3 GLEW)
	standalone_example_common(020_glfw3_glew_recursive_cube GLFW3 GLEW)

	if(HAS_GLEW_NV_path_rendering)
		standalone_example_common(003_glfw3_glew_path_nv GLFW3 GLEW)
		standalone_example_common(004_glfw3_glew_path_nv_text GLFW3 GLEW)
	endif()
endif()
