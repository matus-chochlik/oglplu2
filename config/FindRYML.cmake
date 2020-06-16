#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
add_subdirectory(${PROJECT_SOURCE_DIR}/third_party/rapidyaml ryml)

add_library(EAGopt::RYML INTERFACE IMPORTED)

set_target_properties(
	EAGopt::RYML PROPERTIES
	INTERFACE_LINK_LIBRARIES ryml
)

