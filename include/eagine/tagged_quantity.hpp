/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_TAGGED_QUANTITY_HPP
#define EAGINE_TAGGED_QUANTITY_HPP

#include "compare.hpp"
#include "diagnostic.hpp"
#include "units/default.hpp"
#include "units/traits.hpp"
#include <cmath>
#include <type_traits>

#ifdef __clang__
EAGINE_DIAG_PUSH()
EAGINE_DIAG_OFF(double-promotion)
#endif

namespace eagine {
//------------------------------------------------------------------------------
template <typename T, typename U>
class tagged_quantity;
//------------------------------------------------------------------------------
template <typename U, typename T>
static constexpr auto make_tagged_quantity(const T& value)
  -> tagged_quantity<T, U>;
//------------------------------------------------------------------------------
/// @brief Value of type T with a specified unit or tag type U.
/// @ingroup units
template <typename T, typename U>
class tagged_quantity {
public:
    /// @brief Alias for the unit type.
    using unit_type = U;

    /// @brief Alias for the value type.
    using value_type = T;

    /// @brief Default constructor.
    tagged_quantity() = default;

    /// @brief Explicit constructor initializing the value.
    explicit constexpr tagged_quantity(T v) noexcept
      : _v{std::move(v)} {}

    /// @brief Converting constructor from another tagged quantity.
    template <
      typename X,
      typename UX,
      typename = std::enable_if_t<
        std::is_convertible_v<X, T> && units::is_convertible_v<UX, U>>>
    constexpr tagged_quantity(const tagged_quantity<X, UX>& tq) noexcept
      : _v(T(units::value_conv<UX, U>()(tq._v))) {}

    /// @brief Conversion to a quantity in another unit type.
    template <
      typename UX,
      typename = std::enable_if_t<units::is_convertible_v<U, UX>>>
    constexpr auto to() const noexcept {
        return make_tagged_quantity<UX>(units::value_conv<U, UX>()(_v));
    }

    /// @brief Returns the value.
    constexpr auto value() const noexcept -> T {
        return _v;
    }

    /// @brief Returns the unit.
    static constexpr auto unit() noexcept -> U {
        return {};
    }

    /// Brief Explicit conversion of the value to the specified.
    template <
      typename X,
      typename = std::enable_if_t<std::is_convertible_v<T, X>>>
    explicit constexpr operator X() const noexcept {
        return X(_v);
    }

    /// @brief Addition of another tagged quantity.
    template <
      typename X,
      typename UX,
      typename = std::enable_if_t<
        std::is_convertible_v<X, T> && units::is_convertible_v<UX, U>>>
    auto operator+=(const tagged_quantity<X, UX>& q) noexcept -> auto& {
        _v += T(units::value_conv<UX, U>()(q._v));
        return *this;
    }

    /// @brief Subtraction of another tagged quantity.
    template <
      typename X,
      typename UX,
      typename = std::enable_if_t<
        std::is_convertible_v<X, T> && units::is_convertible_v<UX, U>>>
    auto operator-=(const tagged_quantity<X, UX>& q) noexcept -> auto& {
        _v -= T(units::value_conv<UX, U>()(q._v));
        return *this;
    }

private:
    static_assert(std::is_arithmetic_v<T>);
    T _v{};

    template <typename, typename>
    friend class tagged_quantity;
};
//------------------------------------------------------------------------------
// is_tagged_quantity
template <typename T>
struct is_tagged_quantity : std::false_type {};
//------------------------------------------------------------------------------
template <typename T>
using is_tagged_quantity_t = typename is_tagged_quantity<T>::type;
//------------------------------------------------------------------------------
template <typename T>
constexpr bool is_tagged_quantity_v = is_tagged_quantity<T>::value;
//------------------------------------------------------------------------------
template <typename T, typename U>
struct is_tagged_quantity<tagged_quantity<T, U>> : std::true_type {};
//------------------------------------------------------------------------------
// is_convertible_quantity
template <typename Qty, typename Unit>
struct is_convertible_quantity : std::false_type {};
//------------------------------------------------------------------------------
template <typename Q, typename U>
using is_convertible_quantity_t = typename is_convertible_quantity<Q, U>::type;
//------------------------------------------------------------------------------
template <typename Q, typename U>
constexpr bool is_convertible_quantity_v = is_convertible_quantity<Q, U>::value;
//------------------------------------------------------------------------------
template <typename T, typename QU, typename U>
struct is_convertible_quantity<tagged_quantity<T, QU>, U>
  : units::is_convertible<QU, U> {};
//------------------------------------------------------------------------------
// make_tagged_quantity
template <typename U, typename T>
static constexpr auto make_tagged_quantity(const T& value)
  -> tagged_quantity<T, U> {
    return tagged_quantity<T, U>{value};
}
//------------------------------------------------------------------------------
template <
  typename T,
  typename U,
  typename = std::enable_if_t<
    !is_tagged_quantity_v<T> && !units::is_unit_v<T> && units::is_unit_v<U>>>
static constexpr auto operator*(const T& v, U) {
    return make_tagged_quantity<U>(v);
}
//------------------------------------------------------------------------------
template <typename UX, typename T, typename U>
static inline auto convert_to(const tagged_quantity<T, U>& q) {
    return q.template to<UX>();
}
//------------------------------------------------------------------------------
template <typename T, typename U>
static inline auto value(const tagged_quantity<T, U>& q) {
    return q.value();
}
//------------------------------------------------------------------------------
template <typename T1, typename U1, typename T2, typename U2>
struct equal_cmp<tagged_quantity<T1, U1>, tagged_quantity<T2, U2>> {

    static_assert(units::is_convertible_v<U2, U1>);

    static constexpr auto check(
      const tagged_quantity<T1, U1>& l,
      const tagged_quantity<T2, U2>& r) noexcept -> bool {
        return are_equal(value(l), units::value_conv<U2, U1>()(value(r)));
    }
};
//------------------------------------------------------------------------------
/// @brief Equality comparison.
/// @ingroup units
/// @relates tagged_quantity
template <typename T1, typename U1, typename T2, typename U2>
constexpr auto
operator==(const tagged_quantity<T1, U1>& a, const tagged_quantity<T2, U2>& b)
  -> std::enable_if_t<units::is_convertible_v<U2, U1>, bool> {
    return value(a) == units::value_conv<U2, U1>()(value(b));
}
//------------------------------------------------------------------------------
/// @brief Nonequality comparison.
/// @ingroup units
/// @relates tagged_quantity
template <typename T1, typename U1, typename T2, typename U2>
constexpr auto
operator!=(const tagged_quantity<T1, U1>& a, const tagged_quantity<T2, U2>& b)
  -> std::enable_if_t<units::is_convertible_v<U2, U1>, bool> {
    return value(a) != units::value_conv<U2, U1>()(value(b));
}
//------------------------------------------------------------------------------
/// @brief Less-than comparison.
/// @ingroup units
/// @relates tagged_quantity
template <typename T1, typename U1, typename T2, typename U2>
constexpr auto
operator<(const tagged_quantity<T1, U1>& a, const tagged_quantity<T2, U2>& b)
  -> std::enable_if_t<units::is_convertible_v<U2, U1>, bool> {
    return value(a) < units::value_conv<U2, U1>()(value(b));
}
//------------------------------------------------------------------------------
/// @brief Less-equal comparison.
/// @ingroup units
/// @relates tagged_quantity
template <typename T1, typename U1, typename T2, typename U2>
constexpr auto
operator<=(const tagged_quantity<T1, U1>& a, const tagged_quantity<T2, U2>& b)
  -> std::enable_if_t<units::is_convertible_v<U2, U1>, bool> {
    return value(a) <= units::value_conv<U2, U1>()(value(b));
}
//------------------------------------------------------------------------------
/// @brief Greater-than comparison.
/// @ingroup units
/// @relates tagged_quantity
template <typename T1, typename U1, typename T2, typename U2>
constexpr auto
operator>(const tagged_quantity<T1, U1>& a, const tagged_quantity<T2, U2>& b)
  -> std::enable_if_t<units::is_convertible_v<U2, U1>, bool> {
    return value(a) > units::value_conv<U2, U1>()(value(b));
}
//------------------------------------------------------------------------------
/// @brief Greater-equal comparison.
/// @ingroup units
/// @relates tagged_quantity
template <typename T1, typename U1, typename T2, typename U2>
constexpr auto
operator>=(const tagged_quantity<T1, U1>& a, const tagged_quantity<T2, U2>& b)
  -> std::enable_if_t<units::is_convertible_v<U2, U1>, bool> {
    return value(a) >= units::value_conv<U2, U1>()(value(b));
}
//------------------------------------------------------------------------------
/// @brief Unary plus operator.
/// @ingroup units
/// @relates tagged_quantity
template <typename T, typename U>
constexpr auto operator+(const tagged_quantity<T, U>& a) {
    return a;
}
//------------------------------------------------------------------------------
/// @brief Unary negation operator.
/// @ingroup units
/// @relates tagged_quantity
template <typename T, typename U>
constexpr auto operator-(const tagged_quantity<T, U>& a) {
    return make_tagged_quantity<U>(-value(a));
}
//------------------------------------------------------------------------------
/// @brief Addition operator.
/// @ingroup units
/// @relates tagged_quantity
template <typename T1, typename U1, typename T2, typename U2>
constexpr auto
operator+(const tagged_quantity<T1, U1>& a, const tagged_quantity<T2, U2>& b) {
    using UR = units::add_result_t<U1, U2>;
    return make_tagged_quantity<UR>(
      units::value_conv<U1, UR>()(value(a)) +
      units::value_conv<U2, UR>()(value(b)));
}
//------------------------------------------------------------------------------
/// @brief Subtraction operator.
/// @ingroup units
/// @relates tagged_quantity
template <typename T1, typename U1, typename T2, typename U2>
constexpr auto
operator-(const tagged_quantity<T1, U1>& a, const tagged_quantity<T2, U2>& b) {
    using UR = units::sub_result_t<U1, U2>;
    return make_tagged_quantity<UR>(
      units::value_conv<U1, UR>()(value(a)) -
      units::value_conv<U2, UR>()(value(b)));
}
//------------------------------------------------------------------------------
/// @brief Multiplication operator.
/// @ingroup units
/// @relates tagged_quantity
template <typename T1, typename U1, typename T2, typename U2>
constexpr auto
operator*(const tagged_quantity<T1, U1>& a, const tagged_quantity<T2, U2>& b) {
    using UO1 = units::mul_l_operand_t<U1, U2>;
    using UO2 = units::mul_r_operand_t<U1, U2>;
    using UR = units::mul_result_t<U1, U2>;
    return make_tagged_quantity<UR>(
      units::value_conv<U1, UO1>()(value(a)) *
      units::value_conv<U2, UO2>()(value(b)));
}
//------------------------------------------------------------------------------
/// @brief Multiplication by constant operator.
/// @ingroup units
/// @relates tagged_quantity
template <
  typename T1,
  typename U,
  typename T2,
  typename = std::enable_if_t<!units::is_unit_v<T2> && !is_tagged_quantity_v<T2>>>
constexpr auto operator*(const tagged_quantity<T1, U>& a, const T2& c) {
    return make_tagged_quantity<U>(value(a) * c);
}
//------------------------------------------------------------------------------
/// @brief Multiplication by constant operator.
/// @ingroup units
/// @relates tagged_quantity
template <typename T1, typename T2, typename U>
constexpr auto operator*(const T1& c, const tagged_quantity<T2, U>& a) {
    return make_tagged_quantity<U>(c * value(a));
}
//------------------------------------------------------------------------------
/// @brief Multiplication by unit operator.
/// @ingroup units
/// @relates tagged_quantity
template <
  typename T1,
  typename U1,
  typename U2,
  typename = std::enable_if_t<units::is_unit_v<U2>>>
constexpr auto operator*(const tagged_quantity<T1, U1>& a, U2) {
    return a * make_tagged_quantity<U2>(1);
}
//------------------------------------------------------------------------------
/// @brief Division operator
/// @ingroup units
/// @relates tagged_quantity
template <typename T1, typename U1, typename T2, typename U2>
constexpr auto
operator/(const tagged_quantity<T1, U1>& a, const tagged_quantity<T2, U2>& b) {
    using UO1 = units::div_l_operand_t<U1, U2>;
    using UO2 = units::div_r_operand_t<U1, U2>;
    using UR = units::div_result_t<U1, U2>;
    return make_tagged_quantity<UR>(
      units::value_conv<U1, UO1>()(value(a)) /
      units::value_conv<U2, UO2>()(value(b)));
}
//------------------------------------------------------------------------------
/// @brief Division by constant operator
/// @ingroup units
/// @relates tagged_quantity
template <
  typename T1,
  typename U,
  typename T2,
  typename = std::enable_if_t<!units::is_unit_v<T2>>>
constexpr auto operator/(const tagged_quantity<T1, U>& a, const T2& c) {
    return make_tagged_quantity<U>((1.F * value(a)) / c);
}
//------------------------------------------------------------------------------
/// @brief Constant division operator
/// @ingroup units
/// @relates tagged_quantity
template <
  typename T1,
  typename U1,
  typename U2,
  typename = std::enable_if_t<units::is_unit_v<U2>>>
constexpr auto operator/(const tagged_quantity<T1, U1>& a, U2) {
    return a / make_tagged_quantity<U2>(1);
}
//------------------------------------------------------------------------------
} // namespace eagine

#ifdef __clang__
EAGINE_DIAG_POP()
#endif

#endif // EAGINE_TAGGED_QUANTITY_HPP
