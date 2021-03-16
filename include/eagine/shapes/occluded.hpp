/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_SHAPES_OCCLUDED_HPP
#define EAGINE_SHAPES_OCCLUDED_HPP

#include "delegated.hpp"
#include <eagine/config/basic.hpp>
#include <utility>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
/// @brief Generator modifier calculating vertex occlusion weights.
/// @ingroup shapes
/// @see occlude
class occluded_gen : public delegated_gen {

public:
    occluded_gen(std::shared_ptr<generator> gen, span_size_t samples) noexcept
      : delegated_gen{std::move(gen)}
      , _samples{samples} {}

    void attrib_values(vertex_attrib_variant, span<float>) override;

private:
    span_size_t _samples{64};
};
//------------------------------------------------------------------------------
/// @brief Constructs instances of occluded_gen modifier.
/// @ingroup shapes
static inline auto
occlude(std::shared_ptr<generator> gen, span_size_t samples = 8) noexcept {
    return std::make_unique<occluded_gen>(std::move(gen), samples);
}
//------------------------------------------------------------------------------

} // namespace shapes
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/shapes/occluded.inl>
#endif

#endif // EAGINE_SHAPES_OCCLUDED_HPP
