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

#include "../assert.hpp"
#include "../main_ctx_object.hpp"
#include "interface.hpp"
#include "options.hpp"
#include "state_view.hpp"

namespace eagine::application {
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

    auto run() noexcept -> execution_context& {
        while(is_running()) {
            update();
        }
        return *this;
    }

    void surface_size(int width, int height);
    void pointer_position(float x, float y, int index);

private:
    int _exec_result{0};
    launch_options _options;
    std::unique_ptr<application> _app;

    std::vector<std::shared_ptr<hmi_context>> _hmi_contexts;
    std::vector<std::shared_ptr<input_context>> _input_contexts;
    std::vector<std::shared_ptr<video_context>> _video_contexts;

    auto _setup_contexts() -> bool;
};
//------------------------------------------------------------------------------
auto establish(main_ctx&) -> std::unique_ptr<launchpad>;
} // namespace eagine::application

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/application/context.inl>
#endif

#endif
