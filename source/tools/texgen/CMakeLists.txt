# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

add_executable(
	oglplus-texgen
	input_stream.cpp
	token_info.cpp
	token_stream.cpp
	tokenizer.cpp
	main.cpp
)

if(INVOKE_CLANG_TIDY)
	set_target_properties(
		oglplus-texgen
		PROPERTIES CXX_CLANG_TIDY "${INVOKE_CLANG_TIDY}"
	)
endif()
