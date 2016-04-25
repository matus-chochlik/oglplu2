/**
 *  @file oglplus/texgen/functional_node.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <iostream>
#include <cassert>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
unary_function_output::
unary_function_output(node_intf& parent, unary_function fn)
 : base_output(parent)
 , _input(parent, cstr_ref("Input"), 0.5f, 0.5f, 0.5f, 0.5f)
 , _func(fn)
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
unary_function_output::type_name(void)
{
	switch(_func)
	{
		case unary_function::radians:
			return cstr_ref("Radians");
		case unary_function::degrees:
			return cstr_ref("Degrees");
		case unary_function::sin:
			return cstr_ref("Sin");
		case unary_function::cos:
			return cstr_ref("Cos");
		case unary_function::tan:
			return cstr_ref("Tan");
		case unary_function::asin:
			return cstr_ref("ASin");
		case unary_function::acos:
			return cstr_ref("ACos");
		case unary_function::atan:
			return cstr_ref("ATan");
		case unary_function::abs:
			return cstr_ref("Abs");
		case unary_function::sign:
			return cstr_ref("Sign");
		case unary_function::sqrt:
			return cstr_ref("Sqrt");
		case unary_function::inversesqrt:
			return cstr_ref("InverseSqrt");
		case unary_function::floor:
			return cstr_ref("Floor");
		case unary_function::ceil:
			return cstr_ref("Ceil");
		case unary_function::exp:
			return cstr_ref("Exp");
		case unary_function::exp2:
			return cstr_ref("Exp2");
		case unary_function::log:
			return cstr_ref("Log");
		case unary_function::log2:
			return cstr_ref("Log2");
		case unary_function::negate:
			return cstr_ref("Negate");
		case unary_function::length:
			return cstr_ref("Length");
		case unary_function::none: break;
	}
	return cstr_ref("UnaryFunction");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type
unary_function_output::value_type(void)
{
	switch(_func)
	{
		case unary_function::length: return slot_data_type::float_;
		default: break;
	}
	return make_data_type(
		scalar_data_type::float_,
		data_type_dims(_input.value_type())
	);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
unary_function_output::definitions(std::ostream& out, compile_context& ctxt)
{
	if(already_defined(ctxt)) return out;

	input_defs(out, ctxt);
	opening_expr(out, ctxt);

	out << "\treturn ";
	switch(_func)
	{
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
binary_function_output::
binary_function_output(node_intf& parent, binary_function fn)
 : base_output(parent)
 , _input_a(parent, cstr_ref("A"), 0.f, 0.f, 0.f, 0.f)
 , _input_b(parent, cstr_ref("B"), 1.f, 1.f, 1.f, 1.f)
 , _func(fn)
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
binary_function_output::type_name(void)
{
	switch(_func)
	{
		case binary_function::equal:
			return cstr_ref("Equal");
		case binary_function::not_equal:
			return cstr_ref("NotEqual");
		case binary_function::less:
			return cstr_ref("Less");
		case binary_function::less_equal:
			return cstr_ref("LessEqual");
		case binary_function::greater:
			return cstr_ref("Greater");
		case binary_function::greater_equal:
			return cstr_ref("GreaterEqual");
		case binary_function::add:
			return cstr_ref("Add");
		case binary_function::subtract:
			return cstr_ref("Subtract");
		case binary_function::multiply:
			return cstr_ref("Multiply");
		case binary_function::divide:
			return cstr_ref("Divide");
		case binary_function::modulo:
			return cstr_ref("Modulo");
		case binary_function::max:
			return cstr_ref("Max");
		case binary_function::min:
			return cstr_ref("Min");
		case binary_function::distance:
			return cstr_ref("Distance");
		case binary_function::power:
			return cstr_ref("Power");
		case binary_function::dot:
			return cstr_ref("Dot");
		case binary_function::average:
			return cstr_ref("average");
	}
	return cstr_ref("BinaryFunction");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type
binary_function_output::value_type(void)
{
	switch(_func)
	{
		case binary_function::distance: return slot_data_type::float_;
		case binary_function::dot: return slot_data_type::float_;
		default: break;
	}
	return make_data_type(
		scalar_data_type::float_,
		common_dims(_input_a.value_type(), _input_b.value_type())
	);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
binary_function_output::definitions(std::ostream& out, compile_context& ctxt)
{
	if(already_defined(ctxt)) return out;

	input_defs(out, ctxt);
	opening_expr(out, ctxt);

	slot_data_type dta = make_data_type(
		scalar_data_type::float_,
		common_dims(_input_a.value_type(), _input_b.value_type())
	);
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
	switch(_func)
	{
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

	switch(_func)
	{
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

	switch(_func)
	{
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
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------

