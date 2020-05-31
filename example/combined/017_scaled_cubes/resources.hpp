/**
 *  example combined/017_scaled_cubes/resources.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>

#include <oglplus/shapes/drawing.hpp>

namespace eagine {
class example_context;
namespace oglp {
class example_orbiting_camera;
//------------------------------------------------------------------------------
// program
//------------------------------------------------------------------------------
class cubes_program {
private:
    owned_program_name prog;
    uniform_location camera_loc;
    uniform_location center_loc;
    uniform_location time_loc;

public:
    void init(example_context& ctx);
    void set_projection(
      const example_context& ctx, const example_orbiting_camera& camera);
    void update(const example_context& ctx);

    void bind_position_location(
      const example_context& ctx, vertex_attrib_location loc);
    void bind_pivot_location(
      const example_context& ctx, vertex_attrib_location loc);
    void bind_coord_location(
      const example_context& ctx, vertex_attrib_location loc);
};
//------------------------------------------------------------------------------
// geometry
//------------------------------------------------------------------------------
class cubes_geometry {
private:
    owned_vertex_array_name vao;

    owned_buffer_name positions;
    owned_buffer_name pivots;
    owned_buffer_name coords;
    owned_buffer_name indices;

    std::vector<shape_draw_operation> ops;

public:
    void init(example_context& ctx);
    void draw(const example_context& ctx);

    static auto position_loc() noexcept {
        return vertex_attrib_location{0};
    }

    static auto pivot_loc() noexcept {
        return vertex_attrib_location{1};
    }

    static auto coord_loc() noexcept {
        return vertex_attrib_location{2};
    }
};
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine
