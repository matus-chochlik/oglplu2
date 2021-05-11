/// @example application/023_sketch/resources.cpp
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
#include <eagine/shapes/adjacency.hpp>
#include <eagine/shapes/twisted_torus.hpp>
#include <oglplus/glsl/string_ref.hpp>
#include <oglplus/math/matrix_ctrs.hpp>
#include <oglplus/shapes/generator.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
// sketch program
//------------------------------------------------------------------------------
void sketch_program::init(execution_context& ec, video_context& vc) {
    auto& gl = vc.gl_api();

    gl.create_program() >> _prog;

    const auto prog_src{embed(EAGINE_ID(SketchProg), "sketch.oglpprog")};
    gl.build_program(_prog, prog_src.unpack(ec));
    gl.use_program(_prog);

    gl.get_uniform_location(_prog, "Model") >> _model_loc;
    gl.get_uniform_location(_prog, "View") >> _view_loc;
    gl.get_uniform_location(_prog, "Projection") >> _projection_loc;
    gl.get_uniform_location(_prog, "viewportDimensions") >> _vp_dim_loc;
}
//------------------------------------------------------------------------------
void sketch_program::clean_up(video_context& vc) {
    auto& gl = vc.gl_api();
    gl.delete_program(std::move(_prog));
}
//------------------------------------------------------------------------------
void sketch_program::prepare_frame(
  video_context& vc,
  orbiting_camera& camera,
  float t) {
    const auto [width, height] = vc.surface_size();
    auto& gl = vc.gl_api();
    gl.use_program(_prog);
    gl.set_uniform(
      _prog, _model_loc, oglp::matrix_rotation_x(right_angles_(t * 0.125F))());
    gl.set_uniform(_prog, _view_loc, camera.transform_matrix());
    gl.set_uniform(
      _prog, _projection_loc, camera.perspective_matrix(vc.surface_aspect()));
    gl.set_uniform(_prog, _vp_dim_loc, oglp::vec2(width, height));
}
//------------------------------------------------------------------------------
void sketch_program::bind_position_location(
  video_context& vc,
  oglp::vertex_attrib_location loc) {
    auto& gl = vc.gl_api();
    gl.bind_attrib_location(_prog, loc, "Position");
}
//------------------------------------------------------------------------------
void sketch_program::bind_normal_location(
  video_context& vc,
  oglp::vertex_attrib_location loc) {
    auto& gl = vc.gl_api();
    gl.bind_attrib_location(_prog, loc, "Normal");
}
//------------------------------------------------------------------------------
void sketch_program::bind_coord_location(
  video_context& vc,
  oglp::vertex_attrib_location loc) {
    auto& gl = vc.gl_api();
    gl.bind_attrib_location(_prog, loc, "Coord");
}
//------------------------------------------------------------------------------
// geometry
//------------------------------------------------------------------------------
void shape_geometry::init(execution_context& ec, video_context& vc) {
    const auto& glapi = vc.gl_api();
    const auto& gl = glapi;

    oglp::shape_generator shape(
      glapi,
      shapes::add_triangle_adjacency(shapes::unit_twisted_torus(
        shapes::vertex_attrib_kind::position |
          shapes::vertex_attrib_kind::normal |
          shapes::vertex_attrib_kind::wrap_coord,
        9,
        13,
        9,
        0.5F)));

    auto draw_var = shape.draw_variant(0);
    _ops.resize(std_size(shape.operation_count(draw_var)));
    shape.instructions(glapi, draw_var, cover(_ops));

    // vao
    gl.gen_vertex_arrays() >> _vao;
    gl.bind_vertex_array(_vao);

    // positions
    gl.gen_buffers() >> _positions;
    shape.attrib_setup(
      glapi,
      _vao,
      _positions,
      position_loc(),
      eagine::shapes::vertex_attrib_kind::position,
      ec.buffer());

    // normals
    gl.gen_buffers() >> _normals;
    shape.attrib_setup(
      glapi,
      _vao,
      _normals,
      normal_loc(),
      eagine::shapes::vertex_attrib_kind::normal,
      ec.buffer());

    // coords
    gl.gen_buffers() >> _coords;
    shape.attrib_setup(
      glapi,
      _vao,
      _coords,
      coord_loc(),
      eagine::shapes::vertex_attrib_kind::wrap_coord,
      ec.buffer());

    // indices
    gl.gen_buffers() >> _indices;
    shape.index_setup(glapi, _indices, draw_var, ec.buffer());
}
//------------------------------------------------------------------------------
void shape_geometry::clean_up(video_context& vc) {
    const auto& gl = vc.gl_api();
    gl.delete_buffers(std::move(_indices));
    gl.delete_buffers(std::move(_coords));
    gl.delete_buffers(std::move(_normals));
    gl.delete_buffers(std::move(_positions));
    gl.delete_vertex_arrays(std::move(_vao));
}
//------------------------------------------------------------------------------
void shape_geometry::draw(execution_context&, video_context& ec) {
    draw_using_instructions(ec.gl_api(), view(_ops));
}
//------------------------------------------------------------------------------
// sketch texture
//------------------------------------------------------------------------------
void sketch_texture::init(execution_context& ec, video_context& vc) {
    const auto& [gl, GL] = vc.gl_api();
    const int side = 512;
    std::vector<float> scratches(std_size(side * side));

    auto scratch = [&](auto x, auto y, auto layer) {
        const auto k =
          std_size(((side + y) % side) * side + ((side + x) % side));
        if(scratches[k] < layer) {
            scratches[k] = layer;
        }
    };

    for(const auto i : integer_range(3000)) {
        std::array<float, 6> rand{};
        ec.random_uniform_01(cover(rand));

        const auto xmin = std::min(rand[0], rand[1]);
        const auto xmax = std::max(rand[0], rand[1]);
        const auto ymin = std::min(rand[2], rand[3]);
        const auto ymax = std::max(rand[2], rand[3]);
        const auto w = int((xmax - xmin) * float(side));
        const auto h = int((ymax - ymin) * float(side));
        const auto l = (rand[5] - 0.5F) * 0.4F;

        for(int t : integer_range(2)) {
            if(w > h) {
                const auto layer = rand[4];
                for(auto x : integer_range(w)) {
                    const float c = l * float(x + 1) / float(w);
                    scratch(
                      int(x + xmin * side) + i,
                      int(float(h + t) * c + ymin * side),
                      layer);
                }
            } else {
                const auto layer = rand[4] * 0.85F;
                for(auto y : integer_range(h)) {
                    const float c = l * float(y + 1) / float(h);
                    scratch(
                      int(float(w + t) * c + xmin * side),
                      int(y + ymin * side) + i,
                      layer);
                }
            }
        }
    }

    gl.gen_textures() >> _tex;
    gl.active_texture(GL.texture0);
    gl.bind_texture(GL.texture_2d, _tex);
    gl.tex_parameter_i(GL.texture_2d, GL.texture_min_filter, GL.linear);
    gl.tex_parameter_i(GL.texture_2d, GL.texture_mag_filter, GL.linear);
    gl.tex_parameter_i(GL.texture_2d, GL.texture_wrap_s, GL.mirrored_repeat);
    gl.tex_parameter_i(GL.texture_2d, GL.texture_wrap_t, GL.mirrored_repeat);
    gl.tex_image2d(
      GL.texture_2d,
      0,
      GL.red,
      side,
      side,
      0,
      GL.red,
      GL.float_,
      as_bytes(view(scratches)));
}
//------------------------------------------------------------------------------
void sketch_texture::clean_up(execution_context&, video_context& vc) {
    const auto& gl = vc.gl_api();
    gl.delete_textures(std::move(_tex));
}
//------------------------------------------------------------------------------
} // namespace eagine::application
