/**
 *  @file eagine/shapes/icosahedron.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_ICOSAHEDRON_HPP
#define EAGINE_SHAPES_ICOSAHEDRON_HPP

#include "gen_base.hpp"
#include <eagine/config/basic.hpp>
#include <cassert>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
class unit_icosahedron_gen : public centered_unit_shape_generator_base {
private:
    using _base = centered_unit_shape_generator_base;

    static vertex_attrib_bits _attr_mask() noexcept;

    static vertex_attrib_bits _shared_attrs() noexcept;

    bool _only_shared_attribs() noexcept;

    template <typename T>
    void _indices(span<T> dest) noexcept;

public:
    unit_icosahedron_gen(vertex_attrib_bits attr_bits) noexcept;

    span_size_t vertex_count() override;

    void positions(span<float> dest) noexcept;

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
static inline auto unit_icosahedron(vertex_attrib_bits attr_bits) {
    return std::make_unique<unit_icosahedron_gen>(attr_bits);
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/shapes/icosahedron.inl>
#endif

#endif // EAGINE_SHAPES_ICOSAHEDRON_HPP
