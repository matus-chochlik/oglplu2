# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

if(OPENAL_FOUND)
	include_directories(${OPENAL_INCLUDE_DIRS})
	set(OALPLUS_LIB_SOURCES
		enum_value_names.cpp
		enum_value_range.cpp
	)

	add_library(oalplus EXCLUDE_FROM_ALL ${OALPLUS_LIB_SOURCES})
	set_target_properties(
		oalplus
		PROPERTIES FOLDER "Library/OALplus"
	)
	if(INVOKE_CLANG_TIDY)
		set_target_properties(
			oalplus
			PROPERTIES CXX_CLANG_TIDY "${INVOKE_CLANG_TIDY}"
		)
	endif()

	target_link_libraries(oalplus eagine)
endif()
