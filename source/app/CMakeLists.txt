# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

add_custom_target(applications ALL)
set_target_properties(
	applications
	PROPERTIES FOLDER "Application"
)
foreach(LIB GLFW3)
	add_library(EAGapp::${LIB} INTERFACE IMPORTED)
	if(${LIB}_FOUND)
		target_link_libraries(
			EAGapp::${LIB} 
			INTERFACE ${LIB}::${LIB}
		)
	endif()
endforeach()

add_library(EAGapp::EGL INTERFACE IMPORTED)
if(EGL_FOUND)
	target_link_libraries(
		EAGapp::EGL
		INTERFACE
			EGL::EGL
			eglplus
	)
endif()

add_library(EAGapp::OpenAL INTERFACE IMPORTED)
if(OPENAL_FOUND)
	target_link_libraries(
		EAGapp::OpenAL
		INTERFACE
			OpenAL::OpenAL
			oalplus
	)
endif()

add_library(
	eagine-application
	application_options.cpp
	application_context.cpp
	application_camera.cpp
	application_framedump.cpp
	application_eglplus.cpp
	application_glfw3.cpp
)
eagine_add_lib_analysis(eagine-application)

target_compile_definitions(
	eagine-application
	PUBLIC EAGINE_LINK_LIBRARY=1
)

target_include_directories(
	eagine-application PUBLIC
	"$<INSTALL_INTERFACE:include>"
	"$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>"
	"$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
	"$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/implement>"
	"$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/third_party/include>"
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
)

target_link_libraries(
	eagine-application
	PUBLIC
		eagine
		oglplus
	PRIVATE
		EAGapp::GLFW3
		EAGapp::EGL
		EAGapp::OpenAL
)
if(GLX_FOUND)
	target_link_libraries(
		eagine-application
		PRIVATE GLX::GLX
	)
endif()

set_target_properties(
	eagine-application PROPERTIES
	VERSION ${OGLPLUS_VERSION}
	FOLDER "Library/EAGine"
)

