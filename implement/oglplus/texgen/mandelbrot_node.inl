/**
 *  @file oglplus/texgen/mandelbrot_node.inl
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
mandelbrot_output::mandelbrot_output(node_intf& parent)
 : base_output(parent)
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
mandelbrot_output::type_name(void)
{
	return cstr_ref("Mandelbrot");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type
mandelbrot_output::value_type(void)
{
	return slot_data_type::float_2;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
mandelbrot_output::definitions(std::ostream& result, compile_context& context)
{
	input_defs(result, context);

	opening_expr(result, context);

	result << "\tvec3 k = " << render_param_normalized_coords{*this}<<";\n";
	result << "\tvec2 c = k.xy;\n";
	result << "\tvec2 z = vec2(0.0);\n";
	result << "\tint i, max = 128;\n"; // TODO variable maximum?
	result << "\tfor(i = 0; (i<max) && (distance(c, z) < 2.0); ++i)\n";
	result << "\t{\n";
	result << "\t	z = vec2(\n";
	result << "\t		z.x * z.x - z.y * z.y + c.x,\n";
	result << "\t		2.0 * z.x * z.y + c.y\n";
	result << "\t	);\n";
	result << "\t}\n";
	result << "\treturn vec2(\n";
	result << "\t	float(i)/float(max),\n";
	result << "\t	distance(z, c)*0.5\n";
	result << "\t);\n";

	return closing_expr(result, context);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
mandelbrot_node::mandelbrot_node(void)
 : _output(*this)
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
base_output&
mandelbrot_node::single_output(void)
{
	return _output;
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------

