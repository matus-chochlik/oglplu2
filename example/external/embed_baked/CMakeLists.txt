# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 3.10)
project(oglplus_embed_baked)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)

find_package(OGLplus REQUIRED)

oglplus_add_texture(noise_16x16x3)

add_executable(embed_baked main.cpp)
target_link_libraries(embed_baked PRIVATE OGLplus::eagine)
eagine_embed_packed_target_resources(embed_baked noise_16x16x3)
