/// @example application/022_halo/resources.cpp
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
#include <oglplus/glsl/string_ref.hpp>
#include <oglplus/math/matrix_ctrs.hpp>
#include <oglplus/shapes/generator.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
// surface program
//------------------------------------------------------------------------------
void surface_program::init(execution_context& ec, video_context& vc) {
    auto& gl = vc.gl_api();

    gl.create_program() >> _prog;

    const auto prog_src{embed(EAGINE_ID(SurfProg), "halo_surface.oglpprog")};
    gl.build_program(_prog, prog_src.unpack(ec));
    gl.use_program(_prog);

    gl.get_uniform_location(_prog, "Model") >> _model_loc;
    gl.get_uniform_location(_prog, "View") >> _view_loc;
    gl.get_uniform_location(_prog, "Projection") >> _projection_loc;
}
//------------------------------------------------------------------------------
void surface_program::clean_up(video_context& vc) {
    auto& gl = vc.gl_api();
    gl.delete_program(std::move(_prog));
}
//------------------------------------------------------------------------------
void surface_program::prepare_frame(
  video_context& vc,
  orbiting_camera& camera,
  float t) {
    auto& gl = vc.gl_api();
    gl.use_program(_prog);
    gl.set_uniform(
      _prog, _model_loc, oglp::matrix_rotation_x(right_angles_(t))());
    gl.set_uniform(_prog, _view_loc, camera.transform_matrix());
    gl.set_uniform(
      _prog, _projection_loc, camera.perspective_matrix(vc.surface_aspect()));
}
//------------------------------------------------------------------------------
void surface_program::bind_position_location(
  video_context& vc,
  oglp::vertex_attrib_location loc) {
    auto& gl = vc.gl_api();
    gl.bind_attrib_location(_prog, loc, "Position");
}
//------------------------------------------------------------------------------
void surface_program::bind_normal_location(
  video_context& vc,
  oglp::vertex_attrib_location loc) {
    auto& gl = vc.gl_api();
    gl.bind_attrib_location(_prog, loc, "Normal");
}
//------------------------------------------------------------------------------
// halo program
//------------------------------------------------------------------------------
void halo_program::init(execution_context& ec, video_context& vc) {
    auto& gl = vc.gl_api();

    gl.create_program() >> _prog;

    const auto prog_src{embed(EAGINE_ID(HaloProg), "halo_halo.oglpprog")};
    gl.build_program(_prog, prog_src.unpack(ec));
    gl.use_program(_prog);

    gl.get_uniform_location(_prog, "Model") >> _model_loc;
    gl.get_uniform_location(_prog, "View") >> _view_loc;
    gl.get_uniform_location(_prog, "Projection") >> _projection_loc;
    gl.get_uniform_location(_prog, "CameraPos") >> _camera_pos_loc;
}
//------------------------------------------------------------------------------
void halo_program::clean_up(video_context& vc) {
    auto& gl = vc.gl_api();
    gl.delete_program(std::move(_prog));
}
//------------------------------------------------------------------------------
void halo_program::prepare_frame(
  video_context& vc,
  orbiting_camera& camera,
  float t) {
    auto& gl = vc.gl_api();
    gl.use_program(_prog);

    gl.set_uniform(
      _prog, _model_loc, oglp::matrix_rotation_x(right_angles_(t))());
    gl.set_uniform(_prog, _view_loc, camera.transform_matrix());
    gl.set_uniform(
      _prog, _projection_loc, camera.perspective_matrix(vc.surface_aspect()));
    gl.set_uniform(_prog, _camera_pos_loc, camera.position());
}
//------------------------------------------------------------------------------
void halo_program::bind_position_location(
  video_context& vc,
  oglp::vertex_attrib_location loc) {
    auto& gl = vc.gl_api();
    gl.bind_attrib_location(_prog, loc, "Position");
}
//------------------------------------------------------------------------------
void halo_program::bind_normal_location(
  video_context& vc,
  oglp::vertex_attrib_location loc) {
    auto& gl = vc.gl_api();
    gl.bind_attrib_location(_prog, loc, "Normal");
}
//------------------------------------------------------------------------------
// geometry
//------------------------------------------------------------------------------
void shape_geometry::init(execution_context& ec, video_context& vc) {
    const auto& glapi = vc.gl_api();
    const auto& gl = glapi;

    oglp::shape_generator shape(glapi, _gen);

    auto draw_var = shape.draw_variant(0);
    _ops.resize(std_size(shape.operation_count(draw_var)));
    shape.instructions(glapi, draw_var, cover(_ops));

    // vao
    gl.gen_vertex_arrays() >> _vao;
    gl.bind_vertex_array(_vao);

    // positions
    gl.gen_buffers() >> _positions;
    shape.attrib_setup(
      glapi,
      _vao,
      _positions,
      position_loc(),
      eagine::shapes::vertex_attrib_kind::position,
      ec.buffer());

    // normals
    gl.gen_buffers() >> _normals;
    shape.attrib_setup(
      glapi,
      _vao,
      _normals,
      normal_loc(),
      eagine::shapes::vertex_attrib_kind::normal,
      ec.buffer());

    // indices
    gl.gen_buffers() >> _indices;
    shape.index_setup(glapi, _indices, draw_var, ec.buffer());
}
//------------------------------------------------------------------------------
void shape_geometry::clean_up(video_context& vc) {
    const auto& gl = vc.gl_api();
    gl.delete_buffers(std::move(_indices));
    gl.delete_buffers(std::move(_normals));
    gl.delete_buffers(std::move(_positions));
    gl.delete_vertex_arrays(std::move(_vao));
}
//------------------------------------------------------------------------------
void shape_geometry::draw(execution_context&, video_context& ec) {
    draw_using_instructions(ec.gl_api(), view(_ops));
}
//------------------------------------------------------------------------------
} // namespace eagine::application
