/// @example application/040_metaballs/main.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>

#include <eagine/units/unit/si/angle.hpp>
//
#include <eagine/application/camera.hpp>
#include <eagine/application/main.hpp>
#include <oglplus/math/matrix.hpp>

#include "main.hpp"

namespace eagine::application {
//------------------------------------------------------------------------------
example::example(execution_context& ec, video_context& vc)
  : _ctx{ec}
  , _video{vc} {

    auto& glapi = _video.gl_api();
    auto& [gl, GL] = glapi;

    _volume.init(*this);

    _mball_prog.init(*this);
    _mball_prog.bind_metaballs(*this, _volume.metaballs_binding());

    _field_prog.init(*this);
    _field_prog.bind_field(*this, _volume.field_binding());
    _field_prog.bind_metaballs(*this, _volume.metaballs_binding());
    _field_prog.set_plane_count(*this, _volume.plane_count());

    _srfce_prog.init(*this);
    _srfce_prog.bind_corner_location(*this, _volume.corner_loc());
    _srfce_prog.bind_field(*this, _volume.field_binding());
    _srfce_prog.bind_configs(*this, _volume.configs_binding());
    _srfce_prog.set_plane_count(*this, _volume.plane_count());
    _srfce_prog.set_div_count(*this, _volume.div_count());

    _camera.set_near(0.1F)
      .set_far(50.F)
      .set_orbit_min(7.0F)
      .set_orbit_max(8.0F)
      .set_fov(degrees_(65.F));

    gl.clear_color(0.25F, 0.25F, 0.25F, 0.0F);
    gl.clear_depth(1.0F);

    gl.enable(GL.depth_test);
    gl.enable(GL.cull_face);

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

    _mball_prog.use(*this);
    _mball_prog.prepare_frame(*this);
    gl.dispatch_compute(1, 1, 1);

    _field_prog.use(*this);
    _field_prog.prepare_frame(*this);
    _volume.compute(*this);

    gl.clear(GL.color_buffer_bit | GL.depth_buffer_bit);

    _srfce_prog.use(*this);
    _srfce_prog.prepare_frame(*this);
    _volume.draw(*this);

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
