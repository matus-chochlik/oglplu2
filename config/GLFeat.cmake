#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#

macro(gl_lib_feat_detection GL_LIB FEATURE_NAME)
	gl_feature_detection_helper(${GL_LIB} ${FEATURE_NAME} FEAT)

	if(HAS_${GL_LIB}_${FEATURE_NAME})
		message(STATUS "Found ${GL_LIB} feature: ${FEATURE_NAME}")
	else()
		if(DEBUG_GL_FEAT_ERROR)
			if("${DEBUG_GL_FEAT_ERROR}" STREQUAL "${FEATURE_NAME}")
				message(FATAL_ERROR "Error detecting GL feature ${FEATURE_NAME}")
			endif()
		endif()
	endif()
endmacro()

macro(gl_lib_ext_detection GL_LIB EXTENSION_VENDOR EXTENSION_NAME)

	set(CONFIG_EXT_ID ${EXTENSION_VENDOR}_${EXTENSION_NAME})
	set(CONFIG_QUERY_GL_EXT ${GL_LIB}_${CONFIG_EXT_ID})
	set(CONFIG_QUERY_GL_EXT_VENDOR ${EXTENSION_VENDOR})
	set(CONFIG_QUERY_GL_EXT_NAME ${EXTENSION_NAME})

	gl_feature_detection_helper(${GL_LIB} ${CONFIG_EXT_ID} EXT)

	if(HAS_${GL_LIB}_${CONFIG_EXT_ID})
		message(STATUS "Found ${GL_LIB} extension: ${CONFIG_EXT_ID}")
	else()
		file(APPEND ${FIX_GL_EXTENSION_HPP} "#ifdef GL_${CONFIG_EXT_ID}\n")
		file(APPEND ${FIX_GL_EXTENSION_HPP} "#undef GL_${CONFIG_EXT_ID}\n")
		file(APPEND ${FIX_GL_EXTENSION_HPP} "#endif //GL_${CONFIG_EXT_ID}\n")
		if(DEBUG_GL_FEAT_ERROR)
			if("${DEBUG_GL_FEAT_ERROR}" STREQUAL "${CONFIG_EXT_ID}")
				message(FATAL_ERROR "Error detecting GL extension ${CONFIG_EXT_ID}")
			endif()
		endif()
	endif()

	unset(CONFIG_QUERY_GL_EXT)
	unset(CONFIG_QUERY_GL_EXT_VENDOR)
	unset(CONFIG_QUERY_GL_EXT_NAME)
	unset(CONFIG_EXT_ID)

endmacro()

set(
	FIX_GL_EXTENSION_HPP
	${PROJECT_BINARY_DIR}/include/oglplus/config/fix_gl_extension.hpp
)

configure_file(
	${PROJECT_SOURCE_DIR}/config/oglplus/config/fix_gl_extension.hpp.in
	${FIX_GL_EXTENSION_HPP}
)

# features
gl_lib_feat_detection(GL geometry_shader)

# extensions
gl_lib_ext_detection(GL ARB shader_subroutine)
gl_lib_ext_detection(GL ARB shader_atomic_counters)
gl_lib_ext_detection(GL ARB geometry_shader4)
gl_lib_ext_detection(GL ARB tessellation_shader)
gl_lib_ext_detection(GL ARB separate_shader_objects)
gl_lib_ext_detection(GL ARB shading_language_include)
gl_lib_ext_detection(GL ARB transform_feedback2)
gl_lib_ext_detection(GL ARB viewport_array)
gl_lib_ext_detection(GL ARB compatibility)
gl_lib_ext_detection(GL ARB gpu_shader_fp64)
gl_lib_ext_detection(GL ARB direct_state_access)
gl_lib_ext_detection(GL EXT direct_state_access)
gl_lib_ext_detection(GL KHR debug)
gl_lib_ext_detection(GL NV path_rendering)
gl_lib_ext_detection(GL NV copy_image)

file(APPEND ${FIX_GL_EXTENSION_HPP} "#endif //include guard\n")

macro(glew_ext_detection EXTENSION_VENDOR EXTENSION_NAME)
	if(GLEW_FOUND)
		gl_lib_ext_detection(GLEW ${EXTENSION_VENDOR} ${EXTENSION_NAME})
	endif()
endmacro()

glew_ext_detection(ARB compatibility)
glew_ext_detection(EXT direct_state_access)
glew_ext_detection(ARB debug_output)
glew_ext_detection(ATI meminfo)
glew_ext_detection(NV path_rendering)
glew_ext_detection(AMD performance_monitor)
