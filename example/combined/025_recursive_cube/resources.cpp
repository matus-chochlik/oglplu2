/**
 *  example combined/025_recursive_cube/resources.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "resources.hpp"
#include "../example.hpp"
#include "../example/camera.hpp"

#include <eagine/math/matrix_ctr.hpp>
#include <eagine/shapes/cube.hpp>
#include <oglplus/shapes/generator.hpp>

namespace eagine::oglp {
//------------------------------------------------------------------------------
// program
//------------------------------------------------------------------------------
void cube_program::init(example_context& ctx) {
    auto& cleanup = ctx.cleanup();
    auto& gl = ctx.gl();

    gl.create_program() >> prog;
    gl.delete_program.later_by(cleanup, prog);

    const auto prog_src{embed(EAGINE_ID(prog), "recursive_cube_prog")};
    gl.build_program(prog, prog_src.unpack(ctx.main()));
    gl.use_program(prog);

    gl.get_uniform_location(prog, "Projection") >> projection_loc;
    gl.get_uniform_location(prog, "Modelview") >> modelview_loc;
    gl.get_uniform_location(prog, "LightPos") >> light_pos_loc;
    gl.get_uniform_location(prog, "CubeTex") >> cube_tex_loc;
    ctx.log()
      .debug("uniform locations")
      .arg(EAGINE_ID(Projection), projection_loc.location())
      .arg(EAGINE_ID(ModelView), modelview_loc.location())
      .arg(EAGINE_ID(LightPos), light_pos_loc.location())
      .arg(EAGINE_ID(CubeTex), cube_tex_loc.location());
}
//------------------------------------------------------------------------------
void cube_program::set_texture(
  const example_context& ctx,
  gl_types::int_type tex_unit) {
    ctx.gl().set_uniform(prog, cube_tex_loc, tex_unit);
}
//------------------------------------------------------------------------------
void cube_program::set_projection(
  const example_context& ctx,
  const tmat<float, 4, 4, true>& proj_mat) {
    ctx.gl().set_uniform(prog, projection_loc, proj_mat);
}
//------------------------------------------------------------------------------
void cube_program::update(const example_context& ctx) {
    rad += radians_(0.5F * ctx.state().frame_duration().value());
    ctx.gl().set_uniform(
      prog,
      modelview_loc,
      matrix_rotation_x(rad * 1) * matrix_rotation_y(rad * 2) *
        matrix_rotation_z(rad * 3));
    ctx.gl().set_uniform(
      prog, light_pos_loc, vec3(cos(rad) * 4, sin(rad) * 4, 8));
}
//------------------------------------------------------------------------------
void cube_program::bind_position_location(
  const example_context& ctx,
  vertex_attrib_location loc) {
    ctx.gl().bind_attrib_location(prog, loc, "Position");
}
//------------------------------------------------------------------------------
void cube_program::bind_normal_location(
  const example_context& ctx,
  vertex_attrib_location loc) {
    ctx.gl().bind_attrib_location(prog, loc, "Normal");
}
//------------------------------------------------------------------------------
void cube_program::bind_tex_coord_location(
  const example_context& ctx,
  vertex_attrib_location loc) {
    ctx.gl().bind_attrib_location(prog, loc, "TexCoord");
}
//------------------------------------------------------------------------------
// geometry
//------------------------------------------------------------------------------
void cube_geometry::init(example_context& ctx) {
    auto& cleanup = ctx.cleanup();
    const auto& gl = ctx.gl();

    shape_generator shape(
      gl,
      shapes::unit_cube(
        shapes::vertex_attrib_kind::position |
        shapes::vertex_attrib_kind::normal |
        shapes::vertex_attrib_kind::face_coord));

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

    // tex_coords
    gl.gen_buffers() >> tex_coords;
    gl.delete_buffers.later_by(cleanup, tex_coords);
    shape.attrib_setup(
      ctx.gl(),
      vao,
      tex_coords,
      tex_coord_loc(),
      eagine::shapes::vertex_attrib_kind::face_coord,
      ctx.buffer());

    // indices
    gl.gen_buffers() >> indices;
    gl.delete_buffers.later_by(cleanup, indices);
    shape.index_setup(ctx.gl(), indices, ctx.buffer());
}
//------------------------------------------------------------------------------
void cube_geometry::draw(const example_context& ctx) {
    draw_using_instructions(ctx.gl(), view(ops));
}
//------------------------------------------------------------------------------
void cube_draw_buffers::init(example_context& ctx) {
    auto& cleanup = ctx.cleanup();
    const auto& [gl, GL] = ctx.gl();

    for(int i = 0; i < 2; ++i) {
        auto& obj = objs.front();
        obj.tex_unit = i;
        gl.gen_textures() >> obj.tex;
        gl.delete_textures.later_by(cleanup, obj.tex);
        gl.active_texture(GL.texture0 + i);
        gl.bind_texture(GL.texture_2d, obj.tex);
        gl.tex_parameter_i(GL.texture_2d, GL.texture_min_filter, GL.nearest);
        gl.tex_parameter_i(GL.texture_2d, GL.texture_mag_filter, GL.nearest);
        gl.tex_image2d(
          GL.texture_2d,
          0,
          GL.rgb,
          tex_side,
          tex_side,
          0,
          GL.rgb,
          GL.unsigned_byte_,
          memory::const_block());

        gl.gen_renderbuffers() >> obj.rbo;
        gl.delete_renderbuffers.later_by(cleanup, obj.rbo);
        gl.bind_renderbuffer(GL.renderbuffer, obj.rbo);
        gl.renderbuffer_storage(
          GL.renderbuffer, GL.depth_component, tex_side, tex_side);

        gl.gen_framebuffers() >> obj.fbo;
        gl.delete_framebuffers.later_by(cleanup, obj.fbo);
        gl.bind_framebuffer(GL.draw_framebuffer, obj.fbo);

        gl.framebuffer_texture2d(
          GL.draw_framebuffer, GL.color_attachment0, GL.texture_2d, obj.tex, 0);
        gl.framebuffer_renderbuffer(
          GL.draw_framebuffer, GL.depth_attachment, GL.renderbuffer, obj.rbo);

        gl.viewport(tex_side, tex_side);
        gl.clear(GL.color_buffer_bit);

        objs.swap();
    }

    gl.bind_framebuffer(GL.draw_framebuffer, framebuffer_name(0));
    gl.bind_renderbuffer(GL.renderbuffer, renderbuffer_name(0));
}
//------------------------------------------------------------------------------
} // namespace eagine::oglp
