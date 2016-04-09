/**
 *  @file oglplus/texgen/scale_node.inl
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
scale_output::scale_output(node_intf& parent)
 : base_output(parent)
 , input(parent, cstr_ref("Input"), 0.5f, 0.5f, 0.5f, 0.5f)
 , scale(parent, cstr_ref("Scale"), 1.f, 1.f, 1.f)
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
scale_output::type_name(void)
{
	return cstr_ref("Scale");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type
scale_output::value_type(void)
{
	return input.value_type();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
scale_output::definitions(std::ostream& out, compile_context& ctxt)
{
	if(already_defined(ctxt)) return out;

	input_defs(out, ctxt);
	opening_expr(out, ctxt);

	slot_data_type v3 = slot_data_type::float_3;
	cstr_ref o("1");

	out << "\t vec3 s = ";
	out << expr::conversion_prefix{scale.value_type(), v3};
	out << expr::output_id{scale.output(), ctxt};
	out << expr::render_param_pass{scale.output()};
	out << expr::conversion_suffix_v{scale.value_type(), v3, {o,o,o,o}};
	out << ";" << std::endl;

	out << "\t" << expr::normalized_coord{*this} << " /= s;" << std::endl;
	out << "\t" << expr::norm_voxel_size{*this} << " /= s;" << std::endl;

	out << "\treturn ";
	out << expr::output_id{input.output(), ctxt};
	out << expr::render_param_pass{input.output()};
	out << ";" << std::endl;

	return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::size_t
scale_node::input_count(void)
{
	return 2u;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
input_intf&
scale_node::input(std::size_t index)
{
	if(index == 0) return _output.input;
	assert(index < input_count());
	return _output.scale;
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------

