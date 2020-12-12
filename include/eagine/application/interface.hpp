/**
 *  @file eagine/application/interface.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_APPLICATION_INTERFACE_HPP
#define EAGINE_APPLICATION_INTERFACE_HPP

#include "../main_ctx_fwd.hpp"
#include "options.hpp"
#include <memory>

namespace eagine::application {
class execution_context;
//------------------------------------------------------------------------------
struct input_context {
    input_context() noexcept = default;
    input_context(input_context&&) = delete;
    input_context(const input_context&) = delete;
    auto operator=(input_context&&) = delete;
    auto operator=(const input_context&) = delete;
    virtual ~input_context() noexcept = default;
};
//------------------------------------------------------------------------------
struct video_context {
    video_context() noexcept = default;
    video_context(video_context&&) = delete;
    video_context(const video_context&) = delete;
    auto operator=(video_context&&) = delete;
    auto operator=(const video_context&) = delete;
    virtual ~video_context() noexcept = default;

    virtual auto video_kind() const noexcept -> video_context_kind = 0;

    virtual void video_begin(execution_context&) = 0;
    virtual void video_end(execution_context&) = 0;
    virtual void video_commit(execution_context&) = 0;
};
//------------------------------------------------------------------------------
struct audio_context {
    audio_context() noexcept = default;
    audio_context(audio_context&&) = delete;
    audio_context(const audio_context&) = delete;
    auto operator=(audio_context&&) = delete;
    auto operator=(const audio_context&) = delete;
    virtual ~audio_context() noexcept = default;
};
//------------------------------------------------------------------------------
struct hmi_context {
    hmi_context() noexcept = default;
    hmi_context(hmi_context&&) = delete;
    hmi_context(const hmi_context&) = delete;
    auto operator=(hmi_context&&) = delete;
    auto operator=(const hmi_context&) = delete;
    virtual ~hmi_context() noexcept = default;

    virtual auto is_implemented() const noexcept -> bool = 0;
    virtual auto implementation_name() const noexcept -> string_view = 0;

    virtual auto is_initialized() -> bool = 0;
    virtual auto initialize(execution_context&) -> bool = 0;
    virtual void update(execution_context&) = 0;
    virtual void cleanup(execution_context&) = 0;

    virtual auto video() -> std::shared_ptr<video_context> = 0;
    virtual auto input() -> std::shared_ptr<input_context> = 0;
};
//------------------------------------------------------------------------------
struct application {
    application() noexcept = default;
    application(application&&) = delete;
    application(const application&) = delete;
    auto operator=(application&&) = delete;
    auto operator=(const application&) = delete;
    virtual ~application() noexcept = default;

    virtual auto is_done() noexcept -> bool = 0;
    virtual void update(execution_context&) noexcept = 0;
};
//------------------------------------------------------------------------------
struct launchpad {
    launchpad() noexcept = default;
    launchpad(launchpad&&) = delete;
    launchpad(const launchpad&) = delete;
    auto operator=(launchpad&&) = delete;
    auto operator=(const launchpad&) = delete;
    virtual ~launchpad() noexcept = default;

    virtual auto setup(main_ctx&, launch_options&) -> bool {
        return true;
    }

    virtual auto launch(execution_context&, const launch_options&)
      -> std::unique_ptr<application> = 0;
};
//------------------------------------------------------------------------------
} // namespace eagine::application

#endif
