/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_UNITS_UNIT_SI_INFORMATION_HPP
#define EAGINE_UNITS_UNIT_SI_INFORMATION_HPP

#include "common.hpp"

namespace eagine::units {
namespace base {

// bit
struct bit : unit<amount_of_information, bit> {};

// byte
using byte = scaled_unit<scales::constant<8>, bit>;

} // namespace base

template <>
struct name_of<base::bit> {
    static constexpr const char mp_str[] = "bit";
};
template <>
struct symbol_of<base::bit> {
    static constexpr const char mp_str[] = "b";
};

template <>
struct name_of<base::byte> {
    static constexpr const char mp_str[] = "byte";
};
template <>
struct symbol_of<base::byte> {
    static constexpr const char mp_str[] = "B";
};

// si::base_unit<amount_of_information>
template <>
struct si::base_unit<base::amount_of_information> : base::bit {};

using bit = unit<amount_of_information, si>;

using byte = make_scaled_base_dim_unit_t<
  base::scaled_unit<scales::constant<8>, base::bit>,
  si>;

using kilobyte = make_scaled_base_dim_unit_t<
  base::
    scaled_unit<scales::recombined<scales::kilo, scales::constant<8>>, base::bit>,
  si>;

using kibibyte = make_scaled_base_dim_unit_t<
  base::
    scaled_unit<scales::recombined<scales::kibi, scales::constant<8>>, base::bit>,
  si>;

using megabyte = make_scaled_base_dim_unit_t<
  base::
    scaled_unit<scales::recombined<scales::mega, scales::constant<8>>, base::bit>,
  si>;

using mebibyte = make_scaled_base_dim_unit_t<
  base::
    scaled_unit<scales::recombined<scales::mebi, scales::constant<8>>, base::bit>,
  si>;

} // namespace eagine::units

#endif // EAGINE_UNITS_UNIT_SI_INFORMATION_HPP
