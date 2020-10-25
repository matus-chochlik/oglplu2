# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
add_executable(
	eagine-ecs-elements
	EXCLUDE_FROM_ALL
	main.cpp
	init.cpp
)
eagine_add_exe_analysis(eagine-ecs-elements)
add_dependencies(eagine-examples eagine-ecs-elements)
target_link_libraries(
	eagine-ecs-elements
	PUBLIC eagine
)

set_target_properties(
	eagine-ecs-elements
	PROPERTIES FOLDER "Example/EAGine/ECS"
)
eagine_install_example(eagine-ecs-elements)
eagine_embed_packed_target_resources(eagine-ecs-elements)


