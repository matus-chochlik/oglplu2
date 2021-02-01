# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#

add_library(EAGXharness::GLX INTERFACE IMPORTED)
if(GLX_FOUND)
	set_target_properties(
		EAGXharness::GLX PROPERTIES
		INTERFACE_INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/source/utils/"
	)
	set_target_properties(
		EAGXharness::GLX PROPERTIES
		INTERFACE_LINK_LIBRARIES GLX::GLX
	)
endif()

foreach(LIB GLFW3 GLFW GLUT SDL)
	add_library(EAGXharness::${LIB} INTERFACE IMPORTED)
	if(${LIB}_FOUND)
		set_target_properties(
			EAGXharness::${LIB} PROPERTIES
			INTERFACE_LINK_LIBRARIES ${LIB}::${LIB}
		)
	endif()
endforeach()

add_library(
	combined_example_harness STATIC
	EXCLUDE_FROM_ALL
		args.cpp
		wrapper.cpp
		params.cpp
		state_view.cpp
		context.cpp
		camera.cpp
		random.cpp
		main.cpp
		main_glx.cpp
		main_glfw3.cpp
		main_glfw.cpp
		main_glut.cpp
		main_sdl.cpp
)
eagine_add_lib_analysis(combined_example_harness)
set_target_properties(
	combined_example_harness
	PROPERTIES FOLDER "Example/Combined"
)
target_link_libraries(
	combined_example_harness
	PUBLIC
		eagine
		oglplus
		EAGXharness::GLX
		EAGXharness::GLFW3
		EAGXharness::GLFW
		EAGXharness::GLUT
		EAGXharness::SDL
)



