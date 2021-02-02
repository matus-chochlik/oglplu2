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
#include <eagine/timeout.hpp>
#include <oglplus/math/matrix.hpp>
#include <oglplus/math/vector.hpp>

#include "resources.hpp"

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
    void clean_up() noexcept final;

private:
    execution_context& _ctx;
    video_context& _video;
    timeout _is_done{std::chrono::seconds{30}};

    cube_program prog;
    cube_geometry cube;
    cube_draw_buffers bufs;
};
//------------------------------------------------------------------------------
example_cube::example_cube(execution_context& ec, video_context& vc)
  : _ctx{ec}
  , _video{vc} {
    auto& glapi = _video.gl_api();
    auto& [gl, GL] = glapi;

    prog.init(ec, vc);
    cube.init(ec, vc);
    bufs.init(ec, vc);

    prog.bind_position_location(vc, cube.position_loc());
    prog.bind_normal_location(vc, cube.normal_loc());
    prog.bind_tex_coord_location(vc, cube.tex_coord_loc());

    gl.clear_color(0.8F, 0.8F, 0.8F, 0.0F);
    gl.enable(GL.depth_test);
    gl.enable(GL.cull_face);
    gl.cull_face(GL.back);

    ec.setup_inputs().switch_input_mapping();
}
//------------------------------------------------------------------------------
void example_cube::on_video_resize() noexcept {
    _video.gl_api().viewport(_video.surface_size());
}
//------------------------------------------------------------------------------
void example_cube::update() noexcept {
    if(!_ctx.state().user_is_idle()) {
        _is_done.reset();
    }

    auto& glapi = _video.gl_api();
    auto& [gl, GL] = glapi;

    prog.update(_ctx, _video);
    prog.set_texture(_video, bufs.front_tex_unit());

    // draw into texture
    gl.bind_framebuffer(GL.draw_framebuffer, bufs.back_fbo());
    gl.viewport(bufs.side(), bufs.side());

    prog.set_projection(
      _video,
      oglp::matrix_perspective(-0.5F, 0.5F, -0.5F, 0.5F, 1.0F, 5) *
        oglp::matrix_translation(0, 0, -2));

    gl.clear(GL.color_buffer_bit | GL.depth_buffer_bit);
    cube.draw(_video);

    // draw on screen
    gl.bind_framebuffer(GL.draw_framebuffer, oglp::framebuffer_name(0));
    gl.viewport(_video.surface_size());

    const float h = 0.55F;
    const float w = h * _video.surface_aspect();
    prog.set_projection(
      _video,
      oglp::matrix_perspective(-w, +w, -h, +h, 1, 3) *
        oglp::matrix_translation(0, 0, -2));

    gl.clear(GL.color_buffer_bit | GL.depth_buffer_bit);
    cube.draw(_video);
    // swap texture draw buffers
    bufs.swap();

    _video.commit();
}
//------------------------------------------------------------------------------
void example_cube::clean_up() noexcept {

    bufs.clean_up(_video);
    cube.clean_up(_video);
    prog.clean_up(_video);

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
