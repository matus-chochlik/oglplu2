/**
 *  @file eagine/shapes/sphere.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_SPHERE_HPP
#define EAGINE_SHAPES_SPHERE_HPP

#include "../config/basic.hpp"
#include "../valid_if/greater_than.hpp"
#include "gen_base.hpp"
#include <cassert>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
class unit_sphere_gen : public centered_unit_shape_generator_base {
private:
    using _base = centered_unit_shape_generator_base;

    span_size_t _rings;
    span_size_t _sections;

    static vertex_attrib_bits _attr_mask() noexcept;

    template <typename T>
    void _indices(span<T> dest) noexcept;

public:
    unit_sphere_gen(
      vertex_attrib_bits attr_bits,
      valid_if_greater_than<int, 2> rings,
      valid_if_greater_than<int, 3> sections) noexcept;

    unit_sphere_gen(vertex_attrib_bits attr_bits) noexcept
      : unit_sphere_gen(attr_bits, 12, 18) {
    }

    span_size_t vertex_count() override;

    void positions(span<float> dest) noexcept;

    void normals(span<float> dest) noexcept;

    void tangentials(span<float> dest) noexcept;

    void bitangentials(span<float> dest) noexcept;

    void wrap_coords(span<float> dest) noexcept;

    void attrib_values(vertex_attrib_kind attr, span<float> dest) override;

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
static inline auto unit_sphere(
  vertex_attrib_bits attr_bits,
  valid_if_greater_than<int, 2> rings,
  valid_if_greater_than<int, 3> sections) {
    return std::unique_ptr<generator_intf>{
      new unit_sphere_gen(attr_bits, rings, sections)};
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/shapes/sphere.inl>
#endif

#endif // EAGINE_SHAPES_SPHERE_HPP
