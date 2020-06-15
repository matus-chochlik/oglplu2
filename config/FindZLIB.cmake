#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
find_package(ZLIB)

add_library(EAGopt::ZLIB INTERFACE IMPORTED)
if(ZLIB_FOUND)
	if(ZLIB_INCLUDE_DIRS)
		set_target_properties(
			EAGopt::ZLIB PROPERTIES
			INTERFACE_INCLUDE_DIRECTORIES "${ZLIB_INCLUDE_DIRS}"
		)
	endif()

	if(ZLIB_LIBRARY_DIRS)
		set_target_properties(
			EAGopt::ZLIB PROPERTIES
			INTERFACE_LINK_DIRECTORIES "${ZLIB_LIBRARY_DIRS}"
		)
	endif()

	set_target_properties(
		EAGopt::ZLIB PROPERTIES
		INTERFACE_COMPILE_DEFINITIONS EAGINE_USE_ZLIB=1
	)

	set_target_properties(
		EAGopt::ZLIB PROPERTIES
		INTERFACE_LINK_LIBRARIES "${ZLIB_LIBRARIES}"
	)
endif()


