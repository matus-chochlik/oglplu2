# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

add_executable(bake_noise_image bake_noise_image.cpp)
eagine_add_exe_analysis(bake_noise_image)
target_link_libraries(
	bake_noise_image
	PUBLIC eagine
)

add_executable(bake_checker_image bake_checker_image.cpp)
eagine_add_exe_analysis(bake_checker_image)
target_link_libraries(
	bake_checker_image
	PUBLIC eagine
)

if(TARGET PNG::PNG)
	add_executable(bake_png_image bake_png_image.cpp)
	eagine_add_exe_analysis(bake_png_image )
	target_link_libraries(
		bake_png_image
		PUBLIC
			eagine
			PNG::PNG
	)
endif()

add_executable(bake_shader_source bake_shader_source.cpp)
eagine_add_exe_analysis(bake_shader_source)

add_executable(bake_program_source bake_program_source.cpp)
eagine_add_exe_analysis(bake_program_source)

add_subdirectory(texgen)
