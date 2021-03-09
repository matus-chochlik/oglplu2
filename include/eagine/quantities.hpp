/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

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

/// @brief Alias for type storing duration values in seconds.
/// @ingroup units
/// @see seconds_
template <typename T>
using seconds_t = tagged_quantity<T, units::second>;

/// @brief Creates a tagged quantity storing value in seconds.
/// @ingroup units
template <typename T>
static constexpr auto seconds_(T value) noexcept -> seconds_t<T> {
    return seconds_t<T>{value};
}

/// @brief Alias for type storing angle values in radians.
/// @ingroup units
/// @see radians_
template <typename T>
using radians_t = tagged_quantity<T, units::radian>;

/// @brief Creates a tagged quantity storing value in radians.
/// @ingroup units
/// @see degrees_
/// @see right_angles_
/// @see right_angle_
/// @see turns_
template <typename T>
static constexpr auto radians_(T value) noexcept -> radians_t<T> {
    return radians_t<T>{value};
}

/// @brief Creates a tagged quantity in units of right angle.
/// @ingroup units
/// @see radians_
/// @see degrees_
/// @see right_angle_
/// @see turns_
template <typename T>
static constexpr auto right_angles_(T value) noexcept {
    return radians_(value * math::pi / 2);
}

/// @brief Creates a tagged quantity a right angle value.
/// @ingroup units
/// @see radians_
/// @see degrees_
/// @see right_angles_
/// @see turns_
static constexpr auto right_angle_() noexcept {
    return right_angles_(1);
}

/// @brief Creates a tagged quantity in full turn units.
/// @ingroup units
/// @see radians_
/// @see degrees_
/// @see right_angle_
/// @see right_angles_
template <typename T>
static constexpr auto turns_(T value) noexcept {
    return radians_(value * math::pi * 2);
}

template <
  typename Qty,
  typename = std::enable_if_t<is_convertible_quantity_v<Qty, units::radian>>>
static constexpr auto sin(const Qty& qty) {
    using std::sin;
    return sin(value(convert_to<units::radian>(qty)));
}

template <
  typename Qty,
  typename = std::enable_if_t<is_convertible_quantity_v<Qty, units::radian>>>
static constexpr auto cos(const Qty& qty) {
    using std::cos;
    return cos(value(convert_to<units::radian>(qty)));
}

template <
  typename Qty,
  typename = std::enable_if_t<is_convertible_quantity_v<Qty, units::radian>>>
static constexpr auto tan(const Qty& qty) {
    using std::tan;
    return tan(value(convert_to<units::radian>(qty)));
}

template <typename T>
static constexpr auto arcsin(T x) {
    using std::asin;
    return make_tagged_quantity<units::radian>(asin(x));
}

template <typename T>
static constexpr auto arccos(T x) {
    using std::acos;
    return make_tagged_quantity<units::radian>(acos(x));
}

template <typename T>
static constexpr auto arctan(T y, T x) {
    using std::atan2;
    return make_tagged_quantity<units::radian>(atan2(y, x));
}

/// @brief Alias for type storing angle values in degrees.
/// @ingroup units
/// @see degrees_
template <typename T>
using degrees_t = tagged_quantity<T, units::degree>;

/// @brief Creates a tagged quantity storing value in degrees.
/// @ingroup units
/// @see radians_
/// @see right_angles_
/// @see right_angle_
/// @see turns_
template <typename T>
static constexpr auto degrees_(T value) noexcept -> degrees_t<T> {
    return degrees_t<T>{value};
}

/// @brief Alias for type storing temperature values in kelvins.
/// @ingroup units
/// @see kelvins_
template <typename T>
using kelvins_t = tagged_quantity<T, units::kelvin>;

/// @brief Creates a tagged quantity storing value in kelvins.
/// @ingroup units
template <typename T>
static constexpr auto kelvins_(T value) noexcept -> kelvins_t<T> {
    return kelvins_t<T>{value};
}

} // namespace eagine

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif // EAGINE_QUANTITIES_HPP
