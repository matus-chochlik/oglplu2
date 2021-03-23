/// @example application/024_overdraw/resources.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include "resources.hpp"
#include "main.hpp"

#include <eagine/application/camera.hpp>
#include <eagine/application/context.hpp>
#include <eagine/embed.hpp>
#include <eagine/shapes/cube.hpp>
#include <eagine/shapes/screen.hpp>
#include <oglplus/math/coordinates.hpp>
#include <oglplus/shapes/generator.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
// draw program
//------------------------------------------------------------------------------
void draw_program::init(example& e) {
    auto& gl = e.video().gl_api();

    gl.create_program() >> _prog;
    gl.delete_program.later_by(e.cleanup(), _prog);

    const auto prog_src{embed(EAGINE_ID(DrawProg), "overdraw_draw.oglpprog")};
    gl.build_program(_prog, prog_src.unpack(e.ctx()));
    gl.use_program(_prog);

    gl.get_uniform_location(_prog, "Camera") >> _camera_loc;
}
//------------------------------------------------------------------------------
void draw_program::set_projection(example& e) {
    e.video().gl_api().set_uniform(
      _prog, _camera_loc, e.camera().matrix(e.video()));
}
//------------------------------------------------------------------------------
void draw_program::bind_position_location(
  example& e,
  oglp::vertex_attrib_location loc) {
    e.video().gl_api().bind_attrib_location(_prog, loc, "Position");
}
//------------------------------------------------------------------------------
void draw_program::use(example& e) {
    e.video().gl_api().use_program(_prog);
}
//------------------------------------------------------------------------------
// screen program
//------------------------------------------------------------------------------
void screen_program::init(example& e) {
    auto& gl = e.video().gl_api();

    gl.create_program() >> _prog;
    gl.delete_program.later_by(e.cleanup(), _prog);

    const auto prog_src{
      embed(EAGINE_ID(ScreenProg), "overdraw_screen.oglpprog")};
    gl.build_program(_prog, prog_src.unpack(e.ctx()));
    gl.use_program(_prog);

    gl.get_uniform_location(_prog, "ScreenSize") >> _screen_size_loc;
    gl.get_uniform_location(_prog, "DrawTex") >> _draw_tex_loc;
    gl.set_uniform(_prog, _draw_tex_loc, 0);
}
//------------------------------------------------------------------------------
void screen_program::bind_position_location(
  example& e,
  oglp::vertex_attrib_location loc) {
    e.video().gl_api().bind_attrib_location(_prog, loc, "Position");
}
//------------------------------------------------------------------------------
void screen_program::bind_tex_coord_location(
  example& e,
  oglp::vertex_attrib_location loc) {
    e.video().gl_api().bind_attrib_location(_prog, loc, "TexCoord");
}
//------------------------------------------------------------------------------
void screen_program::set_screen_size(example& e) {
    const auto [w, h] = e.video().surface_size();
    e.video().gl_api().set_uniform(_prog, _screen_size_loc, oglp::vec2(w, h));
}
//------------------------------------------------------------------------------
void screen_program::use(example& e) {
    e.video().gl_api().use_program(_prog);
}
//------------------------------------------------------------------------------
// shape geometry
//------------------------------------------------------------------------------
void shape_geometry::init(example& e) {
    const auto& glapi = e.video().gl_api();
    const auto& [gl, GL] = glapi;

    oglp::shape_generator shape(
      glapi, shapes::unit_cube(shapes::vertex_attrib_kind::position));

    _ops.resize(std_size(shape.operation_count()));
    shape.instructions(glapi, cover(_ops));

    // vao
    gl.gen_vertex_arrays() >> _vao;
    gl.delete_vertex_arrays.later_by(e.cleanup(), _vao);
    gl.bind_vertex_array(_vao);

    // positions
    gl.gen_buffers() >> _positions;
    gl.delete_buffers.later_by(e.cleanup(), _positions);
    shape.attrib_setup(
      glapi,
      _vao,
      _positions,
      position_loc(),
      eagine::shapes::vertex_attrib_kind::position,
      e.ctx().buffer());

    // indices
    gl.gen_buffers() >> _indices;
    gl.delete_buffers.later_by(e.cleanup(), _indices);
    shape.index_setup(glapi, _indices, e.ctx().buffer());

    // offsets
    const float d = 1.414F;
    const float h = float(count - 1) * 0.5F;

    std::vector<oglp::gl_types::float_type> offset_data;
    offset_data.resize(std_size(count * count * count * 4));
    auto p = offset_data.begin();

    for(int k = 0; k != count; ++k) {
        const float z = (float(k) - h) * d;
        for(int j = 0; j != count; ++j) {
            const float y = (float(j) - h) * d;
            for(int i = 0; i != count; ++i) {
                const float x = (float(i) - h) * d;
                *p++ = x;
                *p++ = y;
                *p++ = z;
                *p++ = 0;
            }
        }
    }

    gl.gen_buffers() >> _offsets;
    gl.delete_buffers.later_by(e.cleanup(), _offsets);
    gl.bind_buffer(GL.uniform_buffer, _offsets);
    gl.bind_buffer_base(GL.uniform_buffer, 0, _offsets);
    gl.buffer_data(GL.uniform_buffer, view(offset_data), GL.static_draw);
}
//------------------------------------------------------------------------------
void shape_geometry::draw(example& e) {
    const auto& glapi = e.video().gl_api();
    const auto& gl = glapi;

    gl.bind_vertex_array(_vao);
    draw_instanced_using_instructions(gl, view(_ops), count * count * count);
}
//------------------------------------------------------------------------------
// screen geometry
//------------------------------------------------------------------------------
void screen_geometry::init(example& e) {
    const auto& glapi = e.video().gl_api();
    const auto& [gl, GL] = glapi;

    oglp::shape_generator shape(
      glapi,
      shapes::unit_screen(
        shapes::vertex_attrib_kind::position |
        shapes::vertex_attrib_kind::wrap_coord));

    _ops.resize(std_size(shape.operation_count()));
    shape.instructions(glapi, cover(_ops));

    // vao
    gl.gen_vertex_arrays() >> _vao;
    gl.delete_vertex_arrays.later_by(e.cleanup(), _vao);
    gl.bind_vertex_array(_vao);

    // positions
    gl.gen_buffers() >> _positions;
    gl.delete_buffers.later_by(e.cleanup(), _positions);
    shape.attrib_setup(
      glapi,
      _vao,
      _positions,
      position_loc(),
      eagine::shapes::vertex_attrib_kind::position,
      e.ctx().buffer());

    // coords
    gl.gen_buffers() >> _tex_coords;
    gl.delete_buffers.later_by(e.cleanup(), _tex_coords);
    shape.attrib_setup(
      glapi,
      _vao,
      _tex_coords,
      tex_coord_loc(),
      eagine::shapes::vertex_attrib_kind::wrap_coord,
      e.ctx().buffer());
}
//------------------------------------------------------------------------------
void screen_geometry::draw(example& e) {
    const auto& glapi = e.video().gl_api();
    const auto& gl = glapi;

    gl.bind_vertex_array(_vao);
    draw_using_instructions(gl, view(_ops));
}
//------------------------------------------------------------------------------
// draw buffers
//------------------------------------------------------------------------------
void draw_buffers::init(example& e) {
    const auto& [gl, GL] = e.video().gl_api();
    const auto [width, height] = e.video().surface_size();

    _width = width;
    _height = height;

    gl.gen_textures() >> _tex;
    gl.delete_textures.later_by(e.cleanup(), _tex);
    gl.active_texture(GL.texture0);
    gl.bind_texture(GL.texture_rectangle, _tex);
    gl.tex_parameter_i(GL.texture_rectangle, GL.texture_min_filter, GL.nearest);
    gl.tex_parameter_i(GL.texture_rectangle, GL.texture_mag_filter, GL.nearest);
    gl.tex_image2d(
      GL.texture_rectangle,
      0,
      GL.rg8,
      _width,
      _height,
      0,
      GL.rg,
      GL.unsigned_byte_,
      memory::const_block());

    gl.gen_renderbuffers() >> _rbo;
    gl.delete_renderbuffers.later_by(e.cleanup(), _rbo);
    gl.bind_renderbuffer(GL.renderbuffer, _rbo);
    gl.renderbuffer_storage(
      GL.renderbuffer, GL.depth_component, _width, _height);

    gl.gen_framebuffers() >> _fbo;
    gl.bind_framebuffer(GL.draw_framebuffer, _fbo);

    gl.framebuffer_texture2d(
      GL.draw_framebuffer, GL.color_attachment0, GL.texture_rectangle, _tex, 0);
    gl.framebuffer_renderbuffer(
      GL.draw_framebuffer, GL.depth_attachment, GL.renderbuffer, _rbo);

    gl.bind_framebuffer(GL.draw_framebuffer, oglp::framebuffer_name(0));
}
//------------------------------------------------------------------------------
void draw_buffers::resize(example& e) {
    const auto& [gl, GL] = e.video().gl_api();
    const auto [width, height] = e.video().surface_size();

    if(_width != width || _height != height) {
        _width = width;
        _height = height;

        gl.tex_image2d(
          GL.texture_rectangle,
          0,
          GL.rg8,
          _width,
          _height,
          0,
          GL.rg,
          GL.unsigned_byte_,
          memory::const_block());

        gl.renderbuffer_storage(
          GL.renderbuffer, GL.depth_component, _width, _height);
    }
}
//------------------------------------------------------------------------------
void draw_buffers::draw_offscreen(example& e) {
    const auto& [gl, GL] = e.video().gl_api();
    gl.bind_framebuffer(GL.draw_framebuffer, _fbo);
}
//------------------------------------------------------------------------------
void draw_buffers::draw_onscreen(example& e) {
    const auto& [gl, GL] = e.video().gl_api();
    gl.bind_framebuffer(GL.draw_framebuffer, oglp::framebuffer_name(0));
}
//------------------------------------------------------------------------------
} // namespace eagine::application
