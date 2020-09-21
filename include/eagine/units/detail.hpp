/**
 *  @file eagine/unit/detail.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_DETAIL_HPP
#define EAGINE_UNITS_DETAIL_HPP

#include "../identity.hpp"
#include "../mp_arithmetic.hpp"
#include "base_dim.hpp"
#include "fwd.hpp"
#include "scales.hpp"

namespace eagine::units::bits {

// collapse_tail
template <typename X>
struct collapse_tail : identity<X> {};

template <typename X>
using collapse_tail_t = typename collapse_tail<X>::type;

// dim_pow
template <typename Dim, int Pow>
struct dim_pow {
    using dim = Dim;
    using pow = int_constant<Pow>;
};

// dims
template <typename Head, typename Tail>
struct dims {
    using type = dims;
};

using dimless = dims<nothing_t, nothing_t>;

template <>
struct collapse_tail<dims<nothing_t, nothing_t>> : nothing_t {};

// pow_of_dim
template <typename D, typename Dims>
struct pow_of_dim;

template <typename D, typename Dims>
constexpr int pow_of_dim_v = pow_of_dim<D, Dims>::value;

template <typename D>
struct pow_of_dim<D, nothing_t> : int_constant<0> {};

template <typename D>
struct pow_of_dim<D, dimless> : int_constant<0> {};

template <typename D, int P, typename T>
struct pow_of_dim<D, dims<dim_pow<D, P>, T>> : int_constant<P> {};

template <typename D1, typename D2, int P, typename T>
struct pow_of_dim<D1, dims<dim_pow<D2, P>, T>> : pow_of_dim<D1, T> {};

// get_pow_of_dim
template <typename D, typename H, typename T>
static constexpr inline auto
get_pow_of_dim(base::dimension<D>, dims<H, T>) noexcept -> int {
    return pow_of_dim_v<D, dims<H, T>>;
}

// dim_add
template <typename Dims1, typename Dims2>
struct dim_add;

template <typename Dims1, typename Dims2>
using dim_add_t = typename dim_add<Dims1, Dims2>::type;

template <>
struct dim_add<nothing_t, nothing_t> : nothing_t {};

template <typename H, typename T>
struct dim_add<nothing_t, dims<H, T>> : dims<H, T> {};

template <typename H, typename T>
struct dim_add<dims<H, T>, nothing_t> : dims<H, T> {};

template <>
struct dim_add<dimless, dimless> : dimless {};

template <typename H, typename T>
struct dim_add<dims<H, T>, dimless> : dims<H, T> {};

template <typename H, typename T>
struct dim_add<dimless, dims<H, T>> : dims<H, T> {};

template <typename Dim, int Pow1, typename Tail1, int Pow2, typename Tail2>
struct dim_add<dims<dim_pow<Dim, Pow1>, Tail1>, dims<dim_pow<Dim, Pow2>, Tail2>>
  : std::conditional_t<
      (Pow1 + Pow2 == 0),
      dim_add_t<Tail1, Tail2>,
      dims<dim_pow<Dim, Pow1 + Pow2>, collapse_tail_t<dim_add_t<Tail1, Tail2>>>> {
};

template <
  typename Dim1,
  int Pow1,
  typename Tail1,
  typename Dim2,
  int Pow2,
  typename Tail2>
struct dim_add<dims<dim_pow<Dim1, Pow1>, Tail1>, dims<dim_pow<Dim2, Pow2>, Tail2>>
  : std::conditional_t<
      (base::dim_num_v<Dim1> < base::dim_num_v<Dim2>),
      dims<
        dim_pow<Dim1, Pow1>,
        collapse_tail_t<dim_add_t<Tail1, dims<dim_pow<Dim2, Pow2>, Tail2>>>>,
      dims<
        dim_pow<Dim2, Pow2>,
        collapse_tail_t<dim_add_t<dims<dim_pow<Dim1, Pow1>, Tail1>, Tail2>>>> {
};

// dim_sub
template <typename Dims1, typename Dims2>
struct dim_sub;

template <typename Dims1, typename Dims2>
using dim_sub_t = typename dim_sub<Dims1, Dims2>::type;

template <>
struct dim_sub<nothing_t, nothing_t> : dimless {};

template <>
struct dim_sub<nothing_t, dimless> : dimless {};

template <typename H, typename T>
struct dim_sub<dims<H, T>, nothing_t> : dims<H, T> {};

template <typename D, int P, typename T>
struct dim_sub<nothing_t, dims<dim_pow<D, P>, T>>
  : dims<dim_pow<D, -P>, collapse_tail_t<dim_sub_t<nothing_t, T>>> {};

template <>
struct dim_sub<dimless, dimless> : dimless {};

template <typename H, typename T>
struct dim_sub<dims<H, T>, dimless> : dims<H, T> {};

template <typename D, int P, typename T>
struct dim_sub<dimless, dims<dim_pow<D, P>, T>>
  : dims<dim_pow<D, -P>, collapse_tail_t<dim_sub_t<nothing_t, T>>> {};

template <typename Dim, int Pow1, typename Tail1, int Pow2, typename Tail2>
struct dim_sub<dims<dim_pow<Dim, Pow1>, Tail1>, dims<dim_pow<Dim, Pow2>, Tail2>>
  : std::conditional_t<
      (Pow1 - Pow2 == 0),
      dim_sub_t<Tail1, Tail2>,
      dims<dim_pow<Dim, Pow1 - Pow2>, collapse_tail_t<dim_sub_t<Tail1, Tail2>>>> {
};

template <
  typename Dim1,
  int Pow1,
  typename Tail1,
  typename Dim2,
  int Pow2,
  typename Tail2>
struct dim_sub<dims<dim_pow<Dim1, Pow1>, Tail1>, dims<dim_pow<Dim2, Pow2>, Tail2>>
  : std::conditional_t<
      (base::dim_num_v<Dim1> < base::dim_num_v<Dim2>),
      dims<
        dim_pow<Dim1, Pow1>,
        collapse_tail_t<dim_sub_t<Tail1, dims<dim_pow<Dim2, Pow2>, Tail2>>>>,
      dims<
        dim_pow<Dim2, -Pow2>,
        collapse_tail_t<dim_sub_t<dims<dim_pow<Dim1, Pow1>, Tail1>, Tail2>>>> {
};

// get_pow
template <typename Dims, typename Dim>
struct get_pow;

// get_pow
template <typename Dim>
struct get_pow<nothing_t, Dim> : int_constant<0> {};

// get_pow
template <typename Dim>
struct get_pow<dimless, Dim> : int_constant<0> {};

// get_pow
template <typename H, typename T, typename Dim>
struct get_pow<dims<H, T>, Dim> : get_pow<T, Dim> {};

// get_pow
template <typename Dim, int Pow, typename T>
struct get_pow<dims<dim_pow<Dim, Pow>, T>, Dim> : int_constant<Pow> {};

// uni_sca
template <typename Unit, typename Scale>
struct uni_sca;

template <typename Head, typename Tail>
struct unit_scales {
    using type = unit_scales;
};

template <>
struct collapse_tail<unit_scales<nothing_t, nothing_t>> : nothing_t {};

// insert
template <typename UnitScales, typename Unit, typename Scale>
struct insert;

template <typename UnitScales, typename Unit, typename Scale>
using insert_t = typename insert<UnitScales, Unit, Scale>::type;

template <typename U, typename S>
struct insert<nothing_t, U, S> : unit_scales<uni_sca<U, S>, nothing_t> {};

template <typename U, typename S>
struct insert<unit_scales<nothing_t, nothing_t>, U, S>
  : unit_scales<uni_sca<U, S>, nothing_t> {};

template <typename U, typename SO, typename SN, typename T>
struct insert<unit_scales<uni_sca<U, SO>, T>, U, SN>
  : unit_scales<uni_sca<U, SN>, T> {};

template <typename H, typename T, typename U, typename S>
struct insert<unit_scales<H, T>, U, S> : unit_scales<H, insert_t<T, U, S>> {};

// get_scale
template <typename UnitScales, typename Unit, typename Fallback>
struct get_scale;

template <typename UnitScales, typename Unit, typename Fallback>
using get_scale_t = typename get_scale<UnitScales, Unit, Fallback>::type;

template <typename U, typename Fallback>
struct get_scale<nothing_t, U, Fallback> : Fallback {};

template <typename U, typename Fallback>
struct get_scale<unit_scales<nothing_t, nothing_t>, U, Fallback> : Fallback {};

template <typename U, typename Scale, typename T, typename F>
struct get_scale<unit_scales<uni_sca<U, Scale>, T>, U, F> : Scale {};

template <typename U, typename S1, typename S2, typename T, typename F>
struct get_scale<unit_scales<uni_sca<U, S1>, T>, base::scaled_unit<S2, U>, F>
  : scales::divided<S1, S2> {};

template <typename H, typename T, typename U, typename F>
struct get_scale<unit_scales<H, T>, U, F> : get_scale<T, U, F> {};

// get_dim_unit
template <typename UnitScales, typename BaseDim, typename Fallback>
struct get_dim_unit;

template <typename BD, typename Fallback>
struct get_dim_unit<nothing_t, BD, Fallback> : Fallback {};

template <typename BD, typename Fallback>
struct get_dim_unit<unit_scales<nothing_t, nothing_t>, BD, Fallback>
  : Fallback {};

template <typename U, typename S, typename T, typename BD, typename F>
struct get_dim_unit<unit_scales<uni_sca<U, S>, T>, BD, F>
  : std::conditional_t<
      std::is_same_v<dimension_of_t<U>, BD>,
      base::scaled_unit<S, U>,
      typename get_dim_unit<T, BD, F>::type> {};

// merge
template <typename UnitScales1, typename UnitScales2>
struct merge;

template <typename UnitScales1, typename UnitScales2>
using merge_t = typename merge<UnitScales1, UnitScales2>::type;

template <>
struct merge<nothing_t, nothing_t> : unit_scales<nothing_t, nothing_t> {};

template <>
struct merge<unit_scales<nothing_t, nothing_t>, unit_scales<nothing_t, nothing_t>>
  : unit_scales<nothing_t, nothing_t> {};

template <typename H, typename T>
struct merge<unit_scales<H, T>, nothing_t> : unit_scales<H, T> {};

template <typename H, typename T>
struct merge<nothing_t, unit_scales<H, T>> : unit_scales<H, T> {};

template <typename H, typename T>
struct merge<unit_scales<H, T>, unit_scales<nothing_t, nothing_t>>
  : unit_scales<H, T> {};

template <typename H, typename T>
struct merge<unit_scales<nothing_t, nothing_t>, unit_scales<H, T>>
  : unit_scales<H, T> {};

template <typename U, typename S1, typename S2, typename T1, typename T2>
struct merge<unit_scales<uni_sca<U, S1>, T1>, unit_scales<uni_sca<U, S2>, T2>>
  : unit_scales<uni_sca<U, S1>, collapse_tail_t<merge_t<T1, T2>>> {};

template <
  typename U1,
  typename U2,
  typename S1,
  typename S2,
  typename T1,
  typename T2>
struct merge<unit_scales<uni_sca<U1, S1>, T1>, unit_scales<uni_sca<U2, S2>, T2>>
  : std::conditional_t<
      (base::dim_num_v<dimension_of_t<U1>> <
       base::dim_num_v<dimension_of_t<U2>>),
      unit_scales<
        uni_sca<U1, S1>,
        collapse_tail_t<merge_t<T1, unit_scales<uni_sca<U2, S2>, T2>>>>,
      unit_scales<
        uni_sca<U2, S2>,
        collapse_tail_t<merge_t<unit_scales<uni_sca<U1, S1>, T1>, T2>>>> {};

// _sc_unit_sc_hlp
template <typename Scales, typename System>
struct _sc_unit_sc_hlp {

    template <typename T, typename SV>
    static constexpr auto _pow(T v, SV, int_constant<0>) {
        return v;
    }

    template <typename T, typename S, int E>
    static constexpr auto _pow(T v, S s, int_constant<E>) {
        return _pow(
          (E > 0) ? S::mul(v) : S::div(v),
          s,
          int_constant<E + ((E > 0) ? -1 : 1)>());
    }

    template <typename Dir, typename T>
    static constexpr auto _hlp(Dir, T v) noexcept -> T {
        return v;
    }

    template <typename Dir, typename T>
    static constexpr auto _hlp(Dir d, T v, nothing_t) noexcept -> T {
        return _hlp(d, v);
    }

    template <typename Dir, typename T>
    static constexpr auto _hlp(Dir d, T v, dimless) noexcept -> T {
        return _hlp(d, v);
    }

    template <typename Dir, typename T, typename D, int E>
    static constexpr auto _hlp2(Dir, T v, dim_pow<D, E>) noexcept {
        using SBU = typename System ::template base_unit<D>::type;
        using BS = scales::scale_of_t<SBU>;

        return _pow(
          v,
          get_scale_t<Scales, SBU, BS>(),
          int_constant<(Dir::value ? E : -E)>());
    }

    template <typename Dir, typename T, typename D, int P, typename Dims>
    static constexpr auto
    _hlp(Dir dir, T v, dims<dim_pow<D, P>, Dims>) noexcept {
        return _hlp(dir, _hlp2(dir, v, dim_pow<D, P>()), Dims());
    }
};

} // namespace eagine::units::bits

#endif // EAGINE_UNITS_DETAIL_HPP
