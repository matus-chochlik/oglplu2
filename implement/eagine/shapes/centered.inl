/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/math/functions.hpp>
#include <limits>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void centered_gen::attrib_values(vertex_attrib_variant vav, span<float> dest) {

    const bool is_centered_attrib = vav == vertex_attrib_kind::position ||
                                    vav == vertex_attrib_kind::pivot ||
                                    vav == vertex_attrib_kind::pivot_pivot ||
                                    vav == vertex_attrib_kind::vertex_pivot;

    if(is_centered_attrib) {

        delegated_gen::attrib_values({vertex_attrib_kind::position, vav}, dest);

        std::array<float, 4> min{
          std::numeric_limits<float>::max(),
          std::numeric_limits<float>::max(),
          std::numeric_limits<float>::max(),
          std::numeric_limits<float>::max()};

        std::array<float, 4> max{
          std::numeric_limits<float>::lowest(),
          std::numeric_limits<float>::lowest(),
          std::numeric_limits<float>::lowest(),
          std::numeric_limits<float>::lowest()};

        const span_size_t m = values_per_vertex(vav);

        for(auto v : integer_range(vertex_count())) {
            for(auto c : integer_range(m)) {
                const auto k = std_size(c);

                min[k] = eagine::math::minimum(min[k], dest[v * m + c]);
                max[k] = eagine::math::maximum(max[k], dest[v * m + c]);
            }
        }

        std::array<float, 4> offs{{}};
        for(auto c : integer_range(m)) {
            const auto k = std_size(c);
            offs[k] = (min[k] + max[k]) * 0.5F;
        }

        if(vav != vertex_attrib_kind::position) {
            delegated_gen::attrib_values(vav, dest);
        }

        for(auto v : integer_range(vertex_count())) {
            for(auto c : integer_range(m)) {
                dest[v * m + c] -= offs[std_size(c)];
            }
        }
    } else {
        delegated_gen::attrib_values(vav, dest);
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto centered_gen::bounding_sphere() -> math::sphere<float, true> {
    const auto bs = delegated_gen::bounding_sphere();
    return {{0.F}, bs.radius()};
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine
