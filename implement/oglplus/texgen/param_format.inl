/**
 *  @file oglplus/texgen/param_format.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <iostream>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& operator << (std::ostream& out, render_param_decl_expr)
{
	return out << "(vec3 oglptg_nc)";
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& operator << (std::ostream& out, render_param_pass_expr e)
{
	if(e.output.needs_params())
	{
		out << "(oglptg_nc)";
	}
	return out;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& operator << (std::ostream& out, render_param_normalized_coords)
{
	return out << "oglptg_nc";
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------

