# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

set(EAGINE_LIB_SOURCES
	main_wrap.cpp
	debug.cpp
	logging.cpp
	filesystem.cpp
	file_contents.cpp
	input_data.cpp
	str_var_subst.cpp
	message_bus_endpoint.cpp
	message_bus_router.cpp
	message_bus_setup.cpp
	shapes_base.cpp
	shapes_cube.cpp
	shapes_torus.cpp
	shapes_sphere.cpp
	shapes_icosahedron.cpp
	shapes_modifiers.cpp
	shapes_to_quads.cpp
	random.cpp
)

add_library(
	eagine EXCLUDE_FROM_ALL
	${EAGINE_LIB_SOURCES}
)
eagine_add_lib_analysis(eagine)

target_link_libraries(
	eagine
	PUBLIC
		EAGine::Required
		Threads::Threads
)

set_target_properties(
	eagine PROPERTIES
	INTERFACE_COMPILE_DEFINITIONS EAGINE_LINK_LIB=1
)

set_target_properties(
	eagine PROPERTIES
	FOLDER "Library/EAGine"
)
