/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <cassert>
#include <cmath>
#include <eagine/math/constants.hpp>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdouble-promotion"
#endif

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
vertex_attrib_bits
unit_sphere_gen::_attr_mask(void) noexcept {
    return vertex_attrib_kind::position | vertex_attrib_kind::normal |
           vertex_attrib_kind::tangential | vertex_attrib_kind::bitangential |
           vertex_attrib_kind::box_coord | vertex_attrib_kind::wrap_coord;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
unit_sphere_gen::unit_sphere_gen(
  vertex_attrib_bits attr_bits,
  valid_if_greater_than<int, 2> rings,
  valid_if_greater_than<int, 3> sections) noexcept
  : _base(attr_bits & _attr_mask())
  , _rings(span_size_t(rings.value()))
  , _sections(span_size_t(sections.value())) {
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
span_size_t
unit_sphere_gen::vertex_count(void) {
    return (_rings + 1) * (_sections + 1);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_sphere_gen::positions(const span<float>& dest) noexcept {
    assert(has(vertex_attrib_kind::position));
    assert(dest.size() >= vertex_count() * 3);

    span_size_t k = 0;

    const auto s_step = 2 * math::pi / _sections;
    const auto r_step = 1 * math::pi / _rings;

    for(span_size_t s = 0; s < (_sections + 1); ++s) {
        for(span_size_t r = 0; r < (_rings + 1); ++r) {
            const auto r_lat = std::cos(r * r_step);
            const auto r_rad = std::sin(r * r_step);

            dest[k++] = float(0.5f * r_rad * std::cos(s * s_step));
            dest[k++] = float(0.5f * r_lat);
            dest[k++] = float(0.5f * r_rad * -std::sin(s * s_step));
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_sphere_gen::normals(const span<float>& dest) noexcept {
    assert(has(vertex_attrib_kind::normal));
    assert(dest.size() >= vertex_count() * 3);

    span_size_t k = 0;

    const auto s_step = 2 * math::pi / _sections;
    const auto r_step = 1 * math::pi / _rings;

    for(span_size_t s = 0; s < (_sections + 1); ++s) {
        for(span_size_t r = 0; r < (_rings + 1); ++r) {
            const auto r_lat = std::cos(r * r_step);
            const auto r_rad = std::sin(r * r_step);

            dest[k++] = float(r_rad * std::cos(s * s_step));
            dest[k++] = float(r_lat);
            dest[k++] = float(r_rad * -std::sin(s * s_step));
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_sphere_gen::tangentials(const span<float>& dest) noexcept {
    assert(has(vertex_attrib_kind::tangential));
    assert(dest.size() >= vertex_count() * 3);

    span_size_t k = 0;

    const auto s_step = 2 * math::pi / _sections;

    for(span_size_t s = 0; s < (_sections + 1); ++s) {
        auto x = -std::sin(s * s_step);
        auto z = -std::cos(s * s_step);

        for(span_size_t r = 0; r < (_rings + 1); ++r) {
            dest[k++] = float(x);
            dest[k++] = float(0);
            dest[k++] = float(z);
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_sphere_gen::bitangentials(const span<float>& dest) noexcept {
    assert(has(vertex_attrib_kind::bitangential));
    assert(dest.size() >= vertex_count() * 3);

    span_size_t k = 0;

    const auto s_step = 2 * math::pi / _sections;
    const auto r_step = 1 * math::pi / _rings;
    const auto ty = 0;

    for(span_size_t s = 0; s < (_sections + 1); ++s) {
        for(span_size_t r = 0; r < (_rings + 1); ++r) {
            const auto r_rad = std::sin(r * r_step);
            const auto tx = -std::sin(s * s_step);
            const auto tz = -std::cos(s * s_step);
            const auto nx = -r_rad * tz;
            const auto ny = std::cos(r * r_step);
            const auto nz = r_rad * tx;

            dest[k++] = float(ny * tz - nz * ty);
            dest[k++] = float(nz * tx - nx * tz);
            dest[k++] = float(nx * ty - ny * tx);
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_sphere_gen::wrap_coords(const span<float>& dest) noexcept {
    assert(has(vertex_attrib_kind::wrap_coord));
    assert(dest.size() >= vertex_count() * 2);

    span_size_t k = 0;

    const auto s_step = 1.f / _sections;
    const auto r_step = 1.f / _rings;

    for(span_size_t s = 0; s < (_sections + 1); ++s) {
        for(span_size_t r = 0; r < (_rings + 1); ++r) {
            dest[k++] = s * s_step;
            dest[k++] = r * r_step;
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_sphere_gen::attrib_values(
  vertex_attrib_kind attr, const span<float>& dest) {
    switch(attr) {
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
        case vertex_attrib_kind::wrap_coord:
            wrap_coords(dest);
            break;
        case vertex_attrib_kind::box_coord:
        case vertex_attrib_kind::face_coord:
            _base::attrib_values(attr, dest);
            break;
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
index_data_type
unit_sphere_gen::index_type(void) {
    return index_data_type::unsigned_byte;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
span_size_t
unit_sphere_gen::index_count(void) {
    return _sections * ((_rings + 1) * 2 + (primitive_restart() ? 1 : 0));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_sphere_gen::indices(const span<unsigned>& dest) {
    assert(dest.size() >= index_count());

    const auto pri = unsigned(index_count());
    span_size_t k = 0;
    span_size_t step = _rings + 1;

    for(span_size_t s = 0; s < _sections; ++s) {
        for(span_size_t r = 0; r < step; ++r) {
            dest[k++] = unsigned((s + 0) * step + r);
            dest[k++] = unsigned((s + 1) * step + r);
        }

        if(primitive_restart()) {
            dest[k++] = pri;
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
span_size_t
unit_sphere_gen::operation_count(void) {
    if(primitive_restart()) {
        return 1;
    } else {
        return _sections;
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_sphere_gen::instructions(const span<draw_operation>& ops) {
    assert(ops.size() >= operation_count());

    if(primitive_restart()) {
        draw_operation& op = ops[0];
        op.mode = primitive_type::triangle_strip;
        op.idx_type = index_data_type::unsigned_int;
        op.first = 0;
        op.count = index_count();
        op.primitive_restart_index = unsigned(index_count());
        op.primitive_restart = true;
        op.cw_face_winding = true;
    } else {
        span_size_t step = 2 * (_rings + 1);
        for(span_size_t s = 0; s < _sections; ++s) {
            draw_operation& op = ops[s];
            op.mode = primitive_type::triangle_strip;
            op.idx_type = index_data_type::unsigned_int;
            op.first = s * step;
            op.count = step;
            op.primitive_restart = false;
            op.cw_face_winding = true;
        }
    }
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#ifdef __clang__
#pragma clang diagnostic pop
#endif
