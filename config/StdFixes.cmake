#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#

function(make_missing_std_feature_fix FEATURE FILENAME)
	message(STATUS "Generating fix for std ${FEATURE}")
	set(
		HAS_FEATURE_IN
		${PROJECT_SOURCE_DIR}/config/cpp/has_${FILENAME}.cpp.in
	)
	set(
		HAS_FEATURE_SRC
		${PROJECT_BINARY_DIR}/cpp/has_${FILENAME}.cpp
	)
	set(
		FEATURE_STD_IN
		${PROJECT_SOURCE_DIR}/config/cpp/${FILENAME}_std.hpp.in
	)
	set(
		FEATURE_FIX_IN
		${PROJECT_SOURCE_DIR}/config/cpp/${FILENAME}_fix.hpp.in
	)
	set(
		FEATURE_HPP
		${PROJECT_BINARY_DIR}/include/eagine/stdfix/${FILENAME}.hpp
	)

	configure_file("${HAS_FEATURE_IN}" "${HAS_FEATURE_SRC}")

	try_compile(
		HAS_FEATURE
		${PROJECT_BINARY_DIR}/cpp
		${HAS_FEATURE_SRC}
	)

	if(${HAS_FEATURE})
		configure_file("${FEATURE_STD_IN}" "${FEATURE_HPP}")
	else()
		configure_file("${FEATURE_FIX_IN}" "${FEATURE_HPP}")
	endif()

	list(APPEND EAGINE_INCLUDE_DIRS "${PROJECT_BINARY_DIR}/include") 
	list(APPEND EAGINE_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/include") 
	list(APPEND EAGINE_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/implement") 
	list(APPEND EAGINE_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/third_party/GSL/include") 

	try_compile(
		HAS_FEATURE
		${PROJECT_BINARY_DIR}/cpp
		${HAS_FEATURE_SRC}
		COMPILE_DEFINITIONS
		"-DEAGINE_TEST_STD_FEATURE_FIX=1"
		CMAKE_FLAGS
		"-DINCLUDE_DIRECTORIES:STRING=${EAGINE_INCLUDE_DIRS}"
		OUTPUT_VARIABLE HAS_TRAIT_OUTPUT
	)
	if(NOT ${HAS_FEATURE})
		if(DEBUG_CONFIG)
			message(
				FATAL_ERROR
				"${HAS_TRAIT_OUTPUT}\n"
				"Failed to fix std ${FEATURE}"
			)
		else()
			message(
				SEND_ERROR
				"Failed to fix std ${FEATURE}"
			)
		endif()
	endif()
	unset(HAS_TRAIT_OUTPUT)
endfunction()

make_missing_std_feature_fix("boolean constant ops" bool_const_ops)
make_missing_std_feature_fix("integer sequence" int_sequence)
make_missing_std_feature_fix("invoke" invoke)
make_missing_std_feature_fix("optional" optional)
make_missing_std_feature_fix("variant" variant)
make_missing_std_feature_fix("filesystem" filesystem)
