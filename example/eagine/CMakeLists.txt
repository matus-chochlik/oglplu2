# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
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
		${ARGN}
	)
	eagine_add_exe_analysis(eagine-${EXAMPLE_NAME})
	add_dependencies(eagine-examples eagine-${EXAMPLE_NAME})
	target_link_libraries(
		eagine-${EXAMPLE_NAME}
		PUBLIC eagine
		PRIVATE ${ARGN}
	)

	set_target_properties(
		eagine-${EXAMPLE_NAME}
		PROPERTIES FOLDER "Example/EAGine"
	)
	eagine_install_example(eagine-${EXAMPLE_NAME})
endfunction()

eagine_example_common(valgrind)
eagine_example_common(array_size)
eagine_example_common(integer_hash)
eagine_example_common(signal_switch)
eagine_example_common(limit_cast)
eagine_example_common(str_format)
eagine_example_common(type_name)
eagine_example_common(args_within_limits)
eagine_example_common(extract)
eagine_example_common(tribool)
eagine_example_common(environment)
eagine_example_common(system_info)
eagine_example_common(build_info)
eagine_example_common(user_info)
eagine_example_common(application_config)
eagine_example_common(progress_bar)
eagine_example_common(from_string)
eagine_example_common(string_path)
eagine_example_common(edit_distance)
eagine_example_common(identifier)
eagine_example_common(type_identity)
eagine_example_common(id_tag)
eagine_example_common(interleaved_call)
eagine_example_common(overloaded)
eagine_example_common(hexdump)
eagine_example_common(bindump)
eagine_example_common(base64)
eagine_example_common(url)
eagine_example_common(log_histogram)
eagine_example_common(random_bytes)
eagine_example_common(compress_self)
eagine_example_common(scope_exit)
eagine_example_common(zip_ranges)
eagine_example_common(version)
eagine_example_common(uptime)
eagine_example_common(units)
eagine_example_common(animated_value)
eagine_example_common(variable_history)
eagine_example_common(network_sort)
eagine_example_common(make_index)
eagine_example_common(value_tree)
eagine_example_common(memoized)
eagine_example_common(c_api_wrap)
eagine_example_common(dyn_lib_lookup)
eagine_example_common(sudoku_solver)
eagine_example_common(sudoku_tiling)
eagine_example_common(sudoku_noise)
eagine_example_common(shape_topology)
#
eagine_example_common(embed_self)
eagine_embed_target_resources(eagine-embed_self)
eagine_example_common(embed_baked)
eagine_embed_packed_target_resources(eagine-embed_baked zebra_fur)
#
add_subdirectory(ecs)
add_subdirectory(ssl)
add_subdirectory(serialize)
add_subdirectory(message_bus)
