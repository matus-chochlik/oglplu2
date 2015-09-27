# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

cmake_minimum_required(VERSION 2.8)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_DEBUG_POSTFIX d)

project(OGLplus)

include(config/Compiler.cmake)
include(config/CppFeature.cmake)

include_directories("include")
include_directories("implement")
include_directories("third_party/GSL/include")

add_subdirectory("test")
