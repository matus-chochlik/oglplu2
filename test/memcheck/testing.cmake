#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
macro(add_memcheck_test LIBRARY TEST_NAME)
	add_executable(
		${LIBRARY}-${TEST_NAME}-memcheck
		EXCLUDE_FROM_ALL
		${TEST_NAME}.cpp
	)
	add_test(
		${LIBRARY}-${TEST_NAME}-memcheck-build
		"${CMAKE_COMMAND}"
		--build "${CMAKE_BINARY_DIR}"
		--target ${LIBRARY}-${TEST_NAME}-memcheck
	)
	set_property(
		TEST
		${LIBRARY}-${TEST_NAME}-memcheck-build
		APPEND PROPERTY FOLDER
		"test/${LIBRARY}"
	)

	add_test(
		${LIBRARY}-${TEST_NAME}-memcheck-exec
		${VALGRIND} --tool=memcheck --leak-check=full
		"${CMAKE_CURRENT_BINARY_DIR}/${LIBRARY}-${TEST_NAME}-memcheck"
	)
	set_property(
		TEST
		${LIBRARY}-${TEST_NAME}-memcheck-exec
		APPEND PROPERTY DEPENDS
		${LIBRARY}-${TEST_NAME}-memcheck-build
	)
	set_property(
		TEST
		${LIBRARY}-${TEST_NAME}-memcheck-exec
		APPEND PROPERTY FOLDER
		"test/${LIBRARY}"
	)
endmacro()

macro(add_memcheck_tests LIBRARY)
	file(GLOB MEMCHECK_TESTS *.cpp)
	foreach(MEMCHECK_TEST ${MEMCHECK_TESTS})
		get_filename_component(TEST_NAME "${MEMCHECK_TEST}" NAME_WE)
		add_memcheck_test(${LIBRARY} ${TEST_NAME})
	endforeach()
endmacro()

