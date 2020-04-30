# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
add_custom_target(example-shaders ALL)

function(add_shader_source SHDR_NAME)
	if(TARGET bake_shader_source)
		set(INPUT ${SHDR_NAME}.glsl)
		string(REGEX REPLACE "^.*(\\.[^.]*)$" "\\1" SHDR_LEXT ${SHDR_NAME})
		if("${SHDR_LEXT}" STREQUAL ".vert")
			set(PARAMETERS "--shader-type;vertex")
		elseif("${SHDR_LEXT}" STREQUAL ".teco")
			set(PARAMETERS "--shader-type;tess_control")
		elseif("${SHDR_LEXT}" STREQUAL ".teev")
			set(PARAMETERS "--shader-type;tess_evaluation")
		elseif("${SHDR_LEXT}" STREQUAL ".geom")
			set(PARAMETERS "--shader-type;geometry")
		elseif("${SHDR_LEXT}" STREQUAL ".frag")
			set(PARAMETERS "--shader-type;fragment")
		elseif("${SHDR_LEXT}" STREQUAL ".comp")
			set(PARAMETERS "--shader-type;compute")
		endif()
		if(NOT("${PARAMETERS}" STREQUAL ""))
			set(OUTPUT "${SHDR_NAME}.oglpshdr")
			add_custom_target(
				${OUTPUT}
				COMMAND bake_shader_source
					${PARAMETERS}
						--input ${INPUT}
						--output "${CMAKE_CURRENT_BINARY_DIR}/${OUTPUT}"
				WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
				DEPENDS bake_shader_source ${INPUT}
				COMMENT "Baking shader source ${SHDR_NAME}"
			)
			add_dependencies(example-shaders ${OUTPUT})
			set_target_properties(
				${OUTPUT}
				PROPERTIES FOLDER "Example/Combined/BakedShaders"
			)
		endif()
	endif()
endfunction()

file(GLOB SOURCES "*.glsl")
foreach(SOURCE ${SOURCES})
	get_filename_component(FILE_NAME ${SOURCE} NAME)
	string(REGEX REPLACE "\\.[^.]*$" "" SHDR_NAME ${FILE_NAME})
	add_shader_source(${DIR} ${SHDR_NAME})
endforeach()

