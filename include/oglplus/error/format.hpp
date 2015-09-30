/**
 *  @file oglplus/error/format.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_ERROR_FORMAT_1509260923_HPP
#define OGLPLUS_ERROR_FORMAT_1509260923_HPP

#include "info.hpp"
#include "../utils/string_view.hpp"
#include <iosfwd>

namespace oglplus {

std::ostream& format_info(
	const error_info& info,
	const cstring_view<>& fmt_str,
	std::ostream& out
);

} // namespace oglplus

#include <oglplus/error/format.inl>

#endif // include guard
