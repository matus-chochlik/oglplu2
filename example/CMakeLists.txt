# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

# install example
function(eagine_install_example TARGET_NAME)
	install(
		TARGETS ${TARGET_NAME}
		DESTINATION share/oglplus/examples
	)
endfunction()

add_subdirectory("eagine")
add_subdirectory("eglplus")
add_subdirectory("oalplus")
add_subdirectory("oglplus")
add_subdirectory("combined")
add_subdirectory("application")
