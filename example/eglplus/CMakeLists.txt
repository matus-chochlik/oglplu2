# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 3.10)

# add a target for the examples
add_custom_target(eglplus-examples ALL)
set_target_properties(
	eglplus-examples
	PROPERTIES FOLDER "Example/EGLplus"
)

function(eglplus_example_common EXAMPLE_NAME)
	add_executable(
		eglplus-${EXAMPLE_NAME}
		${EXAMPLE_NAME}.cpp
	)
	eagine_add_exe_analysis(eglplus-${EXAMPLE_NAME})
	add_dependencies(eglplus-examples eglplus-${EXAMPLE_NAME})
	target_link_libraries(
		eglplus-${EXAMPLE_NAME}
		PUBLIC
			EGL::EGL
			eglplus
	)
	set_property(
		TARGET eglplus-${EXAMPLE_NAME}
		PROPERTY FOLDER "Example/EGLplus"
	)
endfunction()

if(EGL_FOUND)
	eglplus_example_common(001_basic_info)
	eglplus_example_common(002_list_apis)
	eglplus_example_common(003_list_extensions)
	eglplus_example_common(005_list_configs)
	eglplus_example_common(006_multisample_configs)
	eglplus_example_common(007_depth_stencil_configs)
endif()

