/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>

#include <eagine/application/camera.hpp>
#include <eagine/application/main.hpp>
#include <eagine/timeout.hpp>
#include <oglplus/math/matrix.hpp>
#include <oglplus/math/vector.hpp>

#include "resources.hpp"

namespace eagine::application {
//------------------------------------------------------------------------------
class example_cubes : public application {
public:
    example_cubes(execution_context&, video_context&);

    auto is_done() noexcept -> bool final {
        return _is_done.is_expired();
    }

    void on_video_resize() noexcept final;
    void update() noexcept final;
    void clean_up() noexcept final;

private:
    execution_context& _ctx;
    video_context& _video;
    timeout _is_done{std::chrono::seconds{30}};

    orbiting_camera camera;
    cubes_program prog;
    cubes_geometry cubes;
};
//------------------------------------------------------------------------------
example_cubes::example_cubes(execution_context& ec, video_context& vc)
  : _ctx{ec}
  , _video{vc} {
    auto& glapi = _video.gl_api();
    auto& [gl, GL] = glapi;

    prog.init(ec, vc);
    cubes.init(ec, vc);

    prog.bind_position_location(vc, cubes.position_loc());
    prog.bind_pivot_location(vc, cubes.pivot_loc());
    prog.bind_coord_location(vc, cubes.coord_loc());

    // camera
    camera.set_near(0.1F)
      .set_far(50.F)
      .set_orbit_min(10.2F)
      .set_orbit_max(16.0F)
      .set_fov(right_angle_());
    prog.set_projection(vc, camera);

    gl.clear_color(0.45F, 0.45F, 0.45F, 0.0F);
    gl.enable(GL.depth_test);
    gl.enable(GL.cull_face);
    gl.cull_face(GL.back);

    camera.connect_inputs(ec).basic_input_mapping(ec);
    ec.setup_inputs().switch_input_mapping();
}
//------------------------------------------------------------------------------
void example_cubes::on_video_resize() noexcept {
    auto& gl = _video.gl_api();
    gl.viewport(_video.surface_size());
}
//------------------------------------------------------------------------------
void example_cubes::update() noexcept {
    auto& state = _ctx.state();
    if(state.is_active()) {
        _is_done.reset();
    }
    if(state.user_idle_too_long()) {
        camera.idle_update(state);
    }

    auto& glapi = _video.gl_api();
    auto& [gl, GL] = glapi;

    gl.clear(GL.color_buffer_bit | GL.depth_buffer_bit);
    prog.update(_ctx, _video);
    prog.set_projection(_video, camera);

    prog.drawing_surface(_video);
    cubes.draw_surface(_video);

    prog.drawing_edges(_video);
    cubes.draw_edges(_video);

    _video.commit();
}
//------------------------------------------------------------------------------
void example_cubes::clean_up() noexcept {

    prog.clean_up(_video);
    cubes.clean_up(_video);

    _video.end();
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
                    return {std::make_unique<example_cubes>(ec, vc)};
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
