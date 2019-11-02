#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
if(CONFIG_SET_LOW_PROFILE)
	set(CONFIG_SET_LOW_PROFILE 1)
	if(${LOW_PROFILE})
		set(LOW_PROFILE 1)
	else()
		set(LOW_PROFILE 0)
	endif()
else()
	set(CONFIG_SET_LOW_PROFILE 0)
	set(LOW_PROFILE 0)
endif()

file(
	WRITE "${PROJECT_BINARY_DIR}/cfg-LOW_PROFILE"
	"${LOW_PROFILE}"
)

