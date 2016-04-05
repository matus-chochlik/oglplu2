/**
 *  @file oglplus/texgen/posterize_node.inl
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
posterize_output::posterize_output(node_intf& parent)
 : base_output(parent)
 , input(parent, cstr_ref("Input"), 0.5f, 0.5f, 0.5f, 0.5f)
 , levels(parent, cstr_ref("Levels"), 4.f, 4.f, 4.f, 4.f)
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
posterize_output::type_name(void)
{
	return cstr_ref("Posterize");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type
posterize_output::value_type(void)
{
	return input.value_type();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
posterize_output::definitions(std::ostream& out, compile_context& ctxt)
{
	if(already_defined(ctxt)) return out;

	input_defs(out, ctxt);
	opening_expr(out, ctxt);

	slot_data_type vt = value_type();
	const cstr_ref f("4.0");

	out << "\t" << data_type_name(vt) << " lvls = ";
	out << conversion_prefix_expr{levels.value_type(), vt};
	out << output_id_expr{levels.output(), ctxt};
	out << render_param_pass_expr{levels.output()};
	conversion_suffix(out, levels.value_type(), vt, f, f, f, f);
	out << ";" << std::endl;

	out << "\tlvls = max(lvls, " << data_type_name(vt);
	out << "(1));" << std::endl;

	out << "\treturn floor(";
	out << output_id_expr{input.output(), ctxt};
	out << render_param_pass_expr{input.output()};
	out << "*lvls)/lvls;" << std::endl;

	return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
posterize_node::posterize_node(void)
 : _output(*this)
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
base_output&
posterize_node::single_output(void)
{
	return _output;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::size_t
posterize_node::input_count(void)
{
	return 2u;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
input_intf&
posterize_node::input(std::size_t index)
{
	if(index == 0) return _output.input;
	assert(index < input_count());
	return _output.levels;
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------

