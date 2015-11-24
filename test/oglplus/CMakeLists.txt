#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 2.8)

enable_testing()
include(../testing.cmake)

include_directories(${OPENGL_INCLUDE_DIRS})

file(GLOB COMPILE_TESTS *_c.cpp)
foreach(COMPILE_TEST ${COMPILE_TESTS})
	get_filename_component(TEST_NAME "${COMPILE_TEST}" NAME_WE)
	add_compile_test(oglplus ${TEST_NAME})
endforeach()

file(GLOB RUNTIME_TESTS *_r.cpp)
foreach(RUNTIME_TEST ${RUNTIME_TESTS})
	get_filename_component(TEST_NAME "${RUNTIME_TEST}" NAME_WE)
	add_runtime_test(oglplus ${TEST_NAME})
endforeach()

add_runtime_test_dependency(oglplus "error_info_r" "error_handling_r")
add_runtime_test_dependency(oglplus "error_info_r" "error_format_r")

add_runtime_test_dependency(oglplus "glsl_source_ref_r" "glsl_string_ref_r")

if(NOT ${NO_ENUM_TESTS})
	add_subdirectory(enums)
endif()
