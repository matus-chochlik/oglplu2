/// @example application/022_halo/main.cpp
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
#include <eagine/shapes/adjacency.hpp>
#include <eagine/shapes/torus.hpp>
#include <eagine/timeout.hpp>
#include <oglplus/math/matrix.hpp>
#include <oglplus/math/vector.hpp>

#include "resources.hpp"

#include <iostream>

namespace eagine::application {
//------------------------------------------------------------------------------
class example_halo : public application {
public:
    example_halo(
      execution_context&,
      video_context&,
      std::shared_ptr<shapes::generator>);

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
    surface_program _surf_prog;
    halo_program _halo_prog;
    shape_geometry _shape;
};
//------------------------------------------------------------------------------
example_halo::example_halo(
  execution_context& ec,
  video_context& vc,
  std::shared_ptr<shapes::generator> gen)
  : _ctx{ec}
  , _video{vc}
  , _shape{std::move(gen)} {
    auto& glapi = _video.gl_api();
    auto& [gl, GL] = glapi;

    _shape.init(ec, vc);

    _surf_prog.init(ec, vc);
    _surf_prog.bind_position_location(vc, _shape.position_loc());
    _surf_prog.bind_normal_location(vc, _shape.normal_loc());

    _halo_prog.init(ec, vc);
    _halo_prog.bind_position_location(vc, _shape.position_loc());
    _halo_prog.bind_normal_location(vc, _shape.normal_loc());

    // camera
    _camera.set_near(0.1F)
      .set_far(50.F)
      .set_orbit_min(1.1F)
      .set_orbit_max(3.5F)
      .set_fov(right_angle_());

    gl.clear_color(0.25F, 0.25F, 0.25F, 0.0F);
    gl.enable(GL.depth_test);
    gl.enable(GL.cull_face);
    gl.cull_face(GL.back);
    gl.blend_func(GL.src_alpha, GL.one);

    _camera.connect_inputs(ec).basic_input_mapping(ec);
    ec.setup_inputs().switch_input_mapping();
}
//------------------------------------------------------------------------------
void example_halo::on_video_resize() noexcept {
    auto& gl = _video.gl_api();
    gl.viewport(_video.surface_size());
}
//------------------------------------------------------------------------------
void example_halo::update() noexcept {
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

    _surf_prog.prepare_frame(_video, _camera);
    _shape.draw(_ctx, _video);

    gl.depth_mask(GL.false_);
    gl.enable(GL.blend);
    _halo_prog.prepare_frame(_video, _camera);
    _shape.draw(_ctx, _video);
    gl.disable(GL.blend);
    gl.depth_mask(GL.true_);

    _video.commit();
}
//------------------------------------------------------------------------------
void example_halo::clean_up() noexcept {

    _halo_prog.clean_up(_video);
    _surf_prog.clean_up(_video);
    _shape.clean_up(_video);

    _video.end();
}
//------------------------------------------------------------------------------
class example_launchpad : public launchpad {
public:
    auto setup(main_ctx&, launch_options& opts) -> bool final {
        opts.no_audio().require_input().require_video();
        _gen = shapes::unit_torus(
          shapes::vertex_attrib_kind::position |
          shapes::vertex_attrib_kind::normal);
        _gen = shapes::add_triangle_adjacency(_gen);
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
                    return {
                      std::make_unique<example_halo>(ec, vc, std::move(_gen))};
                }
            }
        }
        return {};
    }

private:
    std::shared_ptr<shapes::generator> _gen;
};
//------------------------------------------------------------------------------
auto establish(main_ctx&) -> std::unique_ptr<launchpad> {
    return {std::make_unique<example_launchpad>()};
}
//------------------------------------------------------------------------------
} // namespace eagine::application
