/// @file eagine/vect/diff.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_VECT_DIFF_HPP
#define EAGINE_VECT_DIFF_HPP

#include "abs.hpp"

namespace eagine::vect {

template <typename T, int N, bool V>
struct diff {
    using _dpT = data_param_t<T, N, V>;

    static auto apply(_dpT a, _dpT b) noexcept -> data_t<T, N, V> {
        return vect::abs<T, N, V>::apply(a - b);
    }
};

// TODO: some optimizations ?

} // namespace eagine::vect

#endif // EAGINE_VECT_DIFF_HPP
