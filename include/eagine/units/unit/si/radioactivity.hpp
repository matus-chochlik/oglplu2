/// @file eagine/units/unit/si/radioactivity.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_UNITS_UNIT_SI_RADIOACTIVITY_HPP
#define EAGINE_UNITS_UNIT_SI_RADIOACTIVITY_HPP

#include "../../dim/radioactivity.hpp"
#include "common.hpp"

namespace eagine::units {
namespace base {

struct count_of_decays : unit<number_of_decays, count_of_decays> {};

} // namespace base

// si::base_unit<angle>
template <>
struct si::base_unit<base::number_of_decays> : base::count_of_decays {};

// count of decays
using count_of_decays = unit<number_of_decays, si>;

// becquerel
using becquerel = unit<radioactivity, si>;

template <>
struct name_of<becquerel> {
    static constexpr const char mp_str[] = "becquerel";
};

template <>
struct symbol_of<becquerel> {
    static constexpr const char mp_str[] = "Bq";
};

// derived
using kilobecquerel = make_scaled_unit_t<scales::kilo, becquerel>;
using megabecquerel = make_scaled_unit_t<scales::mega, becquerel>;
using gigabecquerel = make_scaled_unit_t<scales::giga, becquerel>;
// TODO

} // namespace eagine::units

#endif // EAGINE_UNITS_UNIT_SI_RADIOACTIVITY_HPP
