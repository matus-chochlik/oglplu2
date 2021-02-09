# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#

add_executable(application-015_worley main.cpp resources.cpp)
eagine_embed_target_resources(application-015_worley vertex.glsl fragment.glsl)
eagine_add_exe_analysis(application-015_worley)

add_dependencies(application-015_worley application-examples)

target_link_libraries(
	application-015_worley
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-015_worley
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-015_worley
	DESTINATION share/oglplus/examples
)
