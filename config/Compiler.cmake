#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
# enable warnings on gcc
set(EAGINE_GNUCXX_COMPILER FALSE)
set(EAGINE_CLANGXX_COMPILER FALSE)
set(EAGINE_GXX_COMPILER FALSE)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	set(EAGINE_GNUCXX_COMPILER TRUE)
	set(EAGINE_CLANGXX_COMPILER TRUE)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	set(EAGINE_GNUCXX_COMPILER TRUE)
	set(EAGINE_GXX_COMPILER TRUE)
endif()

add_definitions(-D_USE_MATH_DEFINES)

