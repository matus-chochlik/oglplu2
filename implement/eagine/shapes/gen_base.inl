/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/memory/span_algo.hpp>
#include <cassert>
#include <vector>

namespace eagine {
namespace shapes {
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
EAGINE_LIB_FUNC
index_data_type generator_base::index_type() {
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
} // namespace shapes
} // namespace eagine
