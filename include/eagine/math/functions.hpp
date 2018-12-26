/**
 *  @file eagine/math/functions.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_FUNCTIONS_HPP
#define EAGINE_MATH_FUNCTIONS_HPP

#include "constants.hpp"
#include <cassert>
#include <cmath>
#include <type_traits>

namespace eagine {
namespace math {
//------------------------------------------------------------------------------
template <typename T>
static constexpr inline auto sign(T x) noexcept {
    return (x < 0) ? T(-1) : T(1);
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr inline T minimum(T a, T b) noexcept {
    return a < b ? a : b;
}
//------------------------------------------------------------------------------
template <typename T, typename... P>
static constexpr inline T minimum(T a, T b, T c, P... d) noexcept {
    return minimum(minimum(a, b), c, d...);
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr inline T maximum(T a, T b) noexcept {
    return a > b ? a : b;
}
//------------------------------------------------------------------------------
template <typename T, typename... P>
static constexpr inline T maximum(T a, T b, T c, P... d) noexcept {
    return maximum(maximum(a, b), c, d...);
}
//------------------------------------------------------------------------------
template <typename T, typename Min, typename Max>
static constexpr inline auto clamp(T x, Min min, Max max) noexcept {
    return x < T(min) ? T(min) : x > T(max) ? T(max) : x;
}
//------------------------------------------------------------------------------
template <typename T, typename S, typename E>
static constexpr inline auto ramp(T x, S start, E end) noexcept {
    return (clamp(x, start, end) - start) / (end - start);
}
//------------------------------------------------------------------------------
template <typename T, typename A>
static constexpr inline auto blend(T v1, T v2, A alpha) noexcept {
    return v1 * alpha + v2 * (1 - alpha);
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr inline auto inverse_logistic(T x) noexcept {
    using std::log;
    return log(x) - log(1 - x);
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr inline auto logistic(T x) noexcept {
    using std::exp;
    return 1 / (1 + exp(-x));
}
//------------------------------------------------------------------------------
template <typename T, typename C>
static constexpr inline auto sigmoid01(T x, C c) noexcept {
    return logistic(c * invLogistic(x));
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr inline auto sigmoid01(T x) noexcept {
    return sigmoid01(x, 2);
}
//------------------------------------------------------------------------------
template <typename T>
static inline auto sine_sigmoid01(T x) {

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdouble-promotion"
#endif
    using std::cos;
    return (1 - cos(x * pi)) / 2;
#ifdef __clang__
#pragma clang diagnostic pop
#endif
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr inline auto sine_wave01(T x) noexcept {
    using std::sin;
    return (sin(2 * pi * x) + 1) / 2;
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr inline auto cosine_wave01(T x) noexcept {
    using std::cos;
    return (cos(2 * pi * x) + 1) / 2;
}
//------------------------------------------------------------------------------
template <typename T, typename U = T>
static constexpr inline auto saw(T x, U u = T(1)) noexcept {
    using std::fmod;
    return fmod(x, u);
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr inline std::enable_if_t<std::is_integral_v<T>, T> factorial(
  T n) noexcept {
    return n > 0 ? n * factorial(n - 1) : 1;
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr inline std::enable_if_t<std::is_integral_v<T>, T> binomial(
  T n, T k) noexcept {
    return ((n >= 0) && (k >= 0) && (k <= n))
             ? (factorial(n) / (factorial(k) * factorial(n - k)))
             : 0;
}
//------------------------------------------------------------------------------
template <typename T, int N>
struct bezier_t {
private:
    static constexpr T _coef(int m, int i, T t) noexcept {
        using std::pow;
        return T(binomial(m, i) * pow(t, i) * pow(1 - t, m - i));
    }

    static constexpr T _calc(int, int, T) noexcept {
        return 0;
    }

    template <typename... P>
    static constexpr T _calc(int m, int i, T t, T f, P... r) noexcept {
        return f * _coef(m, i, t) + _calc(m, i + 1, t, r...);
    }

public:
    template <typename... P, typename = std::enable_if_t<sizeof...(P) == N>>
    constexpr inline T operator()(T t, P... p) noexcept {
        return _calc(N - 1, 0, t, p...);
    }
};
//------------------------------------------------------------------------------
template <typename T, typename... P>
static constexpr inline T bezier(T t, P... p) noexcept {
    return bezier_t<T, sizeof...(P)>()(t, p...);
}
//------------------------------------------------------------------------------
} // namespace math
} // namespace eagine

#endif // EAGINE_MATH_FUNCTIONS_HPP
