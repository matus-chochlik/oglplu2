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
std::ostream&
operator<<(std::ostream& out, render_param_decl) {
    return out << "(vec3 oglptg_nc, vec3 oglptg_vs, vec3 oglptg_vo)";
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
operator<<(std::ostream& out, render_param_pass e) {
    if(e.output.needs_params()) {
	out << "(oglptg_nc, oglptg_vs, oglptg_vo)";
    }
    return out;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
operator<<(std::ostream& out, render_param_pass_voxel_offs e) {
    if(e.output.needs_params()) {
	out << "(oglptg_nc, oglptg_vs, oglptg_vo+vec3(";
	out << e.offs[0] << ", ";
	out << e.offs[1] << ", ";
	out << e.offs[2] << "))";
    }
    return out;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
operator<<(std::ostream& out, normalized_coord) {
    return out << "oglptg_nc";
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
operator<<(std::ostream& out, voxel_offset) {
    return out << "oglptg_vo";
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
operator<<(std::ostream& out, norm_voxel_size) {
    return out << "oglptg_vs";
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
operator<<(std::ostream& out, norm_voxel_offs x) {
    return out << voxel_offset{x.output} << "*" << norm_voxel_size{x.output};
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
operator<<(std::ostream& out, norm_sample_coord x) {
    return out << normalized_coord{x.output} << "+"
	       << norm_voxel_offs{x.output};
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
operator<<(std::ostream& out, nbors2d_offs) {
    return out << "oglptgNbors2dCellOffs";
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
operator<<(std::ostream& out, nbors2d_offs_decl e) {
    cstr_ref tag("nbors2d_cells");
    if(!e.context.has_tag(tag)) {
	out << "vec2 " << nbors2d_offs{} << "[8] = vec2[8](" << std::endl;
	out << "\tvec2(-1,-1)," << std::endl;
	out << "\tvec2(-1, 0)," << std::endl;
	out << "\tvec2(-1, 1)," << std::endl;
	out << "\tvec2( 0,-1)," << std::endl;
	out << "\tvec2( 0, 1)," << std::endl;
	out << "\tvec2( 1,-1)," << std::endl;
	out << "\tvec2( 1, 0)," << std::endl;
	out << "\tvec2( 1, 1)" << std::endl;
	out << ");" << std::endl;
	out << std::endl;
	e.context.add_tag(tag);
    }
    return out;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
operator<<(std::ostream& out, nhood2d_offs) {
    return out << "oglptgNhood2dCellOffs";
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
operator<<(std::ostream& out, nhood2d_offs_decl e) {
    cstr_ref tag("nhood2d_cells");
    if(!e.context.has_tag(tag)) {
	out << "vec2 " << nhood2d_offs{} << "[9] = vec2[9](" << std::endl;
	out << "\tvec2(-1,-1)," << std::endl;
	out << "\tvec2(-1, 0)," << std::endl;
	out << "\tvec2(-1, 1)," << std::endl;
	out << "\tvec2( 0,-1)," << std::endl;
	out << "\tvec2( 0, 0)," << std::endl;
	out << "\tvec2( 0, 1)," << std::endl;
	out << "\tvec2( 1,-1)," << std::endl;
	out << "\tvec2( 1, 0)," << std::endl;
	out << "\tvec2( 1, 1)" << std::endl;
	out << ");" << std::endl;
	out << std::endl;
	e.context.add_tag(tag);
    }
    return out;
}
//------------------------------------------------------------------------------
} // namespace expr
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------
