/**
 *  @file eagine/vect/esum.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_VECT_ESUM_HPP
#define EAGINE_VECT_ESUM_HPP

#include "config.hpp"
#if EAGINE_VECT_OPTS
#include "hsum.hpp"
#else
#include "data.hpp"
#endif

namespace eagine {
namespace vect {

template <typename T, int N, bool V>
struct esum {
private:
    using _dpT = data_param_t<T, N, V>;

    template <int U>
    using _int = int_constant<U>;

    template <bool B>
    using _bool = bool_constant<B>;

    template <int M, bool B>
    static inline T _hlp(_dpT v, _int<M>, _bool<B>) noexcept {
        static_assert(M == N);
        T r = T(0);

        for(int i = 0; i < N; ++i) {
            r += v[i];
        }
        return r;
    }

#if EAGINE_VECT_OPTS
    template <bool B>
    static constexpr inline T _hlp(_dpT v, _int<1>, _bool<B>) noexcept {
        return v[0];
    }

    template <int M>
    static inline T _hlp(_dpT v, _int<M>, std::true_type) noexcept {
        static_assert(M == N);
        return hsum<T, N, V>::apply(v)[N - 1];
    }
#endif
public:
    static inline T apply(_dpT v) noexcept {
        return _hlp(v, _int<N>(), has_vect_data<T, N, V>());
    }
};

} // namespace vect
} // namespace eagine

#endif // EAGINE_VECT_ESUM_HPP
