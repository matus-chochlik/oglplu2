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

	out << "\t" << expr::normalized_coord{*this} << " += ";
	out << expr::conversion_prefix{offset.value_type(), vec3_type};
	out << expr::output_id{offset.output(), ctxt};
	out << expr::render_param_pass{offset.output()};
	out << expr::conversion_suffix{offset.value_type(), vec3_type};
	out << ";" << std::endl;

	out << "\treturn ";
	out << expr::output_id{input.output(), ctxt};
	out << expr::render_param_pass{input.output()};
	out << ";" << std::endl;

	return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------

