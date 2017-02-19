#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 2.8)

enable_testing()

add_subdirectory(compile_test)
add_subdirectory(boost_test)

find_program(CTEST ctest)

if(CTEST)
	add_custom_target(
		check
		COMMAND ${CTEST}
		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
	)
endif()
