# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

add_library(
	oglplus
	EXCLUDE_FROM_ALL
	gl.cpp
)
eagine_add_lib_analysis(oglplus)
set_target_properties(
	oglplus
	PROPERTIES FOLDER "Library/OGLplus"
)
set_target_properties(
	oglplus PROPERTIES
	INTERFACE_COMPILE_DEFINITIONS OGLPLUS_LINK_LIB=1
)
target_link_libraries(
	oglplus
	PUBLIC eagine
)
