/**
 *  @file oglplus/texgen/interlace_node.inl
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
interlace_output::interlace_output(node_intf& parent, interlace_mode mode)
  : base_output(parent)
  , _mode(mode) {
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
string_view interlace_output::type_name() {
    return string_view("Interlace");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type interlace_output::value_type() {
    return slot_data_type::float_;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& interlace_output::definitions(
  std::ostream& out, compile_context& ctxt) {
    if(already_defined(ctxt)) {
        return out;
    }

    input_defs(out, ctxt);
    opening_expr(out, ctxt);

    out << "\tfloat c = (gl_FragCoord.xyz + ";
    out << expr::voxel_offset{*this} << ").";
    switch(_mode) {
        case interlace_mode::columns:
            out << "x";
            break;
        case interlace_mode::rows:
            out << "y";
            break;
        case interlace_mode::layers:
            out << "z";
            break;
    }
    out << ";" << std::endl;
    out << "\treturn mod(floor(c), 2);" << std::endl;

    return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
} // namespace eagine::oglp::texgen
//------------------------------------------------------------------------------
