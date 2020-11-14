#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
set(
	EAGINE_EMBED_GENERATOR
	"${PROJECT_SOURCE_DIR}/config/tools/embed_generator"
)

include("${PROJECT_SOURCE_DIR}/config/EmbedCommon.cmake")

file(WRITE "${PROJECT_BINARY_DIR}/empty" "")
set(EAGINE_EMPTY_FILE "${PROJECT_BINARY_DIR}/empty")
