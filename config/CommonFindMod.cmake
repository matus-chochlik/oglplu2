#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
include(FindPkgConfig)

macro(eagine_common_import_lib PREFIX PC_NAME HEADER LIBRARY)
	unset(${PREFIX}_FOUND)
	unset(${PREFIX}_DEFINITIONS)
	unset(${PREFIX}_INCLUDE_DIRS)
	unset(${PREFIX}_LIBRARY_DIRS)
	unset(${PREFIX}_LIBRARIES)

	if(PKG_CONFIG_FOUND)
		pkg_check_modules(PC_${PREFIX} QUIET ${PC_NAME})
		if(PC_${PREFIX}_FOUND)
			add_library(${PREFIX}::${PREFIX} INTERFACE IMPORTED)
			set_target_properties(
				${PREFIX}::${PREFIX} PROPERTIES
				INTERFACE_COMPILE_OPTIONS
				"${PC_${PREFIX}_CFLAGS_OTHER}"
			)
			set_target_properties(
				${PREFIX}::${PREFIX} PROPERTIES
				INTERFACE_COMPILE_OPTIONS
				"${PC_${PREFIX}_INCLUDE_DIRECTORIES}"
			)
			set_target_properties(
				${PREFIX}::${PREFIX} PROPERTIES
				INTERFACE_LINK_OPTIONS
				"${PC_${PREFIX}_LDFLAGS_OTHER}"
			)
			set_target_properties(
				${PREFIX}::${PREFIX} PROPERTIES
				INTERFACE_LINK_DIRECTORIES
				"${PC_${PREFIX}_LIBRARY_DIRS}"
			)
			set_target_properties(
				${PREFIX}::${PREFIX} PROPERTIES
				INTERFACE_LINK_LIBRARIES
				"${PC_${PREFIX}_LIBRARIES}"
			)
			message(STATUS
				"Found ${PREFIX}: "
				"${PC_${PREFIX}_INCLUDE_DIRS} "
				"${PC_${PREFIX}_LIBRARIES}"
			)
			set(${PREFIX}_FOUND 1)
		endif()
		unset(PC_${PREFIX}_CFLAGS)
		unset(PC_${PREFIX}_CFLAGS_OTHER)
		unset(PC_${PREFIX}_INCLUDE_DIRS)
		unset(PC_${PREFIX}_LDFLAGS)
		unset(PC_${PREFIX}_LDFLAGS_OTHER)
		unset(PC_${PREFIX}_LIBRARY_DIRS)
		unset(PC_${PREFIX}_LIBRARIES)
	endif()

	if(NOT ${PREFIX}_FOUND)
		# TODO: try manually
	endif()

	if(NOT ${PREFIX}_FOUND)
		set(${PREFIX}_FOUND 0)
	endif()

	unset(${PREFIX}_DEFINITIONS)
	unset(${PREFIX}_INCLUDE_DIRS)
	unset(${PREFIX}_LIBRARY_DIRS)
	unset(${PREFIX}_LIBRARIES)
endmacro()
