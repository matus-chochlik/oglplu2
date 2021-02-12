/// @file eagine/vect/cast.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_VECT_CAST_HPP
#define EAGINE_VECT_CAST_HPP

#include "fill.hpp"
#include <utility>

namespace eagine::vect {

template <typename TF, int NF, bool VF, typename TT, int NT, bool VT>
struct cast;

template <typename T, int N, bool V>
struct cast<T, N, V, T, N, V> {
    static constexpr auto apply(data_param_t<T, N, V> v, T) noexcept
      -> data_t<T, N, V> {
        return v;
    }
};

template <typename TF, int NF, bool VF, typename TT, int NT, bool VT>
struct cast {
private:
    template <int... I>
    using _idx_seq = std::integer_sequence<int, I...>;
    template <int N>
    using _make_idx_seq = std::make_integer_sequence<int, N>;

    template <int... I, int... D>
    static constexpr auto _cast(
      data_param_t<TF, NF, VF> v,
      data_param_t<TT, sizeof...(D), VT> d,
      _idx_seq<I...>,
      _idx_seq<D...>) noexcept {
        return data_t<TT, NT, VT>{TT(v[I])..., TT(d[D])...};
    }

    template <int... I>
    static constexpr auto _cast(
      data_param_t<TF, NF, VF> v,
      data_param_t<TT, 0U, VT>,
      _idx_seq<I...>,
      _idx_seq<>) noexcept {
        return data_t<TT, NT, VT>{TT(v[I])...};
    }

public:
    static constexpr auto apply(
      data_param_t<TF, NF, VF> v,
      data_param_t<TT, (NT > NF) ? NT - NF : 0, VT> d) noexcept {
        using is = _make_idx_seq<(NT > NF) ? NF : NT>;
        using ds = _make_idx_seq<(NT > NF) ? NT - NF : 0>;
        return _cast(v, d, is(), ds());
    }

    static constexpr auto apply(data_param_t<TF, NF, VF> v, TT d) noexcept {
        return apply(v, fill < TT, (NT > NF) ? NT - NF : 0, VT > ::apply(d));
    }
};

} // namespace eagine::vect

#endif // EAGINE_VECT_CAST_HPP
