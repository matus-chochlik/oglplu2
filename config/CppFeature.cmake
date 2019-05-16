#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	list(APPEND CMAKE_CXX_FLAGS --std=c++${CMAKE_CXX_STANDARD})
endif()

configure_file(
	${PROJECT_SOURCE_DIR}/config/cpp/test_compiler.cpp
	${PROJECT_BINARY_DIR}/cpp/test_compiler.cpp
)
try_compile(
	SUPPORTED_COMPILER
	${PROJECT_BINARY_DIR}/cpp
	${PROJECT_BINARY_DIR}/cpp/test_compiler.cpp
)
if(NOT ${SUPPORTED_COMPILER})
	message(FATAL_ERROR
	"Your compiler does not support all required C++ features."
	)
endif()
