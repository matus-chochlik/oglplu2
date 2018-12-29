/**
 *  @file eagine/math/intersection.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_INTERSECTION_HPP
#define EAGINE_MATH_INTERSECTION_HPP

#include "../valid_if/nonnegative.hpp"
#include "../valid_if/positive.hpp"
#include "primitives.hpp"
#include "vector.hpp"
#include <cmath>
#include <utility>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdouble-promotion"
#endif

namespace eagine {
namespace math {
//------------------------------------------------------------------------------
template <typename T, bool V>
static constexpr inline T _line_sphere_intersection_a(
  vector<T, 3, V> ld, vector<T, 3, V> oc) noexcept {
    return -T(2) * dot(ld, oc);
}
//------------------------------------------------------------------------------
template <typename T, bool V>
static constexpr inline valid_if_positive<T> _line_sphere_intersection_d(
  vector<T, 3, V> ld) noexcept {
    return T(2) * dot(ld, ld);
}
//------------------------------------------------------------------------------
template <typename T, bool V>
static constexpr inline valid_if_nonnegative<T> _line_sphere_intersection_b(
  vector<T, 3, V> ld, vector<T, 3, V> oc, T sr) noexcept {
    using std::pow;
    return T(
      pow(2 * dot(ld, oc), 2) - 4 * dot(ld, ld) * (dot(oc, oc) - pow(sr, 2)));
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr inline auto _line_sphere_intersection_t(
  T a, valid_if_nonnegative<T> b, valid_if_positive<T> d) noexcept {
    using std::sqrt;
    using R = std::pair<optionally_valid<T>, optionally_valid<T>>;
    return (b && d)
             ? (b.value_anyway() > T(0))
                 ? R{{(a + sqrt(b.value_anyway())) / d.value_anyway(), true},
                     {(a - sqrt(b.value_anyway())) / d.value_anyway(), true}}
                 : R{{a / d.value_anyway(), true}, {}}
             : R{};
}
//------------------------------------------------------------------------------
template <typename T, bool V>
static constexpr inline auto _line_sphere_intersection_p(
  const line<T, V>& l,
  const std::pair<optionally_valid<T>, optionally_valid<T>>& ts) {
    using E = optionally_valid<vector<T, 3, V>>;
    using R = std::pair<E, E>;
    return R{
      std::get<0>(ts) ? E{l.point_at(std::get<0>(ts).value_anyway()), true}
                      : E{},
      std::get<1>(ts) ? E{l.point_at(std::get<1>(ts).value_anyway()), true}
                      : E{},
    };
}
//------------------------------------------------------------------------------
template <typename T, bool V>
static constexpr inline std::pair<
  optionally_valid<vector<T, 3, V>>,
  optionally_valid<vector<T, 3, V>>>
line_sphere_intersection(const line<T, V>& l, const sphere<T, V>& s) noexcept {
    return _line_sphere_intersection_p(
      l,
      _line_sphere_intersection_t(
        _line_sphere_intersection_a(l.direction(), l.origin() - s.center()),
        _line_sphere_intersection_b(
          l.direction(), l.origin() - s.center(), s.radius()),
        _line_sphere_intersection_d(l.direction())));
}
//------------------------------------------------------------------------------
} // namespace math
} // namespace eagine

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif // EAGINE_MATH_INTERSECTION_HPP
