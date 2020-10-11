/**
 *  example combined/009_json_shape/example.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>

#include <eagine/file_contents.hpp>
#include <eagine/shapes/value_tree.hpp>
#include <eagine/value_tree/json.hpp>
#include <oglplus/glsl/string_ref.hpp>
#include <oglplus/math/matrix.hpp>
#include <oglplus/math/vector.hpp>
#include <oglplus/shapes/generator.hpp>

#include "../example.hpp"
#include "../example/camera.hpp"

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
example_string_param color_variant_name{"-c", "--color", "color_1"};
example_string_param shape_file_path{"-s", "--shape", ""};
//------------------------------------------------------------------------------
class example_shape : public example {
    example_orbiting_camera camera;

    owned_vertex_array_name vao;

    owned_buffer_name positions;
    owned_buffer_name colors;
    owned_buffer_name indices;

    owned_shader_name vs;
    owned_shader_name fs;

    owned_program_name prog;
    uniform_location camera_loc;

    std::vector<shape_draw_operation> _ops;

    void set_projection(const example_context& ctx);

public:
    auto check_requirements(const example_context& ctx) -> bool final;
    void init(example_context& ctx) final;
    void pointer_motion(const example_context& ctx) final;
    void pointer_scrolling(const example_context& ctx) final;
    void user_idle(const example_context& ctx) final;
    void resize(const example_context& ctx) final;
    void render(const example_context& ctx) final;
};
//------------------------------------------------------------------------------
// example_shape
//------------------------------------------------------------------------------
auto example_shape ::check_requirements(const example_context& ctx) -> bool {
    const auto& [gl, GL] = ctx.gl();
    auto r = ctx.req_mark();

    return r(gl.disable) && r(gl.clear_color) && r(gl.create_shader) &&
           r(gl.shader_source) && r(gl.compile_shader) &&
           r(gl.create_program) && r(gl.attach_shader) && r(gl.link_program) &&
           r(gl.use_program) && r(gl.gen_buffers) && r(gl.bind_buffer) &&
           r(gl.buffer_data) && r(gl.gen_vertex_arrays) &&
           r(gl.bind_vertex_array) && r(gl.get_attrib_location) &&
           r(gl.vertex_attrib_pointer) && r(gl.enable_vertex_attrib_array) &&
           r(gl.draw_arrays) && r(GL.vertex_shader) && r(GL.fragment_shader);
}
//------------------------------------------------------------------------------
void example_shape::set_projection(const example_context& ctx) {
    ctx.gl().set_uniform(prog, camera_loc, camera.matrix(ctx.state()));
}
//------------------------------------------------------------------------------
void example_shape::init(example_context& ctx) {
    auto& cleanup = ctx.cleanup();
    const auto& [gl, GL] = ctx.gl();

    auto load_shape_data = [&]() {
        if(shape_file_path.is_valid()) {
            if(const auto json_content{file_contents(shape_file_path)}) {
                if(const auto json_text = as_chars(json_content.block())) {
                    return valtree::from_json_text(json_text, ctx.log());
                }
            }
        }
        const auto json_text =
          as_chars(embed(EAGINE_ID(ShapeJson), "shape.json"));
        return valtree::from_json_text(json_text, ctx.log());
    };

    shape_generator shape(
      ctx.gl(), shapes::from_value_tree(load_shape_data(), ctx.log()));

    _ops.resize(std_size(shape.operation_count()));
    shape.instructions(ctx.gl(), cover(_ops));

    gl.clear_color(0.45F, 0.45F, 0.45F, 0.0F);

    // vertex shader
    auto vs_src = embed(EAGINE_ID(VertShader), "vertex.glsl");
    gl.create_shader(GL.vertex_shader) >> vs;
    gl.delete_shader.later_by(cleanup, vs);
    gl.shader_source(vs, glsl_string_ref(vs_src));
    gl.compile_shader(vs);

    // fragment shader
    auto fs_src = embed(EAGINE_ID(FragShader), "fragment.glsl");
    gl.create_shader(GL.fragment_shader) >> fs;
    gl.delete_shader.later_by(cleanup, fs);
    gl.shader_source(fs, glsl_string_ref(fs_src));
    gl.compile_shader(fs);

    // program
    gl.create_program() >> prog;
    gl.delete_program.later_by(cleanup, prog);
    gl.attach_shader(prog, vs);
    gl.attach_shader(prog, fs);
    gl.link_program(prog);
    gl.use_program(prog);

    // vao
    gl.gen_vertex_arrays() >> vao;
    gl.delete_vertex_arrays.later_by(cleanup, vao);
    gl.bind_vertex_array(vao);

    // positions
    vertex_attrib_location position_loc(0);
    gl.gen_buffers() >> positions;
    gl.delete_buffers.later_by(cleanup, positions);
    shape.attrib_setup(
      ctx.gl(),
      vao,
      positions,
      position_loc,
      eagine::shapes::vertex_attrib_kind::position,
      ctx.buffer());
    gl.bind_attrib_location(prog, position_loc, "Position");

    // colors
    vertex_attrib_location color_loc(1);
    gl.gen_buffers() >> colors;
    gl.delete_buffers.later_by(cleanup, colors);
    shape.attrib_setup(
      ctx.gl(),
      vao,
      colors,
      color_loc,
      shape.find_variant_or(
        eagine::shapes::vertex_attrib_kind::color, color_variant_name, 0),
      ctx.buffer());
    gl.bind_attrib_location(prog, color_loc, "Color");

    // indices
    gl.gen_buffers() >> indices;
    gl.delete_buffers.later_by(cleanup, indices);
    shape.index_setup(ctx.gl(), indices, ctx.buffer());

    gl.enable(GL.depth_test);
    gl.enable(GL.cull_face);
    gl.cull_face(GL.back);

    // camera
    const auto sr = shape.bounding_sphere().radius();
    gl.get_uniform_location(prog, "Camera") >> camera_loc;
    camera.set_near(sr * 0.1F)
      .set_far(sr * 5.0F)
      .set_orbit_min(sr * 1.2F)
      .set_orbit_max(sr * 2.4F)
      .set_fov(right_angle_());
    set_projection(ctx);
}
//------------------------------------------------------------------------------
void example_shape::pointer_motion(const example_context& ctx) {
    const auto& state = ctx.state();
    if(camera.apply_pointer_motion(state)) {
        set_projection(ctx);
    }
}
//------------------------------------------------------------------------------
void example_shape::pointer_scrolling(const example_context& ctx) {
    const auto& state = ctx.state();
    if(camera.apply_pointer_scrolling(state)) {
        set_projection(ctx);
    }
}
//------------------------------------------------------------------------------
void example_shape::user_idle(const example_context& ctx) {
    const auto& state = ctx.state();
    if(state.user_idle_time() > seconds_(1)) {
        camera.idle_update(state, 2);
        set_projection(ctx);
    }
}
//------------------------------------------------------------------------------
void example_shape::resize(const example_context& ctx) {
    const auto& state = ctx.state();
    const auto& gl = ctx.gl();

    gl.viewport(state.width(), state.height());
    set_projection(ctx);
}
//------------------------------------------------------------------------------
void example_shape::render(const example_context& ctx) {
    const auto& [gl, GL] = ctx.gl();

    gl.clear(GL.color_buffer_bit | GL.depth_buffer_bit);
    draw_using_instructions(ctx.gl(), view(_ops));
}
//------------------------------------------------------------------------------
} // namespace oglp
//------------------------------------------------------------------------------
auto make_example(const example_args& args, const example_context&)
  -> std::unique_ptr<example> {
    args.parse_param(oglp::color_variant_name);
    args.parse_param(oglp::shape_file_path);
    return {std::make_unique<oglp::example_shape>()};
}
//------------------------------------------------------------------------------
void adjust_params(example_params& params) {
    params.stencil_buffer(false);
}
//------------------------------------------------------------------------------
auto is_example_param(const example_arg& arg) -> bool {
    if(arg == oglp::color_variant_name) {
        return true;
    }
    if(arg == oglp::shape_file_path) {
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
} // namespace eagine
