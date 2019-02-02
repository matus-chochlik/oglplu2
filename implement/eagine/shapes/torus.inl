/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <eagine/math/constants.hpp>
#include <cassert>
#include <cmath>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdouble-promotion"
#endif

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
vertex_attrib_bits unit_torus_gen::_attr_mask() noexcept {
    return vertex_attrib_kind::position | vertex_attrib_kind::normal |
           vertex_attrib_kind::tangential | vertex_attrib_kind::bitangential |
           vertex_attrib_kind::pivot | vertex_attrib_kind::vertex_pivot |
           vertex_attrib_kind::box_coord | vertex_attrib_kind::wrap_coord_0;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
unit_torus_gen::unit_torus_gen(
  vertex_attrib_bits attr_bits,
  valid_if_greater_than<int, 4> rings,
  valid_if_greater_than<int, 3> sections,
  valid_if_ge0_lt1<float> radius_ratio) noexcept
  : _base(attr_bits & _attr_mask())
  , _rings(span_size_t(rings.value()))
  , _sections(span_size_t(sections.value()))
  , _radius_ratio(radius_ratio.value()) {
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
span_size_t unit_torus_gen::vertex_count() {
    return (_rings + 1) * (_sections + 1);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_torus_gen::positions(span<float> dest) noexcept {
    assert(has(vertex_attrib_kind::position));
    assert(dest.size() >= vertex_count() * 3);

    span_size_t k = 0;

    const auto ro = 0.50;
    const auto ri = ro * _radius_ratio;
    const auto r1 = ri;
    const auto r2 = ro - ri;

    const auto s_step = 2 * math::pi / _sections;
    const auto r_step = 2 * math::pi / _rings;

    for(span_size_t s = 0; s < (_sections + 1); ++s) {
        const auto vx = std::cos(s * s_step);
        const auto vz = -std::sin(s * s_step);

        for(span_size_t r = 0; r < (_rings + 1); ++r) {
            const auto vr = -std::cos(r * r_step);
            const auto vy = std::sin(r * r_step);

            dest[k++] = float(vx * (r1 + r2 * (1 + vr)));
            dest[k++] = float(vy * r2);
            dest[k++] = float(vz * (r1 + r2 * (1 + vr)));
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_torus_gen::vertex_pivots(span<float> dest) noexcept {
    assert(has(vertex_attrib_kind::position));
    assert(dest.size() >= vertex_count() * 3);

    span_size_t k = 0;

    const auto ro = 0.50;
    const auto ri = ro * _radius_ratio;
    const auto rc = (ro + ri) / 2;

    const auto s_step = 2 * math::pi / _sections;

    for(span_size_t s = 0; s < (_sections + 1); ++s) {
        const auto vx = std::cos(s * s_step) * rc;
        const auto vz = -std::sin(s * s_step) * rc;

        for(span_size_t r = 0; r < (_rings + 1); ++r) {
            dest[k++] = float(vx);
            dest[k++] = float(0);
            dest[k++] = float(vz);
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_torus_gen::normals(span<float> dest) noexcept {
    assert(has(vertex_attrib_kind::normal));
    assert(dest.size() >= vertex_count() * 3);

    span_size_t k = 0;

    const auto s_step = 2 * math::pi / _sections;
    const auto r_step = 2 * math::pi / _rings;

    for(span_size_t s = 0; s < (_sections + 1); ++s) {
        const auto nx = std::cos(s * s_step);
        const auto nz = -std::sin(s * s_step);

        for(span_size_t r = 0; r < (_rings + 1); ++r) {
            const auto nr = -std::cos(r * r_step);
            const auto ny = std::sin(r * r_step);

            dest[k++] = float(nx * nr);
            dest[k++] = float(ny);
            dest[k++] = float(nz * nr);
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_torus_gen::tangentials(span<float> dest) noexcept {
    assert(has(vertex_attrib_kind::tangential));
    assert(dest.size() >= vertex_count() * 3);

    span_size_t k = 0;

    const auto s_step = 2 * math::pi / _sections;

    for(span_size_t s = 0; s < (_sections + 1); ++s) {
        const auto tx = -std::sin(s * s_step);
        const auto tz = -std::cos(s * s_step);

        for(span_size_t r = 0; r < (_rings + 1); ++r) {
            dest[k++] = float(tx);
            dest[k++] = float(0);
            dest[k++] = float(tz);
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_torus_gen::bitangentials(span<float> dest) noexcept {
    assert(has(vertex_attrib_kind::bitangential));
    assert(dest.size() >= vertex_count() * 3);

    span_size_t k = 0;

    const auto s_step = 2 * math::pi / _sections;
    const auto r_step = 2 * math::pi / _rings;
    const auto ty = 0;

    for(span_size_t s = 0; s < (_sections + 1); ++s) {
        const auto tx = -std::sin(s * s_step);
        const auto tz = -std::cos(s * s_step);

        for(span_size_t r = 0; r < (_rings + 1); ++r) {
            const auto nr = -std::cos(r * r_step);
            const auto ny = std::sin(r * r_step);
            const auto nx = -tz * nr;
            const auto nz = tx * nr;

            dest[k++] = float(ny * tz - nz * ty);
            dest[k++] = float(nz * tx - nx * tz);
            dest[k++] = float(nx * ty - ny * tx);
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_torus_gen::wrap_coords(span<float> dest) noexcept {
    assert(has(vertex_attrib_kind::wrap_coord_0));
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
void unit_torus_gen::attrib_values(vertex_attrib_kind attr, span<float> dest) {
    switch(attr) {
        case vertex_attrib_kind::position:
            positions(dest);
            break;
        case vertex_attrib_kind::vertex_pivot:
            vertex_pivots(dest);
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
        case vertex_attrib_kind::wrap_coord_0:
            wrap_coords(dest);
            break;
        case vertex_attrib_kind::pivot:
        case vertex_attrib_kind::box_coord:
        case vertex_attrib_kind::face_coord:
        case vertex_attrib_kind::wrap_coord_1:
        case vertex_attrib_kind::wrap_coord_2:
        case vertex_attrib_kind::wrap_coord_3:
        case vertex_attrib_kind::object_id:
        case vertex_attrib_kind::material_id:
            generator_base::attrib_values(attr, dest);
            break;
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
index_data_type unit_torus_gen::index_type() {
    if(index_count() < span_size(std::numeric_limits<std::uint8_t>::max())) {
        return index_data_type::unsigned_8;
    }
    if(index_count() < span_size(std::numeric_limits<std::uint16_t>::max())) {
        return index_data_type::unsigned_16;
    }
    return index_data_type::unsigned_32;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
span_size_t unit_torus_gen::index_count() {
    return _sections * ((_rings + 1) * 2 + (primitive_restart() ? 1 : 0));
}
//------------------------------------------------------------------------------
template <typename T>
void unit_torus_gen::_indices(span<T> dest) noexcept {
    assert(dest.size() >= index_count());

    const auto pri = limit_cast<T>(vertex_count());
    span_size_t k = 0;
    span_size_t step = _rings + 1;

    for(span_size_t s = 0; s < _sections; ++s) {
        for(span_size_t r = 0; r < step; ++r) {
            dest[k++] = limit_cast<T>((s + 0) * step + r);
            dest[k++] = limit_cast<T>((s + 1) * step + r);
        }

        if(primitive_restart()) {
            dest[k++] = pri;
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_torus_gen::indices(span<std::uint8_t> dest) {
    _indices(dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_torus_gen::indices(span<std::uint16_t> dest) {
    _indices(dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_torus_gen::indices(span<std::uint32_t> dest) {
    _indices(dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
span_size_t unit_torus_gen::operation_count() {
    if(primitive_restart()) {
        return 1;
    } else {
        return _sections;
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_torus_gen::instructions(span<draw_operation> ops) {
    assert(ops.size() >= operation_count());

    if(primitive_restart()) {
        draw_operation& op = ops[0];
        op.mode = primitive_type::triangle_strip;
        op.idx_type = index_type();
        op.first = 0;
        op.count = index_count();
        op.primitive_restart_index = unsigned(vertex_count());
        op.primitive_restart = true;
        op.cw_face_winding = true;
    } else {
        span_size_t step = 2 * (_rings + 1);
        for(span_size_t s = 0; s < _sections; ++s) {
            draw_operation& op = ops[s];
            op.mode = primitive_type::triangle_strip;
            op.idx_type = index_type();
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
