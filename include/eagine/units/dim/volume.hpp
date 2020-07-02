/**
 *  @file eagine/unit/dim/volume.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_DIM_VOLUME_HPP
#define EAGINE_UNITS_DIM_VOLUME_HPP

#include "../dimension.hpp"

namespace eagine::units {

using volume = decltype(length() * length() * length());

template <>
struct name_of<volume> {
    static constexpr const char mp_str[] = "volume";
};

} // namespace eagine::units

#endif // EAGINE_UNITS_DIM_VOLUME_HPP
