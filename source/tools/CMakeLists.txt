# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

add_executable(noise_image noise_image.cpp)
add_executable(checker_image checker_image.cpp)

if(PNG_FOUND)
	do_use_single_dependency(png_image PNG)
	add_executable(png_image png_image.cpp)
	target_link_libraries(png_image ${PNG_LIBRARIES})
endif()
