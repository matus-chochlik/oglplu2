/**
 *  @file oglplus/texgen/base_output.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <set>
#include <string>
#include <iostream>
#include <cassert>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
base_output::input_defs(std::ostream& out, compile_context& ctxt)
{
	return parent().input_definitions(out, ctxt);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
base_output::opening_expr(std::ostream& out, compile_context& ctxt)
{
	out << data_type_name(value_type()) << " ";
	out << output_id_expr{*this, ctxt};
	out << render_param_decl_expr{*this} << "{" << std::endl;
	return out;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
base_output::closing_expr(std::ostream& out, compile_context&)
{
	return out << "}" << std::endl << std::endl;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
base_output::already_defined(compile_context& context)
{
	if(!context.remembers_output(*this))
	{
		context.remember_output(*this);
		return false;
	}
	return true;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
base_output::name(void)
noexcept
{
	return cstr_ref("Output");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
render_param_bits
base_output::required_params(void)
{
	return all_render_params();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
base_output::definitions(std::ostream& out, compile_context&)
{
	return out;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
base_output::expression(std::ostream& out, compile_context&)
{
	append_id(out);
	return out;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
base_output::is_connected(input_intf& input)
{
	return _inputs.find(&input) != _inputs.end();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
base_output::connect(input_intf& input)
{
	if(input.accepts_value_type(value_type()))
	{
		assert(!is_connected(input));
		_inputs.insert(&input);
		return true;
	}
	return false;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
base_output::disconnect(input_intf& input)
{
	assert(is_connected(input));
	_inputs.erase(&input);
	return true;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void
base_output::notify_connected(void)
{
	for(auto* input : _inputs)
	{
		assert(input != nullptr);
		input->update_needed();
	}
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
base_output::render(const render_params& params)
{
	return parent().render(params);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::intptr_t
base_output::get_id(void) const
noexcept
{
	return reinterpret_cast<std::intptr_t>(this);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void
base_output::append_id(std::ostream& out, const cstr_ref& name)
{
	out << "oglptg" << name << get_id();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void
base_output::append_id(std::ostream& out)
{
	append_id(out, type_name());
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& operator << (std::ostream& out, const output_id_expr& expr)
{
	expr.output.expression(out, expr.context);
	return out;
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------

