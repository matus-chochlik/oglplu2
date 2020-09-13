/**
 *  example combined/004_triangle/example.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>

#include <oglplus/glsl/string_ref.hpp>
#include <oglplus/math/primitives.hpp>
#include <oglplus/math/vector.hpp>

#include "../example.hpp"

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
class example_triangle : public example {
    triangle tri{
      vec3{-0.2F, 0.5F, 0.0F},
      vec3{-0.7F, -0.6F, 0.0F},
      vec3{0.6F, 0.2F, 0.0F}};

    owned_vertex_array_name vao;

    owned_buffer_name positions;
    owned_buffer_name colors;

    owned_shader_name vs;
    owned_shader_name fs;

    owned_program_name prog;

public:
    bool check_requirements(const example_context& ctx) final;
    void init(example_context& ctx) final;
    void resize(const example_context& ctx) final;
    void render(const example_context& ctx) final;
};
//------------------------------------------------------------------------------
// example_triangle
//------------------------------------------------------------------------------
bool example_triangle ::check_requirements(const example_context& ctx) {
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
void example_triangle::init(example_context& ctx) {
    auto& cleanup = ctx.cleanup();
    const auto& [gl, GL] = ctx.gl();

    gl.clear_color(0.4F, 0.4F, 0.4F, 0.0F);

    // vertex shader
    auto vs_source = embed(EAGINE_ID(VertShader), "vertex.glsl");
    gl.create_shader(GL.vertex_shader) >> vs;
    gl.delete_shader.later_by(cleanup, vs);
    gl.shader_source(vs, glsl_string_ref(vs_source));
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

    // vao
    gl.gen_vertex_arrays() >> vao;
    gl.delete_vertex_arrays.later_by(cleanup, vao);
    gl.bind_vertex_array(vao);

    // positions
    const auto position_data = GL.float_.array(
      tri.a().x(),
      tri.a().y(),
      tri.b().x(),
      tri.b().y(),
      tri.c().x(),
      tri.c().y());

    gl.gen_buffers() >> positions;
    gl.delete_buffers.later_by(cleanup, positions);
    gl.bind_buffer(GL.array_buffer, positions);
    gl.buffer_data(GL.array_buffer, view(position_data), GL.static_draw);
    vertex_attrib_location position_loc;
    gl.get_attrib_location(prog, "Position") >> position_loc;

    gl.vertex_attrib_pointer(position_loc, 2, GL.float_, GL.false_);
    gl.enable_vertex_attrib_array(position_loc);

    // color colors
    const auto color_data =
      GL.float_.array(1.0F, 0.1F, 0.1F, 0.1F, 1.0F, 0.1F, 0.1F, 0.1F, 1.0F);

    gl.gen_buffers() >> colors;
    gl.delete_buffers.later_by(cleanup, colors);
    gl.bind_buffer(GL.array_buffer, colors);
    gl.buffer_data(GL.array_buffer, view(color_data), GL.static_draw);
    vertex_attrib_location color_loc;
    gl.get_attrib_location(prog, "Color") >> color_loc;

    gl.vertex_attrib_pointer(color_loc, 3, GL.float_, GL.false_);
    gl.enable_vertex_attrib_array(color_loc);

    gl.disable(GL.depth_test);
}
//------------------------------------------------------------------------------
void example_triangle::resize(const example_context& ctx) {
    const auto& gl = ctx.gl();

    gl.viewport(ctx.state().width(), ctx.state().height());
}
//------------------------------------------------------------------------------
void example_triangle::render(const example_context& ctx) {
    const auto& [gl, GL] = ctx.gl();

    gl.clear(GL.color_buffer_bit);
    gl.draw_arrays(GL.triangles, 0, 3);
}
//------------------------------------------------------------------------------
} // namespace oglp
//------------------------------------------------------------------------------
std::unique_ptr<example>
make_example(const example_args&, const example_context&) {
    return {std::make_unique<oglp::example_triangle>()};
}
//------------------------------------------------------------------------------
void adjust_params(example_params& params) {
    params.depth_buffer(false);
    params.stencil_buffer(false);
}
//------------------------------------------------------------------------------
bool is_example_param(const example_arg&) {
    return false;
}
//------------------------------------------------------------------------------
} // namespace eagine
