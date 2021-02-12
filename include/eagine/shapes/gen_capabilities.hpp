/// @file eagine/shapes/gen_capabilities.hpp
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
enum class generator_capability {
    element_strips,
    element_fans,
    primitive_restart
};
//------------------------------------------------------------------------------
using generator_capabilities = bitfield<generator_capability>;
//------------------------------------------------------------------------------
static constexpr auto
operator|(generator_capability a, generator_capability b) noexcept
  -> generator_capabilities {
    return {a, b};
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#endif // EAGINE_SHAPES_GEN_CAPABILITIES_HPP
