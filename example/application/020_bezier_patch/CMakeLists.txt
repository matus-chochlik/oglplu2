# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
oglplus_add_glsl_program(bezier_patch)
add_executable(application-020_bezier_patch main.cpp resources.cpp)
eagine_embed_packed_target_resources(
	application-020_bezier_patch
	bezier_patch.oglpprog
)
eagine_add_exe_analysis(application-020_bezier_patch)

add_dependencies(application-020_bezier_patch application-examples)

target_link_libraries(
	application-020_bezier_patch
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-020_bezier_patch
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-020_bezier_patch
	DESTINATION share/oglplus/examples
)
