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

#include <iosfwd>
#include "interface.hpp"

namespace oglplus {
namespace texgen {
namespace expr {

struct render_param_decl {
    output_intf& output;
};
std::ostream& operator<<(std::ostream& out, render_param_decl);

struct render_param_pass {
    output_intf& output;
};
std::ostream& operator<<(std::ostream& out, render_param_pass);

struct render_param_pass_voxel_offs {
    output_intf& output;
    float offs[3];
};
std::ostream& operator<<(std::ostream& out, render_param_pass_voxel_offs);

struct normalized_coord {
    output_intf& output;
};
std::ostream& operator<<(std::ostream& out, normalized_coord);

struct voxel_offset {
    output_intf& output;
};
std::ostream& operator<<(std::ostream& out, voxel_offset);

struct norm_voxel_size {
    output_intf& output;
};
std::ostream& operator<<(std::ostream& out, norm_voxel_size);

struct norm_voxel_offs {
    output_intf& output;
};
std::ostream& operator<<(std::ostream& out, norm_voxel_offs);

struct norm_sample_coord {
    output_intf& output;
};
std::ostream& operator<<(std::ostream& out, norm_sample_coord);

struct nhood2d_offs {};
std::ostream& operator<<(std::ostream& out, nhood2d_offs);

struct nhood2d_offs_decl {
    compile_context& context;
};
std::ostream& operator<<(std::ostream& out, nhood2d_offs_decl);

struct nbors2d_offs {};
std::ostream& operator<<(std::ostream& out, nbors2d_offs);

struct nbors2d_offs_decl {
    compile_context& context;
};
std::ostream& operator<<(std::ostream& out, nbors2d_offs_decl);

} // namespace expr
} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/param_format.inl>
#endif

#endif // include guard
