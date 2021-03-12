/// @example application/020_bezier_patch/resources.hpp
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
// program
//------------------------------------------------------------------------------
class patch_program {
public:
    void init(execution_context&, video_context&);
    void clean_up(video_context&);
    void set_projection(video_context&, orbiting_camera&);
    void set_wireframe_color(video_context&);
    void set_surface_color(video_context&);

    void bind_position_location(video_context&, oglp::vertex_attrib_location);

private:
    oglp::owned_program_name prog;
    oglp::uniform_location camera_matrix_loc;
    oglp::uniform_location perspective_matrix_loc;
    oglp::uniform_location color_loc;
};
//------------------------------------------------------------------------------
// geometry
//------------------------------------------------------------------------------
class patch_geometry {
public:
    void init(execution_context&, video_context&);
    void clean_up(video_context&);
    void draw(video_context&);

    static auto position_loc() noexcept {
        return oglp::vertex_attrib_location{0};
    }

private:
    oglp::owned_vertex_array_name _vao;

    oglp::owned_buffer_name _positions;
};
//------------------------------------------------------------------------------
} // namespace eagine::application

#endif
