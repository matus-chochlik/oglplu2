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
set_property(TARGET oglplus PROPERTY FOLDER "Library/OGLplus")

target_link_libraries(oglplus eagine)
target_link_libraries(oglplus ${OGLPLUS_GL_LIBRARIES})
