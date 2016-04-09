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
namespace expr {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& operator << (std::ostream& out, render_param_decl)
{
	return out << "(vec3 oglptg_nc, vec3 oglptg_vs, vec3 oglptg_vo)";
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& operator << (std::ostream& out, render_param_pass e)
{
	if(e.output.needs_params())
	{
		out << "(oglptg_nc, oglptg_vs, oglptg_vo)";
	}
	return out;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& operator << (std::ostream& out, render_param_pass_voxel_offs e)
{
	if(e.output.needs_params())
	{
		out << "(oglptg_nc, oglptg_vs, oglptg_vo+vec3(";
		out << e.offs[0] << ", ";
		out << e.offs[1] << ", ";
		out << e.offs[2] << "))";
	}
	return out;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& operator << (std::ostream& out, normalized_coord)
{
	return out << "oglptg_nc";
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& operator << (std::ostream& out, voxel_offset)
{
	return out << "oglptg_vo";
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& operator << (std::ostream& out, norm_voxel_size)
{
	return out << "oglptg_vs";
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& operator << (std::ostream& out, norm_voxel_offs x)
{
	return out
		<< voxel_offset{x.output}
		<< "*"
		<< norm_voxel_size{x.output};
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& operator << (std::ostream& out, norm_sample_coord x)
{
	return out
		<< normalized_coord{x.output}
		<< "+"
		<< norm_voxel_offs{x.output};
}
//------------------------------------------------------------------------------
} // namespace expr
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------

