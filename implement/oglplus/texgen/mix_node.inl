/**
 *  @file oglplus/texgen/mix_node.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/assert.hpp>
#include <iostream>
#include <set>
#include <string>

namespace eagine::oglp::texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
mix_output::mix_output(node_intf& parent)
  : base_output(parent)
  , zero(parent, string_view("Zero"), 0.f, 0.f, 0.f, 0.f)
  , one(parent, string_view("One"), 1.f, 1.f, 1.f, 1.f)
  , value(parent, string_view("Value"), 0.5f) {}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
string_view mix_output::type_name() {
    return string_view("Mix");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type mix_output::value_type() {
    return common_data_type(zero.value_type(), one.value_type());
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& mix_output::definitions(std::ostream& out, compile_context& ctxt) {
    if(already_defined(ctxt)) {
        return out;
    }

    slot_data_type res_type = value_type();
    slot_data_type val_type = slot_data_type::float_;

    input_defs(out, ctxt);
    opening_expr(out, ctxt);

    out << "\treturn mix(" << std::endl << "\t\t";

    out << expr::conversion_prefix{zero.value_type(), res_type};
    out << expr::output_id{zero.output(), ctxt};
    out << expr::render_param_pass{zero.output()};
    out << expr::conversion_suffix{zero.value_type(), res_type};
    out << "," << std::endl << "\t\t";

    out << expr::conversion_prefix{one.value_type(), res_type};
    out << expr::output_id{one.output(), ctxt};
    out << expr::render_param_pass{one.output()};
    out << expr::conversion_suffix{one.value_type(), res_type};
    out << "," << std::endl << "\t\t";

    out << expr::conversion_prefix{value.value_type(), val_type};
    out << expr::output_id{value.output(), ctxt};
    out << expr::render_param_pass{value.output()};
    out << expr::conversion_suffix{value.value_type(), val_type};
    out << std::endl << "\t";

    out << ");" << std::endl;
    return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
span_size_t mix_node::input_count() {
    return 3;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
input_intf& mix_node::input(span_size_t index) {
    if(index == 0) {
        return _output.zero;
    }
    if(index == 1) {
        return _output.one;
    }
    EAGINE_ASSERT(index < input_count());
    return _output.value;
}
//------------------------------------------------------------------------------
} // namespace eagine::oglp::texgen
//------------------------------------------------------------------------------
