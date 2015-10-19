#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
macro(add_compile_test LIBRARY TEST_NAME)
	add_library(${TEST_NAME} EXCLUDE_FROM_ALL ${TEST_NAME}.cpp)
	add_test(
		${LIBRARY}-compile_test-${TEST_NAME}
		"${CMAKE_COMMAND}"
		--build "${CMAKE_BINARY_DIR}"
		--target ${TEST_NAME}
	)
endmacro()

macro(add_runtime_test LIBRARY TEST_NAME)
	add_executable(${TEST_NAME} EXCLUDE_FROM_ALL ${TEST_NAME}.cpp)
	add_test(
		${LIBRARY}-build_test-${TEST_NAME}
		"${CMAKE_COMMAND}"
		--build "${CMAKE_BINARY_DIR}"
		--target ${TEST_NAME}
	)
	target_link_libraries(
		${TEST_NAME}
		${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
	)
	set_tests_properties(
		${LIBRARY}-build_test-${TEST_NAME}
		PROPERTIES FOLDER
		"test/${LIBRARY}"
	)

	add_test(
		${LIBRARY}-execute_test-${TEST_NAME}
		"${CURRENT_BINARY_DIR}/${TEST_NAME}"
	)
	set_tests_properties(
		${LIBRARY}-execute_test-${TEST_NAME}
		PROPERTIES DEPENDS
		${LIBRARY}-build_test-${TEST_NAME}
	)
	set_tests_properties(
		${LIBRARY}-execute_test-${TEST_NAME}
		PROPERTIES FOLDER
		"test/${LIBRARY}"
	)
endmacro()

function(add_runtime_test_dependency LIBRARY REQUIRED DEPENDING)
	set_tests_properties(
		${LIBRARY}-build_test-${DEPENDING}
		PROPERTIES DEPENDS
		${LIBRARY}-build_test-${REQUIRED}
	)
	set_tests_properties(
		${LIBRARY}-execute_test-${DEPENDING}
		PROPERTIES DEPENDS
		${LIBRARY}-execute_test-${REQUIRED}
	)
endfunction()

