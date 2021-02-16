/// @file
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
#include <eagine/shapes/to_patches.hpp>
#include <oglplus/shapes/generator.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
// program
//------------------------------------------------------------------------------
void sphere_program::init(execution_context& ec, video_context& vc) {
    const auto& glapi = vc.gl_api();
    const auto& gl = glapi;

    gl.create_program() >> prog;

    const auto prog_src{embed(EAGINE_ID(TessProg), "tessellation_prog")};
    gl.build_program(prog, prog_src.unpack(ec));
    gl.use_program(prog);

    gl.get_uniform_location(prog, "CameraMatrix") >> camera_matrix_loc;
    gl.get_uniform_location(prog, "CameraPosition") >> camera_position_loc;
    gl.get_uniform_location(prog, "ViewportDimensions") >> viewport_dim_loc;
    gl.get_uniform_block_index(prog, "OffsetBlock") >> offset_blk_idx;
}
//------------------------------------------------------------------------------
void sphere_program::clean_up(video_context& vc) {
    vc.gl_api().delete_program(std::move(prog));
}
//------------------------------------------------------------------------------
void sphere_program::set_projection(video_context& vc, orbiting_camera& camera) {
    const auto [width, height] = vc.surface_size();
    const auto& gl = vc.gl_api();
    gl.set_uniform(prog, camera_position_loc, camera.position());
    gl.set_uniform(prog, camera_matrix_loc, camera.matrix(vc));
    gl.set_uniform(prog, viewport_dim_loc, oglp::vec2(width, height));
}
//------------------------------------------------------------------------------
void sphere_program::bind_position_location(
  video_context& vc,
  oglp::vertex_attrib_location loc) {
    vc.gl_api().bind_attrib_location(prog, loc, "Position");
}
//------------------------------------------------------------------------------
void sphere_program::bind_offsets_block(
  video_context& vc,
  oglp::gl_types::uint_type binding) {
    vc.gl_api().uniform_block_binding(prog, offset_blk_idx, binding);
}
//------------------------------------------------------------------------------
// geometry
//------------------------------------------------------------------------------
void icosahedron_geometry::init(execution_context& ec, video_context& vc) {
    const auto& glapi = vc.gl_api();
    const auto& [gl, GL] = glapi;

    oglp::shape_generator shape(
      glapi,
      shapes::to_patches(
        shapes::unit_icosahedron(shapes::vertex_attrib_kind::position)));

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

    // offsets
    const float d = 4.2F;
    const float h = float(count - 1) * 0.5F;

    std::vector<oglp::gl_types::float_type> offset_data;
    offset_data.resize(std_size(count * count * count * 4));
    ec.random_normal(cover(offset_data));
    auto p = offset_data.begin();

    for(int k = 0; k != count; ++k) {
        const float z = (float(k) - h) * d;
        for(int j = 0; j != count; ++j) {
            const float y = (float(j) - h) * d;
            for(int i = 0; i != count; ++i) {
                const float x = (float(i) - h) * d;
                *p++ += x;
                *p++ += y;
                *p++ += z;
                *p++ = 0.F;
            }
        }
    }

    gl.gen_buffers() >> offsets;
    gl.bind_buffer(GL.uniform_buffer, offsets);
    gl.bind_buffer_base(GL.uniform_buffer, 0, offsets);
    gl.buffer_data(GL.uniform_buffer, view(offset_data), GL.static_draw);
}
//------------------------------------------------------------------------------
void icosahedron_geometry::clean_up(video_context& vc) {
    const auto& gl = vc.gl_api();
    gl.delete_buffers(std::move(offsets));
    gl.delete_buffers(std::move(indices));
    gl.delete_buffers(std::move(positions));
    gl.delete_vertex_arrays(std::move(vao));
}
//------------------------------------------------------------------------------
void icosahedron_geometry::draw(video_context& vc) {
    draw_instanced_using_instructions(
      vc.gl_api(), view(ops), count * count * count);
}
//------------------------------------------------------------------------------
} // namespace eagine::application
