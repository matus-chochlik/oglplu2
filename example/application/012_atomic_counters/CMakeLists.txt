# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#

add_executable(application-012_atomic_counters main.cpp)
eagine_embed_packed_target_resources(
	application-012_atomic_counters
	vertex.glsl
	geometry.glsl
	fragment.glsl
)
eagine_add_exe_analysis(application-012_atomic_counters)

add_dependencies(application-012_atomic_counters application-examples)

target_link_libraries(
	application-012_atomic_counters
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-012_atomic_counters
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-012_atomic_counters
	DESTINATION share/oglplus/examples
)
