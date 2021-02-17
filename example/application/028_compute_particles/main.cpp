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
#include <oglplus/math/matrix.hpp>

#include "main.hpp"

namespace eagine::application {
//------------------------------------------------------------------------------
example::example(execution_context& ec, video_context& vc)
  : _ctx{ec}
  , _video{vc}
  , _path{view(std::array<oglp::vec3, 4>{
      {{-20.F, -10.F, -10.F},
       {20.F, -10.F, -10.F},
       {0.F, 10.F, 0.F},
       {0.F, -10.F, 10.F}}})} {

    auto& glapi = _video.gl_api();
    auto& [gl, GL] = glapi;

    _particles.init(*this);

    _emit_prog.init(*this);
    _emit_prog.bind_random(*this, _particles.random_binding());
    _emit_prog.bind_offsets(*this, _particles.offsets_binding());
    _emit_prog.bind_velocities(*this, _particles.velocities_binding());
    _emit_prog.bind_ages(*this, _particles.ages_binding());

    _draw_prog.init(*this);
    _draw_prog.bind_origin_location(*this, _particles.origin_loc());
    _draw_prog.bind_offsets(*this, _particles.offsets_binding());
    _draw_prog.bind_ages(*this, _particles.ages_binding());

    _camera.set_near(0.1F)
      .set_far(200.F)
      .set_orbit_min(10.0F)
      .set_orbit_max(40.0F)
      .set_fov(right_angle_());

    gl.clear_color(0.25F, 0.25F, 0.25F, 0.0F);
    gl.clear_depth(1.0F);

    gl.enable(GL.depth_test);
    gl.disable(GL.cull_face);

    _camera.connect_inputs(ec).basic_input_mapping(ec);
    ec.setup_inputs().switch_input_mapping();
}
//------------------------------------------------------------------------------
void example::on_video_resize() noexcept {
    auto& gl = _video.gl_api();
    gl.viewport(_video.surface_size());
}
//------------------------------------------------------------------------------
void example::update() noexcept {
    auto& state = _ctx.state();
    if(state.is_active()) {
        _is_done.reset();
    }
    if(state.user_idle_too_long()) {
        _camera.idle_update(state, 7.F);
    }

    auto& glapi = _video.gl_api();
    auto& [gl, GL] = glapi;

    gl.clear(GL.color_buffer_bit | GL.depth_buffer_bit);

    _emit_prog.use(*this);
    _emit_prog.prepare_frame(*this);
    _particles.emit(*this);

    _draw_prog.use(*this);
    _draw_prog.prepare_frame(*this);
    _particles.draw(*this);

    _video.commit();
}
//------------------------------------------------------------------------------
void example::clean_up() noexcept {
    _cleanup.clear();
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
               GL.vertex_shader && GL.tess_control_shader &&
               GL.tess_evaluation_shader && GL.vertex_shader &&
               GL.geometry_shader && GL.fragment_shader && GL.compute_shader;
    }

    auto launch(execution_context& ec, const launch_options&)
      -> std::unique_ptr<application> final {
        if(auto opt_vc{ec.video_ctx()}) {
            auto& vc = extract(opt_vc);
            vc.begin();
            if(vc.init_gl_api()) {
                if(check_requirements(vc)) {
                    return {std::make_unique<example>(ec, vc)};
                }
            }
        }
        return {};
    }
}; // namespace eagine::application
//------------------------------------------------------------------------------
auto establish(main_ctx&) -> std::unique_ptr<launchpad> {
    return {std::make_unique<example_launchpad>()};
}
//------------------------------------------------------------------------------
} // namespace eagine::application
