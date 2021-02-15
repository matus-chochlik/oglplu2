/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
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

namespace eagine::math {
//------------------------------------------------------------------------------
// utils
//------------------------------------------------------------------------------
template <typename T, typename P, typename L>
static inline auto
nearest_ray_param(const std::pair<valid_if<T, P, L>, valid_if<T, P, L>>& params)
  -> valid_if<T, P, L> {

    const auto& t0 = std::get<0>(params);
    const auto& t1 = std::get<1>(params);

    if(t0 >= 0.F) {
        if(t1 >= 0.F) {
            if(t0 < t1) {
                return t0;
            } else {
                return t1;
            }
        } else {
            return t0;
        }
    } else {
        if(t1 >= 0.F) {
            return t1;
        }
    }
    return {};
}
//------------------------------------------------------------------------------
// line-sphere
//------------------------------------------------------------------------------
template <typename T, bool V>
static constexpr auto
_line_sphere_intersection_a(vector<T, 3, V> ld, vector<T, 3, V> oc) noexcept
  -> T {
    return -T(2) * dot(ld, oc);
}
//------------------------------------------------------------------------------
template <typename T, bool V>
static constexpr auto _line_sphere_intersection_d(vector<T, 3, V> ld) noexcept
  -> valid_if_positive<T> {
    return T(2) * dot(ld, ld);
}
//------------------------------------------------------------------------------
template <typename T, bool V>
static constexpr auto _line_sphere_intersection_b(
  vector<T, 3, V> ld,
  vector<T, 3, V> oc,
  T sr) noexcept -> valid_if_nonnegative<T> {
    using std::pow;
    return T(
      pow(2 * dot(ld, oc), 2) - 4 * dot(ld, ld) * (dot(oc, oc) - pow(sr, 2)));
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto _line_sphere_intersection_t(
  T a,
  valid_if_nonnegative<T> b,
  valid_if_positive<T> d) noexcept {
    using std::sqrt;
    using R = std::pair<optionally_valid<T>, optionally_valid<T>>;
    return (b && d) ? (extract(b) > T(0))
                        ? R{{(a + sqrt(extract(b))) / extract(d), true},
                            {(a - sqrt(extract(b))) / extract(d), true}}
                        : R{{a / extract(d), true}, {}}
                    : R{};
}
//------------------------------------------------------------------------------
template <typename T, bool V>
static constexpr auto _line_sphere_intersection_p(
  const line<T, V>& ray,
  const std::pair<optionally_valid<T>, optionally_valid<T>>& ts) {
    using E = optionally_valid<vector<T, 3, V>>;
    using R = std::pair<E, E>;
    return R{
      std::get<0>(ts) ? E{ray.point_at(extract(std::get<0>(ts))), true} : E{},
      std::get<1>(ts) ? E{ray.point_at(extract(std::get<1>(ts))), true} : E{},
    };
}
//------------------------------------------------------------------------------
template <typename T, bool V>
auto line_sphere_intersection_params(
  const line<T, V>& ray,
  const sphere<T, V>& sph) noexcept
  -> std::pair<optionally_valid<T>, optionally_valid<T>> {
    return _line_sphere_intersection_t(
      _line_sphere_intersection_a(ray.direction(), ray.origin() - sph.center()),
      _line_sphere_intersection_b(
        ray.direction(), ray.origin() - sph.center(), sph.radius()),
      _line_sphere_intersection_d(ray.direction()));
}
//------------------------------------------------------------------------------
/// @brief Finds line-sphere intersection points.
/// @ingroup math
/// @see nearest_line_sphere_intersection
template <typename T, bool V>
static constexpr auto line_sphere_intersection(
  const line<T, V>& ray,
  const sphere<T, V>& sph) noexcept -> std::
  pair<optionally_valid<vector<T, 3, V>>, optionally_valid<vector<T, 3, V>>> {
    return _line_sphere_intersection_p(
      ray, line_sphere_intersection_params(ray, sph));
}
//------------------------------------------------------------------------------
template <typename T, bool V>
static constexpr auto _line_sphere_intersection_n_p(
  const line<T, V>& ray,
  const std::pair<optionally_valid<T>, optionally_valid<T>>& ts) {
    using R = optionally_valid<vector<T, 3, V>>;
    using std::abs;

    return std::get<0>(ts)
             ? std::get<1>(ts)
                 ? abs(extract(std::get<0>(ts))) < abs(extract(std::get<1>(ts)))
                     ? R{ray.point_at(extract(std::get<0>(ts))), true}
                     : R{ray.point_at(extract(std::get<1>(ts))), true}
                 : R{ray.point_at(extract(std::get<0>(ts))), true}
             : R{};
}
//------------------------------------------------------------------------------
/// @brief Finds nearest line-sphere intersection point.
/// @ingroup math
/// @see line_sphere_intersection
template <typename T, bool V>
static constexpr auto nearest_line_sphere_intersection(
  const line<T, V>& ray,
  const sphere<T, V>& sph) noexcept -> optionally_valid<vector<T, 3, V>> {
    return _line_sphere_intersection_n_p(
      ray, line_sphere_intersection_params(ray, sph));
}
//------------------------------------------------------------------------------
// line-triangle
//------------------------------------------------------------------------------
template <typename T, bool V>
static inline auto line_triangle_intersection_param(
  const line<T, V>& ray,
  const triangle<T, V>& tri) noexcept -> optionally_valid<T> {

    const vector<T, 3, V> h = cross(ray.direction(), tri.ac());
    const T a = dot(tri.ab(), h);

    if(const auto ia = reciprocal(a)) {
        const T f = extract(ia);
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
/// @brief Finds line-triangle intersection point.
/// @ingroup math
template <typename T, bool V>
static inline auto line_triangle_intersection(
  const line<T, V>& ray,
  const triangle<T, V>& tri) noexcept -> optionally_valid<vector<T, 3, V>> {
    if(const auto t = line_triangle_intersection_param(ray, tri)) {
        return {ray.origin() + ray.direction() * extract(t), true};
    }
    return {};
}
//------------------------------------------------------------------------------
} // namespace eagine::math

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif // EAGINE_MATH_INTERSECTION_HPP
