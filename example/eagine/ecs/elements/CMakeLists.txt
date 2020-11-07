# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
add_library(
	eagine-ecs-elements-common
	EXCLUDE_FROM_ALL
	init.cpp
)
eagine_add_lib_analysis(eagine-ecs-elements-common)
eagine_embed_packed_target_resources(eagine-ecs-elements-common)

macro(eagine_ecs_example EXAMPLE)
	add_executable(
		eagine-ecs-elements-${EXAMPLE}
		EXCLUDE_FROM_ALL
		main_${EXAMPLE}.cpp
	)
	eagine_add_exe_analysis(eagine-ecs-elements-${EXAMPLE})
	add_dependencies(eagine-examples eagine-ecs-elements-${EXAMPLE})
	target_link_libraries(
		eagine-ecs-elements-${EXAMPLE}
		PUBLIC eagine
		PRIVATE eagine-ecs-elements-common
	)

	set_target_properties(
		eagine-ecs-elements-${EXAMPLE}
		PROPERTIES FOLDER "Example/EAGine/ECS"
	)
	eagine_install_example(eagine-ecs-elements-${EXAMPLE})
endmacro()

eagine_ecs_example(basic)

