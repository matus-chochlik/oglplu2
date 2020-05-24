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

file(READ VERSION OGLPLUS_VERSION)

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
include(config/Embed.cmake)

include(config/FindThreads.cmake)
include(config/FindValgrind.cmake)
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

# SSL
include(config/FindSSL.cmake)

# PNG
include(config/FindPNG.cmake)

# EGL
include(config/FindEGL.cmake)

# OpenAL
include(config/FindAL.cmake)

# configure GL API and Context-init libraries
include(config/ConfigGL.cmake)

# if we only want the configuration info
if(${CONFIG_INFO_ONLY})
	add_subdirectory("config")
	return()
endif()

# now create the site-configuration headers
include(config/SiteConfig.cmake)

include_directories("${PROJECT_BINARY_DIR}/include")
include_directories("include")
include_directories("implement")
include_directories("third_party/include")
include_directories("third_party/asio/asio/include")

# common functions for GL version and extension detection
# include(config/GLVerFeat.cmake)
# GL version detection
# include(config/GLVer.cmake)
# GL feature detection
# include(config/GLFeat.cmake)

# re-create the site-configuration header
include(config/SiteConfig.cmake)
# installation
include(config/Installation.cmake)

# tools, textures, etc.
add_subdirectory("source")

# examples
if(NOT ${NO_EXAMPLES})
	add_subdirectory("example")
endif()

# tests
if(NOT ${NO_TESTS})
	add_subdirectory("test")
endif()

