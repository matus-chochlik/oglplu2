/**
 *  @file eagine/units/unit/si/information.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_INFORMATION_HPP
#define EAGINE_UNITS_UNIT_SI_INFORMATION_HPP

#include "common.hpp"

namespace eagine {
namespace units {
namespace base {

// bit
struct bit : unit<amount_of_information, bit> {};

template <>
struct unit_name<bit> {
    static constexpr const char mp_str[] = "bit";
};
template <>
struct unit_symbol<bit> {
    static constexpr const char mp_str[] = "b";
};

// byte
using byte = scaled_unit<scales::constant<8>, bit>;

template <>
struct unit_name<byte> {
    static constexpr const char mp_str[] = "byte";
};
template <>
struct unit_symbol<byte> {
    static constexpr const char mp_str[] = "B";
};

} // namespace base

// si::base_unit<amount_of_information>
template <>
struct si::base_unit<base::amount_of_information> : base::bit {};

using bit = unit<amount_of_information, si>;

using byte = make_scaled_base_dim_unit_t<
  base::scaled_unit<scales::constant<8>, base::bit>,
  si>;

using kilobyte = make_scaled_base_dim_unit_t<
  base::scaled_unit<
    scales::recombined<scales::kilo, scales::constant<8>>,
    base::bit>,
  si>;

using kibibyte = make_scaled_base_dim_unit_t<
  base::scaled_unit<
    scales::recombined<scales::kibi, scales::constant<8>>,
    base::bit>,
  si>;

using megabyte = make_scaled_base_dim_unit_t<
  base::scaled_unit<
    scales::recombined<scales::mega, scales::constant<8>>,
    base::bit>,
  si>;

using mebibyte = make_scaled_base_dim_unit_t<
  base::scaled_unit<
    scales::recombined<scales::mebi, scales::constant<8>>,
    base::bit>,
  si>;

} // namespace units
} // namespace eagine

#endif // EAGINE_UNITS_UNIT_SI_INFORMATION_HPP
