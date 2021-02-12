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

#include "../memory/span.hpp"
#include "../valid_if/decl.hpp"
#include "constants.hpp"
#include <cassert>
#include <cmath>
#include <type_traits>

namespace eagine::math {
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto is_positive_power_of_2(T value) noexcept
  -> std::enable_if_t<std::is_integral_v<T>, bool> {
    using U = std::make_unsigned_t<T>;
    return (value > 0) && ((U(value) & (U(value) - 1)) == 0);
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto greatest_common_divisor(T l, T r) noexcept
  -> std::enable_if_t<std::is_integral_v<T>, T> {
    return (r == T(0)) ? l : greatest_common_divisor(r, T(l % r));
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto signum(T x) noexcept {
    return (x < 0) ? T(-1) : T(1);
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto minimum(T a, T b) noexcept {
    return a < b ? a : b;
}
//------------------------------------------------------------------------------
template <typename T, typename... P>
static constexpr auto minimum(T a, T b, T c, P... d) noexcept {
    return minimum(minimum(a, b), c, d...);
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto maximum(T a, T b) noexcept {
    return a > b ? a : b;
}
//------------------------------------------------------------------------------
template <typename T, typename... P>
static constexpr auto maximum(T a, T b, T c, P... d) noexcept {
    return maximum(maximum(a, b), c, d...);
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto ratio(T a, T b) noexcept -> optionally_valid<T> {
    if(b > T(0) || (b < T(0))) {
        return {a / b, true};
    }
    return {};
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto reciprocal(T x) noexcept -> optionally_valid<T> {
    using std::abs;
    if(abs(x) > std::numeric_limits<T>::epsilon()) {
        return {T(1) / x, true};
    }
    return {};
}
//------------------------------------------------------------------------------
template <typename T, typename Min, typename Max>
static constexpr auto clamp(T x, Min min, Max max) noexcept {
    return x < T(min) ? T(min) : x > T(max) ? T(max) : x;
}
//------------------------------------------------------------------------------
template <typename T, typename S, typename E>
static constexpr auto ramp(T x, S start, E end) noexcept {
    return (clamp(x, start, end) - start) / (end - start);
}
//------------------------------------------------------------------------------
template <typename T, typename A>
static constexpr auto blend(T v1, T v2, A alpha) noexcept {
    return v1 * alpha + v2 * (1 - alpha);
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto inverse_logistic(T x) noexcept {
    using std::log;
    return log(x) - log(1 - x);
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto logistic(T x) noexcept {
    using std::exp;
    return 1 / (1 + exp(-x));
}
//------------------------------------------------------------------------------
template <typename T, typename C>
static constexpr auto sigmoid01(T x, C c) noexcept {
    return logistic(c * inverse_logistic(x));
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto sigmoid01(T x) noexcept {
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
static constexpr auto sine_wave01(T x) noexcept {
    using std::sin;
    return (sin(2 * pi * x) + 1) / 2;
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto cosine_wave01(T x) noexcept {
    using std::cos;
    return (cos(2 * pi * x) + 1) / 2;
}
//------------------------------------------------------------------------------
template <typename T, typename U = T>
static constexpr auto saw(T x, U u = T(1)) noexcept {
    using std::fmod;
    return fmod(x, u);
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto factorial(T n) noexcept
  -> std::enable_if_t<std::is_integral_v<T>, T> {
    return n > 0 ? n * factorial(n - 1) : 1;
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto binomial(T n, T k) noexcept
  -> std::enable_if_t<std::is_integral_v<T>, T> {
    return ((n >= 0) && (k >= 0) && (k <= n))
             ? (factorial(n) / (factorial(k) * factorial(n - k)))
             : 0;
}
//------------------------------------------------------------------------------
template <typename T, int N>
struct bezier_t {
private:
    static constexpr auto _coef(int m, int i, T t) noexcept {
        using std::pow;
        return T(binomial(m, i) * pow(t, i) * pow(1 - t, m - i));
    }

    static constexpr auto _calc(int, int, T) noexcept {
        return T{0};
    }

    template <typename... P>
    static constexpr auto _calc(int m, int i, T t, T f, P... r) noexcept -> T {
        return f * _coef(m, i, t) + _calc(m, i + 1, t, r...);
    }

    template <typename P, typename S, std::size_t... I>
    static constexpr auto _calc(
      int m,
      int i,
      T t,
      memory::basic_span<const T, P, S> p,
      std::index_sequence<I...>) noexcept -> T {
        return _calc(m, i, t, p[I]...);
    }

public:
    template <typename... P, typename = std::enable_if_t<sizeof...(P) == N>>
    constexpr auto operator()(T t, P... p) const noexcept {
        return _calc(N - 1, 0, t, p...);
    }

    template <typename P, typename S>
    auto operator()(T t, memory::basic_span<const T, P, S> p) const noexcept {
        return _calc(N - 1, 0, t, p, std::make_index_sequence<N>());
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::math

#endif // EAGINE_MATH_FUNCTIONS_HPP
