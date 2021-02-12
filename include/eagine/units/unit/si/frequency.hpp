/// @file eagine/units/unit/si/frequency.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_UNITS_UNIT_SI_FREQUENCY_HPP
#define EAGINE_UNITS_UNIT_SI_FREQUENCY_HPP

#include "../../dim/frequency.hpp"
#include "common.hpp"

namespace eagine::units {
namespace base {

struct count_of_cycles : unit<number_of_cycles, count_of_cycles> {};

} // namespace base

// si::base_unit<angle>
template <>
struct si::base_unit<base::number_of_cycles> : base::count_of_cycles {};

// hertz
using hertz = unit<frequency, si>;

template <>
struct name_of<hertz> {
    static constexpr const char mp_str[] = "hertz";
};

template <>
struct symbol_of<hertz> {
    static constexpr const char mp_str[] = "Hz";
};

// derived
using kilohertz = make_scaled_unit_t<scales::kilo, hertz>;
using megahertz = make_scaled_unit_t<scales::mega, hertz>;
using gigahertz = make_scaled_unit_t<scales::giga, hertz>;
// TODO

} // namespace eagine::units

#endif // EAGINE_UNITS_UNIT_SI_FREQUENCY_HPP
