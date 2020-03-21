# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 3.10)

string(TOLOWER ${OGLPLUS_GL_INIT_LIB} OGLPLUS_EXAMPLE_HARNESS)

# add a target for the examples
add_custom_target(combined-examples ALL)
set_target_properties(
	combined-examples
	PROPERTIES FOLDER "Example/Combined"
)

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
		"${CMAKE_CURRENT_SOURCE_DIR}/example/main_qt5gl.hpp"
	)
elseif("${OGLPLUS_EXAMPLE_HARNESS}" STREQUAL "qt5gl")
	qt5_generate_moc(
		"${CMAKE_CURRENT_SOURCE_DIR}/example/main_qt5gl.hpp"
		"${CMAKE_CURRENT_BINARY_DIR}/example/main_qt5gl-moc.cpp"
	)
	set(
		OGLPLUS_EXAMPLE_HARNESS_ADDITIONAL_SOURCES
		"${CMAKE_CURRENT_BINARY_DIR}/example/main_qt5gl-moc.cpp"
	)
endif()

set(OGLPLUS_EXAMPLE_HARNESS_COMMON_SOURCES
		"${CMAKE_CURRENT_SOURCE_DIR}/example/args.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/example/wrapper.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/example/params.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/example/state_view.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/example/context.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/example/camera.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/example/main.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/example/main_glx.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/example/main_glfw3.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/example/main_glfw.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/example/main_glut.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/example/main_sdl.cpp"
)

# build the code common to all the examples into this library
if(OGLPLUS_EXAMPLE_HARNESS_ADDITIONAL_SOURCES)
	add_library(
		oglplus_example_harness STATIC
		EXCLUDE_FROM_ALL
		"${OGLPLUS_EXAMPLE_HARNESS_COMMON_SOURCES}"
		"${OGLPLUS_EXAMPLE_HARNESS_ADDITIONAL_SOURCES}"
	)
else()
	add_library(
		oglplus_example_harness STATIC
		EXCLUDE_FROM_ALL
		"${OGLPLUS_EXAMPLE_HARNESS_COMMON_SOURCES}"
	)
endif()

target_link_libraries(oglplus_example_harness eagine)
target_link_libraries(oglplus_example_harness oglplus)
# add the dependencies for the harness
add_all_dependencies(main_glx oglplus_example_harness)
add_all_dependencies(main_glfw3 oglplus_example_harness)
add_all_dependencies(main_glfw oglplus_example_harness)
add_all_dependencies(main_glut oglplus_example_harness)
add_all_dependencies(main_sdl oglplus_example_harness)
# optional dependencies for the harness with library
# TODO
#add_oglplus_lib_dependencies(oglplus_example_harness)
# set the solution folder
set_target_properties(
	oglplus_example_harness
	PROPERTIES FOLDER "Example/Combined"
)

if(INVOKE_CLANG_TIDY)
	set_target_properties(
		oglplus_example_harness
		PROPERTIES CXX_CLANG_TIDY "${INVOKE_CLANG_TIDY}"
	)
endif()

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
			set_target_properties(
				${TARGET_NAME}
				PROPERTIES FOLDER "Example/OGLplus"
			)
			if(CLANG_TIDY_EXE)
				set_target_properties(
					${TARGET_NAME}
					PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_EXE}"
				)
			endif()
			if(${WIN32})
				if("${OGLPLUS_EXAMPLE_HARNESS}" STREQUAL "wxgl")
					set_target_propertes(
						${TARGET_NAME}
						PROPERTIES WIN32_EXECUTABLE true
					)
				endif()
			endif()
			file(APPEND "${CMAKE_CURRENT_BINARY_DIR}/examples.txt" "${EXAMPLE_NAME}\n")
		endif()
	endforeach()
endfunction(add_examples)

# make a list of libraries that we're going to link to
set(EXAMPLE_LIBS oglplus_example_harness ${OGLPLUS_GL_LIBRARIES})

# add examples
#add_examples(combined "[0-9][0-9][0-9]*" "${EXAMPLE_LIBS}")
add_examples(combined "001_clear*" "${EXAMPLE_LIBS}")
add_examples(combined "002_triangle*" "${EXAMPLE_LIBS}")
add_examples(combined "004_pick*" "${EXAMPLE_LIBS}")

add_custom_target(glsl_program_sources ALL)
add_custom_target(glsl_shader_sources ALL)

file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/programs/")
file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/shaders/")

function(add_program_source DIR PROG_NAME)
	set(INPUT ${DIR}/programs/${PROG_NAME}.prog)
	file(STRINGS ${INPUT} PARAM_STR)
	string(REPLACE " " ";" PARAMETERS ${PARAM_STR}) 

	list(APPEND DEPENDENCIES "${INPUT}")
	foreach(PARAM ${PARAMETERS})
		if(PARAM MATCHES ".+\.glsl")
			list(
				APPEND DEPENDENCIES
				"${CMAKE_CURRENT_SOURCE_DIR}/shaders/${PARAM}"
			)
		endif()
	endforeach()

	get_filename_component(GENERATOR ${PROG_NAME} NAME_WE)
	set(OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/programs/${PROG_NAME}.oglpprog")

	add_custom_command(
		OUTPUT ${OUTPUT}
		COMMAND bake_program_source
		ARGS ${PARAMETERS} --output ${OUTPUT}
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/shaders
		DEPENDS ${DEPENDENCIES}
		COMMENT "Baking program source ${PROG_NAME}"
	)
	add_custom_target(bake-${PROG_NAME}-program_source DEPENDS ${OUTPUT})
	add_dependencies(glsl_program_sources bake-${PROG_NAME}-program_source)
	set_target_properties(
		bake-${PROG_NAME}-program_source
		PROPERTIES FOLDER "Example/OGLplus/GPUPrograms"
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
		set_target_properties(
			bake-${SHDR_NAME}-shader_source
			PROPERTIES FOLDER "Example/OGLplus/GPUPrograms"
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
