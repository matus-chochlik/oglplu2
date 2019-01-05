/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void scaled_gen::attrib_values(vertex_attrib_kind attr, span<float> dest) {
    delegated_gen::attrib_values(attr, dest);

    if(attr == vertex_attrib_kind::position) {
        for(span_size_t v = 0, n = vertex_count(); v < n; ++v) {
            for(span_size_t c = 0, m = values_per_vertex(attr); c < m; ++c) {
                dest[v * m + c] *= _s[c];
            }
        }
    }
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine
