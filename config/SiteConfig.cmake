#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
configure_file(
	${PROJECT_SOURCE_DIR}/config/eagine/config/site.hpp.in
	${PROJECT_BINARY_DIR}/include/eagine/config/site.hpp
)
configure_file(
	${PROJECT_SOURCE_DIR}/config/oglplus/config/site.hpp.in
	${PROJECT_BINARY_DIR}/include/oglplus/config/site.hpp
)
configure_file(
	${PROJECT_SOURCE_DIR}/config/oalplus/config/site.hpp.in
	${PROJECT_BINARY_DIR}/include/oalplus/config/site.hpp
)

