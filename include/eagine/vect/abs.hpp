/**
 *  @file eagine/vect/abs.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_VECT_ABS_1509260923_HPP
#define EAGINE_VECT_ABS_1509260923_HPP

#include "data.hpp"
#include <cmath>

namespace eagine {
namespace vect {

template <typename T, int N, bool V>
struct abs {
    // TODO: SIMD version?

    static data_t<T, N, V> apply(data_t<T, N, V> v) noexcept {
	for(int i = 0; i < N; ++i) {
	    v[i] = v[i] < 0 ? -v[i] : v[i];
	}
	return v;
    }
};

} // namespace vect
} // namespace eagine

#endif // include guard
