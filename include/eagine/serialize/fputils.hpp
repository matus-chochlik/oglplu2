/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_SERIALIZE_FPUTILS_HPP
#define EAGINE_SERIALIZE_FPUTILS_HPP

#include "../is_within_limits.hpp"
#include "../type_identity.hpp"
#include <cmath>
#include <cstdint>
#include <limits>
#include <tuple>
#include <type_traits>

namespace eagine::fputils {
//------------------------------------------------------------------------------
template <typename F>
struct get_decompose_types;

template <>
struct get_decompose_types<float> {
    using fraction_type = std::uint32_t;
    using exponent_type = std::int16_t;
};

template <>
struct get_decompose_types<double> {
    using fraction_type = std::uint64_t;
    using exponent_type = std::int32_t;
};

template <>
struct get_decompose_types<long double> {
    using fraction_type = std::uintmax_t;
    using exponent_type = std::int64_t;
};

template <typename f>
using decompose_fraction_t = typename get_decompose_types<f>::fraction_type;

template <typename F>
using decompose_exponent_t = typename get_decompose_types<F>::exponent_type;

template <typename F>
using decomposed_t =
  std::tuple<decompose_fraction_t<F>, decompose_exponent_t<F>>;
//------------------------------------------------------------------------------
template <typename F>
constexpr auto max_fraction(type_identity<F> = {}) noexcept
  -> std::enable_if_t<std::is_floating_point_v<F>, decompose_fraction_t<F>> {
    using T = decompose_fraction_t<F>;
    return 1 + std::numeric_limits<T>::max() / T(2);
}
//------------------------------------------------------------------------------
template <typename F>
constexpr inline auto decompose(F f, type_identity<F> = {}) noexcept
  -> decomposed_t<F> {
    switch(std::fpclassify(f)) {
        case FP_ZERO:
            return {0, std::signbit(f) ? 1 : 0};
        case FP_INFINITE:
            return {0, std::signbit(f) ? 3 : 2};
        case FP_NAN:
            return {0, std::signbit(f) ? 5 : 4};
        default:
            break;
    }
    int exp = 0;
    const auto one = F(1);
    const auto two = F(2);
    const auto fr2 = std::fabs(std::frexp(f, &exp) * two);
    EAGINE_ASSERT(fr2 >= one && fr2 < two);
    return {
      (static_cast<decompose_fraction_t<F>>((fr2 - one) * max_fraction<F>())
       << 1U) |
        ((f < 0) ? 0x1U : 0x0U),
      limit_cast<decompose_exponent_t<F>>(exp)};
}
//------------------------------------------------------------------------------
template <typename F>
constexpr inline auto
compose(const decomposed_t<F>& f, type_identity<F> = {}) noexcept -> F {
    const auto fre = std::get<0>(f);
    if(EAGINE_UNLIKELY(!fre)) {
        switch(std::get<1>(f)) {
            case 0:
                return static_cast<F>(0);
            case 1:
                return -static_cast<F>(0);
            case 2:
                return std::numeric_limits<F>::infinity();
            case 3:
                return -std::numeric_limits<F>::infinity();
            case 4:
                return std::numeric_limits<F>::quiet_NaN();
            case 5:
                return -std::numeric_limits<F>::quiet_NaN();
            default:
                break;
        }
    }
    const auto one = F(1);
    const auto two = F(2);
    const auto half = one / two;
    const auto sig = ((fre & 0x1U) == 0x1U) ? -one : one;
    const auto frc = F(fre >> 1U) / max_fraction<F>() / two;
    return sig * std::ldexp(frc + half, limit_cast<int>(std::get<1>(f)));
}
//------------------------------------------------------------------------------
} // namespace eagine::fputils

#endif // EAGINE_SERIALIZE_FPUTILS_HPP
