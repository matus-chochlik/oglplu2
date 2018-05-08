/**
 *  @file oglplus/texgen/map_node.inl
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
map_output::map_output(node_intf& parent)
  : base_output(parent)
  , input(parent, cstr_ref("Input"), 0.5f, 0.5f, 0.5f, 0.5f)
  , coord(parent, cstr_ref("Coord"), 0.f, 0.f, 0.f) {
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
map_output::type_name(void) {
    return cstr_ref("Map");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type
map_output::value_type(void) {
    return input.value_type();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
map_output::definitions(std::ostream& out, compile_context& ctxt) {
    if(already_defined(ctxt))
	return out;

    input_defs(out, ctxt);
    opening_expr(out, ctxt);

    slot_data_type vec3_type = slot_data_type::float_3;

    out << "\tvec3 coord = ";
    out << expr::conversion_prefix{coord.value_type(), vec3_type};
    out << expr::output_id{coord.output(), ctxt};
    out << expr::render_param_pass{coord.output()};
    out << expr::conversion_suffix{coord.value_type(), vec3_type};
    out << ";" << std::endl;

    out << "\treturn ";
    out << expr::output_id{input.output(), ctxt};
    if(input.output().needs_params()) {
	out << "(coord, vec3(0), vec3(0))" << std::endl;
    }
    out << ";" << std::endl;

    return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------
