/**
 *  @file oglplus/texgen/wrap_node.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <cassert>
#include <iostream>

namespace eagine::oglp::texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
wrap_output::wrap_output(node_intf& parent)
  : base_output(parent)
  , mode(wrap_mode::repeat)
  , input(parent, string_view("Input")) {
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
string_view wrap_output::type_name() {
    return string_view("Wrap");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type wrap_output::value_type() {
    return input.value_type();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& wrap_output::definitions(
  std::ostream& out, compile_context& ctxt) {
    if(already_defined(ctxt)) {
        return out;
    }

    input_defs(out, ctxt);
    opening_expr(out, ctxt);

    slot_data_type vt = value_type();

    out << "\t" << data_type_name(vt) << " v = ";
    out << expr::output_id{input.output(), ctxt};
    out << expr::render_param_pass{input.output()};
    out << ";" << std::endl;

    switch(mode) {
        case wrap_mode::repeat:
        case wrap_mode::mirror:
            out << "\t" << data_type_name(vt);
            out << " f = fract(v);" << std::endl;
            out << "\tf = f - floor(f);" << std::endl;
            break;
        case wrap_mode::clamp:
            break;
    }

    out << "\treturn ";
    switch(mode) {
        case wrap_mode::repeat:
            out << "f";
            break;
        case wrap_mode::mirror:
            out << "mix(f, " << data_type_name(vt);
            out << "(1)-f, mod(floor(v), 2))";
            break;
        case wrap_mode::clamp:
            out << "clamp(v, " << data_type_name(vt);
            out << "(0.0), " << data_type_name(vt);
            out << "(1.0))" << std::endl;
            break;
    }
    out << ";" << std::endl;

    return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
} // namespace eagine::oglp::texgen
//------------------------------------------------------------------------------
