/**
 *  example combined/000_translucent_arrow/example.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>

#include <oglplus/math/matrix.hpp>
#include <oglplus/math/vector.hpp>

#include "resources.hpp"
//
#include "../example.hpp"
#include "../example/camera.hpp"

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
class example_arrow : public example {
    example_orbiting_camera camera;

    draw_program draw_prog;
    arrow_geometry arrow;

public:
    auto check_requirements(const example_context& ctx) -> bool final;
    void init(example_context& ctx) final;
    void pointer_motion(const example_context& ctx) final;
    void pointer_scrolling(const example_context& ctx) final;
    void user_idle(const example_context& ctx) final;
    void resize(const example_context& ctx) final;
    void render(const example_context& ctx) final;
};
//------------------------------------------------------------------------------
// example_arrow
//------------------------------------------------------------------------------
auto example_arrow::check_requirements(const example_context& ctx) -> bool {
    const auto& [gl, GL] = ctx.gl();
    auto r = ctx.req_mark();

    return r(gl.disable) && r(gl.clear_color) && r(gl.create_shader) &&
           r(gl.shader_source) && r(gl.compile_shader) &&
           r(gl.create_program) && r(gl.attach_shader) && r(gl.link_program) &&
           r(gl.use_program) && r(gl.gen_buffers) && r(gl.bind_buffer) &&
           r(gl.buffer_data) && r(gl.gen_vertex_arrays) &&
           r(gl.bind_vertex_array) && r(gl.get_attrib_location) &&
           r(gl.vertex_attrib_pointer) && r(gl.enable_vertex_attrib_array) &&
           r(gl.draw_arrays) && r(GL.vertex_shader) && r(GL.fragment_shader);
}
//------------------------------------------------------------------------------
void example_arrow::init(example_context& ctx) {
    const auto& gl = ctx.gl();

    draw_prog.init(ctx);
    arrow.init(ctx);

    draw_prog.bind_position_location(ctx, arrow.position_loc());
    draw_prog.bind_normal_location(ctx, arrow.normal_loc());

    // camera
    const auto sr = arrow.bounding_sphere().radius();
    camera.set_near(sr * 0.1F)
      .set_far(sr * 5.0F)
      .set_orbit_min(sr * 1.2F)
      .set_orbit_max(sr * 2.4F)
      .set_fov(right_angle_());
    draw_prog.set_projection(ctx, camera);

    gl.clear_color(0.45F, 0.45F, 0.45F, 0.0F);
}
//------------------------------------------------------------------------------
void example_arrow::pointer_motion(const example_context& ctx) {
    const auto& state = ctx.state();
    if(camera.apply_pointer_motion(state)) {
        draw_prog.set_projection(ctx, camera);
    }
}
//------------------------------------------------------------------------------
void example_arrow::pointer_scrolling(const example_context& ctx) {
    const auto& state = ctx.state();
    if(camera.apply_pointer_scrolling(state)) {
        draw_prog.set_projection(ctx, camera);
    }
}
//------------------------------------------------------------------------------
void example_arrow::user_idle(const example_context& ctx) {
    const auto& state = ctx.state();
    if(state.user_idle_time() > seconds_(1)) {
        camera.idle_update(state, 2);
        draw_prog.set_projection(ctx, camera);
    }
}
//------------------------------------------------------------------------------
void example_arrow::resize(const example_context& ctx) {
    const auto& state = ctx.state();
    const auto& gl = ctx.gl();

    gl.viewport(state.width(), state.height());
    draw_prog.set_projection(ctx, camera);
}
//------------------------------------------------------------------------------
void example_arrow::render(const example_context& ctx) {
    const auto& [gl, GL] = ctx.gl();

    gl.clear(GL.color_buffer_bit | GL.depth_buffer_bit);
    arrow.draw(ctx);
}
//------------------------------------------------------------------------------
} // namespace oglp
//------------------------------------------------------------------------------
auto make_example(const example_args&, const example_context&)
  -> std::unique_ptr<example> {
    return {std::make_unique<oglp::example_arrow>()};
}
//------------------------------------------------------------------------------
void adjust_params(example_params& params) {
    params.stencil_buffer(false);
}
//------------------------------------------------------------------------------
auto is_example_param(const example_arg&) -> bool {
    return false;
}
//------------------------------------------------------------------------------
} // namespace eagine
