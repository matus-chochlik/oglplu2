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
void translated_gen::attrib_values(
  vertex_attrib_kind attrib, span<float> dest, span_size_t variant_index) {
    delegated_gen::attrib_values(attrib, dest, variant_index);

    const bool is_translated_attrib =
      attrib == vertex_attrib_kind::position ||
      attrib == vertex_attrib_kind::pivot ||
      attrib == vertex_attrib_kind::vertex_pivot;

    if(is_translated_attrib) {
        const auto m = values_per_vertex(attrib, variant_index);
        const auto n = vertex_count();
        for(span_size_t v = 0; v < n; ++v) {
            for(span_size_t c = 0; c < m; ++c) {
                dest[v * m + c] += _d[std_size(c)];
            }
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
math::sphere<float, true> translated_gen::bounding_sphere() {
    const auto bs = delegated_gen::bounding_sphere();
    using V = math::tvec<float, 3, true>;
    return {bs.center() + V{_d[0], _d[1], _d[2]}, bs.radius()};
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine
