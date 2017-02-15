#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 2.8)

find_package(Boost COMPONENTS unit_test_framework)

if(Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIRS})
	enable_testing()
	add_subdirectory("eagine")
	add_subdirectory("oglplus")

	if(EGL_FOUND)
		add_subdirectory("eglplus")
	endif()

	if(OPENAL_FOUND)
		add_subdirectory("oalplus")
	endif()
else()
	message(WARNING "Boost.Test required for testing but not found")
endif()
