#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
#
set(OGLPLUS_GL_INIT_LIBS GLX GLUT GLFW3 GLFW SDL WXGL EGL)
if(${WIN32})
	set(OGLPLUS_GL_API_LIBS GLEW GL3W GLCOREARB_H GL3_H)
else()
	set(OGLPLUS_GL_API_LIBS GLCOREARB_H GL3_H GLEW GL3W)
endif()
#
# The GL context initialization library
set(OGLPLUS_FORCE_GL_INIT_LIB "NONE" CACHE STRING "The GL context initialization library to be used.")
set_property(CACHE OGLPLUS_FORCE_GL_INIT_LIB PROPERTY STRINGS ${OGLPLUS_GL_INIT_LIBS})

# The GL API declaration library
set(OGLPLUS_FORCE_GL_API_LIB "NONE" CACHE STRING "The GL API definition library to be used.")
set_property(CACHE OGLPLUS_FORCE_GL_API_LIB PROPERTY STRINGS ${OGLPLUS_GL_API_LIBS})

# We'll need OpenGL API and context initialization/window-system library
foreach(KIND API INIT)
	if((NOT OGLPLUS_FORCE_GL_${KIND}_LIB) OR (${OGLPLUS_FORCE_GL_${KIND}_LIB} STREQUAL "NONE"))
		foreach(GL_${KIND}_LIB ${OGLPLUS_GL_${KIND}_LIBS})
			if(${GL_${KIND}_LIB}_FOUND)
				set(GL_LIB_HAS_ALL_DEPS true)
				string(TOLOWER ${GL_${KIND}_LIB} LIB_LC)
				# TODO
				#do_require_all_dependencies(
				#	"${CMAKE_CURRENT_SOURCE_DIR}/example/oglplus"
				#	"${LIB_LC}_main"
				#	GL_LIB_HAS_ALL_DEPS
				#)
				unset(LIB_LC)
				if(${GL_LIB_HAS_ALL_DEPS})
					set(OGLPLUS_GL_${KIND}_LIB ${GL_${KIND}_LIB})
					set(OGLPLUS_USE_${GL_${KIND}_LIB} 1)
					break()
				endif()
			endif()
		endforeach()
	else()
		foreach(GL_${KIND}_LIB ${OGLPLUS_GL_${KIND}_LIBS})
			if(${OGLPLUS_FORCE_GL_${KIND}_LIB} STREQUAL ${GL_${KIND}_LIB})
				if(${GL_${KIND}_LIB}_FOUND)
					set(OGLPLUS_GL_${KIND}_LIB ${GL_${KIND}_LIB})
					set(OGLPLUS_USE_${GL_${KIND}_LIB} 1)
					break()
				else()
					message(
						FATAL_ERROR
						"The '${GL_${KIND}_LIB}' library requested but not found"
					)
					return()
				endif()
			endif()
		endforeach()
	endif()
endforeach()

if(NOT OGLPLUS_GL_INIT_LIB)
	if(NOT OGLPLUS_NO_EXAMPLES)
		message(FATAL_ERROR "No OpenGL context initialization library found!")
	endif()
else()
	message(STATUS "Using ${OGLPLUS_GL_INIT_LIB} for GL context initialization.")
endif()

unset(OGLPLUS_GL_INCLUDE_DIRS)

if((${OGLPLUS_USE_GLCOREARB_H}) OR (${OGLPLUS_USE_GL3_H}))

	set(OGLPLUS_GL_INCLUDE_DIRS ${OPENGL_INCLUDE_DIRS})
	include_directories(BEFORE SYSTEM ${OPENGL_INCLUDE_DIRS})
	set(OGLPLUS_GL_LIBRARIES ${OPENGL_LIBRARIES})
	set(OGLPLUS_GL_FOUND 1)

	message(STATUS "Using native OpenGL API library")
elseif(${OGLPLUS_USE_GLEW})

	set(OGLPLUS_GL_INCLUDE_DIRS ${GLEW_INCLUDE_DIRS})
	include_directories(BEFORE SYSTEM ${GLEW_INCLUDE_DIRS})
	set(OGLPLUS_GL_LIBRARIES ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES})
	set(OGLPLUS_GL_FOUND 1)

	message(STATUS "Using GLEW as GL API library")
elseif(${OGLPLUS_USE_GL3W})

  set(OGLPLUS_GL_INCLUDE_DIRS ${GL3W_INCLUDE_DIRS})
	include_directories(BEFORE SYSTEM ${GL3W_INCLUDE_DIRS})
	set(OGLPLUS_GL_LIBRARIES ${GL3W_LIBRARIES} ${OPENGL_LIBRARIES})
	set(OGLPLUS_GL_FOUND 1)

	message(STATUS "Using GL3W as GL API library")
else()
	message(FATAL_ERROR "A library including OpenGL symbols is required for OGLplus")
	return()
endif()

