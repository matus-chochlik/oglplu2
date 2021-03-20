/// @example application/040_metaballs/resources.cpp
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
#include <eagine/integer_range.hpp>
#include <eagine/shapes/cube.hpp>
#include <eagine/shapes/screen.hpp>
#include <oglplus/math/coordinates.hpp>
#include <oglplus/shapes/generator.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
// volume domain
//------------------------------------------------------------------------------
void volume_domain::init(example& e) {
    auto& [gl, GL] = e.video().gl_api();

    // vao
    gl.delete_vertex_arrays.later_by(e, _tetrahedrons);
    gl.gen_vertex_arrays() >> _tetrahedrons;
    gl.bind_vertex_array(_tetrahedrons);

    // corner positions
    // clang-format off
    const auto corner_data = GL.int_.array(
      0, 0, 0, // A
      1, 0, 0, // B
      0, 1, 0, // C
      1, 1, 0, // D
      0, 0, 1, // E
      1, 0, 1, // F
      0, 1, 1, // G
      1, 1, 1);// H
    // clang-format on

    gl.delete_buffers.later_by(e, _corners);
    gl.gen_buffers() >> _corners;
    gl.bind_buffer(GL.array_buffer, _corners);
    gl.buffer_data(GL.array_buffer, view(corner_data), GL.static_draw);
    gl.vertex_attrib_ipointer(corner_loc(), 3, GL.int_);
    gl.enable_vertex_attrib_array(corner_loc());

    // indices
    const unsigned A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7,
                   X = 255;
    // clang-format off
    const auto index_data = GL.unsigned_int_.array(
		A, B, D, H,
		B, A, F, H,
		E, A, G, H,
		E, F, A, H,
		A, C, G, H,
		C, A, D, H
	);
    // clang-format on

    gl.delete_buffers.later_by(e, _indices);
    gl.gen_buffers() >> _indices;
    gl.bind_buffer(GL.element_array_buffer, _indices);
    gl.buffer_data(GL.element_array_buffer, view(index_data), GL.static_draw);

    // field sample values
    gl.delete_buffers.later_by(e, _field);
    gl.gen_buffers() >> _field;
    gl.bind_buffer(GL.shader_storage_buffer, _field);
    gl.bind_buffer_base(GL.shader_storage_buffer, field_binding(), _field);
    gl.buffer_storage(GL.shader_storage_buffer, vertex_count() * 32);

    // metaball parameters
    gl.delete_buffers.later_by(e, _metaballs);
    gl.gen_buffers() >> _metaballs;
    gl.bind_buffer(GL.shader_storage_buffer, _metaballs);
    gl.bind_buffer_base(
      GL.shader_storage_buffer, metaballs_binding(), _metaballs);
    gl.buffer_storage(GL.shader_storage_buffer, 2048);
    gl.clear_buffer_sub_data(
      GL.shader_storage_buffer, 0, 1, oglp::gl_types::uint_type(0U));

    // tetrahedron cut configurations
    // clang-format off
    const auto config_data = GL.unsigned_int_.array(
		X, X, X, X,  X, X, X, X,
		A, C, B, X,  D, D, D, X,
		B, D, A, X,  C, C, C, X,
		B, B, A, A,  C, D, C, D,
		A, D, C, X,  B, B, B, X,
		A, A, C, C,  B, D, B, D,
		A, A, D, D,  C, B, C, B,
		A, A, A, X,  B, D, C, X,
		C, D, B, X,  A, A, A, X,
		C, C, B, B,  A, D, A, D,
		B, D, B, D,  C, C, A, A,
		B, B, B, X,  C, D, A, X,
		C, D, C, D,  A, A, B, B,
		C, C, C, X,  A, D, B, X,
		D, D, D, X,  A, B, C, X,
		X, X, X, X,  X, X, X, X);
    // clang-format on
    gl.delete_buffers.later_by(e, _configs);
    gl.gen_buffers() >> _configs;
    gl.bind_buffer(GL.shader_storage_buffer, _configs);
    gl.bind_buffer_base(GL.shader_storage_buffer, configs_binding(), _configs);
    gl.buffer_data(GL.shader_storage_buffer, view(config_data), GL.static_draw);
}
//------------------------------------------------------------------------------
void volume_domain::compute(example& e) {
    auto& gl = e.video().gl_api();
    const auto groups = plane_count() / 4;
    gl.dispatch_compute(groups, groups, groups);
}
//------------------------------------------------------------------------------
void volume_domain::draw(example& e) {
    auto& [gl, GL] = e.video().gl_api();
    gl.draw_elements_instanced(
      GL.lines_adjacency, 4 * 6, GL.unsigned_int_, nullptr, cube_count());
}
//------------------------------------------------------------------------------
// metaball program
//------------------------------------------------------------------------------
void metaball_program::init(example& e) {
    auto& gl = e.video().gl_api();

    gl.delete_program.later_by(e, _prog);
    gl.create_program() >> _prog;

    const auto prog_src{
      embed(EAGINE_ID(MBallProg), "metaballs_metaball.oglpprog")};
    gl.build_program(_prog, prog_src.unpack(e.ctx()));
    gl.use_program(_prog);
}
//------------------------------------------------------------------------------
void metaball_program::bind_metaballs(
  example& e,
  oglp::gl_types::uint_type binding) {
    auto& gl = e.video().gl_api();
    oglp::shader_storage_block_index blk_idx;
    gl.get_shader_storage_block_index(_prog, "MetaballBlock") >> blk_idx;
    gl.shader_storage_block_binding(_prog, blk_idx, binding);
}
//------------------------------------------------------------------------------
void metaball_program::prepare_frame(example&) {}
//------------------------------------------------------------------------------
void metaball_program::use(example& e) {
    e.video().gl_api().use_program(_prog);
}
//------------------------------------------------------------------------------
// field program
//------------------------------------------------------------------------------
void field_program::init(example& e) {
    auto& gl = e.video().gl_api();

    gl.delete_program.later_by(e, _prog);
    gl.create_program() >> _prog;

    const auto prog_src{
      embed(EAGINE_ID(FieldProg), "metaballs_field.oglpprog")};
    gl.build_program(_prog, prog_src.unpack(e.ctx()));
    gl.use_program(_prog);

    gl.get_uniform_location(_prog, "PlaneCount") >> _plane_count_loc;
}
//------------------------------------------------------------------------------
void field_program::bind_field(example& e, oglp::gl_types::uint_type binding) {
    auto& gl = e.video().gl_api();
    oglp::shader_storage_block_index blk_idx;
    gl.get_shader_storage_block_index(_prog, "FieldBlock") >> blk_idx;
    gl.shader_storage_block_binding(_prog, blk_idx, binding);
}
//------------------------------------------------------------------------------
void field_program::bind_metaballs(
  example& e,
  oglp::gl_types::uint_type binding) {
    auto& gl = e.video().gl_api();
    oglp::shader_storage_block_index blk_idx;
    gl.get_shader_storage_block_index(_prog, "MetaballBlock") >> blk_idx;
    gl.shader_storage_block_binding(_prog, blk_idx, binding);
}
//------------------------------------------------------------------------------
void field_program::set_plane_count(example& e, oglp::gl_types::int_type count) {
    e.video().gl_api().set_uniform(_prog, _plane_count_loc, count);
}
//------------------------------------------------------------------------------
void field_program::prepare_frame(example&) {}
//------------------------------------------------------------------------------
void field_program::use(example& e) {
    e.video().gl_api().use_program(_prog);
}
//------------------------------------------------------------------------------
// surface program
//------------------------------------------------------------------------------
void surface_program::init(example& e) {
    auto& gl = e.video().gl_api();

    gl.delete_program.later_by(e, _prog);
    gl.create_program() >> _prog;

    const auto prog_src{
      embed(EAGINE_ID(SurfProg), "metaballs_surface.oglpprog")};
    gl.build_program(_prog, prog_src.unpack(e.ctx()));
    gl.use_program(_prog);

    gl.get_uniform_location(_prog, "CameraMatrix") >> _camera_mat_loc;
    gl.get_uniform_location(_prog, "PerspectiveMatrix") >> _perspective_mat_loc;
    gl.get_uniform_location(_prog, "PlaneCount") >> _plane_count_loc;
    gl.get_uniform_location(_prog, "DivCount") >> _div_count_loc;
}
//------------------------------------------------------------------------------
void surface_program::prepare_frame(example& e) {
    e.video().gl_api().set_uniform(
      _prog, _camera_mat_loc, e.camera().transform_matrix());
    e.video().gl_api().set_uniform(
      _prog,
      _perspective_mat_loc,
      e.camera().perspective_matrix(e.video().surface_aspect()));
}
//------------------------------------------------------------------------------
void surface_program::bind_field(example& e, oglp::gl_types::uint_type binding) {
    auto& gl = e.video().gl_api();
    oglp::shader_storage_block_index blk_idx;
    gl.get_shader_storage_block_index(_prog, "FieldBlock") >> blk_idx;
    gl.shader_storage_block_binding(_prog, blk_idx, binding);
}
//------------------------------------------------------------------------------
void surface_program::bind_configs(
  example& e,
  oglp::gl_types::uint_type binding) {
    auto& gl = e.video().gl_api();
    oglp::shader_storage_block_index blk_idx;
    gl.get_shader_storage_block_index(_prog, "ConfigsBlock") >> blk_idx;
    gl.shader_storage_block_binding(_prog, blk_idx, binding);
}
//------------------------------------------------------------------------------
void surface_program::set_plane_count(
  example& e,
  oglp::gl_types::int_type count) {
    e.video().gl_api().set_uniform(_prog, _plane_count_loc, count);
}
//------------------------------------------------------------------------------
void surface_program::set_div_count(example& e, oglp::gl_types::int_type count) {
    e.video().gl_api().set_uniform(_prog, _div_count_loc, count);
}
//------------------------------------------------------------------------------
void surface_program::bind_corner_location(
  example& e,
  oglp::vertex_attrib_location loc) {
    e.video().gl_api().bind_attrib_location(_prog, loc, "Corner");
}
//------------------------------------------------------------------------------
void surface_program::use(example& e) {
    e.video().gl_api().use_program(_prog);
}
//------------------------------------------------------------------------------
} // namespace eagine::application
