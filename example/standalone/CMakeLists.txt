# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 2.8)


add_custom_target(standalone-examples ALL)
set_property(TARGET standalone-examples PROPERTY FOLDER "Example/Standalone")

function(standalone_example_common EXAMPLE_NAME)
	foreach(DEP OPENGL ${ARGN})
		do_use_single_dependency(${DEP})
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
	set_property(TARGET ${EXAMPLE_NAME} PROPERTY FOLDER "Example/Standalone")
endfunction()

if(GLFW_FOUND AND GLEW_FOUND)
	standalone_example_common(001_glfw_glew_clear GLFW GLEW) 
	standalone_example_common(002_glfw_glew_triangle GLFW GLEW) 
	standalone_example_common(003_glfw_glew_checker GLFW GLEW) 
endif()

