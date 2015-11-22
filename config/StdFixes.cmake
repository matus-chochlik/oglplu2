#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
function(fix_std_type_trait TEMPLATE TYPE_TRAIT FIXES_HPP)
	configure_file(
		${PROJECT_SOURCE_DIR}/config/cpp/has_${TEMPLATE}_t.cpp.in
		${PROJECT_BINARY_DIR}/cpp/has_${TYPE_TRAIT}_t.cpp
	)
	try_compile(
		HAS_${TYPE_TRAIT}
		${PROJECT_BINARY_DIR}/cpp
		${PROJECT_BINARY_DIR}/cpp/has_${TYPE_TRAIT}_t.cpp
		COMPILE_DEFINITIONS ${CPP_STD_COMPILER_SWITCH}
	)

	if(NOT ${HAS_${TYPE_TRAIT}})
		configure_file(
			${PROJECT_SOURCE_DIR}/config/cpp/make_${TEMPLATE}_t.inl.in
			${PROJECT_BINARY_DIR}/cpp/make_${TYPE_TRAIT}_t.inl
		)
		file(READ ${PROJECT_BINARY_DIR}/cpp/make_${TYPE_TRAIT}_t.inl CONTENTS)
		file(APPEND ${FIXES_HPP} "${CONTENTS}")

		try_compile(
			HAS_${TYPE_TRAIT}
			${PROJECT_BINARY_DIR}/cpp
			${PROJECT_BINARY_DIR}/cpp/has_${TYPE_TRAIT}_t.cpp
			COMPILE_DEFINITIONS ${CPP_STD_COMPILER_SWITCH}
			"-DEAGINE_TEST_TRAIT_FIX=1"
		)
		if(NOT ${HAS_${TYPE_TRAIT}})
			message(FATAL_ERROR "Failed to fix std::${TYPE_TRAIT}_t")
		endif()
	endif()

endfunction()

function(fix_simple_std_type_trait TYPE_TRAIT FIXES_HPP)
	fix_std_type_trait(TYPE_TRAIT "${TYPE_TRAIT}" "${FIXES_HPP}")
endfunction()

function(fix_other_std_type_trait TYPE_TRAIT FIXES_HPP)
	fix_std_type_trait("${TYPE_TRAIT}" "${TYPE_TRAIT}" "${FIXES_HPP}")
endfunction()

function(make_std_type_traits_fixes)
	message(STATUS "Generating fixes for std type_traits")

	set(HEADER type_traits)
	set(FIXES_HPP ${PROJECT_BINARY_DIR}/include/eagine/${HEADER}_fixes.hpp)
	configure_file(
		${PROJECT_SOURCE_DIR}/config/eagine/${HEADER}_fixes.hpp.in
		${FIXES_HPP}
	)

	fix_other_std_type_trait(conditional "${FIXES_HPP}")
	fix_other_std_type_trait(enable_if "${FIXES_HPP}")
	fix_other_std_type_trait(is_convertible "${FIXES_HPP}")

	fix_simple_std_type_trait(decay "${FIXES_HPP}")
	fix_simple_std_type_trait(add_const "${FIXES_HPP}")
	fix_simple_std_type_trait(remove_const "${FIXES_HPP}")
	fix_simple_std_type_trait(add_pointer "${FIXES_HPP}")
	fix_simple_std_type_trait(remove_reference "${FIXES_HPP}")
	fix_simple_std_type_trait(remove_cv "${FIXES_HPP}")
	fix_simple_std_type_trait(add_lvalue_reference "${FIXES_HPP}")
	fix_simple_std_type_trait(remove_all_extents "${FIXES_HPP}")

	file(APPEND ${FIXES_HPP} "} // namespace std\n")
	file(APPEND ${FIXES_HPP} "#endif\n")
endfunction()

make_std_type_traits_fixes()

function(make_std_integer_sequence_fix)
	message(STATUS "Generating fix for std integer_sequence")
	configure_file(
		${PROJECT_SOURCE_DIR}/config/cpp/has_int_sequence.cpp.in
		${PROJECT_BINARY_DIR}/cpp/has_int_sequence.cpp
	)
	try_compile(
		HAS_INT_SEQUENCE
		${PROJECT_BINARY_DIR}/cpp
		${PROJECT_BINARY_DIR}/cpp/has_int_sequence.cpp
		COMPILE_DEFINITIONS ${CPP_STD_COMPILER_SWITCH}
	)

	if(${HAS_INT_SEQUENCE})
		configure_file(
			${PROJECT_SOURCE_DIR}/config/cpp/int_sequence_std.hpp.in
			${PROJECT_BINARY_DIR}/include/eagine/int_sequence_fix.hpp
		)
	else()
		configure_file(
			${PROJECT_SOURCE_DIR}/config/cpp/int_sequence.hpp.in
			${PROJECT_BINARY_DIR}/include/eagine/int_sequence_fix.hpp
		)
	endif()

	try_compile(
		HAS_INT_SEQUENCE
		${PROJECT_BINARY_DIR}/cpp
		${PROJECT_BINARY_DIR}/cpp/has_int_sequence.cpp
		COMPILE_DEFINITIONS "${CPP_STD_COMPILER_SWITCH}"
		"-DEAGINE_TEST_INT_SEQ_FIX=1"
		CMAKE_FLAGS
		"-DINCLUDE_DIRECTORIES:STRING=${PROJECT_BINARY_DIR}/include "
	)
	if(NOT ${HAS_INT_SEQUENCE})
		message(FATAL_ERROR "Failed to fix std::integer_sequence")
	endif()
endfunction()

make_std_integer_sequence_fix()
