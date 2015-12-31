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
#include "units/trivial.hpp"
#include <cmath>

namespace eagine {

// seconds
template <typename T>
using seconds_t = tagged_quantity<T, units::second>;

template <typename T>
static inline
seconds_t<T>
seconds_(T value)
noexcept
{
	return seconds_t<T>{value};
}

// radians
template <typename T>
using radians_t = tagged_quantity<T, units::radian>;

template <typename T>
static inline
radians_t<T>
radians_(T value)
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

// degrees
template <typename T>
using degrees_t = tagged_quantity<T, units::degree>;

template <typename T>
static inline
degrees_t<T>
degrees_(T value)
noexcept
{
	return degrees_t<T>{value};
}

} // namespace eagine

#endif // include guard
