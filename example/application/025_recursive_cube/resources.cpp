/// .file combined/025_recursive_cube/resources.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include "resources.hpp"

#include <eagine/application/camera.hpp>
#include <eagine/application/context.hpp>
#include <eagine/embed.hpp>
#include <eagine/math/matrix_ctr.hpp>
#include <eagine/shapes/cube.hpp>
#include <oglplus/shapes/generator.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
// program
//------------------------------------------------------------------------------
void cube_program::init(execution_context& ec, video_context& vc) {
    const auto& gl = vc.gl_api();

    gl.create_program() >> prog;

    const auto prog_src{embed(EAGINE_ID(prog), "recursive_cube_prog")};
    gl.build_program(prog, prog_src.unpack(ec));
    gl.use_program(prog);

    gl.get_uniform_location(prog, "Projection") >> projection_loc;
    gl.get_uniform_location(prog, "Modelview") >> modelview_loc;
    gl.get_uniform_location(prog, "LightPos") >> light_pos_loc;
    gl.get_uniform_location(prog, "CubeTex") >> cube_tex_loc;
}
//------------------------------------------------------------------------------
void cube_program::clean_up(video_context& vc) {
    const auto& gl = vc.gl_api();
    gl.delete_program(std::move(prog));
}
//------------------------------------------------------------------------------
void cube_program::set_texture(
  video_context& vc,
  oglp::gl_types::int_type tex_unit) {
    vc.gl_api().set_uniform(prog, cube_tex_loc, tex_unit);
}
//------------------------------------------------------------------------------
void cube_program::set_projection(
  video_context& vc,
  const oglp::tmat<float, 4, 4, true>& proj_mat) {
    vc.gl_api().set_uniform(prog, projection_loc, proj_mat);
}
//------------------------------------------------------------------------------
void cube_program::update(execution_context& ec, video_context& vc) {
    rad += radians_(0.5F * ec.state().frame_duration().value());
    auto& glapi = vc.gl_api();
    glapi.set_uniform(
      prog,
      modelview_loc,
      oglp::matrix_rotation_x(rad * 1) * oglp::matrix_rotation_y(rad * 2) *
        oglp::matrix_rotation_z(rad * 3));
    glapi.set_uniform(
      prog, light_pos_loc, oglp::vec3(cos(rad) * 4, sin(rad) * 4, 8));
}
//------------------------------------------------------------------------------
void cube_program::bind_position_location(
  video_context& vc,
  oglp::vertex_attrib_location loc) {
    vc.gl_api().bind_attrib_location(prog, loc, "Position");
}
//------------------------------------------------------------------------------
void cube_program::bind_normal_location(
  video_context& vc,
  oglp::vertex_attrib_location loc) {
    vc.gl_api().bind_attrib_location(prog, loc, "Normal");
}
//------------------------------------------------------------------------------
void cube_program::bind_tex_coord_location(
  video_context& vc,
  oglp::vertex_attrib_location loc) {
    vc.gl_api().bind_attrib_location(prog, loc, "TexCoord");
}
//------------------------------------------------------------------------------
// geometry
//------------------------------------------------------------------------------
void cube_geometry::init(execution_context& ec, video_context& vc) {
    const auto& glapi = vc.gl_api();
    const auto& gl = glapi;

    oglp::shape_generator shape(
      glapi,
      shapes::unit_cube(
        shapes::vertex_attrib_kind::position |
        shapes::vertex_attrib_kind::normal |
        shapes::vertex_attrib_kind::face_coord));

    ops.resize(std_size(shape.operation_count()));
    shape.instructions(glapi, cover(ops));

    // vao
    gl.gen_vertex_arrays() >> vao;
    gl.bind_vertex_array(vao);

    // positions
    gl.gen_buffers() >> positions;
    shape.attrib_setup(
      glapi,
      vao,
      positions,
      position_loc(),
      eagine::shapes::vertex_attrib_kind::position,
      ec.buffer());

    // normals
    gl.gen_buffers() >> normals;
    shape.attrib_setup(
      glapi,
      vao,
      normals,
      normal_loc(),
      eagine::shapes::vertex_attrib_kind::normal,
      ec.buffer());

    // tex_coords
    gl.gen_buffers() >> tex_coords;
    shape.attrib_setup(
      glapi,
      vao,
      tex_coords,
      tex_coord_loc(),
      eagine::shapes::vertex_attrib_kind::face_coord,
      ec.buffer());

    // indices
    gl.gen_buffers() >> indices;
    shape.index_setup(glapi, indices, ec.buffer());
}
//------------------------------------------------------------------------------
void cube_geometry::clean_up(video_context& vc) {
    const auto& gl = vc.gl_api();
    gl.delete_buffers(std::move(indices));
    gl.delete_buffers(std::move(tex_coords));
    gl.delete_buffers(std::move(normals));
    gl.delete_buffers(std::move(positions));
    gl.delete_vertex_arrays(std::move(vao));
}
//------------------------------------------------------------------------------
void cube_geometry::draw(video_context& vc) {
    draw_using_instructions(vc.gl_api(), view(ops));
}
//------------------------------------------------------------------------------
void cube_draw_buffers::init(execution_context&, video_context& vc) {
    const auto& glapi = vc.gl_api();
    const auto& [gl, GL] = glapi;

    for(int i = 0; i < 2; ++i) {
        auto& obj = objs.front();
        obj.tex_unit = i;
        gl.gen_textures() >> obj.tex;
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
        gl.bind_renderbuffer(GL.renderbuffer, obj.rbo);
        gl.renderbuffer_storage(
          GL.renderbuffer, GL.depth_component, tex_side, tex_side);

        gl.gen_framebuffers() >> obj.fbo;
        gl.bind_framebuffer(GL.draw_framebuffer, obj.fbo);

        gl.framebuffer_texture2d(
          GL.draw_framebuffer, GL.color_attachment0, GL.texture_2d, obj.tex, 0);
        gl.framebuffer_renderbuffer(
          GL.draw_framebuffer, GL.depth_attachment, GL.renderbuffer, obj.rbo);

        gl.viewport(tex_side, tex_side);
        gl.clear(GL.color_buffer_bit);

        objs.swap();
    }

    gl.bind_framebuffer(GL.draw_framebuffer, oglp::framebuffer_name(0));
    gl.bind_renderbuffer(GL.renderbuffer, oglp::renderbuffer_name(0));
}
//------------------------------------------------------------------------------
void cube_draw_buffers::clean_up(video_context& vc) {
    const auto& gl = vc.gl_api();
    for(int i = 0; i < 2; ++i) {
        auto& obj = objs.front();
        gl.delete_renderbuffers(std::move(obj.rbo));
        gl.delete_textures(std::move(obj.tex));
        gl.delete_framebuffers(std::move(obj.fbo));
        objs.swap();
    }
}
//------------------------------------------------------------------------------
} // namespace eagine::application
