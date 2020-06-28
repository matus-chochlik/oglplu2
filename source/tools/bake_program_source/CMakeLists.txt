# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

add_executable(oglplus-bake_program_source main.cpp)
eagine_add_exe_analysis(oglplus-bake_program_source)
target_link_libraries(
	oglplus-bake_program_source
	PUBLIC eagine
)
eagine_instalL_tool(oglplus-bake_program_source)
