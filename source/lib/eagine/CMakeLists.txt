# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

# generated files
configure_file(resources.cpp.in resources.cpp @ONLY)
set_source_files_properties(
	resources.cpp PROPERTIES
	GENERATED 1
)

# common private library
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(EAGINE_LIB_SOURCES
	main_wrap.cpp
	debug.cpp
	git_info.cpp
	identifier.cpp
	from_string.cpp
	logging.cpp
	file_contents.cpp
	input_data.cpp
	compression.cpp
	str_var_subst.cpp
	message_bus_context.cpp
	message_bus_message.cpp
	message_bus_setup.cpp
	message_bus_blobs.cpp
	message_bus_endpoint.cpp
	message_bus_router.cpp
	message_bus_bridge.cpp
	shapes_base.cpp
	shapes_cube.cpp
	shapes_torus.cpp
	shapes_sphere.cpp
	shapes_icosahedron.cpp
	shapes_value_tree.cpp
	shapes_modifiers.cpp
	shapes_to_quads.cpp
	random.cpp
	resources.cpp
	value_tree_json.cpp
	value_tree_yaml.cpp
	value_tree_wrappers.cpp
)

add_library(
	eagine EXCLUDE_FROM_ALL
	${EAGINE_LIB_SOURCES}
)
eagine_add_lib_analysis(eagine)
eagine_embed_target_resources(eagine)

target_link_libraries(
	eagine
	PUBLIC
		EAGine::Required
		EAGopt::OpenSSL
		EAGopt::ZLIB
		EAGopt::RYML
		EAGopt::Stacktrace
		EAGopt::BoostSpirit
		Threads::Threads
)

set_target_properties(
	eagine PROPERTIES
	INTERFACE_COMPILE_DEFINITIONS EAGINE_LINK_LIBRARY=1
)
set_target_properties(
	eagine PROPERTIES
	INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(
	eagine PROPERTIES
	FOLDER "Library/EAGine"
)
