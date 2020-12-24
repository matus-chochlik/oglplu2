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
#include "../memory/block.hpp"
#include "../tribool.hpp"
#include "options.hpp"
#include <memory>

namespace eagine::application {
class execution_context;
//------------------------------------------------------------------------------
struct input_provider {
    input_provider() noexcept = default;
    input_provider(input_provider&&) = delete;
    input_provider(const input_provider&) = delete;
    auto operator=(input_provider&&) = delete;
    auto operator=(const input_provider&) = delete;
    virtual ~input_provider() noexcept = default;
};
//------------------------------------------------------------------------------
struct video_provider {
    video_provider() noexcept = default;
    video_provider(video_provider&&) = delete;
    video_provider(const video_provider&) = delete;
    auto operator=(video_provider&&) = delete;
    auto operator=(const video_provider&) = delete;
    virtual ~video_provider() noexcept = default;

    virtual auto video_kind() const noexcept -> video_context_kind = 0;
    virtual auto instance_name() const noexcept -> string_view = 0;

    virtual auto is_offscreen() noexcept -> tribool = 0;
    virtual auto has_framebuffer() noexcept -> tribool = 0;
    virtual auto surface_size() noexcept -> std::tuple<int, int> = 0;

    virtual void video_begin(execution_context&) = 0;
    virtual void video_end(execution_context&) = 0;
    virtual void video_commit(execution_context&) = 0;
};
//------------------------------------------------------------------------------
struct audio_provider {
    audio_provider() noexcept = default;
    audio_provider(audio_provider&&) = delete;
    audio_provider(const audio_provider&) = delete;
    auto operator=(audio_provider&&) = delete;
    auto operator=(const audio_provider&) = delete;
    virtual ~audio_provider() noexcept = default;

    virtual auto audio_kind() const noexcept -> audio_context_kind = 0;
};
//------------------------------------------------------------------------------
struct hmi_provider {
    hmi_provider() noexcept = default;
    hmi_provider(hmi_provider&&) = delete;
    hmi_provider(const hmi_provider&) = delete;
    auto operator=(hmi_provider&&) = delete;
    auto operator=(const hmi_provider&) = delete;
    virtual ~hmi_provider() noexcept = default;

    virtual auto is_implemented() const noexcept -> bool = 0;
    virtual auto implementation_name() const noexcept -> string_view = 0;

    virtual auto is_initialized() -> bool = 0;
    virtual auto should_initialize(execution_context&) -> bool = 0;
    virtual auto initialize(execution_context&) -> bool = 0;
    virtual void update(execution_context&) = 0;
    virtual void cleanup(execution_context&) = 0;

    virtual auto input() -> std::shared_ptr<input_provider> = 0;
    virtual auto video(string_view = {}) -> std::shared_ptr<video_provider> = 0;
    virtual auto audio(string_view = {}) -> std::shared_ptr<audio_provider> = 0;
};
//------------------------------------------------------------------------------
struct frame_dump {
    frame_dump() noexcept = default;
    frame_dump(frame_dump&&) = delete;
    frame_dump(const frame_dump&) = delete;
    auto operator=(frame_dump&&) = delete;
    auto operator=(const frame_dump&) = delete;
    virtual ~frame_dump() noexcept = default;

    virtual auto initialize(execution_context&, framedump_data_type type)
      -> bool = 0;

    virtual auto get_buffer(span_size_t size) -> memory::block = 0;

    virtual void dump_frame(
      int width,
      int height,
      int elements,
      span_size_t element_size,
      framedump_pixel_format,
      framedump_data_type,
      memory::block data) = 0;
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
    virtual void update() noexcept = 0;
    virtual void cleanup() noexcept = 0;
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
