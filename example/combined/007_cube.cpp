/**
 *  example oglplus/003_triangle.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

// clang-format off
#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>
#include <oglplus/glsl/string_ref.hpp>
#include <oglplus/math/vector.hpp>
#include <oglplus/math/matrix.hpp>
#include "example.hpp"
#include "example/camera.hpp"
// clang-format on
#include <eagine/shapes/cube.hpp>
#include <oglplus/shapes/generator.hpp>

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
class example_cube : public example {
    example_orbiting_camera camera;

    owned_vertex_array_name vao;

    owned_buffer_name positions;
    owned_buffer_name normals;

    owned_shader_name vs;
    owned_shader_name fs;

    owned_program_name prog;
    uniform_location camera_loc;

    std::vector<shape_draw_operation> _ops;

    void set_projection(const example_context& ctx);

public:
    bool check_requirements(const example_context& ctx) final;
    void init(example_context& ctx) final;
    void pointer_motion(const example_context& ctx) final;
    void pointer_scrolling(const example_context& ctx) final;
    void user_idle(const example_context& ctx) final;
    void resize(const example_context& ctx) final;
    void render(const example_context& ctx) final;
};
//------------------------------------------------------------------------------
// example_cube
//------------------------------------------------------------------------------
bool example_cube ::check_requirements(const example_context& ctx) {
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
void example_cube::set_projection(const example_context& ctx) {
    ctx.gl().set_uniform(prog, camera_loc, camera.matrix(ctx.state()));
}
//------------------------------------------------------------------------------
void example_cube::init(example_context& ctx) {
    auto& cleanup = ctx.cleanup();
    const auto& [gl, GL] = ctx.gl();

    shape_generator shape(
      ctx.gl(),
      shapes::unit_cube(
        shapes::vertex_attrib_kind::position |
        shapes::vertex_attrib_kind::normal));

    _ops.resize(std_size(shape.operation_count()));
    shape.instructions(ctx.gl(), cover(_ops));

    gl.clear_color(0.4f, 0.4f, 0.4f, 0.0f);

    // vertex shader
    gl.create_shader(GL.vertex_shader) >> vs;
    gl.delete_shader.later_by(cleanup, vs);
    gl.shader_source(
      vs,
      glsl_literal("#version 140\n"
                   "in vec3 Position;\n"
                   "in vec3 Normal;\n"
                   "out vec3 vertColor;\n"
                   "uniform mat4 Camera;\n"
                   "void main()\n"
                   "{\n"
                   "	gl_Position = Camera * vec4(Position, 1.0);\n"
                   "	vertColor = normalize(vec3(1.0)+Normal);\n"
                   "}\n"));
    gl.compile_shader(vs);

    // fragment shader
    gl.create_shader(GL.fragment_shader) >> fs;
    gl.delete_shader.later_by(cleanup, fs);
    gl.shader_source(
      fs,
      glsl_literal("#version 140\n"
                   "in vec3 vertColor;\n"
                   "out vec3 fragColor;\n"
                   "void main()\n"
                   "{\n"
                   "	fragColor = vertColor;\n"
                   "}\n"));
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
    vertex_attrib_location position_loc(0);
    gl.gen_buffers() >> positions;
    gl.delete_buffers.later_by(cleanup, positions);
    shape.attrib_setup(
      ctx.gl(),
      vao,
      positions,
      position_loc,
      eagine::shapes::vertex_attrib_kind::position,
      0,
      ctx.buffer());
    gl.bind_attrib_location(prog, position_loc, "Position");

    // normals
    vertex_attrib_location normal_loc(1);
    gl.gen_buffers() >> normals;
    gl.delete_buffers.later_by(cleanup, normals);
    shape.attrib_setup(
      ctx.gl(),
      vao,
      normals,
      normal_loc,
      eagine::shapes::vertex_attrib_kind::normal,
      0,
      ctx.buffer());
    gl.bind_attrib_location(prog, normal_loc, "Normal");

    gl.enable(GL.depth_test);

    // camera
    gl.get_uniform_location(prog, "Camera") >> camera_loc;
    camera.set_near(0.1f)
      .set_far(50.f)
      .set_orbit_min(1.1f)
      .set_orbit_max(3.5f)
      .set_fov(right_angle_());
    set_projection(ctx);
}
//------------------------------------------------------------------------------
void example_cube::pointer_motion(const example_context& ctx) {
    const auto& state = ctx.state();
    if(camera.apply_pointer_motion(state)) {
        set_projection(ctx);
    }
}
//------------------------------------------------------------------------------
void example_cube::pointer_scrolling(const example_context& ctx) {
    const auto& state = ctx.state();
    if(camera.apply_pointer_scrolling(state)) {
        set_projection(ctx);
    }
}
//------------------------------------------------------------------------------
void example_cube::user_idle(const example_context& ctx) {
    const auto& state = ctx.state();
    if(state.user_idle_time() > seconds_(1)) {
        camera.idle_update(state, 2);
        set_projection(ctx);
    }
}
//------------------------------------------------------------------------------
void example_cube::resize(const example_context& ctx) {
    const auto& state = ctx.state();
    const auto& gl = ctx.gl();

    gl.viewport(state.width(), state.height());
    set_projection(ctx);
}
//------------------------------------------------------------------------------
void example_cube::render(const example_context& ctx) {
    const auto& [gl, GL] = ctx.gl();

    gl.clear(GL.color_buffer_bit | GL.depth_buffer_bit);
    draw_using_instructions(ctx.gl(), view(_ops));
}
//------------------------------------------------------------------------------
} // namespace oglp
//------------------------------------------------------------------------------
std::unique_ptr<example> make_example(
  const example_args&, const example_context&) {
    return {std::make_unique<oglp::example_cube>()};
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

