#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
find_program(VALGRIND valgrind)

if(VALGRIND)
	enable_testing()
	add_subdirectory("eagine")
else()
	message(WARNING "Valgrind required for testing but not found")
endif()
