/**
 *  @file eagine/shapes/torus.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_TORUS_HPP
#define EAGINE_SHAPES_TORUS_HPP

#include "../callable_ref.hpp"
#include "../config/basic.hpp"
#include "../valid_if/ge0_lt1.hpp"
#include "../valid_if/greater_than.hpp"
#include "gen_base.hpp"
#include <array>
#include <cassert>
#include <memory>

namespace eagine {
namespace shapes {

class unit_torus_gen : public centered_unit_shape_generator_base {
private:
    using _base = centered_unit_shape_generator_base;

    const std::size_t _r_seed{1234};
    const std::size_t _s_seed{2345};
    span_size_t _rings;
    span_size_t _sections;
    float _radius_ratio;

    static vertex_attrib_bits _attr_mask() noexcept;

    template <typename T>
    void _indices(span<T> dest) noexcept;

public:
    unit_torus_gen(
      vertex_attrib_bits attr_bits,
      valid_if_greater_than<int, 4> rings,
      valid_if_greater_than<int, 3> sections,
      valid_if_ge0_lt1<float> radius_ratio) noexcept;

    unit_torus_gen(
      vertex_attrib_bits attr_bits,
      valid_if_greater_than<int, 4> rings,
      valid_if_greater_than<int, 3> sections) noexcept
      : unit_torus_gen(attr_bits, std::move(rings), std::move(sections), 0.5f) {
    }

    unit_torus_gen(vertex_attrib_bits attr_bits) noexcept
      : unit_torus_gen(attr_bits, 24, 36) {
    }

    using offset_getter =
      callable_ref<std::array<float, 3>(span_size_t, span_size_t)>;

    span_size_t vertex_count() override;

    void vertex_pivots(span<float> dest) noexcept;

    void positions(span<float> dest, offset_getter) noexcept;

    void normals(span<float> dest, offset_getter) noexcept;

    void tangentials(span<float> dest, offset_getter) noexcept;

    void bitangentials(span<float> dest, offset_getter) noexcept;

    void wrap_coords(span<float> dest) noexcept;

    span_size_t attribute_variants(vertex_attrib_kind attrib) override;

    void attrib_values(vertex_attrib_kind, span_size_t, span<float>) override;

    index_data_type index_type() override;

    span_size_t index_count() override;

    void indices(span<std::uint8_t> dest) override;

    void indices(span<std::uint16_t> dest) override;

    void indices(span<std::uint32_t> dest) override;

    span_size_t operation_count() override;

    void instructions(span<draw_operation> ops) override;

    math::sphere<float, true> bounding_sphere() override;
};
//------------------------------------------------------------------------------
static inline auto unit_torus(
  vertex_attrib_bits attr_bits,
  valid_if_greater_than<int, 4> rings,
  valid_if_greater_than<int, 3> sections,
  valid_if_ge0_lt1<float> radius_ratio) {
    return std::make_unique<unit_torus_gen>(
      attr_bits,
      std::move(rings),
      std::move(sections),
      std::move(radius_ratio));
}
//------------------------------------------------------------------------------
static inline auto unit_torus(vertex_attrib_bits attr_bits) {
    return unit_torus(attr_bits, 18, 36, 0.5f);
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/shapes/torus.inl>
#include <utility>
#endif

#endif // EAGINE_SHAPES_TORUS_HPP
