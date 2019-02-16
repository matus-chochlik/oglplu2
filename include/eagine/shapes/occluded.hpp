/**
 *  @file eagine/shapes/occluded.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_OCCLUDED_HPP
#define EAGINE_SHAPES_OCCLUDED_HPP

#include "delegated.hpp"
#include <eagine/config/basic.hpp>
#include <utility>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
class occluded_gen : public delegated_gen {

public:
    occluded_gen(std::unique_ptr<generator_intf>&& gen) noexcept
      : delegated_gen(std::move(gen)) {
    }

    void attrib_values(vertex_attrib_kind attr, span<float> dest) override;

private:
    span_size_t _samples{8};
};
//------------------------------------------------------------------------------
static inline auto occlude(std::unique_ptr<generator_intf>&& gen) noexcept {
    return std::unique_ptr<generator_intf>(new occluded_gen(std::move(gen)));
}
//------------------------------------------------------------------------------

} // namespace shapes
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/shapes/occluded.inl>
#endif

#endif // EAGINE_SHAPES_OCCLUDED_HPP
