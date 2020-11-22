# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
eagine_example_use_model(crate_2.json)
eagine_add_directory_example(example.cpp)
eagine_pack_directory_resources(
	vertex.glsl
	fragment.glsl
	crate_2.json
	crate_2_color
	crate_2_light
)

