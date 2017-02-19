#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
macro(add_runtime_test LIBRARY TEST_NAME)
	add_executable(
		${LIBRARY}-${TEST_NAME}-boost_test
		EXCLUDE_FROM_ALL
		${TEST_NAME}.cpp
	)
	add_test(
		${LIBRARY}-${TEST_NAME}-boost_test-build
		"${CMAKE_COMMAND}"
		--build "${CMAKE_BINARY_DIR}"
		--target ${LIBRARY}-${TEST_NAME}-boost_test
	)
	target_link_libraries(
		${LIBRARY}-${TEST_NAME}-boost_test
		${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
	)
	set_property(
		TEST
		${LIBRARY}-${TEST_NAME}-boost_test-build
		APPEND PROPERTY FOLDER
		"test/${LIBRARY}"
	)

	add_test(
		${LIBRARY}-${TEST_NAME}-boost_test-exec
		"${CMAKE_CURRENT_BINARY_DIR}/${LIBRARY}-${TEST_NAME}-boost_test"
	)
	set_property(
		TEST
		${LIBRARY}-${TEST_NAME}-boost_test-exec
		APPEND PROPERTY DEPENDS
		${LIBRARY}-${TEST_NAME}-boost_test-build
	)
	set_property(
		TEST
		${LIBRARY}-${TEST_NAME}-boost_test-exec
		APPEND PROPERTY FOLDER
		"test/${LIBRARY}"
	)
endmacro()

macro(add_runtime_tests LIBRARY)
	file(GLOB RUNTIME_TESTS *.cpp)
	foreach(RUNTIME_TEST ${RUNTIME_TESTS})
		get_filename_component(TEST_NAME "${RUNTIME_TEST}" NAME_WE)
		add_runtime_test(${LIBRARY} ${TEST_NAME})
	endforeach()
endmacro()

function(add_runtime_test_dependency LIBRARY REQUIRED DEPENDING)
	set_property(
		TEST
		${LIBRARY}-${DEPENDING}-boost_test-build
		APPEND PROPERTY DEPENDS
		${LIBRARY}-${REQUIRED}-boost_test-build
	)
	set_property(
		TEST
		${LIBRARY}-${DEPENDING}-boost_test-exec
		APPEND PROPERTY DEPENDS
		${LIBRARY}-${REQUIRED}-boost_test-exec
	)
endfunction()

