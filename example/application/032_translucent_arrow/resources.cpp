/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "resources.hpp"

#include <eagine/application/camera.hpp>
#include <eagine/application/context.hpp>
#include <eagine/embed.hpp>
#include <eagine/shapes/value_tree.hpp>
#include <eagine/value_tree/json.hpp>
#include <oglplus/glsl/string_ref.hpp>
#include <oglplus/shapes/generator.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
// programs
//------------------------------------------------------------------------------
void depth_program::init(
  execution_context& ec,
  video_context& vc,
  cleanup_group& cleanup) {
    const auto& [gl, GL] = vc.gl_api();

    // vertex shader
    oglp::owned_shader_name vs;
    auto vs_src = embed(EAGINE_ID(VSDepth), "vertex_depth.glsl");
    gl.create_shader(GL.vertex_shader) >> vs;
    auto cleanup_vs = gl.delete_shader.raii(vs);
    gl.shader_source(vs, oglp::glsl_string_ref(vs_src.unpack(ec)));
    gl.compile_shader(vs);

    // program
    gl.create_program() >> prog;
    gl.delete_program.later_by(cleanup, prog);
    gl.attach_shader(prog, vs);
    gl.link_program(prog);
    gl.use_program(prog);

    gl.get_uniform_location(prog, "Projection") >> camera_loc;
}
//------------------------------------------------------------------------------
void depth_program::set_projection(video_context& vc, orbiting_camera& camera) {
    const auto& gl = vc.gl_api();

    gl.use_program(prog);
    gl.set_uniform(prog, camera_loc, camera.matrix(vc));
}
//------------------------------------------------------------------------------
void depth_program::update(video_context& vc) {
    vc.gl_api().use_program(prog);
}
//------------------------------------------------------------------------------
void depth_program::bind_position_location(
  video_context& vc,
  oglp::vertex_attrib_location loc) {
    vc.gl_api().bind_attrib_location(prog, loc, "Position");
}
//------------------------------------------------------------------------------
void draw_program::init(
  execution_context& ec,
  video_context& vc,
  cleanup_group& cleanup) {
    const auto& [gl, GL] = vc.gl_api();

    // vertex shader
    oglp::owned_shader_name vs;
    auto vs_src = embed(EAGINE_ID(VSDraw), "vertex_draw.glsl");
    gl.create_shader(GL.vertex_shader) >> vs;
    auto cleanup_vs = gl.delete_shader.raii(vs);
    gl.shader_source(vs, oglp::glsl_string_ref(vs_src.unpack(ec)));
    gl.compile_shader(vs);

    // fragment shader
    oglp::owned_shader_name fs;
    auto fs_src = embed(EAGINE_ID(FSDraw), "fragment_draw.glsl");
    gl.create_shader(GL.fragment_shader) >> fs;
    auto cleanup_fs = gl.delete_shader.raii(fs);
    gl.shader_source(fs, oglp::glsl_string_ref(fs_src.unpack(ec)));
    gl.compile_shader(fs);

    // program
    gl.create_program() >> prog;
    gl.delete_program.later_by(cleanup, prog);
    gl.attach_shader(prog, vs);
    gl.attach_shader(prog, fs);
    gl.link_program(prog);
    gl.use_program(prog);

    gl.get_uniform_location(prog, "Projection") >> camera_loc;
    gl.get_uniform_location(prog, "LightPosition") >> light_pos_loc;
    gl.get_uniform_location(prog, "DepthTexture") >> depth_tex_loc;
}
//------------------------------------------------------------------------------
void draw_program::set_depth_texture(
  video_context& vc,
  oglp::gl_types::int_type tex_unit) {
    const auto& gl = vc.gl_api();

    gl.use_program(prog);
    gl.set_uniform(prog, depth_tex_loc, tex_unit);
}
//------------------------------------------------------------------------------
void draw_program::set_projection(video_context& vc, orbiting_camera& camera) {
    const auto& gl = vc.gl_api();

    gl.use_program(prog);
    gl.set_uniform(prog, camera_loc, camera.matrix(vc));
}
//------------------------------------------------------------------------------
void draw_program::update(execution_context& ec, video_context& vc) {
    const auto& gl = vc.gl_api();

    rad += radians_(0.5F * ec.state().frame_duration().value());

    gl.use_program(prog);
    gl.set_uniform(
      prog,
      light_pos_loc,
      oglp::vec3(cos(rad) * 5, sin(rad) * 7, sin(rad * 0.618F) * 8));
}
//------------------------------------------------------------------------------
void draw_program::bind_position_location(
  video_context& vc,
  oglp::vertex_attrib_location loc) {
    vc.gl_api().bind_attrib_location(prog, loc, "Position");
}
//------------------------------------------------------------------------------
void draw_program::bind_normal_location(
  video_context& vc,
  oglp::vertex_attrib_location loc) {
    vc.gl_api().bind_attrib_location(prog, loc, "Normal");
}
//------------------------------------------------------------------------------
// geometry
//------------------------------------------------------------------------------
void arrow_geometry::init(
  execution_context& ec,
  video_context& vc,
  cleanup_group& cleanup) {
    const auto& glapi = vc.gl_api();
    const auto& [gl, GL] = glapi;

    auto load_shape_data = [&]() {
        return valtree::from_json_text(
          as_chars(embed(EAGINE_ID(ArrowJson), "arrow.json").unpack(ec)), ec);
    };

    oglp::shape_generator shape(
      glapi, shapes::from_value_tree(load_shape_data(), ec));

    bound_sphere = shape.bounding_sphere();

    ops.resize(std_size(shape.operation_count()));
    shape.instructions(glapi, cover(ops));

    // vao
    gl.gen_vertex_arrays() >> vao;
    gl.delete_vertex_arrays.later_by(cleanup, vao);
    gl.bind_vertex_array(vao);

    // positions
    gl.gen_buffers() >> positions;
    gl.delete_buffers.later_by(cleanup, positions);
    shape.attrib_setup(
      glapi,
      vao,
      positions,
      position_loc(),
      eagine::shapes::vertex_attrib_kind::position,
      ec.buffer());

    // normals
    gl.gen_buffers() >> normals;
    gl.delete_buffers.later_by(cleanup, normals);
    shape.attrib_setup(
      glapi,
      vao,
      normals,
      normal_loc(),
      eagine::shapes::vertex_attrib_kind::normal,
      ec.buffer());

    // indices
    gl.gen_buffers() >> indices;
    gl.delete_buffers.later_by(cleanup, indices);
    shape.index_setup(glapi, indices, ec.buffer());

    gl.enable(GL.depth_test);
    gl.enable(GL.cull_face);
    gl.cull_face(GL.back);
}
//------------------------------------------------------------------------------
void arrow_geometry::draw(video_context& vc) {
    draw_using_instructions(vc.gl_api(), view(ops));
}
//------------------------------------------------------------------------------
// texture
//------------------------------------------------------------------------------
void depth_texture::init(
  execution_context&,
  video_context& vc,
  cleanup_group& cleanup) {
    const auto& gl = vc.gl_api();

    gl.gen_textures() >> tex;
    gl.delete_textures.later_by(cleanup, tex);
}
//------------------------------------------------------------------------------
void depth_texture::reshape(video_context& vc) {
    const auto& [gl, GL] = vc.gl_api();
    const auto [width, height] = vc.surface_size();

    gl.active_texture(GL.texture0 + tex_unit);
    gl.bind_texture(GL.texture_rectangle, tex);
    gl.tex_parameter_i(GL.texture_rectangle, GL.texture_min_filter, GL.nearest);
    gl.tex_parameter_i(GL.texture_rectangle, GL.texture_mag_filter, GL.nearest);
    gl.tex_image2d(
      GL.texture_rectangle,
      0,
      GL.depth_component,
      width,
      height,
      0,
      GL.depth_component,
      GL.float_,
      memory::const_block());

    gl.viewport(width, height);
    gl.clear(GL.depth_buffer_bit);
}
//------------------------------------------------------------------------------
void depth_texture::copy_from_fb(video_context& vc) {
    const auto [width, height] = vc.surface_size();
    const auto& [gl, GL] = vc.gl_api();

    gl.copy_tex_image2d(
      GL.texture_rectangle, 0, GL.depth_component, 0, 0, width, height, 0);
}
//------------------------------------------------------------------------------

} // namespace eagine::application
