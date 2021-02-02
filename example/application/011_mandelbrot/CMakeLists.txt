# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#

add_executable(application-011_mandelbrot main.cpp)
eagine_embed_target_resources(application-011_mandelbrot vertex.glsl fragment.glsl)
eagine_add_exe_analysis(application-011_mandelbrot)

add_dependencies(application-011_mandelbrot application-examples)

target_link_libraries(
	application-011_mandelbrot
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-011_mandelbrot
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-011_mandelbrot
	DESTINATION share/oglplus/examples
)
