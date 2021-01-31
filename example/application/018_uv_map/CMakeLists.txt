# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
configure_file(
	"${PROJECT_SOURCE_DIR}/assets/models/crate_2.json"
	"${CMAKE_CURRENT_BINARY_DIR}/crate_2.json"
)

add_executable(application-018_uv_map main.cpp)
eagine_embed_packed_target_resources(
	application-018_uv_map
	vertex.glsl fragment.glsl
	crate_2.json
	crate_2_color
	crate_2_light
)
eagine_add_exe_analysis(application-018_uv_map)

add_dependencies(application-018_uv_map application-examples)

target_link_libraries(
	application-018_uv_map
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-018_uv_map
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-018_uv_map
	DESTINATION share/oglplus/examples
)
