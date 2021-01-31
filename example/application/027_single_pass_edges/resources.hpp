/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_EXAMPLE_RESOURCES_HPP // NOLINT(llvm-header-guard)
#define OGLPLUS_EXAMPLE_RESOURCES_HPP

#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>

#include <eagine/application/fwd.hpp>
#include <oglplus/shapes/drawing.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
// program
//------------------------------------------------------------------------------
class edges_program {
private:
    oglp::owned_program_name prog;
    oglp::uniform_location camera_loc;
    oglp::uniform_location vp_dim_loc;

public:
    void init(execution_context&, video_context&);
    void cleanup(video_context&);
    void set_projection(video_context&, orbiting_camera&);

    void bind_position_location(video_context&, oglp::vertex_attrib_location);
};
//------------------------------------------------------------------------------
// geometry
//------------------------------------------------------------------------------
class icosahedron_geometry {
private:
    oglp::owned_vertex_array_name vao;

    oglp::owned_buffer_name positions;
    oglp::owned_buffer_name indices;

    std::vector<oglp::shape_draw_operation> ops;

public:
    void init(execution_context&, video_context&);
    void cleanup(video_context&);
    void draw(video_context&);

    static auto position_loc() noexcept {
        return oglp::vertex_attrib_location{0};
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::application

#endif
