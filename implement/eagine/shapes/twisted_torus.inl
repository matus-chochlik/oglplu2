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
EAGINE_DIAG_PUSH()
EAGINE_DIAG_OFF(double-promotion)
#endif

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto unit_twisted_torus_gen::_attr_mask() noexcept -> vertex_attrib_bits {
    return vertex_attrib_kind::position | vertex_attrib_kind::normal |
           vertex_attrib_kind::box_coord | vertex_attrib_kind::wrap_coord;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
unit_twisted_torus_gen::unit_twisted_torus_gen(
  vertex_attrib_bits attr_bits,
  int twist,
  valid_if_greater_than<int, 2> rings,
  valid_if_greater_than<int, 3> sections,
  valid_if_ge0_lt1<float> radius_ratio) noexcept
  : _base{attr_bits & _attr_mask()}
  , _twist{twist}
  , _rings{rings.value()}
  , _sections{sections.value()}
  , _radius_ratio{radius_ratio.value()} {}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto unit_twisted_torus_gen::vertex_count() -> span_size_t {
    return 2 * 2 * 2 * _sections * (_rings + 1);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_twisted_torus_gen::positions(span<float> dest) noexcept {

    EAGINE_ASSERT(has(vertex_attrib_kind::position));
    EAGINE_ASSERT(dest.size() >= vertex_count() * 3);

    span_size_t k = 0;

    const double ro = 0.50;
    const double ri = ro * _radius_ratio;
    const double r1 = ri;
    const double r2 = ro - ri;

    const double r_twist = double(_twist) / double(_rings);
    const double r_step = (2 * math::pi) / double(_rings);
    const double s_step = (2 * math::pi) / double(_sections);
    const double s_slip = s_step * _thickness_ratio * 2.0;

    for(const auto f : integer_range(2)) {
        const double f_sign = (f == 0) ? 1.0 : -1.0;
        const double fdt = s_slip * f_sign * 0.25;

        for(const auto s : integer_range(_sections)) {
            const double s_angle = s_step * 0.5 + s * s_step;
            const double sa[2] = {
              s_angle + s_slip * f_sign, s_angle - s_slip * f_sign};

            for(const auto r : integer_range(_rings + 1)) {
                const double r_angle = r * r_step;

                const double vx = std::cos(r_angle);
                const double vz = std::sin(r_angle);

                const double ta = s_step * r * r_twist;

                for(const auto d : integer_range(2)) {
                    double vr = std::cos(sa[d] + ta);
                    double vy = std::sin(sa[d] + ta);

                    dest[k++] = float(vx * (r1 + r2 * (1.0 + vr) + fdt * vr));
                    dest[k++] = float(vy * (r2 + fdt));
                    dest[k++] = float(vz * (r1 + r2 * (1.0 + vr) + fdt * vr));
                }
            }
        }
    }

    for(const auto d : integer_range(2)) {
        const double d_sign = (d == 0) ? 1.0 : -1.0;

        for(const auto s : integer_range(_sections)) {
            const double s_angle = s_step * 0.5 + s * s_step;
            const double sa = s_angle + s_slip * d_sign;

            for(const auto r : integer_range(_rings + 1)) {
                const double r_angle = r * r_step;
                const double ta = s_step * r * r_twist;
                const double vr = std::cos(sa + ta);
                const double vy = std::sin(sa + ta);

                const double vx = std::cos(r_angle);
                const double vz = std::sin(r_angle);

                for(unsigned f = 0; f != 2; ++f) {
                    const double f_sign = (f == 0) ? 1.0 : -1.0;
                    const double fdt = -s_slip * d_sign * f_sign * 0.25;

                    dest[k++] = float(vx * (r1 + r2 * (1.0 + vr) + fdt * vr));
                    dest[k++] = float(vy * (r2 + fdt));
                    dest[k++] = float(vz * (r1 + r2 * (1.0 + vr) + fdt * vr));
                }
            }
        }
    }

    EAGINE_ASSERT(k <= dest.size());
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_twisted_torus_gen::normals(span<float> dest) noexcept {
    EAGINE_ASSERT(has(vertex_attrib_kind::normal));
    EAGINE_ASSERT(dest.size() >= vertex_count() * 3);

    span_size_t k = 0;

    const double r_twist = double(_twist) / double(_rings);
    const double r_step = (2.0 * math::pi) / double(_rings);
    const double s_step = (2.0 * math::pi) / double(_sections);
    const double s_slip = s_step * _thickness_ratio * 2.0;

    for(const auto f : integer_range(2)) {
        const double f_sign = (f == 0) ? 1.0 : -1.0;

        for(const auto s : integer_range(_sections)) {
            const double s_angle = s_step * 0.5 + s * s_step;
            const double sa[2] = {
              s_angle + s_slip * f_sign, s_angle - s_slip * f_sign};

            for(const auto r : integer_range(_rings + 1)) {
                const double r_angle = r * r_step;
                double vx = std::cos(r_angle);
                double vz = std::sin(r_angle);

                const double ta = s_step * r * r_twist;

                for(const auto d : integer_range(2)) {
                    double vr = std::cos(sa[d] + ta);
                    double vy = std::sin(sa[d] + ta);

                    dest[k++] = float(f_sign * vx * vr);
                    dest[k++] = float(f_sign * vy);
                    dest[k++] = float(f_sign * vz * vr);
                }
            }
        }
    }

    for(const auto d : integer_range(2)) {
        const double d_sign = (d == 0) ? 1.0 : -1.0;

        for(const auto s : integer_range(_sections)) {
            const double s_angle = s_step * 0.5 + s * s_step;
            const double sa = s_angle + s_slip * d_sign;

            for(const auto r : integer_range(_rings + 1)) {
                const double ta = s_step * r * r_twist;
                const double vr = std::sin(sa + ta);
                const double vy = std::cos(sa + ta);
                const double r_angle = r * r_step;
                double vx = std::cos(r_angle);
                double vz = std::sin(r_angle);

                for(const auto f : integer_range(2)) {
                    EAGINE_MAYBE_UNUSED(f);
                    dest[k++] = float(d_sign * -vx * vr);
                    dest[k++] = float(d_sign * vy);
                    dest[k++] = float(d_sign * -vz * vr);
                }
            }
        }
    }

    EAGINE_ASSERT(k <= dest.size());
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_twisted_torus_gen::wrap_coords(span<float> dest) noexcept {
    EAGINE_ASSERT(has(vertex_attrib_kind::wrap_coord));
    EAGINE_ASSERT(dest.size() >= vertex_count() * 2);

    span_size_t k = 0;

    const double r_step = 0.5 / double(_rings);
    const double s_step = 1.0 / double(_sections);
    const double s_slip = s_step * _thickness_ratio * 2.0;

    for(const auto f : integer_range(4)) {
        const double f_sign = (f == 0) ? 1.0 : -1.0;

        for(const auto s : integer_range(_sections)) {
            const double s_angle = s_step * 0.5 + s * s_step;
            const double sa[2] = {
              s_angle + s_slip * f_sign, s_angle - s_slip * f_sign};

            for(const auto r : integer_range(_rings + 1)) {
                const double r_angle = 2.0 * r * r_step;
                const double u = r_angle;

                for(const auto d : integer_range(2)) {
                    const double v = sa[d];
                    dest[k++] = float(u);
                    dest[k++] = float(v);
                }
            }
        }
    }

    EAGINE_ASSERT(k <= dest.size());
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_twisted_torus_gen::attrib_values(
  vertex_attrib_variant vav,
  span<float> dest) {
    switch(vav.attribute()) {
        case vertex_attrib_kind::position:
            positions(dest);
            break;
        case vertex_attrib_kind::normal:
            normals(dest);
            break;
        case vertex_attrib_kind::wrap_coord:
            wrap_coords(dest);
            break;
        case vertex_attrib_kind::tangential:
        case vertex_attrib_kind::bitangential:
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
auto unit_twisted_torus_gen::operation_count(drawing_variant) -> span_size_t {
    return _sections * 4;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_twisted_torus_gen::instructions(
  drawing_variant var,
  span<draw_operation> ops) {
    if(var == 0) {
        EAGINE_ASSERT(ops.size() >= operation_count(var));

        span_size_t strip = 2 * (_rings + 1);
        span_size_t offs = 0;

        auto opi = ops.begin();
        for(const auto f : integer_range(4)) {
            for(const auto s : integer_range(_sections)) {
                EAGINE_ASSERT(opi != ops.end());
                EAGINE_MAYBE_UNUSED(s);
                draw_operation& op = *opi++;

                op.mode = primitive_type::triangle_strip;
                op.idx_type = index_data_type::none;
                op.first = offs;
                op.count = strip;
                op.phase = f;
                op.primitive_restart = false;
                op.cw_face_winding = true;
                offs += strip;
            }
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto unit_twisted_torus_gen::bounding_sphere() -> math::sphere<float, true> {
    return {{0.F, 0.F, 0.F}, 0.5F};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_twisted_torus_gen::ray_intersections(
  drawing_variant,
  span<const math::line<float, true>> rays,
  span<optionally_valid<float>> intersections) {

    EAGINE_ASSERT(intersections.size() >= rays.size());

    const auto bs = bounding_sphere();

    for(const auto i : integer_range(intersections.size())) {
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
EAGINE_DIAG_POP()
#endif
