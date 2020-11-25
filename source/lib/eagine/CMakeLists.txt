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

set(EAGINE_LIB_SOURCES
	main_wrap.cpp
	debug.cpp
	git_info.cpp
	identifier.cpp
	from_string.cpp
	logging.cpp
	ecs.cpp
	file_contents.cpp
	input_data.cpp
	compression.cpp
	str_var_subst.cpp
	message_bus_context.cpp
	message_bus_message.cpp
	message_bus_setup.cpp
	message_bus_blobs.cpp
	message_bus_endpoint.cpp
	message_bus_registry.cpp
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
	value_tree_filesystem.cpp
	value_tree_wrappers.cpp
	watchdog.cpp
)

add_library(
	eagine EXCLUDE_FROM_ALL
	${EAGINE_LIB_SOURCES}
)
eagine_add_lib_analysis(eagine)

target_compile_definitions(
	eagine PUBLIC EAGINE_LINK_LIBRARY=1
)

target_include_directories(
	eagine PUBLIC
	"$<INSTALL_INTERFACE:include>"
	"$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>"
	"$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
	"$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/implement>"
	"$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/third_party/include>"
	"$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/third_party/asio/asio/include>"
	"$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/third_party/rapidjson/include>"
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
)

eagine_embed_target_resources(eagine)

target_link_libraries(
	eagine
	PUBLIC
		EAGine::Required
		EAGopt::OpenSSL
		EAGopt::Stacktrace
		Threads::Threads
	PRIVATE
		EAGopt::ZLIB
		EAGopt::BoostSpirit
		SYSTEMD::SYSTEMD
)

if(TARGET ryml)
	target_link_libraries(eagine PUBLIC ryml)
	target_compile_definitions(eagine PRIVATE EAGINE_USE_RYML=1)
else()
	target_compile_definitions(eagine PRIVATE EAGINE_USE_RYML=0)
endif()

set_target_properties(
	eagine PROPERTIES
	VERSION ${OGLPLUS_VERSION}
	FOLDER "Library/EAGine"
)

