#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
define_property(
	TARGET PROPERTY OGLPLUS_BAKED_RESOURCE_PATH
	BRIEF_DOCS "Path of bake target output"
	FULL_DOCS "Path of a baked resource output file"
)

#
# Common
#
function(oglplus_do_add_baked_resource BAKE_COMMAND RES_NAME RES_KIND INPUT TRY_PACK)
	if(TARGET "${OGLPLUS_TARGET_PREFIX}${BAKE_COMMAND}")
		configure_file("${INPUT}" "${CMAKE_CURRENT_BINARY_DIR}/${RES_NAME}.bake${RES_KIND}")
		file(
			STRINGS "${CMAKE_CURRENT_BINARY_DIR}/${RES_NAME}.bake${RES_KIND}"
			PARAMETER_STRING
		)
		string(REPLACE "\;" ";" RAW_PARAMETERS ${PARAMETER_STRING})

		set(PARAMETERS)
		foreach(ITEM ${RAW_PARAMETERS})
			if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${ITEM}")
				list(APPEND PARAMETERS "${CMAKE_CURRENT_SOURCE_DIR}/${ITEM}")
			else()
				list(APPEND PARAMETERS "${ITEM}")
			endif()
		endforeach()

		list(APPEND PARAMETERS "--output")
		list(APPEND PARAMETERS "${CMAKE_CURRENT_BINARY_DIR}/${RES_NAME}.oglp${RES_KIND}")

		add_custom_command(
			OUTPUT "${RES_NAME}.oglp${RES_KIND}"
			COMMAND "${OGLPLUS_TARGET_PREFIX}${BAKE_COMMAND}"
			ARGS ${PARAMETERS}
			DEPENDS ${INPUT} "${OGLPLUS_TARGET_PREFIX}${BAKE_COMMAND}"
			COMMENT "Baking resource ${RES_NAME}.oglp${RES_KIND}"
		)
		set_source_files_properties(
			"${RES_NAME}.oglp${RES_KIND}"
			PROPERTIES GENERATED 1
		)
		set(RES_SUFFIX)

		if(${TRY_PACK})
			if(GZIP_COMMAND)
				set(RES_SUFFIX .gz)
				add_custom_command(
					OUTPUT "${RES_NAME}.oglp${RES_KIND}.gz"
					COMMAND "${GZIP_COMMAND}"
					ARGS -9;-f;"${CMAKE_CURRENT_BINARY_DIR}/${RES_NAME}.oglp${RES_KIND}"
					DEPENDS ${RES_NAME}.oglp${RES_KIND}
					COMMENT "Compressing resource ${RES_NAME}.oglp${RES_KIND}"
				)
				set_source_files_properties(
					"${RES_NAME}.oglp${RES_KIND}.gz"
					PROPERTIES GENERATED 1
				)
			endif()
		endif()

		add_custom_target(
			${RES_NAME}
			DEPENDS "${RES_NAME}.oglp${RES_KIND}${RES_SUFFIX}"
		)
		set_property(
			TARGET ${RES_NAME}
			APPEND PROPERTY OGLPLUS_BAKED_RESOURCE_PATH
			"${CMAKE_CURRENT_BINARY_DIR}/${RES_NAME}.oglp${RES_KIND}${RES_SUFFIX}"
		)
	endif()
endfunction()

#
# Textures
#
function(oglplus_do_add_baked_texture GENERATOR TEX_NAME INPUT TRY_PACK)
	oglplus_do_add_baked_resource(
		oglplus-bake_${GENERATOR}_image
		${TEX_NAME}
		tex
		${INPUT}
		${TRY_PACK}
	)
endfunction()

function(oglplus_do_add_texture TEX_NAME TRY_PACK)
	file(GLOB BAKETEX "${TEX_NAME}.*.baketex")
	if("${BAKETEX}" MATCHES "^.*${TEX_NAME}\.(.*)\.baketex$")
		oglplus_do_add_baked_texture(
			${CMAKE_MATCH_1}
			${TEX_NAME}
			${BAKETEX}
			${TRY_PACK}
		)
	else()
		if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${TEX_NAME}.png")
			file(
				WRITE "${CMAKE_CURRENT_BINARY_DIR}/${TEX_NAME}.png.baketex"
				"--input;${CMAKE_CURRENT_SOURCE_DIR}/${TEX_NAME}.png"
			)
			oglplus_do_add_baked_texture(
				png
				${TEX_NAME}
				"${CMAKE_CURRENT_BINARY_DIR}/${TEX_NAME}.png.baketex"
				${TRY_PACK}
			)
		else()
			message(FATAL_ERROR "Invalid input(s) for texture '${TEX_NAME}'")
		endif()
	endif()
endfunction()

function(oglplus_add_texture TEX_NAME)
	oglplus_do_add_texture(${TEX_NAME} FALSE)
endfunction()

function(oglplus_add_packed_texture TEX_NAME)
	oglplus_do_add_texture(${TEX_NAME} TRUE)
endfunction()

#
# GLSL programs
#
function(oglplus_do_add_baked_glsl_program PROG_NAME INPUT TRY_PACK)
	oglplus_do_add_baked_resource(
		oglplus-bake_program_source
		${PROG_NAME}
		prog
		${INPUT}
		${TRY_PACK}
	)
endfunction()


function(oglplus_do_add_glsl_program PROG_NAME TRY_PACK)
	file(GLOB BAKEPROG "${PROG_NAME}.bakeprog")
	if("${BAKEPROG}" MATCHES "^.*${PROG_NAME}\.bakeprog$")
		oglplus_do_add_baked_glsl_program(
			${PROG_NAME}
			${BAKEPROG}
			${TRY_PACK}
		)
	else()
		message(FATAL_ERROR "Invalid input(s) for GLSL program '${PROG_NAME}'")
	endif()
endfunction()

function(oglplus_add_glsl_program PROG_NAME)
	oglplus_do_add_glsl_program(${PROG_NAME} FALSE)
endfunction()

