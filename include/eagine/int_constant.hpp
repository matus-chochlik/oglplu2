/**
 *  @file eagine/int_constant.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_INT_CONSTANT_1509260923_HPP
#define EAGINE_INT_CONSTANT_1509260923_HPP

#include "std/type_traits.hpp"

namespace eagine {

template <bool B>
using bool_constant = std::integral_constant<bool, B>;

template <int I>
using int_constant = std::integral_constant<int, I>;

template <unsigned U>
using unsigned_constant = std::integral_constant<unsigned, U>;

template <std::size_t S>
using size_constant = std::integral_constant<std::size_t, S>;

} // namespace eagine

#endif // include guard
