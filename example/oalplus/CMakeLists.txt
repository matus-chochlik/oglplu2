# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 3.10)

# add a target for the examples
add_custom_target(oalplus-examples ALL)
set_target_properties(
	oalplus-examples
	PROPERTIES FOLDER "Example/OALplus"
)

function(oalplus_example_common EXAMPLE_NAME)
	add_executable(
		oalplus-${EXAMPLE_NAME}
		EXCLUDE_FROM_ALL
		${EXAMPLE_NAME}.cpp
	)
	add_dependencies(oalplus-examples oalplus-${EXAMPLE_NAME})
	foreach(DEP OPENAL ${ARGN})
		target_link_libraries(
			oalplus-${EXAMPLE_NAME}
			${${DEP}_LIBRARIES}
		)
	endforeach()

	if(INVOKE_CLANG_TIDY)
		set_property(
			TARGET oalplus-${EXAMPLE_NAME}
			PROPERTY CXX_CLANG_TIDY "${INVOKE_CLANG_TIDY}"
		)
	endif()

	set_property(
		TARGET oalplus-${EXAMPLE_NAME}
		PROPERTY FOLDER "Example/OALplus"
	)
endfunction()

oalplus_example_common(001_list_devices)

