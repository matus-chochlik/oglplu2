# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 2.8)

string(TOLOWER ${OGLPLUS_GL_INIT_LIB} OGLPLUS_EXAMPLE_HARNESS)

# check the harness dependencies and requirements
set(HARNESS_CAN_BE_BUILT true)
require_all_dependencies(main_${OGLPLUS_EXAMPLE_HARNESS} HARNESS_CAN_BE_BUILT)
if(NOT ${HARNESS_CAN_BE_BUILT})
	message(
		FATAL_ERROR
		"Some of the requirements for the '${OGLPLUS_EXAMPLE_HARNESS}' "
		"example harness were not met. Please choose a different build "
		"configuration or install the required libraries or use "
		"a different compiler."
	)
	return()
endif()

# add a target for the examples
add_custom_target(oglplus-examples ALL)
set_property(TARGET oglplus-examples PROPERTY FOLDER "Example/OGLplus")

unset(OGLPLUS_EXAMPLE_HARNESS_ADDITIONAL_SOURCES)

add_definitions("-DEAGINE_LINK_LIBRARY=1")
add_definitions("-DOGLPLUS_LINK_LIBRARY=1")

if("${OGLPLUS_EXAMPLE_HARNESS}" STREQUAL "glx")
	include_directories(${PROJECT_SOURCE_DIR}/source/utils)

elseif("${OGLPLUS_EXAMPLE_HARNESS}" STREQUAL "egl")
	target_link_libraries(oglplus_example_harness eglplus)

elseif("${OGLPLUS_EXAMPLE_HARNESS}" STREQUAL "qt4gl")
	qt4_wrap_cpp(
		OGLPLUS_EXAMPLE_HARNESS_ADDITIONAL_SOURCES
		"${CMAKE_CURRENT_SOURCE_DIR}/example/main_${OGLPLUS_EXAMPLE_HARNESS}.hpp"
	)
elseif("${OGLPLUS_EXAMPLE_HARNESS}" STREQUAL "qt5gl")
	qt5_generate_moc(
		"${CMAKE_CURRENT_SOURCE_DIR}/example/main_${OGLPLUS_EXAMPLE_HARNESS}.hpp"
		"${CMAKE_CURRENT_BINARY_DIR}/example/main_${OGLPLUS_EXAMPLE_HARNESS}-moc.cpp"
	)
	set(
		OGLPLUS_EXAMPLE_HARNESS_ADDITIONAL_SOURCES
		"${CMAKE_CURRENT_BINARY_DIR}/example/main_${OGLPLUS_EXAMPLE_HARNESS}-moc.cpp"
	)
endif()

# build the code common to all the examples into this library
if(OGLPLUS_EXAMPLE_HARNESS_ADDITIONAL_SOURCES)
	add_library(
		oglplus_example_harness STATIC
		EXCLUDE_FROM_ALL
		"${CMAKE_CURRENT_SOURCE_DIR}/example/main.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/example/args.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/example/wrapper.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/example/params.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/example/state_view.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/example/main_${OGLPLUS_EXAMPLE_HARNESS}.cpp"
		"${OGLPLUS_EXAMPLE_HARNESS_ADDITIONAL_SOURCES}"
	)
else()
	add_library(
		oglplus_example_harness STATIC
		EXCLUDE_FROM_ALL
		"${CMAKE_CURRENT_SOURCE_DIR}/example/main.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/example/args.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/example/wrapper.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/example/params.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/example/state_view.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/example/main_${OGLPLUS_EXAMPLE_HARNESS}.cpp"
	)
endif()

target_link_libraries(oglplus_example_harness eagine)
target_link_libraries(oglplus_example_harness oglplus)
# add the dependencies for the harness
add_all_dependencies(main_${OGLPLUS_EXAMPLE_HARNESS} oglplus_example_harness)
# optional dependencies for the harness with library
# TODO
#add_oglplus_lib_dependencies(oglplus_example_harness)
# set the solution folder
set_property(TARGET oglplus_example_harness PROPERTY FOLDER "Example/OGLplus")

# helper function used in the directories containing examples
function(add_examples LIBRARY EXAMPLE_PATTERN COMMON_LIBS)

	file(GLOB EXAMPLES "${CMAKE_CURRENT_SOURCE_DIR}/${EXAMPLE_PATTERN}.cpp")
	file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/examples.txt" "")

	foreach(EXAMPLE_PATH ${EXAMPLES})
		get_filename_component(EXAMPLE_NAME "${EXAMPLE_PATH}" NAME_WE)
		set(TARGET_NAME "${LIBRARY}-${EXAMPLE_NAME}")

		set(EXAMPLE_CAN_BE_BUILT true)
		require_all_dependencies(${EXAMPLE_NAME} EXAMPLE_CAN_BE_BUILT)

		if(EXAMPLE_CAN_BE_BUILT)
			add_executable(${TARGET_NAME} EXCLUDE_FROM_ALL ${EXAMPLE_PATH})
			target_link_libraries(${TARGET_NAME} ${COMMON_LIBS})
			add_all_dependencies(${TARGET_NAME})
			add_dependencies("${LIBRARY}-examples" ${TARGET_NAME})
			set_property(
				TARGET ${TARGET_NAME}
				PROPERTY FOLDER "Example/OGLplus"
			)
			if(${WIN32})
				if("${OGLPLUS_EXAMPLE_HARNESS}" STREQUAL "wxgl")
					set_property(
						TARGET ${TARGET_NAME}
						PROPERTY WIN32_EXECUTABLE true
					)
				endif()
			endif()
			file(APPEND "${CMAKE_CURRENT_BINARY_DIR}/examples.txt" "${EXAMPLE_NAME}\n")
		endif()
	endforeach()
endfunction(add_examples)

# make a list of libraries that we're going to link to
set(EXAMPLE_LIBS oglplus_example_harness ${OGLPLUS_GL_LIBRARIES})

# add oglplus examples
add_examples(oglplus "[0-9][0-9][0-9]*" "${EXAMPLE_LIBS}")

add_custom_target(glsl_program_sources ALL)
add_custom_target(glsl_shader_sources ALL)

file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/programs/")
file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/shaders/")

function(add_program_source DIR PROG_NAME)
	set(INPUT ${DIR}/programs/${PROG_NAME}.prog)
	file(STRINGS ${INPUT} PARAM_STR)
	string(REPLACE " " ";" PARAMETERS ${PARAM_STR}) 
	get_filename_component(GENERATOR ${PROG_NAME} NAME_WE)
	set(OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/programs/${PROG_NAME}.oglpprog")
	add_custom_command(
		OUTPUT ${OUTPUT}
		COMMAND bake_program_source
		ARGS ${PARAMETERS} --output ${OUTPUT}
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/shaders
		DEPENDS ${INPUT}
		COMMENT "Baking program source ${PROG_NAME}"
	)
	add_custom_target(bake-${PROG_NAME}-program_source DEPENDS ${OUTPUT})
	add_dependencies(glsl_program_sources bake-${PROG_NAME}-program_source)
	set_property(
		TARGET bake-${PROG_NAME}-program_source
		PROPERTY FOLDER "Example/OGLplus/GPUPrograms"
	)
endfunction()

function(add_shader_source DIR SHDR_NAME)
	set(INPUT ${DIR}/shaders/${SHDR_NAME}.glsl)
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
		set(OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/shaders/${SHDR_NAME}.oglpshdr")
		add_custom_command(
			OUTPUT ${OUTPUT}
			COMMAND bake_shader_source
			ARGS ${PARAMETERS} --input ${INPUT} --output ${OUTPUT}
			WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/shaders
			DEPENDS ${INPUT}
			COMMENT "Baking shader source ${SHDR_NAME}"
		)
		add_custom_target(bake-${SHDR_NAME}-shader_source DEPENDS ${OUTPUT})
		add_dependencies(glsl_shader_sources bake-${SHDR_NAME}-shader_source)
		set_property(
			TARGET bake-${SHDR_NAME}-shader_source
			PROPERTY FOLDER "Example/OGLplus/GPUPrograms"
		)
	endif()
endfunction()

function(add_glsl_program_sources DIR)
	file(GLOB SOURCES "${DIR}/programs/*.prog")

	foreach(SOURCE ${SOURCES})
		get_filename_component(FILE_NAME ${SOURCE} NAME)
		string(REGEX REPLACE "\\.[^.]*$" "" PROG_NAME ${FILE_NAME})

		set(PROGRAM_CAN_BE_BUILT true)
		require_all_dependencies(${PROG_NAME} PROGRAM_CAN_BE_BUILT)

		if(PROGRAM_CAN_BE_BUILT)
			add_program_source(${DIR} ${PROG_NAME})
		endif()
	endforeach()
endfunction()

function(add_glsl_shader_sources DIR)
	file(GLOB SOURCES "${DIR}/shaders/*.glsl")

	foreach(SOURCE ${SOURCES})
		get_filename_component(FILE_NAME ${SOURCE} NAME)
		string(REGEX REPLACE "\\.[^.]*$" "" SHDR_NAME ${FILE_NAME})

		set(SHADER_CAN_BE_BUILT true)
		require_all_dependencies(${SHDR_NAME} SHADER_CAN_BE_BUILT)

		if(SHADER_CAN_BE_BUILT)
			add_shader_source(${DIR} ${SHDR_NAME})
		endif()
	endforeach()
endfunction()

add_glsl_program_sources(${CMAKE_CURRENT_SOURCE_DIR})
add_glsl_shader_sources(${CMAKE_CURRENT_SOURCE_DIR})
