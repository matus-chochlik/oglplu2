/**
 *  @file eagine/unit/custom_unit.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_CUSTOM_UNIT_HPP
#define EAGINE_UNITS_CUSTOM_UNIT_HPP

// clang-format off
#include "dimension.hpp"
#include "base_custom_unit.hpp"
#include "unit.hpp"
#include <cmath>
// clang-format on

namespace eagine::units {

template <typename Dims, typename Conv, typename System>
struct custom_dim_unit {
    using dimension = Dims;
    using conversion = Conv;
    using system = System;
    using type = custom_dim_unit;
};

// make_custom_unit
template <typename Conv, typename Unit>
struct make_custom_unit;

template <typename Conv, typename Unit>
using make_custom_unit_t = typename make_custom_unit<Conv, Unit>::type;

template <typename Conv, typename Dimension, typename System>
struct make_custom_unit<Conv, unit<Dimension, System>>
  : custom_dim_unit<Dimension, Conv, System> {};

// is_convertible
template <typename D, typename C, typename S>
struct is_convertible<custom_dim_unit<D, C, S>, unit<D, S>> : std::true_type {};

template <typename D, typename C, typename S>
struct is_convertible<unit<D, S>, custom_dim_unit<D, C, S>> : std::true_type {};

template <typename D, typename C, typename S>
struct is_convertible<custom_dim_unit<D, C, S>, custom_dim_unit<D, C, S>>
  : std::true_type {};

template <typename D, typename C1, typename C2, typename S>
struct is_convertible<custom_dim_unit<D, C1, S>, custom_dim_unit<D, C2, S>>
  : std::true_type {};

// value_conv
template <typename D, typename C, typename S>
struct value_conv<custom_dim_unit<D, C, S>, unit<D, S>> {
    template <typename T>
    constexpr inline auto operator()(T v) const {
        return custom_dim_unit<D, C, S>::conversion::to_base(v);
    }
};

template <typename D, typename C, typename S>
struct value_conv<unit<D, S>, custom_dim_unit<D, C, S>> {
    template <typename T>
    constexpr inline auto operator()(T v) const {
        return custom_dim_unit<D, C, S>::conversion::from_base(v);
    }
};

template <typename D, typename C, typename S>
struct value_conv<custom_dim_unit<D, C, S>, custom_dim_unit<D, C, S>>
  : trivial_value_conv {};

template <typename D, typename C1, typename C2, typename S>
struct value_conv<custom_dim_unit<D, C1, S>, custom_dim_unit<D, C2, S>> {
    template <typename T>
    constexpr inline auto operator()(T v) const {
        return custom_dim_unit<D, C2, S>::conversion::from_base(
          custom_dim_unit<D, C1, S>::conversion::to_base(v));
    }
};

// lit_result
template <typename D, typename C, typename S>
struct lit_result<custom_dim_unit<D, C, S>> : custom_dim_unit<D, C, S> {};

// add_result
template <typename D, typename C, typename S>
struct add_result<custom_dim_unit<D, C, S>, unit<D, S>> : unit<D, S> {};

template <typename D, typename C, typename S>
struct add_result<unit<D, S>, custom_dim_unit<D, C, S>> : unit<D, S> {};

template <typename D, typename C, typename S>
struct add_result<custom_dim_unit<D, C, S>, custom_dim_unit<D, C, S>>
  : custom_dim_unit<D, C, S> {};

template <typename D, typename C1, typename C2, typename S>
struct add_result<custom_dim_unit<D, C1, S>, custom_dim_unit<D, C2, S>>
  : custom_dim_unit<D, C1, S> {};

// sub_result
template <typename D, typename C, typename S>
struct sub_result<custom_dim_unit<D, C, S>, unit<D, S>> : unit<D, S> {};

template <typename D, typename C, typename S>
struct sub_result<unit<D, S>, custom_dim_unit<D, C, S>> : unit<D, S> {};

template <typename D, typename C, typename S>
struct sub_result<custom_dim_unit<D, C, S>, custom_dim_unit<D, C, S>>
  : custom_dim_unit<D, C, S> {};

template <typename D, typename C1, typename C2, typename S>
struct sub_result<custom_dim_unit<D, C1, S>, custom_dim_unit<D, C2, S>>
  : custom_dim_unit<D, C1, S> {};

// mul_l_operand
template <typename D1, typename D2, typename C, typename S>
struct mul_l_operand<custom_dim_unit<D1, C, S>, unit<D2, S>> : unit<D1, S> {};

template <typename D1, typename D2, typename C, typename S>
struct mul_l_operand<unit<D1, S>, custom_dim_unit<D2, C, S>> : unit<D1, S> {};

template <typename D1, typename D2, typename C1, typename C2, typename S>
struct mul_l_operand<custom_dim_unit<D1, C1, S>, custom_dim_unit<D2, C2, S>>
  : custom_dim_unit<D1, bits::merge_t<C1, C2>, S> {};

// mul_r_operand
template <typename D1, typename D2, typename C, typename S>
struct mul_r_operand<custom_dim_unit<D1, C, S>, unit<D2, S>> : unit<D2, S> {};

template <typename D1, typename D2, typename C, typename S>
struct mul_r_operand<unit<D1, S>, custom_dim_unit<D2, C, S>> : unit<D2, S> {};

template <typename D1, typename D2, typename C1, typename C2, typename S>
struct mul_r_operand<custom_dim_unit<D1, C1, S>, custom_dim_unit<D2, C2, S>>
  : custom_dim_unit<D2, bits::merge_t<C1, C2>, S> {};

// mul_result
template <typename D1, typename D2, typename C, typename S>
struct mul_result<custom_dim_unit<D1, C, S>, unit<D2, S>>
  : unit<bits::dim_add_t<D1, D2>, S> {};

template <typename D1, typename D2, typename C, typename S>
struct mul_result<unit<D1, S>, custom_dim_unit<D2, C, S>>
  : unit<bits::dim_add_t<D1, D2>, S> {};

template <typename D1, typename D2, typename C1, typename C2, typename S>
struct mul_result<custom_dim_unit<D1, C1, S>, custom_dim_unit<D2, C2, S>>
  : custom_dim_unit<bits::dim_add_t<D1, D2>, bits::merge_t<C1, C2>, S> {};

// div_result
template <typename D1, typename D2, typename C, typename S>
struct div_result<custom_dim_unit<D1, C, S>, unit<D2, S>>
  : unit<bits::dim_sub_t<D1, D2>, S> {};

template <typename D1, typename D2, typename C, typename S>
struct div_result<unit<D1, S>, custom_dim_unit<D2, C, S>>
  : unit<bits::dim_sub_t<D1, D2>, S> {};

template <typename D1, typename D2, typename C1, typename C2, typename S>
struct div_result<custom_dim_unit<D1, C1, S>, custom_dim_unit<D2, C2, S>>
  : custom_dim_unit<bits::dim_sub_t<D1, D2>, bits::merge_t<C1, C2>, S> {};

} // namespace eagine::units

#endif // EAGINE_UNITS_CUSTOM_UNIT_HPP
