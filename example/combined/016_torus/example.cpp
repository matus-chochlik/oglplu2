/**
 *  example combined/016_torus/example.cpp
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
class example_torus : public example {
    example_orbiting_camera camera;
    torus_program prog;
    torus_geometry torus;

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
// example_torus
//------------------------------------------------------------------------------
bool example_torus ::check_requirements(const example_context& ctx) {
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
void example_torus::init(example_context& ctx) {
    const auto& [gl, GL] = ctx.gl();

    prog.init(ctx);
    torus.init(ctx);

    prog.bind_position_location(ctx, torus.position_loc());
    prog.bind_normal_location(ctx, torus.normal_loc());
    prog.bind_texcoord_location(ctx, torus.texcoord_loc());

    camera.set_near(0.1F)
      .set_far(50.F)
      .set_orbit_min(1.1F)
      .set_orbit_max(3.5F)
      .set_fov(right_angle_());
    prog.set_projection(ctx, camera);

    gl.clear_color(0.4F, 0.4F, 0.4F, 0.0F);

    gl.enable(GL.depth_test);
}
//------------------------------------------------------------------------------
void example_torus::pointer_motion(const example_context& ctx) {
    const auto& state = ctx.state();
    if(camera.apply_pointer_motion(state)) {
        prog.set_projection(ctx, camera);
    }
}
//------------------------------------------------------------------------------
void example_torus::pointer_scrolling(const example_context& ctx) {
    const auto& state = ctx.state();
    if(camera.apply_pointer_scrolling(state)) {
        prog.set_projection(ctx, camera);
    }
}
//------------------------------------------------------------------------------
void example_torus::user_idle(const example_context& ctx) {
    const auto& state = ctx.state();
    if(state.user_idle_time() > seconds_(1)) {
        camera.idle_update(state, 2);
        prog.set_projection(ctx, camera);
    }
}
//------------------------------------------------------------------------------
void example_torus::resize(const example_context& ctx) {
    const auto& state = ctx.state();
    const auto& [gl, GL] = ctx.gl();
    EAGINE_MAYBE_UNUSED(GL);

    gl.viewport(state.width(), state.height());
    prog.set_projection(ctx, camera);
}
//------------------------------------------------------------------------------
void example_torus::render(const example_context& ctx) {
    const auto& [gl, GL] = ctx.gl();

    gl.clear(GL.color_buffer_bit | GL.depth_buffer_bit);
    torus.draw(ctx);
}
//------------------------------------------------------------------------------
seconds_t<float> example_torus::default_timeout() {
    return seconds_(30);
}
//------------------------------------------------------------------------------
} // namespace oglp
//------------------------------------------------------------------------------
std::unique_ptr<example>
make_example(const example_args&, const example_context&) {
    return {std::make_unique<oglp::example_torus>()};
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
