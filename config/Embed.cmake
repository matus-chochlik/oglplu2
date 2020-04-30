#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
set(
	EAGINE_EMBED_GENERATOR
	"${PROJECT_SOURCE_DIR}/config/tools/embed_generator"
)

function(eagine_embed_resources TARGET_NAME)
	get_target_property(
		TARGET_SOURCES
		${TARGET_NAME}
		SOURCES
	)
	set(RESOURCE_FILE ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}-res.cpp)
	set(GEN_OPTIONS -o;${RESOURCE_FILE})
	foreach(TARGET_SOURCE ${TARGET_SOURCES})
		list(APPEND GEN_OPTIONS -i)
		list(APPEND GEN_OPTIONS ${TARGET_SOURCE})
	endforeach()
	execute_process(
		COMMAND ${EAGINE_EMBED_GENERATOR} ${GEN_OPTIONS}
		WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
		RESULT_VARIABLE GENERATE_ERRORS
	)
	if(NOT GENERATE_ERRORS)
		target_sources(
			${TARGET_NAME}
			PRIVATE ${RESOURCE_FILE}
		)
	else()
		message(FATAL_ERROR "failed to compile resources for ${TARGET_NAME}")
	endif()
endfunction()
