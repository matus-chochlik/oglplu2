#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#

if(WITH_CLANG_TIDY)
	find_program(
		CLANG_TIDY_PROG
		NAMES clang-tidy-7 clang-tidy
		DOC "Path to clang-tidy executable"
	)

	if(CLANG_TIDY_PROG)
		set(INVOKE_CLANG_TIDY "${CLANG_TIDY_PROG}")
	endif()
endif()

macro(eagine_add_exe_analysis TARGETNAME)
	if(INVOKE_CLANG_TIDY)
		set_target_properties(
			${TARGETNAME}
			PROPERTIES CXX_CLANG_TIDY "${INVOKE_CLANG_TIDY}"
		)
	endif()
endmacro()

macro(eagine_add_lib_analysis TARGETNAME)
	eagine_add_exe_analysis(${TARGETNAME})
endmacro()

