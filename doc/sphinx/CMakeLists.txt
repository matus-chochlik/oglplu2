# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#

configure_file(conf.py.in conf.py @ONLY)

file(
	GLOB_RECURSE DOC_INPUT_SOURCES
	LIST_DIRECTORIES FALSE
	${CMAKE_CURRENT_SOURCE_DIR}/conf.py
	${CMAKE_CURRENT_SOURCE_DIR}/*.rst
)

add_custom_command(
	OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/sphinx/index.html"
	COMMAND ${SPHINX_EXECUTABLE}
	ARGS
		-c ${CMAKE_CURRENT_BINARY_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_BINARY_DIR}/sphinx
	WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
	DEPENDS ${DOC_INPUT_SOURCES} doc-doxygen-xml
	COMMENT "Generating Sphinx HTML documentation"
)

add_custom_target(
	doc-sphinx-html
	DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/sphinx/index.html"
)

set_target_properties(
	doc-sphinx-html
	PROPERTIES FOLDER "Documentation"
)

install(
	DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/sphinx
	DESTINATION share/oglplus/doc
	USE_SOURCE_PERMISSIONS
	COMPONENT doc-sphinx-html
	EXCLUDE_FROM_ALL
)

add_custom_command(
	OUTPUT "${CMAKE_INSTALL_PREFIX}/share/oglplus/doc/sphinx/sphinx/index.html"
	COMMAND ${CMAKE_COMMAND}
	ARGS -DCOMPONENT=doc-sphinx-html -P cmake_install.cmake
	WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
	MAIN_DEPENDENCY "${CMAKE_CURRENT_BINARY_DIR}/sphinx/index.html"
	DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/sphinx/index.html"
)

add_custom_target(
	install-doc-sphinx-html
	DEPENDS "${CMAKE_INSTALL_PREFIX}/share/oglplus/doc/sphinx/sphinx/index.html"
)

add_dependencies(
	install-doc
	install-doc-sphinx-html
)

