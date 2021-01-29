/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>

#include <eagine/application/camera.hpp>
#include <eagine/application/main.hpp>
#include <eagine/application_config.hpp>
#include <eagine/embed.hpp>
#include <eagine/shapes/cube.hpp>
#include <eagine/timeout.hpp>
#include <oglplus/glsl/string_ref.hpp>
#include <oglplus/math/matrix.hpp>
#include <oglplus/math/primitives.hpp>
#include <oglplus/math/vector.hpp>
#include <oglplus/shapes/generator.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
class example_cube : public application {
public:
    example_cube(execution_context&, video_context&);

    auto is_done() noexcept -> bool final {
        return _is_done.is_expired();
    }

    void on_video_resize() noexcept final;
    void update() noexcept final;
    void cleanup() noexcept final;

    void dragging(const input&);
    void orbit_x(const input&);
    void orbit_y(const input&);
    void drag_x(const input&);
    void drag_y(const input&);

private:
    execution_context& _ctx;
    video_context& _video;
    timeout _is_done{std::chrono::seconds{30}};

    std::vector<oglp::shape_draw_operation> _ops;
    oglp::owned_vertex_array_name vao;

    oglp::owned_buffer_name positions;
    oglp::owned_buffer_name normals;

    oglp::owned_program_name prog;

    orbiting_camera camera;
    oglp::uniform_location camera_loc;

    bool is_dragging{false};
};
//------------------------------------------------------------------------------
example_cube::example_cube(execution_context& ec, video_context& vc)
  : _ctx{ec}
  , _video{vc} {
    auto& glapi = _video.gl_api();
    auto& [gl, GL] = glapi;

    // vertex shader
    auto vs_source = embed(EAGINE_ID(VertShader), "vertex.glsl");
    oglp::owned_shader_name vs;
    gl.create_shader(GL.vertex_shader) >> vs;
    auto cleanup_vs = gl.delete_shader.raii(vs);
    gl.shader_source(vs, oglp::glsl_string_ref(vs_source));
    gl.compile_shader(vs);

    // fragment shader
    auto fs_src = embed(EAGINE_ID(FragShader), "fragment.glsl");
    oglp::owned_shader_name fs;
    gl.create_shader(GL.fragment_shader) >> fs;
    auto cleanup_fs = gl.delete_shader.raii(fs);
    gl.shader_source(fs, oglp::glsl_string_ref(fs_src));
    gl.compile_shader(fs);

    // program
    gl.create_program() >> prog;
    gl.attach_shader(prog, vs);
    gl.attach_shader(prog, fs);
    gl.link_program(prog);
    gl.use_program(prog);

    // geometry
    oglp::shape_generator shape(
      glapi,
      shapes::unit_cube(
        shapes::vertex_attrib_kind::position |
        shapes::vertex_attrib_kind::normal));

    _ops.resize(std_size(shape.operation_count()));
    shape.instructions(glapi, cover(_ops));

    // vao
    gl.gen_vertex_arrays() >> vao;
    gl.bind_vertex_array(vao);

    // positions
    oglp::vertex_attrib_location position_loc{0};
    gl.gen_buffers() >> positions;
    shape.attrib_setup(
      glapi,
      vao,
      positions,
      position_loc,
      eagine::shapes::vertex_attrib_kind::position,
      _ctx.buffer());
    gl.bind_attrib_location(prog, position_loc, "Position");

    // normals
    oglp::vertex_attrib_location normal_loc{1};
    gl.gen_buffers() >> normals;
    shape.attrib_setup(
      glapi,
      vao,
      normals,
      normal_loc,
      eagine::shapes::vertex_attrib_kind::normal,
      _ctx.buffer());
    gl.bind_attrib_location(prog, normal_loc, "Normal");

    // uniform
    gl.get_uniform_location(prog, "Camera") >> camera_loc;
    camera.set_near(0.1F)
      .set_far(50.F)
      .set_orbit_min(1.1F)
      .set_orbit_max(3.5F)
      .set_fov(right_angle_());

    gl.clear_color(0.4F, 0.4F, 0.4F, 0.0F);
    gl.enable(GL.depth_test);

    ec.connect_input(
        ec.stop_running_handler(),
        EAGINE_MSG_ID(Keyboard, Escape),
        input_setup().button())
      .connect_input(
        {this, EAGINE_THIS_MEM_FUNC_C(dragging)},
        EAGINE_MSG_ID(Cursor, Button0),
        input_setup().button())
      .connect_input(
        camera.altitude_change_handler(),
        EAGINE_MSG_ID(Keyboard, KpPlus),
        input_setup().button().multiply(0.05))
      .connect_input(
        camera.altitude_change_handler(),
        EAGINE_MSG_ID(Keyboard, KpMinus),
        input_setup().button().multiply(0.05).invert())
      .connect_input(
        camera.longitude_change_handler(),
        EAGINE_MSG_ID(Keyboard, Left),
        input_setup().button().multiply(0.05))
      .connect_input(
        camera.longitude_change_handler(),
        EAGINE_MSG_ID(Keyboard, Right),
        input_setup().button().multiply(0.05).invert())
      .connect_input(
        camera.latitude_change_handler(),
        EAGINE_MSG_ID(Keyboard, Up),
        input_setup().button().multiply(0.05).invert())
      .connect_input(
        camera.latitude_change_handler(),
        EAGINE_MSG_ID(Keyboard, Down),
        input_setup().button().multiply(0.05))
      .set_input_mapping();
}
//------------------------------------------------------------------------------
void example_cube::on_video_resize() noexcept {
    const auto [width, height] = _video.surface_size();
    auto& gl = _video.gl_api();
    gl.viewport(width, height);
}
//------------------------------------------------------------------------------
void example_cube::update() noexcept {
    auto& glapi = _video.gl_api();
    auto& [gl, GL] = glapi;

    gl.clear(GL.color_buffer_bit | GL.depth_buffer_bit);
    glapi.set_uniform(prog, camera_loc, camera.matrix(_video));
    oglp::draw_using_instructions(glapi, view(_ops));

    _video.commit();
}
//------------------------------------------------------------------------------
void example_cube::cleanup() noexcept {
    auto& gl = _video.gl_api();

    gl.delete_program(std::move(prog));
    gl.delete_buffers(std::move(normals));
    gl.delete_buffers(std::move(positions));
    gl.delete_vertex_arrays(std::move(vao));

    _video.end();
}
//------------------------------------------------------------------------------
void example_cube::dragging(const input& i) {
    is_dragging = bool(i);
}
//------------------------------------------------------------------------------
void example_cube::drag_x(const input&) {
    if(is_dragging) {
    }
}
//------------------------------------------------------------------------------
void example_cube::drag_y(const input&) {
    if(is_dragging) {
    }
}
//------------------------------------------------------------------------------
class example_launchpad : public launchpad {
public:
    auto setup(main_ctx&, launch_options& opts) -> bool final {
        opts.no_audio().require_input().require_video();
        return true;
    }

    auto check_requirements(video_context& vc) -> bool {
        auto& [gl, GL] = vc.gl_api();

        return gl.disable && gl.clear_color && gl.create_shader &&
               gl.shader_source && gl.compile_shader && gl.create_program &&
               gl.attach_shader && gl.link_program && gl.use_program &&
               gl.gen_buffers && gl.bind_buffer && gl.buffer_data &&
               gl.gen_vertex_arrays && gl.bind_vertex_array &&
               gl.get_attrib_location && gl.vertex_attrib_pointer &&
               gl.enable_vertex_attrib_array && gl.draw_arrays &&
               GL.vertex_shader && GL.fragment_shader;
    }

    auto launch(execution_context& ec, const launch_options&)
      -> std::unique_ptr<application> final {
        if(auto opt_vc{ec.video_ctx()}) {
            auto& vc = extract(opt_vc);
            vc.begin();
            if(vc.init_gl_api()) {
                if(check_requirements(vc)) {
                    return {std::make_unique<example_cube>(ec, vc)};
                }
            }
        }
        return {};
    }
};
//------------------------------------------------------------------------------
auto establish(main_ctx&) -> std::unique_ptr<launchpad> {
    return {std::make_unique<example_launchpad>()};
}
//------------------------------------------------------------------------------
} // namespace eagine::application
