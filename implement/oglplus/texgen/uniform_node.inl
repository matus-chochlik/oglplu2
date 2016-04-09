/**
 *  @file oglplus/texgen/uniform_node.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <iostream>
#include <sstream>
#include <cassert>
#include <oglplus/program.hpp>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
uniform_output::uniform_output(node_intf& parent, slot_data_type type)
 : base_output(parent)
 , _value_type(type)
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void
uniform_output::bind_location(void)
{
	std::stringstream id;
	append_id(id);
	id << "u";

	_location = prog_var_loc_ops<tag::uniform>::get_location(
		oper::program_ops::current_program(),
		cstr_ref(id.str())
	);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
uniform_output::type_name(void)
{
	return cstr_ref("Uniform");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type
uniform_output::value_type(void)
{
	return _value_type;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
uniform_output::definitions(std::ostream& out, compile_context& ctxt)
{
	if(already_defined(ctxt)) return out;

	input_defs(out, ctxt);

	out << "uniform " << data_type_name(value_type()) << " ";
	out << output_id_expr{*this, ctxt} << "u;" << std::endl;

	opening_expr(out, ctxt);

	out << "\treturn ";
	out << output_id_expr{*this, ctxt} << "u;" << std::endl;

	return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
uniform_node::uniform_node(slot_data_type type)
 : _output(*this, type)
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
uniform_node::uniform_node(void)
 : uniform_node(slot_data_type::float_4)
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void
uniform_node::prepare(void)
{
	_output.bind_location();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
base_output&
uniform_node::single_output(void)
{
	return _output;
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------

