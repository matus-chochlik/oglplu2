#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
# make the info.py script
set(INFO_JSON "${PROJECT_BINARY_DIR}/config/info.json")
file(WRITE ${INFO_JSON} "{")
#
# GL_INIT_LIBS
file(APPEND ${INFO_JSON} "\"gl_init_libs\": [")
set(FIRST TRUE)
foreach(GL_INIT_LIB GLFW3 GLUT GLX)
	if(${GL_INIT_LIB}_FOUND)
		if(${FIRST})
			set(FIRST FALSE)
		else()
			file(APPEND ${INFO_JSON} ",")
		endif()
		file(APPEND ${INFO_JSON} "\"${GL_INIT_LIB}\"")
	endif()
endforeach()
file(APPEND ${INFO_JSON} "]")
#
# GL_API_LIBS
file(APPEND ${INFO_JSON} ",\"gl_api_libs\": [")
set(FIRST TRUE)
foreach(GL_API_LIB GLCOREARB_H GLEW)
	if(${GL_API_LIB}_FOUND)
		if(${FIRST})
			set(FIRST FALSE)
		else()
			file(APPEND ${INFO_JSON} ",")
		endif()
		file(APPEND ${INFO_JSON} "\"${GL_API_LIB}\"")
	endif()
endforeach()
file(APPEND ${INFO_JSON} "]")
#
file(APPEND ${INFO_JSON} "}") # root
