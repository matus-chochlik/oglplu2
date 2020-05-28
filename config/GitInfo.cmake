#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
find_program(GIT_COMMAND git)

if(GIT_COMMAND)
	set(EAGINE_HAS_GIT_INFO 1)
	execute_process(
		COMMAND ${GIT_COMMAND} "rev-parse" "HEAD"
		WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
		OUTPUT_VARIABLE EAGINE_GIT_HASH_ID
		OUTPUT_STRIP_TRAILING_WHITESPACE
	)
	execute_process(
		COMMAND ${GIT_COMMAND} "rev-parse" "--abbrev-ref" "HEAD"
		WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
		OUTPUT_VARIABLE EAGINE_GIT_BRANCH
		OUTPUT_STRIP_TRAILING_WHITESPACE
	)
else()
	set(EAGINE_HAS_GIT_INFO 0)
endif()

configure_file(
	${PROJECT_SOURCE_DIR}/config/eagine/config/git_info.hpp.in
	${PROJECT_BINARY_DIR}/include/eagine/config/git_info.hpp
	@ONLY
)

