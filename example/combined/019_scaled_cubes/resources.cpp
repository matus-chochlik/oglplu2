/**
 *  example combined/019_scaled_cubes/resources.cpp
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
#include <eagine/shapes/cube.hpp>
#include <eagine/shapes/reboxed.hpp>
#include <oglplus/math/coordinates.hpp>
#include <oglplus/math/interpolate.hpp>
#include <oglplus/shapes/generator.hpp>

namespace eagine::oglp {
//------------------------------------------------------------------------------
// program
//------------------------------------------------------------------------------
void cubes_program::init(example_context& ctx) {
    auto& cleanup = ctx.cleanup();
    auto& gl = ctx.gl();

    gl.create_program() >> prog;
    gl.delete_program.later_by(cleanup, prog);

    const auto prog_src{embed(EAGINE_ID(prog), "example.oglpprog")};
    gl.build_program(prog, prog_src.unpack(ctx.main()));
    gl.use_program(prog);

    gl.get_uniform_location(prog, "Camera") >> camera_loc;
    gl.get_uniform_location(prog, "Center") >> center_loc;
    gl.get_uniform_location(prog, "Time") >> time_loc;
    gl.get_uniform_location(prog, "Edges") >> edges_loc;
}
//------------------------------------------------------------------------------
void cubes_program::set_projection(
  const example_context& ctx, const example_orbiting_camera& camera) {
    ctx.gl().set_uniform(prog, camera_loc, camera.matrix(ctx.state()));
}
//------------------------------------------------------------------------------
void cubes_program::update(const example_context& ctx) {
    const auto t = ctx.state().exec_time().value();
    ctx.gl().set_uniform(
      prog,
      center_loc,
      to_cartesian(unit_spherical_coordinates(
        turns_(t / 3.F),
        smooth_lerp(right_angles_(1.F), right_angles_(-1.F), t / 5.F))) *
        smooth_lerp(0.F, 10.F, t / 7.F));
    ctx.gl().set_uniform(prog, time_loc, t);
}
//------------------------------------------------------------------------------
void cubes_program::bind_position_location(
  const example_context& ctx, vertex_attrib_location loc) {
    ctx.gl().bind_attrib_location(prog, loc, "Position");
}
//------------------------------------------------------------------------------
void cubes_program::bind_pivot_location(
  const example_context& ctx, vertex_attrib_location loc) {
    ctx.gl().bind_attrib_location(prog, loc, "Pivot");
}
//------------------------------------------------------------------------------
void cubes_program::bind_coord_location(
  const example_context& ctx, vertex_attrib_location loc) {
    ctx.gl().bind_attrib_location(prog, loc, "Coord");
}
//------------------------------------------------------------------------------
void cubes_program::drawing_surface(const example_context& ctx) {
    ctx.gl().set_uniform(prog, edges_loc, 0.F);
}
//------------------------------------------------------------------------------
void cubes_program::drawing_edges(const example_context& ctx) {
    ctx.gl().set_uniform(prog, edges_loc, 1.F);
}
//------------------------------------------------------------------------------
// geometry
//------------------------------------------------------------------------------
void cubes_geometry::init(example_context& ctx) {
    auto& cleanup = ctx.cleanup();
    const auto& gl = ctx.gl();

    shape_generator shape(
      gl,
      shapes::rebox(shapes::center(eagine::shapes::ortho_array_xyz(
        shapes::unit_cube(
          shapes::vertex_attrib_kind::position |
          shapes::vertex_attrib_kind::pivot |
          shapes::vertex_attrib_kind::box_coord),
        {1.F, 1.F, 1.F},
        {10, 10, 10}))));

    std::array<shapes::drawing_variant, 2> vars{
      shape.draw_variant(0), shape.draw_variant(1)};

    ops.resize(std_size(shape.operation_count(view(vars))));
    shape.instructions(ctx.gl(), view(vars), cover(subs), cover(ops));

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

    // pivots
    gl.gen_buffers() >> pivots;
    gl.delete_buffers.later_by(cleanup, pivots);
    shape.attrib_setup(
      ctx.gl(),
      vao,
      pivots,
      pivot_loc(),
      eagine::shapes::vertex_attrib_kind::pivot,
      ctx.buffer());

    // coords
    gl.gen_buffers() >> coords;
    gl.delete_buffers.later_by(cleanup, coords);
    shape.attrib_setup(
      ctx.gl(),
      vao,
      coords,
      coord_loc(),
      eagine::shapes::vertex_attrib_kind::box_coord,
      ctx.buffer());

    // indices
    gl.gen_buffers() >> indices;
    gl.delete_buffers.later_by(cleanup, indices);
    shape.index_setup(ctx.gl(), indices, view(vars), ctx.buffer());
}
//------------------------------------------------------------------------------
void cubes_geometry::draw_surface(const example_context& ctx) {
    draw_using_instructions(ctx.gl(), view(ops), subs[0]);
}
//------------------------------------------------------------------------------
void cubes_geometry::draw_edges(const example_context& ctx) {
    draw_using_instructions(ctx.gl(), view(ops), subs[1]);
}
//------------------------------------------------------------------------------
} // namespace eagine::oglp
