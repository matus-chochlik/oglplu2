/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include <eagine/assert.hpp>
#include <eagine/math/constants.hpp>
#include <eagine/math/intersection.hpp>
#include <cmath>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdouble-promotion"
#endif

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto unit_sphere_gen::_attr_mask() noexcept -> vertex_attrib_bits {
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
  , _sections(span_size_t(sections.value())) {}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto unit_sphere_gen::vertex_count() -> span_size_t {
    return (_rings + 1) * (_sections + 1);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_sphere_gen::positions(span<float> dest) noexcept {
    EAGINE_ASSERT(has(vertex_attrib_kind::position));
    EAGINE_ASSERT(dest.size() >= vertex_count() * 3);

    span_size_t k = 0;

    const auto s_step = 2 * math::pi / _sections;
    const auto r_step = 1 * math::pi / _rings;

    for(auto s : integer_range(_sections + 1)) {
        for(auto r : integer_range(_rings + 1)) {
            const auto r_lat = std::cos(r * r_step);
            const auto r_rad = std::sin(r * r_step);

            dest[k++] = float(0.5F * r_rad * std::cos(s * s_step));
            dest[k++] = float(0.5F * r_lat);
            dest[k++] = float(0.5F * r_rad * -std::sin(s * s_step));
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_sphere_gen::normals(span<float> dest) noexcept {
    EAGINE_ASSERT(has(vertex_attrib_kind::normal));
    EAGINE_ASSERT(dest.size() >= vertex_count() * 3);

    span_size_t k = 0;

    const auto s_step = 2 * math::pi / _sections;
    const auto r_step = 1 * math::pi / _rings;

    for(auto s : integer_range(_sections + 1)) {
        for(auto r : integer_range(_rings + 1)) {
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
void unit_sphere_gen::tangentials(span<float> dest) noexcept {
    EAGINE_ASSERT(has(vertex_attrib_kind::tangential));
    EAGINE_ASSERT(dest.size() >= vertex_count() * 3);

    span_size_t k = 0;

    const auto s_step = 2 * math::pi / _sections;

    for(auto s : integer_range(_sections + 1)) {
        auto x = -std::sin(s * s_step);
        auto z = -std::cos(s * s_step);

        for(auto r : integer_range(_rings + 1)) {
            EAGINE_MAYBE_UNUSED(r);
            dest[k++] = float(x);
            dest[k++] = float(0);
            dest[k++] = float(z);
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_sphere_gen::bitangentials(span<float> dest) noexcept {
    EAGINE_ASSERT(has(vertex_attrib_kind::bitangential));
    EAGINE_ASSERT(dest.size() >= vertex_count() * 3);

    span_size_t k = 0;

    const auto s_step = 2 * math::pi / _sections;
    const auto r_step = 1 * math::pi / _rings;
    const auto ty = 0;

    for(auto s : integer_range(_sections + 1)) {
        for(auto r : integer_range(_rings + 1)) {
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
void unit_sphere_gen::wrap_coords(span<float> dest) noexcept {
    EAGINE_ASSERT(has(vertex_attrib_kind::wrap_coord));
    EAGINE_ASSERT(dest.size() >= vertex_count() * 2);

    span_size_t k = 0;

    const auto s_step = 1.F / _sections;
    const auto r_step = 1.F / _rings;

    for(auto s : integer_range(_sections + 1)) {
        for(auto r : integer_range(_rings + 1)) {
            dest[k++] = s * s_step;
            dest[k++] = r * r_step;
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_sphere_gen::attrib_values(
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
        case vertex_attrib_kind::wrap_coord:
            wrap_coords(dest);
            break;
        case vertex_attrib_kind::pivot:
        case vertex_attrib_kind::pivot_pivot:
        case vertex_attrib_kind::vertex_pivot:
        case vertex_attrib_kind::box_coord:
        case vertex_attrib_kind::face_coord:
        case vertex_attrib_kind::object_id:
        case vertex_attrib_kind::polygon_id:
        case vertex_attrib_kind::material_id:
        case vertex_attrib_kind::weight:
        case vertex_attrib_kind::color:
        case vertex_attrib_kind::occlusion:
            _base::attrib_values(vav, dest);
            break;
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto unit_sphere_gen::index_type(drawing_variant v) -> index_data_type {
    if(index_count(v) < span_size(std::numeric_limits<std::uint8_t>::max())) {
        return index_data_type::unsigned_8;
    }
    if(index_count(v) < span_size(std::numeric_limits<std::uint16_t>::max())) {
        return index_data_type::unsigned_16;
    }
    return index_data_type::unsigned_32;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto unit_sphere_gen::index_count(drawing_variant) -> span_size_t {
    return _sections * ((_rings + 1) * 2 + (primitive_restart() ? 1 : 0));
}
//------------------------------------------------------------------------------
template <typename T>
void unit_sphere_gen::_indices(drawing_variant var, span<T> dest) noexcept {
    EAGINE_ASSERT(dest.size() >= index_count(var));
    EAGINE_MAYBE_UNUSED(var);

    const auto pri = limit_cast<T>(vertex_count());
    span_size_t k = 0;
    span_size_t step = _rings + 1;

    for(auto s : integer_range(_sections + 1)) {
        for(auto r : integer_range(step)) {
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
void unit_sphere_gen::indices(drawing_variant var, span<std::uint8_t> dest) {
    _indices(var, dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_sphere_gen::indices(drawing_variant var, span<std::uint16_t> dest) {
    _indices(var, dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_sphere_gen::indices(drawing_variant var, span<std::uint32_t> dest) {
    _indices(var, dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto unit_sphere_gen::operation_count(drawing_variant) -> span_size_t {
    if(primitive_restart()) {
        return 1;
    } else {
        return _sections;
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_sphere_gen::instructions(
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
        op.cw_face_winding = true;
    } else {
        span_size_t step = 2 * (_rings + 1);
        for(auto s : integer_range(_sections)) {
            draw_operation& op = ops[s];
            op.mode = primitive_type::triangle_strip;
            op.idx_type = index_type(var);
            op.first = s * step;
            op.count = step;
            op.primitive_restart = false;
            op.cw_face_winding = true;
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto unit_sphere_gen::bounding_sphere() -> math::sphere<float, true> {
    return {{0.F, 0.F, 0.F}, 0.5F};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_sphere_gen::ray_intersections(
  drawing_variant,
  span<const math::line<float, true>> rays,
  span<optionally_valid<float>> intersections) {

    EAGINE_ASSERT(intersections.size() >= rays.size());

    const auto bs = bounding_sphere();

    for(auto i : integer_range(intersections.size())) {
        const auto& ray = rays[i];
        const auto nparam = math::nearest_ray_param(
          math::line_sphere_intersection_params(ray, bs));
        if(nparam > 0.0001F) {
            auto& oparam = intersections[i];
            if(!oparam || bool(nparam < oparam)) {
                oparam = nparam;
            }
        }
    }
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#ifdef __clang__
#pragma clang diagnostic pop
#endif
