#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
find_program(
	CLANG_TIDY_EXE
	NAMES clang-tidy-7 clang-tidy
	DOC "Path to clang-tidy executable"
)

