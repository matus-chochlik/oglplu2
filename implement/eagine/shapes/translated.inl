/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/math/tvec.hpp>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void translated_gen::attrib_values(vertex_attrib_kind attr, span<float> dest) {
    delegated_gen::attrib_values(attr, dest);

    const bool is_translated_attrib = attr == vertex_attrib_kind::position ||
                                      attr == vertex_attrib_kind::pivot ||
                                      attr == vertex_attrib_kind::vertex_pivot;

    if(is_translated_attrib) {
        for(span_size_t v = 0, n = vertex_count(); v < n; ++v) {
            for(span_size_t c = 0, m = values_per_vertex(attr); c < m; ++c) {
                dest[v * m + c] += _d[std_size(c)];
            }
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
math::sphere<float, true> translated_gen::bounding_sphere() {
    const auto bs = delegated_gen::bounding_sphere();
    return {bs.center() + math::tvec<float, 3, true>{_d[0], _d[1], _d[2]},
            bs.radius()};
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine
