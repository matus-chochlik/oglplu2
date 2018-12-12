/**
 *  @file oglplus/texgen/fold_node.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <cassert>
#include <iostream>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
fold_output::fold_output(node_intf& parent, fold_function fn)
  : multi_input_output(parent)
  , _func(fn) {
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
string_view fold_output::type_name() {
    switch(_func) {
        case fold_function::add:
            return string_view("Add");
        case fold_function::multiply:
            return string_view("Multiply");
        case fold_function::max:
            return string_view("Max");
        case fold_function::min:
            return string_view("Min");
    }
    return string_view("Fold");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type fold_output::value_type() {
    return common_param_type();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
fold_output::definitions(std::ostream& out, compile_context& ctxt) {
    if(already_defined(ctxt))
        return out;

    input_defs(out, ctxt);
    opening_expr(out, ctxt);

    slot_data_type pt = common_param_type();

    out << "\t" << data_type_name(pt) << " r = ";
    out << expr::conversion_prefix{_input.value_type(), pt};
    out << expr::output_id{_input.output(), ctxt};
    out << expr::render_param_pass{_input.output()};
    out << expr::conversion_suffix{_input.value_type(), pt};
    out << ";" << std::endl;

    for(auto i = _inputs.begin(); i != _inputs.end(); ++i) {
        input_with_const_default<float[4]>& input = i->second;

        out << "\tr = ";
        switch(_func) {
            case fold_function::max:
                out << "max(";
                break;
            case fold_function::min:
                out << "min(";
                break;
            default:
                out << "(";
                break;
        }

        out << "r";

        switch(_func) {
            case fold_function::add:
                out << " + ";
                break;
            case fold_function::multiply:
                out << " * ";
                break;
            default:
                out << ", ";
                break;
        }

        out << expr::conversion_prefix{input.value_type(), pt};
        out << expr::output_id{input.output(), ctxt};
        out << expr::render_param_pass{input.output()};
        out << expr::conversion_suffix{input.value_type(), pt};

        switch(_func) {
            default:
                out << ")";
                break;
        }

        out << ";" << std::endl;
    }

    out << "\treturn r;" << std::endl;

    return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
fold_node::fold_node()
  : _output(*this) {
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------
