/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/math/functions.hpp>
#include <eagine/math/intersection.hpp>
#include <eagine/memory/span_algo.hpp>
#include <array>
#include <cassert>
#include <limits>
#include <vector>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
// generator_intf
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
math::sphere<float, true> generator_intf::bounding_sphere() {
    std::array<float, 3> min{std::numeric_limits<float>::max(),
                             std::numeric_limits<float>::max(),
                             std::numeric_limits<float>::max()};

    std::array<float, 3> max{std::numeric_limits<float>::lowest(),
                             std::numeric_limits<float>::lowest(),
                             std::numeric_limits<float>::lowest()};

    const auto attr = vertex_attrib_kind::position;
    const auto n = vertex_count();
    const auto m = values_per_vertex(attr);

    std::vector<float> temp(std_size(n * m));
    auto pos = cover(temp);
    attrib_values(attr, pos);

    for(span_size_t v = 0; v < n; ++v) {
        for(span_size_t c = 0; c < m; ++c) {
            const auto k = std_size(c);

            min[k] = eagine::math::minimum(min[k], pos[v * m + c]);
            max[k] = eagine::math::maximum(max[k], pos[v * m + c]);
        }
    }

    math::vector<float, 3, true> center{};
    float radius{0.f};
    for(span_size_t c = 0; c < m; ++c) {
        const auto k = std_size(c);
        radius = eagine::math::maximum(radius, (max[k] - min[k]) * 0.5f);
    }

    return {center, radius};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void generator_intf::ray_intersections(
  span<const math::line<float, true>> rays,
  span<optionally_valid<float>> intersections) {

    assert(intersections.size() >= rays.size());

    std::vector<draw_operation> ops(std_size(operation_count()));
    instructions(cover(ops));

    std::vector<std::uint32_t> idx(std_size(index_count()));
    indices(cover(idx));

    const auto pvak = vertex_attrib_kind::position;
    const auto vpv = values_per_vertex(pvak);

    std::vector<float> pos(std_size(vertex_count() * vpv));
    attrib_values(pvak, cover(pos));

    for(auto& param : intersections) {
        param = {};
    }

    auto intersect = [&rays, &intersections](const auto& fce, bool cw) {
        for(span_size_t i = 0; i < intersections.size(); ++i) {
            const auto& ray = rays[i];
            const auto nparam =
              math::line_triangle_intersection_param(ray, fce);

            if(nparam) {
                if(nparam.value_anyway() > 0.0001f) {
                    const auto fnml = fce.normal(cw);
                    if(dot(ray.direction(), fnml) < 0.f) {
                        auto& oparam = intersections[i];
                        if(!oparam) {
                            oparam = nparam;
                        } else if(
                          nparam.value_anyway() < oparam.value_anyway()) {
                            oparam = nparam;
                        }
                    }
                }
            }
        }
    };

    auto coord = [&pos, &idx, vpv](auto vx, auto cr, bool idxd) {
        if(idxd) {
            return pos[std_size(span_size(idx[std_size(vx)]) * vpv + cr)];
        } else {
            return pos[std_size(vx * vpv + cr)];
        }
    };

    for(const auto& op : ops) {
        const bool indexed = op.idx_type != index_data_type::none;

        if(op.mode == primitive_type::triangles) {
            std::array<std::array<float, 4>, 3> tri{};
            span_size_t t = 0;
            for(span_size_t v = op.first; v < op.count; ++v) {
                for(span_size_t c = 0; c < 3; ++c) {
                    tri[std_size(t)][std_size(c)] = coord(v, c, indexed);
                }
                if(++t >= 3) {
                    t = 0;
                    math::triangle<float, true> face{
                      {tri[0][0], tri[0][1], tri[0][2]},
                      {tri[1][0], tri[1][1], tri[1][2]},
                      {tri[2][0], tri[2][1], tri[2][2]}};
                    intersect(face, op.cw_face_winding);
                }
            }
        } else if(op.mode == primitive_type::triangle_strip) {
            for(span_size_t v = op.first + 2; v < op.count; ++v) {
                span_size_t w = v - op.first;
                span_size_t o0 = -2, o1 = -1, o2 = 0;
                if(w % 2 != 0) {
                    o1 = 0;
                    o2 = -1;
                }
                math::triangle<float, true> face{{coord(v + o0, 0, indexed),
                                                  coord(v + o0, 1, indexed),
                                                  coord(v + o0, 2, indexed)},
                                                 {coord(v + o1, 0, indexed),
                                                  coord(v + o1, 1, indexed),
                                                  coord(v + o1, 2, indexed)},
                                                 {coord(v + o2, 0, indexed),
                                                  coord(v + o2, 1, indexed),
                                                  coord(v + o2, 2, indexed)}};
                intersect(face, op.cw_face_winding);
            }
        }
    }
}
//------------------------------------------------------------------------------
// generator_base
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC index_data_type generator_base::index_type() {
    return index_data_type::none;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
span_size_t generator_base::index_count() {
    return 0;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void generator_base::indices(span<std::uint8_t>) {
    EAGINE_UNREACHABLE("Invalid function called for this index data type");
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void generator_base::indices(span<std::uint16_t> dest) {
    if(index_type() == index_data_type::unsigned_8) {
        std::vector<std::uint8_t> tmp(std_size(index_count()));
        indices(cover(tmp));
        copy(view(tmp), dest);
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void generator_base::indices(span<std::uint32_t> dest) {
    if(index_type() == index_data_type::unsigned_8) {
        std::vector<std::uint8_t> tmp(std_size(index_count()));
        indices(cover(tmp));
        copy(view(tmp), dest);
    } else if(index_type() == index_data_type::unsigned_16) {
        std::vector<std::uint16_t> tmp(std_size(index_count()));
        indices(cover(tmp));
        copy(view(tmp), dest);
    }
}
//------------------------------------------------------------------------------
// centered_unit_shape_generator_base
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void centered_unit_shape_generator_base::attrib_values(
  vertex_attrib_kind attr, span<float> dest) {
    if(attr == vertex_attrib_kind::box_coord) {
        this->attrib_values(vertex_attrib_kind::position, dest);
        for(float& x : dest) {
            x += 0.5f;
        }
    } else if(attr == vertex_attrib_kind::pivot) {
        fill(head(dest, this->vertex_count() * 3), 0.f);
    } else if(attr == vertex_attrib_kind::vertex_pivot) {
        fill(head(dest, this->vertex_count() * 3), 0.f);
    } else {
        generator_base::attrib_values(attr, dest);
    }
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine
