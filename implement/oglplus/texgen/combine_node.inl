/// @file oglplus/texgen/combine_node.inl
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>

namespace eagine::oglp::texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
combine_output::combine_output(node_intf& parent)
  : base_output(parent)
  , input_r(parent, string_view("Red"))
  , input_g(parent, string_view("Green"))
  , input_b(parent, string_view("Blue"))
  , input_a(parent, string_view("Alpha")) {}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
string_view combine_output::type_name() {
    return string_view("Combine");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
scalar_data_type combine_output::component_type() {
    return elem_data_type(common_data_type(
      common_data_type(
        input_r.output().value_type(), input_g.output().value_type()),
      common_data_type(
        input_b.output().value_type(), input_a.output().value_type())));
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type combine_output::value_type() {
    return make_data_type(component_type(), 4);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::string combine_output::_input_expr(
  _input_t& input,
  slot_data_type type,
  compile_context& ctxt) {
    std::stringstream res;

    res << expr::conversion_prefix{input.value_type(), type};
    res << expr::output_id{input.output(), ctxt};
    res << expr::render_param_pass{input.output()};
    res << expr::conversion_suffix{input.value_type(), type};
    return res.str();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
combine_output::definitions(std::ostream& out, compile_context& ctxt) {
    if(already_defined(ctxt)) {
        return out;
    }

    input_defs(out, ctxt);
    opening_expr(out, ctxt);

    slot_data_type dt = make_data_type(component_type(), 1);

    std::map<std::string, std::set<span_size_t>> expr_to_inputs;

    expr_to_inputs[_input_expr(input_r, dt, ctxt)].insert(0);
    expr_to_inputs[_input_expr(input_g, dt, ctxt)].insert(1);
    expr_to_inputs[_input_expr(input_b, dt, ctxt)].insert(2);
    expr_to_inputs[_input_expr(input_a, dt, ctxt)].insert(3);

    std::map<span_size_t, span_size_t> component_to_expr;

    span_size_t v = 0;

    for(const auto& ei : expr_to_inputs) {
        out << "\t" << data_type_name(dt);
        out << " value" << v << " = " << ei.first << ";" << std::endl;

        for(span_size_t cmpn : ei.second) {
            component_to_expr[cmpn] = v;
        }
        ++v;
    }

    out << "\treturn " << data_type_name(value_type()) << "(";
    for(span_size_t i = 0; i < 4; ++i) {
        if(i > 0) {
            out << ", ";
        }
        out << "value" << component_to_expr[i];
    }
    out << ");" << std::endl;

    return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
span_size_t combine_node::input_count() {
    return 4;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
input_intf& combine_node::input(span_size_t index) {
    if(index == 0) {
        return _output.input_r;
    }
    if(index == 1) {
        return _output.input_g;
    }
    if(index == 2) {
        return _output.input_b;
    }
    EAGINE_ASSERT(index < input_count());
    return _output.input_a;
}
//------------------------------------------------------------------------------
} // namespace eagine::oglp::texgen
//------------------------------------------------------------------------------
