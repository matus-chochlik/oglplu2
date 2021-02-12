/// @file eagine/math/io.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_MATH_IO_HPP
#define EAGINE_MATH_IO_HPP

#include "matrix.hpp"
#include "primitives.hpp"
#include "vector.hpp"
#include <iostream>

namespace eagine::math {
//------------------------------------------------------------------------------
template <typename T, int N, bool V>
static inline auto operator<<(std::ostream& o, const vector<T, N, V>& v)
  -> std::ostream& {

    o << "[" << v._v[0];
    for(int i = 1; i < N; ++i) {
        o << ", " << v._v[i];
    }
    return o << "]";
}
//------------------------------------------------------------------------------
template <typename T, int C, int R, bool V>
static inline auto operator<<(std::ostream& o, const matrix<T, C, R, true, V>& m)
  -> std::ostream& {
    o << "|R0[" << m._v[0][0];

    for(int c = 1; c < C; ++c) {
        o << ", " << m._v[0][c];
    }
    o << "]";

    for(int r = 1; r < R; ++r) {
        o << ",R" << r << "[" << m._v[r][0];
        for(int c = 1; c < C; ++c) {
            o << ", " << m._v[r][c];
        }
        o << "]";
    }
    return o << "|";
}
//------------------------------------------------------------------------------
template <typename T, int C, int R, bool V>
static inline auto
operator<<(std::ostream& o, const matrix<T, C, R, false, V>& m)
  -> std::ostream& {
    o << "|C0[" << m._v[0][0];

    for(int r = 1; r < R; ++r) {
        o << ", " << m._v[0][r];
    }
    o << "]";

    for(int c = 1; c < C; ++c) {
        o << ",C" << c << "[" << m._v[c][0];
        for(int r = 1; r < R; ++r) {
            o << ", " << m._v[c][r];
        }
        o << "]";
    }
    return o << "|";
}
//------------------------------------------------------------------------------
template <typename T, bool V>
static inline auto operator<<(std::ostream& o, const line<T, V>& l)
  -> std::ostream& {
    o << '[' << l.origin() << " -> " << l.direction() << ']';
    return o;
}
//------------------------------------------------------------------------------
template <typename T, bool V>
static inline auto operator<<(std::ostream& o, const triangle<T, V>& t)
  -> std::ostream& {
    o << '[' << t.a() << '|' << t.b() << '|' << t.c() << ']';
    return o;
}
//------------------------------------------------------------------------------
template <typename T, bool V>
static inline auto operator<<(std::ostream& o, const sphere<T, V>& s)
  -> std::ostream& {
    o << '[' << s.center() << ')' << s.radius() << ']';
    return o;
}
//------------------------------------------------------------------------------
} // namespace eagine::math

#endif // EAGINE_MATH_IO_HPP
