# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

if(OPENAL_FOUND)
	add_library(
		oalplus EXCLUDE_FROM_ALL
		_dummy.cpp
	)
	eagine_add_lib_analysis(oalplus)

	target_compile_definitions(
		oalplus PUBLIC OALPLUS_LINK_LIBRARY=1
	)

	target_include_directories(
		oalplus PUBLIC
		"$<INSTALL_INTERFACE:include>"
		"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
	)

	target_link_libraries(
		oalplus
		PUBLIC eagine
	)

	set_target_properties(
		oalplus PROPERTIES
		VERSION ${OGLPLUS_VERSION}
		FOLDER "Library/OALplus"
	)
else()
	add_library(oalplus INTERFACE IMPORTED)
endif()
