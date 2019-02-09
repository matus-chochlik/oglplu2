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
#include "functions.hpp"
#include "primitives.hpp"
#include "vector.hpp"
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
  const line<T, V>& ray,
  const std::pair<optionally_valid<T>, optionally_valid<T>>& ts) {
    using E = optionally_valid<vector<T, 3, V>>;
    using R = std::pair<E, E>;
    return R{
      std::get<0>(ts) ? E{ray.point_at(std::get<0>(ts).value_anyway()), true}
                      : E{},
      std::get<1>(ts) ? E{ray.point_at(std::get<1>(ts).value_anyway()), true}
                      : E{},
    };
}
//------------------------------------------------------------------------------
template <typename T, bool V>
std::pair<optionally_valid<T>, optionally_valid<T>>
line_sphere_intersection_params(
  const line<T, V>& ray, const sphere<T, V>& sph) noexcept {
    return _line_sphere_intersection_t(
      _line_sphere_intersection_a(ray.direction(), ray.origin() - sph.center()),
      _line_sphere_intersection_b(
        ray.direction(), ray.origin() - sph.center(), sph.radius()),
      _line_sphere_intersection_d(ray.direction()));
}
//------------------------------------------------------------------------------
template <typename T, bool V>
static constexpr inline std::
  pair<optionally_valid<vector<T, 3, V>>, optionally_valid<vector<T, 3, V>>>
  line_sphere_intersection(
    const line<T, V>& ray, const sphere<T, V>& sph) noexcept {
    return _line_sphere_intersection_p(
      ray, line_sphere_intersection_params(ray, sph));
}
//------------------------------------------------------------------------------
template <typename T, bool V>
static constexpr inline auto _line_sphere_intersection_n_p(
  const line<T, V>& ray,
  const std::pair<optionally_valid<T>, optionally_valid<T>>& ts) {
    using R = optionally_valid<vector<T, 3, V>>;
    using std::abs;

    return std::get<0>(ts)
             ? std::get<1>(ts)
                 ? abs(std::get<0>(ts).value_anyway()) <
                       abs(std::get<1>(ts).value_anyway())
                     ? R{ray.point_at(std::get<0>(ts).value_anyway()), true}
                     : R{ray.point_at(std::get<1>(ts).value_anyway()), true}
                 : R{ray.point_at(std::get<0>(ts).value_anyway()), true}
             : R{};
}
//------------------------------------------------------------------------------
template <typename T, bool V>
static constexpr inline optionally_valid<vector<T, 3, V>>
nearest_line_sphere_intersection(
  const line<T, V>& ray, const sphere<T, V>& sph) noexcept {
    return _line_sphere_intersection_n_p(
      ray, line_sphere_intersection_params(ray, sph));
}
//------------------------------------------------------------------------------
template <typename T, bool V>
static inline optionally_valid<T> _line_triangle_intersection_p(
  const line<T, V>& ray, const triangle<T, V>& tri) noexcept {

    const vector<T, 3, V> h = cross(ray.direction(), tri.ac());
    const T a = dot(tri.ab(), h);

    if(const auto ia = reciprocal(a)) {
        const T f = ia.value_anyway();
        const vector<T, 3, V> s = ray.origin() - tri.a();
        const T u = f * dot(s, h);

        if((u >= T(0)) && (u <= T(1))) {
            const vector<T, 3, V> q = cross(s, tri.ab());
            const T v = f * dot(ray.direction(), q);

            if((v >= T(0)) && (u + v <= T(1))) {
                const T t = f * dot(tri.ac(), q);
                return {t, t >= T(0)};
            }
        }
    }
    return {};
}
//------------------------------------------------------------------------------
template <typename T, bool V>
static inline optionally_valid<vector<T, 3, V>> line_triangle_intersection(
  const line<T, V>& ray, const triangle<T, V>& tri) noexcept {
    if(const auto t = _line_triangle_intersection_p(ray, tri)) {
        return {ray.origin() + ray.direction() * t.value_anyway(), true};
    }
    return {};
}
//------------------------------------------------------------------------------
} // namespace math
} // namespace eagine

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif // EAGINE_MATH_INTERSECTION_HPP
