#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 3.5)

enable_testing()
include(../testing.cmake)

include_directories(${OPENGL_INCLUDE_DIRS})

add_runtime_tests(oglplus)

add_runtime_test_dependency(oglplus "error_info" "error_handling")
add_runtime_test_dependency(oglplus "error_info" "error_format")

add_runtime_test_dependency(oglplus "glsl_source_ref" "glsl_string_ref")

if(NOT ${NO_ENUM_TESTS})
	add_subdirectory(enums)
endif()
