/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/application/main.hpp>
#include <eagine/application_config.hpp>
#include <eagine/timeout.hpp>

#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
class example_spectrum : public application {
public:
    example_spectrum(execution_context& ec, video_context& vc)
      : _ec{ec}
      , _video{vc} {
        ec.connect_input(
            ec.stop_running_handler(),
            EAGINE_MSG_ID(Keyboard, Escape),
            input_setup().button())
          .set_input_mapping();

        auto& gl = _video.gl_api();
        gl.clear_color(0.4F, 0.4F, 0.4F, 0.0F);
    }

    auto is_done() noexcept -> bool final {
        return _is_done.is_expired();
    }

    void on_video_resize() noexcept final {
        const auto [width, height] = _video.surface_size();
        auto& [gl, GL] = _video.gl_api();

        gl.viewport(width, height);

        const auto h = GL.double_(2);
        const auto w = h * GL.double_(_video.surface_aspect());

        gl.matrix_mode(GL.projection);
        gl.load_identity();
        gl.ortho(-w, +w, -h, +h, 0, 1);
    }

    void update() noexcept final {
        auto& [gl, GL] = _video.gl_api();

        gl.clear(GL.color_buffer_bit);

        gl.matrix_mode(GL.modelview);
        gl.load_identity();
        gl.rotate_f(degrees_(_ec.state().frame_time().value() * 90), 0, 0, 1);

        gl.begin(GL.triangle_fan);

        gl.color3f(0.5F, 0.5F, 0.5F);
        gl.vertex2f(0.000F, 0.000F);

        gl.color3f(1.0F, 0.0F, 0.0F);
        gl.vertex2f(0.000F, 1.000F);

        gl.color3f(1.0F, 0.7F, 0.0F);
        gl.vertex2f(0.707F, 0.707F);

        gl.color3f(0.7F, 1.0F, 0.0F);
        gl.vertex2f(1.000F, 0.000F);

        gl.color3f(0.0F, 1.0F, 0.0F);
        gl.vertex2f(0.707F, -0.707F);

        gl.color3f(0.0F, 1.0F, 0.7F);
        gl.vertex2f(0.000F, -1.000F);

        gl.color3f(0.0F, 0.7F, 1.0F);
        gl.vertex2f(-0.707F, -0.707F);

        gl.color3f(0.0F, 0.0F, 1.0F);
        gl.vertex2f(-1.000F, 0.000F);

        gl.color3f(0.7F, 0.0F, 0.7F);
        gl.vertex2f(-0.707F, 0.707F);

        gl.color3f(1.0F, 0.0F, 0.0F);
        gl.vertex2f(0.000F, 1.000F);

        gl.end();

        gl.begin(GL.line_loop);

        gl.color3f(0, 0, 0);

        gl.vertex2f(0.000F, 1.000F);
        gl.vertex2f(0.707F, 0.707F);
        gl.vertex2f(1.000F, 0.000F);
        gl.vertex2f(0.707F, -0.707F);
        gl.vertex2f(0.000F, -1.000F);
        gl.vertex2f(-0.707F, -0.707F);
        gl.vertex2f(-1.000F, 0.000F);
        gl.vertex2f(-0.707F, 0.707F);
        gl.vertex2f(0.000F, 1.000F);

        gl.end();

        _video.commit();
    }

    void cleanup() noexcept final {
        _video.end();
    }

private:
    execution_context& _ec;
    video_context& _video;
    timeout _is_done{std::chrono::seconds(8)};
};
//------------------------------------------------------------------------------
class example_launchpad : public launchpad {
public:
    auto setup(main_ctx&, launch_options& opts) -> bool final {
        opts.no_audio().require_input().require_video();
        return true;
    }

    auto check_requirements(video_context& vc) -> bool {
        auto& [gl, GL] = vc.gl_api();

        return gl.viewport && gl.clear_color && gl.clear &&
               GL.color_buffer_bit && gl.load_identity && gl.ortho &&
               gl.rotate_f && gl.begin && gl.end && gl.vertex2f && gl.color3f &&
               GL.modelview && GL.projection && GL.triangle_fan && GL.line_loop;
    }

    auto launch(execution_context& ec, const launch_options&)
      -> std::unique_ptr<application> final {
        if(auto opt_vc{ec.video_ctx()}) {
            auto& vc = extract(opt_vc);
            vc.begin();
            if(vc.init_gl_api()) {
                if(check_requirements(vc)) {
                    return {std::make_unique<example_spectrum>(ec, vc)};
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
