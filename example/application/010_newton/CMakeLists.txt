# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#

add_executable(application-010_newton main.cpp)
eagine_embed_target_resources(application-010_newton vertex.glsl fragment.glsl)
eagine_add_exe_analysis(application-010_newton)

add_dependencies(application-010_newton application-examples)

target_link_libraries(
	application-010_newton
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-010_newton
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-010_newton
	DESTINATION share/oglplus/examples
)
