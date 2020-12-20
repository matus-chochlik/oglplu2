#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
find_package(Boost COMPONENTS unit_test_framework)

function(do_add_boost_test LIBRARY TEST_NAME)
	add_executable(
		test-boost-${LIBRARY}-${TEST_NAME}
		EXCLUDE_FROM_ALL
		${TEST_NAME}.cpp
	)
	target_compile_definitions(
		test-boost-${LIBRARY}-${TEST_NAME}
		PRIVATE EAGINE_IMPLEMENTING_LIBRARY=1
	)
	target_link_libraries(
		test-boost-${LIBRARY}-${TEST_NAME}
		PRIVATE eagine Boost::unit_test_framework
	)
	add_test(
		NAME test-boost-${LIBRARY}-${TEST_NAME}-build
		COMMAND "${CMAKE_COMMAND}"
		--build "${CMAKE_BINARY_DIR}"
		--target test-boost-${LIBRARY}-${TEST_NAME}
	)
	set_tests_properties(
		test-boost-${LIBRARY}-${TEST_NAME}-build
		PROPERTIES
		TIMEOUT 120
		FOLDER "test/${LIBRARY}"
		FIXTURES_SETUP "test-boost-${LIBRARY}-${TEST_NAME}-built"
	)

	add_test(
		NAME test-boost-${LIBRARY}-${TEST_NAME}-execute
		COMMAND "$<TARGET_FILE:test-boost-${LIBRARY}-${TEST_NAME}>"
	)
	set_tests_properties(
		test-boost-${LIBRARY}-${TEST_NAME}-execute
		PROPERTIES
		TIMEOUT 200
		FOLDER "test/${LIBRARY}"
		FIXTURES_REQUIRED "test-boost-${LIBRARY}-${TEST_NAME}-built"
	)
	if(VALGRIND_COMMAND)
		add_test(
			NAME test-boost-${LIBRARY}-${TEST_NAME}-memcheck
			COMMAND "${VALGRIND_COMMAND}"
				"--leak-check=full"
				"--error-exitcode=1"
				"$<TARGET_FILE:test-boost-${LIBRARY}-${TEST_NAME}>"
		)
		set_tests_properties(
			test-boost-${LIBRARY}-${TEST_NAME}-memcheck
			PROPERTIES
			TIMEOUT 800
			FOLDER "test/${LIBRARY}"
			FIXTURES_REQUIRED "test-boost-${LIBRARY}-${TEST_NAME}-built"
		)
	endif()
endfunction()

if(Boost_FOUND)
	add_subdirectory(eagine)
	add_subdirectory(oglplus)

	if(EGL_FOUND)
		add_subdirectory(eglplus)
	endif()

	if(OPENAL_FOUND)
		add_subdirectory(oalplus)
	endif()
else()
	message(WARNING "Boost.Test required for testing but not found")
endif()
