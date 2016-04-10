/**
 *  @file oglplus/texgen/border2d_node.inl
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
border2d_output::border2d_output(node_intf& parent)
 : base_output(parent)
 , mode(border2d_mode::max)
 , input(parent, cstr_ref("Input"), 0.5f, 0.5f, 0.5f, 0.5f)
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
border2d_output::type_name(void)
{
	return cstr_ref("Border2D");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type
border2d_output::value_type(void)
{
	return input.value_type();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
border2d_output::definitions(std::ostream& out, compile_context& ctxt)
{
	if(already_defined(ctxt)) return out;

	input_defs(out, ctxt);
	opening_expr(out, ctxt);

	out << "\t" << data_type_name(value_type());
	out << " c = ";
	out << expr::output_id{input.output(), ctxt};
	out << expr::render_param_pass{input.output()};
	out << ";" << std::endl;
	out << "\t" << data_type_name(value_type());
	out << " r = " << data_type_name(value_type()) << "(";

	cstr_ref func_name;
	switch(mode)
	{
		case border2d_mode::max:
			out << "0.0";
			func_name = cstr_ref("max");
			break;
		case border2d_mode::min:
			out << "1.0";
			func_name = cstr_ref("min");
			break;
	}

	out << ");" << std::endl;

	auto func = [this,&out,&ctxt,&func_name](float x, float y)
	{
		out << "\tr = " << func_name << "(r, ";
		out << expr::output_id{input.output(), ctxt};
		out << expr::render_param_pass_voxel_offs{
			input.output(),
			{ x, y, 0.f}
		};
		out << ");" << std::endl;
	};

	func(-1,-1);
	func(-1, 0);
	func(-1, 1);
	func( 0,-1);
	func( 0, 1);
	func( 1,-1);
	func( 1, 0);
	func( 1, 1);

	out << "\treturn abs(r-c);" << std::endl;

	return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------

