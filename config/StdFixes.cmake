#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
function(do_fix_std_type_trait TPL_HAS TPL_MAKE TYPE_TRAIT SUFFIX FIXES_HPP)

	set(
		HAS_TRAIT_IN
		${PROJECT_SOURCE_DIR}/config/cpp/has_${TPL_HAS}${SUFFIX}.cpp.in
	)
	set(
		HAS_TRAIT_SRC
		${PROJECT_BINARY_DIR}/cpp/has_${TYPE_TRAIT}${SUFFIX}.cpp
	)
	set(
		MAKE_TRAIT_IN
		${PROJECT_SOURCE_DIR}/config/cpp/make_${TPL_MAKE}${SUFFIX}.inl.in
	)
	set(
		MAKE_TRAIT_SRC
		${PROJECT_BINARY_DIR}/cpp/make_${TYPE_TRAIT}${SUFFIX}.inl
	)
	if(EXISTS ${HAS_TRAIT_IN})

		configure_file("${HAS_TRAIT_IN}" "${HAS_TRAIT_SRC}")
		configure_file("${MAKE_TRAIT_IN}" "${MAKE_TRAIT_SRC}")
		try_compile(
			HAS_TRAIT
			${PROJECT_BINARY_DIR}/cpp
			${HAS_TRAIT_SRC}
			COMPILE_DEFINITIONS ${CPP_STD_COMPILER_SWITCH}
		)

		if(NOT ${HAS_TRAIT})
			configure_file("${MAKE_TRAIT_IN}" "${MAKE_TRAIT_SRC}")
			file(READ ${MAKE_TRAIT_SRC} CONTENTS)
			file(APPEND ${FIXES_HPP} "${CONTENTS}")

			try_compile(
				HAS_TRAIT
				${PROJECT_BINARY_DIR}/cpp
				${HAS_TRAIT_SRC}
				COMPILE_DEFINITIONS ${CPP_STD_COMPILER_SWITCH}
				"-DEAGINE_TEST_TRAIT_FIX=1"
			)
			if(NOT ${HAS_TRAIT})
				message(
					FATAL_ERROR
					"Failed to fix std::${TYPE_TRAIT}${SUFFIX}"
				)
			endif()
		endif()
	endif()
endfunction()

function(fix_std_type_trait TEMPLATE TYPE_TRAIT SUFFIX FIXES_HPP)
	if(EXISTS ${PROJECT_SOURCE_DIR}/config/cpp/has_${TYPE_TRAIT}${SUFFIX}.cpp.in)
		set(TPL_HAS "${TYPE_TRAIT}")
	else()
		set(TPL_HAS "${TEMPLATE}")
	endif()

	if(EXISTS ${PROJECT_SOURCE_DIR}/config/cpp/make_${TYPE_TRAIT}${SUFFIX}.cpp.in)
		set(TPL_MAKE "${TYPE_TRAIT}")
	else()
		set(TPL_MAKE "${TEMPLATE}")
	endif()

	do_fix_std_type_trait(
		"${TPL_HAS}" "${TPL_MAKE}"
		"${TYPE_TRAIT}" "${SUFFIX}"
		"${FIXES_HPP}"
	)
endfunction()

function(fix_unary_type_std_type_trait TYPE_TRAIT FIXES_HPP)
	fix_std_type_trait(TYPE_TRAIT1 "${TYPE_TRAIT}" "_t" "${FIXES_HPP}")
endfunction()

function(fix_unary_value_std_type_trait TYPE_TRAIT FIXES_HPP)
	fix_std_type_trait(TYPE_TRAIT1 "${TYPE_TRAIT}" "_v" "${FIXES_HPP}")
endfunction()

function(fix_binary_type_std_type_trait TYPE_TRAIT FIXES_HPP)
	fix_std_type_trait(TYPE_TRAIT2 "${TYPE_TRAIT}" "_t" "${FIXES_HPP}")
endfunction()

function(fix_binary_value_std_type_trait TYPE_TRAIT FIXES_HPP)
	fix_std_type_trait(TYPE_TRAIT2 "${TYPE_TRAIT}" "_v" "${FIXES_HPP}")
endfunction()

function(fix_other_std_type_trait TYPE_TRAIT FIXES_HPP)
	fix_std_type_trait("${TYPE_TRAIT}" "${TYPE_TRAIT}" "_t" "${FIXES_HPP}")
	fix_std_type_trait("${TYPE_TRAIT}" "${TYPE_TRAIT}" "_v" "${FIXES_HPP}")
endfunction()

function(make_std_type_traits_fixes)
	message(STATUS "Generating fixes for std type_traits")

	set(HEADER type_traits)
	set(FIXES_HPP ${PROJECT_BINARY_DIR}/include/eagine/stdfix/${HEADER}.hpp)
	configure_file(
		${PROJECT_SOURCE_DIR}/config/cpp/${HEADER}_fix.hpp.in
		${FIXES_HPP}
	)

	fix_other_std_type_trait(aligned_storage "${FIXES_HPP}")
	fix_other_std_type_trait(conditional "${FIXES_HPP}")
	fix_other_std_type_trait(enable_if "${FIXES_HPP}")

	fix_binary_value_std_type_trait(is_same "${FIXES_HPP}")
	fix_binary_value_std_type_trait(is_base_of "${FIXES_HPP}")
	fix_binary_value_std_type_trait(is_convertible "${FIXES_HPP}")

	fix_unary_value_std_type_trait(is_const "${FIXES_HPP}")
	fix_unary_value_std_type_trait(is_signed "${FIXES_HPP}")
	fix_unary_value_std_type_trait(is_integral "${FIXES_HPP}")
	fix_unary_value_std_type_trait(is_floating_point "${FIXES_HPP}")
	fix_unary_value_std_type_trait(is_arithmetic "${FIXES_HPP}")
	fix_unary_value_std_type_trait(is_array "${FIXES_HPP}")
	fix_unary_value_std_type_trait(is_polymorphic "${FIXES_HPP}")

	fix_unary_type_std_type_trait(decay "${FIXES_HPP}")
	fix_unary_type_std_type_trait(add_const "${FIXES_HPP}")
	fix_unary_type_std_type_trait(remove_const "${FIXES_HPP}")
	fix_unary_type_std_type_trait(add_pointer "${FIXES_HPP}")
	fix_unary_type_std_type_trait(remove_reference "${FIXES_HPP}")
	fix_unary_type_std_type_trait(remove_cv "${FIXES_HPP}")
	fix_unary_type_std_type_trait(add_lvalue_reference "${FIXES_HPP}")
	fix_unary_type_std_type_trait(remove_all_extents "${FIXES_HPP}")
	fix_unary_type_std_type_trait(result_of "${FIXES_HPP}")
	fix_unary_type_std_type_trait(underlying_type "${FIXES_HPP}")

	file(APPEND ${FIXES_HPP} "} // namespace std\n")
	file(APPEND ${FIXES_HPP} "#endif\n")
endfunction()

make_std_type_traits_fixes()

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
		COMPILE_DEFINITIONS ${CPP_STD_COMPILER_SWITCH}
	)

	if(${HAS_FEATURE})
		configure_file("${FEATURE_STD_IN}" "${FEATURE_HPP}")
	else()
		configure_file("${FEATURE_FIX_IN}" "${FEATURE_HPP}")
	endif()

	try_compile(
		HAS_FEATURE
		${PROJECT_BINARY_DIR}/cpp
		${HAS_FEATURE_SRC}
		COMPILE_DEFINITIONS "${CPP_STD_COMPILER_SWITCH}"
		"-DEAGINE_TEST_STD_FEATURE_FIX=1"
		CMAKE_FLAGS
		"-DINCLUDE_DIRECTORIES:STRING=${PROJECT_BINARY_DIR}/include "
	)
	if(NOT ${HAS_FEATURE})
		message(FATAL_ERROR "Failed to fix std ${FEATURE}")
	endif()
endfunction()

make_missing_std_feature_fix("optional" optional)
make_missing_std_feature_fix("integer sequence" int_sequence)
make_missing_std_feature_fix("boolean constant ops" bool_const_ops)
