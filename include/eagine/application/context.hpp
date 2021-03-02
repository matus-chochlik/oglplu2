/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_APPLICATION_CONTEXT_HPP
#define EAGINE_APPLICATION_CONTEXT_HPP

#include "../../oalplus/al_api_fwd.hpp"
#include "../../oglplus/gl_api_fwd.hpp"
#include "../application_config.hpp"
#include "../assert.hpp"
#include "../flat_map.hpp"
#include "../main_ctx_object.hpp"
#include "../memory/buffer.hpp"
#include "interface.hpp"
#include "options.hpp"
#include "state_view.hpp"
#include <map>

namespace eagine::application {
//------------------------------------------------------------------------------
/// @brief Class holding video rendering-related application support objects.
/// @ingroup application
/// @see video_options
/// @see audio_context
/// @see execution_context
///
/// Instances of this class represent a single (possibly one of several)
/// video rendering contexts in an application.
class video_context {
public:
    video_context(
      execution_context& parent,
      std::shared_ptr<video_provider> provider) noexcept
      : _parent{parent}
      , _provider{std::move(provider)} {}

    /// @brief Returns a reference to the parent application execution context.
    auto parent() const noexcept -> execution_context& {
        return _parent;
    }

    /// @brief Returns the current video frame number.
    auto frame_number() const noexcept {
        return _frame_no;
    }

    /// @brief Start working in this video rendering context (make it current).
    /// @see end
    /// @see commit
    void begin();

    /// @brief Stop working with this video rendering context.
    /// @see begin
    /// @see commit
    void end();

    /// @brief Apply the rendering commands done since the last commit (swap buffers).
    /// @see begin
    /// @see end
    void commit();

    /// @brief Tries to intialize the GL rendering API in this video context.
    /// @see has_gl_api
    /// @see gl_api
    auto init_gl_api() noexcept -> bool;

    /// @brief Indicates if the GL rendering API in this video context is initialized.
    /// @see init_gl_api
    /// @see gl_api
    auto has_gl_api() const noexcept {
        return bool(_gl_api);
    }

    /// @brief Returns a reference to the GL rendering API in this context.
    /// @see init_gl_api
    /// @pre has_gl_api()
    auto gl_api() const noexcept -> oglp::gl_api& {
        EAGINE_ASSERT(has_gl_api());
        return *_gl_api;
    }

    /// @brief Returns the rendering surface's dimensions (in pixels).
    auto surface_size() noexcept -> std::tuple<int, int> {
        if(EAGINE_LIKELY(_provider)) {
            return extract(_provider).surface_size();
        }
        return {1, 1};
    }

    /// @brief Returns the rendering surface's aspect ratio.
    auto surface_aspect() noexcept -> float {
        if(EAGINE_LIKELY(_provider)) {
            return extract(_provider).surface_aspect();
        }
        return 1.F;
    }

    /// @brief Cleans up and releases this rendering context and APIs.
    void clean_up() noexcept;

private:
    execution_context& _parent;
    long _frame_no{0};
    std::shared_ptr<video_provider> _provider{};
    std::shared_ptr<oglp::gl_api> _gl_api{};
    std::shared_ptr<video_context_state> _state{};
};
//------------------------------------------------------------------------------
/// @brief Class holding audio playback and recording-related application support objects.
/// @ingroup application
/// @see audio_options
/// @see video_context
/// @see execution_context
///
/// Instances of this class represent a single (possibly one of several)
/// audio playback and recording contexts in an application.
class audio_context {
public:
    audio_context(
      execution_context& parent,
      std::shared_ptr<audio_provider> provider) noexcept
      : _parent{parent}
      , _provider{std::move(provider)} {
        EAGINE_MAYBE_UNUSED(_parent);
    }

    /// @brief Tries to intialize the AL sound API in this video context.
    /// @see has_al_api
    /// @see al_api
    auto init_al_api() noexcept -> bool;

    /// @brief Indicates if the AL API in this audio context is initialized.
    /// @see init_al_api
    /// @see al_api
    auto has_al_api() const noexcept {
        return bool(_al_api);
    }

    /// @brief Returns a reference to the AL API in this context.
    /// @see init_al_api
    /// @pre has_al_api()
    auto al_api() const noexcept -> auto& {
        EAGINE_ASSERT(has_al_api());
        return *_al_api;
    }

    /// @brief Cleans up and releases this audio context and APIs.
    void clean_up() noexcept;

private:
    execution_context& _parent;
    std::shared_ptr<audio_provider> _provider{};
    std::shared_ptr<oalp::al_api> _al_api{};
};
//------------------------------------------------------------------------------
/// @brief Class holding shared video/audio rendering application support objects.
/// @ingroup application
/// @see video_context
/// @see audio_context
/// @see launch_options
class execution_context
  : public main_ctx_object
  , private input_sink {
public:
    execution_context(main_ctx_parent parent) noexcept
      : main_ctx_object(EAGINE_ID(AppExecCtx), parent)
      , _options{*this} {}

    /// @brief Returns the application execution result.
    auto result() const noexcept -> int {
        return _exec_result;
    }

    /// @brief Returns a reference to the launch options.
    auto options() const noexcept -> const launch_options& {
        return _options;
    }

    /// @brief Returns a references to a multi-purpose memory buffer.
    auto buffer() const noexcept -> memory::buffer&;

    /// @brief Returns a reference to the context state view.
    auto state() const noexcept -> const context_state_view&;

    /// @brief Prepares the application launch pad object.
    auto prepare(std::unique_ptr<launchpad> pad) -> execution_context&;

    /// @brief Indicates if the application is running its main loop.
    /// @see stop_running
    auto is_running() noexcept -> bool;

    /// @brief Stops the main application loop.
    /// @see is_running
    void stop_running() noexcept;

    /// @brief Updates this execution context (once per a single main loop iteration).
    void update() noexcept;

    /// @brief Cleans up this execution context and managed objects.
    void clean_up() noexcept;

    /// @brief Starts the main application loop (will block until stopped).
    auto run() noexcept -> execution_context& {
        while(is_running()) {
            update();
        }
        clean_up();
        return *this;
    }

    /// @brief Indicates if the application ran long enough.
    auto enough_run_time() const noexcept -> bool;

    /// @brief Indicates if the application rendered enough frames.
    auto enough_frames(span_size_t frame_no) const noexcept -> bool;

    /// @brief Returns the count of created video contexts.
    auto video_ctx_count() const noexcept {
        return span_size(_video_contexts.size());
    }

    /// @brief Returns the video context at the specified index.
    auto video_ctx(span_size_t index = 0) const noexcept -> video_context* {
        if((index >= 0) && (index < video_ctx_count())) {
            return _video_contexts[std_size(index)].get();
        }
        return nullptr;
    }

    /// @brief Returns the count of created audio contexts.
    auto audio_ctx_count() const noexcept {
        return span_size(_audio_contexts.size());
    }

    /// @brief Returns the audio context at the specified index.
    auto audio_ctx(span_size_t index = 0) const noexcept -> audio_context* {
        if((index >= 0) && (index < audio_ctx_count())) {
            return _audio_contexts[std_size(index)].get();
        }
        return nullptr;
    }

    /// @brief Connect the specified logical input to a callable handler reference.
    auto connect_input(message_id input_id, input_handler handler)
      -> execution_context&;

    /// @brief Connect the specified input slot.
    /// @see input_slot
    auto connect_input(const input_slot& input) -> auto& {
        return connect_input(input.id(), input.handler());
    }

    /// @brief Connect generic, reusable application logical input slots.
    auto connect_inputs() -> execution_context&;

    /// @brief Map a specified logical input to a physical input signal.
    auto map_input(
      message_id input_id,
      identifier mapping_id,
      message_id signal_id,
      input_setup setup) -> execution_context&;

    /// @brief Map a specified logical input to a physical input signal.
    auto map_input(message_id input_id, message_id signal_id, input_setup setup)
      -> execution_context& {
        return map_input(input_id, {}, signal_id, setup);
    }

    /// @brief Binds generic application inputs to default physical input signals.
    auto map_inputs(identifier mapping_id) -> execution_context&;

    /// @brief Binds generic application inputs to default physical input signals.
    auto map_inputs() -> execution_context& {
        return map_inputs({});
    }

    /// @brief Sets-up (connects handlers and binds to signals) default inputs.
    auto setup_inputs(identifier mapping_id) -> execution_context& {
        return connect_inputs().map_inputs(mapping_id);
    }

    /// @brief Sets-up (connects handlers and binds to signals) default inputs.
    auto setup_inputs() -> execution_context& {
        return setup_inputs({});
    }

    /// @brief Switches to the input mapping with the specified id.
    auto switch_input_mapping(identifier mapping_id) -> execution_context&;

    /// @brief Switches to the default input mapping.
    auto switch_input_mapping() -> auto& {
        return switch_input_mapping({});
    }

    auto stop_running_input() noexcept -> input_slot {
        return {
          EAGINE_MSG_ID(App, Stop),
          {this, EAGINE_THIS_MEM_FUNC_C(_handle_stop_running)}};
    }

    /// @brief Generates random uniformly-distributed bytes into @p dest.
    void random_uniform(span<byte> dest);

    /// @brief Generates random uniformly-distributed floats in <0, 1> into @p dest.
    void random_uniform_01(span<float> dest);

    /// @brief Generates random normally-distributed floats into @p dest.
    void random_normal(span<float> dest);

private:
    int _exec_result{0};
    launch_options _options;
    std::shared_ptr<context_state> _state;
    std::unique_ptr<application> _app;
    bool _keep_running{true};

    std::vector<std::shared_ptr<hmi_provider>> _hmi_providers;
    std::vector<std::shared_ptr<input_provider>> _input_providers;
    std::vector<std::unique_ptr<video_context>> _video_contexts;
    std::vector<std::unique_ptr<audio_context>> _audio_contexts;

    auto _setup_providers() -> bool;

    identifier _input_mapping{EAGINE_ID(initial)};

    // input id -> handler function reference
    flat_map<message_id, input_handler> _connected_inputs;

    // mapping id -> signal id -> (input id, setup)
    flat_map<
      identifier,
      flat_map<message_id, std::tuple<message_id, input_setup>>>
      _input_mappings;

    // signal id -> (setup, handler)
    flat_map<message_id, std::tuple<input_setup, input_handler>> _mapped_inputs;

    void _handle_stop_running(const input& engaged) {
        if(engaged) {
            stop_running();
        }
    }

    template <typename T>
    void _forward_input(const input_info&, const input_value<T>&) noexcept;

    void consume(const input_info&, const input_value<bool>&) noexcept final;
    void consume(const input_info&, const input_value<int>&) noexcept final;
    void consume(const input_info&, const input_value<float>&) noexcept final;
    void consume(const input_info&, const input_value<double>&) noexcept final;
};
//------------------------------------------------------------------------------
auto establish(main_ctx&) -> std::unique_ptr<launchpad>;
} // namespace eagine::application

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/application/context.inl>
#endif

#endif
