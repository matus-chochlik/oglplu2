/**
 *  @file oglplus/texgen/coord_node.inl
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
coord_output::coord_output(node_intf& parent, coord_type func)
  : base_output(parent)
  , _type(func) {}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
string_view coord_output::type_name() {
    return string_view("Coord");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type coord_output::value_type() {
    return slot_data_type::float_3;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
coord_output::definitions(std::ostream& out, compile_context& context) {
    if(already_defined(context)) {
        return out;
    }

    input_defs(out, context);
    opening_expr(out, context);

    switch(_type) {
        case coord_type::normalized:
            out << "\treturn " << expr::norm_sample_coord{*this};
            out << ";" << std::endl;
            break;
        case coord_type::frag_coord:
            out << "\treturn gl_FragCoord;" << std::endl;
            break;
    }

    return closing_expr(out, context);
}
//------------------------------------------------------------------------------
} // namespace eagine::oglp::texgen
//------------------------------------------------------------------------------
