#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
option(EAGINE_CONFIG_SET_LOW_PROFILE "Set the EAGINE_LOW_PROFILE switch in site_config.hpp." Off)

if(EAGINE_CONFIG_SET_LOW_PROFILE)
	set(EAGINE_CONFIG_SET_LOW_PROFILE 1)
	if(${EAGINE_LOW_PROFILE})
		set(EAGINE_LOW_PROFILE 1)
	else()
		set(EAGINE_LOW_PROFILE 0)
	endif()
else()
	set(EAGINE_CONFIG_SET_LOW_PROFILE 0)
	set(EAGINE_LOW_PROFILE 0)
endif()

