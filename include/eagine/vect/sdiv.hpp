/**
 *  @file eagine/vect/sdiv.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_VECT_SDIV_HPP
#define EAGINE_VECT_SDIV_HPP

#include "data.hpp"

namespace eagine::vect {

template <typename T, int N, bool V>
struct sdiv {
    using _dT = data_t<T, N, V>;
    using _dpT = data_param_t<T, N, V>;

    static constexpr inline _dT apply(_dpT a, _dpT b) noexcept {
        return a / b;
    }
};

#if EAGINE_USE_SIMD
#if defined(__GNUC__) || defined(__clang__)

template <typename T, bool V>
struct sdiv<T, 3, V> {
    using _dT = data_t<T, 3, V>;
    using _dpT = data_param_t<T, 3, V>;

    static constexpr inline _dT _hlp(_dpT a, _dpT b, std::true_type) noexcept {
        return a / _dT{b[0], b[1], b[2], T(1)};
    }

    static constexpr inline _dT _hlp(_dpT a, _dpT b, std::false_type) noexcept {
        return a / b;
    }

    static constexpr inline _dT apply(_dpT a, _dpT b) noexcept {
        return _hlp(a, b, has_vect_data<T, 3, V>());
    }
};

#endif
#endif

} // namespace eagine::vect

#endif // EAGINE_VECT_SDIV_HPP
