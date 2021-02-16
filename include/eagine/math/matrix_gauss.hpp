/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_MATH_MATRIX_GAUSS_HPP
#define EAGINE_MATH_MATRIX_GAUSS_HPP

#include "../compare.hpp"
#include "matrix.hpp"
#include <utility>

namespace eagine::math {
//------------------------------------------------------------------------------
template <typename T, int Ca, int Cb, int R, bool V>
static inline auto gauss_elimination(
  matrix<T, Ca, R, true, V>& a,
  matrix<T, Cb, R, true, V>& b) noexcept -> bool {
    using std::swap;
    const auto is_zero = [](T x) noexcept {
        return are_equal(x, T(0));
    };

    for(int i = 0; i < R; ++i) {
        auto d = a._v[i][i];
        if(is_zero(d)) {
            for(int k = i + 1; k < R; ++k) {
                if(!is_zero(a._v[k][i])) {
                    swap(a._v[k], a._v[i]);
                    swap(b._v[k], b._v[i]);
                    break;
                }
            }
            d = a._v[i][i];
        }
        if(is_zero(d)) {
            return false;
        }
        const auto inv_d = T(1) / d;

        a._v[i] *= inv_d;
        b._v[i] *= inv_d;

        for(int k = i + 1; k < R; ++k) {
            d = a._v[k][i];
            if(!is_zero(d)) {
                a._v[k] -= a._v[i] * d;
                b._v[k] -= b._v[i] * d;
            }
        }
    }
    return true;
}
//------------------------------------------------------------------------------
template <typename T, int Ca, int Cb, int R, bool V>
static inline auto gauss_elimination(
  matrix<T, Ca, R, false, V>& a,
  matrix<T, Cb, R, true, V>& b) noexcept -> bool {
    auto ta = reorder(a);
    if(gauss_elimination(ta, b)) {
        a = reorder(ta);
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
template <typename T, int Ca, int Cb, int R, bool V>
static inline auto gauss_elimination(
  matrix<T, Ca, R, true, V>& a,
  matrix<T, Cb, R, false, V>& b) noexcept -> bool {
    auto tb = reorder(b);
    if(gauss_elimination(a, tb)) {
        b = reorder(tb);
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
template <typename T, int Ca, int Cb, int R, bool V>
static inline auto gauss_elimination(
  matrix<T, Ca, R, false, V>& a,
  matrix<T, Cb, R, false, V>& b) noexcept -> bool {
    auto ta = reorder(a);
    auto tb = reorder(b);
    if(gauss_elimination(ta, tb)) {
        a = reorder(ta);
        b = reorder(tb);
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
template <typename T, int Ca, int Cb, int R, bool V>
static inline auto gauss_jordan_elimination(
  matrix<T, Ca, R, true, V>& a,
  matrix<T, Cb, R, true, V>& b) noexcept -> bool {

    if(gauss_elimination(a, b)) {

        for(int i = R - 1; i > 0; --i) {
            for(int k = 0; k < i; ++k) {
                const T d = a._v[k][i];
                if(!are_equal(d, T(0))) {
                    a._v[k] -= a._v[i] * d;
                    b._v[k] -= b._v[i] * d;
                }
            }
        }

        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
template <typename T, int Ca, int Cb, int R, bool V>
static inline auto gauss_jordan_elimination(
  matrix<T, Ca, R, false, V>& a,
  matrix<T, Cb, R, true, V>& b) noexcept -> bool {
    auto ta = reorder(a);
    if(gauss_jordan_elimination(ta, b)) {
        a = reorder(ta);
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
template <typename T, int Ca, int Cb, int R, bool V>
static inline auto gauss_jordan_elimination(
  matrix<T, Ca, R, true, V>& a,
  matrix<T, Cb, R, false, V>& b) noexcept -> bool {
    auto tb = reorder(b);
    if(gauss_jordan_elimination(a, tb)) {
        b = reorder(tb);
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
template <typename T, int Ca, int Cb, int R, bool V>
static inline auto gauss_jordan_elimination(
  matrix<T, Ca, R, false, V>& a,
  matrix<T, Cb, R, false, V>& b) noexcept -> bool {
    auto ta = reorder(a);
    auto tb = reorder(b);
    if(gauss_jordan_elimination(ta, tb)) {
        a = reorder(ta);
        b = reorder(tb);
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
} // namespace eagine::math

#endif // EAGINE_MATH_MATRIX_GAUSS_HPP
