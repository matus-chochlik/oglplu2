# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#

configure_file(Doxyfile-common.in Doxyfile-common @ONLY)
configure_file(Doxyfile-html.in Doxyfile-html @ONLY)

add_custom_command(
	OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/doxygen/index.html"
	COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile-html
	WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
	MAIN_DEPENDENCY "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile-html"
	DEPENDS
		"${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile-html.in"
		"${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile-html"
		"${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile-common.in"
		"${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile-common"
	COMMENT "Generating Doxygen HTML documentation"
)

add_custom_target(
	doc-doxygen-html
	DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/doxygen/index.html"
)

set_target_properties(
	doc-doxygen-html
	PROPERTIES FOLDER "Documentation"
)

install(
	DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/doxygen
	DESTINATION share/oglplus/doc
	USE_SOURCE_PERMISSIONS
	COMPONENT doc-doxygen-html
	EXCLUDE_FROM_ALL
)

add_custom_command(
	OUTPUT "${CMAKE_INSTALL_PREFIX}/share/oglplus/doc/doxygen/index.html"
	COMMAND ${CMAKE_COMMAND}
	ARGS -DCOMPONENT=doc-doxygen-html -P cmake_install.cmake
	WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
	MAIN_DEPENDENCY "${CMAKE_CURRENT_BINARY_DIR}/doxygen/index.html"
	DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/doxygen/index.html"
)

add_custom_target(
	install-doc-doxygen-html
	DEPENDS "${CMAKE_INSTALL_PREFIX}/share/oglplus/doc/doxygen/index.html"
)

