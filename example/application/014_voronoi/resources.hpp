/// @example application/014_voronoi/resources.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef OGLPLUS_EXAMPLE_RESOURCES_HPP // NOLINT(llvm-header-guard)
#define OGLPLUS_EXAMPLE_RESOURCES_HPP

#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>

#include <eagine/application/fwd.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
// random texture
//------------------------------------------------------------------------------
class random_texture {
public:
    void init(execution_context&, video_context&);
    void clean_up(execution_context&, video_context&);

private:
    oglp::owned_texture_name random;
};
//------------------------------------------------------------------------------
// voronoi program
//------------------------------------------------------------------------------
class voronoi_program {
public:
    oglp::owned_program_name prog;
    oglp::uniform_location offset_loc;
    oglp::uniform_location scale_loc;

    void init(execution_context&, video_context&);
    void clean_up(execution_context&, video_context&);

private:
    oglp::owned_shader_name vs;
    oglp::owned_shader_name fs;
};
//------------------------------------------------------------------------------
// screen geometry
//------------------------------------------------------------------------------
class screen_geometry {
public:
    oglp::vertex_attrib_location position_loc{0};
    oglp::vertex_attrib_location tex_coord_loc{1};

    void init(execution_context&, video_context&);
    void clean_up(execution_context&, video_context&);

private:
    oglp::owned_vertex_array_name vao;

    oglp::owned_buffer_name positions;
    oglp::owned_buffer_name tex_coords;
};
//------------------------------------------------------------------------------
} // namespace eagine::application

#endif
