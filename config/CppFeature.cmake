#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
# we need C++14
if(${CMAKE_COMPILER_IS_GNUCXX})
	add_definitions(-std=c++1z)
	set(CPP_STD_COMPILER_SWITCH -std=c++1z)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	set(CPP_STD_COMPILER_SWITCH -std=c++1z)
endif()
# TODO add support for other compilers

add_definitions(${CPP_STD_COMPILER_SWITCH})

configure_file(
	${PROJECT_SOURCE_DIR}/config/cpp/test_compiler.cpp
	${PROJECT_BINARY_DIR}/cpp/test_compiler.cpp
)
try_compile(
	SUPPORTED_COMPILER
	${PROJECT_BINARY_DIR}/cpp
	${PROJECT_BINARY_DIR}/cpp/test_compiler.cpp
	COMPILE_DEFINITIONS ${CPP_STD_COMPILER_SWITCH}
)
if(NOT ${SUPPORTED_COMPILER})
	message(FATAL_ERROR
	"Your compiler does not support all required C++ features."
	)
endif()
