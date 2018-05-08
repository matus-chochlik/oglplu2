/**
 *  @file eagine/math/io.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_IO_1509260923_HPP
#define EAGINE_MATH_IO_1509260923_HPP

#include "matrix.hpp"
#include "vector.hpp"
#include <iostream>

namespace eagine {
namespace math {

template <typename T, int N, bool V>
static inline std::ostream&
operator<<(std::ostream& o, const vector<T, N, V>& v) {

    o << "[" << v._v[0];
    for(int i = 1; i < N; ++i) {
	o << ", " << v._v[i];
    }
    return o << "]";
}

template <typename T, int C, int R, bool V>
static inline std::ostream&
operator<<(std::ostream& o, const matrix<T, C, R, true, V>& m) {
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

template <typename T, int C, int R, bool V>
static inline std::ostream&
operator<<(std::ostream& o, const matrix<T, C, R, false, V>& m) {
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

} // namespace math
} // namespace eagine

#endif // include guard
