# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

# router
add_executable(eagine-message_bus-router router.cpp)
eagine_add_exe_analysis(eagine-message_bus-router)
target_link_libraries(
	eagine-message_bus-router
	PUBLIC eagine
	PRIVATE eagine-common-pki
)
eagine_install_tool(eagine-message_bus-router)

# bridge
add_executable(eagine-message_bus-bridge bridge.cpp)
eagine_add_exe_analysis(eagine-message_bus-bridge)
target_link_libraries(
	eagine-message_bus-bridge
	PUBLIC eagine
	PRIVATE eagine-common-pki
)
eagine_install_tool(eagine-message_bus-bridge)

# scripts
install(
	PROGRAMS eagine-local-bridge.sh
	RENAME eagine-local-bridge
	DESTINATION bin
	COMPONENT tools
)

