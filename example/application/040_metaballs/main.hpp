/// @example application/040_metaballs/main.hpp
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
#include <oglplus/math/vector.hpp>

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

    auto camera() noexcept -> auto& {
        return _camera;
    }

    auto frame_duration() noexcept {
        return ctx().state().frame_duration().value();
    }

    operator cleanup_group&() noexcept {
        return _cleanup;
    }

private:
    cleanup_group _cleanup;
    execution_context& _ctx;
    video_context& _video;
    timeout _is_done{std::chrono::seconds{60}};

    orbiting_camera _camera;
    metaball_program _mball_prog;
    field_program _field_prog;
    surface_program _srfce_prog;
    volume_domain _volume;
};

} // namespace eagine::application

#endif
