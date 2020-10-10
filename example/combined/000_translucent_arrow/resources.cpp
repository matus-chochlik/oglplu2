/**
 *  example combined/000_translucent_arrow/resources.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "resources.hpp"
#include "../example.hpp"
#include "../example/camera.hpp"

#include <eagine/shapes/value_tree.hpp>
#include <eagine/value_tree/json.hpp>
#include <oglplus/glsl/string_ref.hpp>
#include <oglplus/shapes/generator.hpp>

namespace eagine::oglp {
//------------------------------------------------------------------------------
// programs
//------------------------------------------------------------------------------
void draw_program::init(example_context& ctx) {
    auto& cleanup = ctx.cleanup();
    const auto& [gl, GL] = ctx.gl();

    // vertex shader
    owned_shader_name vs;
    auto vs_src = embed(EAGINE_ID(VSDraw), "vertex_draw.glsl");
    gl.create_shader(GL.vertex_shader) >> vs;
    gl.delete_shader.later_by(cleanup, vs);
    gl.shader_source(vs, glsl_string_ref(vs_src));
    gl.compile_shader(vs);

    // fragment shader
    owned_shader_name fs;
    auto fs_src = embed(EAGINE_ID(FSDraw), "fragment_draw.glsl");
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

    gl.get_uniform_location(prog, "Projection") >> camera_loc;
}
//------------------------------------------------------------------------------
void draw_program::set_projection(
  const example_context& ctx,
  const example_orbiting_camera& camera) {
    auto& state = ctx.state();
    ctx.gl().set_uniform(prog, camera_loc, camera.matrix(state));
}
//------------------------------------------------------------------------------
void draw_program::bind_position_location(
  const example_context& ctx,
  vertex_attrib_location loc) {
    ctx.gl().bind_attrib_location(prog, loc, "Position");
}
//------------------------------------------------------------------------------
void draw_program::bind_normal_location(
  const example_context& ctx,
  vertex_attrib_location loc) {
    ctx.gl().bind_attrib_location(prog, loc, "Normal");
}
//------------------------------------------------------------------------------
// geometry
//------------------------------------------------------------------------------
void arrow_geometry::init(example_context& ctx) {
    auto& cleanup = ctx.cleanup();
    const auto& [gl, GL] = ctx.gl();

    auto load_shape_data = [&]() {
        const auto json_text =
          as_chars(embed(EAGINE_ID(ArrowJson), "arrow.json"));
        return valtree::from_json_text(json_text, ctx.log());
    };

    shape_generator shape(
      ctx.gl(), shapes::from_value_tree(load_shape_data(), ctx.log()));

    bound_sphere = shape.bounding_sphere();

    ops.resize(std_size(shape.operation_count()));
    shape.instructions(ctx.gl(), cover(ops));

    // vao
    gl.gen_vertex_arrays() >> vao;
    gl.delete_vertex_arrays.later_by(cleanup, vao);
    gl.bind_vertex_array(vao);

    // positions
    gl.gen_buffers() >> positions;
    gl.delete_buffers.later_by(cleanup, positions);
    shape.attrib_setup(
      ctx.gl(),
      vao,
      positions,
      position_loc(),
      eagine::shapes::vertex_attrib_kind::position,
      ctx.buffer());

    // normals
    gl.gen_buffers() >> normals;
    gl.delete_buffers.later_by(cleanup, normals);
    shape.attrib_setup(
      ctx.gl(),
      vao,
      normals,
      normal_loc(),
      eagine::shapes::vertex_attrib_kind::normal,
      ctx.buffer());

    // indices
    gl.gen_buffers() >> indices;
    gl.delete_buffers.later_by(cleanup, indices);
    shape.index_setup(ctx.gl(), indices, ctx.buffer());

    gl.enable(GL.depth_test);
    gl.enable(GL.cull_face);
    gl.cull_face(GL.back);
}
//------------------------------------------------------------------------------
void arrow_geometry::draw(const example_context& ctx) {
    draw_using_instructions(ctx.gl(), view(ops));
}
//------------------------------------------------------------------------------
} // namespace eagine::oglp
