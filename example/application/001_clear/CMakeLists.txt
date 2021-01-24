# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#

add_executable(application-001_clear main.cpp)
eagine_add_exe_analysis(application-001_clear)

add_dependencies(application-001_clear application-examples)

target_link_libraries(
	application-001_clear
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-001_clear
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-001_clear
	DESTINATION share/oglplus/examples
)
