/**
 *  @file oglplus/texgen/complement_node.inl
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
complement_output::complement_output(node_intf& parent)
  : base_output(parent)
  , input(parent, string_view("Input"), 0.5f, 0.5f, 0.5f, 0.5f)
  , complement(parent, string_view("Complement"), 0.f, 0.f, 0.f, 1.f) {
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
string_view complement_output::type_name() {
    return string_view("Complement");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type complement_output::value_type() {
    return make_data_type(elem_data_type(input.value_type()), 4);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& complement_output::definitions(
  std::ostream& out, compile_context& ctxt) {
    if(already_defined(ctxt)) {
        return out;
    }

    input_defs(out, ctxt);
    opening_expr(out, ctxt);

    slot_data_type dt = value_type();

    out << "\t" << data_type_name(dt) << " c = ";
    out << expr::conversion_prefix{complement.value_type(), dt};
    out << expr::output_id{complement.output(), ctxt};
    out << expr::render_param_pass{complement.output()};
    out << expr::conversion_suffix{complement.value_type(), dt};
    out << ";" << std::endl;

    out << "\treturn ";
    out << expr::conversion_prefix{input.value_type(), dt};
    out << expr::output_id{input.output(), ctxt};
    out << expr::render_param_pass{input.output()};
    out << expr::conversion_suffix_v{input.value_type(),
                                     dt,
                                     {string_view("c.r"),
                                      string_view("c.g"),
                                      string_view("c.b"),
                                      string_view("c.a")}};
    out << ";" << std::endl;

    return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------
