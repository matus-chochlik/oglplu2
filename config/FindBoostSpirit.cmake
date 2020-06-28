#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#

option(USE_BOOST_SPIRIT "Use the Boost.Spirit library if available" On)

add_library(EAGopt::BoostSpirit INTERFACE IMPORTED)
if(${USE_BOOST_SPIRIT})
	set(EAGINE_USE_BOOST_SPIRIT 1)
else()
	set(EAGINE_USE_BOOST_SPIRIT 0)
endif()

