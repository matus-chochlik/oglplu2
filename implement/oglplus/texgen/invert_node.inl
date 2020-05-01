/**
 *  @file oglplus/texgen/invert_node.inl
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

namespace eagine {
namespace oglp {
namespace texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
invert_output::invert_output(node_intf& parent)
  : base_output(parent)
  , input(parent, string_view("Input"), 0.5f, 0.5f, 0.5f, 0.5f) {
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
string_view invert_output::type_name() {
    return string_view("Invert");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type invert_output::value_type() {
    return input.value_type();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& invert_output::definitions(
  std::ostream& out, compile_context& ctxt) {
    if(already_defined(ctxt)) {
        return out;
    }

    input_defs(out, ctxt);
    opening_expr(out, ctxt);

    out << "\treturn " << data_type_name(value_type()) << "(1)-";
    out << expr::output_id{input.output(), ctxt};
    out << expr::render_param_pass{input.output()};
    out << ";" << std::endl;

    return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglp
} // namespace eagine
//------------------------------------------------------------------------------
