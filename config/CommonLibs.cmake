#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
add_library(EAGine::Required INTERFACE IMPORTED)

if(UNIX AND NOT APPLE)
	add_library(EAGreq::RunTime INTERFACE IMPORTED)
	set_target_properties(
		EAGreq::RunTime PROPERTIES
		INTERFACE_LINK_LIBRARIES rt
	)

	add_library(EAGreq::DynLib INTERFACE IMPORTED)
	set_target_properties(
		EAGreq::DynLib PROPERTIES
		INTERFACE_LINK_LIBRARIES dl
	)

	set_target_properties(
		EAGine::Required PROPERTIES
		INTERFACE_LINK_LIBRARIES
		"EAGreq::RunTime;EAGreq::DynLib"
	)

endif()
