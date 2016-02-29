#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#

function(gl_feature_detection GL_LIB QUERY QUERY_KIND)

	# if there is a specific template for the detection
	if(EXISTS ${PROJECT_SOURCE_DIR}/config/gl/has_${GL_LIB}_${QUERY}.cpp.in)
		# use it
		configure_file(
			${PROJECT_SOURCE_DIR}/config/gl/has_${GL_LIB}_${QUERY}.cpp.in
			${PROJECT_BINARY_DIR}/gl/has_${GL_LIB}_${QUERY}.cpp
		)
	# if there is a specific template for the detection
	elseif(EXISTS ${PROJECT_SOURCE_DIR}/config/gl/has_${GL_LIB}_${QUERY}.cpp)
		# use it
		configure_file(
			${PROJECT_SOURCE_DIR}/config/gl/has_${GL_LIB}_${QUERY}.cpp
			${PROJECT_BINARY_DIR}/gl/has_${GL_LIB}_${QUERY}.cpp
		)
	else()
		# otherwise use the generic template
		configure_file(
			${PROJECT_SOURCE_DIR}/config/gl/has_${GL_LIB}_${QUERY_KIND}.cpp.in
			${PROJECT_BINARY_DIR}/gl/has_${GL_LIB}_${QUERY}.cpp
		)
	endif()

	if(EXISTS ${PROJECT_SOURCE_DIR}/config/gl/has_${GL_LIB}_${QUERY_KIND}.ipp.in)
		configure_file(
			${PROJECT_SOURCE_DIR}/config/gl/has_${GL_LIB}_${QUERY_KIND}.ipp.in
			${PROJECT_BINARY_DIR}/gl/has_${GL_LIB}_${QUERY}.ipp
		)
	endif()

	set(CONFIG_REQUIRED_INCLUDE_DIRS
		"${OGLPLUS_GL_INCLUDE_DIRS};"
		"${PROJECT_SOURCE_DIR}/include;"
		"${PROJECT_SOURCE_DIR}/implement;"
		"${PROJECT_SOURCE_DIR}/source/utils;"
		"${PROJECT_BINARY_DIR}/include"
	)
	set(CONFIG_REQUIRED_LIBRARIES "${OGLPLUS_GL_LIBRARIES}")

	foreach(INIT_LIB GLX GLFW3 GLFW SDL GLUT)
		if(OGLPLUS_USE_${INIT_LIB})
			if(${INIT_LIB}_INCLUDE_DIRS)
				set(CONFIG_REQUIRED_INCLUDE_DIRS
					"${CONFIG_REQUIRED_INCLUDE_DIRS};"
					"${${INIT_LIB}_INCLUDE_DIRS}"
				)
			endif()

			if(${INIT_LIB}_LIBRARY_DIRS)
				set(CONFIG_REQUIRED_LIBRARY_DIRS
					"${CONFIG_REQUIRED_INCLUDE_DIRS};"
					"${${INIT_LIB}_LIBRARY_DIRS}"
				)
			endif()

			if(${INIT_LIB}_LIBRARIES)
				set(CONFIG_REQUIRED_LIBRARIES
					"${CONFIG_REQUIRED_LIBRARIES};"
					"${${INIT_LIB}_LIBRARIES}"
				)
			endif()
			break()
		endif()
	endforeach()

	try_run(
		RUNS_WITH_${GL_LIB}_${QUERY} COMPILED_WITH_${GL_LIB}_${QUERY}
		"${PROJECT_BINARY_DIR}/gl"
		"${PROJECT_BINARY_DIR}/gl/has_${GL_LIB}_${QUERY}.cpp"
		COMPILE_DEFINITIONS ${CPP_STD_COMPILER_SWITCH}
		CMAKE_FLAGS
			"-DINCLUDE_DIRECTORIES:STRING=${CONFIG_REQUIRED_INCLUDE_DIRS} "
			"-DLIBRARY_DIRECTORIES:STRING=${CONFIG_REQUIRED_LIBRARY_DIRS} "
			"-DLINK_DIRECTORIES:STRING=${CONFIG_REQUIRED_LIBRARY_DIRS} "
			"-DLINK_LIBRARIES:STRING=${CONFIG_REQUIRED_LIBRARIES} "
		COMPILE_OUTPUT_VARIABLE TRY_COMPILE_OUTPUT
		RUN_OUTPUT_VARIABLE TRY_RUN_OUTPUT
	)
	if(COMPILED_WITH_${GL_LIB}_${QUERY})
		if(RUNS_WITH_${GL_LIB}_${QUERY} EQUAL 0)
			set(HAS_${GL_LIB}_${QUERY} TRUE PARENT_SCOPE)
		else()
			if(COMPILE_ONLY_GL_TESTS)
				set(HAS_${GL_LIB}_${QUERY} TRUE PARENT_SCOPE)
			else()
				set(NO_${GL_LIB}_${QUERY} TRUE PARENT_SCOPE)
			endif()
		endif()
	else()
		set(NO_${GL_LIB}_${QUERY} TRUE PARENT_SCOPE)
	endif()

	if(
		(DEBUG_GL_VER_ERROR AND ("${QUERY_KIND}" STREQUAL "VER")) OR
		(DEBUG_GL_EXT_ERROR AND ("${QUERY_KIND}" STREQUAL "EXT"))
	)
		message(STATUS "testing: ${GL_LIB}_${QUERY}")
		if(NOT COMPILED_WITH_${GL_LIB}_${QUERY})
			message(WARNING "try_compile: ${TRY_COMPILE_OUTPUT}")
		endif()
		if(NOT RUNS_WITH_${GL_LIB}_${QUERY} EQUAL 0)
			message(WARNING "try_run: ${TRY_RUN_OUTPUT}")
		endif()
	endif()

	unset(TRY_COMPILE_OUTPUT)
	unset(TRY_RUN_OUTPUT)

	unset(RUNS_WITH_${GL_LIB}_${QUERY})
	unset(COMPILED_WITH_${GL_LIB}_${QUERY})
endfunction()

configure_file(
	${PROJECT_SOURCE_DIR}/config/gl/decl_GL_test.ipp.in
	${PROJECT_BINARY_DIR}/gl/decl_GL_test.ipp
)

configure_file(
	${PROJECT_SOURCE_DIR}/config/gl/impl_GL_test.ipp.in
	${PROJECT_BINARY_DIR}/gl/impl_GL_test.ipp
)

