#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
# we need C++14
if(${CMAKE_COMPILER_IS_GNUCXX})
	add_definitions(-std=c++14)
	set(CPP_STD_COMPILER_SWITCH -std=c++14)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	set(CPP_STD_COMPILER_SWITCH -std=c++14)
endif()
# TODO add support for other compilers

add_definitions(${CPP_STD_COMPILER_SWITCH})

