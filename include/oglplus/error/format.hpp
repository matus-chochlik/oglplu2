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

#include "fwd.hpp"
#include "info.hpp"
#include "../utils/cstr_ref.hpp"
#include <iosfwd>

namespace oglplus {

cstr_ref error_message(error&);

std::ostream& format_error_info(
	const error_info& info,
	const cstr_ref& msg_str,
	const cstr_ref& fmt_str,
	const cstr_ref& n_a_str,
 	std::ostream& out
);

std::ostream& format_error_info(
	const error_info& info,
	const cstr_ref& msg_str,
	const cstr_ref& fmt_str,
 	std::ostream& out
);

std::ostream& format_error_info(
	const error_info& info,
	const cstr_ref& fmt_str,
 	std::ostream& out
);

std::ostream& format_error(
	error& err,
	const cstr_ref& fmt_str,
	const cstr_ref& n_a_str,
 	std::ostream& out
);

std::ostream& format_error(
	error& err,
	const cstr_ref& fmt_str,
 	std::ostream& out
);

} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/error/format.inl>
#endif

#endif // include guard
