# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

option(USE_RYML "Use the RapidYAML library." On)
if(${USE_RYML})
	add_subdirectory(rapidyaml ryml)
endif()

