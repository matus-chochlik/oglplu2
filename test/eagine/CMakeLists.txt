#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 2.8)

enable_testing()
include(../testing.cmake)

file(GLOB RUNTIME_TESTS *_r.cpp)
foreach(RUNTIME_TEST ${RUNTIME_TESTS})
	get_filename_component(TEST_NAME "${RUNTIME_TEST}" NAME_WE)
	add_runtime_test(eagine ${TEST_NAME})
endforeach()

add_runtime_test_dependency(eagine "deferred_handler_r" "outcome_r")
add_runtime_test_dependency(eagine "mp_list_r" "enum_class_r")
add_runtime_test_dependency(eagine "enum_class_r" "enum_bitfield_r")
add_runtime_test_dependency(eagine "make_view_r" "buffer_size_r")
add_runtime_test_dependency(eagine "buffer_size_r" "buffer_data_r")
