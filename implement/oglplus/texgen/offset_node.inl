/**
 *  @file oglplus/texgen/offset_node.inl
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
offset_output::offset_output(node_intf& parent)
 : base_output(parent)
 , input(parent, cstr_ref("Input"), 0.5f, 0.5f, 0.5f, 0.5f)
 , offset(parent, cstr_ref("Offset"), 0.f, 0.f, 0.f)
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
offset_output::type_name(void)
{
	return cstr_ref("Offset");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type
offset_output::value_type(void)
{
	return input.value_type();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
offset_output::definitions(std::ostream& out, compile_context& ctxt)
{
	if(already_defined(ctxt)) return out;

	input_defs(out, ctxt);
	opening_expr(out, ctxt);

	slot_data_type vec3_type = slot_data_type::float_3;

	out << "\t" << render_param_normalized_coords{*this} << " += ";
	out << conversion_prefix_expr{offset.value_type(), vec3_type};
	out << output_id_expr{offset.output(), ctxt};
	out << render_param_pass_expr{offset.output()};
	out << conversion_suffix_expr{offset.value_type(), vec3_type};
	out << ";" << std::endl;

	out << "\treturn ";
	out << output_id_expr{input.output(), ctxt};
	out << render_param_pass_expr{input.output()};
	out << ";" << std::endl;

	return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
offset_node::offset_node(void)
 : _output(*this)
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
base_output&
offset_node::single_output(void)
{
	return _output;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::size_t
offset_node::input_count(void)
{
	return 2u;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
input_intf&
offset_node::input(std::size_t index)
{
	if(index == 0) return _output.input;
	assert(index < input_count());
	return _output.offset;
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------

