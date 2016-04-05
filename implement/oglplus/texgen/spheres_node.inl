/**
 *  @file oglplus/texgen/spheres_node.inl
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
spheres_output::spheres_output(node_intf& parent)
 : base_output(parent)
 , repeat(parent, cstr_ref("Repeat"), 8.f, 8.f, 8.f)
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
spheres_output::type_name(void)
{
	return cstr_ref("Spheres");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type
spheres_output::value_type(void)
{
	return slot_data_type::float_;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
spheres_output::definitions(std::ostream& out, compile_context& ctxt)
{
	if(already_defined(ctxt)) return out;

	input_defs(out, ctxt);
	opening_expr(out, ctxt);

	out << "\tvec3 c = " << render_param_normalized_coords{*this} << ";";
	out << std::endl;

	slot_data_type vec3_type = slot_data_type::float_3;
	out << "\tc *= ";
	out << conversion_prefix_expr{repeat.value_type(), vec3_type};
	out << output_id_expr{repeat.output(), ctxt};
	out << render_param_pass_expr{repeat.output()};
	out << conversion_suffix_expr{repeat.value_type(), vec3_type};
	out << ";" << std::endl;

	out << "\tc = floor(c+vec3(0.5))-c;" << std::endl;

	out << "\treturn 1-2.0*length(c);" << std::endl;

	return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
spheres_node::spheres_node(void)
 : _output(*this)
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
base_output&
spheres_node::single_output(void)
{
	return _output;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::size_t
spheres_node::input_count(void)
{
	return 1u;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
input_intf&
spheres_node::input(std::size_t index)
{
	assert(index < input_count());
	return _output.repeat;
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------

