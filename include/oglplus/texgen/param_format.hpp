/**
 *  @file oglplus/texgen/param_format.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_PARAM_FORMAT_1509260923_HPP
#define OGLPLUS_TEXGEN_PARAM_FORMAT_1509260923_HPP

#include "interface.hpp"
#include <iosfwd>

namespace oglplus {
namespace texgen {

struct render_param_decl_expr { output_intf& output; };
std::ostream& operator << (std::ostream& out, render_param_decl_expr);

struct render_param_pass_expr { output_intf& output; };
std::ostream& operator << (std::ostream& out, render_param_pass_expr);

struct render_param_normalized_coord { output_intf& output; };
std::ostream& operator << (std::ostream& out, render_param_normalized_coord);

struct render_param_voxel_offset { output_intf& output; };
std::ostream& operator << (std::ostream& out, render_param_voxel_offset);

struct render_param_norm_voxel_size { output_intf& output; };
std::ostream& operator << (std::ostream& out, render_param_norm_voxel_size);

struct render_param_norm_voxel_offs { output_intf& output; };
std::ostream& operator << (std::ostream& out, render_param_norm_voxel_offs);

struct render_param_norm_sample_coord { output_intf& output; };
std::ostream& operator << (std::ostream& out, render_param_norm_sample_coord);

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/param_format.inl>
#endif

#endif // include guard
