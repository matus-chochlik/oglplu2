/**
 *  @file eagine/vect/data_ary.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VECT_DATA_ARY_HPP
#define EAGINE_VECT_DATA_ARY_HPP

#include "config.hpp"
#include "fwd.hpp"
#include <cstdint>
#include <type_traits>
#include <utility>

namespace eagine::vect {

template <typename T, int N>
struct _ary_data {
    T _v[N];

    using type = _ary_data;

    _ary_data() = default;
    _ary_data(_ary_data&&) noexcept(std::is_nothrow_move_constructible_v<T>) =
      default;
    _ary_data(const _ary_data&) = default;
    _ary_data& operator=(_ary_data&&) noexcept(
      std::is_nothrow_move_constructible_v<T>) = default;
    _ary_data& operator=(const _ary_data&) = default;

    ~_ary_data() noexcept = default;

    template <
      typename P,
      typename = std::enable_if_t<(N == 1) && (std::is_convertible_v<P, T>)>>
    constexpr _ary_data(P&& p)
      : _v{T(std::forward<P>(p))} {
    }

    template <
      typename P1,
      typename P2,
      typename... Pn,
      typename = std::enable_if_t<(sizeof...(Pn) + 2) == N>>
    constexpr _ary_data(P1&& p1, P2&& p2, Pn&&... pn)
      : _v{
          T(std::forward<P1>(p1)),
          T(std::forward<P2>(p2)),
          T(std::forward<Pn>(pn))...} {
    }

    constexpr inline T operator[](int i) const noexcept {
        return _v[i];
    }

    inline T& operator[](int i) noexcept {
        return _v[i];
    }

    constexpr inline _ary_data& operator+=(_ary_data b) noexcept {
        for(int i = 0; i < N; ++i) {
            _v[i] += b[i];
        }
        return *this;
    }

    constexpr inline _ary_data& operator+=(T b) noexcept {
        for(int i = 0; i < N; ++i) {
            _v[i] += b;
        }
        return *this;
    }

    constexpr inline _ary_data& operator-=(_ary_data b) noexcept {
        for(int i = 0; i < N; ++i) {
            _v[i] -= b[i];
        }
        return *this;
    }

    constexpr inline _ary_data& operator-=(T b) noexcept {
        for(int i = 0; i < N; ++i) {
            _v[i] -= b;
        }
        return *this;
    }

    constexpr inline _ary_data& operator*=(_ary_data b) noexcept {
        for(int i = 0; i < N; ++i) {
            _v[i] *= b[i];
        }
        return *this;
    }

    constexpr inline _ary_data& operator*=(T b) noexcept {
        for(int i = 0; i < N; ++i) {
            _v[i] *= b;
        }
        return *this;
    }

    constexpr inline _ary_data& operator/=(_ary_data b) noexcept {
        for(int i = 0; i < N; ++i) {
            _v[i] /= b[i];
        }
        return *this;
    }

    constexpr inline _ary_data& operator/=(T b) noexcept {
        for(int i = 0; i < N; ++i) {
            _v[i] /= b;
        }
        return *this;
    }

    friend constexpr inline _ary_data operator+(_ary_data a) noexcept {
        return a;
    }

    friend _ary_data operator-(_ary_data a) noexcept {
        for(int i = 0; i < N; ++i) {
            a._v[i] = -a._v[i];
        }
        return a;
    }

    friend _ary_data operator+(
      const _ary_data& a, const _ary_data& b) noexcept {
        _ary_data c{};
        for(int i = 0; i < N; ++i) {
            c._v[i] = a._v[i] + b._v[i];
        }
        return c;
    }

    friend _ary_data operator+(const _ary_data& a, T b) noexcept {
        _ary_data c{};
        for(int i = 0; i < N; ++i) {
            c._v[i] = a._v[i] + b;
        }
        return c;
    }

    friend _ary_data operator-(
      const _ary_data& a, const _ary_data& b) noexcept {
        _ary_data c{};
        for(int i = 0; i < N; ++i) {
            c._v[i] = a._v[i] - b._v[i];
        }
        return c;
    }

    friend _ary_data operator-(const _ary_data& a, T b) noexcept {
        _ary_data c{};
        for(int i = 0; i < N; ++i) {
            c._v[i] = a._v[i] - b;
        }
        return c;
    }

    friend _ary_data operator*(
      const _ary_data& a, const _ary_data& b) noexcept {
        _ary_data c{};
        for(int i = 0; i < N; ++i) {
            c._v[i] = a._v[i] * b._v[i];
        }
        return c;
    }

    friend _ary_data operator*(const _ary_data& a, T b) noexcept {
        _ary_data c{};
        for(int i = 0; i < N; ++i) {
            c._v[i] = a._v[i] * b;
        }
        return c;
    }

    friend _ary_data operator/(
      const _ary_data& a, const _ary_data& b) noexcept {
        _ary_data c{};
        for(int i = 0; i < N; ++i) {
            c._v[i] = a._v[i] / b._v[i];
        }
        return c;
    }

    friend _ary_data operator/(const _ary_data& a, T b) noexcept {
        _ary_data c{};
        for(int i = 0; i < N; ++i) {
            c._v[i] = a._v[i] / b;
        }
        return c;
    }
};

template <typename T, int N>
struct _ary_cref {
    using type = const _ary_data<T, N>&;
};

template <typename T>
struct _ary_data<T, 0U> {
    using type = _ary_data;

    T operator[](int i) const;
};

} // namespace eagine::vect

#endif // EAGINE_VECT_DATA_ARY_HPP
