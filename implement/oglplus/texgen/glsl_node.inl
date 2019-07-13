/**
 *  @file oglplus/texgen/glsl_node.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/str_var_subst.hpp>
#include <iostream>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
glsl_output::glsl_output(
  node_intf& parent, std::string glsl, slot_data_type type)
  : multi_input_output(parent)
  , _glsl(std::move(glsl))
  , _type(type) {
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
string_view glsl_output::type_name() {
    return string_view("GLSL");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type glsl_output::value_type() {
    return _type;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& glsl_output::definitions(
  std::ostream& out, compile_context& ctxt) {
    if(already_defined(ctxt)) {
        return out;
    }

    input_defs(out, ctxt);
    opening_expr(out, ctxt);

    std::map<std::string, std::string, eagine::str_view_less> dict;

    dict["NORMALIZED_COORDS"] = "oglptg_nc";
    dict["NC"] = "oglptg_nc";
    dict["VOXEL_SIZE"] = "oglptg_vs";
    dict["VS"] = "oglptg_vs";
    dict["VOXEL_OFFSET"] = "oglptg_vo";
    dict["VO"] = "oglptg_vo";

    out << "\t" << data_type_name(_input.value_type());
    out << " oglptgi = ";
    out << expr::output_id{_input.output(), ctxt};
    out << expr::render_param_pass{_input.output()};
    out << ";" << std::endl;

    dict["Input"] = "oglptgi";
    dict["^"] = "oglptgi";

    for(auto& [id, input] : _inputs) {

        out << "\t" << data_type_name(input.value_type());
        out << " oglptgi_" << id << " = ";
        out << expr::output_id{input.output(), ctxt};
        out << expr::render_param_pass{input.output()};
        out << ";" << std::endl;

        dict[id] = std::string("oglptgi_") + id;
    }

    out << "\treturn ";
    out << eagine::substitute_variables(_glsl, dict);
    out << ";" << std::endl;

    return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
glsl_node::glsl_node()
  : _output(*this) {
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------
