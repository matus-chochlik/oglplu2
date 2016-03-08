# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

add_executable(bake_noise_image bake_noise_image.cpp)
add_executable(bake_checker_image bake_checker_image.cpp)

if(PNG_FOUND)
	do_use_single_dependency(bake_png_image PNG)
	add_executable(bake_png_image bake_png_image.cpp)
	target_link_libraries(bake_png_image ${PNG_LIBRARIES})
endif()

add_executable(bake_shader_source bake_shader_source.cpp)
add_executable(bake_program_source bake_program_source.cpp)
