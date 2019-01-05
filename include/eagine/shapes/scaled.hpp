/**
 *  @file eagine/shapes/scaled.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_SCALED_HPP
#define EAGINE_SHAPES_SCALED_HPP

#include "delegated.hpp"
#include <eagine/config/basic.hpp>
#include <array>
#include <memory>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
class scaled_gen : public delegated_gen {
private:
    std::array<float, 3> _s;

public:
    scaled_gen(
      std::unique_ptr<generator_intf>&& gen, std::array<float, 3> s) noexcept
      : delegated_gen(std::move(gen))
      , _s{s} {
    }

    void attrib_values(vertex_attrib_kind attr, span<float> dest) override;
};
//------------------------------------------------------------------------------
static inline auto scale(
  std::unique_ptr<generator_intf>&& gen, std::array<float, 3> s) noexcept {
    return std::unique_ptr<generator_intf>(new scaled_gen(std::move(gen), s));
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/shapes/scaled.inl>
#endif

#endif // EAGINE_SHAPES_SCALED_HPP
