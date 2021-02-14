/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_MATH_INTERPOLATE_HPP
#define EAGINE_MATH_INTERPOLATE_HPP

#include "constants.hpp"
#include "functions.hpp"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdouble-promotion"
#endif

namespace eagine::math {
//------------------------------------------------------------------------------
/// @brief Linear interpolation between @p a and @p b.
/// @ingroup math
/// @see lerp
template <typename T, typename C>
static inline auto interpolate_linear(const T& a, const T& b, C coef) {
    return T((1 - coef) * a + coef * b);
}
//------------------------------------------------------------------------------
/// @brief Same as interpolate_linear.
/// @ingroup math
/// @see interpolate_linear
template <typename T, typename C>
static inline auto lerp(const T& a, const T& b, C coef) {
    return interpolate_linear(a, b, coef);
}
//------------------------------------------------------------------------------
/// @brief Linear interpolation with @p coef transformed by sine_sigmoid01.
/// @ingroup math
/// @see interpolate_linear
/// @see sine_sigmoid01
template <typename T, typename C>
static inline auto smooth_lerp(const T& a, const T& b, C coef) {
    return lerp(a, b, sine_sigmoid01(coef));
}
//------------------------------------------------------------------------------
/// @brief Smooth interpolation between negative @p a and @p a.
/// @ingroup math
/// @see smooth_lerp
template <typename T, typename C>
static inline auto smooth_oscillate(const T& a, C coef) {
    return smooth_lerp(-a, a, coef);
}
//------------------------------------------------------------------------------
} // namespace eagine::math

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif // EAGINE_MATH_INTERPOLATE_HPP
