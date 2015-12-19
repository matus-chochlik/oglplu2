/**
 *  @file eagine/type_traits.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_TYPE_TRAITS_1509260923_HPP
#define EAGINE_TYPE_TRAITS_1509260923_HPP

#include <type_traits>
#include <eagine/type_traits_fixes.hpp>

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
