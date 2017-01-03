#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
# checks if an EXE can be built and adds required include directories
macro(do_use_single_dependency TGT_NAME DEPENDENCY)
	if(${${DEPENDENCY}_FOUND})
		if(${DEPENDENCY}_USE_FILE)
			include(${${DEPENDENCY}_USE_FILE})
		endif()
		if(${DEPENDENCY}_INCLUDE_DIRS)
			include_directories(${${DEPENDENCY}_INCLUDE_DIRS})
		endif()
		if(${DEPENDENCY}_LIBRARY_DIRS)
			include_directories(${${DEPENDENCY}_LIBRARY_DIRS})
			link_directories(${${DEPENDENCY}_LIBRARY_DIRS})
		endif()
		if(${DEPENDENCY}_DEFINITIONS)
			set_property(
				SOURCE "${TGT_NAME}.cpp" APPEND PROPERTY
				COMPILE_DEFINITIONS ${${DEPENDENCY}_DEFINITIONS}
			)
		endif()
		if(${DEPENDENCY}_CFLAGS)
			string(REPLACE ";" " " TEMP "${${DEPENDENCY}_CFLAGS}")
			set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TEMP}")
		endif()
		if(${DEPENDENCY}_CFLAGS_OTHER)
			string(REPLACE ";" " " TEMP "${${DEPENDENCY}_CFLAGS_OTHER}")
			set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TEMP}")
		endif()
		if(${DEPENDENCY}_CXX_FLAGS)
			string(REPLACE ";" " " TEMP "${${DEPENDENCY}_CXXFLAGS}")
			set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TEMP}")
		endif()
	else()
		message(FATAL_ERROR "'${DEPENDENCY}' not found!")
	endif()
endmacro()

macro(do_require_all_dependencies TGT_DIR TGT_NAME RESULT)

	if(EXISTS "${TGT_DIR}/dependencies/${TGT_NAME}.txt")
		file(STRINGS
			"${TGT_DIR}/dependencies/${TGT_NAME}.txt"
			TGT_DEPENDENCIES
		)
		foreach(DEPENDENCY ${TGT_DEPENDENCIES})
			if(${${DEPENDENCY}_FOUND})
				do_use_single_dependency(${TGT_NAME} ${DEPENDENCY})
			else()
				message(
					STATUS
					"Skipping '${TGT_NAME}' "
					"because '${DEPENDENCY}' not found."
				)
				set(${RESULT} false)
			endif()
		endforeach()
	endif()

	file(GLOB REQ_FILES "${TGT_DIR}/requirements/${TGT_NAME}.*.txt")

	foreach(REQ_FILE ${REQ_FILES})
		file(STRINGS "${REQ_FILE}" TGT_REQUIREMENTS)
		foreach(REQUIREMENT_LIST ${TGT_REQUIREMENTS})
			set(ONE_OF_REQUIREMENTS_FOUND false)
			foreach(REQUIREMENT ${REQUIREMENT_LIST})
				if(NOT (NO_${REQUIREMENT}) OR (NOT ${NO_${REQUIREMENT}}))
					set(ONE_OF_REQUIREMENTS_FOUND true)
				endif()
			endforeach()

			if(NOT ${ONE_OF_REQUIREMENTS_FOUND})
				message(
					STATUS
					"Skipping '${TGT_NAME}' "
					"because '${REQUIREMENT_LIST}' not implemented properly."
				)
				set(${RESULT} false)
				break()
			endif()
		endforeach()
	endforeach()

endmacro(do_require_all_dependencies)

macro(require_all_dependencies TGT_NAME RESULT)
	do_require_all_dependencies(
		"${CMAKE_CURRENT_SOURCE_DIR}"
		"${TGT_NAME}"
		"${RESULT}"
	)
endmacro(require_all_dependencies)

# adds all required libraries to an exe
# also creates a dependency between the exe
# and any textures it is using
macro(add_all_dependencies TGT_NAME)
	if("${ARGN}" STREQUAL "")
		set(TARGET_NAME "${TGT_NAME}")
	else()
		set(TARGET_NAME "${ARGN}")
	endif()
	if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/${TGT_NAME}.txt")
		file(STRINGS
			"${CMAKE_CURRENT_SOURCE_DIR}/dependencies/${TGT_NAME}.txt"
			TGT_DEPENDENCIES
		)
		foreach(DEPENDENCY ${TGT_DEPENDENCIES})
			if(${DEPENDENCY}_LIBRARIES)
				target_link_libraries(${TARGET_NAME} ${${DEPENDENCY}_LIBRARIES})
			endif()
		endforeach()
	endif()

	if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/resources/${TGT_NAME}.tex.txt")
		file(STRINGS
			"${CMAKE_CURRENT_SOURCE_DIR}/resources/${TGT_NAME}.tex.txt"
			TGT_TEXTURES
		)
		foreach(TEXTURE ${TGT_TEXTURES})
			add_dependencies("${TARGET_NAME}" "texture-${TEXTURE}")
		endforeach()
	endif()

	if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/resources/${TGT_NAME}.model.txt")
		file(STRINGS
			"${CMAKE_CURRENT_SOURCE_DIR}/resources/${TGT_NAME}.model.txt"
			TGT_MODELS
		)
		foreach(MODEL ${TGT_MODELS})
			add_dependencies("${TARGET_NAME}" "model-${MODEL}")
		endforeach()
	endif()
endmacro(add_all_dependencies)

