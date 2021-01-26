# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#

# add a target for the examples
add_custom_target(application-examples ALL)
set_target_properties(
	application-examples
	PROPERTIES FOLDER "Example/Application"
)

add_subdirectory(001_clear)
add_subdirectory(002_spectrum)
add_subdirectory(003_checker)
add_subdirectory(004_triangle)
add_subdirectory(010_newton)
