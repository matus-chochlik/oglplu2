#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
find_package(X11)

if(X11_FOUND)
	set(GLX_FOUND 1)

	add_library(GLX::GLX INTERFACE IMPORTED)
	set_target_properties(
		GLX::GLX PROPERTIES
		INTERFACE_INCLUDE_DIRECTORIES "${X11_INCLUDE_DIR}"
	)
	set_target_properties(
		GLX::GLX PROPERTIES
		INTERFACE_LINK_LIBRARIES "${X11_LIBRARIES}"
	)
else()
	set(GLX_FOUND 0)
endif()
