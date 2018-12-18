# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

if(EGL_FOUND)
	include_directories(${EGL_INCLUDE_DIRS})
	set(EGLPLUS_LIB_SOURCES
		enum_value_names.cpp
		enum_value_range.cpp
	)

	add_library(eglplus EXCLUDE_FROM_ALL ${EGLPLUS_LIB_SOURCES})
	set_target_properties(
		eglplus
		PROPERTIES FOLDER "Library/EGLplus"
	)
	if(CLANG_TIDY_PROG)
		set_target_properties(
			eglplus
			PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_PROG}"
		)
	endif()

	target_link_libraries(eglplus eagine)
endif()
