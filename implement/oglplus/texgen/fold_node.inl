/**
 *  @file oglplus/texgen/fold_node.inl
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
fold_output::
fold_output(node_intf& parent, fold_function fn)
 : base_output(parent)
 , _input(parent, cstr_ref("Input"), 0.f, 0.f, 0.f, 0.f)
 , _func(fn)
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
fold_output::type_name(void)
{
	switch(_func)
	{
		case fold_function::add:
			return cstr_ref("Add");
		case fold_function::multiply:
			return cstr_ref("Multiply");
		case fold_function::max:
			return cstr_ref("Max");
		case fold_function::min:
			return cstr_ref("Min");
	}
	return cstr_ref("Fold");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type
fold_output::param_type(void)
{
	slot_data_type result = _input.value_type();

	for(auto i = _inputs.begin(); i != _inputs.end(); ++i)
	{
		result = common_data_type(result, i->second.value_type());
	}

	return result;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type
fold_output::value_type(void)
{
	return param_type();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
fold_output::definitions(std::ostream& out, compile_context& ctxt)
{
	if(already_defined(ctxt)) return out;

	input_defs(out, ctxt);
	opening_expr(out, ctxt);

	slot_data_type pt = param_type();

	out << "\t" << data_type_name(pt) << " r = ";
	out << expr::conversion_prefix{_input.value_type(), pt};
	out << expr::output_id{_input.output(), ctxt};
	out << expr::render_param_pass{_input.output()};
	out << expr::conversion_suffix{_input.value_type(), pt};
	out << ";" << std::endl;

	for(auto i = _inputs.begin(); i != _inputs.end(); ++i)
	{
		input_with_const_default<float[4]>& input = i->second;

		out << "\tr = ";
		switch(_func)
		{
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

		switch(_func)
		{
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

		switch(_func)
		{
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
std::size_t
fold_node::input_count(void)
{
	return 1+_output._inputs.size();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
input_intf&
fold_node::input(std::size_t index)
{
	if(index == 0) return _output._input;
	assert(index < input_count());

	auto p = _output._inputs.begin();
	while(--index > 0)
	{
		assert(p != _output._inputs.end());
		p++;
	}
	assert(p != _output._inputs.end());
	return p->second;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
eagine::optional_reference_wrapper<input_intf>
fold_node::input_by_name(const cstr_ref& name)
{
	auto p = _output._inputs.find(
		std::string(name.data(), std::size_t(name.size()))
	);
	if(p != _output._inputs.end())
	{
		return p->second;
	}
	return nullptr;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
fold_node::can_add_input(void)
{
	return true;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
input_with_const_default<float[4]>&
fold_node::add_input(const cstr_ref& name)
{
	auto p = _output._inputs.emplace(
		std::string(name.data(), std::size_t(name.size())),
		input_with_const_default<float[4]>(
			*this,
			name,
			0.f, 0.f, 0.f, 0.f
		)
	);
	p.first->second.set_name(cstr_ref(
		p.first->first.data(),
		eagine::span_size_type(p.first->first.size())
	));
	return p.first->second;
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------

