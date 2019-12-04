/**
 *  @file eagine/unit/strings.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_STRINGS_HPP
#define EAGINE_UNITS_STRINGS_HPP

#include "../fixed_size_str.hpp"
#include "../mp_string.hpp"
#include "../string_span.hpp"
#include "detail.hpp"
#include "fwd.hpp"

namespace eagine {
namespace units {
namespace base {
//------------------------------------------------------------------------------
template <typename Derived>
static inline string_view get_dim_name(dimension<Derived>) noexcept {
    return mp_make_string<dim_name<Derived>>::value;
}
//------------------------------------------------------------------------------
template <typename Dimension, typename Derived>
static inline string_view get_unit_name(unit<Dimension, Derived>) noexcept {
    return mp_make_string<unit_name<Derived>>::value;
}
//------------------------------------------------------------------------------
template <typename Dimension, typename Derived>
static inline string_view get_unit_symbol(unit<Dimension, Derived>) noexcept {
    return mp_make_string<unit_symbol<Derived>>::value;
}
//------------------------------------------------------------------------------
} // namespace base
//------------------------------------------------------------------------------
namespace scales {
//------------------------------------------------------------------------------
template <typename Scale>
static inline string_view get_scale_name(Scale) noexcept {
    return mp_make_string<scale_name<Scale>>::value;
}
//------------------------------------------------------------------------------
template <typename Scale>
static inline string_view get_scale_symbol(Scale) noexcept {
    return mp_make_string<scale_symbol<Scale>>::value;
}
//------------------------------------------------------------------------------
} // namespace scales
//------------------------------------------------------------------------------
template <typename H, typename T>
static inline string_view get_dim_name(bits::dims<H, T>) noexcept {
    return mp_make_string<dim_name<bits::dims<H, T>>>::value;
}
//------------------------------------------------------------------------------
template <typename Dim, typename Sys>
static inline auto get_dim_name(unit<Dim, Sys>) noexcept {
    return get_dim_name(Dim());
}
//------------------------------------------------------------------------------
template <typename BaseDim, typename Sys>
struct unit_name<unit<
  bits::dims<bits::dim_pow<BaseDim, int_constant<1>>, eagine::nothing_t>,
  Sys>> : base::unit_name<typename Sys::template base_unit<BaseDim>::type> {};
//------------------------------------------------------------------------------
template <typename Dim, typename Sys>
static inline auto get_unit_name(unit<Dim, Sys>) noexcept {
    return mp_make_string<unit_name<unit<Dim, Sys>>>::value;
}
//------------------------------------------------------------------------------
template <typename BaseDim, typename Sys>
struct unit_symbol<unit<
  bits::dims<bits::dim_pow<BaseDim, int_constant<1>>, eagine::nothing_t>,
  Sys>> : base::unit_symbol<typename Sys::template base_unit<BaseDim>::type> {};
//------------------------------------------------------------------------------
template <typename Dim, typename Sys>
static inline auto get_unit_symbol(unit<Dim, Sys>) noexcept {
    return mp_make_string<unit_symbol<unit<Dim, Sys>>>::value;
}
//------------------------------------------------------------------------------
} // namespace units
} // namespace eagine

#endif // EAGINE_UNITS_STRINGS_HPP
