/**
 *  example combined/025_recursive_cube/example.cpp
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
class example_cubes : public example {
    cube_program prog;
    cube_geometry cube;
    cube_draw_buffers bufs;

public:
    auto check_requirements(const example_context& ctx) -> bool final;
    void init(example_context& ctx) final;
    void render(const example_context& ctx) final;
    auto default_timeout() -> seconds_t<float> final;
};
//------------------------------------------------------------------------------
// example_cubes
//------------------------------------------------------------------------------
auto example_cubes ::check_requirements(const example_context& ctx) -> bool {
    const auto& [gl, GL] = ctx.gl();
    auto r = ctx.req_mark();

    return r(gl.disable) && r(gl.clear_color) && r(gl.create_shader) &&
           r(gl.shader_source) && r(gl.compile_shader) &&
           r(gl.create_program) && r(gl.attach_shader) && r(gl.link_program) &&
           r(gl.buffer_data) && r(gl.gen_vertex_arrays) && r(gl.gen_textures) &&
           r(gl.gen_framebuffers) && r(gl.gen_renderbuffers) &&
           r(gl.bind_vertex_array) && r(gl.get_attrib_location) &&
           r(gl.vertex_attrib_pointer) && r(gl.enable_vertex_attrib_array) &&
           r(gl.draw_arrays) && r(GL.vertex_shader) && r(GL.fragment_shader);
}
//------------------------------------------------------------------------------
void example_cubes::init(example_context& ctx) {
    const auto& [gl, GL] = ctx.gl();

    prog.init(ctx);
    cube.init(ctx);
    bufs.init(ctx);

    prog.bind_position_location(ctx, cube.position_loc());
    prog.bind_normal_location(ctx, cube.normal_loc());
    prog.bind_tex_coord_location(ctx, cube.tex_coord_loc());

    gl.clear_color(0.8F, 0.8F, 0.8F, 0.0F);

    gl.enable(GL.depth_test);
}
//------------------------------------------------------------------------------
void example_cubes::render(const example_context& ctx) {
    auto& state = ctx.state();
    const auto& [gl, GL] = ctx.gl();

    prog.update(ctx);
    prog.set_texture(ctx, bufs.front_tex_unit());

    // draw into texture
    gl.bind_framebuffer(GL.draw_framebuffer, bufs.back_fbo());
    gl.viewport(bufs.side(), bufs.side());

    prog.set_projection(
      ctx,
      matrix_perspective(-0.5F, 0.5F, -0.5F, 0.5F, 1.0F, 5) *
        matrix_translation(0, 0, -2));

    gl.clear(GL.color_buffer_bit | GL.depth_buffer_bit);
    cube.draw(ctx);

    // draw on screen
    gl.bind_framebuffer(GL.draw_framebuffer, framebuffer_name(0));
    gl.viewport(state.width(), state.height());

    float h = 0.55F;
    float w = h * state.aspect();
    prog.set_projection(
      ctx,
      matrix_perspective(-w, +w, -h, +h, 1, 3) * matrix_translation(0, 0, -2));

    gl.clear(GL.color_buffer_bit | GL.depth_buffer_bit);
    cube.draw(ctx);
    // swap texture draw buffers
    bufs.swap();
}
//------------------------------------------------------------------------------
auto example_cubes::default_timeout() -> seconds_t<float> {
    return seconds_(30);
}
//------------------------------------------------------------------------------
} // namespace oglp
//------------------------------------------------------------------------------
auto make_example(const example_args&, const example_context&)
  -> std::unique_ptr<example> {
    return {std::make_unique<oglp::example_cubes>()};
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
