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

function(oglplus_do_add_generated_texture GENERATOR TEX_NAME INPUT)

	if(TARGET ${OGLPLUS_TARGET_PREFIX}oglplus-bake_${GENERATOR}_image)
		configure_file("${INPUT}" "${CMAKE_CURRENT_BINARY_DIR}/${TEX_NAME}.proctex")
		file(
			STRINGS "${CMAKE_CURRENT_BINARY_DIR}/${TEX_NAME}.proctex"
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
		list(APPEND PARAMETERS "${CMAKE_CURRENT_BINARY_DIR}/${TEX_NAME}.oglptex")

		add_custom_command(
			OUTPUT "${TEX_NAME}.oglptex"
			COMMAND "${OGLPLUS_TARGET_PREFIX}oglplus-bake_${GENERATOR}_image"
			ARGS ${PARAMETERS}
			DEPENDS ${INPUT}
			COMMENT "Baking texture image ${TEX_NAME}"
		)
		add_custom_target(
			${TEX_NAME}
			DEPENDS "${TEX_NAME}.oglptex"
		)
		set_property(
			TARGET ${TEX_NAME}
			APPEND PROPERTY OGLPLUS_BAKED_RESOURCE_PATH
			"${CMAKE_CURRENT_BINARY_DIR}/${TEX_NAME}.oglptex"
		)
	else()
		message(
			WARNING
			"Missing '${GENERATOR}' generator, for texture image '${TEX_NAME}'"
		)
	endif()
endfunction()

function(oglplus_add_texture TEX_NAME)
	file(GLOB PROCTEX "${TEX_NAME}.*.proctex")
	if("${PROCTEX}" MATCHES "^.*${TEX_NAME}\.(.*)\.proctex$")
		oglplus_do_add_generated_texture(
			${CMAKE_MATCH_1}
			${TEX_NAME}
			${PROCTEX}
		)
	else()
		if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${TEX_NAME}.png")
			file(
				WRITE "${CMAKE_CURRENT_BINARY_DIR}/${TEX_NAME}.png.proctex"
				"--input;${CMAKE_CURRENT_SOURCE_DIR}/${TEX_NAME}.png"
			)
			oglplus_do_add_generated_texture(
				png
				${TEX_NAME}
				"${CMAKE_CURRENT_BINARY_DIR}/${TEX_NAME}.png.proctex"
			)
		else()
			message(FATAL_ERROR "Invalid input(s) for texture '${TEX_NAME}'")
		endif()
	endif()
endfunction()