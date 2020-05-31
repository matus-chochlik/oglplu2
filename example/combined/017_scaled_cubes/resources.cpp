/**
 *  example combined/017_scaled_cubes/resources.cpp
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

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
// program
//------------------------------------------------------------------------------
void cubes_program::init(example_context& ctx) {
    auto& cleanup = ctx.cleanup();
    auto& gl = ctx.gl();

    gl.create_program() >> prog;
    gl.delete_program.later_by(cleanup, prog);
    gl.build_program(prog, embed(EAGINE_ID(prog), "example.oglpprog"));
    gl.use_program(prog);

    gl.get_uniform_location(prog, "Camera") >> camera_loc;
    gl.get_uniform_location(prog, "Center") >> center_loc;
    gl.get_uniform_location(prog, "Time") >> time_loc;
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
        turns_(t / 3.f),
        smooth_lerp(right_angles_(1.f), right_angles_(-1.f), t / 5.f))) *
        smooth_lerp(0.f, 10.f, t / 7.f));
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
        {1.f, 1.f, 1.f},
        {10, 10, 10}))));

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
    shape.index_setup(ctx.gl(), indices, ctx.buffer());
}
//------------------------------------------------------------------------------
void cubes_geometry::draw(const example_context& ctx) {
    draw_using_instructions(ctx.gl(), view(ops));
}
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine
