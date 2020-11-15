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

set(INCLUDE_INSTALL_DIR include/)
set(LIBRARY_INSTALL_DIR lib/)
set(EXECUTABLE_INSTALL_DIR bin/)
set(SYSCONFIG_INSTALL_DIR etc/oglplus/)

configure_package_config_file(
	"${CMAKE_CURRENT_SOURCE_DIR}/OGLplusConfig.cmake.in"
	"${CMAKE_CURRENT_BINARY_DIR}/OGLplusConfig.cmake"
	INSTALL_DESTINATION ${LIBRARY_INSTALL_DIR}/cmake
	PATH_VARS
		INCLUDE_INSTALL_DIR
		LIBRARY_INSTALL_DIR
		EXECUTABLE_INSTALL_DIR
		SYSCONFIG_INSTALL_DIR
)
write_basic_package_version_file(
	"${CMAKE_CURRENT_BINARY_DIR}/OGLplusConfigVersion.cmake"
	VERSION "${OGLPLUS_VERSION}"
	COMPATIBILITY SameMinorVersion
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
		"${CMAKE_CURRENT_SOURCE_DIR}/Baking.cmake"
	DESTINATION lib/cmake/OGLplus
)

install(
	FILES
		"${CMAKE_CURRENT_BINARY_DIR}/OGLplusConfig.cmake"
		"${CMAKE_CURRENT_BINARY_DIR}/OGLplusConfigVersion.cmake"
	DESTINATION lib/cmake
)
