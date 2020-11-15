# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

if(EGL_FOUND)
	add_library(
		eglplus EXCLUDE_FROM_ALL
		_dummy.cpp
	)
	eagine_add_lib_analysis(eglplus)

	target_compile_definitions(
		eglplus PUBLIC EGLPLUS_LINK_LIBRARY=1
	)

	target_include_directories(
		eglplus PUBLIC
		"$<INSTALL_INTERFACE:include>"
		"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
	)

	target_link_libraries(
		eglplus
		PUBLIC eagine
	)

	set_target_properties(
		eglplus PROPERTIES
		VERSION ${OGLPLUS_VERSION}
		FOLDER "Library/EGLplus"
	)
else()
	add_library(eglplus INTERFACE IMPORTED)
endif()
