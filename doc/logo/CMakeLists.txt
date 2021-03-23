# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#

install(
	FILES oglplus_circular.png
	DESTINATION share/oglplus/doc
	COMPONENT doc-logos
	EXCLUDE_FROM_ALL
)

add_custom_command(
	OUTPUT "${CMAKE_INSTALL_PREFIX}/share/oglplus/doc/oglplus_circular.png"
	COMMAND ${CMAKE_COMMAND}
	ARGS -DCOMPONENT=doc-logos -P cmake_install.cmake
	WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
	MAIN_DEPENDENCY "${CMAKE_CURRENT_SOURCE_DIR}/oglplus_circular.png"
	DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/oglplus_circular.png"
)

add_custom_target(
	install-doc-logos
	DEPENDS "${CMAKE_INSTALL_PREFIX}/share/oglplus/doc/oglplus_circular.png"
)

add_dependencies(
	install-doc
	install-doc-logos
)

