#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#

file(
	WRITE "${CMAKE_CURRENT_BINARY_DIR}/environment"
	"OGLPLUS_PREFIX=${CMAKE_INSTALL_PREFIX}\n"
	"OGLPLUS_SERVICE_ARGS=--use-syslog --min-log-severity info --config-group service\n"
)

install(
	FILES "${CMAKE_CURRENT_BINARY_DIR}/environment"
	DESTINATION share/oglplus/user/.oglplus/systemd
)

install(
	FILES
		"eagine-message_bus-router.service"
		"eagine-message_bus-ssh-bridge@.service"
		"eagine-message_bus-pingable@.service"
		"eagine-message_bus-sudoku_helper.service"
	DESTINATION share/oglplus/user/.config/systemd/user
)

