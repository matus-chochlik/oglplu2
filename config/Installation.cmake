#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
# install the headers
install(
	DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION include
)
# install the implementation inline files
install(
	DIRECTORY ${PROJECT_SOURCE_DIR}/implement/
	DESTINATION include
)
# install the generated headers
install(
	DIRECTORY ${PROJECT_BINARY_DIR}/include/
	DESTINATION include
)
#
# user ~/.oglplus config directory
install(
	FILES "${PROJECT_SOURCE_DIR}/INSTALL_PREFIX"
	DESTINATION home/user/.oglplus
)
install(
	PROGRAMS "${CMAKE_CURRENT_SOURCE_DIR}/config/home/ssh-bridge"
	DESTINATION home/user/.oglplus
)
install(
	PROGRAMS
		"${CMAKE_CURRENT_SOURCE_DIR}/config/home/ssh-bridge-cmd/kill_eagine"
		"${CMAKE_CURRENT_SOURCE_DIR}/config/home/ssh-bridge-cmd/show_prefix"
		"${CMAKE_CURRENT_SOURCE_DIR}/config/home/ssh-bridge-cmd/echo_args"
		"${CMAKE_CURRENT_SOURCE_DIR}/config/home/ssh-bridge-cmd/pong_local"
		"${CMAKE_CURRENT_SOURCE_DIR}/config/home/ssh-bridge-cmd/pong_registry"
	DESTINATION home/user/.oglplus/ssh-bridge-cmd
)
install(
	PROGRAMS
		"${CMAKE_CURRENT_SOURCE_DIR}/config/home/bin/ping_local"
		"${CMAKE_CURRENT_SOURCE_DIR}/config/home/bin/ping_registry"
	DESTINATION home/user/.oglplus/bin
)
install(
	PROGRAMS "${CMAKE_CURRENT_SOURCE_DIR}/config/home/update-me.sh"
	DESTINATION home
)
install(
	FILES
		"${PROJECT_SOURCE_DIR}/config/home/config/eagine-application_config.yaml"
		"${PROJECT_SOURCE_DIR}/config/home/config/_template.yaml"
	DESTINATION home/user/.oglplus/config
)
# install example
function(eagine_install_example TARGET_NAME)
	install(
		TARGETS ${TARGET_NAME}
		DESTINATION share/oglplus/examples
	)
endfunction()
