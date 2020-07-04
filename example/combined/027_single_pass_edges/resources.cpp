/**
 *  example combined/027_single_pass_edges/resources.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "resources.hpp"
#include "../example.hpp"
#include "../example/camera.hpp"

#include <eagine/shapes/array.hpp>
#include <eagine/shapes/centered.hpp>
#include <eagine/shapes/icosahedron.hpp>
#include <eagine/shapes/scaled.hpp>
#include <oglplus/shapes/generator.hpp>

namespace eagine::oglp {
//------------------------------------------------------------------------------
// program
//------------------------------------------------------------------------------
void edges_program::init(example_context& ctx) {
    auto& cleanup = ctx.cleanup();
    auto& gl = ctx.gl();

    gl.create_program() >> prog;
    gl.delete_program.later_by(cleanup, prog);

    const auto prog_src{embed(EAGINE_ID(prog), "example.oglpprog")};
    gl.build_program(prog, prog_src.unpack(ctx.main()));
    gl.use_program(prog);

    gl.get_uniform_location(prog, "Projection") >> camera_loc;
    gl.get_uniform_location(prog, "ViewportDimensions") >> vp_dim_loc;
}
//------------------------------------------------------------------------------
void edges_program::set_projection(
  const example_context& ctx, const example_orbiting_camera& camera) {
    auto& state = ctx.state();
    ctx.gl().set_uniform(prog, camera_loc, camera.matrix(state));
    ctx.gl().set_uniform(prog, vp_dim_loc, vec2(state.width(), state.height()));
}
//------------------------------------------------------------------------------
void edges_program::bind_position_location(
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
      gl,
      shapes::center(eagine::shapes::ortho_array_xyz(
        shapes::scale(
          shapes::unit_icosahedron(shapes::vertex_attrib_kind::position),
          {0.5F, 0.5F, 0.5F}),
        {1.F, 1.F, 1.F},
        {3, 3, 3})));

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
} // namespace eagine::oglp
