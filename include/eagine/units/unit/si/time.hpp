/**
 *  @file eagine/units/unit/si/time.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_TIME_HPP
#define EAGINE_UNITS_UNIT_SI_TIME_HPP

#include "common.hpp"

namespace eagine::units {
namespace base {

// second
struct second : unit<time, second> {};

// minute
using minute = scaled_unit<scales::constant<60>, second>;

// hour
using hour = scaled_unit<scales::constant<3600>, second>;

// day
using day = scaled_unit<scales::constant<86400>, second>;

} // namespace base

template <>
struct name_of<base::second> {
    static constexpr const char mp_str[] = "second";
};
template <>
struct symbol_of<base::second> {
    static constexpr const char mp_str[] = "s";
};

template <>
struct name_of<base::minute> {
    static constexpr const char mp_str[] = "minute";
};
template <>
struct symbol_of<base::minute> {
    static constexpr const char mp_str[] = "min";
};

template <>
struct name_of<base::hour> {
    static constexpr const char mp_str[] = "hour";
};
template <>
struct symbol_of<base::hour> {
    static constexpr const char mp_str[] = "hr";
};

template <>
struct name_of<base::day> {
    static constexpr const char mp_str[] = "day";
};
template <>
struct symbol_of<base::day> {
    static constexpr const char mp_str[] = "D";
};

// si::base_unit<time>
template <>
struct si::base_unit<base::time> : base::second {};

using second = unit<time, si>;

// derived
using millisecond =
  make_scaled_base_dim_unit_t<base::scaled_unit<scales::milli, base::second>, si>;

using minute = make_scaled_base_dim_unit_t<base::minute, si>;
using hour = make_scaled_base_dim_unit_t<base::hour, si>;
using day = make_scaled_base_dim_unit_t<base::day, si>;

} // namespace eagine::units

#endif // EAGINE_UNITS_UNIT_SI_TIME_HPP
