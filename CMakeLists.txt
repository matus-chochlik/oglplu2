# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

cmake_minimum_required(VERSION 2.8)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_DEBUG_POSTFIX d)

project(OGLplus)

file(READ VERSION OGLPLUS_VERSION)

set(HEADER_SEARCH_PATHS ${HEADER_SEARCH_PATHS};${PROJECT_SOURCE_DIR}/third_party/include)

include(config/Compiler.cmake)
include(config/CppFeature.cmake)

include(FindPkgConfig)
include(config/CommonFindMod.cmake)

# GL-libraries
include(config/FindGL.cmake)
include(config/FindGLEW.cmake)
include(config/FindGLFW.cmake)

# setting up executable requirements
include(config/ExeRequirements.cmake)

include_directories("include")
include_directories("implement")
include_directories("third_party/GSL/include")

add_subdirectory("example")
add_subdirectory("test")
