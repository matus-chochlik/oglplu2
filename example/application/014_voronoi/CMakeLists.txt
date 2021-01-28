# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#

add_executable(application-014_voronoi main.cpp resources.cpp)
eagine_embed_target_resources(application-014_voronoi vertex.glsl fragment.glsl)
eagine_add_exe_analysis(application-014_voronoi)

add_dependencies(application-014_voronoi application-examples)

target_link_libraries(
	application-014_voronoi
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-014_voronoi
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-014_voronoi
	DESTINATION share/oglplus/examples
)
