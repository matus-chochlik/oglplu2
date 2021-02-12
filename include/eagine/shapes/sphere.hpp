/// @file eagine/shapes/sphere.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

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

    static auto _attr_mask() noexcept -> vertex_attrib_bits;

    template <typename T>
    void _indices(drawing_variant, span<T> dest) noexcept;

public:
    unit_sphere_gen(
      vertex_attrib_bits attr_bits,
      valid_if_greater_than<int, 2> rings,
      valid_if_greater_than<int, 3> sections) noexcept;

    unit_sphere_gen(vertex_attrib_bits attr_bits) noexcept
      : unit_sphere_gen(attr_bits, 12, 18) {}

    auto vertex_count() -> span_size_t override;

    void positions(span<float> dest) noexcept;

    void normals(span<float> dest) noexcept;

    void tangentials(span<float> dest) noexcept;

    void bitangentials(span<float> dest) noexcept;

    void wrap_coords(span<float> dest) noexcept;

    void attrib_values(vertex_attrib_variant, span<float>) override;

    auto index_type(drawing_variant) -> index_data_type override;

    auto index_count(drawing_variant) -> span_size_t override;

    void indices(drawing_variant, span<std::uint8_t> dest) override;

    void indices(drawing_variant, span<std::uint16_t> dest) override;

    void indices(drawing_variant, span<std::uint32_t> dest) override;

    auto operation_count(drawing_variant) -> span_size_t override;

    void instructions(drawing_variant, span<draw_operation> ops) override;

    auto bounding_sphere() -> math::sphere<float, true> override;

    void ray_intersections(
      drawing_variant,
      span<const math::line<float, true>> rays,
      span<optionally_valid<float>> intersections) override;
};
//------------------------------------------------------------------------------
static inline auto unit_sphere(
  vertex_attrib_bits attr_bits,
  valid_if_greater_than<int, 2> rings,
  valid_if_greater_than<int, 3> sections) {
    return std::make_unique<unit_sphere_gen>(
      attr_bits, std::move(rings), std::move(sections));
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/shapes/sphere.inl>
#endif

#endif // EAGINE_SHAPES_SPHERE_HPP
