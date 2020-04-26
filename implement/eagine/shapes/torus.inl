/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <eagine/assert.hpp>
#include <eagine/math/constants.hpp>
#include <cmath>
#include <random>

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
           vertex_attrib_kind::box_coord | vertex_attrib_kind::wrap_coord;
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
void unit_torus_gen::vertex_pivots(span<float> dest) noexcept {
    EAGINE_ASSERT(has(vertex_attrib_kind::position));
    EAGINE_ASSERT(dest.size() >= vertex_count() * 3);

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
void unit_torus_gen::positions(
  span<float> dest, unit_torus_gen::offset_getter get_offs) noexcept {
    EAGINE_ASSERT(has(vertex_attrib_kind::position));
    EAGINE_ASSERT(dest.size() >= vertex_count() * 3);

    const auto ro = 0.50;
    const auto ri = ro * _radius_ratio;
    const auto r1 = ri;
    const auto r2 = ro - ri;

    const auto s_step = 2 * math::pi / _sections;
    const auto r_step = 2 * math::pi / _rings;

    auto k = [this](span_size_t s, span_size_t r, span_size_t c) {
        return 3 * (s * (_rings + 1) + r) + c;
    };

    for(span_size_t s = 0; s < _sections; ++s) {
        for(span_size_t r = 0; r < _rings; ++r) {
            const auto [rd, sd, td] = get_offs(s, r);

            const auto vr = -std::cos((r + rd) * r_step);
            const auto vx = std::cos((s + sd) * s_step);
            const auto vy = std::sin((r + rd) * r_step);
            const auto vz = -std::sin((s + sd) * s_step);
            const auto rt = r2 * (1 + td);

            dest[k(s, r, 0)] = float(vx * (r1 + rt * (1 + vr)));
            dest[k(s, r, 1)] = float(vy * rt);
            dest[k(s, r, 2)] = float(vz * (r1 + rt * (1 + vr)));
        }
        dest[k(s, _rings, 0)] = dest[k(s, 0, 0)];
        dest[k(s, _rings, 1)] = dest[k(s, 0, 1)];
        dest[k(s, _rings, 2)] = dest[k(s, 0, 2)];
    }
    for(span_size_t r = 0; r <= _rings; ++r) {
        dest[k(_sections, r, 0)] = dest[k(0, r, 0)];
        dest[k(_sections, r, 1)] = dest[k(0, r, 1)];
        dest[k(_sections, r, 2)] = dest[k(0, r, 2)];
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_torus_gen::normals(
  span<float> dest, unit_torus_gen::offset_getter get_offs) noexcept {
    EAGINE_ASSERT(has(vertex_attrib_kind::normal));
    EAGINE_ASSERT(dest.size() >= vertex_count() * 3);

    const auto s_step = 2 * math::pi / _sections;
    const auto r_step = 2 * math::pi / _rings;

    auto k = [this](span_size_t s, span_size_t r, span_size_t c) {
        return 3 * (s * (_rings + 1) + r) + c;
    };

    for(span_size_t s = 0; s < _sections; ++s) {
        for(span_size_t r = 0; r < _rings; ++r) {
            const auto [rd, sd, td] = get_offs(s, r);
            EAGINE_MAYBE_UNUSED(td);

            const auto nr = -std::cos((r + rd) * r_step);
            const auto nx = std::cos((s + sd) * s_step);
            const auto ny = std::sin((r + rd) * r_step);
            const auto nz = -std::sin((s + sd) * s_step);

            dest[k(s, r, 0)] = float(nx * nr);
            dest[k(s, r, 1)] = float(ny);
            dest[k(s, r, 2)] = float(nz * nr);
        }
        dest[k(s, _rings, 0)] = dest[k(s, 0, 0)];
        dest[k(s, _rings, 1)] = dest[k(s, 0, 1)];
        dest[k(s, _rings, 2)] = dest[k(s, 0, 2)];
    }
    for(span_size_t r = 0; r <= _rings; ++r) {
        dest[k(_sections, r, 0)] = dest[k(0, r, 0)];
        dest[k(_sections, r, 1)] = dest[k(0, r, 1)];
        dest[k(_sections, r, 2)] = dest[k(0, r, 2)];
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_torus_gen::tangentials(
  span<float> dest, unit_torus_gen::offset_getter get_offs) noexcept {
    EAGINE_ASSERT(has(vertex_attrib_kind::tangential));
    EAGINE_ASSERT(dest.size() >= vertex_count() * 3);

    auto k = [this](span_size_t s, span_size_t r, span_size_t c) {
        return 3 * (s * (_rings + 1) + r) + c;
    };

    const auto s_step = 2 * math::pi / _sections;

    for(span_size_t s = 0; s < _sections; ++s) {
        for(span_size_t r = 0; r < _rings; ++r) {
            const auto [rd, sd, td] = get_offs(s, r);
            EAGINE_MAYBE_UNUSED(rd);
            EAGINE_MAYBE_UNUSED(td);

            const auto tx = -std::sin((s + sd) * s_step);
            const auto tz = -std::cos((s + sd) * s_step);

            dest[k(s, r, 0)] = float(tx);
            dest[k(s, r, 1)] = float(0);
            dest[k(s, r, 2)] = float(tz);
        }
        dest[k(s, _rings, 0)] = dest[k(s, 0, 0)];
        dest[k(s, _rings, 1)] = dest[k(s, 0, 1)];
        dest[k(s, _rings, 2)] = dest[k(s, 0, 2)];
    }
    for(span_size_t r = 0; r <= _rings; ++r) {
        dest[k(_sections, r, 0)] = dest[k(0, r, 0)];
        dest[k(_sections, r, 1)] = dest[k(0, r, 1)];
        dest[k(_sections, r, 2)] = dest[k(0, r, 2)];
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_torus_gen::bitangentials(
  span<float> dest, unit_torus_gen::offset_getter get_offs) noexcept {
    EAGINE_ASSERT(has(vertex_attrib_kind::bitangential));
    EAGINE_ASSERT(dest.size() >= vertex_count() * 3);

    auto k = [this](span_size_t s, span_size_t r, span_size_t c) {
        return 3 * (s * (_rings + 1) + r) + c;
    };

    const auto s_step = 2 * math::pi / _sections;
    const auto r_step = 2 * math::pi / _rings;

    const auto ty = 0;

    for(span_size_t s = 0; s < _sections; ++s) {
        for(span_size_t r = 0; r < _rings; ++r) {
            const auto [rd, sd, td] = get_offs(s, r);
            EAGINE_MAYBE_UNUSED(td);

            const auto tx = -std::sin((s + sd) * s_step);
            const auto tz = -std::cos((s + sd) * s_step);
            const auto nr = -std::cos((r + rd) * r_step);
            const auto ny = std::sin((r + rd) * r_step);
            const auto nx = -tz * nr;
            const auto nz = tx * nr;

            dest[k(s, r, 0)] = float(ny * tz - nz * ty);
            dest[k(s, r, 1)] = float(nz * tx - nx * tz);
            dest[k(s, r, 2)] = float(nx * ty - ny * tx);
        }
        dest[k(s, _rings, 0)] = dest[k(s, 0, 0)];
        dest[k(s, _rings, 1)] = dest[k(s, 0, 1)];
        dest[k(s, _rings, 2)] = dest[k(s, 0, 2)];
    }
    for(span_size_t r = 0; r <= _rings; ++r) {
        dest[k(_sections, r, 0)] = dest[k(0, r, 0)];
        dest[k(_sections, r, 1)] = dest[k(0, r, 1)];
        dest[k(_sections, r, 2)] = dest[k(0, r, 2)];
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_torus_gen::wrap_coords(span<float> dest) noexcept {
    EAGINE_ASSERT(has(vertex_attrib_kind::wrap_coord));
    EAGINE_ASSERT(dest.size() >= vertex_count() * 2);

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
span_size_t unit_torus_gen::attribute_variants(vertex_attrib_kind attrib) {
    switch(attrib) {
        case vertex_attrib_kind::vertex_pivot:
            break;
        case vertex_attrib_kind::position:
        case vertex_attrib_kind::normal:
        case vertex_attrib_kind::tangential:
        case vertex_attrib_kind::bitangential:
            return 2;
        case vertex_attrib_kind::wrap_coord:
        case vertex_attrib_kind::pivot:
        case vertex_attrib_kind::box_coord:
        case vertex_attrib_kind::face_coord:
        case vertex_attrib_kind::object_id:
        case vertex_attrib_kind::material_id:
        case vertex_attrib_kind::weight:
        case vertex_attrib_kind::color:
        case vertex_attrib_kind::emission:
        case vertex_attrib_kind::occlusion:
            break;
    }
    return _base::attribute_variants(attrib);
}
//------------------------------------------------------------------------------
static inline auto unit_torus_gen_make_get_norm_offs(
  std::size_t r_seed, std::size_t s_seed) {
    return [rrg{std::mt19937{r_seed}},
            srg{std::mt19937{s_seed}},
            rnd{std::normal_distribution<float>{0.f, 0.15f}},
            snd{std::normal_distribution<float>{0.f, 0.15f}}](
             span_size_t, span_size_t) mutable -> std::array<float, 3> {
        return {{rnd(rrg), snd(srg), 0.f}};
    };
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_torus_gen::attrib_values(
  vertex_attrib_kind attrib, span_size_t variant_index, span<float> dest) {
    const auto no_offs = [](span_size_t, span_size_t) -> std::array<float, 3> {
        return {{0.f, 0.f, 0.f}};
    };
    switch(attrib) {
        case vertex_attrib_kind::vertex_pivot:
            vertex_pivots(dest);
            break;
        case vertex_attrib_kind::position:
            if(variant_index == 1) {
                auto get_offs =
                  unit_torus_gen_make_get_norm_offs(_r_seed, _s_seed);
                positions(dest, offset_getter{get_offs});
            } else {
                positions(dest, offset_getter{no_offs});
            }
            break;
        case vertex_attrib_kind::normal:
            if(variant_index == 1) {
                auto get_offs =
                  unit_torus_gen_make_get_norm_offs(_r_seed, _s_seed);
                normals(dest, offset_getter{get_offs});
            } else {
                normals(dest, offset_getter{no_offs});
            }
            break;
        case vertex_attrib_kind::tangential:
            if(variant_index == 1) {
                auto get_offs =
                  unit_torus_gen_make_get_norm_offs(_r_seed, _s_seed);
                tangentials(dest, offset_getter{get_offs});
            } else {
                tangentials(dest, offset_getter{no_offs});
            }
            break;
        case vertex_attrib_kind::bitangential:
            if(variant_index == 1) {
                auto get_offs =
                  unit_torus_gen_make_get_norm_offs(_r_seed, _s_seed);
                bitangentials(dest, offset_getter{get_offs});
            } else {
                bitangentials(dest, offset_getter{no_offs});
            }
            break;
        case vertex_attrib_kind::wrap_coord:
            wrap_coords(dest);
            break;
        case vertex_attrib_kind::pivot:
        case vertex_attrib_kind::box_coord:
        case vertex_attrib_kind::face_coord:
        case vertex_attrib_kind::object_id:
        case vertex_attrib_kind::material_id:
        case vertex_attrib_kind::weight:
        case vertex_attrib_kind::color:
        case vertex_attrib_kind::emission:
        case vertex_attrib_kind::occlusion:
            centered_unit_shape_generator_base::attrib_values(
              attrib, variant_index, dest);
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
    EAGINE_ASSERT(dest.size() >= index_count());

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
    EAGINE_ASSERT(ops.size() >= operation_count());

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
EAGINE_LIB_FUNC
math::sphere<float, true> unit_torus_gen::bounding_sphere() {
    return {{0.0f}, 0.5f};
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#ifdef __clang__
#pragma clang diagnostic pop
#endif
