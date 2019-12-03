# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 3.10)

function(eagine_example_common EXAMPLE_NAME)
	add_executable("${EXAMPLE_NAME}" "${EXAMPLE_NAME}.cpp")
	target_link_libraries("${EXAMPLE_NAME}" eagine)
endfunction()

eagine_example_common(environment)
eagine_example_common(identifier)
eagine_example_common(id_tag)
eagine_example_common(interleaved_call)
eagine_example_common(hexdump)
eagine_example_common(bindump)
eagine_example_common(base64)
eagine_example_common(random_bytes)
eagine_example_common(scope_exit)
eagine_example_common(zip_ranges)
eagine_example_common(variable_history)
eagine_example_common(memoized)

