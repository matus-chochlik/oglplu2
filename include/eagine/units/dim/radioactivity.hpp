/**
 *  @file eagine/unit/dim/radioactivity.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_DIM_RADIOACTIVITY_HPP
#define EAGINE_UNITS_DIM_RADIOACTIVITY_HPP

#include "../dimension.hpp"

namespace eagine {
namespace units {

using radioactivity = decltype(number_of_decays() / time());

template <>
struct name_of<radioactivity> {
    static constexpr const char mp_str[] = "radioactivity";
};

} // namespace units
} // namespace eagine

#endif // EAGINE_UNITS_DIM_RADIOACTIVITY_HPP
