# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#

add_executable(application-007_cube main.cpp)
eagine_embed_target_resources(application-007_cube vertex.glsl fragment.glsl)
eagine_add_exe_analysis(application-007_cube)

add_dependencies(application-007_cube application-examples)

target_link_libraries(
	application-007_cube
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-007_cube
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-007_cube
	DESTINATION share/oglplus/examples
)
