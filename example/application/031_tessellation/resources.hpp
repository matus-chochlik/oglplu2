/// @file
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

namespace eagine::application {
//------------------------------------------------------------------------------
// program
//------------------------------------------------------------------------------
class sphere_program {
private:
    oglp::owned_program_name prog;
    oglp::uniform_location camera_matrix_loc;
    oglp::uniform_location camera_position_loc;
    oglp::uniform_location viewport_dim_loc;
    oglp::uniform_block_index offset_blk_idx{0U};

public:
    void init(execution_context&, video_context&);
    void clean_up(video_context&);
    void set_projection(video_context&, orbiting_camera&);

    void bind_position_location(video_context&, oglp::vertex_attrib_location);
    void bind_offsets_block(video_context&, oglp::gl_types::uint_type);
};
//------------------------------------------------------------------------------
// geometry
//------------------------------------------------------------------------------
class icosahedron_geometry {
private:
    const int count = 4;

    oglp::owned_vertex_array_name vao;

    oglp::owned_buffer_name positions;
    oglp::owned_buffer_name indices;
    oglp::owned_buffer_name offsets;

    std::vector<oglp::shape_draw_operation> ops;

public:
    void init(execution_context&, video_context&);
    void clean_up(video_context&);
    void draw(video_context&);

    static auto position_loc() noexcept {
        return oglp::vertex_attrib_location{0};
    }

    static auto offsets_binding() noexcept {
        return 0U;
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::application

#endif
