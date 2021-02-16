/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_UNITS_UNIT_SI_ANGLE_HPP
#define EAGINE_UNITS_UNIT_SI_ANGLE_HPP

#include "common.hpp"

namespace eagine::units {
namespace base {

// radian
struct radian : unit<angle, radian> {};

// degree
using degree =
  scaled_unit<scales::divided<scales::pi, scales::constant<180>>, radian>;

// gradian
using gradian =
  scaled_unit<scales::divided<scales::pi, scales::constant<200>>, radian>;

// quarter
using quarter =
  scaled_unit<scales::multiplied<scales::pi, scales::rational<1, 2>>, radian>;

// turn
using turn =
  scaled_unit<scales::multiplied<scales::constant<2>, scales::pi>, radian>;

} // namespace base

template <>
struct name_of<base::radian> {
    static constexpr const char mp_str[] = "radian";
};

template <>
struct symbol_of<base::radian> {
    static constexpr const char mp_str[] = "rad";
};

template <>
struct name_of<base::degree> {
    static constexpr const char mp_str[] = "degree";
};

template <>
struct symbol_of<base::degree> {
    static constexpr const char mp_str[] = {char(0xC2), char(0xB0), '\0'};
};

template <>
struct name_of<base::gradian> {
    static constexpr const char mp_str[] = "gradian";
};

template <>
struct symbol_of<base::gradian> {
    static constexpr const char mp_str[] = "grad";
};

template <>
struct name_of<base::quarter> {
    static constexpr const char mp_str[] = "quarter";
};

template <>
struct symbol_of<base::quarter> {
    static constexpr const char mp_str[] = "Q";
};

template <>
struct name_of<base::turn> {
    static constexpr const char mp_str[] = "turn";
};

template <>
struct symbol_of<base::turn> {
    static constexpr const char mp_str[] = "r";
};

// si::base_unit<angle>
template <>
struct si::base_unit<base::angle> : base::radian {};

// radian
using radian = unit<angle, si>;

// derived
using degree = make_scaled_base_dim_unit_t<base::degree, si>;
using gradian = make_scaled_base_dim_unit_t<base::gradian, si>;
using quarter = make_scaled_base_dim_unit_t<base::quarter, si>;
using turn = make_scaled_base_dim_unit_t<base::turn, si>;

using pi_rad =
  make_scaled_base_dim_unit_t<base::scaled_unit<scales::pi, base::radian>, si>;

} // namespace eagine::units

#endif // EAGINE_UNITS_UNIT_SI_ANGLE_HPP
