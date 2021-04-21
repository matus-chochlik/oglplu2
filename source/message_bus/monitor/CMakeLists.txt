# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

# monitor
set(MONITOR_RESOURCES
	monitor.qrc
)
set(MONITOR_SOURCES
	monitor.cpp
	src/MonitorTheme.cpp
	src/MonitorBackend.cpp
	src/TrackerModel.cpp
	src/NodeListViewModel.cpp
	src/MonitorViewModel.cpp
	src/SelectedItemViewModel.cpp
)
set(MONITOR_HEADERS
	include/MonitorTheme.hpp
	include/MonitorBackend.hpp
	include/TrackerModel.hpp
	include/NodeListViewModel.hpp
	include/MonitorViewModel.hpp
	include/SelectedItemViewModel.hpp
)
add_executable(
	eagine-message_bus-monitor
	${MONITOR_RESOURCES}
	${MONITOR_SOURCES}
	${MONITOR_HEADERS}
)

eagine_add_exe_analysis(eagine-message_bus-monitor)

target_include_directories(
	eagine-message_bus-monitor
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(
	eagine-message_bus-monitor
	PUBLIC
		eagine
		Qt5::Core
		Qt5::Qml
		Qt5::Quick
)

