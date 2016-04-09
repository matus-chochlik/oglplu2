/**
 *  @file oglplus/texgen/checker_node.inl
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
checker_output::checker_output(node_intf& parent)
 : base_output(parent)
 , repeat(parent, cstr_ref("Repeat"), 8.f, 8.f, 8.f)
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
checker_output::type_name(void)
{
	return cstr_ref("Checker");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type
checker_output::value_type(void)
{
	return slot_data_type::float_;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
checker_output::definitions(std::ostream& out, compile_context& ctxt)
{
	if(already_defined(ctxt)) return out;

	input_defs(out, ctxt);
	opening_expr(out, ctxt);

	out << "\tvec3 c = " << expr::normalized_coord{*this} << ";";
	out << std::endl;

	slot_data_type vec3_type = slot_data_type::float_3;
	out << "\tc *= ";
	out << expr::conversion_prefix{repeat.value_type(), vec3_type};
	out << expr::output_id{repeat.output(), ctxt};
	out << expr::render_param_pass{repeat.output()};
	out << expr::conversion_suffix{repeat.value_type(), vec3_type};
	out << ";" << std::endl;

	out << "\tc += " << expr::norm_voxel_offs{*this} << ";";
	out << std::endl;

	out << "\treturn mod(dot(mod(floor(c), 2), vec3(1)),2);" << std::endl;

	return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
checker_node::checker_node(void)
 : _output(*this)
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
base_output&
checker_node::single_output(void)
{
	return _output;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::size_t
checker_node::input_count(void)
{
	return 1u;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
input_intf&
checker_node::input(std::size_t index)
{
	assert(index < input_count());
	return _output.repeat;
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------

