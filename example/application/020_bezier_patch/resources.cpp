/// @example application/020_bezier_patch/resources.cpp
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

namespace eagine::application {
//------------------------------------------------------------------------------
// program
//------------------------------------------------------------------------------
void patch_program::init(execution_context& ec, video_context& vc) {
    const auto& glapi = vc.gl_api();
    const auto& gl = glapi;

    gl.create_program() >> prog;

    const auto prog_src{embed(EAGINE_ID(BPatchProg), "bezier_patch.oglpprog")};
    gl.build_program(prog, prog_src.unpack(ec));
    gl.use_program(prog);

    gl.get_uniform_location(prog, "Color") >> color_loc;
    gl.get_uniform_location(prog, "CameraMatrix") >> camera_matrix_loc;
    gl.get_uniform_location(prog, "PerspectiveMatrix") >>
      perspective_matrix_loc;
}
//------------------------------------------------------------------------------
void patch_program::clean_up(video_context& vc) {
    vc.gl_api().delete_program(std::move(prog));
}
//------------------------------------------------------------------------------
void patch_program::set_projection(video_context& vc, orbiting_camera& camera) {
    const auto& gl = vc.gl_api();
    gl.set_uniform(prog, camera_matrix_loc, camera.transform_matrix());
    gl.set_uniform(
      prog,
      perspective_matrix_loc,
      camera.perspective_matrix(vc.surface_aspect()));
}
//------------------------------------------------------------------------------
void patch_program::set_wireframe_color(video_context& vc) {
    vc.gl_api().set_uniform(
      prog, color_loc, oglp::vec4(0.1F, 0.1F, 0.1F, 1.0F));
}
//------------------------------------------------------------------------------
void patch_program::set_surface_color(video_context& vc) {
    vc.gl_api().set_uniform(
      prog, color_loc, oglp::vec4(1.0F, 1.0F, 1.0F, 0.4F));
}
//------------------------------------------------------------------------------
void patch_program::bind_position_location(
  video_context& vc,
  oglp::vertex_attrib_location loc) {
    vc.gl_api().bind_attrib_location(prog, loc, "Position");
}
//------------------------------------------------------------------------------
// geometry
//------------------------------------------------------------------------------
void patch_geometry::init(execution_context&, video_context& vc) {
    const auto& glapi = vc.gl_api();
    const auto& [gl, GL] = glapi;

    // vao
    gl.gen_vertex_arrays() >> _vao;
    gl.bind_vertex_array(_vao);

    // positions
    // clang-format off
    const auto position_data = GL.float_.array(
		-2.F,  0.F, -2.F,
		-1.F,  0.F, -3.F,
		 1.F,  0.F, -5.F,
		 2.F,  0.F, -2.F,
		-1.F,  0.F, -1.F,
		 0.F,  4.F, -1.F,
		 1.F,  4.F, -1.F,
		 3.F,  0.F, -1.F,
		-1.F,  0.F,  1.F,
		-1.F,  4.F,  1.F,
		 0.F,  4.F,  1.F,
		 1.F,  0.F,  1.F,
		-2.F,  0.F,  2.F,
		-1.F,  0.F,  5.F,
		 1.F,  0.F,  3.F,
		 2.F,  0.F,  2.F);
    // clang-format on

    gl.gen_buffers() >> _positions;
    gl.bind_buffer(GL.array_buffer, _positions);
    gl.buffer_data(GL.array_buffer, view(position_data), GL.static_draw);
    gl.vertex_attrib_pointer(position_loc(), 3, GL.float_, GL.false_);
    gl.enable_vertex_attrib_array(position_loc());
}
//------------------------------------------------------------------------------
void patch_geometry::clean_up(video_context& vc) {
    const auto& gl = vc.gl_api();
    gl.delete_buffers(std::move(_positions));
    gl.delete_vertex_arrays(std::move(_vao));
}
//------------------------------------------------------------------------------
void patch_geometry::draw(video_context& vc) {
    const auto& [gl, GL] = vc.gl_api();
    gl.draw_arrays(GL.patches, 0, 16);
}
//------------------------------------------------------------------------------
} // namespace eagine::application
