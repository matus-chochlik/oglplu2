/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/memory/span_algo.hpp>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void centered_unit_shape_generator_base ::attrib_values(
  vertex_attrib_kind attr, span<float> dest) {
    if(attr == vertex_attrib_kind::box_coord) {
        this->attrib_values(vertex_attrib_kind::position, dest);
        for(float& x : dest) {
            x += 0.5f;
        }
    } else if(attr == vertex_attrib_kind::pivot) {
        fill(head(dest, this->vertex_count() * 3), 0.f);
    } else {
        generator_base::attrib_values(attr, dest);
    }
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine
