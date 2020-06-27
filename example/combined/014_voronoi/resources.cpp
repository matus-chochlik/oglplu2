/**
 *  example combined/014_voronoi/resources.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "resources.hpp"
#include "../example.hpp"

#include <oglplus/glsl/string_ref.hpp>

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
// random texture
//------------------------------------------------------------------------------
void random_texture::init(example_context& ctx) {
    auto& cleanup = ctx.cleanup();
    const auto& [gl, GL] = ctx.gl();
    auto random_data = GL.unsigned_byte_.array(size_constant<256 * 256 * 3>{});
    ctx.random().uniform(cover(random_data));

    gl.gen_textures() >> random;
    gl.delete_textures.later_by(cleanup, random);
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
// voronoi program
//------------------------------------------------------------------------------
void voronoi_program::init(example_context& ctx) {
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
}
//------------------------------------------------------------------------------
// screen shape
//------------------------------------------------------------------------------
void screen_geometry::init(example_context& ctx) {
    auto& cleanup = ctx.cleanup();
    const auto& [gl, GL] = ctx.gl();

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
    gl.vertex_attrib_pointer(position_loc, 2, GL.float_, GL.false_);
    gl.enable_vertex_attrib_array(position_loc);

    // coords
    const auto tex_coord_data =
      GL.float_.array(-1.0F, -1.0F, -1.0F, 1.0F, 1.0F, -1.0F, 1.0F, 1.0F);

    gl.gen_buffers() >> tex_coords;
    gl.delete_buffers.later_by(cleanup, tex_coords);
    gl.bind_buffer(GL.array_buffer, tex_coords);
    gl.buffer_data(GL.array_buffer, view(tex_coord_data), GL.static_draw);
    gl.vertex_attrib_pointer(tex_coord_loc, 2, GL.float_, GL.false_);
    gl.enable_vertex_attrib_array(tex_coord_loc);
}
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine
