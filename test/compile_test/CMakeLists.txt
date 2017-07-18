#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 3.5)

enable_testing()
add_subdirectory("oglplus")

if(OPENAL_FOUND)
	add_subdirectory("oalplus")
endif()
