# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

file(GLOB EAGINE_LIB_SOURCES *.cpp)

add_library(
	eagine EXCLUDE_FROM_ALL
	${EAGINE_LIB_SOURCES}
)

target_link_libraries(
	eagine
	PUBLIC
		EAGine::Required
		Threads::Threads
)

set_target_properties(
	eagine PROPERTIES
	INTERFACE_COMPILE_DEFINITIONS EAGINE_LINK_LIB=1
)

set_target_properties(
	eagine PROPERTIES
	FOLDER "Library/EAGine"
)

if(INVOKE_CLANG_TIDY)
	set_target_properties(
		eagine
		PROPERTIES CXX_CLANG_TIDY "${INVOKE_CLANG_TIDY}"
	)
endif()

