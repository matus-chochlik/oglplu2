/**
 *  @file oglplus/texgen/newton_node.inl
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
newton_output::newton_output(node_intf& parent)
 : base_output(parent)
 , _function(newton_function::xe3minus1)
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
newton_output::type_name(void)
{
	return cstr_ref("Newton");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type
newton_output::value_type(void)
{
	return slot_data_type::float_;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
newton_output::_func_name(void) const
{
	if(_function == newton_function::xe3minus1)
	{
		return cstr_ref("fXe3Minus1");
	}
	else if(_function == newton_function::xe4minus1)
	{
		return cstr_ref("fXe4Minus1");
	}
	return cstr_ref();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
newton_output::definitions(std::ostream& result, compile_context& context)
{
	if(already_defined(context)) return result;

	input_defs(result, context);

	cstr_ref tag("complex_div");
	if(!context.has_tag(tag))
	{
		result << "vec2 oglptgComplexDiv(vec2 a, vec2 b)\n";
		result << "{\n";
		result << "	float d = dot(b, b);\n";
		result << "	return (d == 0.0)?a:vec2(\n";
		result << "		(a.x*b.x + a.y*b.y) / d,\n";
		result << "		(a.y*b.x - a.x*b.y) / d\n";
		result << "	);\n";
		result << "}\n";

		context.add_tag(tag);
	}

	if(_function == newton_function::xe3minus1)
	{
		tag = cstr_ref("complex_xe3minus1");
		if(!context.has_tag(tag))
		{
			result << "vec2 oglptgNewton_";
			result << _func_name() << "(vec2 n)\n";
			result << "{\n";
			result << "\treturn vec2(\n";
			result << "\t	n.x*n.x*n.x-3.0*n.x*n.y*n.y-1.0,\n";
			result << "\t	-n.y*n.y*n.y+3.0*n.x*n.x*n.y\n";
			result << "\t);\n";
			result << "}\n";

			result << "vec2 oglptgNewton_d";
			result << _func_name() << "(vec2 n)\n";
			result << "{\n";
			result << "\treturn 3.0 * vec2(\n";
			result << "\t	n.x*n.x - n.y*n.y,\n";
			result << "\t	2.0 * n.x * n.y\n";
			result << "\t);\n";
			result << "}\n";

			context.add_tag(tag);
		}
	}
	else if(_function == newton_function::xe4minus1)
	{
		tag = cstr_ref("complex_xe4minus1");
		if(!context.has_tag(tag))
		{
			result << "vec2 oglptgNewton_";
			result << _func_name() << "(vec2 n)\n";
			result << "{\n";
			result << "\treturn vec2(\n";
			result << "\t	n.x*n.x*n.x*n.x +\n";
			result << "\t	n.y*n.y*n.y*n.y -\n";
			result << "\t	6.0*n.x*n.x*n.y*n.y - 1.0,\n";
			result << "\t	4.0*n.x*n.x*n.x*n.y -\n";
			result << "\t	4.0*n.x*n.y*n.y*n.y\n";
			result << "\t);\n";
			result << "}\n";

			result << "vec2 oglptgNewton_d";
			result << _func_name() << "(vec2 n)\n";
			result << "{\n";
			result << "\treturn 4.0 * vec2(\n";
			result << "\t	 n.x*n.x*n.x - 3.0*n.x*n.y*n.y,\n";
			result << "\t	-n.y*n.y*n.y + 3.0*n.x*n.x*n.y\n";
			result << "\t);\n";
			result << "}\n";

			context.add_tag(tag);
		}
	}

	opening_expr(result, context);

	result << "\tvec3 k = " << render_param_normalized_coords{*this}<<";\n";
	result << "\tvec2 z = k.xy;\n";
	result << "\tint i, max = 64;\n";
	result << "\tfor(i = 0; i < max; ++i)\n";
	result << "\t{\n";
	result << "\t	vec2 zn = z - oglptgComplexDiv(\n";

	result << "\t		oglptgNewton_" << _func_name() << "(z),\n";
	result << "\t		oglptgNewton_d" << _func_name() << "(z)\n";

	result << "\t	);\n";
	result << "\t	if(distance(zn, z) < 0.00001) break;\n";
	result << "\t	z = zn;\n";
	result << "\t}\n";
	result << "\treturn float(i)/float(max);\n";

	return closing_expr(result, context);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
newton_node::newton_node(void)
 : _output(*this)
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
base_output&
newton_node::single_output(void)
{
	return _output;
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------

