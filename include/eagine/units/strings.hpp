/**
 *  @file eagine/unit/strings.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_STRINGS_1512222148_HPP
#define EAGINE_UNITS_STRINGS_1512222148_HPP

#include "../cstr_ref.hpp"
#include "../fixed_size_str.hpp"
#include "../mp_string.hpp"
#include "detail.hpp"
#include "fwd.hpp"

namespace eagine {
namespace units {
namespace base {

template <typename Derived>
static inline cstr_ref get_dim_name(dimension<Derived>) noexcept {
    return mp_make_string<dim_name<Derived>>::value;
}

template <typename Dimension, typename Derived>
static inline cstr_ref get_unit_name(unit<Dimension, Derived>) noexcept {
    return mp_make_string<unit_name<Derived>>::value;
}

} // namespace base

namespace scales {

template <typename Scale>
static inline cstr_ref get_scale_name(Scale) noexcept {
    return mp_make_string<scale_name<Scale>>::value;
}

template <typename Scale>
static inline cstr_ref get_scale_symbol(Scale) noexcept {
    return mp_make_string<scale_symbol<Scale>>::value;
}

} // namespace scales

template <typename H, typename T>
static inline cstr_ref get_dim_name(bits::dims<H, T>) noexcept {
    return mp_make_string<dim_name<bits::dims<H, T>>>::value;
}

} // namespace units
} // namespace eagine

#endif // include guard
