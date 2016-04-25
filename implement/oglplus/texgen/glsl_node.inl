/**
 *  @file oglplus/texgen/glsl_node.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <iostream>
#include <eagine/str_var_subst.hpp>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
glsl_output::
glsl_output(node_intf& parent, const std::string& glsl, slot_data_type type)
 : multi_input_output(parent)
 , _glsl(glsl)
 , _type(type)
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
glsl_output::type_name(void)
{
	return cstr_ref("GLSL");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type
glsl_output::value_type(void)
{
	return _type;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
glsl_output::definitions(std::ostream& out, compile_context& ctxt)
{
	if(already_defined(ctxt)) return out;

	input_defs(out, ctxt);
	opening_expr(out, ctxt);

	std::map<std::string, std::string> dict;

	dict["NORMALIZED_COORDS"] = "oglptg_nc";
	dict["NC"] = "oglptg_nc";
	dict["VOXEL_SIZE"] = "oglptg_vs";
	dict["VS"] = "oglptg_vs";
	dict["VOXEL_OFFSET"] = "oglptg_vo";
	dict["VO"] = "oglptg_vo";

	for(auto i = _inputs.begin(); i != _inputs.end(); ++i)
	{
		input_with_const_default<float[4]>& input = i->second;

		out << "\t" << data_type_name(input.value_type());
		out << " oglptgi_" << i->first << " = ";
		out << expr::output_id{input.output(), ctxt};
		out << expr::render_param_pass{input.output()};
		out << ";" << std::endl;

		dict[i->first] = std::string("oglptgi_") + i->first;
	}

	out << "\treturn ";
	out << eagine::substitute_variables(_glsl, dict);
	out << ";" << std::endl;

	return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
glsl_node::glsl_node(void)
 : _output(*this)
{ }
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------

