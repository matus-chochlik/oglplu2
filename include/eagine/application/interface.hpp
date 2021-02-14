/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_APPLICATION_INTERFACE_HPP
#define EAGINE_APPLICATION_INTERFACE_HPP

#include "../memory/block.hpp"
#include "../string_span.hpp"
#include "../tribool.hpp"
#include "fwd.hpp"
#include "input.hpp"
#include "options.hpp"
#include <memory>

namespace eagine::application {
//------------------------------------------------------------------------------
struct input_sink {
    input_sink() noexcept = default;
    input_sink(input_sink&&) = delete;
    input_sink(const input_sink&) = delete;
    auto operator=(input_sink&&) = delete;
    auto operator=(const input_sink&) = delete;
    virtual ~input_sink() noexcept = default;

    virtual void
    consume(const input_info&, const input_value<bool>&) noexcept = 0;
    virtual void
    consume(const input_info&, const input_value<int>&) noexcept = 0;
    virtual void
    consume(const input_info&, const input_value<float>&) noexcept = 0;
    virtual void
    consume(const input_info&, const input_value<double>&) noexcept = 0;
};
//------------------------------------------------------------------------------
struct input_provider {
    input_provider() noexcept = default;
    input_provider(input_provider&&) = delete;
    input_provider(const input_provider&) = delete;
    auto operator=(input_provider&&) = delete;
    auto operator=(const input_provider&) = delete;
    virtual ~input_provider() noexcept = default;

    virtual auto instance_id() const noexcept -> identifier = 0;

    virtual void
      input_enumerate(callable_ref<void(message_id, input_value_kinds)>) = 0;

    virtual void input_connect(input_sink&) = 0;
    virtual void input_disconnect() = 0;

    virtual void mapping_begin(identifier setup_id) = 0;
    virtual void mapping_enable(message_id signal_id) = 0;
    virtual void mapping_commit(identifier setup_id) = 0;
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
    virtual auto instance_id() const noexcept -> identifier = 0;

    virtual auto is_offscreen() noexcept -> tribool = 0;
    virtual auto has_framebuffer() noexcept -> tribool = 0;
    virtual auto surface_size() noexcept -> std::tuple<int, int> = 0;
    virtual auto surface_aspect() noexcept -> float = 0;

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
    virtual auto instance_id() const noexcept -> identifier = 0;
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
    virtual void clean_up(execution_context&) = 0;

    virtual void
      input_enumerate(callable_ref<void(std::shared_ptr<input_provider>)>) = 0;
    virtual void
      video_enumerate(callable_ref<void(std::shared_ptr<video_provider>)>) = 0;
    virtual void
      audio_enumerate(callable_ref<void(std::shared_ptr<audio_provider>)>) = 0;
};
//------------------------------------------------------------------------------
struct framedump {
    framedump() noexcept = default;
    framedump(framedump&&) = delete;
    framedump(const framedump&) = delete;
    auto operator=(framedump&&) = delete;
    auto operator=(const framedump&) = delete;
    virtual ~framedump() noexcept = default;

    virtual auto initialize(execution_context&, const video_options&)
      -> bool = 0;

    virtual auto get_buffer(span_size_t size) -> memory::block = 0;

    virtual auto dump_frame(
      long frame_number,
      int width,
      int height,
      int elements,
      span_size_t element_size,
      framedump_pixel_format,
      framedump_data_type,
      memory::block data) -> bool = 0;
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
    virtual void on_video_resize() noexcept = 0;
    virtual void update() noexcept = 0;
    virtual void clean_up() noexcept = 0;
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
