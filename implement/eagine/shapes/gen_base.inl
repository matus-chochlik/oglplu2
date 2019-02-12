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

    for(span_size_t i = 0; i < intersections.size(); ++i) {
        intersections[i] = math::nearest_ray_param(
          math::line_sphere_intersection_params(rays[i], bounding_sphere()));
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
