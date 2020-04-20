# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

add_executable(message_bus-router router.cpp)
target_compile_definitions(
	message_bus-router
	PRIVATE "-DEAGINE_LINK_LIBRARY=1"
)
target_link_libraries(
	message_bus-router
	PUBLIC eagine
)
