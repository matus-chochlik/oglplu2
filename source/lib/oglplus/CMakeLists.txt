# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

set(OGLPLUS_LIB_SOURCES
	gl.cpp
	error.cpp
	objects.cpp
	shapes.cpp
	enum_value_names.cpp
	enum_value_range.cpp
	texgen_common.cpp
	texgen_nodes.cpp
	texgen_graph.cpp
)

add_library(oglplus EXCLUDE_FROM_ALL ${OGLPLUS_LIB_SOURCES})
set_target_properties(
	oglplus
	PROPERTIES FOLDER "Library/OGLplus"
)
if(CLANG_TIDY_PROG)
	set_target_properties(
		oglplus
		PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_PROG}"
	)
endif()

target_link_libraries(oglplus eagine)
target_link_libraries(oglplus ${OGLPLUS_GL_LIBRARIES})
