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
	eagine_add_exe_analysis(oalplus-${EXAMPLE_NAME})
	add_dependencies(oalplus-examples oalplus-${EXAMPLE_NAME})
	target_link_libraries(
		oalplus-${EXAMPLE_NAME}
		PUBLIC
			OpenAL::OpenAL
			oalplus
	)
	set_property(
		TARGET oalplus-${EXAMPLE_NAME}
		PROPERTY FOLDER "Example/OALplus"
	)
	eagine_install_example(oalplus-${EXAMPLE_NAME})
endfunction()

if(OPENAL_FOUND)
	oalplus_example_common(001_basic_info)
	oalplus_example_common(002_list_devices)
	oalplus_example_common(003_list_extensions)
	oalplus_example_common(004_context_info)
	oalplus_example_common(005_hello_world)
endif()

