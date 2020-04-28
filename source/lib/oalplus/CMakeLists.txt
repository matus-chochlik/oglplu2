# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

if(OPENAL_FOUND)
	add_library(
		oalplus EXCLUDE_FROM_ALL
		enum_value_names.cpp
		enum_value_range.cpp
	)
	eagine_add_lib_analysis(oalplus)
	set_target_properties(
		oalplus
		PROPERTIES FOLDER "Library/OALplus"
	)
	set_target_properties(
		oalplus PROPERTIES
		INTERFACE_COMPILE_DEFINITIONS OALPLUS_LINK_LIB=1
	)
	target_link_libraries(
		oalplus
		PUBLIC eagine
	)
endif()
