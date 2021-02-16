/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <cassert>
#include <iostream>

namespace eagine::oglp::texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
unary_function_output::unary_function_output(
  node_intf& parent,
  unary_function fn)
  : base_output(parent)
  , _input(parent, string_view("Input"), 0.5f, 0.5f, 0.5f, 0.5f)
  , _func(fn) {}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
string_view unary_function_output::type_name() {
    switch(_func) {
        case unary_function::radians:
            return string_view("Radians");
        case unary_function::degrees:
            return string_view("Degrees");
        case unary_function::sin:
            return string_view("Sin");
        case unary_function::cos:
            return string_view("Cos");
        case unary_function::tan:
            return string_view("Tan");
        case unary_function::asin:
            return string_view("ASin");
        case unary_function::acos:
            return string_view("ACos");
        case unary_function::atan:
            return string_view("ATan");
        case unary_function::abs:
            return string_view("Abs");
        case unary_function::sign:
            return string_view("Sign");
        case unary_function::sqrt:
            return string_view("Sqrt");
        case unary_function::inversesqrt:
            return string_view("InverseSqrt");
        case unary_function::floor:
            return string_view("Floor");
        case unary_function::ceil:
            return string_view("Ceil");
        case unary_function::exp:
            return string_view("Exp");
        case unary_function::exp2:
            return string_view("Exp2");
        case unary_function::log:
            return string_view("Log");
        case unary_function::log2:
            return string_view("Log2");
        case unary_function::negate:
            return string_view("Negate");
        case unary_function::length:
            return string_view("Length");
        case unary_function::none:
            break;
    }
    return string_view("UnaryFunction");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type unary_function_output::value_type() {
    switch(_func) {
        case unary_function::length:
            return slot_data_type::float_;
        default:
            break;
    }
    return make_data_type(
      scalar_data_type::float_, data_type_dims(_input.value_type()));
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
unary_function_output::definitions(std::ostream& out, compile_context& ctxt) {
    if(already_defined(ctxt)) {
        return out;
    }

    input_defs(out, ctxt);
    opening_expr(out, ctxt);

    out << "\treturn ";
    switch(_func) {
        case unary_function::radians:
            out << "radians(";
            break;
        case unary_function::degrees:
            out << "degrees(";
            break;
        case unary_function::sin:
            out << "sin(";
            break;
        case unary_function::cos:
            out << "cos(";
            break;
        case unary_function::tan:
            out << "tan(";
            break;
        case unary_function::asin:
            out << "asin(";
            break;
        case unary_function::acos:
            out << "acos(";
            break;
        case unary_function::atan:
            out << "atan(";
            break;
        case unary_function::abs:
            out << "abs(";
            break;
        case unary_function::sign:
            out << "sign(";
            break;
        case unary_function::sqrt:
            out << "sqrt(";
            break;
        case unary_function::inversesqrt:
            out << "inversesqrt(";
            break;
        case unary_function::floor:
            out << "floor(";
            break;
        case unary_function::ceil:
            out << "ceil(";
            break;
        case unary_function::exp:
            out << "exp(";
            break;
        case unary_function::exp2:
            out << "exp2(";
            break;
        case unary_function::log:
            out << "log(";
            break;
        case unary_function::log2:
            out << "log2(";
            break;
        case unary_function::length:
            out << "length(";
            break;
        case unary_function::negate:
            out << "-(";
            break;
        case unary_function::none:
            out << "(";
            break;
    }
    out << expr::output_id{_input.output(), ctxt};
    out << expr::render_param_pass{_input.output()};
    out << ");" << std::endl;

    return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
binary_function_output::binary_function_output(
  node_intf& parent,
  binary_function fn)
  : base_output(parent)
  , _input_a(parent, string_view("A"), 0.f, 0.f, 0.f, 0.f)
  , _input_b(parent, string_view("B"), 1.f, 1.f, 1.f, 1.f)
  , _func(fn) {}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
string_view binary_function_output::type_name() {
    switch(_func) {
        case binary_function::equal:
            return string_view("Equal");
        case binary_function::not_equal:
            return string_view("NotEqual");
        case binary_function::less:
            return string_view("Less");
        case binary_function::less_equal:
            return string_view("LessEqual");
        case binary_function::greater:
            return string_view("Greater");
        case binary_function::greater_equal:
            return string_view("GreaterEqual");
        case binary_function::add:
            return string_view("Add");
        case binary_function::subtract:
            return string_view("Subtract");
        case binary_function::multiply:
            return string_view("Multiply");
        case binary_function::divide:
            return string_view("Divide");
        case binary_function::modulo:
            return string_view("Modulo");
        case binary_function::max:
            return string_view("Max");
        case binary_function::min:
            return string_view("Min");
        case binary_function::distance:
            return string_view("Distance");
        case binary_function::power:
            return string_view("Power");
        case binary_function::dot:
            return string_view("Dot");
        case binary_function::average:
            return string_view("average");
    }
    return string_view("BinaryFunction");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type binary_function_output::value_type() {
    switch(_func) {
        case binary_function::distance:
            return slot_data_type::float_;
        case binary_function::dot:
            return slot_data_type::float_;
        default:
            break;
    }
    return make_data_type(
      scalar_data_type::float_,
      common_dims(_input_a.value_type(), _input_b.value_type()));
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
binary_function_output::definitions(std::ostream& out, compile_context& ctxt) {
    if(already_defined(ctxt)) {
        return out;
    }

    input_defs(out, ctxt);
    opening_expr(out, ctxt);

    slot_data_type dta = make_data_type(
      scalar_data_type::float_,
      common_dims(_input_a.value_type(), _input_b.value_type()));
    slot_data_type dtb = dta;

    out << "\t" << data_type_name(dta) << " a = ";
    out << expr::conversion_prefix{_input_a.value_type(), dta};
    out << expr::output_id{_input_a.output(), ctxt};
    out << expr::render_param_pass{_input_a.output()};
    out << expr::conversion_suffix{_input_a.value_type(), dta};
    out << ";" << std::endl;

    out << "\t" << data_type_name(dtb) << " b = ";
    out << expr::conversion_prefix{_input_b.value_type(), dtb};
    out << expr::output_id{_input_b.output(), ctxt};
    out << expr::render_param_pass{_input_b.output()};
    out << expr::conversion_suffix{_input_b.value_type(), dtb};
    out << ";" << std::endl;

    out << "\treturn ";
    switch(_func) {
        case binary_function::equal:
            out << "(" << data_type_name(dta);
            out << "(1)-abs(sign(";
            break;
        case binary_function::not_equal:
            out << "abs(sign(";
            break;
        case binary_function::less:
            out << "max(-sign(";
            break;
        case binary_function::less_equal:
            out << "(" << data_type_name(dta);
            out << "(1)-max(-sign(";
            break;
        case binary_function::greater:
            out << "max(sign(";
            break;
        case binary_function::greater_equal:
            out << "(" << data_type_name(dta);
            out << "(1)-max(sign(";
            break;
        case binary_function::modulo:
            out << "mod(";
            break;
        case binary_function::max:
            out << "max(";
            break;
        case binary_function::min:
            out << "min(";
            break;
        case binary_function::distance:
            out << "distance(";
            break;
        case binary_function::power:
            out << "pow(";
            break;
        case binary_function::dot:
            out << "dot(";
            break;
        case binary_function::average:
            out << "mix(";
            break;
        default:
            out << "(";
            break;
    }

    out << "a";

    switch(_func) {
        case binary_function::equal:
        case binary_function::not_equal:
        case binary_function::less:
        case binary_function::greater:
        case binary_function::less_equal:
        case binary_function::greater_equal:
        case binary_function::subtract:
            out << " - ";
            break;
        case binary_function::add:
            out << " + ";
            break;
        case binary_function::multiply:
            out << " * ";
            break;
        case binary_function::divide:
            out << " / ";
            break;
        default:
            out << ", ";
            break;
    }

    out << "b";

    switch(_func) {
        case binary_function::equal:
            out << ")))";
            break;
        case binary_function::not_equal:
            out << "))";
            break;
        case binary_function::less:
        case binary_function::greater:
            out << "), " << data_type_name(dtb);
            out << "(0))";
            break;
        case binary_function::less_equal:
        case binary_function::greater_equal:
            out << "), " << data_type_name(dtb);
            out << "(0)))";
            break;
        case binary_function::average:
            out << ", 0.5)";
            break;
        default:
            out << ")";
            break;
    }

    out << ";" << std::endl;

    return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
} // namespace eagine::oglp::texgen
//------------------------------------------------------------------------------
