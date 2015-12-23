/**
 *  @file eagine/unit/dimensionless.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_DIMLESS_1512222148_HPP
#define EAGINE_UNITS_DIMLESS_1512222148_HPP

#include "fwd.hpp"
#include "detail.hpp"

namespace eagine {
namespace units {

typedef bits::dimless dimensionless;

template <>
struct unit_info<dimensionless>
{
	static const char name[] = "dimensionless";
};

} // namespace units
} // namespace eagine

#endif //include guard

