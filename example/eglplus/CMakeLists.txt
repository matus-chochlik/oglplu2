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
		EXCLUDE_FROM_ALL
		${EXAMPLE_NAME}.cpp
	)
	add_dependencies(eglplus-examples eglplus-${EXAMPLE_NAME})
	foreach(DEP EGL ${ARGN})
		target_link_libraries(
			eglplus-${EXAMPLE_NAME}
			${${DEP}_LIBRARIES}
		)
	endforeach()

	if(INVOKE_CLANG_TIDY)
		set_property(
			TARGET eglplus-${EXAMPLE_NAME}
			PROPERTY CXX_CLANG_TIDY "${INVOKE_CLANG_TIDY}"
		)
	endif()

	set_property(
		TARGET eglplus-${EXAMPLE_NAME}
		PROPERTY FOLDER "Example/EGLplus"
	)
endfunction()

if(OPENAL_FOUND)
	eglplus_example_common(001_basic_info)
	eglplus_example_common(002_list_apis)
	eglplus_example_common(003_list_extensions)
endif()

