/// @file oglplus/texgen/checker_node.inl
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <cassert>
#include <iostream>
#include <set>
#include <string>

namespace eagine::oglp::texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
checker_output::checker_output(node_intf& parent)
  : base_output(parent)
  , repeat(parent, string_view("Repeat"), 8.f, 8.f, 8.f) {}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
string_view checker_output::type_name() {
    return string_view("Checker");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type checker_output::value_type() {
    return slot_data_type::float_;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
checker_output::definitions(std::ostream& out, compile_context& ctxt) {
    if(already_defined(ctxt)) {
        return out;
    }

    input_defs(out, ctxt);
    opening_expr(out, ctxt);

    out << "\tvec3 c = " << expr::normalized_coord{*this} << ";";
    out << std::endl;

    slot_data_type vec3_type = slot_data_type::float_3;
    out << "\tc *= ";
    out << expr::conversion_prefix{repeat.value_type(), vec3_type};
    out << expr::output_id{repeat.output(), ctxt};
    out << expr::render_param_pass{repeat.output()};
    out << expr::conversion_suffix{repeat.value_type(), vec3_type};
    out << ";" << std::endl;

    out << "\tc += " << expr::norm_voxel_offs{*this} << ";";
    out << std::endl;

    out << "\treturn mod(dot(mod(floor(c), 2), vec3(1)),2);" << std::endl;

    return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
pixel_checker_output::pixel_checker_output(node_intf& parent)
  : base_output(parent) {}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
string_view pixel_checker_output::type_name() {
    return string_view("PixelChecker");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type pixel_checker_output::value_type() {
    return slot_data_type::float_;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
pixel_checker_output::definitions(std::ostream& out, compile_context& ctxt) {
    if(already_defined(ctxt)) {
        return out;
    }

    input_defs(out, ctxt);
    opening_expr(out, ctxt);

    out << "\tvec3 c = gl_FragCoord.xyz + ";
    out << expr::voxel_offset{*this} << ";" << std::endl;
    out << "\treturn mod(dot(mod(floor(c), 2), vec3(1)),2);" << std::endl;

    return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
} // namespace eagine::oglp::texgen
//------------------------------------------------------------------------------
