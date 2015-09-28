#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 2.8)

enable_testing()
include(CTest)
include(../testing.cmake)

function(add_eagine_runtime_test TEST_NAME)
	add_runtime_test(eagine ${TEST_NAME})
endfunction()

function(add_eagine_runtime_test_dependency REQUIRED DEPENDING)
	add_runtime_test_dependency(eagine ${REQUIRED} ${DEPENDING})
endfunction()

file(GLOB RUNTIME_TESTS *_r.cpp)
foreach(RUNTIME_TEST ${RUNTIME_TESTS})
	get_filename_component(TEST_NAME "${RUNTIME_TEST}" NAME_WE)
	add_eagine_runtime_test(${TEST_NAME})
endforeach()

add_eagine_runtime_test_dependency("deferred_handler_r" "outcome_r")
