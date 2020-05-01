#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
set(
	EAGINE_EMBED_GENERATOR
	"${PROJECT_SOURCE_DIR}/config/tools/embed_generator"
)

function(eagine_embed_target_resources TARGET_NAME)
	get_target_property(
		TARGET_SOURCES
		${TARGET_NAME}
		SOURCES
	)
	set(RESOURCE_FILE ${TARGET_NAME}.resources.cpp)
	set(GEN_DEPENDS)
	set(GEN_OPTIONS)
	list(APPEND GEN_OPTIONS -s)
	list(APPEND GEN_OPTIONS ${CMAKE_CURRENT_BINARY_DIR})
	list(APPEND GEN_OPTIONS -o)
	list(APPEND GEN_OPTIONS ${CMAKE_CURRENT_BINARY_DIR}/${RESOURCE_FILE})
	foreach(TARGET_SOURCE ${TARGET_SOURCES})
		list(APPEND GEN_OPTIONS -i)
		list(APPEND GEN_OPTIONS ${TARGET_SOURCE})
		list(APPEND GEN_DEPENDS ${TARGET_SOURCE})
	endforeach()
	add_custom_command(
		OUTPUT ${RESOURCE_FILE}
		COMMAND ${EAGINE_EMBED_GENERATOR} ${GEN_OPTIONS}
		WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
		DEPENDS ${GEN_DEPENDS} ${ARGN}
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
