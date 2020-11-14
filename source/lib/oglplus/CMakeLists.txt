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

target_compile_definitions(
	oglplus PUBLIC OGLPLUS_LINK_LIBRARY=1
)

target_include_directories(
	oglplus PUBLIC
	"$<INSTALL_INTERFACE:include>"
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
)

target_link_libraries(
	oglplus
	PUBLIC
		eagine
		$<TARGET_NAME:GLEW::GLEW>
)
set_target_properties(
	oglplus
	PROPERTIES FOLDER "Library/OGLplus"
)

