/**
 *  example combined/016_torus/resources.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "resources.hpp"
#include "../example.hpp"
#include "../example/camera.hpp"

#include <eagine/shapes/torus.hpp>
#include <oglplus/shapes/generator.hpp>

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
// program
//------------------------------------------------------------------------------
void torus_program::init(example_context& ctx) {
    auto& cleanup = ctx.cleanup();
    auto& gl = ctx.gl();

    gl.create_program() >> prog;
    gl.delete_program.later_by(cleanup, prog);

    const auto prog_src{embed(EAGINE_ID(prog), "example.oglpprog")};
    gl.build_program(prog, prog_src.unpack(ctx.main()));
    gl.use_program(prog);

    gl.get_uniform_location(prog, "Camera") >> camera_loc;
}
//------------------------------------------------------------------------------
void torus_program::set_projection(
  const example_context& ctx, const example_orbiting_camera& camera) {
    ctx.gl().set_uniform(prog, camera_loc, camera.matrix(ctx.state()));
}
//------------------------------------------------------------------------------
void torus_program::bind_position_location(
  const example_context& ctx, vertex_attrib_location loc) {
    ctx.gl().bind_attrib_location(prog, loc, "Position");
}
//------------------------------------------------------------------------------
void torus_program::bind_normal_location(
  const example_context& ctx, vertex_attrib_location loc) {
    ctx.gl().bind_attrib_location(prog, loc, "Normal");
}
//------------------------------------------------------------------------------
void torus_program::bind_texcoord_location(
  const example_context& ctx, vertex_attrib_location loc) {
    ctx.gl().bind_attrib_location(prog, loc, "TexCoord");
}
//------------------------------------------------------------------------------
// geometry
//------------------------------------------------------------------------------
void torus_geometry::init(example_context& ctx) {
    auto& cleanup = ctx.cleanup();
    const auto& gl = ctx.gl();

    shape_generator shape(
      gl,
      shapes::unit_torus(
        shapes::vertex_attrib_kind::position |
        shapes::vertex_attrib_kind::normal |
        shapes::vertex_attrib_kind::wrap_coord));

    auto draw_var = shape.draw_variant(0);
    ops.resize(std_size(shape.operation_count(draw_var)));
    shape.instructions(ctx.gl(), draw_var, cover(ops));

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
      eagine::shapes::vertex_attrib_kind::position / 3,
      ctx.buffer());

    // normals
    gl.gen_buffers() >> normals;
    gl.delete_buffers.later_by(cleanup, normals);
    shape.attrib_setup(
      ctx.gl(),
      vao,
      normals,
      normal_loc(),
      eagine::shapes::vertex_attrib_kind::normal / 3,
      ctx.buffer());

    // texcoords
    gl.gen_buffers() >> texcoords;
    gl.delete_buffers.later_by(cleanup, texcoords);
    shape.attrib_setup(
      ctx.gl(),
      vao,
      texcoords,
      texcoord_loc(),
      eagine::shapes::vertex_attrib_kind::wrap_coord,
      ctx.buffer());

    // indices
    gl.gen_buffers() >> indices;
    gl.delete_buffers.later_by(cleanup, indices);
    shape.index_setup(ctx.gl(), indices, draw_var, ctx.buffer());
}
//------------------------------------------------------------------------------
void torus_geometry::draw(const example_context& ctx) {
    draw_using_instructions(ctx.gl(), view(ops));
}
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine
