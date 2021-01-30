# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
configure_file(
	"${PROJECT_SOURCE_DIR}/assets/models/traffic_cone.json"
	"${CMAKE_CURRENT_BINARY_DIR}/traffic_cone.json"
)

add_executable(application-017_occlusion main.cpp)
eagine_embed_packed_target_resources(
	application-017_occlusion
	vertex.glsl fragment.glsl
	traffic_cone.json
)
eagine_add_exe_analysis(application-017_occlusion)

add_dependencies(application-017_occlusion application-examples)

target_link_libraries(
	application-017_occlusion
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-017_occlusion
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-017_occlusion
	DESTINATION share/oglplus/examples
)
