/**
 *  @file eagine/tagged_quantity.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_TAGGED_QUANTITY_1509260923_HPP
#define EAGINE_TAGGED_QUANTITY_1509260923_HPP

#include "std/type_traits.hpp"
#include "units/default.hpp"
#include "units/traits.hpp"
#include <cmath>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdouble-promotion"
#endif

namespace eagine {

template <typename T, typename U>
class tagged_quantity;

template <typename U, typename T>
static constexpr tagged_quantity<T, U> make_tagged_quantity(const T& value);

template <typename T, typename U>
class tagged_quantity {
private:
    static_assert(std::is_arithmetic_v<T>, "");
    T _v;

    template <typename, typename>
    friend class tagged_quantity;

public:
    typedef U unit_type;
    typedef T value_type;

    tagged_quantity() = default;

    explicit constexpr inline tagged_quantity(T v) noexcept
      : _v(v) {
    }

    template <
      typename X,
      typename UX,
      typename = std::enable_if_t<
        std::is_convertible_v<X, T> && units::is_convertible_v<UX, U>>>
    constexpr inline tagged_quantity(const tagged_quantity<X, UX>& tq) noexcept
      : _v(T(units::value_conv<UX, U>()(tq._v))) {
    }

    template <
      typename UX,
      typename = std::enable_if_t<units::is_convertible_v<U, UX>>>
    constexpr inline auto to() const noexcept {
        return make_tagged_quantity<UX>(units::value_conv<U, UX>()(_v));
    }

    constexpr inline T value() const noexcept {
        return _v;
    }

    template <
      typename X,
      typename = std::enable_if_t<std::is_convertible_v<T, X>>>
    explicit constexpr inline operator X() const noexcept {
        return X(_v);
    }

    template <
      typename X,
      typename UX,
      typename = std::enable_if_t<
        std::is_convertible_v<X, T> && units::is_convertible_v<UX, U>>>
    tagged_quantity& operator+=(const tagged_quantity<X, UX>& q) noexcept {
        _v += units::value_conv<UX, U>()(q._v);
        return *this;
    }

    template <
      typename X,
      typename UX,
      typename = std::enable_if_t<
        std::is_convertible_v<X, T> && units::is_convertible_v<UX, U>>>
    tagged_quantity& operator-=(const tagged_quantity<X, UX>& q) noexcept {
        _v -= units::value_conv<UX, U>()(q._v);
        return *this;
    }
};

// is_tagged_quantity
template <typename T>
struct is_tagged_quantity : std::false_type {};

template <typename T>
using is_tagged_quantity_t = typename is_tagged_quantity<T>::type;

template <typename T>
constexpr bool is_tagged_quantity_v = is_tagged_quantity<T>::value;

template <typename T, typename U>
struct is_tagged_quantity<tagged_quantity<T, U>> : std::true_type {};

// is_convertible_quantity
template <typename Qty, typename Unit>
struct is_convertible_quantity : std::false_type {};

template <typename Q, typename U>
using is_convertible_quantity_t = typename is_convertible_quantity<Q, U>::type;

template <typename Q, typename U>
constexpr bool is_convertible_quantity_v = is_convertible_quantity<Q, U>::value;

template <typename T, typename QU, typename U>
struct is_convertible_quantity<tagged_quantity<T, QU>, U>
  : units::is_convertible<QU, U> {};

// make_tagged_quantity
template <typename U, typename T>
static constexpr inline tagged_quantity<T, U>
make_tagged_quantity(const T& value) {
    return tagged_quantity<T, U>{value};
}

template <
  typename T,
  typename U,
  typename = std::enable_if_t<
    !is_tagged_quantity_v<T> && !units::is_unit_v<T> && units::is_unit_v<U>>>
static constexpr inline auto operator*(const T& v, U) {
    return make_tagged_quantity<U>(v);
}

template <typename UX, typename T, typename U>
static inline auto convert_to(const tagged_quantity<T, U>& q) {
    return q.template to<UX>();
}

template <typename T, typename U>
static inline T value(const tagged_quantity<T, U>& q) {
    return q.value();
}

template <typename T1, typename U1, typename T2, typename U2>
constexpr inline std::enable_if_t<units::is_convertible_v<U2, U1>, bool>
operator==(const tagged_quantity<T1, U1>& a, const tagged_quantity<T2, U2>& b) {
    return value(a) == units::value_conv<U2, U1>()(value(b));
}

template <typename T1, typename U1, typename T2, typename U2>
constexpr inline std::enable_if_t<units::is_convertible_v<U2, U1>, bool>
operator!=(const tagged_quantity<T1, U1>& a, const tagged_quantity<T2, U2>& b) {
    return value(a) != units::value_conv<U2, U1>()(value(b));
}

template <typename T1, typename U1, typename T2, typename U2>
constexpr inline std::enable_if_t<units::is_convertible_v<U2, U1>, bool>
operator<(const tagged_quantity<T1, U1>& a, const tagged_quantity<T2, U2>& b) {
    return value(a) < units::value_conv<U2, U1>()(value(b));
}

template <typename T1, typename U1, typename T2, typename U2>
constexpr inline std::enable_if_t<units::is_convertible_v<U2, U1>, bool>
operator<=(const tagged_quantity<T1, U1>& a, const tagged_quantity<T2, U2>& b) {
    return value(a) <= units::value_conv<U2, U1>()(value(b));
}

template <typename T1, typename U1, typename T2, typename U2>
constexpr inline std::enable_if_t<units::is_convertible_v<U2, U1>, bool>
operator>(const tagged_quantity<T1, U1>& a, const tagged_quantity<T2, U2>& b) {
    return value(a) > units::value_conv<U2, U1>()(value(b));
}

template <typename T1, typename U1, typename T2, typename U2>
constexpr inline std::enable_if_t<units::is_convertible_v<U2, U1>, bool>
operator>=(const tagged_quantity<T1, U1>& a, const tagged_quantity<T2, U2>& b) {
    return value(a) >= units::value_conv<U2, U1>()(value(b));
}

template <typename T, typename U>
constexpr inline auto operator+(const tagged_quantity<T, U>& a) {
    return a;
}

template <typename T, typename U>
constexpr inline auto operator-(const tagged_quantity<T, U>& a) {
    return make_tagged_quantity<U>(-value(a));
}

template <typename T1, typename U1, typename T2, typename U2>
constexpr inline auto
operator+(const tagged_quantity<T1, U1>& a, const tagged_quantity<T2, U2>& b) {
    typedef units::add_result_t<U1, U2> UR;
    return make_tagged_quantity<UR>(
      units::value_conv<U1, UR>()(value(a)) +
      units::value_conv<U2, UR>()(value(b)));
}

template <typename T1, typename U1, typename T2, typename U2>
constexpr inline auto
operator-(const tagged_quantity<T1, U1>& a, const tagged_quantity<T2, U2>& b) {
    typedef units::sub_result_t<U1, U2> UR;
    return make_tagged_quantity<UR>(
      units::value_conv<U1, UR>()(value(a)) -
      units::value_conv<U2, UR>()(value(b)));
}

template <typename T1, typename U1, typename T2, typename U2>
constexpr inline auto
operator*(const tagged_quantity<T1, U1>& a, const tagged_quantity<T2, U2>& b) {
    typedef units::mul_l_operand_t<U1, U2> UO1;
    typedef units::mul_r_operand_t<U1, U2> UO2;
    typedef units::mul_result_t<U1, U2> UR;
    return make_tagged_quantity<UR>(
      units::value_conv<U1, UO1>()(value(a)) *
      units::value_conv<U2, UO2>()(value(b)));
}

template <
  typename T1,
  typename U,
  typename T2,
  typename =
    std::enable_if_t<!units::is_unit_v<T2> && !is_tagged_quantity_v<T2>>>
constexpr inline auto operator*(const tagged_quantity<T1, U>& a, const T2& c) {
    return make_tagged_quantity<U>(value(a) * c);
}

template <typename T1, typename T2, typename U>
constexpr inline auto operator*(const T1& c, const tagged_quantity<T2, U>& a) {
    return make_tagged_quantity<U>(c * value(a));
}

template <
  typename T1,
  typename U1,
  typename U2,
  typename = std::enable_if_t<units::is_unit_v<U2>>>
constexpr inline auto operator*(const tagged_quantity<T1, U1>& a, U2) {
    return a * make_tagged_quantity<U2>(1);
}

template <typename T1, typename U1, typename T2, typename U2>
constexpr inline auto
operator/(const tagged_quantity<T1, U1>& a, const tagged_quantity<T2, U2>& b) {
    typedef units::div_l_operand_t<U1, U2> UO1;
    typedef units::div_r_operand_t<U1, U2> UO2;
    typedef units::div_result_t<U1, U2> UR;
    return make_tagged_quantity<UR>(
      units::value_conv<U1, UO1>()(value(a)) /
      units::value_conv<U2, UO2>()(value(b)));
}

template <
  typename T1,
  typename U,
  typename T2,
  typename = std::enable_if_t<!units::is_unit_v<T2>>>
constexpr inline auto operator/(const tagged_quantity<T1, U>& a, const T2& c) {
    return make_tagged_quantity<U>((1.f * value(a)) / c);
}

template <
  typename T1,
  typename U1,
  typename U2,
  typename = std::enable_if_t<units::is_unit_v<U2>>>
constexpr inline auto operator/(const tagged_quantity<T1, U1>& a, U2) {
    return a / make_tagged_quantity<U2>(1);
}

} // namespace eagine

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif // include guard
