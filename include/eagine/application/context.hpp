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
#include "../assert.hpp"
#include "../main_ctx_object.hpp"
#include "interface.hpp"
#include "options.hpp"
#include "state_view.hpp"

namespace eagine::application {
//------------------------------------------------------------------------------
class execution_context;
//------------------------------------------------------------------------------
class video_context {
public:
    video_context(
      execution_context& parent,
      std::shared_ptr<video_provider> provider) noexcept
      : _parent{parent}
      , _provider{std::move(provider)} {}

    void begin() {
        _provider->video_begin(_parent);
    }

    void end() {
        _provider->video_end(_parent);
    }

    void commit() {
        _provider->video_commit(_parent);
    }

private:
    execution_context& _parent;
    std::shared_ptr<video_provider> _provider{};
};
//------------------------------------------------------------------------------
class audio_context {
public:
    audio_context(
      execution_context& parent,
      std::shared_ptr<audio_provider> provider) noexcept
      : _parent{parent}
      , _provider{std::move(provider)} {
        // TODO
        EAGINE_MAYBE_UNUSED(_parent);
    }

private:
    execution_context& _parent;
    std::shared_ptr<audio_provider> _provider{};
};
//------------------------------------------------------------------------------
class execution_context_impl;
class execution_context : public main_ctx_object {
public:
    execution_context(main_ctx_parent parent) noexcept
      : main_ctx_object(EAGINE_ID(AppExecCtx), parent)
      , _options{*this} {}

    auto options() const noexcept -> const launch_options& {
        return _options;
    }

    auto result() const noexcept {
        return _exec_result;
    }

    auto prepare(std::unique_ptr<launchpad> pad) -> execution_context&;
    auto is_running() noexcept -> bool;
    void stop_running() noexcept;
    void update() noexcept;
    void cleanup() noexcept;

    auto run() noexcept -> execution_context& {
        while(is_running()) {
            update();
        }
        cleanup();
        return *this;
    }

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

    void surface_size(int width, int height);
    void pointer_position(float x, float y, int index);

private:
    int _exec_result{0};
    launch_options _options;
    std::unique_ptr<application> _app;
    bool _keep_running{true};

    std::vector<std::shared_ptr<hmi_provider>> _hmi_providers;
    std::vector<std::shared_ptr<input_provider>> _input_providers;
    std::vector<std::unique_ptr<video_context>> _video_contexts;
    std::vector<std::unique_ptr<audio_context>> _audio_contexts;

    auto _setup_providers() -> bool;
};
//------------------------------------------------------------------------------
auto establish(main_ctx&) -> std::unique_ptr<launchpad>;
} // namespace eagine::application

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/application/context.inl>
#endif

#endif
