/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "resources.hpp"

#include <eagine/application/camera.hpp>
#include <eagine/application/context.hpp>
#include <eagine/embed.hpp>
#include <eagine/shapes/torus.hpp>
#include <oglplus/glsl/string_ref.hpp>
#include <oglplus/shapes/generator.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
// program
//------------------------------------------------------------------------------
void torus_program::init(execution_context& ec, video_context& vc) {
    auto& gl = vc.gl_api();

    gl.create_program() >> prog;

    const auto prog_src{embed(EAGINE_ID(prog), "example.oglpprog")};
    gl.build_program(prog, prog_src.unpack(ec));
    gl.use_program(prog);

    gl.get_uniform_location(prog, "Camera") >> camera_loc;
}
//------------------------------------------------------------------------------
void torus_program::cleanup(video_context& vc) {
    auto& gl = vc.gl_api();
    gl.delete_program(std::move(prog));
}
//------------------------------------------------------------------------------
void torus_program::set_projection(video_context& vc, orbiting_camera& camera) {
    if(camera.has_changed()) {
        auto& gl = vc.gl_api();
        gl.set_uniform(prog, camera_loc, camera.matrix(vc.surface_aspect()));
    }
}
//------------------------------------------------------------------------------
void torus_program::bind_position_location(
  video_context& vc,
  oglp::vertex_attrib_location loc) {
    auto& gl = vc.gl_api();
    gl.bind_attrib_location(prog, loc, "Position");
}
//------------------------------------------------------------------------------
void torus_program::bind_normal_location(
  video_context& vc,
  oglp::vertex_attrib_location loc) {
    auto& gl = vc.gl_api();
    gl.bind_attrib_location(prog, loc, "Normal");
}
//------------------------------------------------------------------------------
void torus_program::bind_texcoord_location(
  video_context& vc,
  oglp::vertex_attrib_location loc) {
    auto& gl = vc.gl_api();
    gl.bind_attrib_location(prog, loc, "TexCoord");
}
//------------------------------------------------------------------------------
// geometry
//------------------------------------------------------------------------------
void torus_geometry::init(execution_context& ec, video_context& vc) {
    const auto& glapi = vc.gl_api();
    const auto& gl = glapi;

    oglp::shape_generator shape(
      glapi,
      shapes::unit_torus(
        shapes::vertex_attrib_kind::position |
        shapes::vertex_attrib_kind::normal |
        shapes::vertex_attrib_kind::wrap_coord));

    auto draw_var = shape.draw_variant(0);
    ops.resize(std_size(shape.operation_count(draw_var)));
    shape.instructions(glapi, draw_var, cover(ops));

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
      eagine::shapes::vertex_attrib_kind::position / 3,
      ec.buffer());

    // normals
    gl.gen_buffers() >> normals;
    shape.attrib_setup(
      glapi,
      vao,
      normals,
      normal_loc(),
      eagine::shapes::vertex_attrib_kind::normal / 3,
      ec.buffer());

    // texcoords
    gl.gen_buffers() >> texcoords;
    shape.attrib_setup(
      glapi,
      vao,
      texcoords,
      texcoord_loc(),
      eagine::shapes::vertex_attrib_kind::wrap_coord,
      ec.buffer());

    // indices
    gl.gen_buffers() >> indices;
    shape.index_setup(glapi, indices, draw_var, ec.buffer());
}
//------------------------------------------------------------------------------
void torus_geometry::cleanup(video_context& vc) {
    const auto& gl = vc.gl_api();
    gl.delete_buffers(std::move(indices));
    gl.delete_buffers(std::move(texcoords));
    gl.delete_buffers(std::move(normals));
    gl.delete_buffers(std::move(positions));
    gl.delete_vertex_arrays(std::move(vao));
}
//------------------------------------------------------------------------------
void torus_geometry::draw(execution_context&, video_context& ec) {
    draw_using_instructions(ec.gl_api(), view(ops));
}
//------------------------------------------------------------------------------
} // namespace eagine::application
