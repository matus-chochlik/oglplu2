# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 3.10)
project(oglplus_glfw3_glew_clear)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)

find_package(OGLplus REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

add_executable(glfw3_glew_clear main.cpp)
target_link_libraries(
	glfw3_glew_clear
	PRIVATE
		OGLplus::oglplus
		OpenGL::GL
		GLEW::GLEW
		glfw
)
