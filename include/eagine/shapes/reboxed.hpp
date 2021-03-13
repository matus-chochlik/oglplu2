/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_SHAPES_REBOXED_HPP
#define EAGINE_SHAPES_REBOXED_HPP

#include "delegated.hpp"
#include <eagine/config/basic.hpp>
#include <utility>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
/// @brief Generator modifier recalculating the vertex box coords values.
/// @ingroup shapes
/// @see rebox
class reboxed_gen : public delegated_gen {

public:
    reboxed_gen(std::shared_ptr<generator> gen) noexcept
      : delegated_gen{std::move(gen)} {}

    void attrib_values(vertex_attrib_variant, span<float>) override;
};
//------------------------------------------------------------------------------
/// @brief Constructs instances of reboxed_gen modifier.
/// @ingroup shapes
static inline auto rebox(std::shared_ptr<generator> gen) noexcept {
    return std::make_unique<reboxed_gen>(std::move(gen));
}
//------------------------------------------------------------------------------

} // namespace shapes
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/shapes/reboxed.inl>
#endif

#endif // EAGINE_SHAPES_REBOXED_HPP
