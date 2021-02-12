/// .file application/032_translucent_arrow/main.cpp
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
#include <eagine/cleanup_group.hpp>
#include <eagine/timeout.hpp>
#include <oglplus/math/matrix.hpp>
#include <oglplus/math/vector.hpp>

#include "resources.hpp"

namespace eagine::application {
//------------------------------------------------------------------------------
class example_arrow : public application {
public:
    example_arrow(execution_context&, video_context&);

    auto is_done() noexcept -> bool final {
        return _is_done.is_expired();
    }

    void on_video_resize() noexcept final;
    void update() noexcept final;
    void clean_up() noexcept final;

private:
    cleanup_group _cleanup;
    execution_context& _ctx;
    video_context& _video;
    timeout _is_done{std::chrono::seconds{30}};

    orbiting_camera camera;

    depth_program depth_prog;
    draw_program draw_prog;
    arrow_geometry arrow;
    depth_texture depth_tex;
};
//------------------------------------------------------------------------------
example_arrow::example_arrow(execution_context& ec, video_context& vc)
  : _ctx{ec}
  , _video{vc} {
    auto& glapi = _video.gl_api();
    auto& [gl, GL] = glapi;

    arrow.init(ec, vc, _cleanup);
    depth_tex.init(ec, vc, _cleanup);

    depth_prog.init(ec, vc, _cleanup);
    depth_prog.bind_position_location(vc, arrow.position_loc());

    draw_prog.init(ec, vc, _cleanup);
    draw_prog.bind_position_location(vc, arrow.position_loc());
    draw_prog.bind_normal_location(vc, arrow.normal_loc());
    draw_prog.set_depth_texture(vc, depth_tex.texture_unit());

    // camera
    const auto sr = arrow.bounding_sphere().radius();
    camera.set_near(sr * 0.1F)
      .set_far(sr * 4.0F)
      .set_orbit_min(sr * 1.2F)
      .set_orbit_max(sr * 1.7F)
      .set_fov(degrees_(80.F));
    depth_prog.set_projection(vc, camera);
    draw_prog.set_projection(vc, camera);

    gl.clear_color(0.45F, 0.45F, 0.45F, 0.0F);
    gl.enable(GL.depth_test);
    gl.enable(GL.cull_face);
    gl.cull_face(GL.back);

    camera.connect_inputs(ec).basic_input_mapping(ec);
    ec.setup_inputs().switch_input_mapping();
}
//------------------------------------------------------------------------------
void example_arrow::on_video_resize() noexcept {
    auto& gl = _video.gl_api();
    gl.viewport(_video.surface_size());
}
//------------------------------------------------------------------------------
void example_arrow::update() noexcept {
    auto& state = _ctx.state();
    if(state.is_active()) {
        _is_done.reset();
    }
    if(state.user_idle_too_long()) {
        camera.idle_update(state, 2);
    }

    auto& glapi = _video.gl_api();
    auto& [gl, GL] = glapi;

    gl.clear_depth(0);
    gl.clear(GL.depth_buffer_bit);
    gl.depth_func(GL.greater);
    gl.cull_face(GL.front);
    depth_prog.update(_video);
    depth_prog.set_projection(_video, camera);
    arrow.draw(_video);

    depth_tex.copy_from_fb(_video);

    gl.clear_depth(1);
    gl.clear(GL.color_buffer_bit | GL.depth_buffer_bit);
    gl.depth_func(GL.less);
    gl.cull_face(GL.back);
    draw_prog.update(_ctx, _video);
    draw_prog.set_projection(_video, camera);
    arrow.draw(_video);

    _video.commit();
}
//------------------------------------------------------------------------------
void example_arrow::clean_up() noexcept {
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
               GL.vertex_shader && GL.fragment_shader;
    }

    auto launch(execution_context& ec, const launch_options&)
      -> std::unique_ptr<application> final {
        if(auto opt_vc{ec.video_ctx()}) {
            auto& vc = extract(opt_vc);
            vc.begin();
            if(vc.init_gl_api()) {
                if(check_requirements(vc)) {
                    return {std::make_unique<example_arrow>(ec, vc)};
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
