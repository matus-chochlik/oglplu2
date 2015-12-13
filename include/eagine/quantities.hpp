/**
 *  @file eagine/quantities.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_QUANTITIES_1509260923_HPP
#define EAGINE_QUANTITIES_1509260923_HPP

#include "tagged_quantity.hpp"
#include <cmath>

namespace eagine {

struct radians_tag;

template <typename T>
using radians_t = tagged_quantity<T, radians_tag>;

template <typename T>
static inline
radians_t<T>
radians(T value)
noexcept
{
	return radians_t<T>{value};
}

template <typename T>
static constexpr inline
auto sin(radians_t<T> v)
{
	using std::sin;
	return sin(T(v));
}

template <typename T>
static constexpr inline
auto cos(radians_t<T> v)
{
	using std::cos;
	return cos(T(v));
}

template <typename T>
static constexpr inline
auto tan(radians_t<T> v)
{
	using std::tan;
	return tan(T(v));
}

struct degrees_tag;

template <typename T>
using degrees_t = tagged_quantity<T, degrees_tag>;

template <typename T>
static inline
degrees_t<T>
degrees(T value)
noexcept
{
	return degrees_t<T>{value};
}

} // namespace eagine

#endif // include guard
