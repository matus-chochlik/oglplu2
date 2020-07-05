/**
 *  @file eagine/vect/hsum.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_VECT_HSUM_HPP
#define EAGINE_VECT_HSUM_HPP

#include "shuffle.hpp"

namespace eagine::vect {

template <typename T, int N, bool V>
struct hsum {
private:
    using _dT = data_t<T, N, V>;
    using _dpT = data_param_t<T, 1, V>;

    template <int U>
    using _int = int_constant<U>;

    template <bool B>
    using _bool = bool_constant<B>;

    template <int... I>
    static inline _dT _sh_apply(_dpT v) noexcept {
        return shuffle<T, N, V>::template apply<I...>(v);
    }

    template <int M, bool B>
    static _dT _hlp(_dT v, _int<M>, _bool<B>) noexcept {
        static_assert(M == N);

        for(int i = 1; i < N; ++i) {
            v[i] += v[i - 1];
        }
        for(int i = N - 1; i > 0; --i) {
            v[i - 1] = v[i];
        }
        return v;
    }

#if EAGINE_VECT_OPTS
    template <bool B>
    static constexpr inline _dT _hlp(_dT v, _int<1>, _bool<B>) noexcept {
        return v;
    }

    static constexpr inline _dT _hlp(_dpT v, _int<2>, std::true_type) noexcept {
        return v + _sh_apply<1, 0>(v);
    }

    static constexpr inline _dT _hlp3_1(_dpT t, _dpT v) noexcept {
        return t + _sh_apply<2, 2, 1>(v);
    }

    static constexpr inline _dT _hlp(_dpT v, _int<3>, std::true_type) noexcept {
        return _hlp3_1(v + _sh_apply<1, 0, 0>(v), v);
    }

    static constexpr inline _dT _hlp4_1(_dpT v) noexcept {
        return v + _sh_apply<2, 3, 0, 1>(v);
    }

    static constexpr inline _dT _hlp(_dpT v, _int<4>, std::true_type) noexcept {
        return _hlp4_1(v + _sh_apply<1, 0, 3, 2>(v));
    }

    static constexpr inline _dT _hlp8_1(_dpT v) noexcept {
        return v + _sh_apply<1, 0, 3, 2, 5, 4, 7, 6>(v);
    }

    static constexpr inline _dT _hlp8_2(_dpT v) noexcept {
        return v + _sh_apply<2, 3, 0, 1, 6, 7, 4, 5>(v);
    }

    static constexpr inline _dT _hlp8_3(_dpT v) noexcept {
        return v + _sh_apply<4, 5, 6, 7, 0, 1, 2, 3>(v);
    }

    static constexpr inline _dT _hlp(_dpT v, _int<8>, std::true_type) noexcept {
        return _hlp8_3(_hlp8_2(_hlp8_1(v)));
    }
#endif
public:
    static inline _dT apply(_dT v) noexcept {
        return _hlp(v, _int<N>(), has_vect_data<T, N, V>());
    }
};

} // namespace eagine::vect

#endif // EAGINE_VECT_HSUM_HPP
