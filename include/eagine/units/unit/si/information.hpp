/**
 *  @file eagine/units/unit/si/information.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_INFORMATION_1512222148_HPP
#define EAGINE_UNITS_UNIT_SI_INFORMATION_1512222148_HPP

#include "common.hpp"

namespace eagine {
namespace units {
namespace base {

// bit
struct bit : unit<amount_of_information, bit> { };

template <>
struct unit_name<bit>
{
	static constexpr const char mp_str[] = "bit";
};
template <>
struct unit_symbol<bit>
{
	static constexpr const char mp_str[] = "b";
};

// byte
typedef scaled_unit<scales::constant<8>, bit> byte;

template <>
struct unit_name<byte>
{
	static constexpr const char mp_str[] = "byte";
};
template <>
struct unit_symbol<byte>
{
	static constexpr const char mp_str[] = "B";
};

} // namespace base

// si::base_unit<amount_of_information>
template <>
struct si::base_unit<base::amount_of_information>
 : base::bit
{ };

typedef unit<amount_of_information, si> bit;

typedef make_scaled_base_dim_unit_t<
	base::scaled_unit<scales::constant<8>, base::bit>,
	si
> byte;

typedef make_scaled_base_dim_unit_t<
	base::scaled_unit<
		scales::recombined<scales::kilo, scales::constant<8>>,
		base::bit
	>, si
> kilobyte;

typedef make_scaled_base_dim_unit_t<
	base::scaled_unit<
		scales::recombined<scales::kibi, scales::constant<8>>,
		base::bit
	>, si
> kibibyte;

typedef make_scaled_base_dim_unit_t<
	base::scaled_unit<
		scales::recombined<scales::mega, scales::constant<8>>,
		base::bit
	>, si
> megabyte;

typedef make_scaled_base_dim_unit_t<
	base::scaled_unit<
		scales::recombined<scales::mebi, scales::constant<8>>,
		base::bit
	>, si
> mebibyte;


} // namespace units
} // namespace eagine

#endif //include guard

