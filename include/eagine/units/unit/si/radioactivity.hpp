/**
 *  @file eagine/units/unit/si/radioactivity.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_RADIOACTIVITY_1512222148_HPP
#define EAGINE_UNITS_UNIT_SI_RADIOACTIVITY_1512222148_HPP

#include "common.hpp"
#include "../../dim/radioactivity.hpp"

namespace eagine {
namespace units {

// becquerel
typedef unit<radioactivity, si> becquerel;

template <>
struct unit_name<becquerel>
{
	static constexpr const char mp_str[] = "becquerel";
};

template <>
struct unit_symbol<becquerel>
{
	static constexpr const char mp_str[] = "Bq";
};

// derived
// TODO

} // namespace units
} // namespace eagine

#endif //include guard

