# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#

add_executable(
	oglplus-ogl-clear
	EXCLUDE_FROM_ALL
	main.cpp
)
eagine_add_exe_analysis(oglplus-ogl-clear)
add_dependencies(oglplus-ogl-clear applications)
target_link_libraries(
	oglplus-ogl-clear
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	oglplus-ogl-clear
	PROPERTIES FOLDER "Application"
)

