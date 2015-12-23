/**
 *  @file eagine/unit/base_unit.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNIT_BASE_UNIT_1308281038_HPP
#define EAGINE_UNIT_BASE_UNIT_1308281038_HPP

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

template <typename Unit>
struct unit_info;

} // namespace base
} // namespace units
} // namespace eagine

#endif //include guard

