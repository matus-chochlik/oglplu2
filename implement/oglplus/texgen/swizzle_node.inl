/**
 *  @file oglplus/texgen/swizzle_node.inl
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
bool is_valid_swizzle(string_view swizzle) noexcept {
    if(swizzle.size() < 1)
        return false;
    if(swizzle.size() > 4)
        return false;

    const std::string rgba("rgba");
    const std::string xyzw("xyzw");
    const std::string stpq("stpq");

    string_view::size_type rgba_c = 0, xyzw_c = 0, stpq_c = 0;

    for(char c : swizzle) {
        if(rgba.find(c) != std::string::npos)
            ++rgba_c;
        else if(xyzw.find(c) != std::string::npos)
            ++xyzw_c;
        else if(stpq.find(c) != std::string::npos)
            ++stpq_c;
    }

    return (swizzle.size() == rgba_c) || (swizzle.size() == xyzw_c) ||
           (swizzle.size() == stpq_c);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
swizzle_output::swizzle_output(node_intf& parent, const std::string& swiz)
  : base_output(parent)
  , swizzle(swiz)
  , input(parent, string_view("Input"), 0.5f, 0.5f, 0.5f, 0.5f) {
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
swizzle_output::swizzle_output(node_intf& parent)
  : swizzle_output(parent, "xyzw") {
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
string_view swizzle_output::type_name() {
    return string_view("Swizzle");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type swizzle_output::value_type() {
    return make_data_type(
      elem_data_type(input.value_type()), span_size(swizzle.size()));
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
swizzle_output::definitions(std::ostream& out, compile_context& ctxt) {
    if(already_defined(ctxt))
        return out;

    input_defs(out, ctxt);
    opening_expr(out, ctxt);

    slot_data_type tmp_dt =
      make_data_type(elem_data_type(input.value_type()), 4);

    out << "\treturn ";
    out << expr::conversion_prefix{input.value_type(), tmp_dt};
    out << expr::output_id{input.output(), ctxt};
    out << expr::render_param_pass{input.output()};
    out << expr::conversion_suffix{input.value_type(), tmp_dt};
    out << "." << swizzle << ";" << std::endl;

    return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------
