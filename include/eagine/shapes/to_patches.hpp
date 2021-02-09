/**
 *  @file eagine/shapes/to_patches.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_TO_PATCHES_HPP
#define EAGINE_SHAPES_TO_PATCHES_HPP

#include "delegated.hpp"
#include <eagine/config/basic.hpp>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
class to_patches_gen : public delegated_gen {

public:
    to_patches_gen(std::unique_ptr<generator_intf>&& gen) noexcept
      : delegated_gen(std::move(gen)) {}

    void instructions(drawing_variant, span<draw_operation> ops) override;
};
//------------------------------------------------------------------------------
static inline auto to_patches(std::unique_ptr<generator_intf>&& gen) noexcept {
    return std::make_unique<to_patches_gen>(std::move(gen));
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/shapes/to_patches.inl>
#endif

#endif // EAGINE_SHAPES_TO_PATCHES_HPP
