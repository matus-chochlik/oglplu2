# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

# generated files
configure_file(resources.cpp.in resources.cpp @ONLY)
set_source_files_properties(
	resources.cpp PROPERTIES
	GENERATED 1
)

# common private library
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_library(
	eagine-tools-common
	STATIC
	resources.cpp
)
set_target_properties(
	eagine-tools-common PROPERTIES
	INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}
)
eagine_embed_target_resources(eagine-tools-common)

add_subdirectory(bake_noise_image)
add_subdirectory(bake_checker_image)
add_subdirectory(bake_png_image)
add_subdirectory(bake_shader_source)
add_subdirectory(bake_program_source)
add_subdirectory(message_bus)
add_subdirectory(texgen)
