/**
 *  @file oglplus/texgen/scale_node.inl
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
scale_output::scale_output(node_intf& parent)
  : base_output(parent)
  , input(parent, string_view("Input"), 0.5f, 0.5f, 0.5f, 0.5f)
  , scale(parent, string_view("Scale"), 1.f, 1.f, 1.f) {}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
string_view scale_output::type_name() {
    return string_view("Scale");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type scale_output::value_type() {
    return input.value_type();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
scale_output::definitions(std::ostream& out, compile_context& ctxt) {
    if(already_defined(ctxt)) {
        return out;
    }

    input_defs(out, ctxt);
    opening_expr(out, ctxt);

    slot_data_type v3 = slot_data_type::float_3;
    string_view o("1");

    out << "\t vec3 s = ";
    out << expr::conversion_prefix{scale.value_type(), v3};
    out << expr::output_id{scale.output(), ctxt};
    out << expr::render_param_pass{scale.output()};
    out << expr::conversion_suffix_v{scale.value_type(), v3, {o, o, o, o}};
    out << ";" << std::endl;

    out << "\t" << expr::normalized_coord{*this} << " /= s;" << std::endl;
    out << "\t" << expr::norm_voxel_size{*this} << " /= s;" << std::endl;

    out << "\treturn ";
    out << expr::output_id{input.output(), ctxt};
    out << expr::render_param_pass{input.output()};
    out << ";" << std::endl;

    return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
} // namespace eagine::oglp::texgen
//------------------------------------------------------------------------------
