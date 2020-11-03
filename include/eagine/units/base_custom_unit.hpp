/**
 *  @file eagine/unit/base_custom_unit.hpp
 *
 */

#ifndef EAGINE_UNITS_BASE_CUSTOM_UNIT_HPP
#define EAGINE_UNITS_BASE_CUSTOM_UNIT_HPP

#include "base_unit.hpp"

namespace eagine::units::base {

template <typename Conv, typename Unit>
struct custom_unit {
    using dimension = dimension_of_t<Unit>;
    using conversion = Conv;
    using type = custom_unit;
};

} // namespace eagine::units::base

#endif // EAGINE_UNITS_BASE_CUSTOM_UNIT_HPP
