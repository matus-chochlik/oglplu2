/**
 *  @file eagine/make_array.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MAKE_ARRAY_1509260923_HPP
#define EAGINE_MAKE_ARRAY_1509260923_HPP

#include <type_traits>
#include <array>
#include "all_are_same.hpp"

namespace eagine {

// TODO use std::experimental::make_array when available

template <typename T, typename ... P>
static constexpr inline
std::enable_if_t<
	all_are_same<T, P...>::value,
	std::array<T, 1+sizeof...(P)>
> make_array(T v, P ... p)
{
	return {{std::move(v), std::move(p)...}};
}

} // namespace eagine

#endif // include guard
