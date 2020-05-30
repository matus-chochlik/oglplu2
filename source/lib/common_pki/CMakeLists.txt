# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

# generated files
configure_file(lib_common_pki.cpp.in lib_common_pki.cpp @ONLY)
set_source_files_properties(
	lib_common_pki.cpp PROPERTIES
	GENERATED 1
)

# common private library
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_library(
	eagine-common-pki
	STATIC
	lib_common_pki.cpp
)
set_target_properties(
	eagine-common-pki PROPERTIES
	INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}
)
eagine_embed_target_resources(eagine-common-pki)

