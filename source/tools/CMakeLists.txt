# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

add_executable(bake_noise_image bake_noise_image.cpp)
add_executable(bake_checker_image bake_checker_image.cpp)

if(TARGET PNG::PNG)
	add_executable(bake_png_image bake_png_image.cpp)
	target_link_libraries(
		bake_png_image
		PUBLIC PNG::PNG
	)
endif()

add_executable(bake_shader_source bake_shader_source.cpp)
add_executable(bake_program_source bake_program_source.cpp)

# clang-tidy
if(INVOKE_CLANG_TIDY)
	set(EAGINE_TOOL_EXECUTABLES
		bake_noise_image
		bake_checker_image 
		bake_shader_source 
		bake_program_source 
	)
	if(TARGET bake_png_image)
		list(APPEND EAGINE_TOOL_EXECUTABLES bake_png_image)
	endif()

	foreach(TOOL ${EAGINE_TOOL_EXECUTABLES})
		set_target_properties(
			${TOOL}
			PROPERTIES CXX_CLANG_TIDY "${INVOKE_CLANG_TIDY}"
		)
	endforeach()
endif()

add_subdirectory(texgen)
