# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 3.10)

add_custom_target(oglplus-examples ALL)
set_property(TARGET oglplus-examples PROPERTY FOLDER "Example/OGLplus")

function(standalone_example_glfw3_glew EXAMPLE_NAME)
	if(GLFW3_FOUND AND GLEW_FOUND)
		add_executable(
			oglplus-${EXAMPLE_NAME}
			EXCLUDE_FROM_ALL
			${EXAMPLE_NAME}.cpp
		)
		eagine_add_exe_analysis(oglplus-${EXAMPLE_NAME})
		add_dependencies(oglplus-examples oglplus-${EXAMPLE_NAME})
		target_link_libraries(
			oglplus-${EXAMPLE_NAME}
			PUBLIC
				GLFW3::GLFW3
				GLEW::GLEW
				oglplus
		)
		set_property(
			TARGET oglplus-${EXAMPLE_NAME}
			PROPERTY FOLDER "Example/OGLplus"
		)
		eagine_install_example(oglplus-${EXAMPLE_NAME})
	endif()
endfunction()

standalone_example_glfw3_glew(001_glfw3_glew_info)
standalone_example_glfw3_glew(001_glfw3_glew_clear)
