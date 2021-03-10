# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
add_subdirectory(logo)

find_package(Doxygen)
if(Doxygen_FOUND)
	add_subdirectory(doxygen)

	find_program(
		SPHINX_EXECUTABLE
		NAMES sphinx-build
		DOC "Path to sphinx-build executable"
	)
	if(SPHINX_EXECUTABLE)
		add_subdirectory(sphinx)
	endif()
endif()

