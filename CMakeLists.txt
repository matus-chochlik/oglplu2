# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 3.10)

include(config/Policies.cmake)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_DEBUG_POSTFIX d)

project(OGLplus)
set(OGLPLUS_TARGET_PREFIX)

file(STRINGS VERSION OGLPLUS_VERSION)

include(config/Defaults.cmake)

if(NOT ${CONFIG_INFO_ONLY})
	include(config/BuildType.cmake)
	include(config/StaticAnalysis.cmake)
	include(config/Compiler.cmake)
	include(config/CppFeature.cmake)
	include(config/LowProfile.cmake)
	include(config/Jobs.cmake)
endif()

include(config/Tools.cmake)

include(config/FindThreads.cmake)
include(config/FindGZip.cmake)
include(config/FindValgrind.cmake)
include(config/FindStacktrace.cmake)
include(config/FindBoostSpirit.cmake)
include(config/CommonLibs.cmake)

include(config/CommonFindMod.cmake)

# GL-libraries
include(config/FindGL.cmake)
include(config/FindGLES3.cmake)
include(config/FindGLEW.cmake)
include(config/FindGL3W.cmake)

include(config/FindGLX.cmake)
include(config/FindGLFW.cmake)
include(config/FindGLFW3.cmake)
include(config/FindGLUT.cmake)
include(config/FindSDL.cmake)
include(config/FindWXGL.cmake)
include(config/FindQT5GL.cmake)

include(config/FindGLM.cmake)

# ZLIB
include(config/FindZLIB.cmake)

# SSL
include(config/FindSSL.cmake)

# PNG
include(config/FindPNG.cmake)

# EGL
include(config/FindEGL.cmake)

# OpenAL
include(config/FindAL.cmake)

include(config/Baking.cmake)
include(config/Embed.cmake)
include(config/PKI.cmake)

# configure GL API and Context-init libraries
include(config/ConfigGL.cmake)

# if we only want the configuration info
if(${CONFIG_INFO_ONLY})
	add_subdirectory("config/info")
	return()
endif()

# now create the site-configuration headers
include(config/SiteConfig.cmake)
include(config/GitInfo.cmake)

# common functions for GL version and extension detection
# include(config/GLVerFeat.cmake)
# GL version detection
# include(config/GLVer.cmake)
# GL feature detection
# include(config/GLFeat.cmake)

# re-create the site-configuration header
include(config/SiteConfig.cmake)

# third party libraries
add_subdirectory("third_party")

# tools, textures, etc.
add_subdirectory("source")

# assets
add_subdirectory("assets")

# examples
if(NOT ${NO_EXAMPLES})
	add_subdirectory("example")
endif()

# tests
if(NOT ${NO_TESTS})
	add_subdirectory("test")
endif()

add_subdirectory("config")

# install the headers
install(
	DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
	DESTINATION include
)
# install the implementation inline files
install(
	DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/implement/
	DESTINATION include
)
# install the generated headers
install(
	DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/
	DESTINATION include
)

