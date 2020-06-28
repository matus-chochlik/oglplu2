/**
 *  @file eagine/unit/dim/frequency.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_DIM_FREQUENCY_HPP
#define EAGINE_UNITS_DIM_FREQUENCY_HPP

#include "../dimension.hpp"

namespace eagine {
namespace units {

using frequency = decltype(number_of_cycles() / time());

template <>
struct name_of<frequency> {
    static constexpr const char mp_str[] = "frequency";
};

} // namespace units
} // namespace eagine

#endif // EAGINE_UNITS_DIM_FREQUENCY_HPP
