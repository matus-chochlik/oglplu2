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
			${EXAMPLE_NAME}
			EXCLUDE_FROM_ALL
			${EXAMPLE_NAME}.cpp
		)
		add_dependencies(oglplus-examples ${EXAMPLE_NAME})
		target_link_libraries(
			${EXAMPLE_NAME}
			PUBLIC
				GLFW3::GLFW3
				GLEW::GLEW
				oglplus
		)

		if(INVOKE_CLANG_TIDY)
			set_property(
				TARGET ${EXAMPLE_NAME}
				PROPERTY CXX_CLANG_TIDY "${INVOKE_CLANG_TIDY}"
			)
		endif()

		set_property(
			TARGET ${EXAMPLE_NAME}
			PROPERTY FOLDER "Example/OGLplus"
		)
	endif()
endfunction()

standalone_example_glfw3_glew(001_glfw3_glew_info)
standalone_example_glfw3_glew(001_glfw3_glew_clear)
