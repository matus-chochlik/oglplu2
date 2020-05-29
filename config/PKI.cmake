#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#

if(NOT EAGINE_EMBED_CA_CERT)
	if(DEFINED ENV{EAGINE_EMBED_CA_CERT})
		if(EXISTS $ENV{EAGINE_EMBED_CA_CERT})
			set(EAGINE_EMBED_CA_CERT "$ENV{EAGINE_EMBED_CA_CERT}")
		else()
			message(
				WARNING
				"$ENV{EAGINE_EMBED_CA_CERT} exported but does not exist"
			)
		endif()
	endif()
endif()

if(EAGINE_EMBED_CA_CERT)
	if(EXISTS ${EAGINE_EMBED_CA_CERT})
		message(
			STATUS
			"using ${EAGINE_EMBED_CA_CERT} as embedded CA certificate"
		)
	else()
		message(
			WARNING
			"${EAGINE_EMBED_CA_CERT} set but does not exist"
		)
		set(EAGINE_EMBED_CA_CERT "${EAGINE_EMPTY_FILE}")
	endif()
else()
	message(
		STATUS
		"using empty file as embedded CA certificate"
	)
	set(EAGINE_EMBED_CA_CERT "${EAGINE_EMPTY_FILE}")
endif()

