/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef OGLPLUS_EXAMPLE_MAIN_HPP // NOLINT(llvm-header-guard)
#define OGLPLUS_EXAMPLE_MAIN_HPP

#include "resources.hpp"

#include <eagine/application/camera.hpp>
#include <eagine/application/interface.hpp>
#include <eagine/cleanup_group.hpp>
#include <eagine/timeout.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
class example : public application {
public:
    example(execution_context&, video_context&);

    auto is_done() noexcept -> bool final {
        return _is_done.is_expired();
    }

    void on_video_resize() noexcept final;
    void update() noexcept final;
    void clean_up() noexcept final;

    auto ctx() noexcept -> auto& {
        return _ctx;
    }

    auto video() noexcept -> auto& {
        return _video;
    }

    auto cleanup() noexcept -> auto& {
        return _cleanup;
    }

    auto camera() noexcept -> auto& {
        return _camera;
    }

private:
    cleanup_group _cleanup;
    execution_context& _ctx;
    video_context& _video;
    timeout _is_done{std::chrono::seconds{30}};

    orbiting_camera _camera;
    draw_program _draw_prog;
    screen_program _screen_prog;
    shape_geometry _shape;
    screen_geometry _screen;
    draw_buffers _draw_bufs;
};
//------------------------------------------------------------------------------
} // namespace eagine::application

#endif
