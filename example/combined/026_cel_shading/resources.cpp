/**
 *  example combined/026_cel_shading/resources.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "resources.hpp"
#include "../example.hpp"
#include "../example/camera.hpp"

#include <eagine/shapes/icosahedron.hpp>
#include <oglplus/shapes/generator.hpp>

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
// program
//------------------------------------------------------------------------------
void cel_program::init(example_context& ctx) {
    auto& cleanup = ctx.cleanup();
    auto& gl = ctx.gl();

    gl.create_program() >> prog;
    gl.delete_program.later_by(cleanup, prog);
    gl.build_program(prog, embed(EAGINE_ID(prog), "example.oglpprog"));
    gl.use_program(prog);

    gl.get_uniform_location(prog, "Projection") >> projection_loc;
    gl.get_uniform_location(prog, "Modelview") >> modelview_loc;
}
//------------------------------------------------------------------------------
void cel_program::set_projection(
  const example_context& ctx, const example_orbiting_camera& camera) {
    auto& state = ctx.state();
    ctx.gl().set_uniform(prog, projection_loc, camera.matrix(state));
}
//------------------------------------------------------------------------------
void cel_program::set_modelview(const example_context& ctx) {
    shp_turns += 0.1F * ctx.state().frame_duration().value();

    ctx.gl().set_uniform(
      prog,
      modelview_loc,
      matrix_rotation_x(turns_(shp_turns) / 1) *
        matrix_rotation_y(turns_(shp_turns) / 2) *
        matrix_rotation_z(turns_(shp_turns) / 3));
}
//------------------------------------------------------------------------------
void cel_program::bind_position_location(
  const example_context& ctx, vertex_attrib_location loc) {
    ctx.gl().bind_attrib_location(prog, loc, "Position");
}
//------------------------------------------------------------------------------
// geometry
//------------------------------------------------------------------------------
void icosahedron_geometry::init(example_context& ctx) {
    auto& cleanup = ctx.cleanup();
    const auto& gl = ctx.gl();

    shape_generator shape(
      gl, shapes::unit_icosahedron(shapes::vertex_attrib_kind::position));

    ops.resize(std_size(shape.operation_count()));
    shape.instructions(ctx.gl(), cover(ops));

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
      eagine::shapes::vertex_attrib_kind::position,
      ctx.buffer());

    // indices
    gl.gen_buffers() >> indices;
    gl.delete_buffers.later_by(cleanup, indices);
    shape.index_setup(ctx.gl(), indices, ctx.buffer());
}
//------------------------------------------------------------------------------
void icosahedron_geometry::draw(const example_context& ctx) {
    draw_using_instructions(ctx.gl(), view(ops));
}
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine
