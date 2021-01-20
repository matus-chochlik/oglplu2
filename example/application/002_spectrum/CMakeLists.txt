# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#

add_executable(application-002_spectrum main.cpp)
eagine_add_exe_analysis(application-002_spectrum)

add_dependencies(application-002_spectrum application-examples)

target_link_libraries(
	application-002_spectrum
	PUBLIC eagine eagine-application oglplus
)

set_target_properties(
	application-002_spectrum
	PROPERTIES FOLDER "Example/Application"
)

install(
	TARGETS application-002_spectrum
	DESTINATION share/oglplus/examples
)
