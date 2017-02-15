#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
macro(add_compile_test LIBRARY TEST_NAME)
	add_library(
		${LIBRARY}-${TEST_NAME}-compile_test
		EXCLUDE_FROM_ALL
		${TEST_NAME}.cpp
	)
	add_test(
		${LIBRARY}-${TEST_NAME}-compile_test
		"${CMAKE_COMMAND}"
		--build "${CMAKE_BINARY_DIR}"
		--target ${LIBRARY}-${TEST_NAME}-compile_test
	)
endmacro()

macro(add_compile_tests LIBRARY)
	file(GLOB COMPILE_TESTS *.cpp)
	foreach(COMPILE_TEST ${COMPILE_TESTS})
		get_filename_component(TEST_NAME "${COMPILE_TEST}" NAME_WE)
		add_compile_test(${LIBRARY} ${TEST_NAME})
	endforeach()
endmacro()
