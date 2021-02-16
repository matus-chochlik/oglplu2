# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
find_package(Doxygen)

add_subdirectory(logo)

if(Doxygen_FOUND)
	add_subdirectory(doxygen)
endif()
