/**
 *  example combined/011_newton/example.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>

#include <oglplus/glsl/string_ref.hpp>

#include "../example.hpp"

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
class example_newton : public example {
private:
    owned_vertex_array_name vao;

    owned_buffer_name positions;
    owned_buffer_name coords;

    owned_shader_name vs;
    owned_shader_name fs;

    owned_program_name prog;

    uniform_location offset_loc;
    uniform_location scale_loc;

    owned_texture_name gradient;

    float offset_x{-0.5F};
    float offset_y{0.0F};
    float scale{1.0F};
    float aspect{1.0F};

    static constexpr const float min_scale{0.00001F};
    static constexpr const float max_scale{10.0F};

public:
    bool check_requirements(const example_context& ctx) final;
    void init(example_context& ctx) final;
    void pointer_motion(const example_context& ctx) final;
    void pointer_scrolling(const example_context& ctx) final;
    void resize(const example_context& ctx) final;
    void user_idle(const example_context& ctx) final;
    void render(const example_context&) final;
    seconds_t<float> default_timeout() final;
};
//------------------------------------------------------------------------------
// example_newton
//------------------------------------------------------------------------------
bool example_newton::check_requirements(const example_context& ctx) {
    const auto& [gl, GL] = ctx.gl();
    auto r = ctx.req_mark();
    // TODO
    return r(gl.disable) && r(gl.clear_color) && r(gl.create_shader) &&
           r(GL.vertex_shader) && r(GL.fragment_shader);
}
//------------------------------------------------------------------------------
void example_newton::init(example_context& ctx) {
    auto& cleanup = ctx.cleanup();
    const auto& [gl, GL] = ctx.gl();

    // vertex shader
    auto vs_src = embed(EAGINE_ID(VertShader), "vertex.glsl");
    gl.create_shader(GL.vertex_shader) >> vs;
    gl.delete_shader.later_by(cleanup, vs);
    gl.shader_source(vs, glsl_string_ref(vs_src));
    gl.compile_shader(vs);

    // fragment shader
    auto fs_src = embed(EAGINE_ID(FragShader), "fragment.glsl");
    gl.create_shader(GL.fragment_shader) >> fs;
    gl.delete_shader.later_by(cleanup, fs);
    gl.shader_source(fs, glsl_string_ref(fs_src));
    gl.compile_shader(fs);

    // program
    gl.create_program() >> prog;
    gl.delete_program.later_by(cleanup, prog);
    gl.attach_shader(prog, vs);
    gl.attach_shader(prog, fs);
    gl.link_program(prog);
    gl.use_program(prog);

    gl.get_uniform_location(prog, "Offset") >> offset_loc;
    gl.get_uniform_location(prog, "Scale") >> scale_loc;
    gl.uniform2f(offset_loc, offset_x, offset_y);
    gl.uniform2f(scale_loc, aspect * scale, scale);

    // vao
    gl.gen_vertex_arrays() >> vao;
    gl.delete_vertex_arrays.later_by(cleanup, vao);
    gl.bind_vertex_array(vao);

    // positions
    const auto position_data =
      GL.float_.array(-1.0F, -1.0F, -1.0F, 1.0F, 1.0F, -1.0F, 1.0F, 1.0F);

    gl.gen_buffers() >> positions;
    gl.delete_buffers.later_by(cleanup, positions);
    gl.bind_buffer(GL.array_buffer, positions);
    gl.buffer_data(GL.array_buffer, view(position_data), GL.static_draw);
    vertex_attrib_location position_loc;
    gl.get_attrib_location(prog, "Position") >> position_loc;

    gl.vertex_attrib_pointer(position_loc, 2, GL.float_, GL.false_);
    gl.enable_vertex_attrib_array(position_loc);

    const auto coord_data =
      GL.float_.array(-1.0F, -1.0F, -1.0F, 1.0F, 1.0F, -1.0F, 1.0F, 1.0F);

    gl.gen_buffers() >> coords;
    gl.delete_buffers.later_by(cleanup, coords);
    gl.bind_buffer(GL.array_buffer, coords);
    gl.buffer_data(GL.array_buffer, view(coord_data), GL.static_draw);
    vertex_attrib_location coord_loc;
    gl.get_attrib_location(prog, "Coord") >> coord_loc;

    gl.vertex_attrib_pointer(coord_loc, 2, GL.float_, GL.false_);
    gl.enable_vertex_attrib_array(coord_loc);

    // gradient texture
    auto gradient_data = GL.float_.array(size_constant<8 * 3>{});
    ctx.random().uniform_01(cover(gradient_data));

    gl.gen_textures() >> gradient;
    gl.delete_textures.later_by(cleanup, gradient);
    gl.active_texture(GL.texture0);
    gl.bind_texture(GL.texture_1d, gradient);
    gl.tex_parameter_i(GL.texture_1d, GL.texture_min_filter, GL.linear);
    gl.tex_parameter_i(GL.texture_1d, GL.texture_mag_filter, GL.linear);
    gl.tex_parameter_i(GL.texture_1d, GL.texture_wrap_s, GL.repeat);
    gl.tex_image1d(
      GL.texture_1d,
      0,
      GL.rgb,
      8,
      0,
      GL.rgb,
      GL.float_,
      as_bytes(view(gradient_data)));

    gl.disable(GL.depth_test);
}
//------------------------------------------------------------------------------
void example_newton::pointer_motion(const example_context& ctx) {
    const auto& state = ctx.state();
    const auto& gl = ctx.gl();

    if(state.pointer_dragging()) {
        offset_x -= 2 * state.norm_pointer_x().delta() * scale;
        offset_y -= 2 * state.norm_pointer_y().delta() * scale;

        gl.uniform2f(offset_loc, offset_x, offset_y);
    }
}
//------------------------------------------------------------------------------
void example_newton::pointer_scrolling(const example_context& ctx) {
    const auto& state = ctx.state();
    const auto& gl = ctx.gl();

    scale *= float(std::pow(2, -state.norm_pointer_z().delta()));
    if(scale < min_scale) {
        scale = min_scale;
    }
    if(scale > max_scale) {
        scale = max_scale;
    }

    gl.uniform2f(scale_loc, scale * aspect, scale);
}
//------------------------------------------------------------------------------
void example_newton::resize(const example_context& ctx) {
    const auto& state = ctx.state();
    const auto& gl = ctx.gl();

    gl.viewport(state.width(), state.height());

    aspect = state.aspect();
    gl.uniform2f(scale_loc, scale * aspect, scale);
}
//------------------------------------------------------------------------------
void example_newton::user_idle(const example_context& ctx) {
    const auto& state = ctx.state();
    const auto& gl = ctx.gl();

    if(state.user_idle_time() > seconds_(1)) {
        const float s = value(state.frame_duration()) * 60;
        const float dest_offset_x = -0.568407F;
        const float dest_offset_y = 0.125629F;
        const float c = 0.02F * s;

        offset_x = c * dest_offset_x + (1 - c) * offset_x;
        offset_y = c * dest_offset_y + (1 - c) * offset_y;

        scale *= (1 - 0.02F * s);
        if(scale < min_scale) {
            scale = min_scale;
        }

        gl.uniform2f(offset_loc, offset_x, offset_y);
        gl.uniform2f(scale_loc, scale * aspect, scale);
    }
}
//------------------------------------------------------------------------------
seconds_t<float> example_newton::default_timeout() {
    return seconds_(20);
}
//------------------------------------------------------------------------------
void example_newton::render(const example_context& ctx) {
    const auto& [gl, GL] = ctx.gl();
    gl.draw_arrays(GL.triangle_strip, 0, 4);
}
//------------------------------------------------------------------------------
} // namespace oglp
//------------------------------------------------------------------------------
std::unique_ptr<example>
make_example(const example_args&, const example_context&) {
    return std::make_unique<oglp::example_newton>();
}
//------------------------------------------------------------------------------
void adjust_params(example_params& params) {
    params.rand_seed(2345);
    params.depth_buffer(false);
    params.stencil_buffer(false);
}
//------------------------------------------------------------------------------
bool is_example_param(const example_arg&) {
    return false;
}
//------------------------------------------------------------------------------
} // namespace eagine
