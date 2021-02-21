/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_SHAPES_GEN_CAPABILITIES_HPP
#define EAGINE_SHAPES_GEN_CAPABILITIES_HPP

#include "../bitfield.hpp"
#include "../types.hpp"

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
/// @brief Shape generator capability bit enumeration.
/// @ingroup shapes
/// @see generator_capabilities
enum class generator_capability {
    /// @brief Line or triangle strips should be generated if possible.
    element_strips,
    /// @brief Line or triangle fanst should be generated if possible.
    element_fans,
    /// @brief Primitive restart functionality should be used if possible.
    primitive_restart
};
//------------------------------------------------------------------------------
/// @brief Alias for generator_capability bitfield type.
/// @ingroup shapes
using generator_capabilities = bitfield<generator_capability>;
//------------------------------------------------------------------------------
/// @brief Bitwise-or operator for generator_capability enumerators.
/// @ingroup shapes
static constexpr auto
operator|(generator_capability a, generator_capability b) noexcept
  -> generator_capabilities {
    return {a, b};
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#endif // EAGINE_SHAPES_GEN_CAPABILITIES_HPP
