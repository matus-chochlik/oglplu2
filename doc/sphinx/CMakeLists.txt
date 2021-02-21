# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#

file(
	GLOB_RECURSE DOC_INPUT_SOURCES
	LIST_DIRECTORIES FALSE
	${CMAKE_CURRENT_SOURCE_DIR}/*.rst
	${PROJECT_SOURCE_DIR}/include/*.hpp
	${PROJECT_SOURCE_DIR}/example/*.hpp
	${PROJECT_SOURCE_DIR}/example/*.cpp
)

add_custom_command(
	OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/sphinx/index.html"
	COMMAND ${SPHINX_EXECUTABLE}
	ARGS ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/sphinx
	WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
	DEPENDS ${DOC_INPUT_SOURCES}
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
