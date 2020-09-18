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
    using _dpT = data_param_t<T, N, V>;

    static constexpr auto apply(_dpT a, _dpT b) noexcept -> data_t<T, N, V> {
        return a / b;
    }
};

#if EAGINE_USE_SIMD
#if defined(__GNUC__) || defined(__clang__)

template <typename T, bool V>
struct sdiv<T, 3, V> {
    using _dT = data_t<T, 3, V>;
    using _dpT = data_param_t<T, 3, V>;

    static constexpr auto _hlp(_dpT a, _dpT b, std::true_type) noexcept -> _dT {
        return a / _dT{b[0], b[1], b[2], T(1)};
    }

    static constexpr auto _hlp(_dpT a, _dpT b, std::false_type) noexcept
      -> _dT {
        return a / b;
    }

    static constexpr auto apply(_dpT a, _dpT b) noexcept -> _dT {
        return _hlp(a, b, has_vect_data<T, 3, V>());
    }
};

#endif
#endif

} // namespace eagine::vect

#endif // EAGINE_VECT_SDIV_HPP
