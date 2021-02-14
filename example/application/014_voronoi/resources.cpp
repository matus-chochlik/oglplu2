/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include "resources.hpp"

#include <eagine/application/context.hpp>
#include <eagine/embed.hpp>
#include <oglplus/glsl/string_ref.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
// random texture
//------------------------------------------------------------------------------
void random_texture::init(execution_context& ec, video_context& vc) {
    const auto& [gl, GL] = vc.gl_api();
    auto random_data = GL.unsigned_byte_.array(size_constant<256 * 256 * 3>{});
    ec.random_uniform(cover(random_data));

    gl.gen_textures() >> random;
    gl.active_texture(GL.texture0);
    gl.bind_texture(GL.texture_2d, random);
    gl.tex_parameter_i(GL.texture_2d, GL.texture_min_filter, GL.nearest);
    gl.tex_parameter_i(GL.texture_2d, GL.texture_mag_filter, GL.nearest);
    gl.tex_parameter_i(GL.texture_2d, GL.texture_wrap_s, GL.repeat);
    gl.tex_parameter_i(GL.texture_2d, GL.texture_wrap_t, GL.repeat);
    gl.tex_image2d(
      GL.texture_2d,
      0,
      GL.rgb,
      256,
      256,
      0,
      GL.rgb,
      GL.unsigned_byte_,
      as_bytes(view(random_data)));
}
//------------------------------------------------------------------------------
void random_texture::clean_up(execution_context&, video_context& vc) {
    const auto& gl = vc.gl_api();
    gl.delete_textures(std::move(random));
}
//------------------------------------------------------------------------------
// voronoi program
//------------------------------------------------------------------------------
void voronoi_program::init(execution_context&, video_context& vc) {
    const auto& [gl, GL] = vc.gl_api();

    // vertex shader
    auto vs_source = embed(EAGINE_ID(VertShader), "vertex.glsl");
    gl.create_shader(GL.vertex_shader) >> vs;
    gl.shader_source(vs, oglp::glsl_string_ref(vs_source));
    gl.compile_shader(vs);

    // fragment shader
    auto fs_source = embed(EAGINE_ID(FragShader), "fragment.glsl");
    gl.create_shader(GL.fragment_shader) >> fs;
    gl.shader_source(fs, oglp::glsl_string_ref(fs_source));
    gl.compile_shader(fs);

    // program
    gl.create_program() >> prog;
    gl.attach_shader(prog, vs);
    gl.attach_shader(prog, fs);
    gl.link_program(prog);
    gl.use_program(prog);

    gl.get_uniform_location(prog, "Offset") >> offset_loc;
    gl.get_uniform_location(prog, "Scale") >> scale_loc;
}
//------------------------------------------------------------------------------
void voronoi_program::clean_up(execution_context&, video_context& vc) {
    const auto& gl = vc.gl_api();
    gl.delete_shader(std::move(fs));
    gl.delete_shader(std::move(vs));
    gl.delete_program(std::move(prog));
}
//------------------------------------------------------------------------------
// screen shape
//------------------------------------------------------------------------------
void screen_geometry::init(execution_context&, video_context& vc) {
    const auto& [gl, GL] = vc.gl_api();

    // vao
    gl.gen_vertex_arrays() >> vao;
    gl.bind_vertex_array(vao);

    // positions
    const auto position_data =
      GL.float_.array(-1.0F, -1.0F, -1.0F, 1.0F, 1.0F, -1.0F, 1.0F, 1.0F);

    gl.gen_buffers() >> positions;
    gl.bind_buffer(GL.array_buffer, positions);
    gl.buffer_data(GL.array_buffer, view(position_data), GL.static_draw);
    gl.vertex_attrib_pointer(position_loc, 2, GL.float_, GL.false_);
    gl.enable_vertex_attrib_array(position_loc);

    // coords
    const auto tex_coord_data =
      GL.float_.array(-1.0F, -1.0F, -1.0F, 1.0F, 1.0F, -1.0F, 1.0F, 1.0F);

    gl.gen_buffers() >> tex_coords;
    gl.bind_buffer(GL.array_buffer, tex_coords);
    gl.buffer_data(GL.array_buffer, view(tex_coord_data), GL.static_draw);
    gl.vertex_attrib_pointer(tex_coord_loc, 2, GL.float_, GL.false_);
    gl.enable_vertex_attrib_array(tex_coord_loc);
}
//------------------------------------------------------------------------------
void screen_geometry::clean_up(execution_context&, video_context& vc) {
    const auto& gl = vc.gl_api();
    gl.delete_buffers(std::move(tex_coords));
    gl.delete_buffers(std::move(positions));
    gl.delete_vertex_arrays(std::move(vao));
}
//------------------------------------------------------------------------------
} // namespace eagine::application
