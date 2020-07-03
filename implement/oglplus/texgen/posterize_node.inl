/**
 *  @file oglplus/texgen/posterize_node.inl
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

namespace eagine::oglp::texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
posterize_output::posterize_output(node_intf& parent)
  : base_output(parent)
  , input(parent, string_view("Input"), 0.5f, 0.5f, 0.5f, 0.5f)
  , levels(parent, string_view("Levels"), 4.f, 4.f, 4.f, 4.f) {
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
string_view posterize_output::type_name() {
    return string_view("Posterize");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type posterize_output::value_type() {
    return input.value_type();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& posterize_output::definitions(
  std::ostream& out, compile_context& ctxt) {
    if(already_defined(ctxt)) {
        return out;
    }

    input_defs(out, ctxt);
    opening_expr(out, ctxt);

    slot_data_type vt = value_type();
    string_view f("4.0");

    out << "\t" << data_type_name(vt) << " lvls = ";
    out << expr::conversion_prefix{levels.value_type(), vt};
    out << expr::output_id{levels.output(), ctxt};
    out << expr::render_param_pass{levels.output()};
    out << expr::conversion_suffix_v{levels.value_type(), vt, {f, f, f, f}};
    out << ";" << std::endl;

    out << "\tlvls = max(lvls, " << data_type_name(vt);
    out << "(1));" << std::endl;

    out << "\treturn floor(";
    out << expr::output_id{input.output(), ctxt};
    out << expr::render_param_pass{input.output()};
    out << "*lvls)/lvls;" << std::endl;

    return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
} // namespace eagine::oglp::texgen
//------------------------------------------------------------------------------
