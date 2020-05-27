#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#

add_library(EAGopt::Stacktrace INTERFACE IMPORTED)
set(EAGINE_USE_BACKTRACE 0)
set(EAGINE_USE_STACKTRACE 0)

if(${EAGINE_DEBUG})
    find_path(
        STACKTRACE_INCLUDE_DIRS
        boost/stacktrace/stacktrace.hpp
    )

    find_library(BACKTRACE_LIBRARY backtrace)

    find_library(
        STACKTRACE_BACKTRACE_LIBRARY
        boost_stacktrace_backtrace
    )

    if(
        STACKTRACE_BACKTRACE_LIBRARY AND
        EXISTS ${STACKTRACE_BACKTRACE_LIBRARY}
        AND BACKTRACE_LIBRARY
        AND EXISTS ${BACKTRACE_LIBRARY}
    )
		set(EAGINE_USE_STACKTRACE 1)
		set(EAGINE_USE_BACKTRACE 1)
		set(
			STACKTRACE_LIBRARIES
			${BACKTRACE_LIBRARY}
			${STACKTRACE_BACKTRACE_LIBRARY}
		)
	else()
        find_library(
            STACKTRACE_LIBRARIES
            boost_stacktrace_basic
        )
		if(STACKTRACE_LIBRARIES)
			set(EAGINE_USE_STACKTRACE 1)
		endif()
    endif()

	if(STACKTRACE_INCLUDE_DIRS)
		foreach(DIR ${STACKTRACE_INCLUDE_DIRS})
			if(EXISTS ${DIR})
				set_target_properties(
					EAGopt::Stacktrace 
					PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "${DIR}"
				)
			endif()
		endforeach()
	endif()

	if(STACKTRACE_LIBRARIES)
		message(STATUS "Found Stacktrace: ${STACKTRACE_LIBRARIES}")
		foreach(LIB ${STACKTRACE_LIBRARIES})
			set_target_properties(
				EAGopt::Stacktrace 
				PROPERTIES INTERFACE_LINK_LIBRARIES "${LIB}"
			)
		endforeach()
	endif()
endif()
