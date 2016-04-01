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
	return slot_data_type::int_;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
checker_output::definitions(std::ostream& out, compile_context& ctxt)
{
	repeat.definitions(out, ctxt);

	slot_data_type res_type = value_type();
	slot_data_type vec3_type = slot_data_type::float_3;

	out << data_type_name(res_type) << " ";
	out << output_id_expr{*this, ctxt};
	out << render_param_decl_expr{*this} << "{\n\t";
	out << "vec3 c = " << render_param_normalized_coords{*this} << ";\n\t";

	out << "c *= ";
	out << conversion_prefix_expr{repeat.value_type(), vec3_type};
	out << output_id_expr{repeat.output(), ctxt};
	out << render_param_pass_expr{repeat.output()};
	out << conversion_suffix_expr{repeat.value_type(), vec3_type};
	out << ";\n\t";

	out << "return (int(c.x)%2+int(c.y)%2+int(c.z)%2)%2;\n";
	out << "}\n";
	return out;
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

