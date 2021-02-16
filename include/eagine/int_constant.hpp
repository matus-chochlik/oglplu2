/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_INT_CONSTANT_HPP
#define EAGINE_INT_CONSTANT_HPP

#include "identifier_t.hpp"
#include <type_traits>

namespace eagine {

template <bool B>
using bool_constant = std::integral_constant<bool, B>;

template <int I>
using int_constant = std::integral_constant<int, I>;

template <unsigned U>
using unsigned_constant = std::integral_constant<unsigned, U>;

template <std::size_t S>
using size_constant = std::integral_constant<std::size_t, S>;

template <identifier_t Id>
using id_constant = std::integral_constant<identifier_t, Id>;

} // namespace eagine

#endif // EAGINE_INT_CONSTANT_HPP
