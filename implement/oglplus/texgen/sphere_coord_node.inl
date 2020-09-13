/**
 *  @file oglplus/texgen/sphere_coord_node.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/texgen/constants.hpp>
#include <iostream>

namespace eagine::oglp::texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
sphere_coord_output::sphere_coord_output(node_intf& parent)
  : base_output(parent) {}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
string_view sphere_coord_output::type_name() {
    return string_view("SphereCoord");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type sphere_coord_output::value_type() {
    return slot_data_type::float_4;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
sphere_coord_output::definitions(std::ostream& out, compile_context& ctxt) {
    if(already_defined(ctxt)) {
        return out;
    }

    constant_pi cpi;

    cpi.definitions(out, ctxt);
    input_defs(out, ctxt);
    opening_expr(out, ctxt);

    out << "\tvec3 s = " << expr::norm_sample_coord{*this};
    out << ";" << std::endl;

    out << "\treturn vec4(" << std::endl;
    out << "\t\tatan(s.y, s.x)";
    out << "/(2.0*" << expr::constant_id{cpi, ctxt} << ")," << std::endl;
    out << "\t\tatan(s.z, s.x)";
    out << "/(2.0*" << expr::constant_id{cpi, ctxt} << ")," << std::endl;
    out << "\t\tatan(s.y, s.z)";
    out << "/(2.0*" << expr::constant_id{cpi, ctxt} << ")," << std::endl;
    out << "\t\tlength(s)" << std::endl;
    out << "\t);" << std::endl;

    return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
} // namespace eagine::oglp::texgen
//------------------------------------------------------------------------------
