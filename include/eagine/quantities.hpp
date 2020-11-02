/**
 *  @file eagine/quantities.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_QUANTITIES_HPP
#define EAGINE_QUANTITIES_HPP

#include "math/constants.hpp"
#include "tagged_quantity.hpp"
#include "units/trivial.hpp"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdouble-promotion"
#endif

namespace eagine {

// seconds
template <typename T>
using seconds_t = tagged_quantity<T, units::second>;

template <typename T>
static constexpr inline auto seconds_(T value) noexcept {
    return seconds_t<T>{value};
}

// radians
template <typename T>
using radians_t = tagged_quantity<T, units::radian>;

template <typename T>
static constexpr inline auto radians_(T value) noexcept {
    return radians_t<T>{value};
}

template <typename T>
static constexpr inline auto right_angles_(T value) noexcept {
    return radians_(value * math::pi / 2);
}

static constexpr inline auto right_angle_() noexcept {
    return right_angles_(1);
}

template <typename T>
static constexpr inline auto turns_(T value) noexcept {
    return radians_(value * math::pi * 2);
}

template <
  typename Qty,
  typename = std::enable_if_t<is_convertible_quantity_v<Qty, units::radian>>>
static constexpr inline auto sin(const Qty& qty) {
    using std::sin;
    return sin(value(convert_to<units::radian>(qty)));
}

template <
  typename Qty,
  typename = std::enable_if_t<is_convertible_quantity_v<Qty, units::radian>>>
static constexpr inline auto cos(const Qty& qty) {
    using std::cos;
    return cos(value(convert_to<units::radian>(qty)));
}

template <
  typename Qty,
  typename = std::enable_if_t<is_convertible_quantity_v<Qty, units::radian>>>
static constexpr inline auto tan(const Qty& qty) {
    using std::tan;
    return tan(value(convert_to<units::radian>(qty)));
}

template <typename T>
static constexpr inline auto arcsin(T x) {
    using std::asin;
    return make_tagged_quantity<units::radian>(asin(x));
}

template <typename T>
static constexpr inline auto arccos(T x) {
    using std::acos;
    return make_tagged_quantity<units::radian>(acos(x));
}

template <typename T>
static constexpr inline auto arctan(T y, T x) {
    using std::atan2;
    return make_tagged_quantity<units::radian>(atan2(y, x));
}

// degrees
template <typename T>
using degrees_t = tagged_quantity<T, units::degree>;

template <typename T>
static constexpr inline auto degrees_(T value) noexcept {
    return degrees_t<T>{value};
}

// kelvins
template <typename T>
using kelvins_t = tagged_quantity<T, units::kelvin>;

template <typename T>
static constexpr inline auto kelvins_(T value) noexcept {
    return kelvins_t<T>{value};
}

} // namespace eagine

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif // EAGINE_QUANTITIES_HPP
