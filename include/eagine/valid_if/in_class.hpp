/// @file eagine/valid_if/in_class.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_VALID_IF_IN_CLASS_HPP
#define EAGINE_VALID_IF_IN_CLASS_HPP

#include "decl.hpp"

namespace eagine {

// in_class_valid_if
template <
  typename T,
  typename C,
  typename Policy,
  typename DoLog = typename Policy::do_log>
using in_class_valid_if = basic_valid_if<T, Policy, DoLog, const C&>;

} // namespace eagine

#endif // EAGINE_VALID_IF_IN_CLASS_HPP
