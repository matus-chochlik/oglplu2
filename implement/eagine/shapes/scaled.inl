/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/math/functions.hpp>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void scaled_gen::attrib_values(vertex_attrib_variant vav, span<float> dest) {
    delegated_gen::attrib_values(vav, dest);

    const bool is_scaled_attrib = vav == vertex_attrib_kind::position ||
                                  vav == vertex_attrib_kind::pivot ||
                                  vav == vertex_attrib_kind::vertex_pivot;

    if(is_scaled_attrib) {
        const auto m = values_per_vertex(vav);
        const auto n = vertex_count();
        for(span_size_t v = 0; v < n; ++v) {
            for(span_size_t c = 0; c < m; ++c) {
                dest[v * m + c] *= _s[std_size(c)];
            }
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
math::sphere<float, true> scaled_gen::bounding_sphere() {
    const auto bs = delegated_gen::bounding_sphere();
    const auto ms = math::maximum(_s[0], math::maximum(_s[1], _s[2]));
    return {bs.center(), bs.radius() * ms};
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine
