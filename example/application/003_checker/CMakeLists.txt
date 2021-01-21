# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#

add_executable(application-003_checker main.cpp)
eagine_embed_target_resources(application-003_checker fragment.glsl)
eagine_add_exe_analysis(application-003_checker)

add_dependencies(application-003_checker application-examples)

target_link_libraries(
	application-003_checker
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-003_checker
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-003_checker
	DESTINATION share/oglplus/examples
)

install(
	FILES application-003_checker.yaml
	DESTINATION share/oglplus/user/.oglplus/config
)

