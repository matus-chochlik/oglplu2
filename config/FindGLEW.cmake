#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
if(${WIN32})
	eagine_common_find_module(GLEW glew GL/glew.h glew32)
else()
	eagine_common_find_module(GLEW glew GL/glew.h GLEW)
endif()
