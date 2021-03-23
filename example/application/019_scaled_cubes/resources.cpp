/// @example application/019_scaled_cubes/resources.cpp
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
#include <eagine/shapes/array.hpp>
#include <eagine/shapes/centered.hpp>
#include <eagine/shapes/cube.hpp>
#include <eagine/shapes/reboxed.hpp>
#include <oglplus/math/coordinates.hpp>
#include <oglplus/math/interpolate.hpp>
#include <oglplus/shapes/generator.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
// program
//------------------------------------------------------------------------------
void cubes_program::init(execution_context& ec, video_context& vc) {
    auto& gl = vc.gl_api();

    gl.create_program() >> prog;

    const auto prog_src{embed(EAGINE_ID(prog), "scaled_cubes.oglpprog")};
    gl.build_program(prog, prog_src.unpack(ec));
    gl.use_program(prog);

    gl.get_uniform_location(prog, "Camera") >> camera_loc;
    gl.get_uniform_location(prog, "Center") >> center_loc;
    gl.get_uniform_location(prog, "Time") >> time_loc;
    gl.get_uniform_location(prog, "Edges") >> edges_loc;
}
//------------------------------------------------------------------------------
void cubes_program::clean_up(video_context& vc) {
    auto& gl = vc.gl_api();
    gl.delete_program(std::move(prog));
}
//------------------------------------------------------------------------------
void cubes_program::set_projection(video_context& vc, orbiting_camera& camera) {
    if(camera.has_changed()) {
        vc.gl_api().set_uniform(
          prog, camera_loc, camera.matrix(vc.surface_aspect()));
    }
}
//------------------------------------------------------------------------------
void cubes_program::update(execution_context& ec, video_context& vc) {
    const auto t = ec.state().frame_time().value();
    const auto& glapi = vc.gl_api();
    glapi.set_uniform(
      prog,
      center_loc,
      oglp::to_cartesian(oglp::unit_spherical_coordinate(
        turns_(t / 3.F),
        oglp::smooth_lerp(right_angles_(1.F), right_angles_(-1.F), t / 5.F))) *
        oglp::smooth_lerp(0.F, 10.F, t / 7.F));
    glapi.set_uniform(prog, time_loc, t);
}
//------------------------------------------------------------------------------
void cubes_program::bind_position_location(
  video_context& vc,
  oglp::vertex_attrib_location loc) {
    vc.gl_api().bind_attrib_location(prog, loc, "Position");
}
//------------------------------------------------------------------------------
void cubes_program::bind_pivot_location(
  video_context& vc,
  oglp::vertex_attrib_location loc) {
    vc.gl_api().bind_attrib_location(prog, loc, "Pivot");
}
//------------------------------------------------------------------------------
void cubes_program::bind_coord_location(
  video_context& vc,
  oglp::vertex_attrib_location loc) {
    vc.gl_api().bind_attrib_location(prog, loc, "Coord");
}
//------------------------------------------------------------------------------
void cubes_program::drawing_surface(video_context& vc) {
    vc.gl_api().set_uniform(prog, edges_loc, 0.F);
}
//------------------------------------------------------------------------------
void cubes_program::drawing_edges(video_context& vc) {
    vc.gl_api().set_uniform(prog, edges_loc, 1.F);
}
//------------------------------------------------------------------------------
// geometry
//------------------------------------------------------------------------------
void cubes_geometry::init(execution_context& ec, video_context& vc) {
    const auto& glapi = vc.gl_api();
    const auto& gl = glapi;

    oglp::shape_generator shape(
      glapi,
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
    shape.instructions(glapi, view(vars), cover(subs), cover(ops));

    // vao
    gl.gen_vertex_arrays() >> vao;
    gl.bind_vertex_array(vao);

    // positions
    gl.gen_buffers() >> positions;
    shape.attrib_setup(
      glapi,
      vao,
      positions,
      position_loc(),
      eagine::shapes::vertex_attrib_kind::position,
      ec.buffer());

    // pivots
    gl.gen_buffers() >> pivots;
    shape.attrib_setup(
      glapi,
      vao,
      pivots,
      pivot_loc(),
      eagine::shapes::vertex_attrib_kind::pivot,
      ec.buffer());

    // coords
    gl.gen_buffers() >> coords;
    shape.attrib_setup(
      glapi,
      vao,
      coords,
      coord_loc(),
      eagine::shapes::vertex_attrib_kind::box_coord,
      ec.buffer());

    // indices
    gl.gen_buffers() >> indices;
    shape.index_setup(glapi, indices, view(vars), ec.buffer());
}
//------------------------------------------------------------------------------
void cubes_geometry::clean_up(video_context& vc) {
    auto& gl = vc.gl_api();
    gl.delete_buffers(std::move(indices));
    gl.delete_buffers(std::move(coords));
    gl.delete_buffers(std::move(pivots));
    gl.delete_buffers(std::move(positions));
    gl.delete_vertex_arrays(std::move(vao));
}
//------------------------------------------------------------------------------
void cubes_geometry::draw_surface(video_context& vc) {
    draw_using_instructions(vc.gl_api(), view(ops), subs[0]);
}
//------------------------------------------------------------------------------
void cubes_geometry::draw_edges(video_context& vc) {
    draw_using_instructions(vc.gl_api(), view(ops), subs[1]);
}
//------------------------------------------------------------------------------
} // namespace eagine::application
