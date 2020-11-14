#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
install(
	PROGRAMS tools/embed_generator
	RENAME eagine-embed_generator
	DESTINATION bin
)

include(CMakePackageConfigHelpers)

configure_package_config_file(
	"${CMAKE_CURRENT_SOURCE_DIR}/OGLplusConfig.cmake.in"
	"${CMAKE_CURRENT_BINARY_DIR}/OGLplusConfig.cmake"
	INSTALL_DESTINATION lib/cmake
)

install(
	FILES
		"${CMAKE_CURRENT_SOURCE_DIR}/CommonLibs.cmake"
		"${CMAKE_CURRENT_SOURCE_DIR}/FindThreads.cmake"
		"${CMAKE_CURRENT_SOURCE_DIR}/FindStacktrace.cmake"
		"${CMAKE_CURRENT_SOURCE_DIR}/FindBoostSpirit.cmake"
		"${CMAKE_CURRENT_SOURCE_DIR}/FindSSL.cmake"
		"${CMAKE_CURRENT_SOURCE_DIR}/FindZLIB.cmake"
		"${CMAKE_CURRENT_SOURCE_DIR}/EmbedCommon.cmake"
	DESTINATION lib/cmake/OGLplus
)

install(
	FILES "${CMAKE_CURRENT_BINARY_DIR}/OGLplusConfig.cmake"
	DESTINATION lib/cmake
)
