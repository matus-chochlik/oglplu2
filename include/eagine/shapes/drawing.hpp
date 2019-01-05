/**
 *  @file eagine/shapes/drawing.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_DRAWING_HPP
#define EAGINE_SHAPES_DRAWING_HPP

#include "../types.hpp"

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
enum class primitive_type {
    points,
    lines,
    line_strip,
    line_loop,
    triangles,
    triangle_strip,
    triangle_fan,
    patches
};
//------------------------------------------------------------------------------
enum class index_data_type { none, unsigned_8, unsigned_16, unsigned_32 };
//------------------------------------------------------------------------------
struct draw_operation {
    primitive_type mode{primitive_type::points};
    index_data_type idx_type{index_data_type::none};
    span_size_t first{0};
    span_size_t count{0};
    unsigned phase{0};
    unsigned primitive_restart_index{0};
    bool primitive_restart : 1;
    bool cw_face_winding : 1;

    constexpr draw_operation() noexcept
      : primitive_restart(false)
      , cw_face_winding(false) {
    }
};
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#endif // EAGINE_SHAPES_DRAWING_HPP
