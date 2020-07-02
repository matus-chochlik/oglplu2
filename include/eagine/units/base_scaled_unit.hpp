/**
 *  @file eagine/unit/base_scaled_unit.hpp
 *
 */

#ifndef EAGINE_UNITS_BASE_SCALED_UNIT_HPP
#define EAGINE_UNITS_BASE_SCALED_UNIT_HPP

#include "base_unit.hpp"

namespace eagine::units::base {

template <typename Scale, typename Unit>
struct scaled_unit {
    using dimension = dimension_of_t<Unit>;
    using scale = Scale;
    using type = scaled_unit;
};

} // namespace eagine::units::base

#endif // EAGINE_UNITS_BASE_SCALED_UNIT_HPP
