/**
 *  @file eagine/shapes/screen.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_SCREEN_1509260923_HPP
#define EAGINE_SHAPES_SCREEN_1509260923_HPP

#include "gen_base.hpp"
#include <eagine/config/basic.hpp>
#include <cassert>

namespace eagine {
namespace shapes {

class unit_screen_gen : public centered_unit_shape_generator_base {
private:
    typedef centered_unit_shape_generator_base _base;

    static vertex_attrib_bits _attr_mask() noexcept;

public:
    unit_screen_gen(vertex_attrib_bits attr_bits) noexcept;

    span_size_t vertex_count() override;

    void positions(span<float> dest) noexcept;

    void normals(span<float> dest) noexcept;

    void tangentials(span<float> dest) noexcept;

    void bitangentials(span<float> dest) noexcept;

    void face_coords(span<float> dest) noexcept;

    void attrib_values(vertex_attrib_kind attr, span<float> dest) override;

    index_data_type index_type() override;

    span_size_t index_count() override;

    void indices(span<unsigned> dest) override;

    span_size_t operation_count() override;

    void instructions(span<draw_operation> ops) override;
};

} // namespace shapes
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/shapes/screen.inl>
#endif

#endif // include guard
