#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
function(eagine_do_embed_target_resources TARGET_NAME PACKED)
	get_target_property(
		TARGET_SOURCES
		${TARGET_NAME}
		SOURCES
	)
	set(RESOURCE_FILE ${TARGET_NAME}.resources.cpp)
	set(GEN_DEPENDS)
	set(GEN_OPTIONS)
	if(${PACKED})
		list(APPEND GEN_OPTIONS --packed)
	endif()
	list(APPEND GEN_OPTIONS -s)
	list(APPEND GEN_OPTIONS ${CMAKE_CURRENT_BINARY_DIR})
	list(APPEND GEN_OPTIONS -o)
	list(APPEND GEN_OPTIONS ${CMAKE_CURRENT_BINARY_DIR}/${RESOURCE_FILE})
	foreach(TARGET_SOURCE ${TARGET_SOURCES})
		if(EXISTS ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_SOURCE})
			set(DIR ${CMAKE_CURRENT_BINARY_DIR})
		else()
			set(DIR ${CMAKE_CURRENT_SOURCE_DIR})
		endif()
		list(APPEND GEN_OPTIONS -i)
		list(APPEND GEN_OPTIONS ${DIR}/${TARGET_SOURCE})
		list(APPEND GEN_DEPENDS ${DIR}/${TARGET_SOURCE})
	endforeach()

	set(RES_PATHS)
	foreach(RES_NAME ${ARGN})
		if(EXISTS "${CMAKE_CURRENT_BINARY_DIR}/${RES_NAME}")
			list(APPEND RES_PATHS "${CMAKE_CURRENT_BINARY_DIR}/${RES_NAME}")
		elseif(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${RES_NAME}")
			list(APPEND RES_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/${RES_NAME}")
		elseif(TARGET ${RES_NAME})
			get_property(
				RES_PATH
				TARGET ${RES_NAME}
				PROPERTY OGLPLUS_BAKED_RESOURCE_PATH
			)

			list(APPEND GEN_DEPENDS "${RES_NAME}")
			list(APPEND GEN_OPTIONS -t)
			list(APPEND GEN_OPTIONS ${RES_NAME} ${RES_PATH})
			list(APPEND RES_PATHS "${RES_PATH}")
		else()
			list(APPEND RES_PATHS "${RES_NAME}")
		endif()
	endforeach()

	add_custom_command(
		OUTPUT ${RESOURCE_FILE}
		COMMAND ${EAGINE_EMBED_GENERATOR} ${GEN_OPTIONS}
		WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
		DEPENDS ${GEN_DEPENDS} ${RES_PATHS}
	)
	set_source_files_properties(
		${RESOURCE_FILE}
		PROPERTIES GENERATED 1
	)
	target_sources(
		${TARGET_NAME}
		PRIVATE ${RESOURCE_FILE}
	)
endfunction()

function(eagine_embed_target_resources TARGET_NAME)
	eagine_do_embed_target_resources(${TARGET_NAME} FALSE ${ARGN})
endfunction()

function(eagine_embed_packed_target_resources TARGET_NAME)
	if(${ZLIB_FOUND})
		eagine_do_embed_target_resources(${TARGET_NAME} TRUE ${ARGN})
	else()
		eagine_do_embed_target_resources(${TARGET_NAME} FALSE ${ARGN})
	endif()
endfunction()
