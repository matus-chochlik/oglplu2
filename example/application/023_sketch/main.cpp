/// @example application/023_sketch/main.cpp
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

#include <iostream>

namespace eagine::application {
//------------------------------------------------------------------------------
class example_sketch : public application {
public:
    example_sketch(execution_context&, video_context&);

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

    orbiting_camera _camera;
    sketch_program _sketch_prog;
    shape_geometry _shape;
    sketch_texture _tex;
};
//------------------------------------------------------------------------------
example_sketch::example_sketch(execution_context& ec, video_context& vc)
  : _ctx{ec}
  , _video{vc} {
    auto& glapi = _video.gl_api();
    auto& [gl, GL] = glapi;

    _shape.init(ec, vc);
    _tex.init(ec, vc);

    _sketch_prog.init(ec, vc);
    _sketch_prog.bind_position_location(vc, _shape.position_loc());
    _sketch_prog.bind_normal_location(vc, _shape.normal_loc());
    _sketch_prog.bind_coord_location(vc, _shape.coord_loc());

    // camera
    _camera.set_near(0.1F)
      .set_far(50.F)
      .set_orbit_min(1.1F)
      .set_orbit_max(2.5F)
      .set_fov(degrees_(50.F));

    gl.clear_color(0.95F, 0.95F, 0.75F, 0.0F);
    gl.enable(GL.depth_test);
    gl.enable(GL.cull_face);
    gl.cull_face(GL.back);

    _camera.connect_inputs(ec).basic_input_mapping(ec);
    ec.setup_inputs().switch_input_mapping();
}
//------------------------------------------------------------------------------
void example_sketch::on_video_resize() noexcept {
    auto& gl = _video.gl_api();
    gl.viewport(_video.surface_size());
}
//------------------------------------------------------------------------------
void example_sketch::update() noexcept {
    auto& state = _ctx.state();
    if(state.is_active()) {
        _is_done.reset();
    }
    if(state.user_idle_too_long()) {
        _camera.idle_update(state, 9.F);
    }

    auto& glapi = _video.gl_api();
    auto& [gl, GL] = glapi;

    gl.clear(GL.color_buffer_bit | GL.depth_buffer_bit);

    _sketch_prog.prepare_frame(
      _video, _camera, _ctx.state().frame_time().value());
    _shape.draw(_ctx, _video);

    _video.commit();
}
//------------------------------------------------------------------------------
void example_sketch::clean_up() noexcept {

    _sketch_prog.clean_up(_video);
    _shape.clean_up(_video);
    _tex.init(_ctx, _video);

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
               GL.vertex_shader && GL.geometry_shader && GL.fragment_shader;
    }

    auto launch(execution_context& ec, const launch_options&)
      -> std::unique_ptr<application> final {
        if(auto opt_vc{ec.video_ctx()}) {
            auto& vc = extract(opt_vc);
            vc.begin();
            if(vc.init_gl_api()) {
                if(check_requirements(vc)) {
                    return {std::make_unique<example_sketch>(ec, vc)};
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
