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
#include <array>

namespace eagine::application {
//------------------------------------------------------------------------------
// program
//------------------------------------------------------------------------------
class cubes_program {
private:
    oglp::owned_program_name prog;
    oglp::uniform_location camera_loc;
    oglp::uniform_location center_loc;
    oglp::uniform_location time_loc;
    oglp::uniform_location edges_loc;

public:
    void init(execution_context&, video_context&);
    void clean_up(video_context&);
    void set_projection(video_context&, orbiting_camera& camera);
    void update(execution_context&, video_context&);

    void bind_position_location(video_context&, oglp::vertex_attrib_location);
    void bind_pivot_location(video_context&, oglp::vertex_attrib_location);
    void bind_coord_location(video_context&, oglp::vertex_attrib_location);

    void drawing_surface(video_context&);
    void drawing_edges(video_context&);
};
//------------------------------------------------------------------------------
// geometry
//------------------------------------------------------------------------------
class cubes_geometry {
private:
    oglp::owned_vertex_array_name vao;

    oglp::owned_buffer_name positions;
    oglp::owned_buffer_name pivots;
    oglp::owned_buffer_name coords;
    oglp::owned_buffer_name indices;

    std::vector<oglp::shape_draw_operation> ops{};
    std::array<oglp::shape_draw_subset, 2> subs{};

public:
    void init(execution_context&, video_context&);
    void clean_up(video_context&);
    void draw_surface(video_context&);
    void draw_edges(video_context&);

    static auto position_loc() noexcept {
        return oglp::vertex_attrib_location{0};
    }

    static auto pivot_loc() noexcept {
        return oglp::vertex_attrib_location{1};
    }

    static auto coord_loc() noexcept {
        return oglp::vertex_attrib_location{2};
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::application

#endif
