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
	return out << "(vec3 oglptg_nc, vec3 oglptg_vo)";
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& operator << (std::ostream& out, render_param_pass_expr e)
{
	if(e.output.needs_params())
	{
		out << "(oglptg_nc, oglptg_vo)";
	}
	return out;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& operator << (std::ostream& out, render_param_normalized_coord)
{
	return out << "oglptg_nc";
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& operator << (std::ostream& out, render_param_voxel_offset)
{
	return out << "oglptg_vo";
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& operator << (std::ostream& out, render_param_norm_voxel_size)
{
	return out << "oglptg_vs";
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& operator << (std::ostream& out, render_param_norm_voxel_offs x)
{
	return out
		<< render_param_voxel_offset{x.output}
		<< "*"
		<< render_param_norm_voxel_size{x.output};
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& operator << (std::ostream& out, render_param_norm_sample_coord x)
{
	return out
		<< render_param_normalized_coord{x.output}
		<< "+"
		<< render_param_norm_voxel_offs{x.output};
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------

