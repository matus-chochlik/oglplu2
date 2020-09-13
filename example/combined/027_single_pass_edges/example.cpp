/**
 *  example combined/027_single_pass_edges/example.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "resources.hpp"
//
#include "../example.hpp"
#include "../example/camera.hpp"

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
// example
//------------------------------------------------------------------------------
class example_edges : public example {
    example_orbiting_camera camera;
    edges_program prog;
    icosahedron_geometry shape;

public:
    bool check_requirements(const example_context& ctx) final;
    void init(example_context& ctx) final;
    void pointer_motion(const example_context& ctx) final;
    void pointer_scrolling(const example_context& ctx) final;
    void user_idle(const example_context& ctx) final;
    void resize(const example_context& ctx) final;
    void render(const example_context& ctx) final;
    seconds_t<float> default_timeout() final;
};
//------------------------------------------------------------------------------
// example_edges
//------------------------------------------------------------------------------
bool example_edges ::check_requirements(const example_context& ctx) {
    const auto& [gl, GL] = ctx.gl();
    auto r = ctx.req_mark();

    return r(gl.disable) && r(gl.clear_color) && r(gl.create_shader) &&
           r(gl.shader_source) && r(gl.compile_shader) &&
           r(gl.create_program) && r(gl.attach_shader) && r(gl.link_program) &&
           r(gl.buffer_data) && r(gl.gen_vertex_arrays) &&
           r(gl.bind_vertex_array) && r(gl.get_attrib_location) &&
           r(gl.vertex_attrib_pointer) && r(gl.enable_vertex_attrib_array) &&
           r(gl.draw_arrays) && r(GL.vertex_shader) && r(GL.fragment_shader);
}
//------------------------------------------------------------------------------
void example_edges::init(example_context& ctx) {
    const auto& [gl, GL] = ctx.gl();

    prog.init(ctx);
    shape.init(ctx);

    prog.bind_position_location(ctx, shape.position_loc());

    camera.set_near(0.1F)
      .set_far(50.F)
      .set_orbit_min(2.6F)
      .set_orbit_max(9.0F)
      .set_fov(right_angle_());
    prog.set_projection(ctx, camera);

    gl.clear_color(0.4F, 0.4F, 0.4F, 0.0F);

    gl.enable(GL.depth_test);
    gl.enable(GL.cull_face);
    gl.cull_face(GL.back);
}
//------------------------------------------------------------------------------
void example_edges::pointer_motion(const example_context& ctx) {
    const auto& state = ctx.state();
    if(camera.apply_pointer_motion(state)) {
        prog.set_projection(ctx, camera);
    }
}
//------------------------------------------------------------------------------
void example_edges::pointer_scrolling(const example_context& ctx) {
    const auto& state = ctx.state();
    if(camera.apply_pointer_scrolling(state)) {
        prog.set_projection(ctx, camera);
    }
}
//------------------------------------------------------------------------------
void example_edges::user_idle(const example_context& ctx) {
    const auto& state = ctx.state();
    if(state.user_idle_time() > seconds_(1)) {
        camera.idle_update(state, 2);
        prog.set_projection(ctx, camera);
    }
}
//------------------------------------------------------------------------------
void example_edges::resize(const example_context& ctx) {
    const auto& state = ctx.state();
    const auto& [gl, GL] = ctx.gl();
    EAGINE_MAYBE_UNUSED(GL);

    gl.viewport(state.width(), state.height());
    prog.set_projection(ctx, camera);
}
//------------------------------------------------------------------------------
void example_edges::render(const example_context& ctx) {
    const auto& [gl, GL] = ctx.gl();

    gl.clear(GL.color_buffer_bit | GL.depth_buffer_bit);
    shape.draw(ctx);
}
//------------------------------------------------------------------------------
seconds_t<float> example_edges::default_timeout() {
    return seconds_(30);
}
//------------------------------------------------------------------------------
} // namespace oglp
//------------------------------------------------------------------------------
std::unique_ptr<example>
make_example(const example_args&, const example_context&) {
    return {std::make_unique<oglp::example_edges>()};
}
//------------------------------------------------------------------------------
void adjust_params(example_params& params) {
    params.stencil_buffer(false);
}
//------------------------------------------------------------------------------
bool is_example_param(const example_arg&) {
    return false;
}
//------------------------------------------------------------------------------
} // namespace eagine
