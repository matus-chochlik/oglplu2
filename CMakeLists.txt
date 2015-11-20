# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

cmake_minimum_required(VERSION 2.8)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_DEBUG_POSTFIX d)

project(OGLplus)

file(READ VERSION OGLPLUS_VERSION)

set(HEADER_SEARCH_PATHS
	${HEADER_SEARCH_PATHS};${PROJECT_SOURCE_DIR}/third_party/include
)

include(config/Compiler.cmake)
include(config/CppFeature.cmake)

include(FindPkgConfig)
include(config/CommonFindMod.cmake)

# GL-libraries
include(config/FindGL.cmake)
include(config/FindGLEW.cmake)
include(config/FindGL3W.cmake)

include(config/FindGLX.cmake)
include(config/FindGLFW.cmake)
include(config/FindGLFW3.cmake)
include(config/FindGLUT.cmake)
include(config/FindSDL.cmake)
include(config/FindWXGL.cmake)

include(config/FindGLM.cmake)

# EGL
include(config/FindEGL.cmake)

# OpenAL
include(config/FindAL.cmake)

# setting up executable requirements
include(config/ExeRequirements.cmake)

# configure GL API and Context-init libraries
include(config/ConfigGL.cmake)

# now create the site-configuration header
configure_file(
	${PROJECT_SOURCE_DIR}/config/oglplus/config/site.hpp.in
	${PROJECT_BINARY_DIR}/include/oglplus/config/site.hpp
)

include_directories("include")
include_directories("implement")
include_directories("third_party/include")
include_directories("third_party/GSL/include")

# common functions for GL version and extension detection
include(config/GLVerExt.cmake)
# GL version detection
include(config/GLVer.cmake)
# GL extension detection
include(config/GLExt.cmake)

# re-create the site-configuration header
configure_file(
	${PROJECT_SOURCE_DIR}/config/oglplus/config/site.hpp.in
	${PROJECT_BINARY_DIR}/include/oglplus/config/site.hpp
)

add_subdirectory("example")
add_subdirectory("test")

# install the headers
install(
	DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION include
)
# install the implementation inline files
install(
	DIRECTORY ${PROJECT_SOURCE_DIR}/implement/
	DESTINATION include
)
# install the GSL headers
install(
	DIRECTORY ${PROJECT_SOURCE_DIR}/third_party/GSL/include/
	DESTINATION include
)

