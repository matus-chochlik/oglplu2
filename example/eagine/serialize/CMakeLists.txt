# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 3.10)

add_executable("serialize-basic" "basic.cpp")
target_link_libraries("serialize-basic" eagine)

add_executable("serialize-fragmented" "fragmented.cpp")
target_link_libraries("serialize-fragmented" eagine)
