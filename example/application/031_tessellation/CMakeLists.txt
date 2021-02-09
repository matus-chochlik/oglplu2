# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
oglplus_add_glsl_program(tessellation_prog)
add_executable(application-031_tessellation main.cpp resources.cpp)
eagine_embed_packed_target_resources(
	application-031_tessellation
	tessellation_prog
)
eagine_add_exe_analysis(application-031_tessellation)

add_dependencies(application-031_tessellation application-examples)

target_link_libraries(
	application-031_tessellation
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-031_tessellation
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-031_tessellation
	DESTINATION share/oglplus/examples
)
