#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
include(ProcessorCount)
ProcessorCount(EAGINE_NUM_CORES)

if(EAGINE_NUM_CORES EQUAL 0)
	set(EAGINE_NUM_JOBS 2)
else()
	math(EXPR EAGINE_NUM_JOBS ${EAGINE_NUM_CORES}+1)
endif()
message(STATUS "Using ${EAGINE_NUM_JOBS} cores for some jobs")


