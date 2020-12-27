#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
unset(OPENAL_INCLUDE_DIRS)
set(OPENAL_FOUND 0)
#
# try to find AL/al.h
find_path(
	OPENAL_AL_H_DIR AL/al.h
	PATHS ${HEADER_SEARCH_PATHS}
	NO_DEFAULT_PATH
)
# if that didn't work try the system directories
if((NOT OPENAL_AL_H_DIR) OR (NOT EXISTS ${OPENAL_AL_H_DIR}))
	find_path(OPENAL_AL_H_DIR AL/al.h)
endif()
# if found append it to the include directories
if((OPENAL_AL_H_DIR) AND (EXISTS ${OPENAL_AL_H_DIR}))
	set(OPENAL_INCLUDE_DIRS ${OPENAL_INCLUDE_DIRS} ${OPENAL_AL_H_DIR})
	set(OPENAL_AL_H_FOUND 1)
else()
	set(OPENAL_AL_H_FOUND 0)
endif()
#
#
# try to find AL/alc.h
find_path(
	OPENALC_AL_H_DIR AL/alc.h
	PATHS ${HEADER_SEARCH_PATHS}
	NO_DEFAULT_PATH
)
# if that didn't work try the system directories
if((NOT OPENAL_ALC_H_DIR) OR (NOT EXISTS ${OPENALC_AL_H_DIR}))
	find_path(OPENAL_ALC_H_DIR AL/alc.h)
endif()
# if found append it to the include directories
if((OPENAL_ALC_H_DIR) AND (EXISTS ${OPENAL_ALC_H_DIR}))
	if(NOT (${OPENAL_ALC_H_DIR} STREQUAL ${OPENAL_ALC_H_DIR}))
		set(OPENAL_INCLUDE_DIRS ${OPENAL_INCLUDE_DIRS} ${OPENAL_ALC_H_DIR})
	endif()
	set(OPENAL_ALC_H_FOUND 1)
else()
	set(OPENAL_ALC_H_FOUND 0)
endif()
#
#
# try to find AL/alut.h
find_path(
	OPENAL_ALUT_H_DIR AL/alut.h
	PATHS ${HEADER_SEARCH_PATHS}
	NO_DEFAULT_PATH
)
# if that didn't work try the system directories
if((NOT OPENAL_ALUT_H_DIR) OR (NOT EXISTS ${OPENAL_ALUT_H_DIR}))
	find_path(OPENAL_ALUT_H_DIR AL/alut.h)
endif()
#
if((OPENAL_ALUT_H_DIR) AND (EXISTS ${OPENAL_ALUT_H_DIR}))
	if(NOT (${OPENAL_ALC_H_DIR} STREQUAL ${OPENAL_ALC_H_DIR}))
		set(OPENAL_INCLUDE_DIRS ${OPENAL_INCLUDE_DIRS} ${OPENAL_ALUT_H_DIR})
	endif()
	set(OPENAL_ALUT_H_FOUND 1)
else()
	set(OPENAL_ALUT_H_FOUND 0)
endif()

# try to find the AL library
find_library(
	OPENAL_LIBRARY NAMES openal
	PATHS ${LIBRARY_SEARCH_PATHS}
	NO_DEFAULT_PATH
)
if(NOT OPENAL_LIBRARY)
	find_library(OPENAL_LIBRARY NAMES openal)
endif()

# try to find the ALUT library
find_library(
	OPENAL_ALUT_LIBRARY NAMES alut
	PATHS ${LIBRARY_SEARCH_PATHS}
	NO_DEFAULT_PATH
)
if(NOT OPENAL_ALUT_LIBRARY)
	find_library(OPENAL_ALUT_LIBRARY NAMES alut)
endif()

set(OPENAL_LIBRARIES "")
if(OPENAL_LIBRARY AND EXISTS ${OPENAL_LIBRARY})
	set(OPENAL_LIBRARIES ${OPENAL_LIBRARIES} ${OPENAL_LIBRARY})
endif()
if(OPENAL_ALUT_LIBRARY AND EXISTS ${OPENAL_ALUT_LIBRARY})
	set(OPENAL_LIBRARIES ${OPENAL_LIBRARIES} ${OPENAL_ALUT_LIBRARY})
endif()

if(OPENAL_AL_H_FOUND AND OPENAL_ALUT_H_FOUND)
	if(${OPENAL_AL_H_FOUND} AND ${OPENAL_ALUT_H_FOUND})
		set(OPENAL_FOUND 1)

		add_library(OpenAL::OpenAL INTERFACE IMPORTED)
		set_target_properties(
			OpenAL::OpenAL PROPERTIES
			INTERFACE_INCLUDE_DIRECTORIES "${OPENAL_INCLUDE_DIRS}"
		)
		set_target_properties(
			OpenAL::OpenAL PROPERTIES
			INTERFACE_LINK_LIBRARIES "${OPENAL_LIBRARIES}"
		)
	endif()
endif()
