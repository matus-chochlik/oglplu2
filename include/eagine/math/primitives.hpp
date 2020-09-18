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

namespace eagine::math {
//------------------------------------------------------------------------------
template <typename T, bool V>
class line {
public:
    constexpr line() noexcept = default;

    constexpr line(tvec<T, 3, V> orig, tvec<T, 3, V> dir) noexcept
      : _origin{orig}
      , _direction{dir} {}

    constexpr auto origin() const noexcept -> vector<T, 3, V> {
        return _origin;
    }

    constexpr auto direction() const noexcept -> vector<T, 3, V> {
        return _direction;
    }

    constexpr auto point_at(T t) const noexcept -> vector<T, 3, V> {
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

    constexpr triangle(tvec<T, 3, V> a, tvec<T, 3, V> b, tvec<T, 3, V> c) noexcept
      : _vertices{{a, b, c}} {}

    constexpr auto vertex(span_size_t index) const noexcept -> vector<T, 3, V> {
        return _vertices[index];
    }

    constexpr auto a() const noexcept -> vector<T, 3, V> {
        return _vertices[0];
    }

    constexpr auto b() const noexcept -> vector<T, 3, V> {
        return _vertices[1];
    }

    constexpr auto c() const noexcept -> vector<T, 3, V> {
        return _vertices[2];
    }

    constexpr auto ab() const noexcept -> vector<T, 3, V> {
        return b() - a();
    }

    constexpr auto ac() const noexcept -> vector<T, 3, V> {
        return c() - a();
    }

    constexpr auto center() const noexcept -> vector<T, 3, V> {
        return (a() + b() + c()) / T(3);
    }

    constexpr auto normal(bool cw) const noexcept -> vector<T, 3, V> {
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
      : _params{vector<T, 4, V>::from(cntr, rad)} {}

    constexpr auto center() const noexcept -> vector<T, 3, V> {
        return vector<T, 3, V>::from(_params);
    }

    constexpr auto radius() const noexcept -> T {
        return _params[3];
    }

private:
    vector<T, 4, V> _params{};
};
//------------------------------------------------------------------------------
} // namespace eagine::math

#endif // EAGINE_MATH_PRIMITIVES_HPP
