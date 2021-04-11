/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include <eagine/assert.hpp>
#include <eagine/math/tvec.hpp>
#include <eagine/memory/span_algo.hpp>

#ifdef __clang__
EAGINE_DIAG_PUSH()
EAGINE_DIAG_OFF(double-promotion)
#endif

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto unit_round_cube_gen::_attr_mask() noexcept -> vertex_attrib_bits {
    return vertex_attrib_kind::position | vertex_attrib_kind::normal |
           vertex_attrib_kind::tangential | vertex_attrib_kind::bitangential |
           vertex_attrib_kind::pivot | vertex_attrib_kind::box_coord;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
unit_round_cube_gen::unit_round_cube_gen(
  vertex_attrib_bits attr_bits,
  int divisions) noexcept
  : _base{attr_bits & _attr_mask()}
  , _divisions{divisions} {
    EAGINE_ASSERT(_divisions > 0);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto unit_round_cube_gen::vertex_count() -> span_size_t {
    return 6 * (_divisions + 1) * (_divisions + 1);
}
//------------------------------------------------------------------------------
static inline auto unit_round_cube_face_normal(span_size_t f) noexcept {
    return std::array<math::tvec<float, 3, true>, 6>{{
      {-1.F, 0.F, 0.F},
      {+1.F, 0.F, 0.F},
      {0.F, -1.F, 0.F},
      {0.F, +1.F, 0.F},
      {0.F, 0.F, -1.F},
      {0.F, 0.F, +1.F},
    }}[f];
}
//------------------------------------------------------------------------------
static inline auto unit_round_cube_face_tangential(span_size_t f) noexcept {
    return std::array<math::tvec<float, 3, true>, 6>{{
      {0.F, 0.F, +1.F},
      {0.F, 0.F, -1.F},
      {+1.F, 0.F, 0.F},
      {+1.F, 0.F, 0.F},
      {-1.F, 0.F, 0.F},
      {+1.F, 0.F, 0.F},
    }}[f];
}
//------------------------------------------------------------------------------
static inline auto unit_round_cube_face_bitangential(span_size_t f) noexcept {
    return std::array<math::tvec<float, 3, true>, 6>{{
      {0.F, +1.F, 0.F},
      {0.F, +1.F, 0.F},
      {0.F, 0.F, +1.F},
      {0.F, 0.F, -1.F},
      {0.F, +1.F, 0.F},
      {0.F, +1.F, 0.F},
    }}[f];
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_round_cube_gen::positions(span<float> dest) noexcept {
    span_size_t k = 0;

    EAGINE_ASSERT(dest.size() >= vertex_count() * 3);

    auto frac = [this](int q) {
        return float(q) / float(_divisions) - 0.5F;
    };

    for(auto f : integer_range(6)) {
        const auto vx = unit_round_cube_face_tangential(f);
        const auto vy = unit_round_cube_face_bitangential(f);
        const auto vz = unit_round_cube_face_normal(f);
        for(auto y : integer_range(_divisions + 1)) {
            const float j = frac(y);
            for(auto x : integer_range(_divisions + 1)) {
                const float i = frac(x);
                const auto vp = normalized((vz * 0.5F) + (vy * j) + (vx * i));
                dest[k++] = vp.x();
                dest[k++] = vp.y();
                dest[k++] = vp.z();
            }
        }
    }

    EAGINE_ASSERT(k == vertex_count() * 3);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_round_cube_gen::normals(span<float> dest) noexcept {
    EAGINE_ASSERT(has(vertex_attrib_kind::normal));
    positions(dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_round_cube_gen::face_coords(span<float> dest) noexcept {
    EAGINE_ASSERT(has(vertex_attrib_kind::face_coord));
    EAGINE_ASSERT(dest.size() >= vertex_count() * 3);

    span_size_t k = 0;

    for(auto f : integer_range(6)) {
        const auto l = _divisions + 1;
        for(auto y : integer_range(l)) {
            const float j = float(y) / float(_divisions);
            for(auto x : integer_range(l)) {
                const float i = float(x) / float(_divisions);
                dest[k++] = i;
                dest[k++] = j;
                dest[k++] = float(f);
            }
        }
    }
    EAGINE_ASSERT(k == vertex_count() * 3);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_round_cube_gen::attrib_values(
  vertex_attrib_variant vav,
  span<float> dest) {
    switch(vav.attribute()) {
        case vertex_attrib_kind::position:
            positions(dest);
            break;
        case vertex_attrib_kind::normal:
            normals(dest);
            break;
        case vertex_attrib_kind::face_coord:
            face_coords(dest);
            break;
        case vertex_attrib_kind::tangential:
        case vertex_attrib_kind::bitangential:
        case vertex_attrib_kind::pivot:
        case vertex_attrib_kind::pivot_pivot:
        case vertex_attrib_kind::vertex_pivot:
        case vertex_attrib_kind::object_id:
        case vertex_attrib_kind::polygon_id:
        case vertex_attrib_kind::material_id:
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
auto unit_round_cube_gen::index_count(drawing_variant) -> span_size_t {
    if(primitive_restart()) {
        return 6 * _divisions * ((_divisions + 1) * 2 + 1);
    }
    return 6 * _divisions * (_divisions + 1) * 2;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto unit_round_cube_gen::index_type(drawing_variant var) -> index_data_type {
    if(index_count(var) < span_size(std::numeric_limits<std::uint8_t>::max())) {
        return index_data_type::unsigned_8;
    }
    if(index_count(var) < span_size(std::numeric_limits<std::uint16_t>::max())) {
        return index_data_type::unsigned_16;
    }
    return index_data_type::unsigned_32;
}
//------------------------------------------------------------------------------
template <typename T>
inline void
unit_round_cube_gen::_indices(drawing_variant var, span<T> dest) noexcept {
    EAGINE_ASSERT(var == 0);
    EAGINE_ASSERT(dest.size() >= index_count(var));
    EAGINE_MAYBE_UNUSED(var);

    span_size_t k = 0;
    for(auto f : integer_range(6)) {
        for(auto d : integer_range(_divisions)) {
            for(auto l : integer_range(_divisions + 1)) {
                for(auto s : integer_range(2)) {
                    dest[k++] = limit_cast<T>(
                      (f * (_divisions + 1) * (_divisions + 1)) +
                      ((d + s) * (_divisions + 1)) + l);
                }
            }
            if(primitive_restart()) {
                dest[k++] = vertex_count();
            }
        }
    }

    EAGINE_ASSERT(k == index_count(var));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_round_cube_gen::indices(drawing_variant var, span<std::uint8_t> dest) {
    _indices(var, dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_round_cube_gen::indices(
  drawing_variant var,
  span<std::uint16_t> dest) {
    _indices(var, dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_round_cube_gen::indices(
  drawing_variant var,
  span<std::uint32_t> dest) {
    _indices(var, dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto unit_round_cube_gen::operation_count(drawing_variant) -> span_size_t {
    if(primitive_restart()) {
        return 1;
    }
    return 6 * _divisions;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_round_cube_gen::instructions(
  drawing_variant var,
  span<draw_operation> ops) {
    EAGINE_ASSERT(ops.size() >= operation_count(var));

    if(primitive_restart()) {
        draw_operation& op = ops[0];
        op.mode = primitive_type::triangle_strip;
        op.idx_type = index_type(var);
        op.first = 0;
        op.count = index_count(var);
        op.primitive_restart_index = unsigned(vertex_count());
        op.primitive_restart = true;
    } else {
        span_size_t o = 0;
        span_size_t offs = 0;
        const span_size_t len = (_divisions + 1) * 2;
        for(auto f : integer_range(6)) {
            EAGINE_MAYBE_UNUSED(f);
            for(auto d : integer_range(_divisions)) {
                EAGINE_MAYBE_UNUSED(d);
                draw_operation& op = ops[o++];
                op.mode = primitive_type::triangle_strip;
                op.idx_type = index_type(var);
                op.first = offs;
                op.count = len;
                op.primitive_restart = false;
                offs += len;
            }
        }
        EAGINE_ASSERT(offs == index_count(var));
        EAGINE_ASSERT(o == operation_count(var));
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto unit_round_cube_gen::bounding_sphere() -> math::sphere<float, true> {
    using std::sqrt;
    return {{0.0F}, float(1)};
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#ifdef __clang__
EAGINE_DIAG_POP()
#endif
