#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
option(USE_RYML "Use the ryml library" Off)

add_library(EAGopt::RYML INTERFACE IMPORTED)

if(USE_RYML)
	add_subdirectory(${PROJECT_SOURCE_DIR}/third_party/rapidyaml ryml)

	set_target_properties(
		EAGopt::RYML PROPERTIES
		INTERFACE_LINK_LIBRARIES ryml
	)

	set_target_properties(
		EAGopt::RYML PROPERTIES
		INTERFACE_COMPILE_DEFINITIONS EAGINE_USE_RYML=1
	)
else()
	set_target_properties(
		EAGopt::RYML PROPERTIES
		INTERFACE_COMPILE_DEFINITIONS EAGINE_USE_RYML=0
	)
endif()

