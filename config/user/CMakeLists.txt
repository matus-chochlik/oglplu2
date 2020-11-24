#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#

install(
	PROGRAMS
		"execute"
		"ssh-bridge"
	DESTINATION share/oglplus/user/.oglplus
)

install(
	PROGRAMS
		"ssh-bridge-cmd/kill_eagine"
		"ssh-bridge-cmd/show_prefix"
		"ssh-bridge-cmd/pong_local"
		"ssh-bridge-cmd/pong_registry"
	DESTINATION share/oglplus/user/.oglplus/ssh-bridge-cmd
)

add_executable(echo_input "src/echo_input.c")
install(
	TARGETS
		echo_input
	DESTINATION share/oglplus/user/.oglplus/ssh-bridge-cmd
)

install(
	PROGRAMS
		"bin/ssh-bridge"
		"bin/echo_input"
		"bin/show_prefix"
		"bin/ping_local"
		"bin/ping_registry"
	DESTINATION share/oglplus/user/.oglplus/bin
)

install(
	PROGRAMS "update-me"
	DESTINATION share/oglplus/user
)

install(
	FILES
		"config/service.yaml"
		"config/eagine-application_config.yaml"
		"config/_template.yaml"
	DESTINATION share/oglplus/user/.oglplus/config
)

