# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 3.10)

add_executable(message_bus-loopback "001_loopback.cpp")
target_link_libraries(
	message_bus-loopback
	PUBLIC eagine
)

add_executable(message_bus-direct "002_direct.cpp")
target_link_libraries(
	message_bus-direct
	PUBLIC eagine
)

add_executable(message_bus-ping "003_ping.cpp")
target_link_libraries(
	message_bus-ping
	PUBLIC eagine
)

add_executable(message_bus-pong "003_pong.cpp")
target_link_libraries(
	message_bus-pong
	PUBLIC eagine
)

add_executable(message_bus-fibonacci "004_fibonacci.cpp")
target_link_libraries(
	message_bus-fibonacci
	PUBLIC eagine
)

add_executable(message_bus-fib_threads "005_fib_threads.cpp")
target_link_libraries(
	message_bus-fib_threads
	PUBLIC eagine
)

add_executable(message_bus-conn_setup "006_conn_setup.cpp")
target_link_libraries(
	message_bus-conn_setup
	PUBLIC eagine
)
