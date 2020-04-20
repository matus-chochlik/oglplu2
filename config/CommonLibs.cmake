#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
add_library(EAGine::Required INTERFACE IMPORTED)

if(UNIX AND NOT APPLE)
	add_library(Linux::RT INTERFACE IMPORTED)
	set_target_properties(
		Linux::RT PROPERTIES
		INTERFACE_LINK_LIBRARIES rt
	)

	set_target_properties(
		EAGine::Required PROPERTIES
		INTERFACE_LINK_LIBRARIES Linux::RT
	)

endif()
