/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/application/main.hpp>
#include <eagine/application_config.hpp>
#include <eagine/timeout.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
class ogl_clear : public application {
public:
    ogl_clear(execution_context& ec, video_context& vc)
      : _ec{ec}
      , _video{vc} {
        EAGINE_MAYBE_UNUSED(_ec);
    }

    auto is_done() noexcept -> bool final {
        return _is_done.is_expired();
    }

    void update() noexcept final {
        // TODO
        _video.commit();
    }

    void cleanup() noexcept final {
        _video.end();
    }

private:
    execution_context& _ec;
    video_context& _video;
    timeout _is_done{std::chrono::seconds(10)};
};
//------------------------------------------------------------------------------
class my_app_launchpad : public launchpad {
public:
    auto setup(main_ctx&, launch_options& opts) -> bool final {
        opts.require_video().no_audio().no_input();
        return true;
    }

    auto launch(execution_context& ec, const launch_options&)
      -> std::unique_ptr<application> final {
        if(auto opt_vc{ec.video_ctx()}) {
            auto& vc = extract(opt_vc);
            vc.begin();
            if(vc.init_gl_api()) {
                return {std::make_unique<ogl_clear>(ec, vc)};
            }
        }
        return {};
    }
};
//------------------------------------------------------------------------------
auto establish(main_ctx&) -> std::unique_ptr<launchpad> {
    return {std::make_unique<my_app_launchpad>()};
}
//------------------------------------------------------------------------------
} // namespace eagine::application
