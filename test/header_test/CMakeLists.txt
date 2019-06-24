#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 3.10)

enable_testing()

set(TEST_SRC_PREFIX "${PROJECT_SOURCE_DIR}/include")
set(TEST_DST_PREFIX "${CMAKE_CURRENT_BINARY_DIR}")

# TODO:
set(TESTED_HEADERS "${TEST_SRC_PREFIX}/eagine/program_args.hpp")

foreach(TESTED_HEADER ${TESTED_HEADERS})
	string(
		REGEX REPLACE
		"^${TEST_SRC_PREFIX}/" ""
		TESTED_HEADER_REL_PATH
		"${TESTED_HEADER}"
	)
	string(
		REGEX REPLACE
		"[/.]" "_"
		TEST_NAME
		"${TESTED_HEADER_REL_PATH}"
	)
	set(HELPER_SOURCE "${TEST_DST_PREFIX}/${TESTED_HEADER_REL_PATH}.cpp")
	configure_file(
		"${CMAKE_CURRENT_SOURCE_DIR}/helper.cpp"
		"${HELPER_SOURCE}"
		@ONLY
	)
	set(TEST_NAME "header_test_${TEST_NAME}")
	add_executable(
		"${TEST_NAME}"
		EXCLUDE_FROM_ALL
		"${HELPER_SOURCE}"
	)
	if(INVOKE_CLANG_TIDY)
		set_property(
			TARGET ${TEST_NAME}
			PROPERTY CXX_CLANG_TIDY "${INVOKE_CLANG_TIDY}"
		)
	endif()
endforeach()
