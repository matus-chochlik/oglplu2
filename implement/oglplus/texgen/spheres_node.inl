/**
 *  @file oglplus/texgen/spheres_node.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <cassert>
#include <iostream>
#include <set>
#include <string>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
spheres_output::spheres_output(node_intf& parent)
  : base_output(parent)
  , repeat(parent, cstr_ref("Repeat"), 8.f, 8.f, 8.f) {
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
spheres_output::type_name() {
    return cstr_ref("Spheres");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type
spheres_output::value_type() {
    return slot_data_type::float_;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
spheres_output::definitions(std::ostream& out, compile_context& ctxt) {
    if(already_defined(ctxt))
        return out;

    input_defs(out, ctxt);
    opening_expr(out, ctxt);

    out << "\tvec3 c = " << expr::normalized_coord{*this} << ";";
    out << std::endl;

    slot_data_type vec3_type = slot_data_type::float_3;
    out << "\tc *= ";
    out << expr::conversion_prefix{repeat.value_type(), vec3_type};
    out << expr::output_id{repeat.output(), ctxt};
    out << expr::render_param_pass{repeat.output()};
    out << expr::conversion_prefix{repeat.value_type(), vec3_type};
    out << ";" << std::endl;

    out << "\tc += " << expr::norm_voxel_offs{*this} << ";";
    out << std::endl;

    out << "\tc = floor(c+vec3(0.5))-c;" << std::endl;

    out << "\treturn 1-2.0*length(c);" << std::endl;

    return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------
