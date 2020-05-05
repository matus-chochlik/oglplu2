# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

if(TARGET PNG::PNG)
	add_executable(oglplus-bake_png_image main.cpp)
	eagine_add_exe_analysis(oglplus-bake_png_image )
	target_link_libraries(
		oglplus-bake_png_image
		PUBLIC
			eagine
			PNG::PNG
	)
	eagine_install_tool(oglplus-bake_png_image)
endif()

