/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include <eagine/assert.hpp>
#include <eagine/math/constants.hpp>

#ifdef __clang__
EAGINE_DIAG_PUSH()
EAGINE_DIAG_OFF(double-promotion)
#endif

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto unit_icosahedron_gen::_attr_mask() noexcept -> vertex_attrib_bits {
    return vertex_attrib_kind::position | vertex_attrib_kind::normal |
           vertex_attrib_kind::box_coord;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto unit_icosahedron_gen::_shared_attrs() noexcept -> vertex_attrib_bits {
    return vertex_attrib_kind::position | vertex_attrib_kind::normal |
           vertex_attrib_kind::box_coord;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto unit_icosahedron_gen::_only_shared_attribs() noexcept -> bool {
    return !(attrib_bits() & ~_shared_attrs());
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
unit_icosahedron_gen::unit_icosahedron_gen(vertex_attrib_bits attr_bits) noexcept
  : _base(attr_bits & _attr_mask()) {}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto unit_icosahedron_gen::vertex_count() -> span_size_t {
    return 12;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_icosahedron_gen::positions(span<float> dest) noexcept {
    EAGINE_ASSERT(dest.size() >= vertex_count() * 3);

    span_size_t k = 0;

    const auto il = 1.0 / std::sqrt(1.0 + std::pow(math::phi, 2.0));
    const decltype(il) q[3] = {0.0, il, math::phi * il};

    /*
     *        ^(y)
     *        |
     *  (D)-------(C)  (E)-------(F)    (I)-------(J)
     *   |    |    |    |         |      |         |
     *(z)|    |    |    |         | (x)  |         | (y)
     *<--|---(x)   |    |   (y)---|-->   |   (z)---|-->
     *   |         |    |    |    |      |    |    |
     *   |         |    |    |    |      |    |    |
     *  (B)-------(A)  (G)-------(H)    (K)-------(L)
     *                       |                |
     *                       v(z)             v(x)
     */

    const span_size_t qi[3][3] = {{0, 2, 1}, {1, 0, 2}, {2, 1, 0}};
    const float ps = 1.F;
    const float ns = -1.F;

    for(const auto& qip : qi) {
        for(int v = 0; v < 4; ++v) {
            const float sv[3] = {
              0.F, v % 2 == 0 ? ns : ps, v / 2 == 0 ? ns : ps};
            for(const auto qci : qip) {
                dest[k++] = float(sv[qci] * q[qci]);
            }
        }
    }

    EAGINE_ASSERT(k == vertex_count() * 3);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_icosahedron_gen::normals(span<float> dest) noexcept {
    EAGINE_ASSERT(dest.size() >= vertex_count() * 3);
    positions(dest);
    for(auto& x : head(dest, vertex_count() * 3)) {
        x *= 2.F;
    }
}
//------------------------------------------------------------------------------
void unit_icosahedron_gen::attrib_values(
  vertex_attrib_variant vav,
  span<float> dest) {
    switch(vav.attribute()) {
        case vertex_attrib_kind::position:
            positions(dest);
            break;
        case vertex_attrib_kind::normal:
            normals(dest);
            break;
        case vertex_attrib_kind::pivot:
        case vertex_attrib_kind::vertex_pivot:
        case vertex_attrib_kind::pivot_pivot:
        case vertex_attrib_kind::object_id:
        case vertex_attrib_kind::polygon_id:
        case vertex_attrib_kind::material_id:
        case vertex_attrib_kind::tangential:
        case vertex_attrib_kind::bitangential:
        case vertex_attrib_kind::face_coord:
        case vertex_attrib_kind::box_coord:
        case vertex_attrib_kind::wrap_coord:
        case vertex_attrib_kind::weight:
        case vertex_attrib_kind::color:
        case vertex_attrib_kind::occlusion:
            _base::attrib_values(vav, dest);
            break;
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto unit_icosahedron_gen::index_type(drawing_variant) -> index_data_type {
    return index_data_type::unsigned_8;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto unit_icosahedron_gen::index_count(drawing_variant) -> span_size_t {
    return 20 * 3;
}
//------------------------------------------------------------------------------
template <typename T>
void unit_icosahedron_gen::_indices(drawing_variant var, span<T> dest) noexcept {
    EAGINE_ASSERT(dest.size() >= index_count(var));
    EAGINE_MAYBE_UNUSED(var);

    span_size_t k = 0;

    const T A = 0, B = 1, C = 2, D = 3;
    const T E = 4, F = 5, G = 6, H = 7;
    const T I = 8, J = 9, K = 10, L = 11;

    dest[k++] = E;
    dest[k++] = F;
    dest[k++] = A;
    dest[k++] = F;
    dest[k++] = E;
    dest[k++] = C;
    dest[k++] = H;
    dest[k++] = G;
    dest[k++] = B;
    dest[k++] = G;
    dest[k++] = H;
    dest[k++] = D;

    dest[k++] = I;
    dest[k++] = J;
    dest[k++] = E;
    dest[k++] = J;
    dest[k++] = I;
    dest[k++] = G;
    dest[k++] = L;
    dest[k++] = K;
    dest[k++] = F;
    dest[k++] = K;
    dest[k++] = L;
    dest[k++] = H;

    dest[k++] = A;
    dest[k++] = B;
    dest[k++] = I;
    dest[k++] = B;
    dest[k++] = A;
    dest[k++] = K;
    dest[k++] = D;
    dest[k++] = C;
    dest[k++] = J;
    dest[k++] = C;
    dest[k++] = D;
    dest[k++] = L;

    dest[k++] = A;
    dest[k++] = I;
    dest[k++] = E;
    dest[k++] = A;
    dest[k++] = F;
    dest[k++] = K;
    dest[k++] = C;
    dest[k++] = E;
    dest[k++] = J;
    dest[k++] = C;
    dest[k++] = L;
    dest[k++] = F;
    dest[k++] = B;
    dest[k++] = G;
    dest[k++] = I;
    dest[k++] = B;
    dest[k++] = K;
    dest[k++] = H;
    dest[k++] = D;
    dest[k++] = J;
    dest[k++] = G;
    dest[k++] = D;
    dest[k++] = H;
    dest[k++] = L;

    EAGINE_ASSERT(k == index_count(var));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_icosahedron_gen::indices(
  drawing_variant var,
  span<std::uint8_t> dest) {
    _indices(var, dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_icosahedron_gen::indices(
  drawing_variant var,
  span<std::uint16_t> dest) {
    _indices(var, dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_icosahedron_gen::indices(
  drawing_variant var,
  span<std::uint32_t> dest) {
    _indices(var, dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto unit_icosahedron_gen::operation_count(drawing_variant) -> span_size_t {
    return 1;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_icosahedron_gen::instructions(
  drawing_variant var,
  span<draw_operation> ops) {
    EAGINE_ASSERT(ops.size() >= operation_count(var));

    draw_operation& op = ops[0];
    op.mode = primitive_type::triangles;
    op.idx_type = index_data_type::unsigned_8;
    op.first = 0;
    op.count = index_count(var);
    op.primitive_restart = false;
    op.cw_face_winding = false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto unit_icosahedron_gen::bounding_sphere() -> math::sphere<float, true> {
    return {{0.0F}, 0.5F};
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#ifdef __clang__
EAGINE_DIAG_POP()
#endif
