/// @file eagine/shapes/screen.inl
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include <eagine/assert.hpp>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdouble-promotion"
#endif

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto unit_screen_gen::_attr_mask() noexcept -> vertex_attrib_bits {
    return vertex_attrib_kind::position | vertex_attrib_kind::normal |
           vertex_attrib_kind::tangential | vertex_attrib_kind::bitangential |
           vertex_attrib_kind::wrap_coord | vertex_attrib_kind::face_coord |
           vertex_attrib_kind::box_coord;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
unit_screen_gen::unit_screen_gen(vertex_attrib_bits attr_bits) noexcept
  : _base(attr_bits & _attr_mask()) {}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto unit_screen_gen::vertex_count() -> span_size_t {
    return 4;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_screen_gen::positions(span<float> dest) noexcept {
    EAGINE_ASSERT(dest.size() >= vertex_count() * 3);

    /*
     * [-1, 1] [ 1, 1]
     *    (1)---(3)
     *     | \   |
     *     |  \  |
     *     |   \ |
     *    (0)---(2)
     * [-1,-1] [ 1,-1]
     */

    span_size_t k = 0;
    // (0)
    dest[k++] = -1.F;
    dest[k++] = -1.F;
    dest[k++] = 0.F;
    // (1)
    dest[k++] = -1.F;
    dest[k++] = 1.F;
    dest[k++] = 0.F;
    // (2)
    dest[k++] = 1.F;
    dest[k++] = -1.F;
    dest[k++] = 0.F;
    // (3)
    dest[k++] = 1.F;
    dest[k++] = 1.F;
    dest[k++] = 0.F;

    EAGINE_ASSERT(k == vertex_count() * 3);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_screen_gen::normals(span<float> dest) noexcept {
    EAGINE_ASSERT(has(vertex_attrib_kind::normal));
    EAGINE_ASSERT(dest.size() >= vertex_count() * 3);

    span_size_t k = 0;
    for(auto i : integer_range(4)) {
        EAGINE_MAYBE_UNUSED(i);
        dest[k++] = 0.F;
        dest[k++] = 0.F;
        dest[k++] = 1.F;
    }

    EAGINE_ASSERT(k == vertex_count() * 3);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_screen_gen::tangentials(span<float> dest) noexcept {
    EAGINE_ASSERT(has(vertex_attrib_kind::tangential));
    EAGINE_ASSERT(dest.size() >= vertex_count() * 3);

    span_size_t k = 0;
    for(auto i : integer_range(4)) {
        EAGINE_MAYBE_UNUSED(i);
        dest[k++] = 1.F;
        dest[k++] = 0.F;
        dest[k++] = 0.F;
    }

    EAGINE_ASSERT(k == vertex_count() * 3);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_screen_gen::bitangentials(span<float> dest) noexcept {
    EAGINE_ASSERT(has(vertex_attrib_kind::bitangential));
    EAGINE_ASSERT(dest.size() >= vertex_count() * 3);

    span_size_t k = 0;
    for(auto i : integer_range(4)) {
        EAGINE_MAYBE_UNUSED(i);
        dest[k++] = 0.F;
        dest[k++] = 1.F;
        dest[k++] = 0.F;
    }

    EAGINE_ASSERT(k == vertex_count() * 3);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_screen_gen::face_coords(span<float> dest) noexcept {
    EAGINE_ASSERT(has(vertex_attrib_kind::face_coord));
    EAGINE_ASSERT(dest.size() >= vertex_count() * 2);

    /*
     *  [0, 1]  [1, 1]
     *    (1)---(3)
     *     | \   |
     *     |  \  |
     *     |   \ |
     *    (0)---(2)
     *  [0, 0]  [1, 0]
     */

    span_size_t k = 0;
    // (0)
    dest[k++] = 0.F;
    dest[k++] = 0.F;
    // (1)
    dest[k++] = 0.F;
    dest[k++] = 1.F;
    // (2)
    dest[k++] = 1.F;
    dest[k++] = 0.F;
    // (3)
    dest[k++] = 1.F;
    dest[k++] = 1.F;

    EAGINE_ASSERT(k == vertex_count() * 2);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_screen_gen::attrib_values(
  vertex_attrib_variant vav,
  span<float> dest) {
    switch(vav.attrib) {
        case vertex_attrib_kind::position:
            positions(dest);
            break;
        case vertex_attrib_kind::normal:
            normals(dest);
            break;
        case vertex_attrib_kind::tangential:
            tangentials(dest);
            break;
        case vertex_attrib_kind::bitangential:
            bitangentials(dest);
            break;
        case vertex_attrib_kind::box_coord:
        case vertex_attrib_kind::face_coord:
        case vertex_attrib_kind::wrap_coord:
            face_coords(dest);
            break;
        case vertex_attrib_kind::pivot:
        case vertex_attrib_kind::pivot_pivot:
        case vertex_attrib_kind::vertex_pivot:
        case vertex_attrib_kind::object_id:
        case vertex_attrib_kind::polygon_id:
        case vertex_attrib_kind::material_id:
        case vertex_attrib_kind::weight:
        case vertex_attrib_kind::color:
        case vertex_attrib_kind::occlusion:
            _base::attrib_values(vav, dest);
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto unit_screen_gen::operation_count(drawing_variant) -> span_size_t {
    return 1;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_screen_gen::instructions(
  drawing_variant var,
  span<draw_operation> ops) {
    EAGINE_ASSERT(ops.size() >= operation_count(var));
    EAGINE_MAYBE_UNUSED(var);

    draw_operation& op = ops[0];
    op.mode = primitive_type::triangle_strip;
    op.idx_type = index_data_type::none;
    op.first = 0;
    op.count = vertex_count();
    op.primitive_restart = false;
    op.cw_face_winding = true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto unit_screen_gen::bounding_sphere() -> math::sphere<float, true> {
    using std::sqrt;
    return {{0.0F}, float(sqrt(2.F))};
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#ifdef __clang__
#pragma clang diagnostic pop
#endif
