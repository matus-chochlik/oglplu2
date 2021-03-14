/// @example application/022_halo/resources.hpp
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
class surface_program {
public:
    void init(execution_context&, video_context&);
    void clean_up(video_context&);
    void prepare_frame(video_context&, orbiting_camera& camera);

    void bind_position_location(video_context&, oglp::vertex_attrib_location);
    void bind_normal_location(video_context&, oglp::vertex_attrib_location);

private:
    oglp::owned_program_name _prog;
    oglp::uniform_location _view_loc;
    oglp::uniform_location _projection_loc;
};
//------------------------------------------------------------------------------
class halo_program {
public:
    void init(execution_context&, video_context&);
    void clean_up(video_context&);
    void prepare_frame(video_context&, orbiting_camera& camera);

    void bind_position_location(video_context&, oglp::vertex_attrib_location);
    void bind_normal_location(video_context&, oglp::vertex_attrib_location);

private:
    oglp::owned_program_name _prog;
    oglp::uniform_location _view_loc;
    oglp::uniform_location _projection_loc;
};
//------------------------------------------------------------------------------
// geometry
//------------------------------------------------------------------------------
class shape_geometry {
public:
    shape_geometry(std::shared_ptr<shapes::generator> gen)
      : _gen{std::move(gen)} {}

    void init(execution_context&, video_context&);
    void clean_up(video_context&);
    void draw(execution_context&, video_context&);

    static auto position_loc() noexcept {
        return oglp::vertex_attrib_location{0};
    }

    static auto normal_loc() noexcept {
        return oglp::vertex_attrib_location{1};
    }

private:
    std::shared_ptr<shapes::generator> _gen;
    oglp::owned_vertex_array_name _vao;

    oglp::owned_buffer_name _positions;
    oglp::owned_buffer_name _normals;
    oglp::owned_buffer_name _indices;

    std::vector<oglp::shape_draw_operation> _ops;
};
//------------------------------------------------------------------------------
} // namespace eagine::application

#endif
