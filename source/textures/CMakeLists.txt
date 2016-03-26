# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

add_custom_target(textures ALL)

file(MAKE_DIRECTORY "${PROJECT_BINARY_DIR}/textures/")

function(add_procedural_texture DIR TEX_NAME)
	set(INPUT ${DIR}/${TEX_NAME}.proc)
	file(STRINGS ${INPUT} PARAM_STR)
	string(REPLACE " " ";" PARAMETERS ${PARAM_STR}) 
	get_filename_component(GENERATOR ${TEX_NAME} NAME_WE)
	set(OUTPUT "${PROJECT_BINARY_DIR}/textures/${TEX_NAME}.oglptex")
	add_custom_command(
		OUTPUT ${OUTPUT}
		COMMAND bake_${GENERATOR}_image
		ARGS ${PARAMETERS} --output ${OUTPUT}
		DEPENDS ${INPUT}
		COMMENT "Baking image ${TEX_NAME}"
	)
	add_custom_target(bake-${TEX_NAME}-image DEPENDS ${OUTPUT})
	add_dependencies(textures bake-${TEX_NAME}-image)
	set_property(TARGET bake-${TEX_NAME}-image PROPERTY FOLDER "Textures")
endfunction()

function(add_procedural_textures DIR)
	file(GLOB SOURCES "${DIR}/*.proc")

	foreach(SOURCE ${SOURCES})
		get_filename_component(FILE_NAME ${SOURCE} NAME)
		string(REGEX REPLACE "\\.[^.]*$" "" TEX_NAME ${FILE_NAME})
		add_procedural_texture(${DIR} ${TEX_NAME})
	endforeach()
endfunction()

add_procedural_textures(${CMAKE_CURRENT_SOURCE_DIR})
