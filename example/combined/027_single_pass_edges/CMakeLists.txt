# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
oglplus_add_glsl_program(single_pass_edges_prog)
eagine_add_directory_example(example.cpp resources.cpp)
eagine_pack_directory_resources(single_pass_edges_prog)

