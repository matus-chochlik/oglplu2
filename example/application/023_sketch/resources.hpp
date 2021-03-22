/// @example application/023_sketch/resources.hpp
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
#include <oglplus/shapes/drawing.hpp>
#include <oglplus/shapes/generator.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
// program
//------------------------------------------------------------------------------
class sketch_program {
public:
    void init(execution_context&, video_context&);
    void clean_up(video_context&);
    void prepare_frame(video_context&, orbiting_camera& camera, float t);

    void bind_position_location(video_context&, oglp::vertex_attrib_location);
    void bind_normal_location(video_context&, oglp::vertex_attrib_location);
    void bind_coord_location(video_context&, oglp::vertex_attrib_location);

private:
    oglp::owned_program_name _prog;
    oglp::uniform_location _model_loc;
    oglp::uniform_location _view_loc;
    oglp::uniform_location _projection_loc;
    oglp::uniform_location _vp_dim_loc;
};
//------------------------------------------------------------------------------
// geometry
//------------------------------------------------------------------------------
class shape_geometry {
public:
    void init(execution_context&, video_context&);
    void clean_up(video_context&);
    void draw(execution_context&, video_context&);

    static auto position_loc() noexcept {
        return oglp::vertex_attrib_location{0};
    }

    static auto normal_loc() noexcept {
        return oglp::vertex_attrib_location{1};
    }

    static auto coord_loc() noexcept {
        return oglp::vertex_attrib_location{2};
    }

private:
    oglp::owned_vertex_array_name _vao;

    oglp::owned_buffer_name _positions;
    oglp::owned_buffer_name _normals;
    oglp::owned_buffer_name _coords;
    oglp::owned_buffer_name _indices;

    std::vector<oglp::shape_draw_operation> _ops;
};
//------------------------------------------------------------------------------
// texture
//------------------------------------------------------------------------------
class sketch_texture {
public:
    void init(execution_context&, video_context&);
    void clean_up(execution_context&, video_context&);

private:
    oglp::owned_texture_name _tex;
};
//------------------------------------------------------------------------------
} // namespace eagine::application

#endif
