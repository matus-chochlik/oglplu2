/// @example application/028_compute_particles/resources.cpp
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
// particles
//------------------------------------------------------------------------------
void particles::init(example& e) {
    auto& [gl, GL] = e.video().gl_api();

    // vao
    gl.gen_vertex_arrays() >> _vao;
    gl.bind_vertex_array(_vao);

    // origin
    const auto origin_data = GL.float_.array(0.F, 0.F, 0.F);

    gl.delete_buffers.later_by(e, _origin);
    gl.gen_buffers() >> _origin;
    gl.bind_buffer(GL.array_buffer, _origin);
    gl.buffer_data(GL.array_buffer, view(origin_data), GL.static_draw);
    gl.vertex_attrib_pointer(origin_loc(), 3, GL.float_, GL.false_);
    gl.enable_vertex_attrib_array(origin_loc());

    // cursors
    const auto cursor_values = GL.unsigned_int_.array(0U, 0U);

    gl.gen_buffers() >> _cursors;
    gl.bind_buffer(GL.atomic_counter_buffer, _cursors);
    gl.bind_buffer_base(GL.atomic_counter_buffer, cursors_binding(), _cursors);
    gl.buffer_data(
      GL.atomic_counter_buffer, view(cursor_values), GL.dynamic_draw);

    //
    std::vector<oglp::gl_types::float_type> init_data;
    // random
    init_data.resize(std_size(_count * 16));
    e.ctx().random_uniform_01(cover(init_data));

    gl.delete_buffers.later_by(e, _random);
    gl.gen_buffers() >> _random;
    gl.bind_buffer(GL.shader_storage_buffer, _random);
    gl.bind_buffer_base(GL.shader_storage_buffer, random_binding(), _random);
    gl.buffer_data(GL.shader_storage_buffer, view(init_data), GL.static_draw);

    // offsets
    init_data.resize(std_size(_count * 4));
    fill(cover(init_data), 0.F);
    gl.delete_buffers.later_by(e, _offsets);
    gl.gen_buffers() >> _offsets;
    gl.bind_buffer(GL.shader_storage_buffer, _offsets);
    gl.bind_buffer_base(GL.shader_storage_buffer, offsets_binding(), _offsets);
    gl.buffer_data(GL.shader_storage_buffer, view(init_data), GL.dynamic_draw);

    // velocities
    init_data.resize(std_size(_count * 4));
    fill(cover(init_data), 0.F);
    gl.delete_buffers.later_by(e, _velocities);
    gl.gen_buffers() >> _velocities;
    gl.bind_buffer(GL.shader_storage_buffer, _velocities);
    gl.bind_buffer_base(
      GL.shader_storage_buffer, velocities_binding(), _velocities);
    gl.buffer_data(GL.shader_storage_buffer, view(init_data), GL.dynamic_draw);

    // ages
    init_data.resize(std_size(_count));
    fill(cover(init_data), 1.F);
    gl.delete_buffers.later_by(e, _ages);
    gl.gen_buffers() >> _ages;
    gl.bind_buffer(GL.shader_storage_buffer, _ages);
    gl.bind_buffer_base(GL.shader_storage_buffer, ages_binding(), _ages);
    gl.buffer_data(GL.shader_storage_buffer, view(init_data), GL.dynamic_draw);
}
//------------------------------------------------------------------------------
void particles::emit(example& e) {
    auto& [gl, GL] = e.video().gl_api();

    const auto cursor_values = GL.unsigned_int_.array(0U);
    gl.buffer_sub_data(GL.atomic_counter_buffer, 0, view(cursor_values));
    gl.dispatch_compute(_count, 1, 1);
}
//------------------------------------------------------------------------------
void particles::draw(example& e) {
    auto& [gl, GL] = e.video().gl_api();
    gl.draw_arrays_instanced(GL.points, 0, 1, _count);
}
//------------------------------------------------------------------------------
// emit program
//------------------------------------------------------------------------------
void emit_program::init(example& e) {
    auto& gl = e.video().gl_api();

    gl.delete_program.later_by(e, _prog);
    gl.create_program() >> _prog;

    const auto prog_src{embed(EAGINE_ID(EmitProg), "emit_prog.oglpprog")};
    gl.build_program(_prog, prog_src.unpack(e.ctx()));
    gl.use_program(_prog);

    gl.get_uniform_location(_prog, "emitPosition") >> _emit_position_loc;
    gl.get_uniform_location(_prog, "deltaTime") >> _delta_time_loc;
}
//------------------------------------------------------------------------------
void emit_program::prepare_frame(example& e) {
    auto& gl = e.video().gl_api();
    gl.set_uniform(_prog, _emit_position_loc, e.emit_position());
    gl.set_uniform(_prog, _delta_time_loc, e.frame_duration());
}
//------------------------------------------------------------------------------
void emit_program::bind_random(example& e, oglp::gl_types::uint_type binding) {
    auto& gl = e.video().gl_api();
    oglp::shader_storage_block_index blk_idx;
    gl.get_shader_storage_block_index(_prog, "RandomBlock") >> blk_idx;
    gl.shader_storage_block_binding(_prog, blk_idx, binding);
}
//------------------------------------------------------------------------------
void emit_program::bind_offsets(example& e, oglp::gl_types::uint_type binding) {
    auto& gl = e.video().gl_api();
    oglp::shader_storage_block_index blk_idx;
    gl.get_shader_storage_block_index(_prog, "OffsetBlock") >> blk_idx;
    gl.shader_storage_block_binding(_prog, blk_idx, binding);
}
//------------------------------------------------------------------------------
void emit_program::bind_velocities(
  example& e,
  oglp::gl_types::uint_type binding) {
    auto& gl = e.video().gl_api();
    oglp::shader_storage_block_index blk_idx;
    gl.get_shader_storage_block_index(_prog, "VelocityBlock") >> blk_idx;
    gl.shader_storage_block_binding(_prog, blk_idx, binding);
}
//------------------------------------------------------------------------------
void emit_program::bind_ages(example& e, oglp::gl_types::uint_type binding) {
    auto& gl = e.video().gl_api();
    oglp::shader_storage_block_index blk_idx;
    gl.get_shader_storage_block_index(_prog, "AgeBlock") >> blk_idx;
    gl.shader_storage_block_binding(_prog, blk_idx, binding);
}
//------------------------------------------------------------------------------
void emit_program::use(example& e) {
    e.video().gl_api().use_program(_prog);
}
//------------------------------------------------------------------------------
// draw program
//------------------------------------------------------------------------------
void draw_program::init(example& e) {
    auto& gl = e.video().gl_api();

    gl.delete_program.later_by(e, _prog);
    gl.create_program() >> _prog;

    const auto prog_src{embed(EAGINE_ID(DrawProg), "draw_prog.oglpprog")};
    gl.build_program(_prog, prog_src.unpack(e.ctx()));
    gl.use_program(_prog);

    gl.get_uniform_location(_prog, "ProjectionMatrix") >> _projection_mat_loc;
    gl.get_uniform_location(_prog, "PerspectiveMatrix") >> _perspective_mat_loc;
}
//------------------------------------------------------------------------------
void draw_program::prepare_frame(example& e) {
    e.video().gl_api().set_uniform(
      _prog, _projection_mat_loc, e.camera().projection_matrix());
    e.video().gl_api().set_uniform(
      _prog,
      _perspective_mat_loc,
      e.camera().perspective_matrix(e.video().surface_aspect()));
}
//------------------------------------------------------------------------------
void draw_program::bind_origin_location(
  example& e,
  oglp::vertex_attrib_location loc) {
    e.video().gl_api().bind_attrib_location(_prog, loc, "Origin");
}
//------------------------------------------------------------------------------
void draw_program::bind_offsets(example& e, oglp::gl_types::uint_type binding) {
    auto& gl = e.video().gl_api();
    oglp::shader_storage_block_index blk_idx;
    gl.get_shader_storage_block_index(_prog, "OffsetBlock") >> blk_idx;
    gl.shader_storage_block_binding(_prog, blk_idx, binding);
}
//------------------------------------------------------------------------------
void draw_program::bind_ages(example& e, oglp::gl_types::uint_type binding) {
    auto& gl = e.video().gl_api();
    oglp::shader_storage_block_index blk_idx;
    gl.get_shader_storage_block_index(_prog, "AgeBlock") >> blk_idx;
    gl.shader_storage_block_binding(_prog, blk_idx, binding);
}
//------------------------------------------------------------------------------
void draw_program::use(example& e) {
    e.video().gl_api().use_program(_prog);
}
//------------------------------------------------------------------------------
} // namespace eagine::application
