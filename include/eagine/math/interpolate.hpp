/**
 *  @file eagine/math/interpolate.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_INTERPOLATE_HPP
#define EAGINE_MATH_INTERPOLATE_HPP

#include "constants.hpp"
#include "functions.hpp"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdouble-promotion"
#endif

namespace eagine {
namespace math {
//------------------------------------------------------------------------------
template <typename T, typename C>
static inline T interpolate_linear(const T& a, const T& b, C coef) {
    return T((1 - coef) * a + coef * b);
}
//------------------------------------------------------------------------------
template <typename T, typename C>
static inline auto lerp(const T& a, const T& b, C coef) {
    return interpolate_linear(a, b, coef);
}
//------------------------------------------------------------------------------
template <typename T, typename C>
static inline auto smooth_lerp(const T& a, const T& b, C coef) {
    return lerp(a, b, sine_sigmoid01(coef));
}
//------------------------------------------------------------------------------
template <typename T, typename C>
static inline auto smooth_oscillate(const T& a, C coef) {
    return smooth_lerp(-a, a, coef);
}
//------------------------------------------------------------------------------
} // namespace math
} // namespace eagine

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif // EAGINE_MATH_INTERPOLATE_HPP
