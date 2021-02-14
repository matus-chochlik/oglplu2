/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/application/main.hpp>
#include <eagine/application_config.hpp>
#include <eagine/timeout.hpp>

#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
class example_clear : public application {
public:
    example_clear(execution_context& ec, video_context& vc)
      : _ec{ec}
      , _video{vc} {
        ec.connect_inputs().map_inputs().switch_input_mapping();
    }

    auto is_done() noexcept -> bool final {
        return _is_done.is_expired();
    }

    void on_video_resize() noexcept final {
        const auto [width, height] = _video.surface_size();
        auto& gl = _video.gl_api();
        gl.viewport(width, height);
    }

    void update() noexcept final {
        auto& [gl, GL] = _video.gl_api();

        const auto sec = int(_ec.state().frame_time());

        gl.clear_color(
          (sec % 3 == 0) ? 1.F : 0.F,
          (sec % 3 == 1) ? 1.F : 0.F,
          (sec % 3 == 2) ? 1.F : 0.F,
          0.0F);

        gl.clear(GL.color_buffer_bit);

        _video.commit();
    }

    void clean_up() noexcept final {
        _video.end();
    }

private:
    execution_context& _ec;
    video_context& _video;
    timeout _is_done{std::chrono::seconds(10)};
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

        return gl.clear_color && gl.clear && GL.color_buffer_bit;
    }

    auto launch(execution_context& ec, const launch_options&)
      -> std::unique_ptr<application> final {
        if(auto opt_vc{ec.video_ctx()}) {
            auto& vc = extract(opt_vc);
            vc.begin();
            if(vc.init_gl_api()) {
                if(check_requirements(vc)) {
                    return {std::make_unique<example_clear>(ec, vc)};
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
