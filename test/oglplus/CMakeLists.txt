#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 2.8)

enable_testing()
include(CTest)

function(add_oglplus_compile_test TEST_NAME)
	add_library(oglplus_${TEST_NAME} EXCLUDE_FROM_ALL ${TEST_NAME}.cpp)
	add_test(
		oglplus-compile_test-${TEST_NAME}
		"${CMAKE_COMMAND}"
		--build "${CMAKE_BINARY_DIR}"
		--target oglplus_${TEST_NAME}
	)
endfunction()

add_oglplus_compile_test("vertex_array_c")
add_oglplus_compile_test("buffer_c")
add_oglplus_compile_test("framebuffer_c")
add_oglplus_compile_test("renderbuffer_c")
add_oglplus_compile_test("texture_c")
add_oglplus_compile_test("sampler_c")
add_oglplus_compile_test("shader_c")
add_oglplus_compile_test("program_c")
add_oglplus_compile_test("program_pipeline_c")
add_oglplus_compile_test("transform_feedback_c")
add_oglplus_compile_test("query_c")

