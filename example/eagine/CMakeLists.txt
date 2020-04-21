# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 3.10)

add_custom_target(eagine-examples ALL)
set_target_properties(
	eagine-examples
	PROPERTIES FOLDER "Example/EAGine"
)

function(eagine_example_common EXAMPLE_NAME)
	add_executable(
		eagine-${EXAMPLE_NAME}
		EXCLUDE_FROM_ALL
		"${EXAMPLE_NAME}.cpp"
	)
	add_dependencies(eagine-examples eagine-${EXAMPLE_NAME})
	target_link_libraries(
		eagine-${EXAMPLE_NAME}
		PUBLIC eagine
	)

	set_target_properties(
		eagine-${EXAMPLE_NAME}
		PROPERTIES FOLDER "Example/EAGine"
	)
endfunction()

eagine_example_common(valgrind)
eagine_example_common(array_size)
eagine_example_common(signal_switch)
eagine_example_common(limit_cast)
eagine_example_common(str_format)
eagine_example_common(type_name)
eagine_example_common(args_within_limits)
eagine_example_common(extract)
eagine_example_common(environment)
eagine_example_common(tribool)
eagine_example_common(progress_bar)
eagine_example_common(from_string)
eagine_example_common(string_path)
eagine_example_common(identifier)
eagine_example_common(identity)
eagine_example_common(id_tag)
eagine_example_common(interleaved_call)
eagine_example_common(callable_composer)
eagine_example_common(hexdump)
eagine_example_common(bindump)
eagine_example_common(base64)
eagine_example_common(random_bytes)
eagine_example_common(scope_exit)
eagine_example_common(zip_ranges)
eagine_example_common(units)
eagine_example_common(variable_history)
eagine_example_common(network_sort)
eagine_example_common(make_index)
eagine_example_common(memoized)
eagine_example_common(c_api_wrap)

add_subdirectory(serialize)
add_subdirectory(message_bus)
