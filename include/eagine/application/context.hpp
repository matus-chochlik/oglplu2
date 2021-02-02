/**
 *  @file eagine/application/context.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

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
class video_context {
public:
    video_context(
      execution_context& parent,
      std::shared_ptr<video_provider> provider) noexcept
      : _parent{parent}
      , _provider{std::move(provider)} {}

    auto frame_number() const noexcept {
        return _frame_no;
    }

    void begin();
    void end();
    void commit();

    auto init_gl_api() noexcept -> bool;

    auto has_gl_api() const noexcept {
        return bool(_gl_api);
    }

    auto gl_api() const noexcept -> auto& {
        EAGINE_ASSERT(has_gl_api());
        return *_gl_api;
    }

    auto surface_size() noexcept -> std::tuple<int, int> {
        if(EAGINE_LIKELY(_provider)) {
            return extract(_provider).surface_size();
        }
        return {1, 1};
    }

    auto surface_aspect() noexcept -> float {
        if(EAGINE_LIKELY(_provider)) {
            return extract(_provider).surface_aspect();
        }
        return 1.F;
    }

    void clean_up() noexcept;

private:
    execution_context& _parent;
    long _frame_no{0};
    std::shared_ptr<video_provider> _provider{};
    std::shared_ptr<oglp::gl_api> _gl_api{};
    std::shared_ptr<video_context_state> _state{};
};
//------------------------------------------------------------------------------
class audio_context {
public:
    audio_context(
      execution_context& parent,
      std::shared_ptr<audio_provider> provider) noexcept
      : _parent{parent}
      , _provider{std::move(provider)} {
        EAGINE_MAYBE_UNUSED(_parent);
    }

    auto init_al_api() noexcept -> bool;

    auto has_al_api() const noexcept {
        return bool(_al_api);
    }

    auto al_api() const noexcept -> auto& {
        EAGINE_ASSERT(has_al_api());
        return *_al_api;
    }

    void clean_up() noexcept;

private:
    execution_context& _parent;
    std::shared_ptr<audio_provider> _provider{};
    std::shared_ptr<oalp::al_api> _al_api{};
};
//------------------------------------------------------------------------------
class execution_context
  : public main_ctx_object
  , private input_sink {
public:
    execution_context(main_ctx_parent parent) noexcept
      : main_ctx_object(EAGINE_ID(AppExecCtx), parent)
      , _options{*this} {}

    auto result() const noexcept {
        return _exec_result;
    }

    auto options() const noexcept -> const launch_options& {
        return _options;
    }

    auto buffer() const noexcept -> memory::buffer&;

    auto state() const noexcept -> const context_state_view&;

    auto prepare(std::unique_ptr<launchpad> pad) -> execution_context&;
    auto is_running() noexcept -> bool;
    void stop_running() noexcept;
    void update() noexcept;
    void clean_up() noexcept;

    auto run() noexcept -> execution_context& {
        while(is_running()) {
            update();
        }
        clean_up();
        return *this;
    }

    auto enough_run_time() const noexcept -> bool;
    auto enough_frames(span_size_t frame_no) const noexcept -> bool;

    auto video_ctx_count() const noexcept {
        return span_size(_video_contexts.size());
    }

    auto video_ctx(span_size_t index = 0) const noexcept -> video_context* {
        if((index >= 0) && (index < video_ctx_count())) {
            return _video_contexts[std_size(index)].get();
        }
        return nullptr;
    }

    auto audio_ctx_count() const noexcept {
        return span_size(_audio_contexts.size());
    }

    auto audio_ctx(span_size_t index = 0) const noexcept -> audio_context* {
        if((index >= 0) && (index < audio_ctx_count())) {
            return _audio_contexts[std_size(index)].get();
        }
        return nullptr;
    }

    auto connect_input(message_id input_id, input_handler handler)
      -> execution_context&;

    auto connect_input(const input_slot& input) -> auto& {
        return connect_input(input.id(), input.handler());
    }

    auto connect_inputs() -> execution_context&;

    auto map_input(
      message_id input_id,
      identifier mapping_id,
      message_id signal_id,
      input_setup setup) -> execution_context&;

    auto map_input(message_id input_id, message_id signal_id, input_setup setup)
      -> execution_context& {
        return map_input(input_id, {}, signal_id, setup);
    }

    auto map_inputs(identifier mapping_id) -> execution_context&;
    auto map_inputs() -> execution_context& {
        return map_inputs({});
    }

    auto setup_inputs(identifier mapping_id) -> execution_context& {
        return connect_inputs().map_inputs(mapping_id);
    }
    auto setup_inputs() -> execution_context& {
        return setup_inputs({});
    }

    auto switch_input_mapping(identifier mapping_id) -> execution_context&;
    auto switch_input_mapping() -> auto& {
        return switch_input_mapping({});
    }

    auto stop_running_input() noexcept -> input_slot {
        return {
          EAGINE_MSG_ID(App, Stop),
          {this, EAGINE_THIS_MEM_FUNC_C(_handle_stop_running)}};
    }

    void random_uniform(span<byte> dest);
    void random_uniform_01(span<float> dest);
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
