/**
 *  @file eagine/vect/compare.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_VECT_COMPARE_HPP
#define EAGINE_VECT_COMPARE_HPP

#include "data.hpp"

namespace eagine {
namespace vect {

template <typename T, int N, bool V>
struct is_zero {
    using _dT = data_t<T, N, V>;
    using _dpT = data_param_t<T, N, V>;

    static bool apply(_dpT v) noexcept {
        for(int i = 0; i < N; ++i) {
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wfloat-equal"
#endif
            if(v[i] != 0)
#ifdef __clang__
#pragma clang diagnostic pop
#endif
            {
                return false;
            }
        }
        return true;
    }
};

// TODO: some optimizations ?

} // namespace vect
} // namespace eagine

#endif // EAGINE_VECT_COMPARE_HPP
