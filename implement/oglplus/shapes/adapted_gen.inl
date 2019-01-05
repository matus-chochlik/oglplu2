/**
 *  @file oglplus/shapes/adapted_gen.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <vector>

namespace oglplus {
namespace shapes {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
span_size_t adapted_generator::_index_type_size(
  eagine::shapes::index_data_type type) {
    switch(type) {
        // TODO currently all indices are GLuint
        case eagine::shapes::index_data_type::unsigned_8:
            // TODO return sizeof(GLubyte);
        case eagine::shapes::index_data_type::unsigned_16:
            // TODO return sizeof(GLushort);
        case eagine::shapes::index_data_type::unsigned_32:
            return sizeof(GLuint);
        case eagine::shapes::index_data_type::none:
            break;
    }
    return 0;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void adapted_generator::instructions(span<draw_operation> ops) const {
    assert(ops.size() >= operation_count());
    std::vector<eagine::shapes::draw_operation> tmp(
      std_size(operation_count()));
    _gen->instructions(cover(tmp));

    for(decltype(tmp.size()) i = 0; i < tmp.size(); ++i) {
        ops[span_size(i)] = draw_operation(tmp[i]);
    }
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace oglplus
//------------------------------------------------------------------------------
