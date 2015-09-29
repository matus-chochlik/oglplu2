#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 2.8)

enable_testing()
include(../testing.cmake)

function(add_oglplus_compile_test TEST_NAME)
	add_compile_test(oglplus ${TEST_NAME})
endfunction()

function(add_oglplus_runtime_test TEST_NAME)
	add_runtime_test(oglplus ${TEST_NAME})
endfunction()

file(GLOB COMPILE_TESTS *_c.cpp)
foreach(COMPILE_TEST ${COMPILE_TESTS})
	get_filename_component(TEST_NAME "${COMPILE_TEST}" NAME_WE)
	add_oglplus_compile_test(${TEST_NAME})
endforeach()

add_subdirectory(enums)
