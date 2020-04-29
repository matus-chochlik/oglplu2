# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
add_custom_target(glsl_program_sources ALL)

function(add_program_source PROG_NAME)
	set(INPUT ${PROG_NAME}.prog)
	file(STRINGS ${INPUT} PARAM_STR)
	string(REPLACE " " ";" PARAMETERS ${PARAM_STR}) 

	list(APPEND DEPENDENCIES "${INPUT}")
	foreach(PARAM ${PARAMETERS})
		if(PARAM MATCHES ".+\.glsl")
			list(
				APPEND DEPENDENCIES
				"${CMAKE_CURRENT_SOURCE_DIR}/../shaders/${PARAM}"
			)
		endif()
	endforeach()

	get_filename_component(GENERATOR ${PROG_NAME} NAME_WE)
	set(OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${PROG_NAME}.oglpprog")

	add_custom_command(
		OUTPUT ${OUTPUT}
		COMMAND bake_program_source
		ARGS ${PARAMETERS} --output ${OUTPUT}
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../shaders
		DEPENDS ${DEPENDENCIES}
		COMMENT "Baking program source ${PROG_NAME}"
	)
	add_custom_target(bake-${PROG_NAME}-program_source DEPENDS ${OUTPUT})
	add_dependencies(glsl_program_sources bake-${PROG_NAME}-program_source)
	set_target_properties(
		bake-${PROG_NAME}-program_source
		PROPERTIES FOLDER "Example/Combined/GPUPrograms"
	)
endfunction()

file(GLOB SOURCES "*.prog")

foreach(SOURCE ${SOURCES})
	get_filename_component(FILE_NAME ${SOURCE} NAME)
	string(REGEX REPLACE "\\.[^.]*$" "" PROG_NAME ${FILE_NAME})

	add_program_source(${PROG_NAME})
endforeach()
