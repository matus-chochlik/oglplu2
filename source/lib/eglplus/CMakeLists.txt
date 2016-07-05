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
	set_property(TARGET eglplus PROPERTY FOLDER "Library/EGLplus")

	target_link_libraries(eglplus eagine)
endif()
