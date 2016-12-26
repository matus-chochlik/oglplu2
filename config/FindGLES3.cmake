#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
unset(OPENGLES3_INCLUDE_DIRS)
set(OPENGLES3_FOUND 0)
#
# try to find GLES3/gl3.h
find_path(
	OPENGLES3_GL3_H_DIR GLES3/gl3.h
	PATHS ${HEADER_SEARCH_PATHS}
	NO_DEFAULT_PATH
)
# if that didn't work try the system directories
if((NOT OPENGLES3_GL3_H_DIR) OR (NOT EXISTS ${OPENGLES3_GL3_H_DIR}))
	find_path(
		OPENGLES3_GL3_H_DIR
		NAMES GLES3/gl3.h
	)
endif()
# if found append it to the include directories
if((OPENGLES3_GL3_H_DIR) AND (EXISTS ${OPENGLES3_GL3_H_DIR}))
	set(OPENGLES3_INCLUDE_DIRS ${OPENGLES3_INCLUDE_DIRS} ${OPENGLES3_GL3_H_DIR})
	set(OPENGLES3_FOUND 1)
	set(GLES3_GL3_H_FOUND 1)
endif()
#
# try to find the GLES3 library
find_library(
	OPENGLES3_LIBRARIES NAMES GLES3 GL
	PATHS ${LIBRARY_SEARCH_PATHS}
	NO_DEFAULT_PATH
)
if(NOT OPENGLES3_LIBRARIES)
	find_library(OPENGLES3_LIBRARIES NAMES GLES3)
else()
	get_filename_component(OPENGLES3_LIBRARY_DIRS ${OPENGLES3_LIBRARIES} PATH)
endif()

#if we have not found the library
if(NOT OPENGLES3_LIBRARIES)
	set(OPENGLES3_LIBRARIES "")
endif()
