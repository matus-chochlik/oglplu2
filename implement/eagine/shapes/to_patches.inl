/// @file eagine/shapes/to_patches.inl
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/assert.hpp>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void to_patches_gen::instructions(
  drawing_variant var,
  span<draw_operation> ops) {

    delegated_gen::instructions(var, ops);

    for(auto& op : ops) {
        if(op.mode == primitive_type::triangles) {
            op.mode = primitive_type::patches;
            op.patch_vertices = 3;
        } else if(op.mode == primitive_type::quads) {
            op.mode = primitive_type::patches;
            op.patch_vertices = 4;
        }
    }
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine
