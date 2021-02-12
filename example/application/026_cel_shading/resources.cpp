/// .file application/026_cel_shading/resources.cpp
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
#include <eagine/shapes/icosahedron.hpp>
#include <oglplus/shapes/generator.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
// program
//------------------------------------------------------------------------------
void cel_program::init(execution_context& ec, video_context& vc) {
    auto& gl = vc.gl_api();

    gl.create_program() >> prog;

    const auto prog_src{embed(EAGINE_ID(prog), "cel_shading_prog")};
    gl.build_program(prog, prog_src.unpack(ec));
    gl.use_program(prog);

    gl.get_uniform_location(prog, "Projection") >> projection_loc;
    gl.get_uniform_location(prog, "Modelview") >> modelview_loc;
}
//------------------------------------------------------------------------------
void cel_program::clean_up(video_context& vc) {
    auto& gl = vc.gl_api();
    gl.delete_program(std::move(prog));
}
//------------------------------------------------------------------------------
void cel_program::set_projection(video_context& vc, orbiting_camera& camera) {
    if(camera.has_changed()) {
        vc.gl_api().set_uniform(prog, projection_loc, camera.matrix(vc));
    }
}
//------------------------------------------------------------------------------
void cel_program::set_modelview(execution_context& ec, video_context& vc) {
    shp_turns += 0.1F * ec.state().frame_duration().value();

    vc.gl_api().set_uniform(
      prog,
      modelview_loc,
      oglp::matrix_rotation_x(turns_(shp_turns) / 1) *
        oglp::matrix_rotation_y(turns_(shp_turns) / 2) *
        oglp::matrix_rotation_z(turns_(shp_turns) / 3));
}
//------------------------------------------------------------------------------
void cel_program::bind_position_location(
  video_context& vc,
  oglp::vertex_attrib_location loc) {
    vc.gl_api().bind_attrib_location(prog, loc, "Position");
}
//------------------------------------------------------------------------------
// geometry
//------------------------------------------------------------------------------
void icosahedron_geometry::init(execution_context& ec, video_context& vc) {
    const auto& glapi = vc.gl_api();
    const auto& gl = glapi;

    oglp::shape_generator shape(
      gl, shapes::unit_icosahedron(shapes::vertex_attrib_kind::position));

    ops.resize(std_size(shape.operation_count()));
    shape.instructions(glapi, cover(ops));

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

    // indices
    gl.gen_buffers() >> indices;
    shape.index_setup(glapi, indices, ec.buffer());
}
//------------------------------------------------------------------------------
void icosahedron_geometry::clean_up(video_context& vc) {
    auto& gl = vc.gl_api();
    gl.delete_buffers(std::move(indices));
    gl.delete_buffers(std::move(positions));
    gl.delete_vertex_arrays(std::move(vao));
}
//------------------------------------------------------------------------------
void icosahedron_geometry::draw(video_context& vc) {
    draw_using_instructions(vc.gl_api(), view(ops));
}
//------------------------------------------------------------------------------
} // namespace eagine::application
