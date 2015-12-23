/**
 *  @file eagine/unit/base_unit.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_BASE_UNIT_1512222148_HPP
#define EAGINE_UNITS_BASE_UNIT_1512222148_HPP

#include "base_dim.hpp"

namespace eagine {
namespace units {
namespace base {

template <typename Dimension, typename Derived>
struct unit
{
	typedef Dimension dimension;
	typedef scales::one scale;
	typedef Derived type;
};

} // namespace base
} // namespace units
} // namespace eagine

#endif //include guard

