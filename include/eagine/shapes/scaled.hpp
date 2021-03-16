/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_SHAPES_SCALED_HPP
#define EAGINE_SHAPES_SCALED_HPP

#include "delegated.hpp"
#include <eagine/config/basic.hpp>
#include <array>
#include <memory>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
/// @brief Generator modifier scaling the generated vertices by specifed amount.
/// @ingroup shapes
/// @see translate
class scaled_gen : public delegated_gen {

public:
    scaled_gen(std::shared_ptr<generator> gen, std::array<float, 3> s) noexcept
      : delegated_gen{std::move(gen)}
      , _s{s} {}

    void attrib_values(vertex_attrib_variant, span<float>) override;

    auto bounding_sphere() -> math::sphere<float, true> override;

private:
    std::array<float, 3> _s;
};
//------------------------------------------------------------------------------
/// @brief Constructs instances of scaled_gen modifier.
/// @ingroup shapes
static inline auto
scale(std::shared_ptr<generator> gen, std::array<float, 3> s) noexcept {
    return std::make_unique<scaled_gen>(std::move(gen), s);
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/shapes/scaled.inl>
#endif

#endif // EAGINE_SHAPES_SCALED_HPP
