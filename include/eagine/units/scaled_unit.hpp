/**
 *  @file eagine/unit/scaled_unit.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_SCALED_UNIT_HPP
#define EAGINE_UNITS_SCALED_UNIT_HPP

// clang-format off
#include "dimension.hpp"
#include "base_scaled_unit.hpp"
#include "custom_unit.hpp"
#include "unit.hpp"
#include <cmath>
// clang-format on

namespace eagine::units {

template <typename Dims, typename Scales, typename System>
struct scaled_dim_unit_conv {
    using type = scaled_dim_unit_conv;

    using _impl = bits::_sc_unit_sc_hlp<Scales, System>;
    using _ndp = bits::dim_pow<nothing_t, 0>;

    template <typename T>
    static constexpr auto to_base(T v) {
        return _impl::_hlp(std::true_type(), v, bits::dims<_ndp, Dims>());
    }

    template <typename T>
    static constexpr auto from_base(T v) {
        return _impl::_hlp(std::false_type(), v, bits::dims<_ndp, Dims>());
    }
};

// make_scaled_base_dim_unit
template <typename BaseScaledUnit, typename System>
struct make_scaled_base_dim_unit;

template <typename BaseScaledUnit, typename System>
using make_scaled_base_dim_unit_t =
  typename make_scaled_base_dim_unit<BaseScaledUnit, System>::type;

template <typename Scale, typename BaseUnit, typename System>
struct make_scaled_base_dim_unit<base::scaled_unit<Scale, BaseUnit>, System>
  : scaled_dim_unit<
      dimension<dimension_of_t<BaseUnit>, 1>,
      bits::unit_scales<bits::uni_sca<BaseUnit, Scale>, nothing_t>,
      System> {};

template <typename Scale, typename UnitScales>
using add_none_unit_scale_t =
  bits::unit_scales<bits::uni_sca<nothing_t, Scale>, UnitScales>;

// make_scaled_unit
template <typename Scale, typename Unit>
struct make_scaled_unit;

template <typename Scale, typename Unit>
using make_scaled_unit_t = typename make_scaled_unit<Scale, Unit>::type;

template <typename Scale, typename Dimension, typename System>
struct make_scaled_unit<Scale, unit<Dimension, System>>
  : scaled_dim_unit<Dimension, add_none_unit_scale_t<Scale, nothing_t>, System> {
};

// value_conv
template <typename D, typename AS, typename US, typename System>
struct value_conv<
  scaled_dim_unit<D, add_none_unit_scale_t<AS, US>, System>,
  unit<D, System>> {
    template <typename T>
    constexpr auto operator()(T v) const {
        return AS::to_base(v);
    }
};

template <typename D, typename AS, typename US, typename System>
struct value_conv<
  unit<D, System>,
  scaled_dim_unit<D, add_none_unit_scale_t<AS, US>, System>> {
    template <typename T>
    constexpr auto operator()(T v) const {
        return AS::from_base(v);
    }
};

template <typename D, typename AS1, typename AS2, typename US, typename System>
struct value_conv<
  scaled_dim_unit<D, add_none_unit_scale_t<AS1, US>, System>,
  scaled_dim_unit<D, add_none_unit_scale_t<AS2, US>, System>> {
    template <typename T>
    constexpr auto operator()(T v) const {
        return AS2::from_base(AS1::to_base(v));
    }
};

// lit_result
template <typename D, typename S>
struct lit_result<unit<D, S>>
  : scaled_dim_unit<D, bits::unit_scales<nothing_t, nothing_t>, S> {};

template <typename D1, typename D2, typename US1, typename US2, typename S>
struct mul_l_operand<scaled_dim_unit<D1, US1, S>, scaled_dim_unit<D2, US2, S>>
  : scaled_dim_unit<D1, bits::merge_t<US1, US2>, S> {};

template <typename D1, typename D2, typename US1, typename US2, typename S>
struct mul_r_operand<scaled_dim_unit<D1, US1, S>, scaled_dim_unit<D2, US2, S>>
  : scaled_dim_unit<D2, bits::merge_t<US1, US2>, S> {};

template <typename D1, typename D2, typename US1, typename US2, typename S>
struct mul_result<scaled_dim_unit<D1, US1, S>, scaled_dim_unit<D2, US2, S>>
  : scaled_dim_unit<bits::dim_add_t<D1, D2>, bits::merge_t<US1, US2>, S> {};

template <typename D1, typename D2, typename US1, typename US2, typename S>
struct div_result<scaled_dim_unit<D1, US1, S>, scaled_dim_unit<D2, US2, S>>
  : scaled_dim_unit<bits::dim_sub_t<D1, D2>, bits::merge_t<US1, US2>, S> {};

} // namespace eagine::units

#endif // EAGINE_UNITS_SCALED_UNIT_HPP
