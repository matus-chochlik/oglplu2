/**
 *  @file oglplus/error/format.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_ERROR_FORMAT_HPP
#define OGLPLUS_ERROR_FORMAT_HPP

#include "../utils/string_span.hpp"
#include "fwd.hpp"
#include "info.hpp"
#include <iosfwd>

namespace oglplus {

string_view error_message(error&);

std::ostream& format_error_info(
  const error_info& info,
  string_view msg_str,
  string_view fmt_str,
  string_view n_a_str,
  std::ostream& out);

std::ostream& format_error_info(
  const error_info& info,
  string_view msg_str,
  string_view fmt_str,
  std::ostream& out);

std::ostream& format_error_info(
  const error_info& info, string_view fmt_str, std::ostream& out);

std::ostream& format_error(
  error& err, string_view fmt_str, string_view n_a_str, std::ostream& out);

std::ostream& format_error(error& err, string_view fmt_str, std::ostream& out);

} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/error/format.inl>
#endif

#endif // OGLPLUS_ERROR_FORMAT_HPP
