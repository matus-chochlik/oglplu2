/**
 *  @file eagine/math/primitives.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_PRIMITIVES_HPP
#define EAGINE_MATH_PRIMITIVES_HPP

#include "tvec.hpp"
#include <array>

namespace eagine {
namespace math {
//------------------------------------------------------------------------------
template <typename T, bool V>
class line {
public:
    constexpr line() noexcept = default;

    constexpr line(tvec<T, 3, V> orig, tvec<T, 3, V> dir) noexcept
      : _origin{orig}
      , _direction{dir} {
    }

    constexpr vector<T, 3, V> origin() const noexcept {
        return _origin;
    }

    constexpr vector<T, 3, V> direction() const noexcept {
        return _direction;
    }

    constexpr vector<T, 3, V> point_at(T t) const noexcept {
        return _origin + _direction * t;
    }

private:
    vector<T, 3, V> _origin{};
    vector<T, 3, V> _direction{};
};
//------------------------------------------------------------------------------
template <typename T, bool V>
class triangle {
public:
    constexpr triangle() noexcept = default;

    constexpr triangle(
      tvec<T, 3, V> a, tvec<T, 3, V> b, tvec<T, 3, V> c) noexcept
      : _vertices{{a, b, c}} {
    }

    constexpr vector<T, 3, V> vertex(span_size_t index) const noexcept {
        return _vertices[index];
    }

    constexpr vector<T, 3, V> a() const noexcept {
        return _vertices[0];
    }

    constexpr vector<T, 3, V> b() const noexcept {
        return _vertices[1];
    }

    constexpr vector<T, 3, V> c() const noexcept {
        return _vertices[2];
    }

    constexpr vector<T, 3, V> ab() const noexcept {
        return b() - a();
    }

    constexpr vector<T, 3, V> ac() const noexcept {
        return c() - a();
    }

    constexpr vector<T, 3, V> center() const noexcept {
        return (a() + b() + c()) / T(3);
    }

    constexpr vector<T, 3, V> normal(bool cw) const noexcept {
        return cw ? cross(ac(), ab()) : cross(ab(), ac());
    }

private:
    std::array<vector<T, 3, V>, 3> _vertices;
};
//------------------------------------------------------------------------------
template <typename T, bool V>
class sphere {
public:
    constexpr sphere(tvec<T, 3, V> cntr, T rad) noexcept
      : _params{vector<T, 4, V>::from(cntr, rad)} {
    }

    constexpr vector<T, 3, V> center() const noexcept {
        return vector<T, 3, V>::from(_params);
    }

    constexpr T radius() const noexcept {
        return _params[3];
    }

private:
    vector<T, 4, V> _params{};
    T _radius{1};
};
//------------------------------------------------------------------------------
} // namespace math
} // namespace eagine

#endif // EAGINE_MATH_PRIMITIVES_HPP
