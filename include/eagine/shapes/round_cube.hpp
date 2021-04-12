/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_SHAPES_ROUND_CUBE_HPP
#define EAGINE_SHAPES_ROUND_CUBE_HPP

#include "gen_base.hpp"
#include <eagine/config/basic.hpp>
#include <cassert>
#include <memory>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
/// @brief Generator of centered, subdivided and rounded cube shape with unit radius.
/// @ingroup shapes
/// @see unit_round_cube
class unit_round_cube_gen : public centered_unit_shape_generator_base {
public:
    unit_round_cube_gen(vertex_attrib_bits attr_bits, int divisions) noexcept;

    auto vertex_count() -> span_size_t override;

    void positions(span<float> dest) noexcept;

    void normals(span<float> dest) noexcept;

    void face_coords(span<float> dest) noexcept;

    void attrib_values(vertex_attrib_variant, span<float>) override;

    auto index_type(drawing_variant) -> index_data_type override;

    auto index_count(drawing_variant) -> span_size_t override;

    void indices(drawing_variant, span<std::uint8_t> dest) override;

    void indices(drawing_variant, span<std::uint16_t> dest) override;

    void indices(drawing_variant, span<std::uint32_t> dest) override;

    auto operation_count(drawing_variant) -> span_size_t override;

    void instructions(drawing_variant, span<draw_operation> ops) override;

    auto bounding_sphere() -> math::sphere<float, true> override;

private:
    using _base = centered_unit_shape_generator_base;

    static auto _attr_mask() noexcept -> vertex_attrib_bits;

    template <typename T>
    void _indices(drawing_variant, span<T> dest) noexcept;

    int _divisions;
};
//------------------------------------------------------------------------------
/// @brief Constructs instances of unit_round_cube_gen.
/// @ingroup shapes
/// @see from_value_tree
/// @see unit_cube
/// @see unit_icosahedron
/// @see unit_sphere
/// @see unit_torus
/// @see unit_twisted_torus
/// @see unit_screen
static inline auto unit_round_cube(vertex_attrib_bits attr_bits, int divisions) {
    return std::make_unique<unit_round_cube_gen>(attr_bits, divisions);
}
//------------------------------------------------------------------------------
static inline auto unit_round_cube(vertex_attrib_bits attr_bits) {
    return std::make_unique<unit_round_cube_gen>(attr_bits, 8);
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/shapes/round_cube.inl>
#endif

#endif // EAGINE_SHAPES_ROUND_CUBE_HPP
