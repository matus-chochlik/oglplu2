/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_UNITS_UNIT_SI_PRESSURE_HPP
#define EAGINE_UNITS_UNIT_SI_PRESSURE_HPP

#include "../../dim/pressure.hpp"
#include "common.hpp"
#include "length.hpp"
#include "mass.hpp"
#include "time.hpp"

namespace eagine::units {

// pascal
using pascal = unit<pressure, si>;

template <>
struct name_of<pascal> {
    static constexpr const char mp_str[] = "pascal";
};

template <>
struct symbol_of<pascal> {
    static constexpr const char mp_str[] = "Pa";
};

// derived
using kilopascal = make_scaled_unit_t<scales::kilo, pascal>;
using megapascal = make_scaled_unit_t<scales::mega, pascal>;
// TODO

} // namespace eagine::units

#endif // EAGINE_UNITS_UNIT_SI_PRESSURE_HPP
