#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
# install the headers
install(
	DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION include
)
# install the implementation inline files
install(
	DIRECTORY ${PROJECT_SOURCE_DIR}/implement/
	DESTINATION include
)
# install the generated headers
install(
	DIRECTORY ${PROJECT_BINARY_DIR}/include/
	DESTINATION include
)
#
function(eagine_install_example TARGET_NAME)
	install(
		TARGETS ${TARGET_NAME}
		OPTIONAL EXCLUDE_FROM_ALL
		COMPONENT examples
		DESTINATION share/oglplus/examples
	)
endfunction()
