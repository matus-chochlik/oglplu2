#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#

foreach(RES CA_CERT ROUTER_CERT BRIDGE_CERT)
	if(NOT EAGINE_EMBED_${RES})
		if(DEFINED ENV{EAGINE_EMBED_${RES}})
			if(EXISTS $ENV{EAGINE_EMBED_${RES}})
				set(EAGINE_EMBED_${RES} "$ENV{EAGINE_EMBED_${RES}}")
			else()
				message(
					WARNING
					"$ENV{EAGINE_EMBED_${RES}} exported but does not exist"
				)
			endif()
		endif()
	endif()

	if(EAGINE_EMBED_${RES})
		if(EXISTS ${EAGINE_EMBED_${RES}})
			message(
				STATUS
				"using ${EAGINE_EMBED_${RES}} as embedded ${RES}"
			)
		else()
			message(
				WARNING
				"${EAGINE_EMBED_${RES}} set but does not exist"
			)
			set(EAGINE_EMBED_${RES}"${EAGINE_EMPTY_FILE}")
		endif()
	else()
		message(
			STATUS
			"using empty file as embedded ${RES}"
		)
		set(EAGINE_EMBED_${RES} "${EAGINE_EMPTY_FILE}")
	endif()
endforeach()
