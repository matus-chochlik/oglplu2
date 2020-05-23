#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
find_package(Boost COMPONENTS unit_test_framework)

function(eagine_add_boost_test LIBRARY TEST_NAME)
	add_executable(
		test-boost-${LIBRARY}-${TEST_NAME}
		EXCLUDE_FROM_ALL
		${TEST_NAME}.cpp
	)
	target_link_libraries(
		test-boost-${LIBRARY}-${TEST_NAME}
		Boost::unit_test_framework
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
		FOLDER "test/${LIBRARY}"
		FIXTURES_SETUP "test-boost-${LIBRARY}-${TEST_NAME}-built"
	)

	add_test(
		NAME test-boost-${LIBRARY}-${TEST_NAME}-exec
		COMMAND "$<TARGET_FILE:test-boost-${LIBRARY}-${TEST_NAME}>"
	)
	set_tests_properties(
		test-boost-${LIBRARY}-${TEST_NAME}-exec
		PROPERTIES
		FOLDER "test/${LIBRARY}"
		FIXTURES_REQUIRED "test-boost-${LIBRARY}-${TEST_NAME}-built"
	)
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
